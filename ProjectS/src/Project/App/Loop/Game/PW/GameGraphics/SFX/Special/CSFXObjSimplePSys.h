#ifndef CSFXObjSimplePSysH
#define CSFXObjSimplePSysH

#include <stdlib.h>
#include "Game/GameGraphics/sfx/CSFXObject.h"

class CSFXObjSimplePSys : public CSFXObject
{
	public:
			 CSFXObjSimplePSys();
			~CSFXObjSimplePSys();

			virtual void Init(MTH_CPoint3 &_oPos,int _iType,bool _bPerturb,float _fLifeTime);
			virtual void Enable();
			virtual void Disable();
			virtual void Pos(MTH_CPoint3 &_oPos);

	protected:
			short sID;
			short sPID;
};

#endif
