// ----------------------------------------------------------------------------
#ifndef SCNUt_AnimSceneLoader_h
#define SCNUt_AnimSceneLoader_h 1
// ----------------------------------------------------------------------------

#include "GammaE_Scene.h"
#include "SCNUt_TriScene.h"

// ----------------------------------------------------------------------------
class SCNUt_AnimSceneLoader 
{
    
  public:
			SCNUt_AnimSceneLoader();
			~SCNUt_AnimSceneLoader();

			CObject3D* poLoad (char* _szFilename);
			CGDynArray<CGString> m_oMaterials;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
