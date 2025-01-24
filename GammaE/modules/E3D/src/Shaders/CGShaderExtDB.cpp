// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "Shaders\CGShaderExtDB.h"
// ----------------------------------------------------------------------------
CGHashTable <void*> CGShaderExtDB::oExtDB;

// ----------------------------------------------------------------------------
CGShaderExtDB::CGShaderExtDB()
{
    oExtDB.Init(10);
}
// ----------------------------------------------------------------------------
CGShaderExtDB::~CGShaderExtDB()
{
}
// ----------------------------------------------------------------------------
void CGShaderExtDB::AddExtension (char* _szExtensionName, void* _pExtensionFunc)
{
    oExtDB.AddVar(_szExtensionName,_pExtensionFunc);
}
// ----------------------------------------------------------------------------
void* CGShaderExtDB::pGetExtension (char* _szExtensionName)
{
    return ( oExtDB.poGetVar(_szExtensionName) );
}
// ----------------------------------------------------------------------------
void CGShaderExtDB::Invalidate ()
{
    oExtDB.Invalidate();
}
// ----------------------------------------------------------------------------epilog: singleton initializer through static instantiation
// ----------------------------------------------------------------------------
static CGShaderExtDB oInstance;
// ----------------------------------------------------------------------------
