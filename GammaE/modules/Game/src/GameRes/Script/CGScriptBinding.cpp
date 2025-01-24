%module GammaE

%{
// #include "GammaE.h"
	#include "GammaE_Mem.h"
	#include "GammaE_Misc.h"
	#include "GammaE_Math.h"
	#include "GammaE_E3D.h"
	#include "GammaE_Scene.h"
	#include "GammaE_SceneObjects.h"
	#include "GammaE_Game.h"
%}
 

#include "GammaE_Mem.h"
#include "GammaE_Misc.h"
#include "GammaE_Math.h"
#include "GammaE_E3D.h"
#include "GammaE_Scene.h"
#include "GammaE_SceneObjects.h"
#include "GammaE_Game.h"

%inline %{
// ----------------------------------------------------------------------------
// Helper Functions
// ----------------------------------------------------------------------------
void DebugPrint(char* _szStr)
{
	CGStandardLC::I()->Write(_szStr);
}
//-----------------------------------------------------------------------------
void DebugClear()
{
	CGStandardLC::I()->poGetLogger()->szGetBuffer()[0] = 0;
}
//-----------------------------------------------------------------------------
void* CallExtension(char* _szFunction)
{
	void* pRes = CGScriptingSystem::I()->pCallExtension(CGString(_szFunction));
	return( pRes );
}
//-----------------------------------------------------------------------------
void* CallExtension(char* _szFunction,char* _szParameters)
{
	void* pRes = CGScriptingSystem::I()->pCallExtension(CGString(_szFunction), CGString(_szParameters));
	return( pRes );
}
//-----------------------------------------------------------------------------
uobject CGGameRegistry_oGetVar(char* _szVariable)
{
	return( CGGameRegistry::I()->oGetVar(_szVariable) );
}
//-----------------------------------------------------------------------------
void SpawnEntity(CGGameEntity* _poEnt,float _fTime)
{
	CGGameEntitySpawner::I()->Spawn(_poEnt,_fTime);
}
//-----------------------------------------------------------------------------
uint castto_uint(TEntityState _eState) { return((uint)_eState); };
CSmoother* castto_CSmoother(uobject _uoObj) { return((CSmoother*)_uoObj); };
CHUDLabel* castto_CHUDLabel(uobject _uoObj) { return((CHUDLabel*)_uoObj); };
CGGameEntity* castto_CGGameEntity(uobject _uoObj) { return((CGGameEntity*)_uoObj); };


class CGUObject
{
	public:
		CGUObject(uobject _uoObj)
		{
			m_uoObj = _uoObj;
		}

		//
		CSmoother*			toSmoother()		{ return( (CSmoother*)m_uoObj );	}
		//
		CHUDLabel*			toCHUDLabel()		{ return( (CHUDLabel*)m_uoObj );	}
		//
		CGGameEntity*		toCGGameEntity()	{ return( (CGGameEntity*)m_uoObj ); };
		
		uint				toUint()			{ return( (uint)m_uoObj );	}

	protected:
		uobject	m_uoObj;
};
/*
typedef CGSingleton<CGGameMessageMgr> TGameMessageMgr;
TGameMessageMgr GameMessageMgr()
{
	return( CGGameMessageMgr::I() );
}

typedef CGSingleton< CGStandardLC > TStandardLC;
TStandardLC StandardLC()
{
	return ( CGStandardLC::I() );
}
*/

//-----------------------------------------------------------------------------
%}

//-----------------------------------------------------------------------------
%{
CGGameEntity* poThis();
%}

CGGameEntity* poThis();

/*
%extend CGInputHandler {
	float fValue(const CGString& _sString)
	{
		return ( fGetValue(_sString) );
	}
}
*/