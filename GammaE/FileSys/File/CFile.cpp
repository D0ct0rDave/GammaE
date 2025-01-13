//## begin module%3C7E0C860264.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E0C860264.cm

//## begin module%3C7E0C860264.cp preserve=no
//## end module%3C7E0C860264.cp

//## Module: CFile%3C7E0C860264; Pseudo Package body
//## Source file: i:\Projects\GammaE\FileSys\File\CFile.cpp

//## begin module%3C7E0C860264.additionalIncludes preserve=no
//## end module%3C7E0C860264.additionalIncludes

//## begin module%3C7E0C860264.includes preserve=yes
#include <assert.h>
#include "FILEMgr.h"
//## end module%3C7E0C860264.includes

// CFile
#include "FileSys\File\CFile.h"
//## begin module%3C7E0C860264.additionalDeclarations preserve=yes
//## end module%3C7E0C860264.additionalDeclarations


// Class CFile 


CFile::CFile()
  //## begin CFile::CFile%.hasinit preserve=no
  //## end CFile::CFile%.hasinit
  //## begin CFile::CFile%.initialization preserve=yes
  //## end CFile::CFile%.initialization
{
  //## begin CFile::CFile%.body preserve=yes
  //## end CFile::CFile%.body
}


CFile::~CFile()
{
  //## begin CFile::~CFile%.body preserve=yes
  //## end CFile::~CFile%.body
}



//## Other Operations (implementation)
int CFile::iOpen (char *_szFilename, char* _szMode)
{
  //## begin CFile::iOpen%1014892612.body preserve=yes
	assert(gpoFILESYSMGR);
	iHandler = gpoFILESYSMGR->iOpenFile(_szFilename,_szMode);
	return( iHandler?1:0 );
  //## end CFile::iOpen%1014892612.body
}

void CFile::Close ()
{
  //## begin CFile::Close%1014892613.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->CloseFile(iHandler);
  //## end CFile::Close%1014892613.body
}

int CFile::iRead (void* _pData, int _iSize)
{
  //## begin CFile::iRead%1014892614.body preserve=yes
	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iReadFile(iHandler,_pData,_iSize));
  //## end CFile::iRead%1014892614.body
}

int CFile::iWrite (void* _pData, int _iSize)
{
  //## begin CFile::iWrite%1014892615.body preserve=yes
	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iWriteFile(iHandler,_pData,_iSize));
  //## end CFile::iWrite%1014892615.body
}

float CFile::fRead ()
{
  //## begin CFile::fRead%1017566936.body preserve=yes
	assert(gpoFILESYSMGR);
	float fValue;
	gpoFILESYSMGR->iReadFile(iHandler,&fValue,4);
	return(fValue);
  //## end CFile::fRead%1017566936.body
}

void CFile::Write (float _fValue)
{
  //## begin CFile::Write%1017566937.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_fValue,4);
  //## end CFile::Write%1017566937.body
}

void CFile::Write (int _iValue)
{
  //## begin CFile::Write%1017566924.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_iValue,4);
  //## end CFile::Write%1017566924.body
}

int CFile::iRead ()
{
  //## begin CFile::iRead%1017566925.body preserve=yes
	assert(gpoFILESYSMGR);
	int iValue;
	gpoFILESYSMGR->iReadFile(iHandler,&iValue,4);
	return(iValue);
  //## end CFile::iRead%1017566925.body
}

void CFile::Write (short _sValue)
{
  //## begin CFile::Write%1017566926.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_sValue,2);
  //## end CFile::Write%1017566926.body
}

short CFile::sRead ()
{
  //## begin CFile::sRead%1017566927.body preserve=yes
  	assert(gpoFILESYSMGR);
	short sValue;
	gpoFILESYSMGR->iReadFile(iHandler,&sValue,2);
	return(sValue);
  //## end CFile::sRead%1017566927.body
}

void CFile::Write (char _cValue)
{
  //## begin CFile::Write%1017566928.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,&_cValue,1);
  //## end CFile::Write%1017566928.body
}

char CFile::cRead ()
{
  //## begin CFile::cRead%1017566929.body preserve=yes
  	assert(gpoFILESYSMGR);
	char cValue;
	gpoFILESYSMGR->iReadFile(iHandler,&cValue,1);
	return(cValue);
  //## end CFile::cRead%1017566929.body
}

void CFile::ReadIntArray (int *_piBuff, int _iNumElems)
{
  //## begin CFile::ReadIntArray%1017566930.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_piBuff,4*_iNumElems);
  //## end CFile::ReadIntArray%1017566930.body
}

void CFile::WriteIntArray (int *_piBuff, int _iNumElems)
{
  //## begin CFile::WriteIntArray%1017566931.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_piBuff,4*_iNumElems);
  //## end CFile::WriteIntArray%1017566931.body
}

void CFile::ReadShortArray (short *_psBuff, int _iNumElems)
{
  //## begin CFile::ReadShortArray%1017566932.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_psBuff,2*_iNumElems);
  //## end CFile::ReadShortArray%1017566932.body
}

void CFile::WriteShortArray (short *_psBuff, int _iNumElems)
{
  //## begin CFile::WriteShortArray%1017566933.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_psBuff,2*_iNumElems);
  //## end CFile::WriteShortArray%1017566933.body
}

void CFile::ReadCharArray (char *_pcBuff, int _iNumElems)
{
  //## begin CFile::ReadCharArray%1017566934.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_pcBuff,_iNumElems);
  //## end CFile::ReadCharArray%1017566934.body
}

void CFile::WriteCharArray (char *_pcBuff, int _iNumElems)
{
  //## begin CFile::WriteCharArray%1017566935.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_pcBuff,_iNumElems);
  //## end CFile::WriteCharArray%1017566935.body
}

void CFile::ReadFloatArray (float *_pfBuff, int _iNumElems)
{
  //## begin CFile::ReadFloatArray%1017566938.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iReadFile(iHandler,_pfBuff,4*_iNumElems);
  //## end CFile::ReadFloatArray%1017566938.body
}

void CFile::WriteFloatArray (float *_pfBuff, int _iNumElems)
{
  //## begin CFile::WriteFloatArray%1017566939.body preserve=yes
	assert(gpoFILESYSMGR);
	gpoFILESYSMGR->iWriteFile(iHandler,_pfBuff,4*_iNumElems);
  //## end CFile::WriteFloatArray%1017566939.body
}

int CFile::iSeek (int _iOffset, eFile_SeekMode _eMode)
{
  //## begin CFile::iSeek%1014892616.body preserve=yes
	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iSeekFile(iHandler,_iOffset,_eMode));
  //## end CFile::iSeek%1014892616.body
}

int CFile::iLength ()
{
  //## begin CFile::iLength%1014892617.body preserve=yes
	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iLengthFile(iHandler));
  //## end CFile::iLength%1014892617.body
}

int CFile::iPos ()
{
  //## begin CFile::iPos%1014912983.body preserve=yes
	assert(gpoFILESYSMGR);
	return(gpoFILESYSMGR->iPosFile(iHandler));
  //## end CFile::iPos%1014912983.body
}

// Additional Declarations
  //## begin CFile%3C7E0C860264.declarations preserve=yes
  //## end CFile%3C7E0C860264.declarations

//## begin module%3C7E0C860264.epilog preserve=yes
//## end module%3C7E0C860264.epilog
