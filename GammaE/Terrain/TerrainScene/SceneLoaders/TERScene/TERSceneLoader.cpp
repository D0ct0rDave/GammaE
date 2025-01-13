//## begin module%3B4658C503C0.cm preserve=no
//## end module%3B4658C503C0.cm

//## begin module%3B4658C503C0.cp preserve=no
//## end module%3B4658C503C0.cp

//## Module: TERSceneLoader%3B4658C503C0; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainScene\SceneLoaders\TERScene\TERSceneLoader.cpp

//## begin module%3B4658C503C0.additionalIncludes preserve=no
//## end module%3B4658C503C0.additionalIncludes

//## begin module%3B4658C503C0.includes preserve=yes
#include <file.h>
#include <string.h>
#include "Memory/GammaE_mem.h"
//## end module%3B4658C503C0.includes

// TERSceneLoader
#include "Terrain\TerrainScene\SceneLoaders\TERScene\TERSceneLoader.h"
//## begin module%3B4658C503C0.additionalDeclarations preserve=yes
#define ShowMessage(Msg)
//## end module%3B4658C503C0.additionalDeclarations


// Class TERSceneLoader 


















TERSceneLoader::TERSceneLoader()
  //## begin TERSceneLoader::TERSceneLoader%.hasinit preserve=no
      : HF(NULL), TM(NULL), LM(NULL), TS(NULL), ATS(NULL), iSectorRes(0), fSectorSize(0), fXYScale(0), fIScale(0), iCircXRes(0), iCircYRes(0), fCircXSize(0), fCircYSize(0), TB(NULL)
  //## end TERSceneLoader::TERSceneLoader%.hasinit
  //## begin TERSceneLoader::TERSceneLoader%.initialization preserve=yes
  //## end TERSceneLoader::TERSceneLoader%.initialization
{
  //## begin TERSceneLoader::TERSceneLoader%.body preserve=yes
	HF  = mNew CHeightField();
	TM  = mNew CTexMap();
	LM  = mNew CLightMap();
	TS  = mNew TTexSet();
	ATS = mNew TTexSet();
  //## end TERSceneLoader::TERSceneLoader%.body
}


TERSceneLoader::~TERSceneLoader()
{
  //## begin TERSceneLoader::~TERSceneLoader%.body preserve=yes
	mDel HF;
	mDel TM;
	mDel LM;
	mDel TS;
	mDel ATS;
  //## end TERSceneLoader::~TERSceneLoader%.body
}



//## Other Operations (implementation)
CObject3D * TERSceneLoader::Load (char *_Filename)
{
  //## begin TERSceneLoader::Load%994466160.body preserve=yes
	FILE *fd;
	fd = fopen(_Filename,"rb");
	if (! fd) return(NULL);

	// First load the scene
	LoadData(fd);
	fclose(fd);

	// Now build the scene
	CObject3D *poScene = GenerateScene();
	
	return(poScene);
  //## end TERSceneLoader::Load%994466160.body
}

