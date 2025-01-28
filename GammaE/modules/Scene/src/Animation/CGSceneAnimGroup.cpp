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
#include "Animation\CGSceneAnimGroup.h"
#include <assert.h>
// ----------------------------------------------------------------------------
CGSceneAnimGroup::CGSceneAnimGroup()
{
    m_eNodeType = SNT_AnimGroup;
}
// ----------------------------------------------------------------------------
CGSceneAnimGroup::~CGSceneAnimGroup()
{
    for (int iObj = 0; iObj < m_poObjs.uiNumElems(); iObj++)
    {
        m_poObjs[iObj]->Deref();
    }
    m_poObjs.Clear();

    for (uint uiState = 0; uiState < m_poStateBVs.uiNumElems(); uiState++)
    {
        delete m_poStateBVs[uiState];
    }
    m_poStateBVs.Clear();
}
// ----------------------------------------------------------------------------
void CGSceneAnimGroup::Setup(uint _uiNumStates)
{
    m_poStateBVs.Init(_uiNumStates);
	for (uint uiState = 0; uiState < _uiNumStates; uiState++)
	{
		m_poStateBVs[uiState] = CGGraphBVFactory::poCreate();
	}

    m_uiNumStates = _uiNumStates;
}
// ----------------------------------------------------------------------------
void CGSceneAnimGroup::SetAnimState(uint _uiSrc, uint _uiDst, float _fFactor)
{
    for (uint i = 0; i < m_poObjs.uiNumElems(); i++)
    {
		if ((m_poObjs[i]->eGetNodeType() > SNT_Anim_Begin) &&
			(m_poObjs[i]->eGetNodeType() < SNT_Anim_End))
			((CGSceneAnimNode*)m_poObjs[i])->SetAnimState(_uiSrc, _uiDst, _fFactor);
    }

	m_poBV = m_poStateBVs[_uiSrc];
}
// ----------------------------------------------------------------------------
uint CGSceneAnimGroup::uiGetNumStates() const
{
    return (m_uiNumStates);
}
// ----------------------------------------------------------------------------
void CGSceneAnimGroup::ComputeStatesBVols()
{
	assert((m_poStateBVs.uiNumElems()>0) && "NULL Bounding Volume State array");

	CGVect3			oCenter;
	CGVect3*		pBVVXs;
	CGGraphBV*		pBVol;
	ESceneNodeType	eObjType;

	pBVVXs = mNew CGVect3[m_poObjs.uiNumElems()* 2];
	for (uint uiObj = 0; uiObj < m_poObjs.uiNumElems(); uiObj++)
	{
		eObjType = m_poObjs[uiObj]->eGetNodeType();

		if ((eObjType > SNT_Anim_Begin) && (eObjType < SNT_Anim_End))
		{
			((CGSceneAnimNode*)m_poObjs[uiObj])->ComputeStatesBVols();
		}
	}

	for (uint uiState = 0; uiState < m_uiNumStates; uiState++)
	{
		for (uint uiObj = 0; uiObj < m_poObjs.uiNumElems(); uiObj++)
		{
			eObjType = m_poObjs[uiObj]->eGetNodeType();

			if ((eObjType > SNT_Anim_Begin) && (eObjType < SNT_Anim_End))
			{
				pBVol = ((CGSceneAnimNode*)m_poObjs[uiObj])->poGetStateBVol(uiState);
			}
			else
			{
				pBVol = m_poObjs[uiObj]->poGetBV();
			}

			oCenter = pBVol->oGetCenter();

			pBVVXs[uiObj * 2 + 0].Set(oCenter.x - pBVol->GetRange(0),
				oCenter.y - pBVol->GetRange(1),
				oCenter.z - pBVol->GetRange(2));

			pBVVXs[uiObj * 2 + 1].Set(oCenter.x + pBVol->GetRange(0),
				oCenter.y + pBVol->GetRange(1),
				oCenter.z + pBVol->GetRange(2));
		}

		m_poStateBVs[uiState]->Compute(pBVVXs, m_poObjs.uiNumElems() * 2);
	}

	mDel[]pBVVXs;
	m_poBV = m_poStateBVs[0];
}
// ----------------------------------------------------------------------------
CGGraphBV* CGSceneAnimGroup::poGetStateBVol(int _iState)
{
	return m_poStateBVs[0];
}
// ----------------------------------------------------------------------------
CGGraphBV* CGSceneAnimGroup::poGetBV()
{
	return m_poBV;
}
// ----------------------------------------------------------------------------
