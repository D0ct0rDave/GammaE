//## begin module%3B8B83190029.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8B83190029.cm

//## begin module%3B8B83190029.cp preserve=no
//## end module%3B8B83190029.cp

//## Module: CLoaderMD3%3B8B83190029; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\MD3Loader\CLoaderMD3.cpp

//## begin module%3B8B83190029.additionalIncludes preserve=no
//## end module%3B8B83190029.additionalIncludes

//## begin module%3B8B83190029.includes preserve=yes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Memory\Gammae_Mem.h"
#include "Misc\Gammae_Misc.h"
#include "MD3Model.h"
//## end module%3B8B83190029.includes

// CLoaderMD3
#include "Scene\3D_Loaders\MD3Loader\CLoaderMD3.h"
//## begin module%3B8B83190029.additionalDeclarations preserve=yes

/*
	
	Mayuscula transformation node
	minuscula mesh node

	Estructura de los nodos en los modelos MD3:

		a-a-a-A
			  |
			  b-b-b-B
	
				
	Estructura de los modelos en GammaE Engine:

		A
		|
		a-a-a-B
			  |
	 		  b-b-b
	
	Para transformar un modelo MD3 al engine, es necesario, postponer la
	transformaci�n para el final. Esto tambi�n se consigue haciendo que la
	transformaci�n leida en un nodo anterior se establezca al leer el nodo actual,
	y la del nodo actual, se reutilice al leer el siguiente nodo:

		X <- Identity
		|
		a-a-a-B ( con la transformaci�n de A)
			  |
			  b-b-b-C ( con la transformaci�n de B)
	
	Este es el cometido de las funciones
		
			SetTransfStateInfo  y SetupAnimTransfNode 

*/

#define	TOTAL_MD3FRAME_ANIMS		25
#define TOTAL_MD3FRAME_ANIM_TIME	100

//## end module%3B8B83190029.additionalDeclarations


// Class CLoaderMD3 


CLoaderMD3::CLoaderMD3()
  //## begin CLoaderMD3::CLoaderMD3%.hasinit preserve=no
  //## end CLoaderMD3::CLoaderMD3%.hasinit
  //## begin CLoaderMD3::CLoaderMD3%.initialization preserve=yes
  //## end CLoaderMD3::CLoaderMD3%.initialization
{
  //## begin CLoaderMD3::CLoaderMD3%.body preserve=yes
  //## end CLoaderMD3::CLoaderMD3%.body
}


CLoaderMD3::~CLoaderMD3()
{
  //## begin CLoaderMD3::~CLoaderMD3%.body preserve=yes
  //## end CLoaderMD3::~CLoaderMD3%.body
}



//## Other Operations (implementation)
int CLoaderMD3::iParseSkinSentence (char* _Buffer, char *SkinName, char *MeshName)
{
  //## begin CLoaderMD3::iParseSkinSentence%1000073571.body preserve=yes
	int iNumFields = 0;
  	int	iPos  =0;
	int iSPos = 0;
	
		
	// iNumFields = 0;
	while ((_Buffer[iPos] != ',') && (_Buffer[iPos])) 
	{
		MeshName[iPos] = _Buffer[iPos];
		iPos++;
	}
	// Finalize string
	MeshName[iPos] = 0;		

	// Not end of line
	if (_Buffer[iPos] != ',') return (0);
	
	// At least one field
	iNumFields++;
		
	iPos++;

	if ( ! _Buffer[iPos] ) return(1);
	
	iSPos = 0;
	while ((_Buffer[iPos] != ',') && (_Buffer[iPos])) 
	{
		SkinName[iSPos] = _Buffer[iPos];
		iPos++;
		iSPos++;
	}
	// Finalize string
	SkinName[iSPos] = 0;
	
	return (2);
  //## end CLoaderMD3::iParseSkinSentence%1000073571.body
}

