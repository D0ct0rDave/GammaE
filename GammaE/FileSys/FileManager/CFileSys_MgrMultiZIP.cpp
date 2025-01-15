//## begin module%3C7E14E8006B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E14E8006B.cm

//## begin module%3C7E14E8006B.cp preserve=no
//## end module%3C7E14E8006B.cp

//## Module: CFileSys_MgrMultiZIP%3C7E14E8006B; Pseudo Package body
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_MgrMultiZIP.cpp

//## begin module%3C7E14E8006B.additionalIncludes preserve=no
//## end module%3C7E14E8006B.additionalIncludes

//## begin module%3C7E14E8006B.includes preserve=yes
//## end module%3C7E14E8006B.includes

// CFileSys_MgrMultiZIP
#include "FileSys\FileManager\CFileSys_MgrMultiZIP.h"
//## begin module%3C7E14E8006B.additionalDeclarations preserve=yes
//## end module%3C7E14E8006B.additionalDeclarations


// Class CFileSys_MgrMultiZIP 


CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP()
  //## begin CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP%.hasinit preserve=no
  //## end CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP%.hasinit
  //## begin CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP%.initialization preserve=yes
  //## end CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP%.initialization
{
  //## begin CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP%.body preserve=yes
  //## end CFileSys_MgrMultiZIP::CFileSys_MgrMultiZIP%.body
}


CFileSys_MgrMultiZIP::~CFileSys_MgrMultiZIP()
{
  //## begin CFileSys_MgrMultiZIP::~CFileSys_MgrMultiZIP%.body preserve=yes
  //## end CFileSys_MgrMultiZIP::~CFileSys_MgrMultiZIP%.body
}



//## Other Operations (implementation)
CFileSys_Manager::FileHandler CFileSys_MgrMultiZIP::iOpenFile (char *_szFilename, char* _szMode)
{
  //## begin CFileSys_MgrMultiZIP::iOpenFile%1014892618.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiZIP::iOpenFile%1014892618.body
}

void CFileSys_MgrMultiZIP::CloseFile (FileHandler _iHandler)
{
  //## begin CFileSys_MgrMultiZIP::CloseFile%1014892619.body preserve=yes
  //## end CFileSys_MgrMultiZIP::CloseFile%1014892619.body
}

int CFileSys_MgrMultiZIP::iReadFile (FileHandler _iHandler, void* _pData, int _iSize)
{
  //## begin CFileSys_MgrMultiZIP::iReadFile%1014892620.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiZIP::iReadFile%1014892620.body
}

int CFileSys_MgrMultiZIP::iWriteFile (FileHandler _iHandler, void* _pData, int _iSize)
{
  //## begin CFileSys_MgrMultiZIP::iWriteFile%1014892621.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiZIP::iWriteFile%1014892621.body
}

int CFileSys_MgrMultiZIP::iSeekFile (FileHandler _iHandler, int _iOffset, eFile_SeekMode _eMode)
{
  //## begin CFileSys_MgrMultiZIP::iSeekFile%1014892622.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiZIP::iSeekFile%1014892622.body
}

int CFileSys_MgrMultiZIP::iLengthFile (FileHandler _iHandler)
{
  //## begin CFileSys_MgrMultiZIP::iLengthFile%1014892623.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiZIP::iLengthFile%1014892623.body
}

int CFileSys_MgrMultiZIP::iPosFile (FileHandler _iHandler)
{
  //## begin CFileSys_MgrMultiZIP::iPosFile%1014912976.body preserve=yes
  return(0);
  //## end CFileSys_MgrMultiZIP::iPosFile%1014912976.body
}

// Additional Declarations
  //## begin CFileSys_MgrMultiZIP%3C7E14E8006B.declarations preserve=yes
  //## end CFileSys_MgrMultiZIP%3C7E14E8006B.declarations

//## begin module%3C7E14E8006B.epilog preserve=yes
//## end module%3C7E14E8006B.epilog
