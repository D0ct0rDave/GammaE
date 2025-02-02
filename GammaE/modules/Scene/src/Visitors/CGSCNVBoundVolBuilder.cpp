// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "CGSCNVBoundVolBuilder.h"

#include "GammaE_E3D.h"
#include "GammaE_Math.h"

#include "CGSceneBSPNode.h"
#include "CGSceneCamera.h"
#include "CGSceneInstance.h"
#include "CGSceneLeaf.h"
#include "CGSceneMux.h"
#include "CGSceneNode.h"
#include "CGSceneScreenRect.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"
#include "CGSceneTransf.h"

#include "Animation/CGSceneAnimNode.h"
#include "Animation/CGSceneAnimActionSet.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimGroup.h"
#include "Animation/CGSceneAnimTransf.h"
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneNode* _poNode)
{
    if (_poNode == NULL) return;

    _poNode->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneBSPNode* _poNode)
{
    if (_poNode == NULL) return;

//       TODO: Implement CGSCNVBoundVolBuilder::Visit(CGSceneBSPNode* _poNode)

       // Las bounding boxes de los objetos deben tener en cuenta
       // las transformaciones que se deben realizar en los nodos
       // hijos. Probar a transformar la BoundingBox mediante la
       // matriz asociada al nodo. Despues volver a obtener
       // los max y los mins, para volver a tener una AABB
       float fXSide,fYSide,fZSide;
       CGVect3 Maxs,Mins,Center;
       CGGraphBV* BV;
       CGSceneNode* poSubObjs[2];

       poSubObjs[0] = _poNode->poGetFrontNode();
       poSubObjs[1] = _poNode->poGetBackNode();

       Mins.Set( 1e10f, 1e10f, 1e10f);
       Maxs.Set(-1e10f,-1e10f,-1e10f);

       for ( uint cObj = 0; cObj < 2; cObj++ )
       {
            if ( poSubObjs[cObj] )
            {
                // Compute the AABB for the object
                poSubObjs[cObj]->Accept(this);
                BV = poSubObjs[cObj]->poGetBV();

                // Get object properties
                fXSide = BV->GetRange(0) * 0.5f;
                fYSide = BV->GetRange(1) * 0.5f;
                fZSide = BV->GetRange(2) * 0.5f;
                Center = BV->oGetCenter();

                // Compute Maxs/Mins vectors
                if ( Center.x + fXSide > Maxs.x ) Maxs.x = Center.x + fXSide;
                if ( Center.x - fXSide < Mins.x ) Mins.x = Center.x - fXSide;

                if ( Center.y + fYSide > Maxs.y ) Maxs.y = Center.y + fYSide;
                if ( Center.y - fYSide < Mins.y ) Mins.y = Center.y - fYSide;

                if ( Center.z + fZSide > Maxs.z ) Maxs.z = Center.z + fZSide;
                if ( Center.z - fZSide < Mins.z ) Mins.z = Center.z - fZSide;
            }
       }

       CGGraphBVAABB oAABB;
       oAABB.Init(Maxs,Mins);

       CGGraphBV* poBV = (_poNode->poGetBV() != NULL) ? _poNode->poGetBV() : CGGraphBVFactory::poCreate();
       poBV->Copy(oAABB);

       _poNode->SetBV(poBV);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneCamera* _poNode)
{
    if (_poNode == NULL) return;

    Visit( (CGSceneGroup*)_poNode );
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneInstance* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneLeaf* _poNode)
{
    if (_poNode == NULL) return;

    if ( _poNode->poGetMesh()->eGetType() == E3D_MT_Mesh )
    {
        CGMesh* poMesh = (CGMesh*)_poNode->poGetMesh();

        CGGraphBV* poBV = (poMesh->poGetBV() != NULL)? poMesh->poGetBV() : CGGraphBVFactory::poCreate();
        poBV->Compute(poMesh->m_poVX, poMesh->uiGetNumVXs());

        poMesh->SetBV( poBV );
    }
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneMux* _poNode)
{
    Visit( (CGSceneGroup*)_poNode );
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneGroup* _poNode)
{
    if (_poNode == NULL) return;

    // Las bounding boxes de los objetos deben tener en cuenta
    // las transformaciones que se deben realizar en los nodos
    // hijos. Probar a transformar la BoundingBox mediante la
    // matriz asociada al nodo. Despues volver a obtener
    // los max y los mins, para volver a tener una AABB
    CGVect3 Maxs,Mins;
    
    Mins.Set( 1e10f, 1e10f, 1e10f);
    Maxs.Set(-1e10f,-1e10f,-1e10f);

    for ( uint cObj = 0; cObj < _poNode->uiNumSubObjs(); cObj++ )
    {
        if ( _poNode->poGetObject(cObj) )
        {
            // Compute the AABB for the object
            _poNode->poGetObject(cObj)->Accept(this);
            CGGraphBV* poBV = _poNode->poGetObject(cObj)->poGetBV();

            if (poBV == NULL) continue;

            // Get object properties
            float fXSide = poBV->GetRange(0) * 0.5f;
            float fYSide = poBV->GetRange(1) * 0.5f;
            float fZSide = poBV->GetRange(2) * 0.5f;
            CGVect3 Center = poBV->oGetCenter();

            // Compute Maxs/Mins vectors
            if ( Center.x + fXSide > Maxs.x ) Maxs.x = Center.x + fXSide;
            if ( Center.x - fXSide < Mins.x ) Mins.x = Center.x - fXSide;

            if ( Center.y + fYSide > Maxs.y ) Maxs.y = Center.y + fYSide;
            if ( Center.y - fYSide < Mins.y ) Mins.y = Center.y - fYSide;

            if ( Center.z + fZSide > Maxs.z ) Maxs.z = Center.z + fZSide;
            if ( Center.z - fZSide < Mins.z ) Mins.z = Center.z - fZSide;
        }
    }
 
    CGGraphBVAABB oAABB;
    oAABB.Init(Maxs, Mins);
    
    _poNode->poGetBV()->Copy(oAABB);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneScreenRect* _poNode)
{
    if (_poNode == NULL) return;

    if ( _poNode->poGetMesh()->eGetType() == E3D_MT_Mesh )
    {
        CGMesh* poMesh = (CGMesh*)_poNode->poGetMesh(); 
        
        CGGraphBV* poBV = (poMesh->poGetBV() != NULL) ? poMesh->poGetBV() : CGGraphBVFactory::poCreate();
        poBV->Compute(poMesh->m_poVX, poMesh->uiGetNumVXs());
        poBV->Transform(_poNode->oGetMatrix());

        poMesh->SetBV( poBV );
    }
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneSwitch* _poNode)
{
    if (_poNode == NULL) return;

    if ( _poNode->poGetObject() != NULL )
        _poNode->poGetObject()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneTransf* _poNode)
{
    if (_poNode == NULL) return;

    _poNode->poGetObject()->Accept(this);
    CGGraphBV* poBV = (_poNode->poGetBV() != NULL) ? _poNode->poGetBV() : CGGraphBVFactory::poCreate();
    
    poBV->Copy(*_poNode->poGetObject()->poGetBV());
    poBV->Transform(_poNode->oTransf());

    _poNode->SetBV(poBV);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimActionSet* _poNode)
{
    if (_poNode == NULL) return;
    
    if (_poNode->poGetAnimObject() != NULL)
    {
       _poNode->poGetAnimObject()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimMesh* _poNode)
{
    if (_poNode == NULL) return;

    // Recompute the bounding volume of the startup mesh
    if (_poNode->poGetMesh()->poGetBV() == NULL)
    {
        _poNode->poGetMesh()->SetBV(CGGraphBVFactory::poCreate());
    }

     _poNode->ComputeStatesBVols();
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimGroup* _poNode)
{
    if (_poNode == NULL) return;

    for ( uint i = 0; i < _poNode->uiNumAnimObjects(); i++ )
        _poNode->poGetAnimObject(i)->Accept(this);

    _poNode->ComputeStatesBVols();
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimTransf* _poNode)
{    
    if (_poNode == NULL) return;

    // Recompute the bounding volume of the startup mesh
    _poNode->ComputeStatesBVols();
}
// ---------------------------------------------------------------------
