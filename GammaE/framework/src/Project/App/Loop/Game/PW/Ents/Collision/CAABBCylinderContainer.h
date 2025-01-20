// -----------------------------------------------------------------------------
#ifndef CAABBCylinderContainerH
#define CAABBCylinderContainerH
// -----------------------------------------------------------------------------
#include "antares.h"

// -----------------------------------------------------------------------------

typedef struct{

	float		fRad;
	float		fH;
	MTH_CMat4x4 oRS;

}TCylinder;
// -----------------------------------------------------------------------------
#define MAX_CYLINDERS 15
// -----------------------------------------------------------------------------
class CAABBCylinderContainer
{
	public:
			CAABBCylinderContainer();
			~CAABBCylinderContainer();
			
			void AddCylinder(int _iCylID,TCylinder* _poCylList);
			float fVolume();
			bool  bFull();
			void ComputeCylAABB(TCylinder* _poCyl,MTH_CPoint3& _oMax,MTH_CPoint3& _oMin);
			void Reset();
			void SetVolumeThreshold(float _fVT);

	public:
			MTH_CPoint3		m_oMaxs;
			MTH_CPoint3		m_oMins;
			float			m_fVT;
			unsigned int	m_uiNumCyls;
			TCylinder*		m_poCylList[MAX_CYLINDERS];
			int				m_iCylIDList[MAX_CYLINDERS];
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------