void CLoaderMD3::LoadSkinInfo (char* _Filename)
{
  //## begin CLoaderMD3::LoadSkinInfo%1000073566.body preserve=yes
	FILE			*fd;
	char			StrBuff[1024];
	char			MeshName[68];
	char			SkinName[68];
	int				iNumFields;	

	int				iCurrentSkin;
	int				iCurrentTag;

	memset(&SkinBookmark,0,sizeof(skin_file_t));
	
	fd  = fopen(_Filename,"rt");
	
	if (! fd) 
	{				
		return;
	}
	
	SkinBookmark.iNumSkinMeshes  = 0;
	SkinBookmark.iNumSkinTags   = 0;

	while (! feof(fd))
	{
		fscanf(fd,"%s",StrBuff);
		iNumFields = iParseSkinSentence(StrBuff,SkinName,MeshName);
		
		switch (iNumFields)
		{
			case 2:	SkinBookmark.iNumSkinMeshes++;
					break;
			case 1: SkinBookmark.iNumSkinTags ++;
					break;
		}
	}
	// Set the file pos to the begin of the file
	fseek(fd,0,SEEK_SET);

	// Allocate space for structures
	SkinBookmark.skinmeshes = (skin_mesh_entry_t*)malloc(sizeof(skin_mesh_entry_t)*SkinBookmark.iNumSkinMeshes);
	SkinBookmark.skintags   = (skin_tag_entry_t *)malloc(sizeof(skin_tag_entry_t )*SkinBookmark.iNumSkinTags  );
	
	// read skin data
	iCurrentSkin = 0;
	iCurrentTag  = 0;
	while (! feof(fd))
	{
		fscanf(fd,"%s",StrBuff);
		iNumFields = iParseSkinSentence(StrBuff,SkinName,MeshName);

		switch (iNumFields)
		{
			case 2:	strncpy(SkinBookmark.skinmeshes[iCurrentSkin].name   ,MeshName,68);
					strncpy(SkinBookmark.skinmeshes[iCurrentSkin].texture,SkinName,68);
					iCurrentSkin++;		
					break;
			case 1: strncpy(SkinBookmark.skintags[iCurrentTag].name,MeshName,68);
					iCurrentTag++;
					break;
		}
	}

	fclose(fd);
  //## end CLoaderMD3::LoadSkinInfo%1000073566.body
}

CE3D_Shader * CLoaderMD3::poGetShader (char *_szMeshName)
{
  //## begin CLoaderMD3::poGetShader%1000073569.body preserve=yes
	int iSkin;
	
	for (iSkin=0;iSkin<SkinBookmark.iNumSkinMeshes;iSkin++)
	{
		if (! strcmp(_szMeshName,SkinBookmark.skinmeshes[iSkin].name))
			// Skin found
			return( CE3D_ShaderWH::poCreateShader(SkinBookmark.skinmeshes[iSkin].texture) );
	}

	return (NULL);
  //## end CLoaderMD3::poGetShader%1000073569.body
}

CObject3D_AnimTransf* CLoaderMD3::CreateAnimTransfNode (tag_t* _pTags, int _iNumTags, int _iTagStep)
{
  //## begin CLoaderMD3::CreateAnimTransfNode%1000332372.body preserve=yes
	CMatrix4x4 *Mat;
	CObject3D_AnimTransf *pAnimTransf;
	
	pAnimTransf = mNew CObject3D_AnimTransf;	
	pAnimTransf->CreateStates(_iNumTags);
		
	// Setup transformation array
	Mat = pAnimTransf->pTransStates;
	for (int cFrame=0;cFrame<_iNumTags;cFrame++)
	{		
		// X row
		Mat->Set(0,0,_pTags->rotation[0][0]);
		Mat->Set(0,1,_pTags->rotation[0][1]);
		Mat->Set(0,2,_pTags->rotation[0][2]);

		// Y row
		Mat->Set(1,0,_pTags->rotation[1][0]);
		Mat->Set(1,1,_pTags->rotation[1][1]);
		Mat->Set(1,2,_pTags->rotation[1][2]);
			
		// Z row
		Mat->Set(2,0,_pTags->rotation[2][0]);
		Mat->Set(2,1,_pTags->rotation[2][1]);
		Mat->Set(2,2,_pTags->rotation[2][2]);
		
		// Last row
		Mat->Set(3,0,0.0f);
		Mat->Set(3,1,0.0f);
		Mat->Set(3,2,0.0f);

		Mat->Set(0,3,_pTags->position[0]);
		Mat->Set(1,3,_pTags->position[1]);
		Mat->Set(2,3,_pTags->position[2]);
		Mat->Set(3,3,1.0f);		
		
		Mat ++;
		_pTags += _iTagStep;
	}

	return(pAnimTransf);
  //## end CLoaderMD3::CreateAnimTransfNode%1000332372.body
}

