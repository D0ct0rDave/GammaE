// ----------------------------------------------------------------------------
/*! \class CGFileSysMgrDirect
 *  \brief File System Manager Class. Retrieves files directly from native directory structure.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <assert.h>
#include "GammaE_Mem.h"
#include "OSFile/OSFile.h"

#include "CGFileSysMgrDirect.h"
// ----------------------------------------------------------------------------
handler CGFileSysMgrDirect::hOpenFile (const CGString& _sFilename, EFileOpenMode _eOpenMode) const
{
    OSFILE* poOSFile = mNew OSFILE;

    if ( poOSFile->bOpen(_sFilename,_eOpenMode) )
        return( (handler)poOSFile );
    else
    {
        mDel poOSFile;
        return(0);
    }
}
// ----------------------------------------------------------------------------
void CGFileSysMgrDirect::CloseFile (handler _hHandler) const
{
    assert(_hHandler);

    ( (OSFILE*)_hHandler )->Close();
    mDel ( (OSFILE*)_hHandler );
}
// ----------------------------------------------------------------------------
uint CGFileSysMgrDirect::uiReadFile (handler _hHandler, pointer _pData, uint _uiSize) const
{
    assert(_hHandler);
    assert(_pData);
    return ( ( (OSFILE*)_hHandler )->uiRead(_pData,_uiSize) );
}
// ----------------------------------------------------------------------------
uint CGFileSysMgrDirect::uiWriteFile (handler _hHandler, pointer _pData, uint _uiSize) const
{
    assert(_hHandler);
    assert(_pData);
    return ( ( (OSFILE*)_hHandler )->uiWrite(_pData,_uiSize) );
}
// ----------------------------------------------------------------------------
int CGFileSysMgrDirect::iSeekFile (handler _hHandler, int _iOffset,EFileSeekMode _eSeekMode) const
{
    assert(_hHandler);
    return ( ( (OSFILE*)_hHandler )->iSeek(_iOffset,_eSeekMode) );
}
// ----------------------------------------------------------------------------
uint CGFileSysMgrDirect::uiLengthFile (handler _hHandler) const
{
    assert(_hHandler);
    return ( ( (OSFILE*)_hHandler )->uiLength() );
}
// ----------------------------------------------------------------------------
uint CGFileSysMgrDirect::uiPosFile (handler _hHandler) const
{
    assert(_hHandler);
    return ( ( (OSFILE*)_hHandler )->uiPos() );
}
// ----------------------------------------------------------------------------
