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
#include "CGCoronaInstance.h"
// ----------------------------------------------------------------------------
CGCoronaInstance::CGCoronaInstance(CGCoronaGenerator* _poTG)
{
    m_poTG = _poTG;
    m_poInstanceData = m_poTG->poCreateInstanceData();
}
// ----------------------------------------------------------------------------
void CGCoronaInstance::SetPos(const CGVect3& _oNewPos)
{
    m_poInstanceData->SetPos(_oNewPos);
}
// ----------------------------------------------------------------------------
void CGCoronaInstance::Render()
{
    m_poTG->UpdateInstance(this,CGRenderer::I()->oGetStats().m_fDelta);
}
// ----------------------------------------------------------------------------
void CGCoronaInstance::Reinit()
{
    m_poTG->InitInstance(this);
}
// ----------------------------------------------------------------------------
