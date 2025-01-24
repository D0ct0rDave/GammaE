// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#include "Gammae_FileSys.h"
#include <string.h>
#include "GammaE_Mem.h"

// TERSceneLoader
#include "TerrainScene\SceneLoaders\TERScene\TERSceneLoader.h"
#define ShowMessage(Msg)

// Class TERSceneLoader

TERSceneLoader::TERSceneLoader()
    : HF(NULL), TM(NULL), LM(NULL), TS(NULL), ATS(NULL), iSectorRes(0), fSectorSize(0), fXYScale(0), fIScale(0), iCircXRes(0), iCircYRes(0), fCircXSize(0), fCircYSize(0), poTB(NULL), poTT(NULL), poLS(NULL)
{
}

TERSceneLoader::~TERSceneLoader()
{
    if ( HF ) mDel HF;
    if ( TM ) mDel TM;
    if ( LM ) mDel LM;
    if ( TS ) mDel TS;
    if ( ATS ) mDel ATS;
    if ( poTB ) mDel poTB;
    if ( poTT ) mDel poTT;
    if ( poLS ) mDel poLS;
}

CGSceneNode* TERSceneLoader::poLoad (char* _Filename)
{
    FILE* fd;
    fd = fopen(_Filename,"rb");
    if ( !fd ) return(NULL);

    // First load the scene
    LoadData(fd);
    fclose(fd);

    CreateSharedObjects();

    // Now build the scene
    CGSceneNode* poScene = poGenerateScene();
    return(poScene);
}

void TERSceneLoader::LoadData (FILE* fd)
{
    // First load all the data
    unsigned int uiID;
    unsigned int uiBlockLenght;
    unsigned char ucMajorVersion,ucMinorVersion;
    // ------------------------
    // Project data
    // ------------------------
    fread(&uiID,4,1,fd);
    fread(&uiBlockLenght,4,1,fd);
    if ( uiID != MAKE_RIFF_ID('T','P','R','J') )
    {
        printf("Invalid project identifier");
        exit(1);
    }

    // read structure version
    fread(&ucMajorVersion,1,1,fd);
    fread(&ucMinorVersion,1,1,fd);

    if ( (ucMajorVersion > 2) || (ucMajorVersion < 0) || ( (ucMajorVersion == 2) && (ucMinorVersion > 1) ) )
    {
        printf("Unsupported structure version");
        exit(1);
    }

    // skip (for the moment) project data
    fseek(fd,80,SEEK_CUR);                  // skip name
    fseek(fd,sizeof(TDate),SEEK_CUR);   // skip creation date
    fseek(fd,sizeof(TDate),SEEK_CUR);   // skip modification date

    // ------------------------
    // Heightfield data
    // ------------------------
    fread(&uiID,4,1,fd);
    fread(&uiBlockLenght,4,1,fd);

    if ( uiID != MAKE_RIFF_ID('H','F','L','D') )
    {
        printf("Invalid HeightField identifier");
        exit(1);
    }

    HF = mNew CHeightField();
    if ( !HF->iLoadWithHandler(fd) )
    {
        printf("Unable to load height field data");
        exit(1);
    }

    // ------------------------
    // Texture Map data
    // ------------------------
    fread(&uiID,4,1,fd);
    fread(&uiBlockLenght,4,1,fd);

    if ( uiID != MAKE_RIFF_ID('T','M','A','P') )
    {
        printf("Invalid TexMap identifier");
    }

    TM = mNew CTexMap();
    if ( !TM->iLoadWithHandler(fd) )
    {
        printf("Unable to load texture map data");
        exit(1);
    }

    // ------------------------
    // Light Map data
    // ------------------------
    fread(&uiID,4,1,fd);
    fread(&uiBlockLenght,4,1,fd);

    if ( uiID != MAKE_RIFF_ID('L','M','A','P') )
    {
        printf("Invalid LightMap identifier");
        exit(1);
    }

    LM = mNew CLightMap();
    if ( !LM->iLoadWithHandler(fd) )
    {
        printf("Unable to load light map data");
        exit(1);
    }

    // ------------------------
    // Texture Set data
    // ------------------------
    fread(&uiID,4,1,fd);
    fread(&uiBlockLenght,4,1,fd);

    if ( uiID != MAKE_RIFF_ID('T','S','E','T') )
    {
        printf("Invalid texset identifier");
        exit(1);
    }

    TS = mNew TTexSet();
    if ( !TS->LoadWithHandler(fd) )
    {
        printf("Unable to load tex set data");
        exit(1);
    }

    // ------------------------
    // read environment parameters
    // ------------------------
    if ( (ucMajorVersion == 2) && (ucMinorVersion == 0) )
    {
        memset( &EnvPars,0,sizeof(TEnvironmentPars) );
        fread (&EnvPars,104,1,fd);
    }
    else
        fread(&EnvPars,sizeof(TEnvironmentPars),1,fd);

    // ------------------------
    // Useful information
    // ------------------------
    fXYScale = EnvPars.fXYScale;
    fIScale = 1.0f / fXYScale;
    iSectorRes = HF->GetResolution() & 0xfffffffe;
    fSectorSize = fXYScale * iSectorRes;
    iCircXRes = HF->iGetSecsPerRow() * iSectorRes;
    iCircYRes = HF->iGetSecsPerCol() * iSectorRes;
    fCircXSize = HF->iGetSecsPerRow() * fSectorSize;
    fCircYSize = HF->iGetSecsPerCol() * fSectorSize;

    // ------------------------
    // Texture Set data
    // ------------------------
    fread(&uiID,4,1,fd);
    fread(&uiBlockLenght,4,1,fd);

    if ( uiID != MAKE_RIFF_ID('T','S','E','T') )
    {
        printf("Invalid texset identifier");
        exit(1);
    }

    ATS = mNew TTexSet();
    if ( !ATS->LoadWithHandler(fd) )
    {
        printf("Unable to load tex set data");
        exit(1);
    }
}

