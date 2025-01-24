//	  %X% %Q% %Z% %W%

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "FILEMgr.h"

// CFile
#include "File\CFile.h"


// Class CFile 
CFile::CFile()
{

}

CFile::~CFile()
{
}

bool CFile::bOpen (const char *_szFilename, char* _szMode)
{
  	assert(gpoFILESYSMGR);
	iHandler = gpoFILESYSMGR->iOpenFile((char*)_szFilename,_szMode);
	return( iHandler?true:false );
}

void CFile::Close ()
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->CloseFile(iHandler);
}

int CFile::iRead (void* _pData, int _iSize)
{
  	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iReadFile(iHandler,_pData,_iSize));
}

int CFile::iWrite (void* _pData, int _iSize)
{
  	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iWriteFile(iHandler,_pData,_iSize));
}

float CFile::fRead ()
{
  	assert(gpoFILESYSMGR);
	float fValue;
	gpoFILESYSMGR->iReadFile(iHandler,&fValue,4);
	return(fValue);
}

void CFile::Write (float _fValue)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_fValue,4);
}

void CFile::Write (int _iValue)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_iValue,4);
}

int CFile::iRead ()
{
  	assert(gpoFILESYSMGR);
	int iValue;
	gpoFILESYSMGR->iReadFile(iHandler,&iValue,4);
	return(iValue);
}

void CFile::Write (short _sValue)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_sValue,2);
}

short CFile::sRead ()
{
    	assert(gpoFILESYSMGR);
	short sValue;
	gpoFILESYSMGR->iReadFile(iHandler,&sValue,2);
	return(sValue);
}

void CFile::Write (char _cValue)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_cValue,1);
}

char CFile::cRead ()
{
   	assert(gpoFILESYSMGR);
	char cValue;
	gpoFILESYSMGR->iReadFile(iHandler,&cValue,1);
	return(cValue);
}

void CFile::ReadIntArray (int *_piBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_piBuff,4*_iNumElems);
}

void CFile::WriteIntArray (int *_piBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_piBuff,4*_iNumElems);
}

void CFile::ReadShortArray (short *_psBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_psBuff,2*_iNumElems);
}

void CFile::WriteShortArray (short *_psBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_psBuff,2*_iNumElems);
}

void CFile::ReadCharArray (char *_pcBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_pcBuff,_iNumElems);
}

void CFile::WriteCharArray (char *_pcBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_pcBuff,_iNumElems);
}

void CFile::ReadFloatArray (float *_pfBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_pfBuff,4*_iNumElems);
}

void CFile::WriteFloatArray (float *_pfBuff, int _iNumElems)
{
  	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_pfBuff,4*_iNumElems);
}

uint CFile::uiSeek (int _iOffset, eFile_SeekMode _eMode)
{
  	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iSeekFile(iHandler,_iOffset,_eMode));
}

uint CFile::uiLength ()
{
  	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iLengthFile(iHandler));
}

uint CFile::uiPos ()
{
  	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iPosFile(iHandler));
}

// Additional Declarations
void CFile::Skip(unsigned int _uiBytes)
{
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iSeekFile(iHandler,_uiBytes,eFile_SM_Cur);
}
  
void CFile::WriteText(char*fmt,...)
{
	char szLocalBuff[8192];

	va_list argptr;
	va_start(argptr,fmt);
	vsprintf(szLocalBuff,fmt,argptr);
	va_end  (argptr);

	int iLen = strlen(szLocalBuff);
	WriteCharArray(szLocalBuff,iLen);
}
