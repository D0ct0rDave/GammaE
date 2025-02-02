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
#ifndef CGShaderUtilsH
#define CGShaderUtilsH
// ----------------------------------------------------------------------------
#include "Shaders/CGShader.h"
#include "Materials/CGMipMap.h"
#include "Materials/CGColor.h"
// ----------------------------------------------------------------------------
class CGShaderUtils
{
    public:

        CGShaderUtils();

        ~CGShaderUtils();

        static CGShader* poGenerateShaderFromMipMap(const CGMipMap* _poMip,const char* _szMatName);

        static CGShader* poGenerateShaderFromColor(const CGColor& _oColor, const char* _szMatName);

        static void SetupTilingFlags(int _iUTFlag, int _iVTFlag);

        static void SetupFilterFlags(int _iMinFFlag, int _iMagFFlag);

    protected:

        static int iUTFlag;

        static int iVTFlag;

        static int iMagFFlag;

        static int iMinFFlag;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