CObject3D_AnimMesh * CLoaderMD3::pCreateAnimMesh (mesh_header_t& _Header, skin_t &_Skin, Q3triangle_t *_Tris, vertice_t* _VXs, tex_coord_t* _UVs)
{
  //## begin CLoaderMD3::pCreateAnimMesh%1000073570.body preserve=yes
	CObject3D_AnimMesh  *AnimMesh = mNew CObject3D_AnimMesh;
	CMesh				*Mesh     = mNew CMesh;	
	CObject3D_Leaf		*LeafObj  = mNew CObject3D_Leaf;

	// ----------------------------------
	// Translate previously read information to our engine
	// classes
	// ----------------------------------

	// -----------------
	// Animated mesh object
	// -----------------
	AnimMesh->SetLeaf(LeafObj);
	AnimMesh->CreateStates(_Header.numMeshFrames,_Header.numVertexs);	

	// -----------------
	// Setup leaf object
	// -----------------
	LeafObj->SetMesh (Mesh);
	// Setup mesh material	
	if (*_Skin.name)
	{
		// the mesh has a link to its mesh material
		LeafObj->SetShader( CE3D_ShaderWH::poCreateShader(_Skin.name) );
	}
	else
	{
		// use the skin bookmark to find the mesh material
		LeafObj->SetShader( poGetShader( _Header.name ) );
	}

	Mesh->Init(_Header.numVertexs,_Header.numTriangles,E3D_MESH_TRIS,
			   MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_VNORMALS |MESH_FIELD_INDEXES );
	// -----------------
	// Setup mesh
	// -----------------
		
	// Setup mesh indexes
	int cTri,cVert,iIdx = 0;
	for (cTri =0;cTri<_Header.numTriangles;cTri++)
		for (cVert=0;cVert<3;cVert++)
			Mesh->Idxs[iIdx++]   = _Tris[cTri].vertex[cVert];

	// Setup mesh tex coords	
	for (cVert=0;cVert<_Header.numVertexs;cVert++)
		Mesh->UVs [cVert].V2(_UVs[cVert].texvec[0],_UVs[cVert].texvec[1]);
	
	// Setup vertexes
	vertice_t *pV   = _VXs;
	CVect3	  *pVXs = AnimMesh->pMeshStates;

	for (cVert=0;cVert<_Header.numMeshFrames*_Header.numVertexs;cVert++)
	{
		pVXs->V3( (float)pV->Vec[0]/64.0f,(float)pV->Vec[1]/64.0f,(float)pV->Vec[2]/64.0f);

		pV++;
		pVXs++;
	}

	return (AnimMesh);
  //## end CLoaderMD3::pCreateAnimMesh%1000073570.body
}

