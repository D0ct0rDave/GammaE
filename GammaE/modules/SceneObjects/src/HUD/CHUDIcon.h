//-----------------------------------------------------------------------------
#ifndef CHUDIconH
#define CHUDIconH
//-----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Scene.h"
#include "CHUDObject.h"
//-----------------------------------------------------------------------------
class CHUDIcon : public CHUDObject
{
	public:		CHUDIcon();
				virtual ~CHUDIcon();

				CGraphBV* poCreateBoundVol();

				void SetIcon(CE3D_Shader *_poShader);
	private:
				CObject3D_Leaf *poLeaf;
};

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
