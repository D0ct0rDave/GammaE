// -----------------------------------------------------------------------------
#ifndef CCollManagerH
#define CCollManagerH
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "CCollEntity.h"

// Entity List
#define 	MAX_ENTITY_TYPES	32

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
typedef struct{

	CCollEntity*	poSEnt;
	CCollEntity*	poDEnt;
	float			fU0;
	float			fU1;
	MTH_CPoint3		oP0;
	MTH_CPoint3		oP1;
	int				iColAxis;
	int				iNum;

}TCollisionInfo;
// -----------------------------------------------------------------------------
#define MAX_ENTITIES 1024
// -----------------------------------------------------------------------------
typedef void (* TCollisionCallback)(TCollisionInfo*);
// -----------------------------------------------------------------------------
class CCollManager
{
	public:
		static void Init();
		static void Finish();
		static void Step();

		static void RegisterCollisionTest(CCollEntity* _poEnt,unsigned int _uiEntMask);
		static void RegisterCollisionCallback(unsigned int _uiSrcEnt,unsigned int _uiDstEnt,TCollisionCallback* _poCB);

	public:
		static bool					m_bCTTable[MAX_ENTITY_TYPES][MAX_ENTITY_TYPES];			// Collision test table
		static TCollisionCallback	m_poCBTable[MAX_ENTITY_TYPES][MAX_ENTITY_TYPES];		// Collision test callback table
		static CCollEntity*			m_poCE[MAX_ENTITIES];
		static unsigned int			m_uiNumEnts;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------