void TERSceneLoader::LoadData (FILE *fd)
{
  //## begin TERSceneLoader::LoadData%994715397.body preserve=yes
	// First load all the data
	unsigned int uiID;
	unsigned int uiBlockLenght;
	unsigned char ucMajorVersion,ucMinorVersion;
	// ------------------------
	// Project data
	// ------------------------	
	fread(&uiID,4,1,fd);
	fread(&uiBlockLenght,4,1,fd);
	if (uiID != MAKE_RIFF_ID('T','P','R','J'))
	{
		printf("Invalid project identifier");
		exit(1);
	}
	
	// read structure version
	fread(&ucMajorVersion,1,1,fd);
	fread(&ucMinorVersion,1,1,fd);

	if ((ucMajorVersion>2) || (ucMajorVersion<0) || ((ucMajorVersion==2) && (ucMinorVersion>1)) )
	{
		printf("Unsupported structure version");
		exit(1);
	}

	// skip (for the moment) project data	
	fseek(fd,80,SEEK_CUR);					// skip name
	fseek(fd,sizeof(tdstDate),SEEK_CUR);	// skip creation date
	fseek(fd,sizeof(tdstDate),SEEK_CUR);	// skip modification date

	// ------------------------
	// Heightfield data
	// ------------------------	
	fread(&uiID,4,1,fd);
	fread(&uiBlockLenght,4,1,fd);

	if (uiID != MAKE_RIFF_ID('H','F','L','D'))
	{
		printf("Invalid HeightField identifier");
		exit(1);
	}

	if (! HF->iLoadWithHandler(fd))
	{
		printf("Unable to load height field data");
		exit(1);
	}	
		
	// ------------------------
	// Texture Map data
	// ------------------------
	fread(&uiID,4,1,fd);
	fread(&uiBlockLenght,4,1,fd);
	
	if (uiID != MAKE_RIFF_ID('T','M','A','P'))
	{
		printf("Invalid TexMap identifier");
	}


	if (! TM->iLoadWithHandler(fd))
	{
		printf("Unable to load texture map data");
		exit(1);
	}
	
	// ------------------------
	// Light Map data
	// ------------------------	
	fread(&uiID,4,1,fd);
	fread(&uiBlockLenght,4,1,fd);
	
	if (uiID != MAKE_RIFF_ID('L','M','A','P'))	
	{
		printf("Invalid LightMap identifier");
		exit(1);
	}

	if (! LM->iLoadWithHandler(fd))
	{
		printf("Unable to load light map data");
		exit(1);
	}

	// ------------------------
	// Texture Set data
	// ------------------------
	fread(&uiID,4,1,fd);
	fread(&uiBlockLenght,4,1,fd);
	
	if (uiID != MAKE_RIFF_ID('T','S','E','T'))
	{
		printf("Invalid texset identifier");
		exit(1);
	}

	if (! TS->LoadWithHandler(fd))
	{
		printf("Unable to load tex set data");
		exit(1);
	}

	// ------------------------
	// read environment parameters
	// ------------------------
    if ((ucMajorVersion==2) && (ucMinorVersion == 0))
    {
        memset(&EnvPars,0,sizeof(TEnvironmentPars));
		fread (&EnvPars,104,1,fd);
    }
    else
        fread(&EnvPars,sizeof(TEnvironmentPars),1,fd);

	// ------------------------
	// Useful information
	// ------------------------
	fXYScale	= EnvPars.fXYScale;
	fIScale		= 1.0f / fXYScale;
	iSectorRes	= HF->GetResolution() & 0xfffffffe;
	fSectorSize	= fXYScale * iSectorRes;
	iCircXRes	= HF->iGetSecsPerRow() * iSectorRes;
	iCircYRes	= HF->iGetSecsPerCol() * iSectorRes;
	fCircXSize  = HF->iGetSecsPerRow() * fSectorSize;
	fCircYSize 	= HF->iGetSecsPerCol() * fSectorSize;

	// ------------------------
	// Texture Set data
	// ------------------------
	fread(&uiID,4,1,fd);
	fread(&uiBlockLenght,4,1,fd);
	
	if (uiID != MAKE_RIFF_ID('T','S','E','T'))
	{
		printf("Invalid texset identifier");
		exit(1);
	}

	if (! ATS->LoadWithHandler(fd))
	{
		printf("Unable to load tex set data");
		exit(1);
	}
  //## end TERSceneLoader::LoadData%994715397.body
}

