//## begin module%3C7E144D00EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E144D00EA.cm

//## begin module%3C7E144D00EA.cp preserve=no
//## end module%3C7E144D00EA.cp

//## Module: CFileSys_MgrMultiPAK%3C7E144D00EA; Pseudo Package body
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_MgrMultiPAK.cpp

//## begin module%3C7E144D00EA.additionalIncludes preserve=no
//## end module%3C7E144D00EA.additionalIncludes

//## begin module%3C7E144D00EA.includes preserve=yes
//## end module%3C7E144D00EA.includes

// CFileSys_MgrMultiPAK
#include "FileSys\FileManager\CFileSys_MgrMultiPAK.h"
//## begin module%3C7E144D00EA.additionalDeclarations preserve=yes
//## end module%3C7E144D00EA.additionalDeclarations


// Class CFileSys_MgrMultiPAK 


CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK()
  //## begin CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK%.hasinit preserve=no
  //## end CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK%.hasinit
  //## begin CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK%.initialization preserve=yes
  //## end CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK%.initialization
{
  //## begin CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK%.body preserve=yes
  //## end CFileSys_MgrMultiPAK::CFileSys_MgrMultiPAK%.body
}


CFileSys_MgrMultiPAK::~CFileSys_MgrMultiPAK()
{
  //## begin CFileSys_MgrMultiPAK::~CFileSys_MgrMultiPAK%.body preserve=yes
  //## end CFileSys_MgrMultiPAK::~CFileSys_MgrMultiPAK%.body
}



//## Other Operations (implementation)
CFileSys_Manager::FileHandler CFileSys_MgrMultiPAK::iOpenFile (char *_szFilename, char* _szMode)
{
  //## begin CFileSys_MgrMultiPAK::iOpenFile%1014892630.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiPAK::iOpenFile%1014892630.body
}

void CFileSys_MgrMultiPAK::CloseFile (FileHandler _iHandler)
{
  //## begin CFileSys_MgrMultiPAK::CloseFile%1014892631.body preserve=yes
  //## end CFileSys_MgrMultiPAK::CloseFile%1014892631.body
}

int CFileSys_MgrMultiPAK::iReadFile (FileHandler _iHandler, void* _pData, int _iSize)
{
  //## begin CFileSys_MgrMultiPAK::iReadFile%1014892632.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiPAK::iReadFile%1014892632.body
}

int CFileSys_MgrMultiPAK::iWriteFile (FileHandler _iHandler, void* _pData, int _iSize)
{
  //## begin CFileSys_MgrMultiPAK::iWriteFile%1014892633.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiPAK::iWriteFile%1014892633.body
}

int CFileSys_MgrMultiPAK::iSeekFile (FileHandler _iHandler, int _iOffset, eFile_SeekMode _eMode)
{
  //## begin CFileSys_MgrMultiPAK::iSeekFile%1014892634.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiPAK::iSeekFile%1014892634.body
}

int CFileSys_MgrMultiPAK::iLengthFile (FileHandler _iHandler)
{
  //## begin CFileSys_MgrMultiPAK::iLengthFile%1014892635.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiPAK::iLengthFile%1014892635.body
}

int CFileSys_MgrMultiPAK::iPosFile (FileHandler _iHandler)
{
  //## begin CFileSys_MgrMultiPAK::iPosFile%1014912978.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiPAK::iPosFile%1014912978.body
}

// Additional Declarations
  //## begin CFileSys_MgrMultiPAK%3C7E144D00EA.declarations preserve=yes
  //## end CFileSys_MgrMultiPAK%3C7E144D00EA.declarations

//## begin module%3C7E144D00EA.epilog preserve=yes
//## end module%3C7E144D00EA.epilog
