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
#include "FileManager\CGFileSysMgrPAK.h"
// ----------------------------------------------------------------------------
CGFileSysMgrPAK::CGFileSysMgrPAK()
{
}

CGFileSysMgrPAK::~CGFileSysMgrPAK()
{
}

handler CGFileSysMgrPAK::hOpenFile (const CGString& _sFilename, EFileOpenMode _eOpenMode)
{
    return(0);
}

void CGFileSysMgrPAK::CloseFile (handler _iHandler)
{
}

uint CGFileSysMgrPAK::uiReadFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

uint CGFileSysMgrPAK::uiWriteFile (handler _iHandler, pointer _pData, uint _uiSize)
{
    return(0);
}

int CGFileSysMgrPAK::iSeekFile (handler _iHandler, int _iOffset, EFileSeekMode _eMode)
{
    return(0);
}

uint CGFileSysMgrPAK::uiLengthFile (handler _iHandler)
{
    return(0);
}

uint CGFileSysMgrPAK::uiPosFile (handler _iHandler)
{
    return(0);
}
// ----------------------------------------------------------------------------
