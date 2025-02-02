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
#include "FileManager\CGFileSysMgrZIP.h"
// ----------------------------------------------------------------------------
CGFileSysMgrZIP::CGFileSysMgrZIP()
{
}

CGFileSysMgrZIP::~CGFileSysMgrZIP()
{
}

handler CGFileSysMgrZIP::hOpenFile (const CGString& _sFilename, EFileOpenMode _eOpenMode)
{
    return(0);
}

void CGFileSysMgrZIP::CloseFile (handler _iHandler)
{
}

uint CGFileSysMgrZIP::uiReadFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

uint CGFileSysMgrZIP::uiWriteFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

int CGFileSysMgrZIP::iSeekFile (handler _iHandler, int _iOffset, EFileSeekMode _eMode)
{
    return(0);
}

uint CGFileSysMgrZIP::uiLengthFile (handler _iHandler)
{
    return(0);
}

uint CGFileSysMgrZIP::uiPosFile (handler _iHandler)
{
    return(0);
}
// ----------------------------------------------------------------------------
