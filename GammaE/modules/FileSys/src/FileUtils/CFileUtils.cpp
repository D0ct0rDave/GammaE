//	  %X% %Q% %Z% %W%





// CFileUtils
#include "FileUtils\CFileUtils.h"


// Class CFileUtils 

unsigned int  CFileUtils::uiBlockLenPos[256];

int CFileUtils::uiBLIdx = -1;

CFileUtils::CFileUtils()
        {
}


CFileUtils::~CFileUtils()
{
}



void CFileUtils::BeginRIFFBlock (unsigned int _uiID, CFile& _oFile)
{
    	if ( uiBLIdx == 255) return;	
	
	uiBLIdx++;
	
	// Write RIFF identifier
	_oFile.iWrite(&_uiID,4);
	
	uiBlockLenPos[uiBLIdx] = _oFile.uiPos();

	// Write invalid RIFF BlockLenght
	_oFile.iWrite(&uiBlockLenPos[uiBLIdx],4);
}

void CFileUtils::EndRIFFBlock (CFile& _oFile)
{
    	unsigned int uiBlockLenght = _oFile.uiPos() - (uiBlockLenPos[uiBLIdx]+4);
	
	// set file position pointing to RIFF BlockLenght
	_oFile.uiSeek(uiBlockLenPos[uiBLIdx],eFile_SM_Set);

	// write BlockLenght
	_oFile.iWrite(&uiBlockLenght,4);
	
	// skip RIFF block data
	_oFile.uiSeek(uiBlockLenght,eFile_SM_Cur);

	uiBLIdx--;
}

// Additional Declarations
    


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
		
		return( (_cA) | (_cB << 8) | (_cC <<16) | (_cD << 24) );


#endif
