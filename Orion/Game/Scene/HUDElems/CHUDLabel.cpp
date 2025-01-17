#include "CHUDLabel.h"
//--------------------------------------------------------------------------------
CHUDLabel::CHUDLabel()
{
	Init(1);

	// Create the text mesh
	CMesh *poMesh;

	poMesh = mNew CMesh;
	poMesh->Init(4*MAX_LABEL_CHARS,
				   MAX_LABEL_CHARS,
				   E3D_MESH_NIQUADS,
				   MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);

	CVect3 *poVX = poMesh->VXs;

	for (int cI=0;cI<MAX_LABEL_CHARS;cI++)
	{
		poVX[0].V3(cI  ,0.0f,0.0f);
		poVX[1].V3(cI  ,1.0f,0.0f);
		poVX[2].V3(cI+1,1.0f,0.0f);
		poVX[3].V3(cI+1,0.0f,0.0f);

		poVX+=4;
	}

	// Create the leaf
	poLeaf = mNew CObject3D_Leaf;
	poLeaf->SetMesh(poMesh);
	poLeaf->ComputeBoundVol();

	
	// Set leaf as child
	iAddObject(poLeaf);
	ComputeBoundVol();
}
//--------------------------------------------------------------------------------
CHUDLabel::~CHUDLabel()
{
}
//--------------------------------------------------------------------------------
void CHUDLabel::SetFont(CE3D_Shader *_poShader)
{
	poLeaf->SetShader( _poShader );
}
//--------------------------------------------------------------------------------
void CHUDLabel::SetColor(TFColor _oColor)
{
	if ((oColor.r == _oColor.r) && (oColor.g == _oColor.g) &&
	    (oColor.b == _oColor.b) && (oColor.a == _oColor.a)) return;

	oColor = _oColor;

	CVect4 *poVC = poLeaf->poGetMesh()->VCs;
	for (int cI=0;cI<MAX_LABEL_CHARS*4;cI++)
	{
		poVC->V4(oColor.r,oColor.g,oColor.b,oColor.a);
		poVC++;
	}
}
//--------------------------------------------------------------------------------
void CHUDLabel::WriteChar(char _cA)
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

	// Get UV pointer
	CVect2 *poUV = poLeaf->poGetMesh()->UVs + 4*poLeaf->poGetMesh()->usNumPrims;

	// Setup tex coords
	poUV[0].V2(fU        ,fV        );
	poUV[1].V2(fU        ,fV+fUVSize);
	poUV[2].V2(fU+fUVSize,fV+fUVSize);
	poUV[3].V2(fU+fUVSize,fV        );
}
//--------------------------------------------------------------------------------
void CHUDLabel::SetText(char *_szText)
{
	if (! strncmp(_szText,szText,MAX_LABEL_CHARS)) return;
	strncpy(szText,_szText,MAX_LABEL_CHARS);

	int cI,iLen = strlen(_szText);
	
	if (iLen>MAX_LABEL_CHARS) iLen=MAX_LABEL_CHARS;

	poLeaf->poGetMesh()->usNumPrims = 0;
	for (cI=0;cI<iLen;cI++)
	{		
		WriteChar(szText[cI]);
		poLeaf->poGetMesh()->usNumPrims++;
	}

	poLeaf->poGetMesh()->usNumVerts = poLeaf->poGetMesh()->usNumPrims*4;

	ComputeBoundVol();

	/*
	// Fill with spaces
	for (cI=iLen;cI<16;cI++)
		WriteChar(cI,oColor,' ');
	*/
}
//--------------------------------------------------------------------------------
void CHUDLabel::Enable()
{
	SelectAll();
}

void CHUDLabel::Disable()
{
	SelectNone();
}

void CHUDLabel::SetVisible(bool _bShow)
{
	if (_bShow) Enable(); else Disable();
}


//--------------------------------------------------------------------------------