//-----------------------------------------------------------------------------
#include "CGScriptingSystem.h"
#include "lua.hpp"
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
	extern int luaopen_GammaE(lua_State* L); // declare the wrapped module
}
#endif
/*
//-----------------------------------------------------------------------------
static int CGScriptingSystem_iFunctionDispatcher(lua_State *L)
{
	// Retrieve the parameters
	uint		uiLenFunc  = 0;	
	const char* szStrFunc = NULL;
	// if (luaL_checkany(L,1))
	{
		szStrFunc = luaL_checkstring(L,1);
	}

	uint		uiLenPars  = 0;
	const char* szStrPars = NULL;
	// if (luaL_checkany(L,2))
	{
		szStrPars = luaL_optstring(L,2,NULL);
	}

	// Call the extension
	return( CGScriptingSystem::I()->pCallExtension( szStrFunc, szStrPars ) );
}
//-----------------------------------------------------------------------------
static const luaL_reg extensionLib[] = {
	
	{"Call", CGScriptingSystem_iFunctionDispatcher },
	{NULL, NULL}
};

LUALIB_API int luaopen_extensionLib(lua_State *L)
{
	luaL_register(L, "extensionLib", extensionLib);
	return 1;
}
*/
//-----------------------------------------------------------------------------
void CGScriptingSystem::Init()
{
	lua_State *L;

	L = lua_open();
	luaopen_base(L);			// load basic libs (eg. print)
	luaopen_string(L);
	int i = luaopen_GammaE(L);	// load the wrappered module

	m_hHnd = (handler)L;

	// Extensions
	m_oExtensionTable.Clear();
	
	//
	// luaopen_extensionLib(L);
}
//-----------------------------------------------------------------------------
void CGScriptingSystem::Finish()
{
	lua_close((lua_State*)m_hHnd);
}
//-----------------------------------------------------------------------------
void CGScriptingSystem::RegisterExtension(const CGString& _sFunctionName,void* _pFunctionCallback,const CGString& _sParameters,const CGString& _sResults)
{
	TExtension oExt = { _sFunctionName, _sParameters, _sResults ,_pFunctionCallback };
	m_oExtensionTable.uiAdd(oExt);
}
//-----------------------------------------------------------------------------
void *CGScriptingSystem::pCallExtension(const CGString& _sFunctionName,const CGString& _sFunctionParameters)
{
	for (uint i=0;i<m_oExtensionTable.uiNumElems();i++)
	{
		if (m_oExtensionTable[i].m_sFunctionName == _sFunctionName)
		{
			void* poRes = NULL;

			if (_sFunctionParameters != "")
			{
				typedef void*(*TFuncPointer )(const CGString& _sParameters);
				TFuncPointer Func = (TFuncPointer)m_oExtensionTable[i].m_pFunctionCallback;

				poRes = Func(_sFunctionParameters);
			}
			else
			{
				typedef void*(*TFuncPointer )(void);
				TFuncPointer Func = (TFuncPointer)m_oExtensionTable[i].m_pFunctionCallback;

				poRes = Func();
			}

			return((void*)poRes);
		}
	}

	return(NULL);
}
//-----------------------------------------------------------------------------
