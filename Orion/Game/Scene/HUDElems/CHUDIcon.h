#ifndef CHUDIconH
#define CHUDIconH


#include "GammaE.h"


class CHUDIcon : public CObject3D_Mux
{
	public:		CHUDIcon();
				~CHUDIcon();

				void SetIcon(CE3D_Shader *_poShader);

				void Enable();
				void Disable();
				void SetVisible(bool _bShow);
	private:
				CObject3D_Leaf *poLeaf;
};


#endif