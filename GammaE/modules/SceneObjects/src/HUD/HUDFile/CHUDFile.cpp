//-----------------------------------------------------------------------------
#include "CHUDFile.h"
#include "GammaE_Misc.h"
#include "HUD/CHUDLabel.h"
#include "HUD/CHUDIcon.h"
#include "HUD/CHUDProgressBar.h"
#include "HUD/Font/CHUDFontWH.h"

//-----------------------------------------------------------------------------
CHUD* CHUDFile::poLoad(const CGString& _sFile)
{
	CGConfigFile oFile(_sFile);

	if(!oFile.bInitialized())
		return(NULL);

	CHUD* poHUD	= mNew CHUD;
	
	uint uiNumElems = oFile.iGetInteger("General.NumElems",0);
	CGString oUnits = oFile.sGetString("General.Units","Viewport");
	
	float fXMultiplier = 1.0f;
	float fYMultiplier = 1.0f;

	if (oUnits == "640x480")
	{
		fXMultiplier = 1.0f / 640.0f;
		fYMultiplier = 1.0f / 480.0f;
	}

	poHUD->Init(uiNumElems);
	
	for (uint i=0;i<uiNumElems;i++)
	{
		CHUDObject* poObj = NULL;
		
		// Build object identifier
		CGString sObj = CGString("Object") + CGString(i);

		// Common values
		CGString sName = oFile.sGetString(sObj+".Name","Nonamed");
		CGString sType = oFile.sGetString(sObj+".Type","NONE");

		float fX  = oFile.fGetFloat(sObj+".X",0);
		float fY  = oFile.fGetFloat(sObj+".Y",0);
		float fTX = oFile.fGetFloat(sObj+".TX",0);
		float fTY = oFile.fGetFloat(sObj+".TY",0);
		
		// Specific values
		if (sType |= "label")
		{
			CGString sText = oFile.sGetString(sObj+".Text","NONE");
			CGString sFont  = oFile.sGetString(sObj+".Font","");
		
			eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
			CGraphBV_Manager::SetBVMode(eGraphBV_Box);
			CHUDLabel* poLabel = mNew CHUDLabel( sText.uiLen() );
			CGraphBV_Manager::SetBVMode(eOldType);

			poObj = poLabel;

			// Set font name
			CHUDFont*poFont = CHUDFontWH::I()->poLoad( sFont );
			poLabel->SetFont(poFont);

			// Set label text
			poLabel->SetText( sText );

			// Color
			CGColor oColor;
			oColor.r = oFile.fGetFloat(sObj+".Color.R",1.0f);
			oColor.g = oFile.fGetFloat(sObj+".Color.G",1.0f);
			oColor.b = oFile.fGetFloat(sObj+".Color.B",1.0f);
			oColor.a = oFile.fGetFloat(sObj+".Color.A",1.0f);

			poLabel->SetColor(oColor);
		
		}
	else if (sType |= "icon")
		{
			CHUDIcon* poIcon = mNew CHUDIcon;
			poObj = poIcon;

			CGString sIcon = oFile.sGetString(sObj+".Icon","");
			poIcon->SetIcon( CE3D_ShaderWH::I()->poCreateShader( sIcon.szString() ) );
		}
	else if (sType |= "progressbar")
		{
			
		}

		if (poObj != NULL)
			poHUD->uiAddObject(poObj,fX*fXMultiplier,fY*fYMultiplier,fTX*fXMultiplier,fTY*fYMultiplier,sName);
	}

	poHUD->ComputeBoundVol();
	return( poHUD );
}
//-----------------------------------------------------------------------------
