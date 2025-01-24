//	  %X% %Q% %Z% %W%





// CFileSys_MgrZIP
#include "FileManager\CFileSys_MgrZIP.h"


// Class CFileSys_MgrZIP 



CFileSys_MgrZIP::CFileSys_MgrZIP()
        {
}


CFileSys_MgrZIP::~CFileSys_MgrZIP()
{
}



handler CFileSys_MgrZIP::iOpenFile (char *_szFilename, char* _szMode)
{
    return(0);
}

void CFileSys_MgrZIP::CloseFile (handler _iHandler)
{
}

int CFileSys_MgrZIP::iReadFile (handler _iHandler, void* _pData, int _iSize)
{
    return(0);
}

int CFileSys_MgrZIP::iWriteFile (handler _iHandler, void* _pData, int _iSize)
{
    return(0);
}

int CFileSys_MgrZIP::iSeekFile (handler _iHandler, int _iOffset, eFile_SeekMode _eMode)
{
    return(0);
}

int CFileSys_MgrZIP::iLengthFile (handler _iHandler)
{
    return(0);
}

int CFileSys_MgrZIP::iPosFile (handler _iHandler)
{
    return(0);
}

// Additional Declarations
    
