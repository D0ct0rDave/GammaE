//## begin module%3C7E0C780187.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E0C780187.cm

//## begin module%3C7E0C780187.cp preserve=no
//## end module%3C7E0C780187.cp

//## Module: CFileSys_Manager%3C7E0C780187; Pseudo Package body
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_Manager.cpp

//## begin module%3C7E0C780187.additionalIncludes preserve=no
//## end module%3C7E0C780187.additionalIncludes

//## begin module%3C7E0C780187.includes preserve=yes
#include <assert.h>
#include "Memory/GammaE_Mem.h"
#include "OSFile.h"
//## end module%3C7E0C780187.includes

// CFileSys_Manager
#include "FileSys\FileManager\CFileSys_Manager.h"
//## begin module%3C7E0C780187.additionalDeclarations preserve=yes
//## end module%3C7E0C780187.additionalDeclarations


// Class CFileSys_Manager 

CFileSys_Manager::CFileSys_Manager()
  //## begin CFileSys_Manager::CFileSys_Manager%.hasinit preserve=no
  //## end CFileSys_Manager::CFileSys_Manager%.hasinit
  //## begin CFileSys_Manager::CFileSys_Manager%.initialization preserve=yes
  //## end CFileSys_Manager::CFileSys_Manager%.initialization
{
  //## begin CFileSys_Manager::CFileSys_Manager%.body preserve=yes
  //## end CFileSys_Manager::CFileSys_Manager%.body
}


CFileSys_Manager::~CFileSys_Manager()
{
  //## begin CFileSys_Manager::~CFileSys_Manager%.body preserve=yes
  //## end CFileSys_Manager::~CFileSys_Manager%.body
}



//## Other Operations (implementation)
HANDLER CFileSys_Manager::iOpenFile (char *_szFilename, char* _szMode)
{
  //## begin CFileSys_Manager::iOpenFile%1014892600.body preserve=yes
	OSFILE *poOSFile = mNew OSFILE;	
	
	if (poOSFile->iOpenOSF(_szFilename,_szMode))
		return((int)poOSFile);
	else
		return(0);
  //## end CFileSys_Manager::iOpenFile%1014892600.body
}

void CFileSys_Manager::CloseFile (int _iHandler)
{
  //## begin CFileSys_Manager::CloseFile%1014892601.body preserve=yes
	assert(_iHandler);

	((OSFILE*)_iHandler)->CloseOSF();
	mDel ((OSFILE*)_iHandler);
  //## end CFileSys_Manager::CloseFile%1014892601.body
}

int CFileSys_Manager::iReadFile (int _iHandler, void* _pData, int _iSize)
{
  //## begin CFileSys_Manager::iReadFile%1014892602.body preserve=yes
	assert(_iHandler);
	assert(_pData);
	return ( ((OSFILE*)_iHandler)->iReadOSF(_pData,_iSize) );
  //## end CFileSys_Manager::iReadFile%1014892602.body
}

int CFileSys_Manager::iWriteFile (int _iHandler, void* _pData, int _iSize)
{
  //## begin CFileSys_Manager::iWriteFile%1014892603.body preserve=yes
	assert(_iHandler);
	assert(_pData);
	return ( ((OSFILE*)_iHandler)->iWriteOSF(_pData,_iSize) );
  //## end CFileSys_Manager::iWriteFile%1014892603.body
}

int CFileSys_Manager::iSeekFile (int _iHandler, int _iOffset, eFile_SeekMode _eMode)
{
  //## begin CFileSys_Manager::iSeekFile%1014892604.body preserve=yes
	assert(_iHandler);
	switch (_eMode)
	{
		case eFile_SM_Set:	return ( ((OSFILE*)_iHandler)->iSeekOSF(_iOffset,eOSF_SM_Set) );
		case eFile_SM_Cur:	return ( ((OSFILE*)_iHandler)->iSeekOSF(_iOffset,eOSF_SM_Cur) );
		case eFile_SM_End:	return ( ((OSFILE*)_iHandler)->iSeekOSF(_iOffset,eOSF_SM_End) );
	}
	return(0);
  //## end CFileSys_Manager::iSeekFile%1014892604.body
}

int CFileSys_Manager::iLengthFile (int _iHandler)
{
  //## begin CFileSys_Manager::iLengthFile%1014892605.body preserve=yes
	assert(_iHandler);
	return ( ((OSFILE*)_iHandler)->iLengthOSF() );
  //## end CFileSys_Manager::iLengthFile%1014892605.body
}

int CFileSys_Manager::iPosFile (int _iHandler)
{
  //## begin CFileSys_Manager::iPosFile%1014912979.body preserve=yes
	assert(_iHandler);
	return ( ((OSFILE*)_iHandler)->iPosOSF() );
  //## end CFileSys_Manager::iPosFile%1014912979.body
}

// Additional Declarations
  //## begin CFileSys_Manager%3C7E0C780187.declarations preserve=yes
  //## end CFileSys_Manager%3C7E0C780187.declarations

//## begin module%3C7E0C780187.epilog preserve=yes
//## end module%3C7E0C780187.epilog
