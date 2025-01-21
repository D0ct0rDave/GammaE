// ----------------------------------------------------------------------------
#include "CGScriptResource.h"
#include "CGScriptingSystem.h"
#include <lua.hpp>
// ----------------------------------------------------------------------------
inline lua_State* luaState()
{
	return ( (lua_State*)CGScriptingSystem::I()->hHandler() );
}
// ----------------------------------------------------------------------------
CGScriptResource::CGScriptResource() : m_bLESuccessful(true)
{
	
}
// ----------------------------------------------------------------------------
CGScriptResource::~CGScriptResource()
{
	Finish();
}
// ----------------------------------------------------------------------------
void CGScriptResource::Init()
{
	int iRes = luaL_loadstring(luaState(),sGetData().szString());

	// int iRes = luaL_dostring(luaState(),sGetData().szString());
	// if (iRes == LUA_YIELD)
	//	iRes = lua_resume (luaState(),0);
}
// ----------------------------------------------------------------------------
void CGScriptResource::Finish()
{
}
// ----------------------------------------------------------------------------
class CGGameEntity;
static CGGameEntity* spoThis = NULL;

CGGameEntity* poThis()
{
	return( spoThis );
}
// ----------------------------------------------------------------------------
void CGScriptResource::Think(float _fDeltaT,void* _pParams)
{
	if (luaState() == NULL) return;
	
	spoThis = (CGGameEntity*)_pParams;

	// call the function with 0 argument and 0 results	
	int iRes = luaL_dostring(luaState(),sGetData().szString());

    if (iRes != 0)
    {
		if (m_bLESuccessful)
		{
			switch (iRes)
			{
				case LUA_ERRRUN:
					CGSystemLC::I()->Error("error de ejecución\n");
				break;

				case LUA_ERRMEM:
					CGSystemLC::I()->Error("error de reserva de memoria\n");
				break;

				case LUA_ERRERR:
					CGSystemLC::I()->Error("error mientras se está ejecutando la función manejadora de error\n");
				break;

				case LUA_ERRSYNTAX:
					CGSystemLC::I()->Error("Error de syntaxis\n");
				break;

				case LUA_YIELD:
					lua_resume (luaState(),NULL,0,NULL);
				break;
			}

			m_bLESuccessful = false;
		}
    }
    else
		m_bLESuccessful = true;

    //
}
// ----------------------------------------------------------------------------
