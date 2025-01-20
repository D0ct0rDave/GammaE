//	  %X% %Q% %Z% %W%




#include <stdio.h>
#include <string.h>
#include <assert.h>


/*
#ifdef _DEBUG
typedef struct{
	char FN[1024][256];
	int  iNumFiles;
}TFileList;

#ifdef __BORLANDC__
TFileList oFileList;
#else
extern TFileList oFileList;
#endif

#endif
*/

// COSFileW32
#include "OSFile\COSFileW32.h"


// Class COSFileW32 



COSFileW32::COSFileW32()
        {
}


COSFileW32::~COSFileW32()
{
}



int COSFileW32::iOpenOSF (char *_szFilename, char* _szMode)
{
  	fd = fopen(_szFilename,_szMode);
	strncpy(szFilename,_szFilename,256);

	#ifdef _DEBUG
	// strncpy(oFileList.FN[oFileList.iNumFiles++],_szFilename,256);
	#endif

	return(fd?1:0);
}

void COSFileW32::CloseOSF ()
{
  	if (fd) fclose(fd);
	fd = NULL;
}

int COSFileW32::iReadOSF (void* _pData, int _iSize)
{
  	assert(_pData && "NULL Data buffer");
	if (_iSize <= 0) return(0);

	return(fread(_pData,_iSize,1,fd));	
}

int COSFileW32::iWriteOSF (void* _pData, int _iSize)
{
  	assert(_pData && "NULL Data buffer");
	if (_iSize <= 0) return(0);

	return(fwrite(_pData,_iSize,1,fd));
}

int COSFileW32::iSeekOSF (int _iOffset, eOSF_SeekMode _eMode)
{
  	switch (_eMode)
	{
		case eOSF_SM_Set:	return(fseek(fd,_iOffset,SEEK_SET));
		case eOSF_SM_Cur:	return(fseek(fd,_iOffset,SEEK_CUR));
		case eOSF_SM_End:	return(fseek(fd,_iOffset,SEEK_END));
	}
	return(0);
}

int COSFileW32::iLengthOSF ()
{
  	int iCurPos,iLength;

	iCurPos = ftell(fd);
	fseek(fd, 0, SEEK_END);

	iLength = ftell(fd);
	fseek(fd, iCurPos, SEEK_SET);

	return (iLength);
}

int COSFileW32::iPosOSF ()
{
  	return(ftell(fd));
}

// Additional Declarations
    
