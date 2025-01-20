// -----------------------------------------------------------------------------
#ifndef CEntCollisionH
#define CEntCollisionH
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "CVisEntity.h"
#include "EntityIDs.h"
#include "Collision/CAABBCylinderContainer.h"

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
typedef struct{
	
	CVisEntity* poEnt;
	float		fU0;	
	float		fU1;
	MTH_CPoint3	oP0;
	MTH_CPoint3	oP1;
	int			iColAxis;
	int			iNum;
	
}TCollisionInfo;

// -----------------------------------------------------------------------------
class CEntCollision
{
	public:	
		static void Init();
		static void Finish();

		// Utility functions
		static TCollisionInfo*	poCheckCollision(CVisEntity *_poEnt,unsigned int _uiTypesFlag);
		static TCollisionInfo*	poCheckCollision(CVisEntity* _poSrc,CVisEntity* _poDst);

		static TCollisionInfo*  poCheckParticleCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,unsigned int _uiTypesFlag);
		static TCollisionInfo*  poCheckParticleCollision(MTH_CPoint3& _oPos,MTH_CPoint3& _oOPos,CVisEntity* _poDst);
		
		static bool				bCheckPoint(MTH_CPoint3 &_oPos,CVisEntity *_poEnt);
		static CVisEntity*		poCheckPoint(MTH_CPoint3& _oPos,unsigned int _uiTypesFlag);

	public:
		static MEM_DynamicArray<TCylinder>*					m_poCL;
		static MEM_DynamicArray<CAABBCylinderContainer>*	m_poAABBCC;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------