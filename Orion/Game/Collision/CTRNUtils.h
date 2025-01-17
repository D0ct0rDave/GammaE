#ifndef CTRNUtilsH
#define CTRNUtilsH

#include "GammaE.h"

class CTRNUtils
{
	public:	CTRNUtils();
			~CTRNUtils();
			
			static void Init();

			static float fGetHeight(CVect3 &_roPos);
			static float fGetHeight(float _fX,float _fY);
			static int iGetSector  (CVect3 &_roPos,int &_riXSect,int &_riYSect);
			static int iGetSector  (float _fX,float _fY,int &_riXSect,int &_riYSect);

			static bool bSunArrivesToPoint(CVect3 &_roPos);
			bool bIntersect(CVect3 &_roPos,CVect3 &_roPoint);
};

#endif
