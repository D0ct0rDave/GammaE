// ----------------------------------------------------------------------------
#include "CGCoronaInstance.h"
// ----------------------------------------------------------------------------
CGCoronaInstance::CGCoronaInstance(CGCoronaGenerator* _poTG)
{
	m_poTG = _poTG;
	m_poInstanceData = m_poTG->poCreateInstanceData();
}
// ----------------------------------------------------------------------------
void CGCoronaInstance::SetPos(const CVect3& _oNewPos)
{
	m_poInstanceData->SetPos(_oNewPos);
}
// ----------------------------------------------------------------------------
void CGCoronaInstance::Render()
{
	m_poTG->UpdateInstance(this,CGRenderer::I()->REStats.DTime);
}
// ----------------------------------------------------------------------------
void CGCoronaInstance::Reinit()
{
	m_poTG->InitInstance(this);
}
// ----------------------------------------------------------------------------
