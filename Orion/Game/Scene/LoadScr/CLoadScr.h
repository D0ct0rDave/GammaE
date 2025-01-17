// --------------------------------------------------------------
#ifndef CLoadScrH
#define CLoadScrH
// --------------------------------------------------------------
#include "GammaE.h"
#include "Game/Scene/HUDElems/CHUDLabel.h"
#include "Game/Scene/HUDElems/CHUDIcon.h"

// --------------------------------------------------------------

class CLoadScr
{
	public:
			CLoadScr();
			~CLoadScr();

			void Init();
			void Render();
			void SetPercentage(float _fFact);

	private:
			CHUDLabel	*poMapName;
			CHUDLabel*	*poDesc;

			CHUDLabel	*poPK;

			CHUDIcon	*poBgrPic;
			CHUDIcon	*poMapImg;

			CE3D_Viewport			oLSCRHUDViewport;
			CE3D_Camera				oLSCROrthoCam;
			CE3D_Projector			oLSCROrthoPrj;
			CObject3D_Camera		oLSCRCam;
			CHeadUpDisplay			oLSCRHUD;
};
// --------------------------------------------------------------
#endif
// --------------------------------------------------------------