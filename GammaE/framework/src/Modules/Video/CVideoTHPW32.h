// ----------------------------------------------------------------------------
#ifndef CVideoTHPW32H
#define CVideoTHPW32H
// ----------------------------------------------------------------------------
#include "GammaE.h"
// ----------------------------------------------------------------------------
class CVideo
{
	public:
		static bool bInit(char* _szStr);
		static void Finish();
 		static void Update(float _fDeltaT);
		static void Render();
		static CE3D_Shader* poGetFrame();

	protected:
		static void DecodeFrame();
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------