#include "Menu/CMenuTextGrid.h"
#include <string.h>


CMenuTextGrid::CMenuTextGrid()
{
}

void CMenuTextGrid::Init  (int _iCols,int _iMaxRows)
{
	iCols	 = _iCols;
	iMaxRows = _iMaxRows;
	iCurRow  = 0;

	CMesh::Init(4*iMaxRows*iCols,
				  iMaxRows*iCols,
				E3D_MESH_NIQUADS,
				MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);
}

void CMenuTextGrid::Reset()
{
	usNumPrims= 0;
	usNumVerts= 0;
	iCurRow   = 0;
}

void CMenuTextGrid::WriteChar(float _fX,float _fY, TFColor _oColor,char _cA)
{		
	const float fUVSize = 1.0f / 8.0f;
	float	fU,fV,u1,v1,u2,v2;
	int		iX,iY;

	// Get proper UV coords
	int iChar = _cA - 'A';
	if ((_cA >='A') && (_cA <='Z'))
	{
		iChar = _cA - 'A';
	}
else if ((_cA >='a') && (_cA <='z'))
	{
		iChar = (_cA-'a') + (2+3*8);
	}
else if ((_cA >='0') && (_cA <='9'))
	{
		iChar = (_cA + 17) + (3+6*8);
	}
else if (_cA == '?')
	{
		iChar = (8*8) - 2;
	}
else
	{
		// Point to the last char
		iChar = (8*8) - 1;
	}

	iX = iChar % 8;
	iY = iChar / 8;

	fU = (float)iX*fUVSize;
	fV = (float)iY*fUVSize;

	// Get data pointers
	CVect2 *poUV = UVs + 4*usNumPrims;
	CVect3 *poVX = VXs + 4*usNumPrims;
	CVect4 *poVC = VCs + 4*usNumPrims;

	// Setup vertices
	poVX[0].V3(_fX     ,_fY     ,0.0f);
	poVX[1].V3(_fX     ,_fY+1.0f,0.0f);
	poVX[2].V3(_fX+1.0f,_fY+1.0f,0.0f);
	poVX[3].V3(_fX+1.0f,_fY     ,0.0f);
	
	// Setup tex coords
	poUV[0].V2(fU        ,fV        );
	poUV[1].V2(fU        ,fV+fUVSize);
	poUV[2].V2(fU+fUVSize,fV+fUVSize);
	poUV[3].V2(fU+fUVSize,fV        );

	// Setup color
	poVC[0].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
	poVC[1].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
	poVC[2].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
	poVC[3].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);

	usNumPrims++;
	usNumVerts+=4;
}

void CMenuTextGrid::WriteXY  (float _fXOfs, float _fYOfs, TFColor _oColor,char *_szText)
{
	int iPos = 0;

	while (*_szText)
	{
		WriteChar(_fXOfs + (float)iPos,_fYOfs,_oColor,*_szText);
		
		iPos++;
		_szText++;
	}
}

void CMenuTextGrid::WriteText(char* _szText,TFColor _oColor,float _fAlpha)
{
	TFColor	oFinalColor;
	oFinalColor    = _oColor;
	oFinalColor.a *= _fAlpha;

	int		iStrLen = strlen(_szText);
	float	fXOfs = ((float)iCols - (float)iStrLen) * 0.5f;

	WriteXY(fXOfs,(float)iCurRow,oFinalColor,_szText);	
	iCurRow++;
}