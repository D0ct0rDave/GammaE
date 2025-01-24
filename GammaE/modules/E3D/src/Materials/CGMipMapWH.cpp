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
#include <string.h>
#include <stdio.h>
// ----------------------------------------------------------------------------
#include "CGMipMapWH.h"
#include <freeimage.h>
// ----------------------------------------------------------------------------
FIBITMAP* GenericLoaderINT(const char* lpszPathName, int flag)
{
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

    // check the file signature and deduce its format
    // (the second argument is currently not used by FreeImage)
    fif = FreeImage_GetFileType(lpszPathName, 0);
    if ( fif == FIF_UNKNOWN )
    {
        // no signature ?
        // try to guess the file format from the file extension
        fif = FreeImage_GetFIFFromFilename(lpszPathName);
    }

    // check that the plugin has reading capabilities ...
    if ( (fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif) )
    {
        // ok, let's load the file
        FIBITMAP* dib = FreeImage_Load(fif, lpszPathName, flag);
        // unless a bad file format, we are done !
        return(dib);
    }
    return(NULL);
}
// ----------------------------------------------------------------------------
FIBITMAP* GenericLoader(const char* lpszPathName, int flag)
{
    // Has the filename any extension?
    if ( strstr(lpszPathName,".") == NULL )
    {
        char* szDefaultExtensions[] = {"tga","jpg","png",NULL};

        uint uiExt = 0;
        while ( szDefaultExtensions[uiExt] != NULL )
        {
            // Filename has no extension, so try appending some standard extensions like TGA, JPG, PNG
            FIBITMAP* poBmp = NULL;
            char szStr[1024];

            sprintf(szStr,"%s.%s",lpszPathName,szDefaultExtensions[uiExt]);
            poBmp = GenericLoaderINT(szStr,flag);

            if ( poBmp != NULL )
                // Ok we've found it!
                return(poBmp);

            // Nop, try next extension
            uiExt++;
        }
    }
    else
        // Filename has extension so let's load normaly
        return( GenericLoaderINT(lpszPathName,flag) );

    return(NULL);
}
// ----------------------------------------------------------------------------
void FlipImage(FIBITMAP* dib)
{
    uint uiHeight = FreeImage_GetHeight(dib);
    uint uiHHeight = uiHeight >> 1;
    uint uiSize = FreeImage_GetPitch(dib);
    void* pLine = mAlloc(uiSize);

    for ( uint i = 0; i < uiHHeight; i++ )
    {
        void* pSLine = FreeImage_GetScanLine(dib,i);
        void* pDLine = FreeImage_GetScanLine(dib,uiHeight - i - 1);

        memcpy(pLine,pSLine,uiSize);
        memcpy(pSLine,pDLine,uiSize);
        memcpy(pDLine,pLine,uiSize);
    }

    mFree(pLine);
}
// ----------------------------------------------------------------------------
void SwapRBChannels(FIBITMAP* dib)
{
    uint uiBPP = FreeImage_GetBPP(dib);
    if ( (uiBPP != 24) && (uiBPP != 32) ) return;

    uint uiHeight = FreeImage_GetHeight(dib);
    uint uiHHeight = uiHeight >> 1;
    uint uiSize = FreeImage_GetPitch(dib);
    uint uiStep = uiBPP / 8;

    for ( uint i = 0; i < uiHeight; i++ )
    {
        void* pLine = FreeImage_GetScanLine(dib,i);

        for ( uint j = 0; j < uiSize; j += uiStep )
        {
            char* pPixel = (char*)pLine + j;
            char aux = pPixel[0];
            pPixel[0] = pPixel[2];
            pPixel[2] = aux;
        }
    }
}
// ----------------------------------------------------------------------------
CGMipMapWH::CGMipMapWH() : m_sAlternatePath("")
{
    FreeImage_Initialise();
}
// ----------------------------------------------------------------------------
// If mipmap texture not found, please implement the return of a null texture.
// ----------------------------------------------------------------------------
CGMipMap* CGMipMapWH::poLoadResource(const CGString& _sFilename)
{
    FIBITMAP* dib = GenericLoader( (char*)_sFilename.szString(), 0 );

    // Try with alternate path
    if ( dib == NULL )
    {
        CGString sFilename = m_sAlternatePath + "/" + _sFilename;
        dib = GenericLoader(sFilename.szString(), 0);
    }

    // If not loaded return
    if ( dib == NULL ) return(NULL);

    FlipImage(dib);
    SwapRBChannels(dib);

    CGMipMap* poMMO = mNew CGMipMap;

    poMMO->m_poHandler = (void*)dib;
    poMMO->m_uiTX = FreeImage_GetWidth(dib);
    poMMO->m_uiTY = FreeImage_GetHeight(dib);
    poMMO->m_pLOD[0] = FreeImage_GetBits(dib);
    poMMO->m_uiNumLODs = 1;

    switch ( FreeImage_GetColorType(dib) )
    {
        case FIC_MINISWHITE:
        case FIC_MINISBLACK:
        case FIC_CMYK:
        break;

        case FIC_RGB:
        {
            BITMAPINFOHEADER* bih = FreeImage_GetInfoHeader(dib);

            if ( bih->biBitCount == 32 )
                poMMO->m_eFormat = IF_RGBA;
            else
                poMMO->m_eFormat = IF_RGB;

            /*
               uint uiSize = poMMO->m_uiTX*poMMO->m_uiTY;
               unsigned char*pSrc = (unsigned char*)poMMO->m_pLOD[0];
               unsigned char*pDst = (unsigned char*)mAlloc(uiSize * 4);
               poMMO->m_pLOD[0] = pDst;

               while (uiSize>0)
               {
                pDst[0] = pSrc[0];
                pDst[1] = pSrc[1];
                pDst[2] = pSrc[2];
                pDst[3] = 255;

                pSrc += 3;
                pDst += 4;
                uiSize --;
               }

               poMMO->m_eFormat = IF_RGBA;
             */
        }
        break;

        case FIC_RGBALPHA:
        poMMO->m_eFormat = IF_RGBA;
        break;

        case FIC_PALETTE:
        poMMO->m_eFormat = IF_PALETTE;
        poMMO->m_pPalette = FreeImage_GetPalette(dib);
        break;
    }

    return(poMMO);
}
// ----------------------------------------------------------------------------
