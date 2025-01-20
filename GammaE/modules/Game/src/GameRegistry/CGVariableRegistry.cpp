// -----------------------------------------------------------------------------
#include "CGVariableRegistry.h"
// -----------------------------------------------------------------------------
/*
#define DECLARE_INHERITANT_SINGLETON(CLASSNAME,BASECLASSVISIBILITY,BASECLASS)\
class CLASSNAME : public CGSingleton<CLASSNAME>,BASECLASSVISIBILITY BASECLASS
*/

float CGVariableRegistry::fGetValue(const CGString& _sVariable)
{
	return(0.0f);
}
// -----------------------------------------------------------------------------
int CGVariableRegistry::iGetValue(const CGString& _sVariable)
{
	return(0);
}
// -----------------------------------------------------------------------------
const CGString& CGVariableRegistry::sGetValue(const CGString& _sVariable)
{
	return( _sVariable );
}
// -----------------------------------------------------------------------------