void TERSceneLoader::CreateSharedObjects ()
{
    // Generate the tile bookmark
    poTB = poCreateTileBookmark ();

    // Create the tesselator object
    poTT = mNew CTerrainTesselatorGM();
    poTT->Init( (iSectorRes + 1) * (iSectorRes + 1) );
    poTT->SetTileLODPar(EnvPars.fTileLODParam);

    // Create the LOD selector
    poLS = poCreateLODSelector();
}

CTileBookmark* TERSceneLoader::poCreateTileBookmark ()
{
    CTileBookmark* poTB;
    CE3D_Shader* poSh;
    CE3D_ShIns_TexOp* poTI;
    CGMipMap* poTex;
    int iMaxLODs,iMaxTiles,cTile,cLOD;
    char MatName[256];

    iMaxTiles = TS->GetMaxMipMaps();
    iMaxLODs = TS->GetMaxLODS();

    poTB = mNew CTileBookmark();
    poTB->Init(iMaxTiles,iMaxLODs);

    CE3D_ShaderUtils::SetupTilingFlags(E3D_TEX_WRAP_REPEAT,E3D_TEX_WRAP_REPEAT);
    CE3D_ShaderUtils::SetupFilterFlags(E3D_TEX_MIN_FILTER_LINEAR_MIPMAP_LINEAR,
                                       E3D_TEX_MAX_FILTER_LINEAR);
    /*
       CE3D_ShaderUtils::SetupFilterFlags(E3D_TEX_MIN_FILTER_NEAREST,
                                        E3D_TEX_MAX_FILTER_NEAREST);
     */
    for ( cTile = 0; cTile < iMaxTiles; cTile++ )
    {
        poTex = TS->GetMipMap(cTile);

        if ( poTex )
        {
            sprintf(MatName,"TerrTex%d_LOD%d.tex",cTile,cLOD);
            poSh = CE3D_ShaderUtils::poGenerateShaderFromMipMap(poTex,MatName);

            // Add tile rotation shader instruction
            poTI = mNew CE3D_ShIns_TexOp;
            poTI->SetTOpType(eSITexOp_Rotate);
            poTI->SetEvaluator( mNew CEval_Const );
            poSh->PushInstruction(poTI);

            poTB->SetTileMaterial(cTile,cLOD,poSh);
        }
    }

    CE3D_ShaderUtils::SetupFilterFlags(E3D_TEX_MIN_FILTER_NEAREST,E3D_TEX_MAX_FILTER_LINEAR);
    return(poTB);
}

CLODSelector* TERSceneLoader::poCreateLODSelector ()
{
    CLODSelector_Array* pLODSel = mNew CLODSelector_Array();
    int cLOD;
    int MaxLODs = log( (float)iSectorRes ) / log(2.0f);

    pLODSel->Init(MaxLODs);

    float fAccum = 0;
    float fValue;
    for ( cLOD = 0; cLOD < MaxLODs; cLOD++ )
    {
        fValue = EnvPars.fTerrLODParam * fSectorSize * (cLOD + 1);
        fAccum += fValue;

        pLODSel->AddLOD(fAccum);
    }

    return (pLODSel);
}

