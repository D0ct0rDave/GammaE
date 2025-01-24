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
#ifndef CGShaderParserH
#define CGShaderParserH
// ----------------------------------------------------------------------------CGShader
#include "Shaders\CGShader.h"
#include "GammaE_Math.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGShaderParser
{
    public:
        CGShaderParser();

        static CGShader* poCreateShaderFromTexture(const CGString& _sTexName);

        static CGShader* poParseShader(const CGString& _sShaderDefinition,const CGString& _sShaderName);

    protected:
        static void Parse_Color_General(char* _szDesc, float* _fR, float* _fG, float* _fB, float* _fA);

        static CGEvaluator* poParseEvaluator(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_Program(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_Texture(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_Color(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_Wireframe(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_Extension(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_BlendingOperation(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_TextureOperation(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_GeometricOperation(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_SetTMU(char*&_szDesc);

        static CGShaderInstruction* poParse_ShIns_ZOperation(char*&_szDesc);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
