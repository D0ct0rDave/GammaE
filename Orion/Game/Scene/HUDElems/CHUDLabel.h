#ifndef CHUDLabelH
#define CHUDLabelH


#include "GammaE.h"

#define MAX_LABEL_CHARS	64
class CHUDLabel : public CObject3D_Mux
{
	public:		 CHUDLabel();
				~CHUDLabel();

				void SetFont(CE3D_Shader *_poShader);
				void SetText(char *_szText);
				void SetColor(TFColor _oColor);


				void Enable();
				void Disable();
				void SetVisible(bool _bShow);
	protected:	
				void WriteChar(char _cA);	

				CObject3D_Leaf	*poLeaf;
				char			szText[MAX_LABEL_CHARS];
				TFColor			oColor;
};

#endif