CObject3D * CLoaderMD3::pLoadModel (char *Filename)
{
  //## begin CLoaderMD3::pLoadModel%1000073567.body preserve=yes
  	FILE					*md3file;
	int						i;
	
	md3_header_t			header;
	boneframe_t				*boneframes;
	tag_t					*tags;

	long					mesh_offset;
			
	Q3triangle_t			*Tris;
	tex_coord_t				*UVs;
	vertice_t				*VXs;

	CObject3D_AnimNode		*AnimModel;
	CObject3D_AnimTransf	*AnimTransf;
	CObject3D_AnimMesh		*AnimMesh;

	// open file
	md3file = fopen(Filename,"rb");
	if (! md3file)
	{
		return (NULL);
	}	

	//
	//	read header
	//
	fread(&header, 1, sizeof(md3_header_t), md3file);

	if ( strncmp(header.id,"IDP3",4) || header.version != 15)
	{
		fclose(md3file);
		return (NULL);
	}	
	
	//
	//	read boneframes
	//
	boneframes = (boneframe_t *) malloc(sizeof(boneframe_t) * header.numBoneFrames);
	fread(boneframes, sizeof(boneframe_t), header.numBoneFrames, md3file);

	//
	//	read tags
	//
	tags = (tag_t *) malloc(sizeof(tag_t) * header.numBoneFrames * header.numTags);
	fread(tags, sizeof(tag_t), header.numBoneFrames * header.numTags, md3file);	
	
	// Create animation transformation node (bones)
	AnimTransf = CreateAnimTransfNode(tags,header.numBoneFrames,header.numTags);

	AnimModel = mNew CObject3D_AnimNode;
	AnimModel->Init        (header.numMeshes+1+1);
	AnimModel->CreateStates(header.numBoneFrames);
	// free buffers
	free (tags);
	free (boneframes);

	// Read meshes
	skin_t			skin;
	mesh_header_t	mesh_header;

	mesh_offset = ftell(md3file);
	for (i=0;i<header.numMeshes;i++)
	{		
		// Find proper file position	
		fseek(md3file, mesh_offset, SEEK_SET);

		// Read mesh header
		fread(&mesh_header, sizeof(mesh_header_t), 1, md3file);		

		// Read skin filename
		fread(&skin,sizeof(skin_t),1,md3file);		

		// Read triangles
		fseek(md3file, mesh_offset+mesh_header.tri_start, SEEK_SET);
		Tris = (Q3triangle_t *)malloc(mesh_header.numTriangles*sizeof(Q3triangle_t));
		fread(Tris, sizeof(Q3triangle_t), mesh_header.numTriangles, md3file);

		// Read tex coords
		fseek(md3file, mesh_offset+mesh_header.texvec_start, SEEK_SET);
		UVs = (tex_coord_t *) malloc(sizeof(tex_coord_t) * mesh_header.numVertexs);
		fread(UVs, sizeof(tex_coord_t), mesh_header.numVertexs, md3file);

		// Read vertexes
		fseek(md3file, mesh_offset+mesh_header.vertex_start, SEEK_SET);
		VXs = (vertice_t *) malloc(sizeof(vertice_t) * mesh_header.numVertexs    * mesh_header.numMeshFrames);
		fread(VXs, sizeof(vertice_t), mesh_header.numMeshFrames * mesh_header.numVertexs, md3file);

		mesh_offset += mesh_header.meshsize;

		// Setup mesh info using previously read file information		
		AnimMesh = pCreateAnimMesh(mesh_header,skin,Tris,VXs,UVs);
		
		// Generate normals for this mesh
		glbAnimMesh_NormalGenerator.Generate(AnimMesh);

		AnimModel->AddObject( AnimMesh );

		// free auxiliary arrays
		free(Tris);
		free(UVs );
		free(VXs );
	}
	
	fclose (md3file);

	// Link transformation node	
	AnimModel->AddObject(AnimTransf);

	return ( AnimModel );
  //## end CLoaderMD3::pLoadModel%1000073567.body
}

CObject3D * CLoaderMD3::pLoad (char *_ModelName, char* _SkinName)
{
  //## begin CLoaderMD3::pLoad%1000073568.body preserve=yes
	LoadSkinInfo(_SkinName);
	return ( pLoadModel(_ModelName) );
  //## end CLoaderMD3::pLoad%1000073568.body
}

