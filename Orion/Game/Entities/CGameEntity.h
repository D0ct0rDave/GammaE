#ifndef CGameEntity_h
#define CGameEntity_h 1

#include "GammaE.h"

class CGameEntity 
{
		  public:	CGameEntity();
					~CGameEntity();

					virtual void Think (float _fDelta);
					bool bActive;
  
		  protected:

		  private:
		  private:
};

#endif
