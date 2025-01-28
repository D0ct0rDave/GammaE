// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
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
    int iRes = luaL_loadstring( luaState(),sGetData().szString() );

    // int iRes = luaL_dostring(luaState(),sGetData().szString());
    // if (iRes == LUA_YIELD)
    // iRes = lua_resume (luaState(),0);
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
    return(spoThis);
}
// ----------------------------------------------------------------------------
void CGScriptResource::Think(float _fDeltaT,void* _pParams)
{
    if ( luaState() == NULL ) return;

    spoThis = (CGGameEntity*)_pParams;

    // call the function with 0 argument and 0 results
    int iRes = luaL_dostring( luaState(),sGetData().szString() );

    if ( iRes != 0 )
    {
        if ( m_bLESuccessful )
        {
            switch ( iRes )
            {
                case LUA_ERRRUN:
                CGSystemLC::I()->Error("error de ejecuci�n\n");
                break;

                case LUA_ERRMEM:
                CGSystemLC::I()->Error("error de reserva de memoria\n");
                break;

                case LUA_ERRERR:
                CGSystemLC::I()->Error("error mientras se est� ejecutando la funci�n manejadora de error\n");
                break;

                case LUA_ERRSYNTAX:
                CGSystemLC::I()->Error("Error de syntaxis\n");
                break;

                case LUA_YIELD:
					int nresults;
					lua_resume (luaState(),NULL,0, &nresults);
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
