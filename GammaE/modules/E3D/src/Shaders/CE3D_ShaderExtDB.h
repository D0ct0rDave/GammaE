// ----------------------------------------------------------------------------
#ifndef CE3D_ShaderExtDB_h
#define CE3D_ShaderExtDB_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CE3D_ShaderExtDB 
{
    
  public:
		CE3D_ShaderExtDB();

		~CE3D_ShaderExtDB();

		static void AddExtension (char *_szExtensionName, void *_pExtensionFunc);

		static void * pGetExtension (char *_szExtensionName);

		static void Invalidate ();

  private:

		static CGHashTable<void*> oExtDB;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------


