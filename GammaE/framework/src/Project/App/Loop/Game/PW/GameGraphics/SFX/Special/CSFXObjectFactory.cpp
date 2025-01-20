// ----------------------------------------------------------------------------
#include "CSFXObjectFactory.h"
#include "CSFXObjSimplePSys.h"
#include "CSFXObjFlareAndPSys.h"

// ----------------------------------------------------------------------------
// Creates instances of special SFX object
// Initializes them with specific properties
// Common (position,direction) initialization is performed by callers.
// ----------------------------------------------------------------------------
CSFXObject* CSFXObjectFactory::poGetInstance(char* _szSFXObject)
{
	SWITCH (_szSFXObject)
	{
		CASE("FX_Reactor")
		{
			CSFXObjFlareAndPSys* poObj = pNew CSFXObjFlareAndPSys;
			poObj->Init((MTH_CPoint3&)MTH_CPoint3::oZero(),3,3,false,-1.0f);

			return(poObj);
		}
		BREAK;

		CASE("Otro")		
		{
			CSFXObjSimplePSys* poObj = pNew CSFXObjSimplePSys;
			poObj->Init((MTH_CPoint3&)MTH_CPoint3::oZero(),3,false,-1.0f);

			return(poObj);
		}
		BREAK;

		DEFAULT_CASE
		{
			return(NULL);
		}
		BREAK;
	}
	END_SWITCH;
	
	return(NULL);
}
// ----------------------------------------------------------------------------