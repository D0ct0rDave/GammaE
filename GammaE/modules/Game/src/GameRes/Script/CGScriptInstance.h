// -----------------------------------------------------------------------------
#ifndef CGScriptInstanceH
#define CGScriptInstanceH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGScriptResource.h"
// -----------------------------------------------------------------------------
class CGScriptInstance
{
public:
		CGScriptInstance();
		
		CGScriptInstance(CGScriptResource* _poResource) { m_poResource = _poResource; };
		CGScriptInstance(const CGString& _sResource);
		~CGScriptInstance();

		/// Initializes a script instance of a given resource
		virtual void Init(const CGString& _sResource);
		
		/// Performs a step in the logic of the instance
		void Think(float _fDeltaT,void* _pParams);
		
		/// Retrieves a reference of the instance script resource
		CGScriptResource* poScriptResource() { return (m_poResource); };		
		
		/// Sets the reference of the instance script resource
		void ScriptResource(CGScriptResource* _poResource) { m_poResource = _poResource; };

protected:
		CGScriptResource*	m_poResource;
};	
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------