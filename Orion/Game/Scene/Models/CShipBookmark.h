// -----------------------------------------------------------
#ifndef CShipBookmark
#define CShipBookmark
// -----------------------------------------------------------

#include "GammaE.h"

// -----------------------------------------------------------
typedef struct{
	
	char	szName[8];
	CVect3  oPos;

}TControlPoint;
// -----------------------------------------------------------
typedef struct
{
	CObject3D	*poModel;
	CDynArray <TControlPoint> oCPs;

}TOrionObj;

// -----------------------------------------------------------
class COrionObjBookmark
{
	public:	 COrionObjBookmark();
			~COrionObjBookmark();
			
			static void LoadObjects();

			static CDynArray <TOrionObj> gObjBookmark;			
};

// -----------------------------------------------------------
#endif
// -----------------------------------------------------------