//-----------------------------------------------------------------------------
#ifndef CGSingleton_h
#define CGSingleton_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Mem.h"
//-----------------------------------------------------------------------------
#define DECLARE_SINGLETON(CLASSNAME)\
class CLASSNAME : public CGSingleton<CLASSNAME>

#define DECLARE_INHERITANT_SINGLETON(CLASSNAME,BASECLASSVISIBILITY,BASECLASS)\
class CLASSNAME : public CGSingleton<CLASSNAME>,BASECLASSVISIBILITY BASECLASS
//-----------------------------------------------------------------------------
template <class T>
class CGSingleton 
{ 
	protected:
    
		CGSingleton(){};

	public:
		static T* I()
		{
			static T* soInstance = mNew T;
			return soInstance;
		}
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