CObject3D * TERSceneLoader::GenerateScene ()
{
  //## begin TERSceneLoader::GenerateScene%994715398.body preserve=yes
	unsigned int cSect,cSectX,cSectY;
	CVect3	     Maxs,Mins;
	float		 fResolution;
	float		 fSize;

	// CObject3D_Node	*TScene;
	CTerrainCircuit *TC = mNew CTerrainCircuit();
	CTerrainSector	*Sect;
	
		
	// Create te main terrain scene object node
	TC->Init(HF->iGetSecsPerRow(),HF->iGetSecsPerCol(),fSectorSize);
	
	// Generate the tile bookmark
	GenerateTileBookmark ();
	
	// Create the tesselator object
	CTerrainTesselatorGM *Tess = mNew CTerrainTesselatorGM();	
	Tess->Init( (iSectorRes+1)*(iSectorRes+1) );
	Tess->SetTileLODPar(EnvPars.fTileLODParam);
		
	// Setup each sector object	
	cSect = 0;
	for (cSectY=0;cSectY<HF->iGetSecsPerCol();cSectY++)
		for (cSectX=0;cSectX<HF->iGetSecsPerRow();cSectX++)
		{		
			// Create sector object
			Sect = mNew CTerrainSector();

			// Setup sector properties
			Sect->HF   = (CHFSector *)HF->GetSector(cSect);
			Sect->TM   = (CTMSector *)TM->GetSector(cSect);
			Sect->LM   = (CLMSector *)LM->GetSector(cSect);
			Sect->TB   = TB;
			Sect->Tess = Tess;			
			Sect->fXYScale = fXYScale;

			fResolution= (float)(Sect->HF->GetResolution() & 0xfffffffe);
			fSize      = fResolution * fXYScale;

			Maxs.V3((cSectX+1)*fSize,(cSectY+1)*fSize,Sect->HF->GetMaxHeight());
			Mins.V3((cSectX  )*fSize,(cSectY  )*fSize,Sect->HF->GetMinHeight());
			Sect->SetMaxsMins(Maxs,Mins);

			// Add sector to the circuit			
			TC->SetSector(cSectX,cSectY,Sect);
						
			cSect++;
		}

	// Create the LOD selector
	TC->SetLODSelector( CreateLODSelector() );
	
	// Create skybox
	SkyBox  = CreateSkyBox();
	SkyDome = CreateSkyDome();

	// Create scene
	/*
	TScene->Init(2);
	TScene->AddObject(SkyBox);
	TScene->AddObject(TC);
	*/
	
	return(TC);
  //## end TERSceneLoader::GenerateScene%994715398.body
}

void TERSceneLoader::GenerateTileBookmark ()
{
  //## begin TERSceneLoader::GenerateTileBookmark%994715400.body preserve=yes
	CE3D_Shader			*poSh;	
	CE3D_ShIns_TexOp	*poTI;
	Texture				*poTex;
	int					iMaxLODs,iMaxTiles,cTile,cLOD;	
	char				MatName[256];

	iMaxTiles = TS->GetMaxMipMaps();
	iMaxLODs  = TS->GetMaxLODS();

	TB = mNew CTileBookmark();
	TB->Init(iMaxTiles,iMaxLODs);

	CE3D_ShaderUtils::SetupTilingFlags(E3D_TEX_WRAP_REPEAT,E3D_TEX_WRAP_REPEAT);

	for (cTile=0;cTile<iMaxTiles;cTile++)
		for (cLOD=0;cLOD<iMaxLODs;cLOD++)
		{
			poTex = TS->GetMipMapLOD(cTile,cLOD);
			if (poTex)
			{	
				sprintf(MatName,"TerrTex%d_LOD%d.tex",cTile,cLOD);
				poSh = CE3D_ShaderUtils::poGenerateShaderFromTexture(poTex,MatName);

				// Add tile rotation shader instruction
				poTI		 = mNew CE3D_ShIns_TexOp;
				poTI->SeteTOpType(eSITexOp_Rotate);
				poTI->poEval = mNew CEval_Const;
				poSh->PushInstruction(poTI);

				TB->SetTileMaterial(cTile,cLOD,poSh);
			}
		}
  //## end TERSceneLoader::GenerateTileBookmark%994715400.body
}

CLODSelector * TERSceneLoader::CreateLODSelector ()
{
  //## begin TERSceneLoader::CreateLODSelector%995406158.body preserve=yes
	CLODSelector_Array *pLODSel = mNew CLODSelector_Array();
	int					cLOD;
	int					MaxLODs = logf(iSectorRes)/log(2.0f);

	pLODSel->Init(MaxLODs);
	
	float fAccum = 0;
	float fValue;
	for (cLOD=0;cLOD<MaxLODs;cLOD++)
	{
		fValue = EnvPars.fTerrLODParam*fSectorSize*(cLOD+1);
		fAccum += fValue;
		
		pLODSel->AddLOD(fAccum);
	}
	
	return (pLODSel);
  //## end TERSceneLoader::CreateLODSelector%995406158.body
}

