// -----------------------------------------------------------------------------
#ifndef CGEOGraphicInstanceH
#define CGEOGraphicInstanceH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "CGraphicResource.h"
#include "sfx/CSFXObject.h"
// -----------------------------------------------------------------------------
class CGraphicInstance
{
public:
	 CGraphicInstance();

	CGraphicInstance(char* _szResource);
	~CGraphicInstance();

	virtual void Init(char* _szResource);

	virtual void Update(float _fDeltaT);
	virtual void Render();

	bool bVisible() { return(m_bVisible); };


	void Pos(MTH_CPoint3& _oPos) { m_oPos = _oPos; m_bDirty = true; };
	MTH_CPoint3& oPos() { return (m_oPos); };

	float fScale() {return (m_fScale); };
	void Scale(float _fScale) { m_fScale = _fScale; m_bDirty = true;};

	float fPitch() { return(m_fPitch); };
	void Pitch(float _fPitch) { m_fPitch = _fPitch; m_bDirty = true;};

	float fYaw() { return(m_fYaw); };
	void Yaw(float _fYaw) { m_fYaw = _fYaw; m_bDirty = true;};

	float fRoll() { return(m_fRoll); };
	void Roll(float _fRoll) { m_fRoll = _fRoll; m_bDirty = true;};

	bool bEnabled() { return(m_bEnabled); };
	void Enable(bool _bEnable);
	void Visible(bool _bEnable);
	
	CGraphicResource* poGraphicResource() { return (m_poResource); };
	MTH_CMat4x4& oTransform()
	{ 
		if (m_bDirty) UpdateTransform(); 
		return (m_oMat);
	};

protected:

	bool							m_bVisible;
	bool							m_bEnabled;
	
	// Transformation properties
	float							m_fScale;
	
	float							m_fPitch;
	float							m_fYaw;
	float							m_fRoll;

	MTH_CPoint3						m_oPos;
	bool							m_bDirty;
	MTH_CMat4x4						m_oMat;	
	
	void							UpdateTransform();
private: // This part depends on the kind of representation we choose for this game: we can choose sprites or 3D objects, etc

	// Representation Dependent Part
	CGraphicResource*				m_poResource;
	MEM_DynamicArray<CSFXObject*>	m_oFX;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------