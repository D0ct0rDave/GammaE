//## begin module%3C2B3AF301FA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2B3AF301FA.cm

//## begin module%3C2B3AF301FA.cp preserve=no
//## end module%3C2B3AF301FA.cp

//## Module: GameDum_Loader%3C2B3AF301FA; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\GameMap\GameDummy\GameDum_Loader.cpp

//## begin module%3C2B3AF301FA.additionalIncludes preserve=no
//## end module%3C2B3AF301FA.additionalIncludes

//## begin module%3C2B3AF301FA.includes preserve=yes
#include <stdlib.h>
#include <stdio.h>
#include "Memory/GammaE_Mem.h"
//## end module%3C2B3AF301FA.includes

// GameDum_Loader
#include "Game\GameScene\GameMap\GameDummy\GameDum_Loader.h"
//## begin module%3C2B3AF301FA.additionalDeclarations preserve=yes
//## end module%3C2B3AF301FA.additionalDeclarations


// Class GameDum_Loader 

GameDum_Loader::GameDum_Loader()
  //## begin GameDum_Loader::GameDum_Loader%.hasinit preserve=no
  //## end GameDum_Loader::GameDum_Loader%.hasinit
  //## begin GameDum_Loader::GameDum_Loader%.initialization preserve=yes
  //## end GameDum_Loader::GameDum_Loader%.initialization
{
  //## begin GameDum_Loader::GameDum_Loader%.body preserve=yes
  //## end GameDum_Loader::GameDum_Loader%.body
}


GameDum_Loader::~GameDum_Loader()
{
  //## begin GameDum_Loader::~GameDum_Loader%.body preserve=yes
  //## end GameDum_Loader::~GameDum_Loader%.body
}



//## Other Operations (implementation)
CObject3D* GameDum_Loader::pLoad (char* _szFilename)
{
  //## begin GameDum_Loader::pLoad%1009496916.body preserve=yes
	FILE			*fd;
	unsigned int	uiDummyID;
	unsigned int	uiBlockSize;
	
	unsigned char	ucMajorVersion;
	unsigned char	ucMinorVersion;

	TDummyInfo		DInfo;

	unsigned int	uiDType;

	fd = fopen(_szFilename,"rb");
	if (! fd) return(NULL);

	
    // begin riff header
    fread(&uiDummyID,4,1,fd);
    fread(&uiBlockSize,4,1,fd);

    if (uiDummyID != DIF_FILEIDENTIFIER)
    {
        fclose(fd);        
        return(NULL);
    }

    fread(&ucMajorVersion,1,1,fd);
    fread(&ucMinorVersion,1,1,fd);

    if ((ucMajorVersion>DIF_MAJORVERSION) ||
        (ucMajorVersion==DIF_MAJORVERSION) && (ucMinorVersion>DIF_MINORVERSION))
    {
        fclose(fd);
        return(NULL);
    }

        // -----------------------------
        // Read data
        // -----------------------------


        // Read terrain scene linked to dummy info
        fread(DInfo.szTerrainScene,DINFO_MAXCARS,1,fd);
        DInfo.szTerrainScene[DINFO_MAXCARS] = 0;
        
        // Write the number of dummy types
        fread(&DInfo.uiNumDTs,4,1,fd);
		DInfo.pDT = mNew TDummyList[DInfo.uiNumDTs];
        
        // Write dummy properties
        for (uiDType=0;uiDType<DInfo.uiNumDTs;uiDType++)
        {
            // read dummy filename
            fread(DInfo.pDT[uiDType].szModelName,DINFO_MAXCARS,1,fd);
            DInfo.pDT[uiDType].szModelName[DINFO_MAXCARS] = 0;
            
            // read used algorithm
            fread(&DInfo.pDT[uiDType].iAlgType,4,1,fd);

            // read probability
            fread(&DInfo.pDT[uiDType].fProb,4,1,fd);

            // read scale
            fread(&DInfo.pDT[uiDType].fScale,4,1,fd);

            // read  iterations
			fread(&DInfo.pDT[uiDType].iIters,4,1,fd);            

            // -----------------------------
            // read the dummy instance list
            // -----------------------------

                // read the number of instances
                fread(&DInfo.pDT[uiDType].uiNumDInsts,4,1,fd);
				DInfo.pDT[uiDType].pDInsts = mNew CVect3[DInfo.pDT[uiDType].uiNumDInsts];

                // Clear previous instance list
				fread( DInfo.pDT[uiDType].pDInsts,DInfo.pDT[uiDType].uiNumDInsts,sizeof(CVect3),fd);
        }

    fclose(fd);

	CObject3D *pDummyScene;
	pDummyScene = pCreateDummyScene(DInfo);

	DestroyDummyInfo(DInfo);

	return(pDummyScene);
  //## end GameDum_Loader::pLoad%1009496916.body
}

CObject3D* GameDum_Loader::pCreateDummyScene (TDummyInfo& _DInfo)
{
  //## begin GameDum_Loader::pCreateDummyScene%1009496917.body preserve=yes
	unsigned int	uiDType;
	unsigned int	uiDInst;
	CObject3D		*pDMdl;
	CObject3D_Transf*pLeafNode;
	CObject3D_Node	*pDTNode;
	CObject3D_Node	*pMainNode;
	CLoaderGEM		GEMLoader;

	pMainNode = mNew CObject3D_Node;
	pMainNode->Init(_DInfo.uiNumDTs);

	for (uiDType=0;uiDType<_DInfo.uiNumDTs;uiDType++)
	{
		pDMdl = GEMLoader.pLoad(_DInfo.pDT[uiDType].szModelName);
		if (pDMdl)
		{
			pDTNode = mNew CObject3D_Node;
			pDTNode->Init(_DInfo.pDT[uiDType].uiNumDInsts);

			for (uiDInst=0;uiDInst<_DInfo.pDT[uiDType].uiNumDInsts;uiDInst++)
			{
				// Setup instance
				pLeafNode = mNew CObject3D_Transf;
				pLeafNode->SetObject(pDMdl);
				pLeafNode->SetPos(_DInfo.pDT[uiDType].pDInsts[uiDInst]);
				
				// Add instance to this dummy type list
				pDTNode->iAddObject(pLeafNode);
			}

			// Add this dummy type list to the main dummy scene node
			pMainNode->iAddObject(pDTNode);
		}
	}

	pMainNode->ComputeBoundVol();
	return(pMainNode);
  //## end GameDum_Loader::pCreateDummyScene%1009496917.body
}

void GameDum_Loader::DestroyDummyInfo (TDummyInfo& _DInfo)
{
  //## begin GameDum_Loader::DestroyDummyInfo%1009496918.body preserve=yes
	unsigned int uiDType;
    
    for (uiDType=0;uiDType<_DInfo.uiNumDTs;uiDType++)
	{
		mDel []_DInfo.pDT[uiDType].pDInsts;			
	}
	
	mDel []_DInfo.pDT;
  //## end GameDum_Loader::DestroyDummyInfo%1009496918.body
}

// Additional Declarations
  //## begin GameDum_Loader%3C2B3AF301FA.declarations preserve=yes
  //## end GameDum_Loader%3C2B3AF301FA.declarations

//## begin module%3C2B3AF301FA.epilog preserve=yes
//## end module%3C2B3AF301FA.epilog
