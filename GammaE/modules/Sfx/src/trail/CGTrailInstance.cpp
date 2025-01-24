// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
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