CSkyBox* TERSceneLoader::poCreateSkyBox ()
{
    char StrBuff[256];

    CE3D_Shader* Mats[6];
    CGMipMap* Tex;
    int iTex = 0;

    CSkyBox* pSkyBox = NULL;
    CVect3 SkyBoxCenter;

    CE3D_ShaderUtils::SetupTilingFlags(E3D_TEX_WRAP_REPEAT,E3D_TEX_WRAP_REPEAT);
    for ( int cMat = 0; cMat < 6; cMat++ )
    {
        Tex = ATS->GetMipMap(cMat);
        if ( Tex )
        {
            iTex++;
            sprintf(StrBuff,"SkyBox_%d.tex",cMat);
            Mats[cMat] = CE3D_ShaderUtils::poGenerateShaderFromMipMap(Tex,StrBuff);
        }
    }

    if ( iTex == 6 )
    {
        // We have a perfectly defined Sky Box, only if we have the 6 side materials
        pSkyBox = mNew CSkyBox;
        SkyBoxCenter.V3( (HF->iGetSecsPerRow() * fSectorSize) / 2,
                        (HF->iGetSecsPerCol() * fSectorSize) / 2,
                        EnvPars.fBKZTranslation );

        pSkyBox->InitSkyBox(EnvPars.fBKDiameter,SkyBoxCenter,EnvPars.fBKRollRotation,Mats);
    }

    return(pSkyBox);
}

CSkyDome* TERSceneLoader::poCreateSkyDome ()
{
    CE3D_Shader* Mat;
    CGMipMap* Tex;

    CSkyDome* pSkyDome;
    CVect3 SkyDomeCenter;
    CVect3 SkyDomeAxis;

    CE3D_ShaderUtils::SetupTilingFlags(E3D_TEX_WRAP_REPEAT,E3D_TEX_WRAP_REPEAT);

    Tex = ATS->GetMipMap(6);
    if ( !Tex ) return(NULL);

    Mat = CE3D_ShaderUtils::poGenerateShaderFromMipMap(Tex,"SkyDome.tex");

    // Create object
    pSkyDome = mNew CSkyDome;

    // Setup attributes
    pSkyDome->SetRadius  (EnvPars.fSDDiameter / 2);
    SkyDomeAxis.V3      (0.0f,0.0f,1.0f);
    pSkyDome->SetAxis    (SkyDomeAxis);
    pSkyDome->SetRotation(EnvPars.fSDRollRotation);

    SkyDomeCenter.V3(   0.0f,
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
}

CGSceneNode* TERSceneLoader::poGenerateScene ()
{
    unsigned int cSect,cSectX,cSectY;
    CVect3 Maxs,Mins;
    float fResolution;
    float fSize;

    // CGSceneNode	*TScene;
    CTerrainCircuit* poTC = mNew CTerrainCircuit();
    CTerrainSector* poSect;

    // Create te main terrain scene object node
    poTC->Init(HF->iGetSecsPerRow(),HF->iGetSecsPerCol(),fSectorSize);

    // Setup each sector object
    cSect = 0;
    for ( cSectY = 0; cSectY < HF->iGetSecsPerCol(); cSectY++ )
        for ( cSectX = 0; cSectX < HF->iGetSecsPerRow(); cSectX++ )
        {
            // Create sector object
            poSect = mNew CTerrainSector();

            // Setup sector properties
            poSect->HF = (CHFSector*)HF->GetSector(cSect);
            poSect->TM = (CTMSector*)TM->GetSector(cSect);
            poSect->LM = (CLMSector*)LM->GetSector(cSect);
            poSect->TB = poTB;
            poSect->Tess = poTT;
            poSect->fXYScale = fXYScale;

            fResolution = (float)(poSect->HF->GetResolution() & 0xfffffffe);
            fSize = fResolution * fXYScale;

            Maxs.V3( (cSectX + 1) * fSize,(cSectY + 1) * fSize,poSect->HF->GetMaxHeight() );
            Mins.V3( (cSectX) * fSize,(cSectY) * fSize,poSect->HF->GetMinHeight() );
            poSect->SetMaxsMins(Maxs,Mins);

            // Add sector to the circuit
            poTC->SetSector(cSectX,cSectY,poSect);
            cSect++;
        }

    poTC->SetLODSelector( poLS );
    return(poTC);
}

// Additional Declarations
