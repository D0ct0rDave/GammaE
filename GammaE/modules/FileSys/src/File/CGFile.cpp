// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "FileManager/CGFileMgr.h"
#include "CGFile.h"
// ----------------------------------------------------------------------------
bool CGFile::bOpen (const CGString& _sFilename, EFileOpenMode _eOpenMode)
{
    assert(gpoFILESYSMGR);
    m_hHandler = gpoFILESYSMGR->hOpenFile(_sFilename,_eOpenMode);
    return( (m_hHandler != NULL)?true:false );
}
// ----------------------------------------------------------------------------
void CGFile::Close ()
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->CloseFile(m_hHandler);
}
// ----------------------------------------------------------------------------
uint CGFile::uiRead (pointer _pData, uint _uiSize) const
{
    assert(gpoFILESYSMGR);
    return( gpoFILESYSMGR->uiReadFile(m_hHandler,_pData,_uiSize) );
}
// ----------------------------------------------------------------------------
uint CGFile::uiWrite (pointer _pData, uint _uiSize) const
{
    assert(gpoFILESYSMGR);
    return( gpoFILESYSMGR->uiWriteFile(m_hHandler,_pData,_uiSize) );
}
// ----------------------------------------------------------------------------
float CGFile::fRead () const
{
    assert(gpoFILESYSMGR);
    float fValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & fValue,4);
    return(fValue);
}
// ----------------------------------------------------------------------------
void CGFile::Write (float _fValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _fValue,4);
}
// ----------------------------------------------------------------------------
void CGFile::Write (int _iValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _iValue,4);
}
// ----------------------------------------------------------------------------
void CGFile::Write (uint _uiValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _uiValue,4);
}
// ----------------------------------------------------------------------------
int CGFile::iRead () const
{
    assert(gpoFILESYSMGR);
    int iValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & iValue,4);
    return(iValue);
}
// ----------------------------------------------------------------------------
uint CGFile::uiRead () const
{
    assert(gpoFILESYSMGR);
    uint uiValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & uiValue,4);
    return(uiValue);
}
// ----------------------------------------------------------------------------
void CGFile::Write (short _sValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _sValue,2);
}
// ----------------------------------------------------------------------------
void CGFile::Write (unsigned short _usValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _usValue,2);
}
// ----------------------------------------------------------------------------
short CGFile::sRead () const
{
    assert(gpoFILESYSMGR);
    short sValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & sValue,2);
    return(sValue);
}
// ----------------------------------------------------------------------------
unsigned short CGFile::usRead () const
{
    assert(gpoFILESYSMGR);
    unsigned short usValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & usValue,2);
    return(usValue);
}
// ----------------------------------------------------------------------------
void CGFile::Write (char _cValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _cValue,1);
}
// ----------------------------------------------------------------------------
void CGFile::Write (unsigned char _ucValue) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer) & _ucValue,1);
}
// ----------------------------------------------------------------------------
char CGFile::cRead () const
{
    assert(gpoFILESYSMGR);
    char cValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & cValue,1);
    return(cValue);
}
// ----------------------------------------------------------------------------
unsigned char CGFile::ucRead () const
{
    assert(gpoFILESYSMGR);
    unsigned char ucValue;
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer) & ucValue,1);
    return(ucValue);
}
// ----------------------------------------------------------------------------
void CGFile::ReadArray (int* _piBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer)_piBuff,4 * _uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::WriteArray (int* _piBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer)_piBuff,4 * _uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::ReadArray (short* _psBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer)_psBuff,2 * _uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::WriteArray (short* _psBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer)_psBuff,2 * _uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::ReadArray (char* _pcBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer)_pcBuff,_uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::WriteArray (char* _pcBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer)_pcBuff,_uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::ReadArray (float* _pfBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiReadFile(m_hHandler,(pointer)_pfBuff,4 * _uiNumElems);
}
// ----------------------------------------------------------------------------
void CGFile::WriteArray (float* _pfBuff, uint _uiNumElems) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->uiWriteFile(m_hHandler,(pointer)_pfBuff,4 * _uiNumElems);
}
// ----------------------------------------------------------------------------
int CGFile::iSeek (int _iOffset, EFileSeekMode _eSeekMode) const
{
    assert(gpoFILESYSMGR);
    return( gpoFILESYSMGR->iSeekFile(m_hHandler,_iOffset,_eSeekMode) );
}
// ----------------------------------------------------------------------------
uint CGFile::uiLength () const
{
    assert(gpoFILESYSMGR);
    return( gpoFILESYSMGR->uiLengthFile(m_hHandler) );
}
// ----------------------------------------------------------------------------
uint CGFile::uiPos () const
{
    assert(gpoFILESYSMGR);
    return( gpoFILESYSMGR->uiPosFile(m_hHandler) );
}
// ----------------------------------------------------------------------------
void CGFile::Skip(uint _uiBytes) const
{
    assert(gpoFILESYSMGR);
    gpoFILESYSMGR->iSeekFile(m_hHandler,_uiBytes,FSM_CUR);
}
// ----------------------------------------------------------------------------
void CGFile::WriteText(char* fmt,...) const
{
    const uint BUFFER_SIZE = 8192;
    char szLocalBuff[BUFFER_SIZE];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf_s(szLocalBuff,BUFFER_SIZE,fmt,argptr);
    va_end  (argptr);

    int iLen = strlen(szLocalBuff);
    WriteArray(szLocalBuff,iLen);
}
// ----------------------------------------------------------------------------
