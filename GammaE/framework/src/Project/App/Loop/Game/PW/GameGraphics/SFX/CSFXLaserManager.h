// -----------------------------------------------------------------------------
#ifndef CSFXLaserManagerH
#define CSFXLaserManagerH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "sfx.h"
// -----------------------------------------------------------------------------
typedef struct {

	int			m_iType;		// Type of laser

	MTH_CPoint3 m_oFPos;		// Final Position
	MTH_CPoint3 m_oIPos;		// Initial Position	

} TLaserEntry;
// -----------------------------------------------------------------------------
#define MAX_LASERS 128
// -----------------------------------------------------------------------------
class CSFXLaserManager
{
public:
	static void Init();

	static uint uiAddLaser(int _iType);
	static void UpdateLaser(uint _uiID,MTH_CPoint3& _oIPos,MTH_CPoint3& _oFPos);
	static void DeleteLaser(uint _uiID);

	static void Reset();
	static void Update(float _fDeltaT);
	static void Render();

	private:
		static CTex*			m_poTex;		// Texture used for neons
		static CBBRenderer*		m_poBB;
		static TLaserEntry		m_oLE[MAX_LASERS];
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------