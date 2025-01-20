// -----------------------------------------------------------------------------
#include "CEntRend.h"
#include "CGraphicInstance.h"
// -----------------------------------------------------------------------------
CVisEntity*	 CEntRend::m_apoREI[MAX_INSTANCES];
int			 CEntRend::m_iNumInsts;
// -----------------------------------------------------------------------------
int CEntRend::iAdd(CVisEntity* _poEnt)
{
	if (m_iNumInsts==MAX_INSTANCES)
		error("Maximum number of instances reached");

	m_apoREI[m_iNumInsts] = _poEnt;
	m_iNumInsts++;

	return(m_iNumInsts-1);
}
// -----------------------------------------------------------------------------
void CEntRend::Invalidate()
{
	m_iNumInsts = 0;
}
// -----------------------------------------------------------------------------
void CEntRend::Update(float _fDeltaT)
{
	for (int iE=0;iE<m_iNumInsts;iE++)
	{
		if ((m_apoREI[iE]->m_bVisible) && (m_apoREI[iE]->m_eState != ENTSTATE_INACTIVE))
		{
			m_apoREI[iE]->m_poGI->Update(m_apoREI[iE]->m_fTimeMult * _fDeltaT);
		}
	}
}
// -----------------------------------------------------------------------------
void CEntRend::Render()
{
	for (int iE=0;iE<m_iNumInsts;iE++)
	{
		if (m_apoREI[iE]->m_bVisible)
		{
			m_apoREI[iE]->m_poGI->Render();
		}
	}
}
// -----------------------------------------------------------------------------