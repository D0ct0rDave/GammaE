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
#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimInstance.h"
#include "Animation/CGSceneAnimGroup.h"
#include "Animation/CGSceneAnimTransf.h"

// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneNode* _poNode)
{
    _poNode->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneBSPNode* _poNode)
{
    /*
       TODO: Implement CGSCNVBoundVolBuilder::Visit(CGSceneBSPNode* _poNode)

       // Las bounding boxes de los objetos deben tener en cuenta
       // las transformaciones que se deben realizar en los nodos
       // hijos. Probar a transformar la BoundingBox mediante la
       // matriz asociada al nodo. Despues volver a obtener
       // los max y los mins, para volver a tener una AABB
       float fXSide,fYSide,fZSide;
       CGVect3 Maxs,Mins,Center;
       CGBoundingVolume* BV;
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

       _poNode->poGetBV()->Init(Maxs,Mins);
     */
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneCamera* _poNode)
{
    Visit( (CGSceneGroup*)_poNode );
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneCompiledLeaf* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneInstance* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneLeaf* _poNode)
{
    if ( _poNode->poGetMesh()->eGetType() == E3D_MT_Mesh )
    {
        CGBoundingVolume* poBV = MeshUtils::poComputeBV( (CGMesh &) * _poNode->poGetMesh() );

        _poNode->poGetMesh()->SetBV( poBV );
        _poNode->SetBV( poBV );
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
    /*
       TODO: Implement CGSCNVBoundVolBuilder::Visit(CGSceneGroup* _poNode)

       // Las bounding boxes de los objetos deben tener en cuenta
       // las transformaciones que se deben realizar en los nodos
       // hijos. Probar a transformar la BoundingBox mediante la
       // matriz asociada al nodo. Despues volver a obtener
       // los max y los mins, para volver a tener una AABB
       float fXSide,fYSide,fZSide;
       CGVect3 Maxs,Mins,Center;
       CGBoundingVolume* poBV;

       Mins.Set( 1e10f, 1e10f, 1e10f);
       Maxs.Set(-1e10f,-1e10f,-1e10f);

       for ( uint cObj = 0; cObj < _poNode->uiNumSubObjs(); cObj++ )
       {
        if ( _poNode->poGetObject(cObj) )
        {
            // Compute the AABB for the object
            _poNode->poGetObject(cObj)->Accept(this);
            poBV = _poNode->poGetObject(cObj)->poGetBV();

            if ( poBV == NULL ) continue;

            // Get object properties
            fXSide = poBV->GetRange(0) * 0.5f;
            fYSide = poBV->GetRange(1) * 0.5f;
            fZSide = poBV->GetRange(2) * 0.5f;
            Center = poBV->oGetCenter();

            // Compute Maxs/Mins vectors
            if ( Center.x + fXSide > Maxs.x ) Maxs.x = Center.x + fXSide;
            if ( Center.x - fXSide < Mins.x ) Mins.x = Center.x - fXSide;

            if ( Center.y + fYSide > Maxs.y ) Maxs.y = Center.y + fYSide;
            if ( Center.y - fYSide < Mins.y ) Mins.y = Center.y - fYSide;

            if ( Center.z + fZSide > Maxs.z ) Maxs.z = Center.z + fZSide;
            if ( Center.z - fZSide < Mins.z ) Mins.z = Center.z - fZSide;
        }
       }

       _poNode->poGetBV()->Init(Maxs,Mins);
     */
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneScreenRect* _poNode)
{
    if ( _poNode->poGetMesh()->eGetType() == E3D_MT_Mesh )
    {
        CGBoundingVolume* poBV = MeshUtils::poComputeBV( (CGMesh &) * _poNode->poGetMesh() );
        // _poNode->poGetBV()->Transform( (CGMatrix4x4 &)_poNode->oGetMatrix() );
        _poNode->poGetMesh()->SetBV( poBV );
        _poNode->SetBV( poBV );
    }
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneSwitch* _poNode)
{
    if ( _poNode->poGetObject() != NULL )
        _poNode->poGetObject()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneTransf* _poNode)
{
    _poNode->poGetObject()->Accept(this);
    _poNode->poGetBV()->Copy( _poNode->poGetObject()->poGetBV() );
    _poNode->poGetBV()->Transform( (CGMatrix4x4 &)_poNode->oTransf() );
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimCfg* _poNode)
{
    _poNode->poGetAnimObj()->Accept(this);
    // _poNode->poGetBoundVol()->Copy( _poNode->poGetAnimObj()->poGetKeyFrameBVol );
    // _poNode->poGetBoundVol()->Transform( (CGMatrix4x4&)_poNode->oTransf() );
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimMesh* _poNode)
{
    // Recompute the bounding volume of the startup mesh
    _poNode->poGetMesh()->ComputeBoundVol();

    // Recompute the bounding volume of the key frames
    for ( uint uiFrame = 0; uiFrame < _poNode->uiGetNumKeyFrames(); uiFrame++ )
    {
        CGBoundingVolume* poBV = _poNode->poGetKeyFrameBVol(uiFrame);
        poBV->Compute( _poNode->poGetVertexs() + uiFrame * _poNode->uiGetNumFrameVXs(),_poNode->uiGetNumFrameVXs() );
    }
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimInstance* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimGroup* _poNode)
{
    for ( uint i = 0; i < _poNode->uiNumAnimObjects(); i++ )
        _poNode->poGetAnimObject(i)->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVBoundVolBuilder::Visit(CGSceneAnimTransf* _poNode)
{
    /*
       DMC: To be implemented
       _poNode->
       for (uint i=0;i<_poNode->uiNumAnimObjects();i++)
        _poNode->poGetAnimObject(i)->Accept(this);

       CGVect3 Max,Min;

       Max.Set(0,0,0);
       Min.Set(0,0,0);

       BVol = CGraphBV_Manager::poCreate();
       BVol->Init(Max,Min);
     */
}
// ---------------------------------------------------------------------
