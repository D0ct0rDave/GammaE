// ----------------------------------------------------------------------------
#ifndef CE3D_ShaderParser_h
#define CE3D_ShaderParser_h 1
// ----------------------------------------------------------------------------
// CE3D_Shader
#include "Shaders\CE3D_Shader.h"
// GammaE_Math
#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
class CE3D_ShaderParser 
{   
  public:
          CE3D_ShaderParser();

            static CE3D_Shader * poCreateShaderFromTexture (const CGString& _sTexName);

            static CE3D_Shader * poParseShader(const CGString& _sShaderDefinition,const CGString& _sShaderName);

  protected:
			static void Parse_Color_General (char* _szDesc, float* _fR, float* _fG, float* _fB, float* _fA);

            static CEvaluator * poParseEvaluator (char *&_szDesc);

			static CE3D_ShaderInstruction * poParse_ShIns_Program (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_Texture (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_Color (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_Wireframe (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_Extension (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_BlendingOperation (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_TextureOperation (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_GeometricOperation (char *&_szDesc);

            static CE3D_ShaderInstruction * poParse_ShIns_SetTMU (char *&_szDesc);
            
            static CE3D_ShaderInstruction * poParse_ShIns_ZOperation (char *&_szDesc);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
