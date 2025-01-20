//	  %X% %Q% %Z% %W%



#ifndef SCNUt_SceneCompiler_h
#define SCNUt_SceneCompiler_h 1



// CObject3D
#include "GammaE_Scene.h"





class SCNUt_SceneCompiler 
{
    
  public:
          SCNUt_SceneCompiler();

          ~SCNUt_SceneCompiler();

				CGraphBV* poCreateBoundVol (){ return( CGraphBV_Manager::poCreate() ); };

                void CompileScene (CObject3D* _poScn);

            void SetNULLMaterials (bool _bNULL);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  bool bNULLMaterials;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_SceneCompiler 


inline void SCNUt_SceneCompiler::SetNULLMaterials (bool _bNULL)
{
  	bNULLMaterials = _bNULL;
}



#endif
