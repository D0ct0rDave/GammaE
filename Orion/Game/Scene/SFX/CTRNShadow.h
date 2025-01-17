// ----------------------------------------------------
#ifndef CTRNShadowH
#define CTRNShadowH
// ----------------------------------------------------

#include "GammaE.h"

class CTRNShadow
{
	public:		CTRNShadow();
				~CTRNShadow();

				static void Setup (CObject3D *_poObj);
				static void Render();
	protected:
};

// ----------------------------------------------------
#endif
// ----------------------------------------------------