// ----------------------------------------------------------------------------
#include <assert.h>
#include "GammaE_Mem.h"
#include "CObject3D_Node.h"
// ----------------------------------------------------------------------------
CObject3D_Node::CObject3D_Node()
{
    TypeID      = e3DObj_Node;
    BVol        = poCreateBoundVol();
    bFrustumTest = true;
}
// ----------------------------------------------------------------------------
CObject3D_Node::CObject3D_Node(uint _uiMaxSubObjs)
{
    Init(_uiMaxSubObjs);
}
// ----------------------------------------------------------------------------
CObject3D_Node::~CObject3D_Node()
{
    Clear();
    mDel BVol;
}
// ----------------------------------------------------------------------------
void CObject3D_Node::Init(uint _uiMaxSubObjs)
{
   poSubObj.Init(_uiMaxSubObjs);

    for (uint i = 0; i < _uiMaxSubObjs; i++)
        poSubObj.iAdd(NULL);

    //poSubObj.iAdd(NULL);

    /*
       MaxSubObjects = _MaxSubObjects;
       SubObj        = mNew CObject3D_Gen *[MaxSubObjects];
       for(int cObj=0;cObj<MaxSubObjects;cObj++)	SubObj[cObj] = NULL;
     */

    // poSubObj.
}
// ----------------------------------------------------------------------------
void CObject3D_Node::Clear()
{
     // Free SubObj
    for(uint cObj = 0; cObj < poSubObj.uiNumElems(); cObj++)
    {
        if(poSubObj[cObj])
            poSubObj[cObj]->Deref();
    }
    poSubObj.Clear();
}
// ----------------------------------------------------------------------------
CGraphBV *CObject3D_Node::poCreateBoundVol()
{
    return ( CGraphBV_Manager::poCreate() );
}
// ----------------------------------------------------------------------------
CGraphBV *CObject3D_Node::poGetBoundVol()
{
    return( BVol );
}
// ----------------------------------------------------------------------------
void CObject3D_Node::ComputeBoundVol()
{
     // Las bounding boxes de los objetos deben tener en cuenta
     // las transformaciones que se deben realizar en los nodos
     // hijos. Probar a transformar la BoundingBox mediante la
     // matriz asociada al nodo. Despues volver a obtener
     // los max y los mins, para volver a tener una AABB
    float fXSide,fYSide,fZSide;
    CVect3 Maxs,Mins,Center;
    CGraphBV    *BV;

    Mins.V3( 1e10f, 1e10f, 1e10f);
    Maxs.V3(-1e10f,-1e10f,-1e10f);

    for(uint cObj = 0; cObj < poSubObj.uiNumElems(); cObj++)
    {
        if(poSubObj[cObj])
        {
             // Compute the AABB for the object
            poSubObj[cObj]->ComputeBoundVol();
            BV = poSubObj[cObj]->poGetBoundVol();

            if(BV == NULL) continue;

             // Get object properties
            fXSide = BV->GetRange(0) * 0.5f;
            fYSide = BV->GetRange(1) * 0.5f;
            fZSide = BV->GetRange(2) * 0.5f;
            Center = BV->GetCenter();

             // Compute Maxs/Mins vectors
            if( Center.x + fXSide > Maxs.x ) Maxs.x = Center.x + fXSide;

            if( Center.x - fXSide < Mins.x ) Mins.x = Center.x - fXSide;

            if( Center.y + fYSide > Maxs.y ) Maxs.y = Center.y + fYSide;

            if( Center.y - fYSide < Mins.y ) Mins.y = Center.y - fYSide;

            if( Center.z + fZSide > Maxs.z ) Maxs.z = Center.z + fZSide;

            if( Center.z - fZSide < Mins.z ) Mins.z = Center.z - fZSide;
        }
    }

    BVol->Init(Maxs,Mins);
} // ComputeBoundVol
// ----------------------------------------------------------------------------
void CObject3D_Node::DelObject(uint _uiPos)
{
    assert( ( _uiPos < poSubObj.uiNumElems() ) && "Object out of bounds" );

    if( poSubObj[_uiPos] )
    {
        poSubObj[_uiPos]->Deref();
        poSubObj[_uiPos] = NULL;
    }
}
// ----------------------------------------------------------------------------
int CObject3D_Node::iAddObject(CObject3D *_poObj)
{
    for (uint i = 0; i < poSubObj.uiMaxElems(); i++)
    {
        if (poSubObj[i] == NULL)
        {
            poSubObj[i] = _poObj;
            _poObj->Ref();

            return( i );
        }
    }

     // Cannot add object to the node
    return( -1 );
}
// ----------------------------------------------------------------------------
void CObject3D_Node::SetObject(CObject3D *_poObj, uint _uiPos)
{
    assert( ( _uiPos < poSubObj.uiNumElems() ) && "Object out of bounds" );
    assert( _poObj && "Setting a NULL Subobject");

    poSubObj[_uiPos] = _poObj;
    _poObj->Ref();
}
// ----------------------------------------------------------------------------
CObject3D *CObject3D_Node::poGetObject(uint _uiPos)
{
    assert( ( _uiPos < poSubObj.uiNumElems() ) && "Object out of bounds" );
    return( poSubObj[_uiPos] );
}
// ----------------------------------------------------------------------------
void CObject3D_Node::Render()
{
    if( bVisible() )
    {
        for(uint cObj = 0; cObj < poSubObj.uiNumElems(); cObj++)
            if(poSubObj[cObj])
                poSubObj[cObj]->Render();
    }
}
// ----------------------------------------------------------------------------
uint CObject3D_Node::uiNumSubObjs()
{
   uint uiNumSubObjects = 0;

    for(uint cObj = 0; cObj < poSubObj.uiNumElems(); cObj++)
        if(poSubObj[cObj])
            uiNumSubObjects++;

    return( uiNumSubObjects );
}
// ----------------------------------------------------------------------------
