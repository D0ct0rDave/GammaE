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
#include "CGPSGDefFileWH.h"
#include "CGPSysGenWH.h"
#include "CGPSGGenericQuad.h"
#include "CGPSGGenericQuadOrbit.h"
// ----------------------------------------------------------------------------
void CGPSGDefFileWH::ProcessPSGDefFile(const CGString& _sPSGDefFilename)
{
    CGConfigFile oCfg(_sPSGDefFilename);

    if ( !oCfg.bInitialized() )
        return;

    uint uiNumDefs = oCfg.iGetInteger("General.NumDefinitions",0);

    for ( uint i = 0; i < uiNumDefs; i++ )
    {
        CGString sDef = CGString("Definition") + CGString(i);

        // Get the name of the particle system generator
        CGString sName = oCfg.sGetString(sDef + ".Name","");

        // Retrieve the psg in case it's already defined
        CGParticleSystemGenerator* poPSG = CGPSysGenWH::I()->poFind(sName);

        // Get the type for this particle system generator
        CGString sType = oCfg.sGetString(sDef + ".Type","");

        // Retrieve common properties
        uint uiMaxParticles = oCfg.iGetInteger(sDef + ".NumParticles",0);
        float fIEnergy = oCfg.fGetFloat(sDef + ".Energy",0);
        float fIREnergy = oCfg.fGetFloat(sDef + ".RandomEnergy",0);
        CGString sShader = oCfg.sGetString(sDef + ".Shader","");

        if ( (sType |= "generic") || (sType |= "orbit") )
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

            float fIRFactor = oCfg.fGetFloat(sDef + ".IRCFactor",0.0f);
            float fFRFactor = oCfg.fGetFloat(sDef + ".FRCFactor",0.0f);

            // Size
            float fISize = oCfg.fGetFloat(sDef + ".ISize",0.0f);
            float fFSize = oCfg.fGetFloat(sDef + ".FSize",0.0f);
            float fIRSize = oCfg.fGetFloat(sDef + ".IRsize",0.0f);
            float fFRSize = oCfg.fGetFloat(sDef + ".FRsize",0.0f);

            // Angle
            float fIAngle = oCfg.fGetFloat(sDef + ".IAngle",0.0f);
            float fFAngle = oCfg.fGetFloat(sDef + ".FAngle",0.0f);
            float fIRAngle = oCfg.fGetFloat(sDef + ".IRAngle",0.0f);
            float fFRAngle = oCfg.fGetFloat(sDef + ".FRAngle",0.0f);

            // Radius
            float fIRadius = oCfg.fGetFloat(sDef + ".IRadius",0.0f);
            float fFRadius = oCfg.fGetFloat(sDef + ".FRadius",0.0f);
            float fIRRadius = oCfg.fGetFloat(sDef + ".IRRadius",0.0f);
            float fFRRadius = oCfg.fGetFloat(sDef + ".FRRadius",0.0f);

            if ( sType |= "orbit" )
            {
                CGPSGGenericQuadOrbit* poPSGO = NULL;

                if ( poPSG == NULL )
                {
                    poPSGO = mNew CGPSGGenericQuadOrbit();
                    poPSG = poPSGO;
                    CGPSysGenWH::I()->uiAdd(poPSG,sName);
                }
                else
                {
                    poPSGO = (CGPSGGenericQuadOrbit*)poPSG;
                }

                float fOrbitFactor = oCfg.fGetFloat(sDef + ".OrbitFactor",0.0f);
                poPSGO->SetOrbitFactor(fOrbitFactor);
            }
            else
            {
                if ( poPSG == NULL )
                {
                    poPSG = mNew CGPSGGenericQuad();
                    CGPSysGenWH::I()->uiAdd(poPSG,sName);
                }
            }

            CGPSGGenericQuad* poPSGQ = (CGPSGGenericQuad*)poPSG;

            poPSGQ->SetMaxParticles(uiMaxParticles);
            poPSGQ->SetEnergyFact(fIEnergy,fIREnergy);
            poPSGQ->SetColorsPars(oIColor,oFColor,fIRFactor,fFRFactor);
            poPSGQ->SetSizePars(fISize,fFSize,fIRSize,fFRSize);
            poPSGQ->SetAnglePars(fIAngle,fFAngle,fIRAngle,fFRAngle);
            poPSGQ->SetRadiusPars(fIRadius,fFRadius,fIRRadius,fFRRadius);
            poPSGQ->SetShader( CE3D_ShaderWH::I()->poCreateShader( sShader.szString() ) );
        }
    }
}
// ----------------------------------------------------------------------------
CGTextResource* CGPSGDefFileWH::poLoadResource(const CGString& _sFilename)
{
    CGTextResource* poRes = mNew CGTextResource;
    // poRes->SetData( Utils::Parse::ReadFile((char*)_sFilename.szString()) );
    // ProcessPSGDefFile( poRes->sGetData().szString() );

    ProcessPSGDefFile( _sFilename );

    return (poRes);
}
// ----------------------------------------------------------------------------
void CGPSGDefFileWH::Reload()
{
    ParentReload();
}
// ----------------------------------------------------------------------------
