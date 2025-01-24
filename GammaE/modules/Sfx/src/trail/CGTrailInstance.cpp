// ----------------------------------------------------------------------------
#include "CGTrailInstance.h"
// ----------------------------------------------------------------------------
CGTrailInstance::CGTrailInstance(CGTrailGenerator* _poTG)
{
	m_poTG = _poTG;
	m_poInstanceData = m_poTG->poCreateInstanceData();
}
// ----------------------------------------------------------------------------
void CGTrailInstance::SetPos(const CVect3& _oNewPos)
{
	m_poInstanceData->SetPos(_oNewPos);
}
// ----------------------------------------------------------------------------
void CGTrailInstance::Update()
{
	m_poTG->UpdateInstance(this,CGRenderer::I()->REStats.DTime);
}
// ----------------------------------------------------------------------------
void CGTrailInstance::Reinit()
{
	m_poTG->InitInstance(this);
}
// ----------------------------------------------------------------------------
