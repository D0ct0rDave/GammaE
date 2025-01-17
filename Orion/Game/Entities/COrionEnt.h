// --------------------------------------------------------------
#ifndef COrionEntH
#define COrionEntH
// --------------------------------------------------------------
#include "CGameEntity.h"
#include "GammaE.h"
// --------------------------------------------------------------
// Collision information

typedef struct{
	
	CVect3			oOldPos;		// Old position
	CVect3			oPos;			// New position
	CGraphBV		*poBV;			// Bounding Volume

}TOrionCollider;
// --------------------------------------------------------------
typedef enum eOrionObjState
{
	OOST_NONE,
	OOST_SPAWN,
	OOST_ALIVE,
	OOST_BEGINEXPLOSION,
	OOST_EXPLODING,
	OOST_DEAD,
	OOST_NUM
};
// --------------------------------------------------------------
class COrionEnt : public CGameEntity
{
	public:		 COrionEnt();
				~COrionEnt();
	
				void Setup(int _iEntTypeID,int _iEntSubType,int _iModelIdx,CVect3 &_roPos);

				virtual void ProcessCmds(float _fDelta);
				virtual void Interact	(float _fDelta);

				int					iEntTypeID;		// Global entity type ID
				int					iEntSubType;	// Subtype entity
				int					iModelIdx;		// Index to the orion model bookmark
				eOrionObjState		eState;			// Orion Object State

				CObject3D_Transf	*poTransf;		// The object graphic instance
				TOrionCollider		oCol;			// Collider object

				COrionEnt			*poParent;		// Parent of this entity: NULL = world
				COrionEnt			*poInflictor;	// Who inflicted interaction with this entity
};

// --------------------------------------------------------------
#endif
// --------------------------------------------------------------