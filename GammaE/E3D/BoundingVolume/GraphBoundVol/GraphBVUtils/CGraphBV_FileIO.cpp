//## begin module%3BA91166024F.cm preserve=no
//## end module%3BA91166024F.cm

//## begin module%3BA91166024F.cp preserve=no
//## end module%3BA91166024F.cp

//## Module: CGraphBV_FileIO%3BA91166024F; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\GraphBVUtils\CGraphBV_FileIO.cpp

//## begin module%3BA91166024F.additionalIncludes preserve=no
//## end module%3BA91166024F.additionalIncludes

//## begin module%3BA91166024F.includes preserve=yes
#include "File.h"
#include "memory/gammae_mem.h"
//## end module%3BA91166024F.includes

// CGraphBV_FileIO
#include "E3D\BoundingVolume\GraphBoundVol\GraphBVUtils\CGraphBV_FileIO.h"
//## begin module%3BA91166024F.additionalDeclarations preserve=yes
//## end module%3BA91166024F.additionalDeclarations


// Class CGraphBV_FileIO 

CGraphBV_FileIO::CGraphBV_FileIO()
  //## begin CGraphBV_FileIO::CGraphBV_FileIO%.hasinit preserve=no
  //## end CGraphBV_FileIO::CGraphBV_FileIO%.hasinit
  //## begin CGraphBV_FileIO::CGraphBV_FileIO%.initialization preserve=yes
  //## end CGraphBV_FileIO::CGraphBV_FileIO%.initialization
{
  //## begin CGraphBV_FileIO::CGraphBV_FileIO%.body preserve=yes
  //## end CGraphBV_FileIO::CGraphBV_FileIO%.body
}


CGraphBV_FileIO::~CGraphBV_FileIO()
{
  //## begin CGraphBV_FileIO::~CGraphBV_FileIO%.body preserve=yes
  //## end CGraphBV_FileIO::~CGraphBV_FileIO%.body
}



//## Other Operations (implementation)
CGraphBV * CGraphBV_FileIO::pLoadGraphBV (CFile& _roFile)
{
  //## begin CGraphBV_FileIO::pLoadGraphBV%1000933012.body preserve=yes
	unsigned int uiObjID;
	unsigned int uiBlockLen;

	CGraphBV_Sphere		*pSph;
	CGraphBV_Box		*pBox;
	CGraphBV_Cylinder	*pCyl;	
	
	// Read object identifier
	_roFile.iRead(&uiObjID   ,sizeof(unsigned int));
	_roFile.iRead(&uiBlockLen,sizeof(unsigned int));

	switch (uiObjID)
	{
		case MAKE_RIFF_ID('B','S','P','H'):
					pSph = mNew CGraphBV_Sphere;
					_roFile.iRead(&pSph->pGetSphere()->Center,sizeof(CVect3));
					_roFile.iRead(&pSph->pGetSphere()->Radius,sizeof(float ));
					
					return (pSph);
					break;

		case MAKE_RIFF_ID('B','B','O','X'):
					pBox = mNew CGraphBV_Box;

					_roFile.iRead(&pBox->pGetBox()->Maxs  ,  sizeof(CVect3));
					_roFile.iRead(&pBox->pGetBox()->Mins  ,  sizeof(CVect3));
					_roFile.iRead(&pBox->pGetBox()->Points,8*sizeof(CVect3));
					
					pBox->Compute(pBox->Vol.Points,8);
					return (pBox);
					break;

		case MAKE_RIFF_ID('B','C','Y','L'):		
					pCyl = mNew CGraphBV_Cylinder;
					_roFile.iRead(&pCyl->pGetCylinder()->Center,sizeof(CVect3));
					_roFile.iRead(&pCyl->pGetCylinder()->Height,sizeof(float ));
					_roFile.iRead(&pCyl->pGetCylinder()->Radius,sizeof(float ));
					return (pCyl);
					break;
	}

	return (NULL);

  //## end CGraphBV_FileIO::pLoadGraphBV%1000933012.body
}

int CGraphBV_FileIO::iSaveGraphBV (CFile& _roFile, CGraphBV *_pGBV)
{
  //## begin CGraphBV_FileIO::iSaveGraphBV%1000933013.body preserve=yes
	CGraphBV_Sphere		*pSph = (CGraphBV_Sphere   *)_pGBV;
	CGraphBV_Box		*pBox = (CGraphBV_Box      *)_pGBV;
	CGraphBV_Cylinder	*pCyl = (CGraphBV_Cylinder *)_pGBV;

	switch (_pGBV->eGetTypeID())
	{
		case eGraphBV_Sphere:  	CFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','S','P','H'),_roFile);
									_roFile.iWrite(&pSph->pGetSphere()->Center,sizeof(CVect3));
									_roFile.iWrite(&pSph->pGetSphere()->Radius,sizeof(float ));
								CFileUtils::EndRIFFBlock(_roFile);
								break;

		case eGraphBV_Box:		CFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','B','O','X'),_roFile);
									_roFile.iWrite(&pBox->pGetBox()->Maxs  ,  sizeof(CVect3));
									_roFile.iWrite(&pBox->pGetBox()->Mins  ,  sizeof(CVect3));
									_roFile.iWrite(&pBox->pGetBox()->Points,8*sizeof(CVect3));
								CFileUtils::EndRIFFBlock(_roFile);
								break;
		case eGraphBV_Cylinder:	CFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','C','Y','L'),_roFile);
									_roFile.iWrite(&pCyl->pGetCylinder()->Center,sizeof(CVect3));
									_roFile.iWrite(&pCyl->pGetCylinder()->Height,sizeof(float ));
									_roFile.iWrite(&pCyl->pGetCylinder()->Radius,sizeof(float ));
								CFileUtils::EndRIFFBlock(_roFile);
								break;
	}

	return (RES_OP_OK);
  //## end CGraphBV_FileIO::iSaveGraphBV%1000933013.body
}

// Additional Declarations
  //## begin CGraphBV_FileIO%3BA91166024F.declarations preserve=yes
  //## end CGraphBV_FileIO%3BA91166024F.declarations

//## begin module%3BA91166024F.epilog preserve=yes
//## end module%3BA91166024F.epilog
