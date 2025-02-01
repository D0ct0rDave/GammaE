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
    m_eNodeType = SNT_AnimTransf;
    m_poBV = CGGraphBVFactory::poCreate();
}
// --------------------------------------------------------------------------------
CGSceneAnimTransf::~CGSceneAnimTransf()
{
    if ( m_poTransforms )
    {
        mDel [] m_poTransforms;
    }

    for (uint uiState = 0; uiState < m_poStateBVs.uiNumElems(); uiState++)
    {
        if (m_poStateBVs[uiState] != NULL)
        {
            mDel m_poStateBVs[uiState];
        }
    }
    
    m_poStateBVs.Clear();

    if (m_poBV != NULL)
    {
        mDel m_poBV;
    }
}
// --------------------------------------------------------------------------------
void CGSceneAnimTransf::Setup(uint _uiNumStates)
{
    m_poTransforms = mNew CGMatrix4x4[_uiNumStates];
    for (uint i = 0; i < _uiNumStates; i++)
    {
        m_poStateBVs.iAdd( CGGraphBVFactory::poCreate() );
    }

    m_uiNumStates = _uiNumStates;
    ComputeStatesBVols();
}
// --------------------------------------------------------------------------------
void CGSceneAnimTransf::ComputeStatesBVols()
{
    /*
    if (!BVol)
    {
        CGVect3 Max,Min;

        Max.Set(0,0,0);
        Min.Set(0,0,0);

        BVol = CGraphBV_Manager::poCreate();
        BVol->Init(Max,Min);
    }
    */
}
// --------------------------------------------------------------------------------
void CGSceneAnimTransf::SetAnimState (uint _uiSrc, uint _uiDst, float _fFactor)
{
    assert (m_poTransforms && "NULL Transform state array");

    // HACK!!! No slerp quaternion code
    // if (_fFactor > 0.5f) _fFactor = 1.0f; else _fFactor = 0.0f;

    if (m_uiNumStates == 1)
    {
        m_oTrans = m_poTransforms[0];
    }
    else
    {
        if (_uiSrc >= m_uiNumStates) _uiSrc = m_uiNumStates -1;
        if (_uiDst >= m_uiNumStates) _uiDst = m_uiNumStates -1;

        if ((_uiSrc != _uiDst) && (_fFactor>0.0f))
        {
            if (_fFactor < 1.0f)
            {
                CGQuaternion SrcQuat,DstQuat,ResQuat;
                CGVect4 SrcPos,DstPos,ResPos;

                // Interpolate rotations
                SrcQuat.FromMatrix(m_poTransforms[_uiSrc] );
                DstQuat.FromMatrix(m_poTransforms[_uiDst] );

                ResQuat.Slerp(SrcQuat,DstQuat,_fFactor);
                m_oTrans = ResQuat.ToMatrix();

                // Interpolate positions
                SrcPos = m_poTransforms[_uiSrc].oGetCol(3);
                DstPos = m_poTransforms[_uiDst].oGetCol(3);

                ResPos.Interpolate(SrcPos,DstPos,_fFactor);

                m_oTrans.Set(0,3,ResPos.x);
                m_oTrans.Set(1,3,ResPos.y);
                m_oTrans.Set(2,3,ResPos.z);
            }
            else
            {
                m_oTrans = m_poTransforms[_uiDst];
            }
        }
        else
            m_oTrans = m_poTransforms[_uiSrc];
    }

    m_poBV->Copy(*m_poStateBVs[_uiSrc]);
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimTransf::poGetStateBVol(int _iState)
{
    return m_poStateBVs[_iState];
}
// ----------------------------------------------------------------------------
void CGSceneAnimTransf::SetStateBVol(int _iState, CGGraphBV* _poBV)
{
    if (m_poStateBVs[_iState] != NULL)
    {
        mDel m_poStateBVs[_iState];
    }

    m_poStateBVs[_iState] = _poBV;
}
// --------------------------------------------------------------------------------
uint CGSceneAnimTransf::uiGetNumStates() const
{
    return(m_uiNumStates);
}
// --------------------------------------------------------------------------------
const CGMatrix4x4& CGSceneAnimTransf::GetCurrentTranform() const
{
    return(m_oTrans);
}
// --------------------------------------------------------------------------------
void CGSceneAnimTransf::SetObject(CGSceneNode* _poObj)
{
    m_poObject = _poObj;
}
// --------------------------------------------------------------------------------
CGSceneNode* CGSceneAnimTransf::poGetObject()
{
    return m_poObject;
}
// --------------------------------------------------------------------------------
CGMatrix4x4* CGSceneAnimTransf::poGetStateTransforms()
{
    return m_poTransforms;
}
// --------------------------------------------------------------------------------
CGGraphBV* CGSceneAnimTransf::poGetBV()
{
    return m_poBV;
}
// --------------------------------------------------------------------------------
