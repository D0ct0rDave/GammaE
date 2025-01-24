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
#ifndef CGShaderWHH
#define CGShaderWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Shaders/CGShader.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGShaderWH,CGResourceWH,CGShader)
{
    public:
        CGShaderWH() {
        };

        virtual void Invalidate(int _iIdx = -1);
        void InvalidateElem(int _iIdx);
        CGShader* poCreateShader(const char* _szShaderName);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
