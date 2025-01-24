// ----------------------------------------------------------------------------
/*! \class CGFileUtils
 *  \brief Utility class to ease the creation of RIFF blocks on disk files.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGFileUtilsH
#define CGFileUtilsH
// ----------------------------------------------------------------------------
#include "File\CGFile.h"
// ----------------------------------------------------------------------------
#ifndef MAKE_RIFF_ID
    #define MAKE_RIFF_ID(a,b,c,d)  ( (a) | (b << 8) | (c << 16) | (d << 24) )
#endif
// ----------------------------------------------------------------------------
class CGFileUtils
{
    public:

        // / Starts the definition of a RIFF block on a file on disk.
        static void BeginRIFFBlock(uint _uiID, const CGFile& _oFile);

        // / Ends the definition of a RIFF block on a file on disk.
        static void EndRIFFBlock(const CGFile& _oFile);

    protected:

        static CGDynArray <uint> m_uiBlockLenPos;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
