// ----------------------------------------------------------------------------
#include "Shaders\CE3D_ShaderExtDB.h"
// ----------------------------------------------------------------------------
CGHashTable<void*> CE3D_ShaderExtDB::oExtDB;

// ----------------------------------------------------------------------------
CE3D_ShaderExtDB::CE3D_ShaderExtDB()
{
  	oExtDB.Init(10);
}
// ----------------------------------------------------------------------------
CE3D_ShaderExtDB::~CE3D_ShaderExtDB()
{
}
// ----------------------------------------------------------------------------
void CE3D_ShaderExtDB::AddExtension (char *_szExtensionName, void *_pExtensionFunc)
{
  	oExtDB.AddVar(_szExtensionName,_pExtensionFunc);
}
// ----------------------------------------------------------------------------
void * CE3D_ShaderExtDB::pGetExtension (char *_szExtensionName)
{
  	return ( oExtDB.poGetVar(_szExtensionName) );
}
// ----------------------------------------------------------------------------
void CE3D_ShaderExtDB::Invalidate ()
{
  	oExtDB.Invalidate();
}
// ----------------------------------------------------------------------------
// Additional Declarations
    
	//-----------------------------------------------------------------------------
	// epilog: singleton initializer through static instantiation
	//-----------------------------------------------------------------------------
	static CE3D_ShaderExtDB oInstance;

