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
#include "CGScriptInstance.h"
#include "CGScriptResourceWH.h"
#include <lua.hpp>
// ----------------------------------------------------------------------------
CGScriptInstance::CGScriptInstance() : m_poResource(NULL)
{
}
// ----------------------------------------------------------------------------
CGScriptInstance::~CGScriptInstance()
{
}
// ----------------------------------------------------------------------------
CGScriptInstance::CGScriptInstance(const CGString& _sResource)
{
    Init(_sResource);
}
// ----------------------------------------------------------------------------
void CGScriptInstance::Init(const CGString& _sResource)
{
    if ( _sResource == "" ) return;

    CGScriptResource* poRes = CGScriptResourceWH::I()->poLoad(_sResource);
    ScriptResource(poRes);
}
// ----------------------------------------------------------------------------
void CGScriptInstance::Think(float _fDeltaT,void* _pParams)
{
    if ( m_poResource )
        m_poResource->Think(_fDeltaT,_pParams);
}
// ----------------------------------------------------------------------------