CSkyBox * TERSceneLoader::CreateSkyBox ()
{
  //## begin TERSceneLoader::CreateSkyBox%996522680.body preserve=yes
	char StrBuff[256];	
	
	CE3D_Shader		*Mats[6];
	Texture			*Tex;	
	int				iTex = 0;

	CSkyBox *pSkyBox = NULL;
	CVect3	 SkyBoxCenter;	
	
	CE3D_ShaderUtils::SetupTilingFlags(E3D_TEX_WRAP_REPEAT,E3D_TEX_WRAP_REPEAT);
	for (int cMat=0;cMat<6;cMat++)
	{
		Tex = ATS->GetTexture(cMat);
		if (Tex)
		{			
			iTex++;
			sprintf(StrBuff,"SkyBox_%d.tex",cMat);
			Mats[cMat] = CE3D_ShaderUtils::poGenerateShaderFromTexture(Tex,StrBuff);
		}
	}
	
	if (iTex == 6)	
	{
		// We have a perfectly defined Sky Box, only if we have the 6 side materials
		pSkyBox = mNew CSkyBox;
		SkyBoxCenter.V3((HF->iGetSecsPerRow()*fSectorSize)/2, 
						(HF->iGetSecsPerCol()*fSectorSize)/2,
						EnvPars.fBKZTranslation);

		pSkyBox->InitSkyBox(EnvPars.fBKDiameter,SkyBoxCenter,EnvPars.fBKRollRotation,Mats);
	}
	
	return(pSkyBox);
  //## end TERSceneLoader::CreateSkyBox%996522680.body
}

CSkyDome * TERSceneLoader::CreateSkyDome ()
{
  //## begin TERSceneLoader::CreateSkyDome%1001452005.body preserve=yes
	CE3D_Shader		*Mat;
	Texture			*Tex;

	CSkyDome *pSkyDome;
	CVect3	 SkyDomeCenter;
	CVect3	 SkyDomeAxis;
		
	CE3D_ShaderUtils::SetupTilingFlags(E3D_TEX_WRAP_REPEAT,E3D_TEX_WRAP_REPEAT);	

	Tex = ATS->GetTexture(6);
	if (! Tex) 	return(NULL);

	Mat = CE3D_ShaderUtils::poGenerateShaderFromTexture(Tex,"SkyDome.tex");
	
	// Create object
	pSkyDome = mNew CSkyDome;
	
	// Setup attributes
	pSkyDome->SetRadius  (EnvPars.fSDDiameter/2);
	SkyDomeAxis.V3		(0.0f,0.0f,1.0f);
	pSkyDome->SetAxis    (SkyDomeAxis); 
	pSkyDome->SetRotation(EnvPars.fSDRollRotation);

	SkyDomeCenter.V3(	0.0f,
						0.0f,
						/*
						(HF->iGetSecsPerRow()*fSectorSize)/2, 
						(HF->iGetSecsPerCol()*fSectorSize)/2,
						*/
						0.0f
						/* (EnvPars.fSDDiameter/2)*(EnvPars.fSDZTranslation/100.0f)*/
						);	

	pSkyDome->SetPosition(SkyDomeCenter);
	
	pSkyDome->CreateDome(EnvPars.iFogAffEv,16,16,0,16,4.0f,-1.0f);
		
	// Set material
	pSkyDome->SetShader(Mat);

	return(pSkyDome);
  //## end TERSceneLoader::CreateSkyDome%1001452005.body
}

// Additional Declarations
  //## begin TERSceneLoader%3B4658C503C0.declarations preserve=yes
  //## end TERSceneLoader%3B4658C503C0.declarations

//## begin module%3B4658C503C0.epilog preserve=yes
//## end module%3B4658C503C0.epilog
