//## begin module%3AA40E33028A.cm preserve=no
//## end module%3AA40E33028A.cm

//## begin module%3AA40E33028A.cp preserve=no
//## end module%3AA40E33028A.cp

//## Module: CE3D_RenderVars%3AA40E33028A; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\RenderVars\CE3D_RenderVars.cpp

//## begin module%3AA40E33028A.additionalIncludes preserve=no
//## end module%3AA40E33028A.additionalIncludes

//## begin module%3AA40E33028A.includes preserve=yes
#include <string.h>
//## end module%3AA40E33028A.includes

// CE3D_RenderVars
#include "E3D\RenderVars\CE3D_RenderVars.h"
//## begin module%3AA40E33028A.additionalDeclarations preserve=yes
//## end module%3AA40E33028A.additionalDeclarations


// Class CE3D_RenderVars 

//## begin CE3D_RenderVars::oVarTable%3C6E68B9012E.attr preserve=no  private: static CHashTable {UA} 
CHashTable CE3D_RenderVars::oVarTable;
//## end CE3D_RenderVars::oVarTable%3C6E68B9012E.attr

CE3D_RenderVars::CE3D_RenderVars()
  //## begin CE3D_RenderVars::CE3D_RenderVars%.hasinit preserve=no
  //## end CE3D_RenderVars::CE3D_RenderVars%.hasinit
  //## begin CE3D_RenderVars::CE3D_RenderVars%.initialization preserve=yes
  //## end CE3D_RenderVars::CE3D_RenderVars%.initialization
{
  //## begin CE3D_RenderVars::CE3D_RenderVars%.body preserve=yes
	oVarTable.Init(10,50);
  //## end CE3D_RenderVars::CE3D_RenderVars%.body
}


CE3D_RenderVars::~CE3D_RenderVars()
{
  //## begin CE3D_RenderVars::~CE3D_RenderVars%.body preserve=yes
  //## end CE3D_RenderVars::~CE3D_RenderVars%.body
}



//## Other Operations (implementation)
void CE3D_RenderVars::AddRenderVar (char *_szVariable, void *_pValue)
{
  //## begin CE3D_RenderVars::AddRenderVar%995233492.body preserve=yes
	oVarTable.AddVar(_szVariable,_pValue);
  //## end CE3D_RenderVars::AddRenderVar%995233492.body
}

void * CE3D_RenderVars::pGetRenderVar (char *_szVariable)
{
  //## begin CE3D_RenderVars::pGetRenderVar%995233493.body preserve=yes
	return ( oVarTable.pGetVar(_szVariable) );
  //## end CE3D_RenderVars::pGetRenderVar%995233493.body
}

// Additional Declarations
  //## begin CE3D_RenderVars%3AA40E33028A.declarations preserve=yes
	
	//---------------------------------------------------------------------------
	// epilog: singleton initializer through static instantiation
	//---------------------------------------------------------------------------
	static CE3D_RenderVars oIntance;

  //## end CE3D_RenderVars%3AA40E33028A.declarations
//## begin module%3AA40E33028A.epilog preserve=yes
//## end module%3AA40E33028A.epilog
