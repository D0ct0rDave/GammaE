//## begin module%3AC0F80B0168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC0F80B0168.cm

//## begin module%3AC0F80B0168.cp preserve=no
//## end module%3AC0F80B0168.cp

//## Module: CLoaderMD2%3AC0F80B0168; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\MD2Loader\CLoaderMD2.cpp

//## begin module%3AC0F80B0168.additionalIncludes preserve=no
//## end module%3AC0F80B0168.additionalIncludes

//## begin module%3AC0F80B0168.includes preserve=yes
//## end module%3AC0F80B0168.includes

// CLoaderMD2
#include "Scene\3D_Loaders\MD2Loader\CLoaderMD2.h"
//## begin module%3AC0F80B0168.additionalDeclarations preserve=yes
#include <stdlib.h>
#include <string.h>
#include "Memory/GammaE_Mem.h"
//## end module%3AC0F80B0168.additionalDeclarations


// Class CLoaderMD2 








CLoaderMD2::CLoaderMD2()
  //## begin CLoaderMD2::CLoaderMD2%.hasinit preserve=no
      : Stream(NULL), StreamSize(0), MD2Header(NULL), Frame(NULL), Triangles(NULL), Vertexs(NULL), TexCoords(NULL)
  //## end CLoaderMD2::CLoaderMD2%.hasinit
  //## begin CLoaderMD2::CLoaderMD2%.initialization preserve=yes
  //## end CLoaderMD2::CLoaderMD2%.initialization
{
  //## begin CLoaderMD2::CLoaderMD2%.body preserve=yes
  //## end CLoaderMD2::CLoaderMD2%.body
}


CLoaderMD2::~CLoaderMD2()
{
  //## begin CLoaderMD2::~CLoaderMD2%.body preserve=yes
	if (Stream) mFree(Stream);
  //## end CLoaderMD2::~CLoaderMD2%.body
}



//## Other Operations (implementation)
int CLoaderMD2::ReadFile (char *Filename)
{
  //## begin CLoaderMD2::ReadFile%986042756.body preserve=yes
  	//---------------------------------------------------------------------------
	// Read file contents
	//---------------------------------------------------------------------------	    
	FILE		 *fd;	

    fd = fopen(Filename,"rb");
    if (! fd) return(0);

    fseek(fd,0,SEEK_END);
    StreamSize = ftell(fd);

    fseek(fd,0,SEEK_SET);
    Stream = (char *)mAlloc(StreamSize);
    if (! Stream)
    {
        fclose(fd);
        return(0);
    }
    fread(Stream,StreamSize,1,fd);
    fclose(fd);

	return(1);
  //## end CLoaderMD2::ReadFile%986042756.body
}

void CLoaderMD2::SetupFrame (int iFrame)
{
  //## begin CLoaderMD2::SetupFrame%986042755.body preserve=yes
	Frame   = (frame_t             *)& Stream[MD2Header->offsetFrames + iFrame*MD2Header->frameSize ];
	Vertexs = (triangleVertex_t    *)& Frame->vertices; 	
  //## end CLoaderMD2::SetupFrame%986042755.body
}

void CLoaderMD2::ParseHeader ()
{
  //## begin CLoaderMD2::ParseHeader%985725079.body preserve=yes
	MD2Header  = (model_t *)Stream;

	SetupFrame(0);

	Triangles = (triangle_t          *)&Stream[ MD2Header->offsetTriangles ];
	TexCoords = (textureCoordinate_t *)&Stream[ MD2Header->offsetTexCoords ];
  //## end CLoaderMD2::ParseHeader%985725079.body
}

CObject3D * CLoaderMD2::ParseChunks ()
{
  //## begin CLoaderMD2::ParseChunks%985725080.body preserve=yes
	SCNUt_TriScene			*MD2Mesh;
	
	SCNUt_MeshCompacter	MCompacter;	
	
	CE3D_Shader			*Skin;
		
	CObject3D_AnimMesh		*AnimMesh;
	CObject3D_Leaf			*LeafObj;
	CMesh					*Mesh;
	// Parse model header
	ParseHeader();

	if (MD2Header->magic   != ('I' + ('D' << 8) + ('P' << 16) + ('2' << 24)) ) return(NULL);
	if (MD2Header->version != 8) return(NULL);

	// ----------------------------------------
	// Get mesh info
	// ----------------------------------------
	MD2Mesh = ParseModel();

	// Generate a legal mesh
	Mesh = MCompacter.CompactMesh(*MD2Mesh);

	// free auxiliary resources
	mDel MD2Mesh;

	// ----------------------------------------
	// Get material info
	// ----------------------------------------	
	// Get the material
	Skin = ParseMaterial ();
	
	// ----------------------------------------
	// Setup the model & material & frames
	// ----------------------------------------		
	LeafObj  = mNew CObject3D_Leaf;
	LeafObj->SetMesh(Mesh);
	LeafObj->SetShader(Skin);

	AnimMesh = mNew CObject3D_AnimMesh();
	AnimMesh->CreateStates(MD2Header->numFrames,Mesh->usNumVerts);	
	AnimMesh->SetLeaf(LeafObj);		

	// Parse model frames
	ParseFrameSet(*AnimMesh,*Mesh);
	
	glbAnimMesh_NormalGenerator.Generate(AnimMesh);

	return(AnimMesh);
  //## end CLoaderMD2::ParseChunks%985725080.body
}

