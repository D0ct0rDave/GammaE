// CObject3D_AnimNode
#include "Animation\CObject3D_AnimNode.h"
#include <string.h>

// Class CObject3D_AnimNode

CObject3D_AnimNode::CObject3D_AnimNode()
    : poObjs(NULL), iNumObjs(0), iMaxObjs(0), poBVolStates(NULL)
{
    TypeID = e3DObj_AnimNode;
}

CObject3D_AnimNode::~CObject3D_AnimNode()
{

    for (int iObj = 0; iObj < iNumObjs; iObj++)
        poObjs[iObj]->Deref();

    mDel [] poObjs;

    if (poBVolStates)
    {
        for (int iState = 0; iState < iNumStates; iState++)
            mDel poBVolStates[iState];

        mDel [] poBVolStates;
    }

}

CGraphBV *CObject3D_AnimNode::poGetBoundVol ()
{
    return ( BVol );
}

void CObject3D_AnimNode::ComputeBoundVol ()
{
    assert (poBVolStates && "NULL Bounding Volume State array");

    int iState;
    int iObj;
    CVect3 Center;
    CVect3          *pBVVXs;
    CGraphBV        *pBVol;
    e3DObjectTypeID eObjType;

    pBVVXs = mNew CVect3[iNumObjs * 2];

    for (iState = 0; iState < iNumStates; iState++)
    {
        for (iObj = 0; iObj < iNumObjs; iObj++)
        {
            poObjs[iObj]->ComputeBoundVol ();

            eObjType = poObjs[iObj]->eGetTypeID();

            if ( ( eObjType > e3DObj_Anim_Begin )  &&  ( eObjType < e3DObj_Anim_End ) )
                pBVol = ( (CObject3D_AnimGen *)poObjs[iObj] )->poGetStateBVol(iState);
            else
                pBVol = poObjs[iObj]->poGetBoundVol();

            Center = pBVol->GetCenter();

            pBVVXs[iObj * 2 + 0].V3( Center.x - pBVol->GetRange(0),
                                    Center.y - pBVol->GetRange(1),
                                    Center.z - pBVol->GetRange(2) );

            pBVVXs[iObj * 2 + 1].V3( Center.x + pBVol->GetRange(0),
                                    Center.y + pBVol->GetRange(1),
                                    Center.z + pBVol->GetRange(2) );
        }

        poBVolStates[iState]->Compute  ( pBVVXs,iNumObjs * 2    );
    }

    mDel [] pBVVXs;

    BVol = poBVolStates[0];

} // ComputeBoundVol

void CObject3D_AnimNode::Render ()
{
    assert( poObjs && "NULL animated object array");

    for (int cObj = 0; cObj < iNumObjs; cObj++)
        poObjs[cObj]->Render();

}

void CObject3D_AnimNode::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
    assert (poBVolStates && "NULL Bounding Volume State array");

     // Set animation state of child objects
    for (int cObj = 0; cObj < iNumObjs; cObj++)
    {
        if ( ( poObjs[cObj]->eGetTypeID() > e3DObj_Anim_Begin )     &&
            ( poObjs[cObj]->eGetTypeID() < e3DObj_Anim_End ) )
            ( (CObject3D_AnimGen *)poObjs[cObj] )->SetAnimState(_iSrc,_iDst,_fFactor);
    }
    BVol = poBVolStates[_iSrc];

}

CGraphBV *CObject3D_AnimNode::poGetStateBVol (int _iState)
{
    assert (poBVolStates && "NULL Bounding Volume State array");

    if (_iState >= iNumStates) _iState = iNumStates - 1;
    return ( poBVolStates[_iState] );
}

void CObject3D_AnimNode::Init (int _iMaxObjs)
{
    iMaxObjs = _iMaxObjs;
    iNumObjs = 0;

    poObjs    = mNew CObject3D *[iMaxObjs];
    memset(poObjs,0,4 * iMaxObjs);
}

int CObject3D_AnimNode::AddObject (CObject3D_AnimGen *_poObj)
{
    assert( poObjs               && "NULL animated object array");
    assert( ( iNumObjs < iMaxObjs ) && "Full animated object array" );

    poObjs[iNumObjs++] = _poObj;
    return( iNumObjs - 1 );
}

void CObject3D_AnimNode::CreateStates (int _iNumStates)
{
   int iState;

    iNumStates   = _iNumStates;

     // OPTIMIZE (SIZE): Memory sucker!
    poBVolStates = mNew CGraphBV *[iNumStates];

    for (iState = 0; iState < iNumStates; iState++)
        poBVolStates[iState] = CGraphBV_Manager::poCreate();

}

void CObject3D_AnimNode::Clear ()
{
    assert( poObjs && "NULL animated object array");

    for (int cObj = 0; cObj < iNumObjs; cObj++)
        poObjs[cObj]->Deref();

}

CObject3D *CObject3D_AnimNode::poGetObject (int _iObj)
{
    assert( poObjs              && "NULL animated object array");
    assert( ( _iObj < iNumObjs ) && "Object out of bounds" );

    return ( poObjs[_iObj] );
}

// Additional Declarations
