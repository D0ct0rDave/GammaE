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
#include "FileManager\CGFileSysMgrMultiZIP.h"

// ----------------------------------------------------------------------------
CGFileSysMgrMultiZIP::CGFileSysMgrMultiZIP()
{
}

CGFileSysMgrMultiZIP::~CGFileSysMgrMultiZIP()
{
}

handler CGFileSysMgrMultiZIP::hOpenFile (const CGString& _sFilename, EFileOpenMode _eOpenMode)
{
    return(0);
}

void CGFileSysMgrMultiZIP::CloseFile (handler _iHandler)
{
}

uint CGFileSysMgrMultiZIP::uiReadFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

uint CGFileSysMgrMultiZIP::uiWriteFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

int CGFileSysMgrMultiZIP::iSeekFile (handler _iHandler, int _iOffset, EFileSeekMode _eMode)
{
    return(0);
}

uint CGFileSysMgrMultiZIP::uiLengthFile (handler _iHandler)
{
    return(0);
}

uint CGFileSysMgrMultiZIP::uiPosFile (handler _iHandler)
{
    return(0);
}
// ----------------------------------------------------------------------------
