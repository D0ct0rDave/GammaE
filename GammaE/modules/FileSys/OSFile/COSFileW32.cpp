//## begin module%3C7E13120227.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E13120227.cm

//## begin module%3C7E13120227.cp preserve=no
//## end module%3C7E13120227.cp

//## Module: COSFileW32%3C7E13120227; Pseudo Package body
//## Source file: i:\Projects\GammaE\FileSys\OSFile\COSFileW32.cpp

//## begin module%3C7E13120227.additionalIncludes preserve=no
//## end module%3C7E13120227.additionalIncludes

//## begin module%3C7E13120227.includes preserve=yes
#include <stdio.h>
#include <string.h>
#include <assert.h>
//## end module%3C7E13120227.includes

// COSFileW32
#include "FileSys\OSFile\COSFileW32.h"
//## begin module%3C7E13120227.additionalDeclarations preserve=yes
//## end module%3C7E13120227.additionalDeclarations


// Class COSFileW32 



COSFileW32::COSFileW32()
  //## begin COSFileW32::COSFileW32%.hasinit preserve=no
  //## end COSFileW32::COSFileW32%.hasinit
  //## begin COSFileW32::COSFileW32%.initialization preserve=yes
  //## end COSFileW32::COSFileW32%.initialization
{
  //## begin COSFileW32::COSFileW32%.body preserve=yes
  //## end COSFileW32::COSFileW32%.body
}


COSFileW32::~COSFileW32()
{
  //## begin COSFileW32::~COSFileW32%.body preserve=yes
  //## end COSFileW32::~COSFileW32%.body
}



//## Other Operations (implementation)
int COSFileW32::iOpenOSF (char *_szFilename, char* _szMode)
{
  //## begin COSFileW32::iOpenOSF%1014892594.body preserve=yes
	fd = fopen(_szFilename,_szMode);
	strncpy(szFilename,_szFilename,256);	
	return(fd?1:0);
  //## end COSFileW32::iOpenOSF%1014892594.body
}

void COSFileW32::CloseOSF ()
{
  //## begin COSFileW32::CloseOSF%1014892595.body preserve=yes
	if (fd) fclose(fd);
	fd = NULL;
  //## end COSFileW32::CloseOSF%1014892595.body
}

int COSFileW32::iReadOSF (void* _pData, int _iSize)
{
  //## begin COSFileW32::iReadOSF%1014892596.body preserve=yes
	assert(_pData && "NULL Data buffer");
	if (_iSize <= 0) return(0);

	return(fread(_pData,_iSize,1,fd));	
  //## end COSFileW32::iReadOSF%1014892596.body
}

int COSFileW32::iWriteOSF (void* _pData, int _iSize)
{
  //## begin COSFileW32::iWriteOSF%1014892597.body preserve=yes
	assert(_pData && "NULL Data buffer");
	if (_iSize <= 0) return(0);

	return(fwrite(_pData,_iSize,1,fd));
  //## end COSFileW32::iWriteOSF%1014892597.body
}

int COSFileW32::iSeekOSF (int _iOffset, eOSF_SeekMode _eMode)
{
  //## begin COSFileW32::iSeekOSF%1014892598.body preserve=yes
	switch (_eMode)
	{
		case eOSF_SM_Set:	return(fseek(fd,_iOffset,SEEK_SET));
		case eOSF_SM_Cur:	return(fseek(fd,_iOffset,SEEK_CUR));
		case eOSF_SM_End:	return(fseek(fd,_iOffset,SEEK_END));
	}
	return(0);
  //## end COSFileW32::iSeekOSF%1014892598.body
}

int COSFileW32::iLengthOSF ()
{
  //## begin COSFileW32::iLengthOSF%1014892599.body preserve=yes
	int iCurPos,iLength;

	iCurPos = ftell(fd);
	fseek(fd, 0, SEEK_END);

	iLength = ftell(fd);
	fseek(fd, iCurPos, SEEK_SET);

	return (iLength);
  //## end COSFileW32::iLengthOSF%1014892599.body
}

int COSFileW32::iPosOSF ()
{
  //## begin COSFileW32::iPosOSF%1014912981.body preserve=yes
	return(ftell(fd));
  //## end COSFileW32::iPosOSF%1014912981.body
}

// Additional Declarations
  //## begin COSFileW32%3C7E13120227.declarations preserve=yes
  //## end COSFileW32%3C7E13120227.declarations

//## begin module%3C7E13120227.epilog preserve=yes
//## end module%3C7E13120227.epilog
