



#include <string.h>
#include "GammaE_Mem.h"

// CConsole
#include "Console\CConsole.h"


// Class CConsole 













CConsole::CConsole()
        : Width(0), Height(0), Cols(0), Rows(0), BackgroundMat(NULL), CharMatrixMat(NULL), Background(NULL), CharMatrix(NULL), Data(NULL), MatrixMesh(NULL)
      {
    	Color.Set(1.0f,1.0f,1.0f,1.0f);
}


CConsole::~CConsole()
{
  	if (Data)		mDel []Data;	
}



void CConsole::Init (float _Width, float _Height, int _Cols, int _ows, CE3D_Shader* _BGMat, CE3D_Shader* _CMMat)
{
  	CHUD::Init(2);
	
	Cols   = _Cols;
	Rows   = _ows;

	Width  = _Width;
	Height = _Height;
	
	//Background de la consola	
	Data   = mNew char[Rows*Cols];
	
	Background = mNew CObject3D_Leaf;
	Background->SetMesh(mNew CMesh_Rect() );	
	Background->SetShader( _BGMat );
	Background->ComputeBoundVol();
	BackgroundMat = _BGMat;
	Background->poGetMesh()->UVs[0].y = 1;
	Background->poGetMesh()->UVs[1].y = 1;
	Background->poGetMesh()->UVs[2].y = 0;
	Background->poGetMesh()->UVs[3].y = 0;

	uiAddObject(Background,0,0,_Width,_Height,"ConsoleBackground");

	// Array de caracteres
	CreateCharMatrix ();

	CharMatrix = mNew  CObject3D_Leaf;
	CharMatrix->SetMesh(MatrixMesh);
	CharMatrix->SetShader( _CMMat);
	CharMatrix->ComputeBoundVol();	
	CharMatrixMat = _CMMat;
	uiAddObject(CharMatrix,0,0,_Width,_Height,"ConsoleCharMatrix");
}

void CConsole::Write (char* _szTex)
{
  	int   iX=0;
	int   iY=0;	

	while (*_szTex)
	{
		if (*_szTex >= ' ')
		{
			SetChar(iX % Cols,iY + (iX/Cols),*_szTex);
			iX++;
		}
		else
		{
			switch (*_szTex)
			{
				case 1:	// White
						Color.Set(1.0f,1.0f,1.0f,1.0f);
						break;
				case 2: // Black
						Color.Set(0.0f,0.0f,0.0f,1.0f);
						break;
				case 3: // Red
						Color.Set(1.0f,0.0f,0.0f,1.0f);
						break;
				case 4: // Green
						Color.Set(0.0f,1.0f,0.0f,1.0f);
						break;
				case 5: // Blue
						Color.Set(0.0f,0.0f,1.0f,1.0f);
						break;
				case 6: // Yellow
						Color.Set(1.0f,1.0f,0.0f,1.0f);
						break;
				case 7: // Dark Gray
						Color.Set(0.25f,0.25f,0.25f,1.0f);
						break;
				case '\n':iX  =0;
						  iY  ++;
						  break;
			}
		}
		_szTex++;
	}
}

void CConsole::WriteXY (int X, int Y, char *Text)
{
  	int iPos;	
	iPos = 0;
	while (*Text)
	{
		if (*Text >= ' ')
		{
			SetChar((X+iPos) % Cols,Y + ((X+iPos)/Cols),*Text);
			iPos ++;
		}
		else
			{
				switch (*Text)
				{
					case 1:	// White
							Color.Set(1.0f,1.0f,1.0f,1.0f);
							break;
					case 2: // Black
							Color.Set(0.0f,0.0f,0.0f,1.0f);
							break;
					case 3: // Red
							Color.Set(1.0f,0.0f,0.0f,1.0f);
							break;
					case 4: // Green
							Color.Set(0.0f,1.0f,0.0f,1.0f);
							break;
					case 5: // Blue
							Color.Set(0.0f,0.0f,1.0f,1.0f);
							break;
					case 6: // Yellow
							Color.Set(1.0f,1.0f,0.0f,1.0f);
							break;
					case 7: // Dark Gray
							Color.Set(0.25f,0.25f,0.25f,1.0f);
							break;
				}
			}
		Text++;
	}
}

