



#include "GammaE_FileSys.h"
#include "GammaE_Mem.h"

// CGraphBV_FileIO
#include "BoundingVolume\GraphBoundVol\GraphBVUtils\CGraphBV_FileIO.h"


// Class CGraphBV_FileIO 

CGraphBV_FileIO::CGraphBV_FileIO()
        {
}


CGraphBV_FileIO::~CGraphBV_FileIO()
{
}



CGraphBV * CGraphBV_FileIO::pLoadGraphBV (CFile& _oFile)
{
  	unsigned int uiObjID;
	unsigned int uiBlockLen;

	CGraphBV_Sphere		*pSph;
	CGraphBV_Box		*pBox;
	CGraphBV_Cylinder	*pCyl;	
	
	// Read object identifier
	_oFile.iRead(&uiObjID   ,sizeof(unsigned int));
	_oFile.iRead(&uiBlockLen,sizeof(unsigned int));

	switch (uiObjID)
	{
		case MAKE_RIFF_ID('B','S','P','H'):
					pSph = mNew CGraphBV_Sphere;
					_oFile.iRead(&pSph->pGetSphere()->Center,sizeof(CVect3));
					_oFile.iRead(&pSph->pGetSphere()->Radius,sizeof(float ));
					
					return (pSph);
					break;

		case MAKE_RIFF_ID('B','B','O','X'):
					pBox = mNew CGraphBV_Box;

					_oFile.iRead(&pBox->pGetBox()->Maxs  ,  sizeof(CVect3));
					_oFile.iRead(&pBox->pGetBox()->Mins  ,  sizeof(CVect3));
					_oFile.iRead(&pBox->pGetBox()->Points,8*sizeof(CVect3));
					
					pBox->Compute(pBox->Vol.Points,8);
					return (pBox);
					break;

		case MAKE_RIFF_ID('B','C','Y','L'):		
					pCyl = mNew CGraphBV_Cylinder;
					_oFile.iRead(&pCyl->pGetCylinder()->Center,sizeof(CVect3));
					_oFile.iRead(&pCyl->pGetCylinder()->Height,sizeof(float ));
					_oFile.iRead(&pCyl->pGetCylinder()->Radius,sizeof(float ));
					return (pCyl);
					break;
	}

	return (NULL);

}

int CGraphBV_FileIO::iSaveGraphBV (CFile& _oFile, CGraphBV *_pGBV)
{
  	CGraphBV_Sphere		*pSph = (CGraphBV_Sphere   *)_pGBV;
	CGraphBV_Box		*pBox = (CGraphBV_Box      *)_pGBV;
	CGraphBV_Cylinder	*pCyl = (CGraphBV_Cylinder *)_pGBV;

	switch (_pGBV->eGetTypeID())
	{
		case eGraphBV_Sphere:  	CFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','S','P','H'),_oFile);
									_oFile.iWrite(&pSph->pGetSphere()->Center,sizeof(CVect3));
									_oFile.iWrite(&pSph->pGetSphere()->Radius,sizeof(float ));
								CFileUtils::EndRIFFBlock(_oFile);
								break;

		case eGraphBV_Box:		CFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','B','O','X'),_oFile);
									_oFile.iWrite(&pBox->pGetBox()->Maxs  ,  sizeof(CVect3));
									_oFile.iWrite(&pBox->pGetBox()->Mins  ,  sizeof(CVect3));
									_oFile.iWrite(&pBox->pGetBox()->Points,8*sizeof(CVect3));
								CFileUtils::EndRIFFBlock(_oFile);
								break;
		case eGraphBV_Cylinder:	CFileUtils::BeginRIFFBlock(MAKE_RIFF_ID('B','C','Y','L'),_oFile);
									_oFile.iWrite(&pCyl->pGetCylinder()->Center,sizeof(CVect3));
									_oFile.iWrite(&pCyl->pGetCylinder()->Height,sizeof(float ));
									_oFile.iWrite(&pCyl->pGetCylinder()->Radius,sizeof(float ));
								CFileUtils::EndRIFFBlock(_oFile);
								break;
	}

	return (RES_OP_OK);
}

// Additional Declarations
    
