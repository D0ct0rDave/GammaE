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
#include "CGMipMap.h"
#include <freeimage.h>
// ----------------------------------------------------------------------------
uint uiGetBPP(EImageFormat _eFormat)
{
    switch ( _eFormat )
    {
        case IF_RGBA: return(32);
        break;

        case IF_RGB: return(24);
        break;

        case IF_PALETTE: return(8);
        break;

        case IF_RGBA16: return(16);
        break;

        case IF_RGB16: return(16);
        break;
    }

    return(0);
}
// ----------------------------------------------------------------------------
CGMipMap::CGMipMap(uint _uiTX,uint _uiTY,uint _uiNumLODs,EImageFormat _eFormat)
{
    m_poHandler = (FIBITMAP*)FreeImage_Allocate( _uiTX,_uiTY,uiGetBPP(_eFormat) );
    if ( m_poHandler != NULL )
    {
        m_uiTX = _uiTX;
        m_uiTY = _uiTY;
        m_uiNumLODs = _uiNumLODs;
        m_eFormat = _eFormat;
        m_pLOD[0] = FreeImage_GetBits( (FIBITMAP*)m_poHandler );
        m_pPalette = NULL;
    }
}
// ----------------------------------------------------------------------------
CGMipMap::~CGMipMap()
{
    if ( m_poHandler != NULL )
    {
        FreeImage_Unload( (FIBITMAP*)m_poHandler );
        m_poHandler = NULL;
    }
}
// ----------------------------------------------------------------------------
