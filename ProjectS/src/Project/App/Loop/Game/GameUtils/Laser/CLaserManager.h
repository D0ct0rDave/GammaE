// -----------------------------------------------------------------------------
#ifndef CLaserManagerH
#define CLaserManagerH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
typedef struct {

	int		m_iType;		// Type of laser

	CGVect3	m_oFPos;		// Final Position
	CGVect3	m_oIPos;		// Initial Position	

} TLaserEntry;
// -----------------------------------------------------------------------------
#define MAX_LASERS 128
// -----------------------------------------------------------------------------
class CLaserManager
{
public:
	static void Init();

	static uint uiAddLaser(int _iType);
	static void UpdateLaser(uint _uiID,const CGVect3& _roIPos,const CGVect3& _roFPos);
	static void DeleteLaser(uint _uiID);

	static void Reset();
	static void Update(float _fDeltaT);
	static void Render();

	private:
		static CGShader*		m_poShader;		// Shader used for neons
		static CGMesh*			m_poMesh;
		static TLaserEntry		m_oLE[MAX_LASERS];
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------