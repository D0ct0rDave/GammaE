#ifndef CHUDMsgBoxH
#define CHUDMsgBoxH

#include "GammaE_E3D.h"
#include "GammaE_Scene.h"

#include "CMenuTextGrid.h"

#define MAX_LINE_CHARS	64
#define MAX_MSG_LINES	128

typedef struct{
	char szLine[MAX_LINE_CHARS];
}TMsgLine;

class CHUDMsgBox : public CObject3D_Mux
{
	public:		CHUDMsgBox();
				virtual ~CHUDMsgBox();

				void Init (int _iRows,int _iCols);

				void Open (char *_szText);
				void Close();				

				void SetBackground(CE3D_Shader *_poShader);
				void SetFont      (CE3D_Shader *_poShader);		//
				void SetColor     (CGColor _oColor);			//
				
				void AdvanceHdr();
				void PutBackHdr();

				int iGetWidthChars();
				int iGetHeightChars();

	protected:	CGStArray <TMsgLine> oMsg;
				
				void SetText	  (char *_szText);				//
				void SetGText();								//
				void SetBackground();							//

				int	iHdrPos;


				CMenuTextGrid		oGTxt;
				CMesh_Rect			oBckRect;

				CObject3D_Leaf*		poTxtLeaf;
				
				CObject3D_Leaf*		poBckLeaf;
				CObject3D_Transf*	poBckTransf;

				CObject3D_Leaf*		poPrevIcLeaf;
				CObject3D_Transf*	poPrevIcTransf;
				
				CObject3D_Leaf*		poNextIcLeaf;
				CObject3D_Transf*	poNextIcTransf;

				CGColor			oColor;
				int				iRows;
				int				iCols;
};

#endif