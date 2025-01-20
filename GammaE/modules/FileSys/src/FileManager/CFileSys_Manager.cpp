//	  %X% %Q% %Z% %W%




#include <assert.h>
#include "GammaE_Mem.h"
#include "OSFile.h"

// CFileSys_Manager
#include "FileManager\CFileSys_Manager.h"


// Class CFileSys_Manager 

CFileSys_Manager::CFileSys_Manager()
        {
}


CFileSys_Manager::~CFileSys_Manager()
{
}



int CFileSys_Manager::iOpenFile (char *_szFilename, char* _szMode)
{
  	OSFILE *poOSFile = mNew OSFILE;	
	
	if (poOSFile->iOpenOSF(_szFilename,_szMode))
		return((int)poOSFile);
	else
	{
		mDel poOSFile;
		return(0);
	}
}

void CFileSys_Manager::CloseFile (int _iHandler)
{
  	assert(_iHandler);

	((OSFILE*)_iHandler)->CloseOSF();
	mDel ((OSFILE*)_iHandler);
}

int CFileSys_Manager::iReadFile (int _iHandler, void* _pData, int _iSize)
{
  	assert(_iHandler);
	assert(_pData);
	return ( ((OSFILE*)_iHandler)->iReadOSF(_pData,_iSize) );
}

int CFileSys_Manager::iWriteFile (int _iHandler, void* _pData, int _iSize)
{
  	assert(_iHandler);
	assert(_pData);
	return ( ((OSFILE*)_iHandler)->iWriteOSF(_pData,_iSize) );
}

int CFileSys_Manager::iSeekFile (int _iHandler, int _iOffset, eFile_SeekMode _eMode)
{
  	assert(_iHandler);
	switch (_eMode)
	{
		case eFile_SM_Set:	return ( ((OSFILE*)_iHandler)->iSeekOSF(_iOffset,eOSF_SM_Set) );
		case eFile_SM_Cur:	return ( ((OSFILE*)_iHandler)->iSeekOSF(_iOffset,eOSF_SM_Cur) );
		case eFile_SM_End:	return ( ((OSFILE*)_iHandler)->iSeekOSF(_iOffset,eOSF_SM_End) );
	}
	return(0);
}

int CFileSys_Manager::iLengthFile (int _iHandler)
{
  	assert(_iHandler);
	return ( ((OSFILE*)_iHandler)->iLengthOSF() );
}

int CFileSys_Manager::iPosFile (int _iHandler)
{
  	assert(_iHandler);
	return ( ((OSFILE*)_iHandler)->iPosOSF() );
}

// Additional Declarations
    
