// -----------------------------------------------------------------------------
#include "CGEOGraphicResource.h"
#include "antares.h"
#include "Common/Graph/Anim/CActorMgr.h"
#include "Common/Graph/Anim/CEMFXMgr.h"
#include "C3DObjWH.h"
// -----------------------------------------------------------------------------
CGraphicResource::CGraphicResource(char* _szResource)
{
	// CEMFXMgr::Init(LOOP_3D_MEMORY_BLOCK);
	// int iA = CActorMgr::iLoadActor(_szResource,NULL);

	char szTexturePath[MAX_CHARS];
	strcpy(szTexturePath,_szResource);
	ExtractPath(szTexturePath);

	m_poGeo = C3DObjWH::poGetObj(_szResource,szTexturePath);
	
	m_oMaxs.Set(m_poGeo->m_fBBXMax,m_poGeo->m_fBBYMax,m_poGeo->m_fBBZMax);
	m_oMins.Set(m_poGeo->m_fBBXMin,m_poGeo->m_fBBYMin,m_poGeo->m_fBBZMin);
}
// -----------------------------------------------------------------------------
MTH_CPoint3 CGraphicResource::oGetCP(char* _szCPName)
{
	for (int i=0;i<m_poGeo->m_iSphNum;i++)
		if (! stricmp(m_poGeo->m_poSphLst[i].m_acName,_szCPName))
			return (m_poGeo->m_poSphLst[i].m_oPos);
	
	return (MTH_CPoint3::oZero());
}
// -----------------------------------------------------------------------------