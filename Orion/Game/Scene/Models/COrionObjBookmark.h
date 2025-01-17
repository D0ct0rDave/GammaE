// -----------------------------------------------------------
#ifndef COrionObjBookmarkH
#define COrionObjBookmarkH
// -----------------------------------------------------------

#include "GammaE.h"
// -----------------------------------------------------------
enum eOrionObjBookmarkEntry{
	OOBE_MAP,
	OOBE_SPYDA,
	OOBE_PERSECUTOR,
	OOBE_BLASTER,
	OOBE_MISSILE,
	OOBE_BARREL,
	OOBE_LASER,
	OOBE_ELASER,
	OOBE_PLASMA,	

	OOBE_POWERUP,

	OOBE_PW_LASER,
	OOBE_PW_HBLASTER,
	OOBE_PW_CHAINGUN,
	OOBE_PW_RAILGUN,
	OOBE_PW_BFG,
	OOBE_PW_HOMMING,
	OOBE_PW_NAPALM,
	OOBE_PW_CONCUSSION,

	OOBE_NUMENTRIES
};
// -----------------------------------------------------------
typedef struct{
	
	char			szName[8];
	CVect3			oPos;
	
	unsigned char	ucCPType;
	unsigned char	ucSubType;
	unsigned char	ucDir;
	unsigned char	ucPad;

}TControlPoint;
// -----------------------------------------------------------
typedef struct{

	CObject3D *poModel;
	CDynArray <TControlPoint> oCPs;

}TOrionObj;

// -----------------------------------------------------------
class COrionObjBookmark
{
	public:	 COrionObjBookmark();
			~COrionObjBookmark();
			
			static void LoadObjects(char *_szMapFilename);
			static void ProcessControlPoints();
			static CStArray <TOrionObj*> gObjBookmark;			
			static void AddObject(char *_szFilename);
};

// -----------------------------------------------------------
#endif
// -----------------------------------------------------------