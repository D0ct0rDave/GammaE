//## begin module%3BD358A00059.cm preserve=no
//## end module%3BD358A00059.cm

//## begin module%3BD358A00059.cp preserve=no
//## end module%3BD358A00059.cp

//## Module: CE3D_ShaderExtDB%3BD358A00059; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\CE3D_ShaderExtDB.cpp

//## begin module%3BD358A00059.additionalIncludes preserve=no
//## end module%3BD358A00059.additionalIncludes

//## begin module%3BD358A00059.includes preserve=yes
//## end module%3BD358A00059.includes

// CE3D_ShaderExtDB
#include "E3D\Shaders\CE3D_ShaderExtDB.h"
//## begin module%3BD358A00059.additionalDeclarations preserve=yes
//## end module%3BD358A00059.additionalDeclarations


// Class CE3D_ShaderExtDB 

//## begin CE3D_ShaderExtDB::oExtDB%3BD3590702F6.attr preserve=no  private: static CHashTable {UA} 
CHashTable CE3D_ShaderExtDB::oExtDB;
//## end CE3D_ShaderExtDB::oExtDB%3BD3590702F6.attr

CE3D_ShaderExtDB::CE3D_ShaderExtDB()
  //## begin CE3D_ShaderExtDB::CE3D_ShaderExtDB%.hasinit preserve=no
  //## end CE3D_ShaderExtDB::CE3D_ShaderExtDB%.hasinit
  //## begin CE3D_ShaderExtDB::CE3D_ShaderExtDB%.initialization preserve=yes
  //## end CE3D_ShaderExtDB::CE3D_ShaderExtDB%.initialization
{
  //## begin CE3D_ShaderExtDB::CE3D_ShaderExtDB%.body preserve=yes
	oExtDB.Init(3,10);
  //## end CE3D_ShaderExtDB::CE3D_ShaderExtDB%.body
}


CE3D_ShaderExtDB::~CE3D_ShaderExtDB()
{
  //## begin CE3D_ShaderExtDB::~CE3D_ShaderExtDB%.body preserve=yes
  //## end CE3D_ShaderExtDB::~CE3D_ShaderExtDB%.body
}



//## Other Operations (implementation)
void CE3D_ShaderExtDB::AddExtension (char *_szExtensionName, void *_pExtensionFunc)
{
  //## begin CE3D_ShaderExtDB::AddExtension%1003698097.body preserve=yes
	oExtDB.AddVar(_szExtensionName,_pExtensionFunc);
  //## end CE3D_ShaderExtDB::AddExtension%1003698097.body
}

void * CE3D_ShaderExtDB::pGetExtension (char *_szExtensionName)
{
  //## begin CE3D_ShaderExtDB::pGetExtension%1003698098.body preserve=yes
	return ( oExtDB.pGetVar(_szExtensionName) );
  //## end CE3D_ShaderExtDB::pGetExtension%1003698098.body
}

// Additional Declarations
  //## begin CE3D_ShaderExtDB%3BD358A00059.declarations preserve=yes
  //## end CE3D_ShaderExtDB%3BD358A00059.declarations

//## begin module%3BD358A00059.epilog preserve=yes
//---------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
//---------------------------------------------------------------------------
static CE3D_ShaderExtDB oInstance;
//## end module%3BD358A00059.epilog
