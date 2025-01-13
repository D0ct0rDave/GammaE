//## begin module%3AF6F98F00DC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF6F98F00DC.cm

//## begin module%3AF6F98F00DC.cp preserve=no
//## end module%3AF6F98F00DC.cp

//## Module: CConsole%3AF6F98F00DC; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\Console\CConsole.cpp

//## begin module%3AF6F98F00DC.additionalIncludes preserve=no
//## end module%3AF6F98F00DC.additionalIncludes

//## begin module%3AF6F98F00DC.includes preserve=yes
#include <string.h>
#include "memory/gammae_mem.h"
//## end module%3AF6F98F00DC.includes

// CConsole
#include "SceneObjects\Console\CConsole.h"
//## begin module%3AF6F98F00DC.additionalDeclarations preserve=yes
//## end module%3AF6F98F00DC.additionalDeclarations


// Class CConsole 













CConsole::CConsole()
  //## begin CConsole::CConsole%.hasinit preserve=no
      : Width(0), Height(0), Cols(0), Rows(0), BackgroundMat(NULL), CharMatrixMat(NULL), Background(NULL), CharMatrix(NULL), Data(NULL), MatrixMesh(NULL)
  //## end CConsole::CConsole%.hasinit
  //## begin CConsole::CConsole%.initialization preserve=yes
  //## end CConsole::CConsole%.initialization
{
  //## begin CConsole::CConsole%.body preserve=yes
  	Color.V4(1.0f,1.0f,1.0f,1.0f);
  //## end CConsole::CConsole%.body
}


CConsole::~CConsole()
{
  //## begin CConsole::~CConsole%.body preserve=yes
	if (Data)		mDel []Data;	
  //## end CConsole::~CConsole%.body
}



//## Other Operations (implementation)
void CConsole::Init (float _Width, float _Height, int _Cols, int _Rows, CE3D_Shader* _BGMat, CE3D_Shader* _CMMat)
{
  //## begin CConsole::Init%989264851.body preserve=yes
	CHeadUpDisplay::Init(2);
	
	Cols   = _Cols;
	Rows   = _Rows;

	Width  = _Width;
	Height = _Height;
	
	//Background de la consola	
	Data   = mNew char[Rows*Cols];
	
	Background = mNew CObject3D_Leaf;
	Background->SetMesh(mNew CMesh_Rect() );	
	Background->SetShader( _BGMat );
	Background->ComputeBoundVol();
	BackgroundMat = _BGMat;
	AddObject(Background,0,0,_Width,_Height);

	// Array de caracteres
	CreateCharMatrix ();

	CharMatrix = mNew  CObject3D_Leaf;
	CharMatrix->SetMesh(MatrixMesh);
	CharMatrix->SetShader( _CMMat);
	CharMatrix->ComputeBoundVol();	
	CharMatrixMat = _CMMat;
	AddObject(CharMatrix,0,0,_Width,_Height);
  //## end CConsole::Init%989264851.body
}

void CConsole::Write (char* _szTex)
{
  //## begin CConsole::Write%1014992648.body preserve=yes	
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
						Color.V4(1.0f,1.0f,1.0f,1.0f);
						break;
				case 2: // Black
						Color.V4(0.0f,0.0f,0.0f,1.0f);
						break;
				case 3: // Red
						Color.V4(1.0f,0.0f,0.0f,1.0f);
						break;
				case 4: // Green
						Color.V4(0.0f,1.0f,0.0f,1.0f);
						break;
				case 5: // Blue
						Color.V4(0.0f,0.0f,1.0f,1.0f);
						break;
				case 6: // Yellow
						Color.V4(1.0f,1.0f,0.0f,1.0f);
						break;
				case 7: // Dark Gray
						Color.V4(0.25f,0.25f,0.25f,1.0f);
						break;
				case '\n':iX  =0;
						  iY  ++;
						  break;
			}
		}
		_szTex++;
	}
  //## end CConsole::Write%1014992648.body
}

void CConsole::WriteXY (int X, int Y, char *Text)
{
  //## begin CConsole::WriteXY%989264852.body preserve=yes
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
							Color.V4(1.0f,1.0f,1.0f,1.0f);
							break;
					case 2: // Black
							Color.V4(0.0f,0.0f,0.0f,1.0f);
							break;
					case 3: // Red
							Color.V4(1.0f,0.0f,0.0f,1.0f);
							break;
					case 4: // Green
							Color.V4(0.0f,1.0f,0.0f,1.0f);
							break;
					case 5: // Blue
							Color.V4(0.0f,0.0f,1.0f,1.0f);
							break;
					case 6: // Yellow
							Color.V4(1.0f,1.0f,0.0f,1.0f);
							break;
					case 7: // Dark Gray
							Color.V4(0.25f,0.25f,0.25f,1.0f);
							break;
				}
			}
		Text++;
	}
  //## end CConsole::WriteXY%989264852.body
}

