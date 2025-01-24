// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#include "CGScriptResourceWH.h"
// ----------------------------------------------------------------------------
CGScriptResource* CGScriptResourceWH::poLoadResource(const CGString& _sFilename)
{
    CGScriptResource* poRes = mNew CGScriptResource;

    poRes->SetData( ParseUtils_ReadFile( (char*)_sFilename.szString() ) );
    poRes->Init();

    return(poRes);
}
// ----------------------------------------------------------------------------
