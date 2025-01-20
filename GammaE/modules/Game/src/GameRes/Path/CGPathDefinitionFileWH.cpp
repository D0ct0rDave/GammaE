#include "CGPathDefinitionFileWH.h"
#include "CGPathResourceWH.h"
#include "CGPath.h"
#include "CGCurvePath.h"
#include "CGSpiralPath.h"
// ----------------------------------------------------------------------------
void CGPathDefinitionFileWH::ProcessPathDefFile(const CGString& _sPathDefFilename)
{
	CGConfigFile oCfg(_sPathDefFilename);

	if (! oCfg.bInitialized())
		return;	
	
	uint uiNumDefs = oCfg.iGetInteger("General.NumPaths",0);
	
	for (uint j=0;j<uiNumDefs;j++)
	{
		CGString sDef  = CGString("Path") + CGString(j);

		// Get the type for this path
		CGString sType      =  oCfg.sGetString(sDef+".Type","");

		// Retrieve the path in case it's already defined
		CGPathResource* poPR = CGPathResourceWH::I()->poFind(sDef);

		// If the path doesn't exist, create a new one and add to the warehouse
		if (poPR == NULL)
		{			
			poPR = mNew CGPathResource;
			CGPathResourceWH::I()->uiAdd(poPR,sDef);
		}

		// Read path properties
		if (sType |= "curve")
		{
			CCurveDynamic* poCurve = mNew CCurveDynamic;
			// Read the number of control points of the path
			uint uiNumPoints = oCfg.iGetInteger(sDef+".NumPoints",0);
			
			// Read the points
			for (uint i=0;i<uiNumPoints;i++)
			{
				CGString sVar = sDef + ".Point" + CGString(i);		
				CVect3 oP;				
				
				oP.x = oCfg.fGetFloat(sVar+".x",0.0f);
				oP.y = oCfg.fGetFloat(sVar+".y",0.0f);
				oP.z = oCfg.fGetFloat(sVar+".z",0.0f);
				
				poCurve->AddPoint(oP);
			}

			CGCurvePath* poCP = mNew CGCurvePath;
			poCP->Init(poCurve);
			poPR->SetPath( poCP );
		}
else if (sType |= "spiral")
		{
			CGSpiralPath* poCP     = mNew CGSpiralPath;
			poPR->SetPath( poCP );

			TSpiralPathParams oSPP;
			
			// Read the number of control points of the path
			oSPP.m_fPathTime     = oCfg.fGetFloat(sDef+".LifeTime",0.0f);

			// Read initial position
			oSPP.m_oInitialPos.x = oCfg.fGetFloat(sDef+".InitialPos.x",0.0f);
			oSPP.m_oInitialPos.y = oCfg.fGetFloat(sDef+".InitialPos.y",0.0f);
			oSPP.m_oInitialPos.z = oCfg.fGetFloat(sDef+".InitialPos.z",0.0f);

			// Read speed
			oSPP.m_oSpeed.x = oCfg.fGetFloat(sDef+".Speed.x",0.0f);
			oSPP.m_oSpeed.y = oCfg.fGetFloat(sDef+".Speed.y",0.0f);
			oSPP.m_oSpeed.z = oCfg.fGetFloat(sDef+".Speed.z",0.0f);

			// Read initial radius
			oSPP.m_oInitialRadius.x = oCfg.fGetFloat(sDef+".InitialRadius.x",0.0f);
			oSPP.m_oInitialRadius.y = oCfg.fGetFloat(sDef+".InitialRadius.y",0.0f);
			oSPP.m_oInitialRadius.z = oCfg.fGetFloat(sDef+".InitialRadius.z",0.0f);

			// Read radius speed
			oSPP.m_oRadiusSpeed.x = oCfg.fGetFloat(sDef+".RadiusSpeed.x",0.0f);
			oSPP.m_oRadiusSpeed.y = oCfg.fGetFloat(sDef+".RadiusSpeed.y",0.0f);
			oSPP.m_oRadiusSpeed.z = oCfg.fGetFloat(sDef+".RadiusSpeed.z",0.0f);

			// Read initial Phase
			oSPP.m_oInitialPhase.x = oCfg.fGetFloat(sDef+".InitialPhase.x",0.0f);
			oSPP.m_oInitialPhase.y = oCfg.fGetFloat(sDef+".InitialPhase.y",0.0f);
			oSPP.m_oInitialPhase.z = oCfg.fGetFloat(sDef+".InitialPhase.z",0.0f);

			// Read angular speed
			oSPP.m_oAngularSpeed.x = oCfg.fGetFloat(sDef+".AngularSpeed.x",0.0f);
			oSPP.m_oAngularSpeed.y = oCfg.fGetFloat(sDef+".AngularSpeed.y",0.0f);
			oSPP.m_oAngularSpeed.z = oCfg.fGetFloat(sDef+".AngularSpeed.z",0.0f);
			
			poCP->Init(oSPP);			
		}
	}
}
// ----------------------------------------------------------------------------
CGTextResource* CGPathDefinitionFileWH::poLoadResource(const CGString &_sFilename)
{
	CGTextResource* poRes = mNew CGTextResource;
	// poRes->SetData( ParseUtils_ReadFile((char*)_sFilename.szString()) );
	// ProcessPSGDefFile( poRes->sGetData().szString() );

	ProcessPathDefFile( _sFilename );

	return ( poRes );
}
// ----------------------------------------------------------------------------