void CConsole::Resize (float _Width, float _Height)
{
  //## begin CConsole::Resize%989269072.body preserve=yes
    Width  = _Width;
    Height = _Height;
	
	// Background resizing
	ObjPos[0].tx = _Width;
	ObjPos[0].ty = _Height;

	// Charmatrix resizing
	ObjPos[1].tx = _Width;
	ObjPos[1].ty = _Height;
  //## end CConsole::Resize%989269072.body
}

void CConsole::SetChar (int _X, int _Y, char _a)
{
  //## begin CConsole::SetChar%989269073.body preserve=yes
	float	u1,v1,u2,v2;
	int		iIdx;

	/*
	if (_a != 32)
	{
		_a -= 48;					// starting from base char "0"

		int		iRow = _a / 16;		// Get the proper row in the font texture
		int		iCol = _a % 16;		// Get the proper col in the font texture
		u1 = (float)(iCol  )/16.0f;
		v1 = (float)(iRow  )/16.0f;
		u2 = (float)(iCol+1)/16.0f;
		v2 = (float)(iRow+1)/16.0f;
	}
	else
	{
		u1 = v2 = v1 = v2 = 0;
	}
	*/
	
	int		iRow = _a / 16;		// Get the proper row in the font texture
	int		iCol = _a % 16;		// Get the proper col in the font texture
	u1 = (float)(iCol  )/16.0f;
	v1 = (float)(iRow  )/16.0f;
	u2 = (float)(iCol+1)/16.0f;
	v2 = (float)(iRow+1)/16.0f;

	// Setup UV coords
	iIdx = (_Y*Cols + _X) * 4;

	MatrixMesh->UVs [iIdx + 0].V2(u1,v1);
	MatrixMesh->UVs [iIdx + 1].V2(u1,v2);
	MatrixMesh->UVs [iIdx + 2].V2(u2,v2);
	MatrixMesh->UVs [iIdx + 3].V2(u2,v1);

	// Setup color
	MatrixMesh->VCs [iIdx + 0].Assign(Color);
	MatrixMesh->VCs [iIdx + 1].Assign(Color);
	MatrixMesh->VCs [iIdx + 2].Assign(Color);
	MatrixMesh->VCs [iIdx + 3].Assign(Color);
  //## end CConsole::SetChar%989269073.body
}

void CConsole::CreateCharMatrix ()
{
  //## begin CConsole::CreateCharMatrix%989269074.body preserve=yes
	int cI,cJ,iIdx;

	if (MatrixMesh) mDel MatrixMesh;

	MatrixMesh = mNew CMesh();
	MatrixMesh->Init(4*Rows*Cols,Rows*Cols,E3D_MESH_NIQUADS,MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);
	
	iIdx = 0;
	for (cJ=0;cJ<Rows;cJ++)
		for (cI=0;cI<Cols;cI++)
		{
			MatrixMesh->VXs [iIdx + 0].V3((float)(cI  )/Cols,(float)(cJ  )/Rows, 0);
			MatrixMesh->VXs [iIdx + 1].V3((float)(cI  )/Cols,(float)(cJ+1)/Rows, 0);
			MatrixMesh->VXs [iIdx + 2].V3((float)(cI+1)/Cols,(float)(cJ+1)/Rows, 0);
			MatrixMesh->VXs [iIdx + 3].V3((float)(cI+1)/Cols,(float)(cJ  )/Rows, 0);

			MatrixMesh->UVs [iIdx + 0].V2(0.0f,0.0f);
			MatrixMesh->UVs [iIdx + 1].V2(0.0f,0.0f);
			MatrixMesh->UVs [iIdx + 2].V2(0.0f,0.0f);
			MatrixMesh->UVs [iIdx + 3].V2(0.0f,0.0f);

			MatrixMesh->VCs [iIdx + 0].V4(1.0f,1.0f,1.0f,1.0f);
			MatrixMesh->VCs [iIdx + 1].V4(1.0f,1.0f,1.0f,1.0f);
			MatrixMesh->VCs [iIdx + 2].V4(1.0f,1.0f,1.0f,1.0f);
			MatrixMesh->VCs [iIdx + 3].V4(1.0f,1.0f,1.0f,1.0f);
			
			iIdx += 4;
		}

  //## end CConsole::CreateCharMatrix%989269074.body
}

void CConsole::SetCharMatrixMat (CE3D_Shader *_CMMat)
{
  //## begin CConsole::SetCharMatrixMat%989269079.body preserve=yes
	CharMatrixMat = _CMMat;
	CharMatrix->SetShader( CharMatrixMat );
  //## end CConsole::SetCharMatrixMat%989269079.body
}

void CConsole::SetBackgroundMat (CE3D_Shader *_BGMat)
{
  //## begin CConsole::SetBackgroundMat%989269080.body preserve=yes
	BackgroundMat = _BGMat;
	Background->SetShader( BackgroundMat );
  //## end CConsole::SetBackgroundMat%989269080.body
}

// Additional Declarations
  //## begin CConsole%3AF6F98F00DC.declarations preserve=yes
  //## end CConsole%3AF6F98F00DC.declarations

//## begin module%3AF6F98F00DC.epilog preserve=yes
//## end module%3AF6F98F00DC.epilog
