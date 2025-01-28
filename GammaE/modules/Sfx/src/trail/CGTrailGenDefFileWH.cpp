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
#include "CGTrailGenDefFileWH.h"
#include "CGTrailGenWH.h"
#include "CGTrailGenStd.h"

// ----------------------------------------------------------------------------
void CGTrailGenDefFileWH::ProcessTrailGenDefFile(const CGString& _sTrailDefFilename)
{
    CGConfigFile oCfg(_sTrailDefFilename);

    if ( !oCfg.bInitialized() )
        return;

    uint uiNumDefs = oCfg.iGetInteger("General.NumDefinitions",0);

    for ( uint i = 0; i < uiNumDefs; i++ )
    {
        CGString sDef = CGString("Definition") + CGString(i);

        // Get the name of the trail generator
        CGString sName = oCfg.sGetString(sDef + ".Name","");

        // Retrieve the trail in case it's already defined
        CGTrailGenerator* poTG = CGTrailGenWH::I()->poFind(sName);

        // Get the type for this trail generator
        CGString sType = oCfg.sGetString(sDef + ".Type","");

        // Retrieve common properties
        uint uiMaxDivs = oCfg.iGetInteger(sDef + ".MaxDivisions",0);
        uint uiMaxPoints = oCfg.iGetInteger(sDef + ".MaxPoints",0);
        float fEnergy = oCfg.fGetFloat(sDef + ".Energy",0.0f);
        float fRndEnergy = oCfg.fGetFloat(sDef + ".RandomEnergy",0.0f);
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
            float fIRSize = oCfg.fGetFloat(sDef + ".IRsize",0.0f);
            float fFRSize = oCfg.fGetFloat(sDef + ".FRsize",0.0f);
            float fUpdateTime = oCfg.fGetFloat(sDef + ".UpdateTime",0.0f);

            if ( poTG == NULL )
            {
                poTG = mNew CGTrailGenStd();
                CGTrailGenWH::I()->uiAdd(poTG,sName);
            }

            CGTrailGenStd* poTGS = (CGTrailGenStd*)poTG;
            poTGS->SetColorPars(oIColor,oFColor);
            poTGS->SetSizePars(fISize,fIRSize,fFSize,fFRSize);
            poTGS->SetUpdateTimePar(fUpdateTime);
        }

        poTG->SetEnergyPars(fEnergy,fRndEnergy);
        poTG->SetMaxDivisions(uiMaxDivs);
        poTG->SetMaxPoints(uiMaxPoints);
        poTG->SetShader( CGShaderWH::I()->poCreateShader( sShader.szString() ) );
    }
}
// ----------------------------------------------------------------------------
CGTextResource* CGTrailGenDefFileWH::poLoadResource(const CGString& _sFilename)
{
    CGTextResource* poRes = mNew CGTextResource;
    // poRes->SetData( Utils::Parse::ReadFile((char*)_sFilename.szString()) );
    // ProcessPSGDefFile( poRes->sGetData().szString() );

    ProcessTrailGenDefFile( _sFilename );

    return (poRes);
}
// ----------------------------------------------------------------------------
void CGTrailGenDefFileWH::Reload()
{
    ParentReload();
}
// ----------------------------------------------------------------------------
