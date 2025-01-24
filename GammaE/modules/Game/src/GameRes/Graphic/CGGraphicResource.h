// -----------------------------------------------------------------------------
#ifndef CGGraphicResourceH
#define CGGraphicResourceH
// -----------------------------------------------------------------------------
class CVect3;
class CObject3D;
// -----------------------------------------------------------
#include "GammaE_Math.h"
#include "GammaE_Misc.h"
#include "GammaE_Scene.h"
// -----------------------------------------------------------
class CGControlPoint
{
public:
	CGString		m_sName;
	CVect3			m_oPos;

	unsigned char	m_ucCPType;
	unsigned char	m_ucSubType;
	unsigned char	m_ucDir;
	unsigned char	m_ucPad;
};
// -----------------------------------------------------------------------------
class CGGraphicResource : public CGResource
{
public:
		CGGraphicResource(CObject3D* _poModel = NULL) {m_poModel = _poModel;};
		
		/// Retrieves a named control point 
		CGControlPoint* poGetCP(const CGString& _sCPName);
		
		/// Gets the model associated with the graphic resource
		CObject3D* poModel(){return (m_poModel); };
		
		/// Sets the model associated with the graphic resource
		void Model(CObject3D* _poModel){ m_poModel= _poModel; };

private:
		CObject3D*						m_poModel;
public:
		CGDynArray <CGControlPoint>		m_oCPs;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------