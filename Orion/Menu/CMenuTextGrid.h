#ifndef CMenuTextGridH
#define CMenuTextGridH 

#include "E3D\Mesh\CMesh_Rect.h"
#include "Scene\2D_Objects\CHeadUpDisplay.h"
#include "Scene\CObject3D_Leaf.h"

class CMenuTextGrid : public CMesh
{
	public:
				CMenuTextGrid();

				void Init  (int _iCols,int _iMaxRows);
				void Reset();
				void WriteText(char* _szText,TFColor _oColor,float _fAlpha);

	protected:
				void WriteChar(float _fX,float _fY, TFColor _oColor,char _cA);
				void WriteXY  (float _fXOfs, float _fYOfs, TFColor _oColor,char *_szText);
				
				
				int		iCols;
				int		iMaxRows;
				int		iCurRow;
};


#endif
