// -----------------------------------------------------------------------------
#include "CSFXLaserManager.h"
// -----------------------------------------------------------------------------

CTex*			CSFXLaserManager::m_poTex = NULL;
CBBRenderer*	CSFXLaserManager::m_poBB  = NULL;
TLaserEntry		CSFXLaserManager::m_oLE[MAX_LASERS];
// -----------------------------------------------------------------------------

typedef struct{

	E3D_Color	m_oColor;
	float		m_fWidth;

}TLaserType;

const int MAX_LASER_TYPES = 4;
static TLaserType gsLaserTypes[MAX_LASER_TYPES] = 
{
	{ E3D_Color(1.0f,1.0f,1.0f,1.0f),  7.5f },
	{ E3D_Color(0.25f,0.0f,1.0f,1.0f),30.0f },
	{ E3D_Color(1.0f,1.0f,1.0f,1.0f), 10.0f },
};
// -----------------------------------------------------------------------------
void CSFXLaserManager::Init()
{
	// Load texture
	m_poTex = CTexMgr::poLoad("data/others/fx/part/fx_part8");
	
	// Initialize billboard object
	m_poBB = pNew CBBRenderer;
	m_poBB->Init(MAX_LASERS*4*2,8,false);

	Reset();
}
// -----------------------------------------------------------------------------
uint CSFXLaserManager::uiAddLaser(int _iType)
{
	// Look for a free laser entry
	for (int i=0;i<MAX_LASERS;i++)
	{	
		// Found a free one???
		if (m_oLE[i].m_iType == -1)
		{
			m_oLE[i].m_iType = _iType;
			return (i);
		}
	}

	return(-1);
}
// -----------------------------------------------------------------------------
void CSFXLaserManager::UpdateLaser(uint _uiID,MTH_CPoint3& _oIPos,MTH_CPoint3& _oFPos)
{
	m_oLE[_uiID].m_oFPos = _oFPos;
	m_oLE[_uiID].m_oIPos = _oIPos;
}
// -----------------------------------------------------------------------------
void CSFXLaserManager::Reset()
{
	// Initialize laser list
	memset(m_oLE,0,sizeof(m_oLE));
	
	// 
	for (int i=0;i<MAX_LASERS;i++)
		m_oLE[i].m_iType = -1;
}
// -----------------------------------------------------------------------------
void CSFXLaserManager::Update(float _fDeltaT)
{
	// loop through all particle types
	m_poBB->Reset();

	m_poBB->Begin(m_poTex,E3D_BM_ADD);
		
		for (int i=0;i<MAX_LASERS;i++)
		{	
			int iType = m_oLE[i].m_iType;
			
			if (iType != -1)
			{
				MTH_CPoint3 oIPos;				
				MTH_CPoint3 oFPos;

				oSFXViewMat.MultVec3 (m_oLE[i].m_oIPos,oIPos);
				oSFXViewMat.MultVec3 (m_oLE[i].m_oFPos,oFPos);

/*
				oIPos.z = -1.0f;
				oFPos.z = -1.0f;
*/

				m_poBB->AddStretchedBillboard(0.0f,gsLaserTypes[iType+1].m_fWidth,gsLaserTypes[iType+1].m_oColor.pfRGBA(),oFPos,oIPos);
				m_poBB->AddStretchedBillboard(0.0f,gsLaserTypes[iType].m_fWidth,gsLaserTypes[iType].m_oColor.pfRGBA(),oFPos,oIPos);

				/*
				oIPos.Set(100,i*20.0f,-910.0f);
				oFPos.Set(540,i*20.0f,-910.0f);
				m_poBB->AddStretchedBillboard(0.0f,10.0f,gsLaserTypes[iType].m_oColor.pfRGBA(),oFPos,oIPos);
				*/
			}
		}
				
	m_poBB->End();
}
// -----------------------------------------------------------------------------
void CSFXLaserManager::DeleteLaser(uint _uiID)
{
	m_oLE[_uiID].m_iType = -1;
}
// -----------------------------------------------------------------------------
void CSFXLaserManager::Render()
{
	gDC->ForceSetup(true);

		gDC->ResetContext();

		m_poBB->SetContext(0);
		m_poBB->Flush();
		m_poBB->RestoreContext(0);
	
	gDC->ForceSetup(false);
}
// -----------------------------------------------------------------------------