#include "CAABBCylinderContainer.h"

// -----------------------------------------------------------------------------
CAABBCylinderContainer::CAABBCylinderContainer()
{
	m_fVT = 1e16f;
	Reset();
}
// -----------------------------------------------------------------------------
CAABBCylinderContainer::~CAABBCylinderContainer()
{
}
// -----------------------------------------------------------------------------
void CAABBCylinderContainer::AddCylinder(int _iCylID,TCylinder* _poCyl)
{
	if (! bFull())
	{
		m_poCylList[m_uiNumCyls]  = _poCyl;
		m_iCylIDList[m_uiNumCyls] = _iCylID;
		m_uiNumCyls++;

		// Recalc AABB
		MTH_CPoint3 oMax,oMin;
		ComputeCylAABB(_poCyl,oMax,oMin);

		if (oMax.x > m_oMaxs.x) m_oMaxs.x = oMax.x;
		if (oMax.y > m_oMaxs.y) m_oMaxs.y = oMax.y;
		if (oMax.z > m_oMaxs.z) m_oMaxs.z = oMax.z;
		if (oMin.x < m_oMins.x) m_oMins.x = oMin.x;
		if (oMin.y < m_oMins.y) m_oMins.y = oMin.y;
		if (oMin.z < m_oMins.z) m_oMins.z = oMin.z;
	}
}
// -----------------------------------------------------------------------------
float CAABBCylinderContainer::fVolume()
{
	// float b*a*h
	MTH_CPoint3 oExt = m_oMaxs - m_oMins;
	return(oExt.x * oExt.y * oExt.z);
}
// -----------------------------------------------------------------------------
bool  CAABBCylinderContainer::bFull()
{
	// Politicas: 
	//		vamos metiendo cilindros en el AABB container hasta superar un volumen máximo o llegar al límite de la lista
	return ((fVolume() >m_fVT) || (m_uiNumCyls==MAX_CYLINDERS));
}
// -----------------------------------------------------------------------------
void CAABBCylinderContainer::ComputeCylAABB(TCylinder* _poCyl,MTH_CPoint3& _oMax,MTH_CPoint3& _oMin)
{
	MTH_CPoint3 oE0CC,oE1CC,oE2CC;
	oE0CC.Set( _poCyl->fRad,0, 0);
	oE1CC.Set( 0,_poCyl->fRad,0);
	oE2CC.Set( 0,0,_poCyl->fH);

	MTH_CPoint3 oE0,oE1,oE2;
	_poCyl->oRS.Mult3x3Vec3(oE0CC,oE0);
	_poCyl->oRS.Mult3x3Vec3(oE1CC,oE1);
	_poCyl->oRS.Mult3x3Vec3(oE2CC,oE2);

	MTH_CPoint3 oPos;
	_poCyl->oRS.GetCol3(&oPos);

	_oMax = oPos + oE0 + oE1 + oE2;
	_oMin = oPos - oE0 - oE1 - oE2;

	if (_oMin.x > _oMax.x){ float fTmp = _oMax.x; _oMax.x = _oMin.x; _oMin.x = fTmp;};
	if (_oMin.y > _oMax.y){ float fTmp = _oMax.y; _oMax.y = _oMin.y; _oMin.y = fTmp;};
	if (_oMin.z > _oMax.z){ float fTmp = _oMax.z; _oMax.z = _oMin.z; _oMin.z = fTmp;};
}
// -----------------------------------------------------------------------------
void CAABBCylinderContainer::Reset()
{
	m_oMaxs.Set(-1e6f,-1e6f,-1e6f);
	m_oMins.Set( 1e6f, 1e6f, 1e6f);

	m_uiNumCyls = 0;
}
// -----------------------------------------------------------------------------
void CAABBCylinderContainer::SetVolumeThreshold(float _fVT)
{
	m_fVT = _fVT;
}
// -----------------------------------------------------------------------------