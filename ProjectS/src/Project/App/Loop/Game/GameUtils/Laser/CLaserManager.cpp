// -----------------------------------------------------------------------------
#include "CLaserManager.h"
// -----------------------------------------------------------------------------

CE3D_Shader*	CLaserManager::m_poShader = NULL;
CMesh*			CLaserManager::m_poMesh = NULL;
TLaserEntry		CLaserManager::m_oLE[MAX_LASERS];
// -----------------------------------------------------------------------------

typedef struct{

	CGColor		m_oColor;
	float		m_fWidth;

}TLaserType;

const int MAX_LASER_TYPES = 4;
static TLaserType gsLaserTypes[MAX_LASER_TYPES] = 
{
	{ CGColor(1.0f,1.0f,1.0f,1.0f),  7.5f },
	{ CGColor(0.25f,0.0f,1.0f,1.0f),30.0f },
	{ CGColor(1.0f,1.0f,1.0f,1.0f), 10.0f },
};
// -----------------------------------------------------------------------------
void CLaserManager::Init()
{
	// Load texture
	m_poShader = CE3D_ShaderWH::I()->poCreateShader("data/textures/fx/fx_part8");
	
	// Initialize billboard object
	m_poMesh = mNew CMesh();
	m_poMesh->Init( MAX_LASERS*4*2,MAX_LASERS,
					E3D_MESH_QUADS,
					MESH_FIELD_VERTEXS  |
					MESH_FIELD_UVCOORDS |
					MESH_FIELD_COLORS   |
					MESH_FIELD_INDEXES);

	Reset();
}
// -----------------------------------------------------------------------------
uint CLaserManager::uiAddLaser(int _iType)
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
void CLaserManager::UpdateLaser(uint _uiID,const CVect3& _roIPos,const CVect3& _roFPos)
{
	m_oLE[_uiID].m_oFPos = _roFPos;
	m_oLE[_uiID].m_oIPos = _roIPos;
}
// -----------------------------------------------------------------------------
void CLaserManager::Reset()
{
	// Initialize laser list
	memset(m_oLE,0,sizeof(m_oLE));
	
	// 
	for (int i=0;i<MAX_LASERS;i++)
		m_oLE[i].m_iType = -1;
}
// -----------------------------------------------------------------------------
void CLaserManager::Update(float _fDeltaT)
{
	// loop through all particle types
	
	// m_poBB->Reset();
	// m_poBB->Begin(m_poTex,E3D_BM_ADD);
		
		for (int i=0;i<MAX_LASERS;i++)
		{	
			int iType = m_oLE[i].m_iType;
			
			if (iType != -1)
			{
				CVect3 oIPos;				
				CVect3 oFPos;
				/*
				oSFXViewMat.MultVec3 (m_oLE[i].m_oIPos,oIPos);
				oSFXViewMat.MultVec3 (m_oLE[i].m_oFPos,oFPos);

				m_poBB->AddStretchedBillboard(0.0f,gsLaserTypes[iType+1].m_fWidth,gsLaserTypes[iType+1].m_oColor.pfRGBA(),oFPos,oIPos);
				m_poBB->AddStretchedBillboard(0.0f,gsLaserTypes[iType].m_fWidth,gsLaserTypes[iType].m_oColor.pfRGBA(),oFPos,oIPos);
				*/
			}
		}
				
	// m_poShader->End();
}
// -----------------------------------------------------------------------------
void CLaserManager::DeleteLaser(uint _uiID)
{
	m_oLE[_uiID].m_iType = -1;
}
// -----------------------------------------------------------------------------
void CLaserManager::Render()
{
	/*
	gDC->ForceSetup(true);

		gDC->ResetContext();

		m_poBB->SetContext(0);
		m_poBB->Flush();
		m_poBB->RestoreContext(0);
	
	gDC->ForceSetup(false);
	*/
}
// -----------------------------------------------------------------------------