SCNUt_TriScene * CLoaderMD2::ParseModel ()
{
  //## begin CLoaderMD2::ParseModel%985903379.body preserve=yes
  	CVect3					VX;
	int						cTri;
	unsigned int			cVert;
	unsigned int			uiVPos;
	unsigned int			uiTPos;
	
	SCNUt_TriScene			*MD2Mesh   = mNew SCNUt_TriScene();

	SetupFrame(0);

	int iVert;
	MD2Mesh->Init(MD2Header->numTriangles);
	for (cTri=0;cTri<MD2Header->numTriangles;cTri++)
	{
		for (cVert=0;cVert<3;cVert++)
		{
			// Reverse winding while reading
			iVert  = 2-cVert;

			uiVPos = Triangles[cTri].vertexIndices[iVert];
			uiTPos = Triangles[cTri].textureIndices[iVert];

			MD2Mesh->Tris[cTri].VXs[cVert].V3(
			Vertexs[uiVPos].vertex[0]*Frame->scale[0] + Frame->translate[0],
			Vertexs[uiVPos].vertex[1]*Frame->scale[1] + Frame->translate[1],
			Vertexs[uiVPos].vertex[2]*Frame->scale[2] + Frame->translate[2]);

			MD2Mesh->Tris[cTri].UVs[cVert].V2(
					(float)TexCoords[uiTPos].s/(float)MD2Header->skinWidth,
					(float)TexCoords[uiTPos].t/(float)MD2Header->skinHeight);
			
			MD2Mesh->Tris[cTri].VCs[cVert].V4(1,1,1,0);
		}
	}

	return(MD2Mesh);
  //## end CLoaderMD2::ParseModel%985903379.body
}

CE3D_Shader * CLoaderMD2::ParseMaterial ()
{
  //## begin CLoaderMD2::ParseMaterial%985903848.body preserve=yes
	char *SkinFile = &Stream[ MD2Header->offsetSkins ];

	return( CE3D_ShaderWH::poCreateShader(SkinFile) );
  //## end CLoaderMD2::ParseMaterial%985903848.body
}

unsigned short * CLoaderMD2::GetVertexConversionTable (CMesh &Mesh)
{
  //## begin CLoaderMD2::GetVertexConversionTable%985989940.body preserve=yes
	CVect3			NewVX;
  	int				cVert,cMD2Vert;
	unsigned short *NewIdxs = (unsigned short *)mAlloc(Mesh.usNumVerts*sizeof(unsigned short));

	// Obtener los nuevos indices en funcion de los antiguos
	for (cVert=0;cVert<Mesh.usNumVerts;cVert++)
	{	
		// Buscar el vertice MD2 al que corresponde el vértice actual
		cMD2Vert = 0;
		do {
			NewVX.V3(
					 Vertexs[cMD2Vert].vertex[0]*Frame->scale[0] + Frame->translate[0],
					 Vertexs[cMD2Vert].vertex[1]*Frame->scale[1] + Frame->translate[1],
					 Vertexs[cMD2Vert].vertex[2]*Frame->scale[2] + Frame->translate[2]
					);
			
			cMD2Vert++;
		}while ( (! NewVX.Equal(Mesh.VXs[cVert])) && (cMD2Vert < MD2Header->numVertices));
		
		NewIdxs[cVert] = cMD2Vert-1;
	}

	return( NewIdxs );
	/*
	unsigned char   ucX,ucY,ucZ;

	do {
		Vertexs = (triangleVertex_t *)&Frame->vertices + cOldVert;
		ucX = ((Mesh.VXs[cVert].X() - Frame->translate[0]) / Frame->scale[0]);
		ucY = ((Mesh.VXs[cVert].Y() - Frame->translate[1]) / Frame->scale[1]);
		ucZ = ((Mesh.VXs[cVert].Z() - Frame->translate[2]) / Frame->scale[2]);
	}while (! ((ucX == vertex[0]) && (ucY == vertex[1]) && (ucZ == vertex[2]))
			&&
			(cOldVert < MD2Header->numVertices));
	*/
  //## end CLoaderMD2::GetVertexConversionTable%985989940.body
}