void CConsole::Resize (float _Width, float _Height)
{
      Width  = _Width;
    Height = _Height;
	
	// Background resizing
	m_oHUDObjs[0]->tx = _Width;
	m_oHUDObjs[0]->ty = _Height;

	// Charmatrix resizing
	m_oHUDObjs[1]->tx = _Width;
	m_oHUDObjs[1]->ty = _Height;
}

void CConsole::SetChar (int _X, int _Y, char _a)
{
  	float	u1,v1,u2,v2;
	int		iIdx;

	int		iRow = _a / 16;		// Get the proper row in the font texture
	int		iCol = _a % 16;		// Get the proper col in the font texture
	u1 = (float)(iCol  )/16.0f;
	v1 = (float)(iRow  )/16.0f;
	u2 = (float)(iCol+1)/16.0f;
	v2 = (float)(iRow+1)/16.0f;

	// Setup UV coords
	// iIdx = ((Rows -1 - _Y)*Cols + _X) * 4;
	iIdx = (_Y*Cols + _X) * 4;

	MatrixMesh->UVs [iIdx + 0].V2(u1,v1);
	MatrixMesh->UVs [iIdx + 1].V2(u1,v2);
	MatrixMesh->UVs [iIdx + 2].V2(u2,v2);
	MatrixMesh->UVs [iIdx + 3].V2(u2,v1);

	// Setup color
	MatrixMesh->VCs [iIdx + 0] = Color;
	MatrixMesh->VCs [iIdx + 1] = Color;
	MatrixMesh->VCs [iIdx + 2] = Color;
	MatrixMesh->VCs [iIdx + 3] = Color;
}

void CConsole::CreateCharMatrix ()
{
  	int cI,cJ,iIdx;

	if (MatrixMesh) mDel MatrixMesh;

	MatrixMesh = mNew CMesh();
	MatrixMesh->Init(4*Rows*Cols,Rows*Cols,E3D_MESH_NIQUADS,MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);
	
	iIdx = 0;
	for (cJ=0;cJ<Rows;cJ++)
		for (cI=0;cI<Cols;cI++)
		{
			// row 0 has the greatest Y (0), last row is the lowest Y (-1)
			MatrixMesh->VXs [iIdx + 0].V3((float)(cI  )/Cols,(float)(cJ  )/Rows, 0);
			MatrixMesh->VXs [iIdx + 1].V3((float)(cI  )/Cols,(float)(cJ+1)/Rows, 0);
			MatrixMesh->VXs [iIdx + 2].V3((float)(cI+1)/Cols,(float)(cJ+1)/Rows, 0);
			MatrixMesh->VXs [iIdx + 3].V3((float)(cI+1)/Cols,(float)(cJ  )/Rows, 0);

			MatrixMesh->UVs [iIdx + 0].V2(0.0f,0.0f);
			MatrixMesh->UVs [iIdx + 1].V2(0.0f,0.0f);
			MatrixMesh->UVs [iIdx + 2].V2(0.0f,0.0f);
			MatrixMesh->UVs [iIdx + 3].V2(0.0f,0.0f);

			MatrixMesh->VCs [iIdx + 0].Set(1.0f,1.0f,1.0f,1.0f);
			MatrixMesh->VCs [iIdx + 1].Set(1.0f,1.0f,1.0f,1.0f);
			MatrixMesh->VCs [iIdx + 2].Set(1.0f,1.0f,1.0f,1.0f);
			MatrixMesh->VCs [iIdx + 3].Set(1.0f,1.0f,1.0f,1.0f);
			
			iIdx += 4;
		}

}

void CConsole::SetCharMatrixMat (CE3D_Shader *_CMMat)
{
  	CharMatrixMat = _CMMat;
	CharMatrix->SetShader( CharMatrixMat );
}

void CConsole::SetBackgroundMat (CE3D_Shader *_BGMat)
{
  	BackgroundMat = _BGMat;
	Background->SetShader( BackgroundMat );
}

// Additional Declarations
    
