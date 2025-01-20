// CObject3D_AnimTransf
#include "Animation\CObject3D_AnimTransf.h"

// Class CObject3D_AnimTransf

CObject3D_AnimTransf::CObject3D_AnimTransf()
    : pTransStates(NULL)
{
    TypeID = e3DObj_AnimTransf;
}

CObject3D_AnimTransf::~CObject3D_AnimTransf()
{
    if (pTransStates) mDel [] pTransStates;
}

void CObject3D_AnimTransf::CreateStates (int _iNumStates)
{
    iNumStates   = _iNumStates;
    pTransStates = mNew CMatrix4x4[iNumStates];
}

CGraphBV *CObject3D_AnimTransf::poGetBoundVol ()
{
    return ( BVol );
}

void CObject3D_AnimTransf::ComputeBoundVol ()
{
    if (!BVol)
    {
   CVect3 Max,Min;

   Max.V3(0,0,0);
   Min.V3(0,0,0);

        BVol = CGraphBV_Manager::poCreate();
        BVol->Init(Max,Min);
    }
}

void CObject3D_AnimTransf::Render ()
{
   CGRenderer::I()->MultiplyMatrix(&Trans);
}

void CObject3D_AnimTransf::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
    assert (pTransStates       && "NULL Transform state array");

    // HACK!!! No slerp quaternion code
    // if (_fFactor > 0.5f) _fFactor = 1.0f; else _fFactor = 0.0f;

    if (iNumStates == 1)
    {
        Trans = pTransStates[0];
    }
    else
    {
        if (_iSrc >= iNumStates) _iSrc = iNumStates - 1;

        if (_iDst >= iNumStates) _iDst = iNumStates - 1;

        if ( ( _iSrc != _iDst ) && ( _fFactor > 0.0f ) )
        {
            if (_fFactor < 1.0f)
            {
   CQuaternion SrcQuat,DstQuat,ResQuat;
   CVect4 SrcPos,DstPos,ResPos;

                 // Interpolate rotations
                SrcQuat.FromMatrix( pTransStates[_iSrc] );
                DstQuat.FromMatrix( pTransStates[_iDst] );

                ResQuat.Slerp(SrcQuat,DstQuat,_fFactor);
                Trans = ResQuat.ToMatrix();

                 // Interpolate positions
                SrcPos = pTransStates[_iSrc].GetColVector(3);
                DstPos = pTransStates[_iDst].GetColVector(3);

                ResPos.Interpolate(SrcPos,DstPos,_fFactor);

                Trans.Set(0,3,ResPos.x);
                Trans.Set(1,3,ResPos.y);
                Trans.Set(2,3,ResPos.z);
            }
            else
            {
                Trans = pTransStates[_iDst];
            }
        }
        else
            Trans = pTransStates[_iSrc];
    }
} // SetAnimState

CGraphBV *CObject3D_AnimTransf::poGetStateBVol (int _iState)
{

    return ( BVol );

}

// Additional Declarations
