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
#include "GammaE_Misc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// SCNUt_TriSceneLoader
#include "TriScnLoader\SCNUt_TriSceneLoader.h"

// Class SCNUt_TriSceneLoader
SCNUt_TriSceneLoader::SCNUt_TriSceneLoader()
{
}

SCNUt_TriSceneLoader::~SCNUt_TriSceneLoader()
{
}

SCNUt_TriScene* SCNUt_TriSceneLoader::poLoad (char* _szFilename, SCNUt_MaterialTable& _oMTable)
{
    SCNUt_TriScene* poScene;
    char* StrBuff;
    char* Token;
    char* StrPos;
    int iMat,iMatNum;
    int iTris,iTri;

    CVect3 VXa,VXb,VXc;
    CVect3 VNa,VNb,VNc;
    CVect4 VCa,VCb,VCc;
    CVect2 UVa,UVb,UVc;

    StrBuff = ParseUtils_ReadFile(_szFilename);
    if ( !StrBuff ) return(NULL);

    // Clean material table ... just in case
    _oMTable.Invalidate();

    StrPos = StrBuff;
    while ( StrPos )
    {
        Token = ParseUtils_ParseToken(StrPos);

        if ( !strcmp(Token,"BEGIN") )
        {
            Token = ParseUtils_ParseToken(StrPos);

            if ( !strcmp(Token,"TRISCENE") )
            {
                StrPos = ParseUtils_SkipLine(StrPos);
            }
            else if ( !strcmp(Token,"MATERIALS") )
            {
                Token = ParseUtils_ParseToken(StrPos);

                int iNumMaterials = 0;
                sscanf(Token,"%d",&iNumMaterials);

                // skip opening bracket
                StrPos = ParseUtils_SkipLine(StrPos);

                for ( iMat = 0; iMat < iNumMaterials; iMat++ )
                {
                    // Get the material number
                    Token = ParseUtils_ParseToken(StrPos);
                    sscanf(Token,"%d",&iMatNum);
                    iMatNum--;  // Materials are 1 based

                    // Get the material
                    Token = ParseUtils_ParseToken(StrPos);

                    // Add the material to the material table
                    CE3D_Shader* poShader = CE3D_ShaderWH::I()->poCreateShader(Token);
                    if ( poShader == NULL )
                    {
                        poShader = mNew CE3D_Shader;
                        CE3D_ShaderWH::I()->uiAdd(poShader,Token);
                    }

                    _oMTable.uiAdd(poShader,Token);

                    // const CE3D_Shader*poShader = poLeaf->poGetShader();
                    // const char* szShaderName = CE3D_ShaderWH::I()->sGetName( poShader ).szString();
                    // pszMaterials[iMatNum] = ParseUtils_CreateString(Token);
                }
            }
            else if ( !strcmp(Token,"TRIS") )
            {
                Token = ParseUtils_ParseToken(StrPos);

                sscanf(Token,"%d",&iTris);

                // skip opening bracket
                StrPos = ParseUtils_SkipLine(StrPos);

                // Create and parse scene
                poScene = mNew SCNUt_TriScene;
                poScene->Init(iTris);

                for ( iTri = 0; iTri < iTris; iTri++ )
                {
                    // skip opening braket
                    StrPos = ParseUtils_SkipLine(StrPos);

                    // Read triangle material
                    Token = ParseUtils_ParseToken(StrPos);
                    sscanf(Token,"<%d>",&iMat);
                    iMat--;                    // Materials are 1 based

                    // Read triangle coordinates
                    Token = StrPos;
                    StrPos = ParseUtils_SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf(Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VXa.x,&VXa.y,&VXa.z,
                           &VXb.x,&VXb.y,&VXb.z,
                           &VXc.x,&VXc.y,&VXc.z);

                    // Read vertex normals
                    Token = StrPos;
                    StrPos = ParseUtils_SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf(Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VNa.x,&VNa.y,&VNa.z,
                           &VNb.x,&VNb.y,&VNb.z,
                           &VNc.x,&VNc.y,&VNc.z);

                    // Read vertex colors
                    Token = StrPos;
                    StrPos = ParseUtils_SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf(Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VCa.x,&VCa.y,&VCa.z,
                           &VCb.x,&VCb.y,&VCb.z,
                           &VCc.x,&VCc.y,&VCc.z);

                    VCa.x /= 100.0f;
                    VCa.y /= 100.0f;
                    VCa.z /= 100.0f;
                    VCa.w = 1.0f;
                    VCb.x /= 100.0f;
                    VCb.y /= 100.0f;
                    VCb.z /= 100.0f;
                    VCb.w = 1.0f;
                    VCc.x /= 100.0f;
                    VCc.y /= 100.0f;
                    VCc.z /= 100.0f;
                    VCc.w = 1.0f;

                    // Read texture coordinates
                    Token = StrPos;
                    StrPos = ParseUtils_SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf(Token,"<%f %f><%f %f><%f %f>",
                           &UVa.x,&UVa.y,
                           &UVb.x,&UVb.y,
                           &UVc.x,&UVc.y);

                    // skip closing braket
                    StrPos = ParseUtils_SkipLine(StrPos);

                    // Setup triangle
                    poScene->Tris[iTri].VXs[0] = VXa;
                    poScene->Tris[iTri].VXs[1] = VXb;
                    poScene->Tris[iTri].VXs[2] = VXc;

                    poScene->Tris[iTri].VNs[0] = VNa;
                    poScene->Tris[iTri].VNs[1] = VNb;
                    poScene->Tris[iTri].VNs[2] = VNc;

                    poScene->Tris[iTri].VCs[0] = VCa;
                    poScene->Tris[iTri].VCs[1] = VCb;
                    poScene->Tris[iTri].VCs[2] = VCc;

                    poScene->Tris[iTri].UVs[0] = UVa;
                    poScene->Tris[iTri].UVs[1] = UVb;
                    poScene->Tris[iTri].UVs[2] = UVc;

                    poScene->Tris[iTri].Material = iMat;
                }
            }
        }
    }

    MEMFree (StrBuff);
    return (poScene);
}

// Additional Declarations
