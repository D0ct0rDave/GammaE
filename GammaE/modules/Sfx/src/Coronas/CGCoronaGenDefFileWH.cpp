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
// ----------------------------------------------------------------------------
#include "CGCoronaGenDefFileWH.h"
#include "CGCoronaGenWH.h"
#include "CGCoronaGenStd.h"

// ----------------------------------------------------------------------------
void CGCoronaGenDefFileWH::ProcessCoronaGenDefFile(const CGString& _sCoronaDefFilename)
{
    CGConfigFile oCfg(_sCoronaDefFilename);

    if ( !oCfg.bInitialized() )
        return;

    uint uiNumDefs = oCfg.iGetInteger("General.NumDefinitions",0);

    for ( uint i = 0; i < uiNumDefs; i++ )
    {
        CGString sDef = CGString("Definition") + CGString(i);

        // Get the name of the Corona generator
        CGString sName = oCfg.sGetString(sDef + ".Name","");

        // Retrieve the Corona in case it's already defined
        CGCoronaGenerator* poTG = CGCoronaGenWH::I()->poFind(sName);

        // Get the type for this Corona generator
        CGString sType = oCfg.sGetString(sDef + ".Type","");

        // Retrieve common properties
        CGString sShader = oCfg.sGetString(sDef + ".Shader","");

        if ( sType |= "standard" )
        {
            // Retrieve color
            CGColor oIColor;
            CGColor oFColor;

            oIColor.r = oCfg.fGetFloat(sDef + ".IColor.r",0.0f);
            oIColor.g = oCfg.fGetFloat(sDef + ".IColor.g",0.0f);
            oIColor.b = oCfg.fGetFloat(sDef + ".IColor.b",0.0f);
            oIColor.a = oCfg.fGetFloat(sDef + ".IColor.a",0.0f);

            oFColor.r = oCfg.fGetFloat(sDef + ".FColor.r",0.0f);
            oFColor.g = oCfg.fGetFloat(sDef + ".FColor.g",0.0f);
            oFColor.b = oCfg.fGetFloat(sDef + ".FColor.b",0.0f);
            oFColor.a = oCfg.fGetFloat(sDef + ".FColor.a",0.0f);

            // Size
            float fISize = oCfg.fGetFloat(sDef + ".ISize",0.0f);
            float fFSize = oCfg.fGetFloat(sDef + ".FSize",0.0f);
            float fFreq = oCfg.fGetFloat(sDef + ".Freq",0.0f);
            CGString sCoronaFunction = oCfg.sGetString(sDef + ".CoronaFunc","");

            ECoronaFunction eCF = CF_Sin;

            if ( sCoronaFunction |= "Sin" )
            {
                eCF = CF_Sin;
            }
            /*
               else if (...)
             */

            if ( poTG == NULL )
            {
                poTG = mNew CGCoronaGenStd();
                CGCoronaGenWH::I()->uiAdd(poTG,sName);
            }

            CGCoronaGenStd* poTGS = (CGCoronaGenStd*)poTG;
            poTGS->SetColorPars(oIColor,oFColor);
            poTGS->SetSizePars(fISize,fFSize);
            poTGS->SetFuncPars(CF_Sin,fFreq);
        }

        poTG->SetShader( CE3D_ShaderWH::I()->poCreateShader( sShader.szString() ) );
    }
}
// ----------------------------------------------------------------------------
CGTextResource* CGCoronaGenDefFileWH::poLoadResource(const CGString& _sFilename)
{
    CGTextResource* poRes = mNew CGTextResource;
    // poRes->SetData( ParseUtils_ReadFile((char*)_sFilename.szString()) );
    // ProcessPSGDefFile( poRes->sGetData().szString() );

    ProcessCoronaGenDefFile( _sFilename );

    return (poRes);
}
// ----------------------------------------------------------------------------
void CGCoronaGenDefFileWH::Reload()
{
    ParentReload();
}
// ----------------------------------------------------------------------------
