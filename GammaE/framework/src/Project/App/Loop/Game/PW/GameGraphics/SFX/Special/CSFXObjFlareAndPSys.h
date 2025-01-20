#ifndef CSFXObjFlareAndPSysH
#define CSFXObjFlareAndPSysH

#include <stdlib.h>
#include "Game/GameGraphics/sfx/CSFXObject.h"

class CSFXObjFlareAndPSys : public CSFXObject
{
	public:
			 CSFXObjFlareAndPSys();
			~CSFXObjFlareAndPSys();

			virtual void Init(MTH_CPoint3 &_oPos,int _iFType,int _iPType,bool _bPerturb,float _fLifeTime);
			virtual void Enable();
			virtual void Disable();
			virtual void Pos(MTH_CPoint3 &_oPos);

	protected:
			short sPSysID;
			short sFlareID;
			short sPerturbID;
};

#endif