CObject3D * CLoaderMD3::pLoad (char* Filename)
{
  //## begin CLoaderMD3::pLoad%998998857.body preserve=yes
	char			*SkinFilename;
	int				iFilenameLen;

	// Set skinfilename
	iFilenameLen = strlen(Filename);
	SkinFilename = (char *) malloc(iFilenameLen+2);

	strcpy(SkinFilename,Filename);

	SkinFilename[ iFilenameLen-3 ] = 's';  // previously 'm'
	SkinFilename[ iFilenameLen-2 ] = 'k';  // previously 'd'
	SkinFilename[ iFilenameLen-1 ] = 'i';  // previously '3'
	SkinFilename[ iFilenameLen   ] = 'n';  // previously  0
	SkinFilename[ iFilenameLen+1 ] =  0;
	
	LoadSkinInfo( SkinFilename );
	
	pLoad(Filename,SkinFilename);
	return (NULL);
  //## end CLoaderMD3::pLoad%998998857.body
}

CObject3D_AnimCfgGen * CLoaderMD3::pLoadQ3Player (char* _Path, char* _SkinName)
{
  //## begin CLoaderMD3::pLoadQ3Player%1000046686.body preserve=yes
	char					l_mpath[1024], u_mpath[1024], h_mpath[1024];
	char					l_spath[1024], u_spath[1024], h_spath[1024];
	char					a_path[1024];

	CObject3D_AnimNode		*L,*U,*H;
  	CObject3D_AnimCfgMgr	*pQ3Player;

	sprintf(l_mpath, "%s/lower.md3", _Path);
	sprintf(u_mpath, "%s/upper.md3", _Path);
	sprintf(h_mpath, "%s/head.md3" , _Path);

	sprintf(l_spath, "%s/lower_%s.skin", _Path, _SkinName);
	sprintf(u_spath, "%s/upper_%s.skin", _Path, _SkinName);
	sprintf(h_spath, "%s/head_%s.skin" , _Path, _SkinName);

    L = (CObject3D_AnimNode *)pLoad(l_mpath,l_spath);
	U = (CObject3D_AnimNode *)pLoad(u_mpath,u_spath);
	H = (CObject3D_AnimNode *)pLoad(h_mpath,h_spath);

	// Linkar objetos
	U->AddObject(H);
	sprintf(a_path,"%s/Animation.cfg",_Path);
	pQ3Player = pLoadAnimation(a_path,L,U);

	// Esto realmente va afuera, pero de momento se deja aqui
	return ( pQ3Player );
  //## end CLoaderMD3::pLoadQ3Player%1000046686.body
}