void CLoaderMD2::ParseFrameSet (CObject3D_AnimMesh &AnimMesh, CMesh &Mesh)
{
  //## begin CLoaderMD2::ParseFrameSet%985989939.body preserve=yes
	int				cVert,cFrame;		
	unsigned short  *NewIdxs = GetVertexConversionTable( Mesh );

	CVect3		 	 NewVX;
	CVect3			*pVX = AnimMesh.pMeshStates;
	CMatrix4x4		oCMat;	// Correction matrix
	oCMat.LoadIdentity();
	oCMat.RotateAxis('z',_PI2_);

	// Parse every frame
	for (cFrame=0;cFrame<MD2Header->numFrames;cFrame++)
	{
		SetupFrame(cFrame);
		Frame = (frame_t *)&Stream[ MD2Header->offsetFrames + cFrame * MD2Header->frameSize];

		// Convert from MD2 frames to engine frames
		for (cVert=0;cVert<Mesh.usNumVerts;cVert++)
		{
			NewVX.V3(
					 Vertexs[ NewIdxs[cVert] ].vertex[0]*Frame->scale[0] + Frame->translate[0],
					 Vertexs[ NewIdxs[cVert] ].vertex[1]*Frame->scale[1] + Frame->translate[1],
					 Vertexs[ NewIdxs[cVert] ].vertex[2]*Frame->scale[2] + Frame->translate[2]
					);
			
			// Correct point
			oCMat.TransformPoint(NewVX);

			pVX->Assign(NewVX);
			pVX++;
		}
	}

	mFree ( NewIdxs );
  //## end CLoaderMD2::ParseFrameSet%985989939.body
}

CObject3D * CLoaderMD2::pLoad (char* Filename)
{
  //## begin CLoaderMD2::pLoad%985903378.body preserve=yes
    CObject3D *Obj = NULL;

	if (! ReadFile(Filename)) return(NULL);

	//---------------------------------------------------------------------------	
	
	Obj	= ParseChunks();

	return(Obj);	
  //## end CLoaderMD2::pLoad%985903378.body
}

int CLoaderMD2::GetNumSkins ()
{
  //## begin CLoaderMD2::GetNumSkins%986042752.body preserve=yes
	return (MD2Header->numSkins);
  //## end CLoaderMD2::GetNumSkins%986042752.body
}

char * CLoaderMD2::GetSkin (int iSkin)
{
  //## begin CLoaderMD2::GetSkin%986042753.body preserve=yes
	return ( & Stream[MD2Header->offsetSkins + iSkin*64] );
  //## end CLoaderMD2::GetSkin%986042753.body
}

int CLoaderMD2::GetNumFrames ()
{
  //## begin CLoaderMD2::GetNumFrames%986051315.body preserve=yes
	return (MD2Header->numFrames );
  //## end CLoaderMD2::GetNumFrames%986051315.body
}

CObject3D_AnimCfgGen * CLoaderMD2::pLoadQ2Player (char* Filename)
{
  //## begin CLoaderMD2::pLoadQ2Player%1000676444.body preserve=yes
	CObject3D_AnimCfg  *pQ2Player;
	CObject3D_AnimMesh *pQ2Model;
	
	pQ2Model = (CObject3D_AnimMesh *)pLoad(Filename);

	if (pQ2Model)
	{
		pQ2Player = mNew CObject3D_AnimCfg();
		pQ2Player->CreateFrameAnims(9);
		pQ2Player->SetupFrameAnim(0,0 ,MD2Header->numFrames,40,true);

		pQ2Player->SetupFrameAnim( 1,0 ,39,10.0f,true );	// stand
		pQ2Player->SetupFrameAnim( 2,40,45, 0.5f,true );	// run
		pQ2Player->SetupFrameAnim( 3,46,53, 2.0f,true );	// attack
		pQ2Player->SetupFrameAnim( 4,54,57, 2.0f,false);	// pain 1
		pQ2Player->SetupFrameAnim( 5,58,61, 2.0f,false);	// pain 2
		pQ2Player->SetupFrameAnim( 6,62,65, 2.0f,false);	// pain 3
		pQ2Player->SetupFrameAnim( 7,66,71, 2.0f,false);	// jump
		pQ2Player->SetupFrameAnim( 8,71,84, 2.0f,false);	// flip
		
		pQ2Player->SetFrameAnim  (1);	
			
		pQ2Player->SetAnimObj(pQ2Model);
	}

	return (pQ2Player);
  //## end CLoaderMD2::pLoadQ2Player%1000676444.body
}

// Additional Declarations
  //## begin CLoaderMD2%3AC0F80B0168.declarations preserve=yes
  //## end CLoaderMD2%3AC0F80B0168.declarations

//## begin module%3AC0F80B0168.epilog preserve=yes
//## end module%3AC0F80B0168.epilog
