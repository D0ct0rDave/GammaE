// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "AnimScnLoader/SCNUt_AnimSceneLoader.h"
// ----------------------------------------------------------------------------
SCNUt_AnimSceneLoader::~SCNUt_AnimSceneLoader()
{
}
// ----------------------------------------------------------------------------
SCNUt_AnimSceneLoader::SCNUt_AnimSceneLoader()
{
}
// ----------------------------------------------------------------------------
CGSceneNode* SCNUt_AnimSceneLoader::poLoad(char* _szFilename)
{
    char* StrBuff;
    char* Token;
    char* StrPos;
    int iMat,iMatNum;
    int iTris,iTri;
    int iNumFrames;

    CGVect3 VXa,VXb,VXc;
    CGVect3 VNa,VNb,VNc;
    CGVect4 VCa,VCb,VCc;
    CGVect2 UVa,UVb,UVc;

    CGDynArray <SCNUt_TriScene*> oFrames;
    SCNUt_TriScene* poStartupFrame;

    StrBuff = Utils::Parse::ReadFile(_szFilename);
    if ( !StrBuff ) return(NULL);

    m_oMaterials.Clear();

    // Animation frames
    iNumFrames = 0;

    StrPos = StrBuff;
    while ( *StrPos)
    {
        Token = Utils::Parse::ParseToken(StrPos);

        if ( !strcmp(Token,"BEGIN") )
        {
            Token = Utils::Parse::ParseToken(StrPos);

            if ( !strcmp(Token,"TRISCENE") )
            {
                StrPos = Utils::Parse::SkipLine(StrPos);
            }
            else if ( !strcmp(Token,"MATERIALS") )
            {
                Token = Utils::Parse::ParseToken(StrPos);

                int iNumMaterials;
                sscanf_s(Token,"%d",&iNumMaterials);

                // skip opening bracket
                StrPos = Utils::Parse::SkipLine(StrPos);

                // Read the materials
                for ( iMat = 0; iMat < iNumMaterials; iMat++ )
                {
                    // Get the material number
                    Token = Utils::Parse::ParseToken(StrPos);
                    sscanf_s(Token,"%d",&iMatNum);
                    iMatNum--;  // Materials are 1 based

                    // Get the material
                    Token = Utils::Parse::ParseToken(StrPos);
                    m_oMaterials.uiAdd( Token );
                }
            }
            else if ( !strcmp(Token,"TRIS") )
            {
                Token = Utils::Parse::ParseToken(StrPos);

                sscanf_s(Token,"%d",&iTris);

                // skip opening bracket
                StrPos = Utils::Parse::SkipLine(StrPos);

                // Create and parse scene
                poStartupFrame = mNew SCNUt_TriScene;
                poStartupFrame->Init(iTris);

                for ( iTri = 0; iTri < iTris; iTri++ )
                {
                    // skip opening braket
                    StrPos = Utils::Parse::SkipLine(StrPos);

                    // Read triangle material
                    Token = Utils::Parse::ParseToken(StrPos);
                    sscanf_s(Token,"<%d>",&iMat);
                    iMat--;     // Materials are 1 based

                    // Read triangle coordinates
                    Token = StrPos;
                    StrPos = Utils::Parse::SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf_s( Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VXa.v(0),&VXa.v(1),&VXa.v(2),
                           &VXb.v(0),&VXb.v(1),&VXb.v(2),
                           &VXc.v(0),&VXc.v(1),&VXc.v(2) );

                    // Read vertex normals
                    Token = StrPos;
                    StrPos = Utils::Parse::SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf_s( Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VNa.v(0),&VNa.v(1),&VNa.v(2),
                           &VNb.v(0),&VNb.v(1),&VNb.v(2),
                           &VNc.v(0),&VNc.v(1),&VNc.v(2) );

                    // Read vertex colors
                    Token = StrPos;
                    StrPos = Utils::Parse::SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf_s( Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VCa.v(0),&VCa.v(1),&VCa.v(2),
                           &VCb.v(0),&VCb.v(1),&VCb.v(2),
                           &VCc.v(0),&VCc.v(1),&VCc.v(2) );

                    VCa.v(0) /= 100.0f;
                    VCa.v(1) /= 100.0f;
                    VCa.v(2) /= 100.0f;
                    VCa.v(3) = 1.0f;
                    VCb.v(0) /= 100.0f;
                    VCb.v(1) /= 100.0f;
                    VCb.v(2) /= 100.0f;
                    VCb.v(3) = 1.0f;
                    VCc.v(0) /= 100.0f;
                    VCc.v(1) /= 100.0f;
                    VCc.v(2) /= 100.0f;
                    VCc.v(3) = 1.0f;

                    // Read texture coordinates
                    Token = StrPos;
                    StrPos = Utils::Parse::SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf_s( Token,"<%f %f><%f %f><%f %f>",
                           &UVa.v(0),&UVa.v(1),
                           &UVb.v(0),&UVb.v(1),
                           &UVc.v(0),&UVc.v(1) );

                    // skip closing braket
                    StrPos = Utils::Parse::SkipLine(StrPos);

                    // Setup triangle
                    poStartupFrame->Tris[iTri].VXs[0] = VXa;
                    poStartupFrame->Tris[iTri].VXs[1] = VXb;
                    poStartupFrame->Tris[iTri].VXs[2] = VXc;

                    poStartupFrame->Tris[iTri].VNs[0] = VNa;
                    poStartupFrame->Tris[iTri].VNs[1] = VNb;
                    poStartupFrame->Tris[iTri].VNs[2] = VNc;

                    poStartupFrame->Tris[iTri].VCs[0] = VCa;
                    poStartupFrame->Tris[iTri].VCs[1] = VCb;
                    poStartupFrame->Tris[iTri].VCs[2] = VCc;

                    poStartupFrame->Tris[iTri].UVs[0] = UVa;
                    poStartupFrame->Tris[iTri].UVs[1] = UVb;
                    poStartupFrame->Tris[iTri].UVs[2] = UVc;

                    poStartupFrame->Tris[iTri].Material = iMat;
                }
            }
            else if ( !strcmp(Token,"ANIMFRAMES") )
            {
                Token = Utils::Parse::ParseToken(StrPos);

                sscanf_s(Token,"%i",&iNumFrames);

                //
            }
            else if ( !strcmp(Token,"ANIMFRAME") )
            {
                // skip frame number
                Token = Utils::Parse::ParseToken(StrPos);

                // Skip opening braket
                StrPos = Utils::Parse::SkipLine(StrPos);

                // Create and parse scene
                SCNUt_TriScene* poFrame = mNew SCNUt_TriScene;
                poFrame->Init(iTris);

                for ( iTri = 0; iTri < iTris; iTri++ )
                {
                    // skip opening braket
                    StrPos = Utils::Parse::SkipLine(StrPos);

                    // Read triangle coordinates
                    Token = StrPos;
                    StrPos = Utils::Parse::SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf_s( Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VXa.v(0),&VXa.v(1),&VXa.v(2),
                           &VXb.v(0),&VXb.v(1),&VXb.v(2),
                           &VXc.v(0),&VXc.v(1),&VXc.v(2) );

                    // Read vertex normals
                    Token = StrPos;
                    StrPos = Utils::Parse::SkipLine(StrPos);
                    *(char*)(StrPos - 1) = 0;

                    sscanf_s( Token,"<%f %f %f><%f %f %f><%f %f %f>",
                           &VNa.v(0),&VNa.v(1),&VNa.v(2),
                           &VNb.v(0),&VNb.v(1),&VNb.v(2),
                           &VNc.v(0),&VNc.v(1),&VNc.v(2) );

                    // Setup triangle
                    poFrame->Tris[iTri].VXs[0] = VXa;
                    poFrame->Tris[iTri].VXs[1] = VXb;
                    poFrame->Tris[iTri].VXs[2] = VXc;

                    poFrame->Tris[iTri].VNs[0] = VNa;
                    poFrame->Tris[iTri].VNs[1] = VNb;
                    poFrame->Tris[iTri].VNs[2] = VNc;

                    poFrame->Tris[iTri].Material = 0;

                    // skip closing braket
                    StrPos = Utils::Parse::SkipLine(StrPos);
                }

                oFrames.uiAdd(poFrame);
            }
        }
    }

    // Compact the startup frame mesh
    SCNUt_MeshCompacter oMC;
    CCompactMeshData oCD;
    oMC.CompactMesh(*poStartupFrame,&oCD);
    oCD.m_poMesh->SetBV(CGGraphBVFactory::poCreate());
    oCD.m_poMesh->poGetBV()->Compute(oCD.m_poMesh->m_poVN, oCD.m_poMesh->uiGetNumVXs());

    // Build anim mesh
    CGVect3* poVXs = mNew CGVect3[ oFrames.uiNumElems() * oCD.m_oInvTable.uiNumElems() ];
    CGVect3* poVNs = mNew CGVect3[ oFrames.uiNumElems() * oCD.m_oInvTable.uiNumElems() ];
    CGVect3* poVX = poVXs;
    CGVect3* poVN = poVNs;

    for ( uint j = 0; j < oFrames.uiNumElems(); j++ )
    {
        SCNUt_TriScene* poScn = oFrames[j];
        for ( uint i = 0; i < oCD.m_oInvTable.uiNumElems(); i++ )
        {
            uint uiTri = oCD.m_oInvTable[i].m_uiTri;
            uint uiVX = oCD.m_oInvTable[i].m_uiVX;

            *poVX = poScn->Tris[uiTri].VXs[uiVX];
            *poVN = poScn->Tris[uiTri].VNs[uiVX];

            poVX++;
            poVN++;
        }
    }

    // Create the animation mesh
    CGSceneAnimMesh* poAM = mNew CGSceneAnimMesh;
    poAM->Setup(oCD.m_poMesh, oFrames.uiNumElems(), oCD.m_oInvTable.uiNumElems());

    // Create configuration
    CGSceneAnimActionSet* poACfg = mNew CGSceneAnimActionSet;
    poACfg->uiAddAction("TEST",0,oFrames.uiNumElems(),30.0f,true);
    poACfg->SetAnimObject(poAM);

    // Rebuild bounding volumes
    CGSCNVBoundVolBuilder::I()->Visit(poAM);

    // Free resources
    MEMFree (StrBuff);

    return (poACfg);
}
// ----------------------------------------------------------------------------