CObject3D_AnimCfgMgr * CLoaderMD3::pLoadAnimation (char *_Filename, CObject3D_AnimNode* _pLegs, CObject3D_AnimNode* _pTorso)
{
  //## begin CLoaderMD3::pLoadAnimation%1000758288.body preserve=yes
	char	*Buffer   = ParseUtils_ReadFile(_Filename);
	char	*szHeader = Buffer;
	char	*szToken;
	
	anim_t				AnimCfg[TOTAL_MD3FRAME_ANIMS];	
	int					iAnimNum = 0;

	if (! Buffer) return (NULL);
	

	while (*szHeader)
	{		
		szToken  = ParseUtils_ParseToken (szHeader);

		if (! strcmp("//",szToken))
			szHeader = ParseUtils_SkipLine(szHeader);
   else if (! strcmp("sex",szToken))
			szHeader = ParseUtils_SkipLine(szHeader);
   else if (! strcmp("footsteps",szToken))
			szHeader = ParseUtils_SkipLine(szHeader);
   else 
		{
			if (iAnimNum < TOTAL_MD3FRAME_ANIMS)
			{
				// restore token delimiter previous to String Header position
				szHeader--;	*szHeader = ' ';

				// Parsing Frame Animation Code
				sscanf(szToken,"%d %d %d %d", &AnimCfg[iAnimNum].first_frame,
											  &AnimCfg[iAnimNum].num_frames,
											  &AnimCfg[iAnimNum].looping_frames,
											  &AnimCfg[iAnimNum].frames_per_second);
				
				if(AnimCfg[iAnimNum].frames_per_second<=0.0f)
					AnimCfg[iAnimNum].frames_per_second = 1.0f;

				iAnimNum++;
			}

			// Now skip this line
			szHeader = ParseUtils_SkipLine(szHeader);
		}
	}

	int iSkip = (AnimCfg[13].first_frame - AnimCfg[6].first_frame);
	for (int iAnim=13;iAnim<TOTAL_MD3FRAME_ANIMS;iAnim++)
		// These animations have an offset
		AnimCfg[iAnim].first_frame -= iSkip;

	// --------------------------------
	// Ok: go to process animation info:
	// --------------------------------
  	CObject3D_AnimCfgMgr	*pQ3Player;
	
	CObject3D_AnimCfg		*AnimT;
	CObject3D_AnimCfg		*AnimL;
	
	AnimT = mNew CObject3D_AnimCfg;
	AnimL = mNew CObject3D_AnimCfg;	

	AnimL->SetAnimObj      (_pLegs );	
	AnimT->SetAnimObj      (_pTorso);

	AnimL->CreateFrameAnims(TOTAL_MD3FRAME_ANIMS+1);
	AnimT->CreateFrameAnims(TOTAL_MD3FRAME_ANIMS+1);

	AnimL->SetupFrameAnim(0,0,_pLegs ->iGetNumStates()-1,TOTAL_MD3FRAME_ANIM_TIME,true);
	AnimT->SetupFrameAnim(0,0,_pTorso->iGetNumStates()-1,TOTAL_MD3FRAME_ANIM_TIME,true);

	SetupAnim(1,AnimCfg,AnimL,AnimT);
	SetupAnim(2,AnimCfg,AnimL,AnimT);
	SetupAnim(3,AnimCfg,AnimL,AnimT);
	SetupAnim(7,AnimCfg,AnimL,AnimT);

	// Setup animation manager
	pQ3Player = mNew CObject3D_AnimCfgMgr;
	pQ3Player->Init(2);
	pQ3Player->AddAnimObj(AnimL);
	pQ3Player->AddAnimObj(AnimT);
	
	return (pQ3Player);
  //## end CLoaderMD3::pLoadAnimation%1000758288.body
}

