//-----------------------------------------------------------------------------
/*! \class CGVariableRegistry
 *  \brief A registry to store string values associated to variables
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGVariableRegistryH
#define CGVariableRegistryH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// -----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGVariableRegistry,public,CGLookupArray<CGString>)
{
	public:
		/// Retrieves the number of variables in the registry
		uint uiNumVariables() { return (m_oVars.uiNumElems() ); };

		/// Retrieves the variable name of a given element index
		const CGString& sGetVariable(uint _uiIdx) { return ( m_oVars[_uiIdx].m_sName ); };

		/// Retrieves the value of a given element index
		const CGString& sGetValue(uint _uiIdx) { return ( m_oVars[_uiIdx].m_oData ); };

		/// Retrieves the value of a given variable as a float value
		float fGetValue(const CGString& _sVariable);
		
		/// Retrieves the value of a given variable as an integer value
		int   iGetValue(const CGString& _sVariable);
		
		/// Retrieves the value of a given variable as a string value
		const CGString& sGetValue(const CGString& _sVariable);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
