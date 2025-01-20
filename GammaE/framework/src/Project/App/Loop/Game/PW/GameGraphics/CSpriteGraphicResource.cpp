// -----------------------------------------------------------------------------
#include "CSpriteGraphicResource.h"
#include "antares.h"
// -----------------------------------------------------------------------------
CGraphicResource::CGraphicResource(char* _szResource)
{
	m_poTex = CTexMgr::poLoad(_szResource);

	m_oMins.Set(0,0,0);
	m_oMaxs.Set(m_poTex->m_poTex->uiWidth() *((float)STD_SCR_WIDTH  / (float) SCR_WIDTH),
				m_poTex->m_poTex->uiHeight()*((float)STD_SCR_HEIGHT / (float)SCR_HEIGHT),
				0.0f);
	m_oMaxs.z = fMax(m_oMaxs.x,m_oMaxs.y);
}
// -----------------------------------------------------------------------------