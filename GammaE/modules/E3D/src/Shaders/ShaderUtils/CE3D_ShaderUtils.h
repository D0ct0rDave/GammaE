//	  %X% %Q% %Z% %W%



#ifndef CE3D_ShaderUtils_h
#define CE3D_ShaderUtils_h 1



// GammaE_E3D
#include "GammaE_E3D.h"





class CE3D_ShaderUtils 
{
    
  public:
          CE3D_ShaderUtils();

          ~CE3D_ShaderUtils();


                static CE3D_Shader* poGenerateShaderFromMipMap (const CGMipMap* _poMip,const char *_szMatName);

            static CE3D_Shader* poGenerateShaderFromColor (const CGColor& _oColor, const char *_szMatName);

            static void SetupTilingFlags (int _iUTFlag, int _iVTFlag);

            static void SetupFilterFlags (int _iMinFFlag, int _iMagFFlag);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  static int iUTFlag;
      
                  static int iVTFlag;
      
                  static int iMagFFlag;
      
                  static int iMinFFlag;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CE3D_ShaderUtils 



#endif
