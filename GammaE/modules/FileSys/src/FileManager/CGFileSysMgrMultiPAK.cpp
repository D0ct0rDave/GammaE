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
#include "FileManager\CGFileSysMgrMultiPAK.h"
// ----------------------------------------------------------------------------
CGFileSysMgrMultiPAK::CGFileSysMgrMultiPAK()
{
}

CGFileSysMgrMultiPAK::~CGFileSysMgrMultiPAK()
{
}

handler CGFileSysMgrMultiPAK::hOpenFile (const CGString& _sFilename, EFileOpenMode _eOpenMode)
{
    return(0);
}

void CGFileSysMgrMultiPAK::CloseFile (handler _iHandler)
{
}

uint CGFileSysMgrMultiPAK::uiReadFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

uint CGFileSysMgrMultiPAK::uiWriteFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

int CGFileSysMgrMultiPAK::iSeekFile (handler _iHandler, int _iOffset, EFileSeekMode _eMode)
{
    return(0);
}

uint CGFileSysMgrMultiPAK::uiLengthFile (handler _iHandler)
{
    return(0);
}

uint CGFileSysMgrMultiPAK::uiPosFile (handler _iHandler)
{
    return(0);
}
// ----------------------------------------------------------------------------
