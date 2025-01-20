// -----------------------------------------------------------------------------
#ifndef CSpriteGraphicInstanceH
#define CSpriteGraphicInstanceH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "CGraphicResource.h"

class CGraphicInstance
{
public:
	 CGraphicInstance();

	CGraphicInstance(char* _szResource);
	~CGraphicInstance();

	void Init(char* _szResource);

	void Update(float _fDeltaT);
	void Render();

	bool bVisible() { return(m_bVisible); };
	void Visible(bool _bEnable) {m_bVisible=_bEnable; }

	void Pos(MTH_CPoint3& _oPos);
	MTH_CPoint3 oPos();
	
	float fScale() {return (m_fScale); };
	void Scale(float _fScale) { m_fScale = _fScale; };

	bool bEnabled() { return(m_bEnabled); };
	void Enable(bool _bEnable) {m_bEnabled = _bEnable; }

	CGraphicResource* poGraphicResource() { return (m_poResource); };

protected:

	bool			m_bVisible;
	bool			m_bEnabled;
	float			m_fScale;

	MTH_CMat4x4		m_oMat;

private: // This part depends on the kind of representation we choose for this game: we can choose sprites or 3D objects, etc

	// Representation Dependent Part
	CGraphicResource* m_poResource;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------