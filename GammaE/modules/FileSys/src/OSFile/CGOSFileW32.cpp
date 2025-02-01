// ----------------------------------------------------------------------------
/*! \class CGOSFileW32
 *  \brief WIN32 Platform dependent file class.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
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

// CGOSFileW32
#include "OSFile\CGOSFileW32.h"

// ----------------------------------------------------------------------------
CGOSFileW32::CGOSFileW32() :
    m_poFD(NULL)
{
}
// ----------------------------------------------------------------------------
CGOSFileW32::~CGOSFileW32()
{
}
// ----------------------------------------------------------------------------
bool CGOSFileW32::bOpen(const CGString& _sFilename, EFileOpenMode _eOpenMode)
{
    fopen_s(&m_poFD,_sFilename.szString(),(_eOpenMode == FOM_READ)?"rb":"wb");
    m_sFilename = _sFilename;

    #ifdef _DEBUG
    // strncpy(oFileList.FN[oFileList.iNumFiles++],_szFilename,256);
    #endif

    return(m_poFD != NULL);
}
// ----------------------------------------------------------------------------
void CGOSFileW32::Close()
{
    if ( m_poFD ) fclose(m_poFD);
    m_poFD = NULL;
}
// ----------------------------------------------------------------------------
uint CGOSFileW32::uiReadData(pointer _pData, uint _uiSize) const
{
    assert(_pData && "NULL Data buffer");
    if ( _uiSize <= 0 ) return(0);

    return( fread(_pData,_uiSize,1,m_poFD) );
}
// ----------------------------------------------------------------------------
uint CGOSFileW32::uiWriteData(pointer _pData, uint _uiSize) const
{
    assert(_pData && "NULL Data buffer");
    if ( _uiSize <= 0 ) return(0);

    return( fwrite(_pData,_uiSize,1,m_poFD) );
}
// ----------------------------------------------------------------------------
int CGOSFileW32::iSeek(int _iOffset, EFileSeekMode _eMode) const
{
    switch ( _eMode )
    {
        case FSM_SET:   return( fseek(m_poFD,_iOffset,SEEK_SET) );

        case FSM_CUR:   return( fseek(m_poFD,_iOffset,SEEK_CUR) );

        case FSM_END:   return( fseek(m_poFD,_iOffset,SEEK_END) );
    }

    return(0);
}
// ----------------------------------------------------------------------------
uint CGOSFileW32::uiLength() const
{
    int iCurPos,iLength;

    iCurPos = ftell(m_poFD);
    fseek(m_poFD, 0, SEEK_END);

    iLength = ftell(m_poFD);
    fseek(m_poFD, iCurPos, SEEK_SET);

    return (iLength);
}
// ----------------------------------------------------------------------------
uint CGOSFileW32::uiPos() const
{
    return( ftell(m_poFD) );
}
// ----------------------------------------------------------------------------
