//## begin module%3C6AE3CE011E.cm preserve=no
//## end module%3C6AE3CE011E.cm

//## begin module%3C6AE3CE011E.cp preserve=no
//## end module%3C6AE3CE011E.cp

//## Module: CE3D_ShDefWH_Entry%3C6AE3CE011E; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderDefWarehouse\CE3D_ShDefWH_Entry.cpp

//## begin module%3C6AE3CE011E.additionalIncludes preserve=no
//## end module%3C6AE3CE011E.additionalIncludes

//## begin module%3C6AE3CE011E.includes preserve=yes
#include "memory/GammaE_mem.h"
#include <stdlib.h>
//## end module%3C6AE3CE011E.includes

// CE3D_ShDefWH_Entry
#include "E3D\Shaders\ShaderDefWarehouse\CE3D_ShDefWH_Entry.h"
//## begin module%3C6AE3CE011E.additionalDeclarations preserve=yes
//## end module%3C6AE3CE011E.additionalDeclarations


// Class CE3D_ShDefWH_Entry 




CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry()
  //## begin CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry%.hasinit preserve=no
      : szName(NULL), szDef(NULL)
  //## end CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry%.hasinit
  //## begin CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry%.initialization preserve=yes
  //## end CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry%.initialization
{
  //## begin CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry%.body preserve=yes
  //## end CE3D_ShDefWH_Entry::CE3D_ShDefWH_Entry%.body
}


CE3D_ShDefWH_Entry::~CE3D_ShDefWH_Entry()
{
  //## begin CE3D_ShDefWH_Entry::~CE3D_ShDefWH_Entry%.body preserve=yes
	if (szDef)	mFree(szDef);
	if (szName) mFree(szName);
  //## end CE3D_ShDefWH_Entry::~CE3D_ShDefWH_Entry%.body
}


// Additional Declarations
  //## begin CE3D_ShDefWH_Entry%3C6AE3CE011E.declarations preserve=yes
  //## end CE3D_ShDefWH_Entry%3C6AE3CE011E.declarations

//## begin module%3C6AE3CE011E.epilog preserve=yes
//## end module%3C6AE3CE011E.epilog
