//## begin module%3C7EA4E00311.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7EA4E00311.cm

//## begin module%3C7EA4E00311.cp preserve=no
//## end module%3C7EA4E00311.cp

//## Module: CFileUtils%3C7EA4E00311; Pseudo Package body
//## Source file: i:\Projects\GammaE\FileSys\FileUtils\CFileUtils.cpp

//## begin module%3C7EA4E00311.additionalIncludes preserve=no
//## end module%3C7EA4E00311.additionalIncludes

//## begin module%3C7EA4E00311.includes preserve=yes
//## end module%3C7EA4E00311.includes

// CFileUtils
#include "FileSys\FileUtils\CFileUtils.h"
//## begin module%3C7EA4E00311.additionalDeclarations preserve=yes
//## end module%3C7EA4E00311.additionalDeclarations


// Class CFileUtils 

//## begin CFileUtils::uiBlockLenPos%3C7EA63601AA.attr preserve=no  private: static unsigned int [256] {UA} 
unsigned int  CFileUtils::uiBlockLenPos[256];
//## end CFileUtils::uiBlockLenPos%3C7EA63601AA.attr

//## begin CFileUtils::uiBLIdx%3C7EA6EF03A5.attr preserve=no  private: static int {UA} -1
int CFileUtils::uiBLIdx = -1;
//## end CFileUtils::uiBLIdx%3C7EA6EF03A5.attr

CFileUtils::CFileUtils()
  //## begin CFileUtils::CFileUtils%.hasinit preserve=no
  //## end CFileUtils::CFileUtils%.hasinit
  //## begin CFileUtils::CFileUtils%.initialization preserve=yes
  //## end CFileUtils::CFileUtils%.initialization
{
  //## begin CFileUtils::CFileUtils%.body preserve=yes
  //## end CFileUtils::CFileUtils%.body
}


CFileUtils::~CFileUtils()
{
  //## begin CFileUtils::~CFileUtils%.body preserve=yes
  //## end CFileUtils::~CFileUtils%.body
}



//## Other Operations (implementation)
void CFileUtils::BeginRIFFBlock (unsigned int _uiID, CFile& _roFile)
{
  //## begin CFileUtils::BeginRIFFBlock%1014932975.body preserve=yes
  	if ( uiBLIdx == 255) return;	
	
	uiBLIdx++;
	
	// Write RIFF identifier
	_roFile.iWrite(&_uiID,4);
	
	uiBlockLenPos[uiBLIdx] = _roFile.iPos();

	// Write invalid RIFF BlockLenght
	_roFile.iWrite(&uiBlockLenPos[uiBLIdx],4);
  //## end CFileUtils::BeginRIFFBlock%1014932975.body
}

void CFileUtils::EndRIFFBlock (CFile& _roFile)
{
  //## begin CFileUtils::EndRIFFBlock%1014932976.body preserve=yes
  	unsigned int uiBlockLenght = _roFile.iPos() - (uiBlockLenPos[uiBLIdx]+4);
	
	// set file position pointing to RIFF BlockLenght
	_roFile.iSeek(uiBlockLenPos[uiBLIdx],eFile_SM_Set);

	// write BlockLenght
	_roFile.iWrite(&uiBlockLenght,4);
	
	// skip RIFF block data
	_roFile.iSeek(uiBlockLenght,eFile_SM_Cur);

	uiBLIdx--;
  //## end CFileUtils::EndRIFFBlock%1014932976.body
}

// Additional Declarations
  //## begin CFileUtils%3C7EA4E00311.declarations preserve=yes
  //## end CFileUtils%3C7EA4E00311.declarations

//## begin module%3C7EA4E00311.epilog preserve=yes
//## end module%3C7EA4E00311.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CFileUtils::RIFFID%1014932977.body preserve=no
		
		return( (_cA) | (_cB << 8) | (_cC <<16) | (_cD << 24) );

//## end CFileUtils::RIFFID%1014932977.body

#endif
