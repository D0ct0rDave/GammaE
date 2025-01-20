// -----------------------------------------------------------------------------
#include "CGEOGraphicInstance.h"
#include "CGraphicResourceMgr.h"
#include "antares.h"
#include "Cephei.h"
#include "SFX/Special/CSFXObjectFactory.h"
// -----------------------------------------------------------------------------
CGraphicInstance::CGraphicInstance()
{
}
// -----------------------------------------------------------------------------
CGraphicInstance::CGraphicInstance(char* _szResource)
{
	m_bVisible 	= false;
	m_bEnabled 	= false;
	m_fScale   	= 1.0f;
	m_oPos	   	= MTH_CPoint3::oZero();
	m_poResource= NULL;

	m_fPitch   	= 0.0f;
	m_fYaw   	= 0.0f;
	m_fRoll		= 0.0f;

	m_bDirty = false;

	Init(_szResource);
}
// -----------------------------------------------------------------------------
CGraphicInstance::~CGraphicInstance()
{

}
// -----------------------------------------------------------------------------
static char sszClassName[MAX_CHARS];

char* szClassName(char* _szObjName)
{
	char* szName = _szObjName;

	// Go to the end of the string
	while (*szName) szName++;
	
	//
	int iLen = strlen(_szObjName) - 1;

	// Go backwards to skip object numbers
	while ((iLen >= 0) && (_szObjName[iLen] >='0') && (_szObjName[iLen]<='9'))
		iLen--;

	// Terminate string
	strncpy(sszClassName,_szObjName,iLen+1);
	sszClassName[iLen+1] = 0;

	return(sszClassName);
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Init(char* _szResource)
{
	m_poResource = CGraphicResourceMgr::poGetResource(_szResource);

	// Parse Resource FX
	for (int i=0;i<m_poResource->m_poGeo->m_iSphNum;i++)
	{
		char* szName = szClassName( m_poResource->m_poGeo->m_poSphLst[i].m_acName );

		CSFXObject* poObj = CSFXObjectFactory::poGetInstance( szClassName(m_poResource->m_poGeo->m_poSphLst[i].m_acName) );
		
		if (poObj)
		{
			// Initialze common properties
			poObj->Init(m_poResource->m_poGeo->m_poSphLst[i].m_oPos);

			// Add objects
			m_oFX.iAdd(poObj);
		}
	}
}
// -----------------------------------------------------------------------------
void CGraphicInstance::UpdateTransform()
{
	if (m_bDirty == false) return;

	MTH_CMat4x4 oScale;
	oScale.Identity();
	oScale.Scale(m_fScale);
	
	MTH_CMat4x4 oTrans;
	oTrans.Translate(m_oPos);

	MTH_CMat4x4 oRX;
	oRX.RotateX(m_fPitch);

	MTH_CMat4x4 oRY;
	oRY.RotateY(m_fYaw);
	
	MTH_CMat4x4 oRZ;
	oRZ.RotateZ(m_fRoll);
	
	//
	m_oMat   = oTrans * oScale * oRX * oRY * oRZ;

	// Clear flag
	m_bDirty = false;
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Update(float _fDeltaT)
{
	if (! m_bEnabled) return;

	//
	UpdateTransform();

	// Update SFX
	for (int i=0;i<m_oFX.iGetNbElem();i++)
	{
		MTH_CPoint3 oNewPos;
		CSFXObject* poObj = m_oFX.roGetAt(i);
		m_oMat.MultVec3(poObj->m_oIPos,oNewPos);

		// Update position
		poObj->Pos(oNewPos);
	}
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Render()
{
	if (! m_bVisible) return;

	gDC->PushMatrix();

		gDC->MultMatrix(E3D_MM_MODELVIEW,m_oMat);

		// Render SFX
		for (int i=0;i<m_oFX.iGetNbElem();i++)
			m_oFX.roGetAt(i)->Render();

		// Render Object
		if (m_poResource)
			m_poResource->m_poGeo->Render();
	
	gDC->PopMatrix();
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Enable(bool _bEnable) 
{
	m_bEnabled = _bEnable;

	// Make visible sfx	
	for (int i=0;i<m_oFX.iGetNbElem();i++)
	{
		if ((_bEnable) && (m_bVisible))
			m_oFX.roGetAt(i)->Enable();
		else
			m_oFX.roGetAt(i)->Disable();
	}
}
// -----------------------------------------------------------------------------
void CGraphicInstance::Visible(bool _bEnable)
{
	m_bVisible=_bEnable;

	// Make visible sfx	
	for (int i=0;i<m_oFX.iGetNbElem();i++)
	{
		if ((_bEnable) && (m_bVisible))
			m_oFX.roGetAt(i)->Enable();
		else
			m_oFX.roGetAt(i)->Disable();
	}
}
// -----------------------------------------------------------------------------