void CLoaderMD3::SetupAnim (int _iAnimNum, anim_t *_MD3Anim, CObject3D_AnimCfg* _pLegs, CObject3D_AnimCfg* _pTorso)
{
  //## begin CLoaderMD3::SetupAnim%1000758289.body preserve=yes

/*	
	Code ripped from
	    Advance OpenGL MD3Load 
		Mustata Bogdan (LoneRunner)
	
	Also based on another code
*/
	/*
	if (_iAnimNum>=0 && _iAnimNum<=5)
	{ 
		// Both animation
		_pLegs ->SetupFrameAnim(_iAnimNum+1,
							    _MD3Anim.first_frame,
								_MD3Anim.first_frame+_MD3Anim.num_frames-1,
								(float)_MD3Anim.num_frames/(float)_MD3Anim.frames_per_second,
								_MD3Anim.looping_frames);
		_pTorso ->SetupFrameAnim(_iAnimNum+1,
							    _MD3Anim.first_frame,
								_MD3Anim.first_frame+_MD3Anim.num_frames-1,
								(float)_MD3Anim.num_frames/(float)_MD3Anim.frames_per_second,
								_MD3Anim.looping_frames);
	}
	else if (_iAnimNum>5 && _iAnimNum<13)
	{
		_pLegs ->SetupFrameAnim(_iAnimNum+1,
							    _MD3Anim.first_frame,
								_MD3Anim.first_frame+_MD3Anim.num_frames-1,
								(float)_MD3Anim.num_frames/(float)_MD3Anim.frames_per_second,
								_MD3Anim.looping_frames);
		_pTorso ->SetupFrameAnim(_iAnimNum+1,
							    0,
								0,
								1.0f,
								false);
	}
	else if(_iAnimNum>=13 && _iAnimNum<=24)
	{
		_pTorso ->SetupFrameAnim(_iAnimNum+1,
							    _MD3Anim.first_frame,
								_MD3Anim.first_frame+_MD3Anim.num_frames-1,
								(float)_MD3Anim.num_frames/(float)_MD3Anim.frames_per_second,
								_MD3Anim.looping_frames);
		_pLegs ->SetupFrameAnim(_iAnimNum+1,
							    0,
								0,
								1.0f,
								false);
	}
	*/
	/*
	#define		FRAME_STAND		1
	#define		FRAME_RUN		2
	#define		FRAME_WALK		4
	#define		FRAME_ATTACK	3
	#define		FRAME_JUMP		7
	*/
	switch (_iAnimNum)
	{
		case 1:	// Stand
				_pLegs ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[22].first_frame,
										_MD3Anim[22].first_frame+_MD3Anim[22].num_frames-1,
										(float)_MD3Anim[22].num_frames/(float)_MD3Anim[22].frames_per_second,
										_MD3Anim[22].looping_frames);				
				
				_pTorso ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[11].first_frame,
										_MD3Anim[11].first_frame+_MD3Anim[11].num_frames-1,
										(float)_MD3Anim[11].num_frames/(float)_MD3Anim[11].frames_per_second,
										_MD3Anim[11].looping_frames);				
				break;	

		case 2:	// Run
				_pLegs ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[15].first_frame,
										_MD3Anim[15].first_frame+_MD3Anim[15].num_frames-1,
										(float)_MD3Anim[15].num_frames/(float)_MD3Anim[15].frames_per_second,
										_MD3Anim[15].looping_frames);				
				
				_pTorso ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[10].first_frame,
										_MD3Anim[10].first_frame+_MD3Anim[10].num_frames-1,
										(float)_MD3Anim[10].num_frames/(float)_MD3Anim[10].frames_per_second,
										_MD3Anim[10].looping_frames);				
				break;
		case 3:	// Attack
				_pLegs ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[12].first_frame,
										_MD3Anim[12].first_frame+_MD3Anim[12].num_frames-1,
										(float)_MD3Anim[12].num_frames/(float)_MD3Anim[12].frames_per_second,
										_MD3Anim[12].looping_frames);				
				
				_pTorso ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[7].first_frame,
										_MD3Anim[7].first_frame+_MD3Anim[7].num_frames-1,
										(float)_MD3Anim[7].num_frames/(float)_MD3Anim[7].frames_per_second,
										_MD3Anim[7].looping_frames);				
				break;
		case 7:	// Jump
				_pLegs ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[20].first_frame,
										_MD3Anim[20].first_frame+_MD3Anim[20].num_frames-1,
										(float)_MD3Anim[20].num_frames/(float)_MD3Anim[20].frames_per_second,
										_MD3Anim[20].looping_frames);				
				
				_pTorso ->SetupFrameAnim(_iAnimNum,
										_MD3Anim[12].first_frame,
										_MD3Anim[12].first_frame+_MD3Anim[12].num_frames-1,
										(float)_MD3Anim[12].num_frames/(float)_MD3Anim[12].frames_per_second,
										_MD3Anim[12].looping_frames);				
				break;
	}
  //## end CLoaderMD3::SetupAnim%1000758289.body
}

// Additional Declarations
  //## begin CLoaderMD3%3B8B83190029.declarations preserve=yes
  //## end CLoaderMD3%3B8B83190029.declarations

//## begin module%3B8B83190029.epilog preserve=yes
//## end module%3B8B83190029.epilog
