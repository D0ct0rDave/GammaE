//	  %X% %Q% %Z% %W%





// CFileSys_MgrPAK
#include "FileManager\CFileSys_MgrPAK.h"


// Class CFileSys_MgrPAK 



CFileSys_MgrPAK::CFileSys_MgrPAK()
        {
}


CFileSys_MgrPAK::~CFileSys_MgrPAK()
{
}



handler CFileSys_MgrPAK::iOpenFile (char *_szFilename, char* _szMode)
{
    return(0);
}

void CFileSys_MgrPAK::CloseFile (handler _iHandler)
{
}

int CFileSys_MgrPAK::iReadFile (handler _iHandler, void* _pData, int _iSize)
{
    return(0);
}

int CFileSys_MgrPAK::iWriteFile (handler _iHandler, void* _pData, int _iSize)
{
    return(0);
}

int CFileSys_MgrPAK::iSeekFile (handler _iHandler, int _iOffset, eFile_SeekMode _eMode)
{
    return(0);
}

int CFileSys_MgrPAK::iLengthFile (handler _iHandler)
{
  	return(0);
}

int CFileSys_MgrPAK::iPosFile (handler _iHandler)
{
    return(0);
}

// Additional Declarations
    
