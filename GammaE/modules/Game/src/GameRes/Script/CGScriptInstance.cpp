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
	if (_sResource=="") return;

	CGScriptResource* poRes = CGScriptResourceWH::I()->poLoad(_sResource);
	ScriptResource(poRes);
}
// ----------------------------------------------------------------------------
void CGScriptInstance::Think(float _fDeltaT,void* _pParams)
{
	if (m_poResource)
		m_poResource->Think(_fDeltaT,_pParams);
}
// ----------------------------------------------------------------------------
