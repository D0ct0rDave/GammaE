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
#include "Animation\CGSceneAnimTransf.h"
// --------------------------------------------------------------------------------
CGSceneAnimTransf::CGSceneAnimTransf() :
    m_poTransforms(NULL)
{
    m_eTypeID = OBJ3D_AnimTransf;
}
// --------------------------------------------------------------------------------
CGSceneAnimTransf::~CGSceneAnimTransf()
{
    if ( m_poTransforms )
        mDel [] m_poTransforms;
}
/*
   void CGSceneAnimTransf::ComputeBoundVol ()
   {
    if (!BVol)
    {
        CGVect3 Max,Min;

        Max.Set(0,0,0);
        Min.Set(0,0,0);

        BVol = CGraphBV_Manager::poCreate();
        BVol->Init(Max,Min);
    }
   }

   void CGSceneAnimTransf::Render ()
   {
    CGRenderer::I()->MultiplyMatrix(&Trans);
   }

   void CGSceneAnimTransf::SetAnimState (int _iSrc, int _iDst, float _fFactor)
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
        if (_iSrc >= iNumStates) _iSrc = iNumStates-1;
        if (_iDst >= iNumStates) _iDst = iNumStates-1;

        if ((_iSrc != _iDst) && (_fFactor>0.0f))
        {
            if (_fFactor < 1.0f)
            {
                CQuaternion SrcQuat,DstQuat,ResQuat;
                CGVect4 SrcPos,DstPos,ResPos;

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
   }
 */
// --------------------------------------------------------------------------------
