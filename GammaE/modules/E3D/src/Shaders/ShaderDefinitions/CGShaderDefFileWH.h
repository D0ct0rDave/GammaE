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
#ifndef CGShaderDefFileWHH
#define CGShaderDefFileWHH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CGShaderDefFileWH,CGDiskResourceWH,CGTextResource)
{
    public:
        virtual CGTextResource* poLoadResource(const CGString& _sFilename);
        virtual void Reload();

    private:
        void AddShader (char* _szShaderString);
        void ProcessShaderDefFile(const CGString &_sShaderDefs);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
