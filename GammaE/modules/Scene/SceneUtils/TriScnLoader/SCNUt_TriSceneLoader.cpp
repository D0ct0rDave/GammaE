//## begin module%3BE6F90101CB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE6F90101CB.cm

//## begin module%3BE6F90101CB.cp preserve=no
//## end module%3BE6F90101CB.cp

//## Module: SCNUt_TriSceneLoader%3BE6F90101CB; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\TriScnLoader\SCNUt_TriSceneLoader.cpp

//## begin module%3BE6F90101CB.additionalIncludes preserve=no
//## end module%3BE6F90101CB.additionalIncludes

//## begin module%3BE6F90101CB.includes preserve=yes
#include "Misc\GammaE_Misc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//## end module%3BE6F90101CB.includes

// SCNUt_TriSceneLoader
#include "Scene\SceneUtils\TriScnLoader\SCNUt_TriSceneLoader.h"
//## begin module%3BE6F90101CB.additionalDeclarations preserve=yes
//## end module%3BE6F90101CB.additionalDeclarations


// Class SCNUt_TriSceneLoader 



SCNUt_TriSceneLoader::SCNUt_TriSceneLoader()
  //## begin SCNUt_TriSceneLoader::SCNUt_TriSceneLoader%.hasinit preserve=no
      : pszMaterials(NULL), iNumMaterials(0)
  //## end SCNUt_TriSceneLoader::SCNUt_TriSceneLoader%.hasinit
  //## begin SCNUt_TriSceneLoader::SCNUt_TriSceneLoader%.initialization preserve=yes
  //## end SCNUt_TriSceneLoader::SCNUt_TriSceneLoader%.initialization
{
  //## begin SCNUt_TriSceneLoader::SCNUt_TriSceneLoader%.body preserve=yes
  //## end SCNUt_TriSceneLoader::SCNUt_TriSceneLoader%.body
}


SCNUt_TriSceneLoader::~SCNUt_TriSceneLoader()
{
  //## begin SCNUt_TriSceneLoader::~SCNUt_TriSceneLoader%.body preserve=yes
  //## end SCNUt_TriSceneLoader::~SCNUt_TriSceneLoader%.body
}



//## Other Operations (implementation)
SCNUt_TriScene * SCNUt_TriSceneLoader::poLoad (char* _szFilename)
{
  //## begin SCNUt_TriSceneLoader::poLoad%1004992830.body preserve=yes
	SCNUt_TriScene	*poScene;
	char			*StrBuff;
	char			*Token;
	char			*StrPos;
	int				iMat,iMatNum;
	int				iTris,iTri;

	CVect3			VXa,VXb,VXc;
	CVect3			VNa,VNb,VNc;
	CVect4			VCa,VCb,VCc;
	CVect2			UVa,UVb,UVc;

	StrBuff = ParseUtils_ReadFile(_szFilename);
	if (! StrBuff) return(NULL);

	iNumMaterials = 0;
	pszMaterials  = NULL;


	StrPos = StrBuff;
	while (StrPos)
	{
		Token  = ParseUtils_ParseToken(StrPos);

		if (! strcmp(Token,"BEGIN"))
		{
			Token = ParseUtils_ParseToken(StrPos);

			if (! strcmp(Token,"TRISCENE"))
			{
				StrPos = ParseUtils_SkipLine(StrPos);
			}
       else if (! strcmp(Token,"MATERIALS"))
			{
				Token = ParseUtils_ParseToken(StrPos);

				sscanf(Token,"%d",&iNumMaterials);

                // skip opening bracket
                StrPos = ParseUtils_SkipLine(StrPos);
				pszMaterials = new char *[iNumMaterials];

				for (iMat=0;iMat<iNumMaterials;iMat++)
				{
                    // Get the material number
					Token  = ParseUtils_ParseToken(StrPos);
                    sscanf(Token,"%d",&iMatNum);

                    // Get the material
					Token  = ParseUtils_ParseToken(StrPos);

					pszMaterials[iMatNum] = ParseUtils_CreateString(Token);
				}
			}
	   else if (! strcmp(Token,"TRIS"))
			{
				Token = ParseUtils_ParseToken(StrPos);

				sscanf(Token,"%d",&iTris);

                // skip opening bracket
                StrPos = ParseUtils_SkipLine(StrPos);

				// Create and parse scene
				poScene =  new SCNUt_TriScene;
				poScene->Init(iTris);

				for (iTri=0;iTri<iTris;iTri++)
				{
					// skip opening braket
					StrPos = ParseUtils_SkipLine(StrPos);

						// Read triangle material
						Token  = ParseUtils_ParseToken(StrPos);
						sscanf(Token,"<%d>",&iMat);

						// Read triangle coordinates
						Token  = StrPos;
						StrPos = ParseUtils_SkipLine(StrPos);
                        *(char*)(StrPos-1) = 0;

						sscanf(Token,"<%f %f %f><%f %f %f><%f %f %f>",
										&VXa.v[0],&VXa.v[1],&VXa.v[2],
										&VXb.v[0],&VXb.v[1],&VXb.v[2],
										&VXc.v[0],&VXc.v[1],&VXc.v[2]);

						// Read vertex normals
						Token  = StrPos;
						StrPos = ParseUtils_SkipLine(StrPos);
                        *(char*)(StrPos-1) = 0;

						sscanf(Token,"<%f %f %f><%f %f %f><%f %f %f>",
										&VNa.v[0],&VNa.v[1],&VNa.v[2],
										&VNb.v[0],&VNb.v[1],&VNb.v[2],
										&VNc.v[0],&VNc.v[1],&VNc.v[2]);

						// Read vertex colors
						Token  = StrPos;
						StrPos = ParseUtils_SkipLine(StrPos);
                        *(char*)(StrPos-1) = 0;

						sscanf(Token,"<%f %f %f><%f %f %f><%f %f %f>",
										&VCa.v[0],&VCa.v[1],&VCa.v[2],
										&VCb.v[0],&VCb.v[1],&VCb.v[2],
										&VCc.v[0],&VCc.v[1],&VCc.v[2]);

                        VCa.v[0] /= 100.0f;
                        VCa.v[1] /= 100.0f;
                        VCa.v[2] /= 100.0f;
                        VCa.v[3] = 1.0f;
                        VCb.v[0] /= 100.0f;
                        VCb.v[1] /= 100.0f;
                        VCb.v[2] /= 100.0f;
                        VCb.v[3] = 1.0f;
                        VCc.v[0] /= 100.0f;
                        VCc.v[1] /= 100.0f;
                        VCc.v[2] /= 100.0f;
                        VCc.v[3] = 1.0f;

						// Read texture coordinates
						Token  = StrPos;
						StrPos = ParseUtils_SkipLine(StrPos);
                        *(char*)(StrPos-1) = 0;

						sscanf(Token,"<%f %f><%f %f><%f %f>",
										&UVa.v[0],&UVa.v[1],
										&UVb.v[0],&UVb.v[1],
										&UVc.v[0],&UVc.v[1]);


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

	free (StrBuff);
    return (poScene);
  //## end SCNUt_TriSceneLoader::poLoad%1004992830.body
}

// Additional Declarations
  //## begin SCNUt_TriSceneLoader%3BE6F90101CB.declarations preserve=yes
  //## end SCNUt_TriSceneLoader%3BE6F90101CB.declarations

//## begin module%3BE6F90101CB.epilog preserve=yes
//## end module%3BE6F90101CB.epilog
