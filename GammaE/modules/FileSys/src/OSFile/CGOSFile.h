// ----------------------------------------------------------------------------
/*! \class CGOSFile
 *  \brief Platform dependent file class.
 *  All platforms should derive a file class from this one and implement the provided interface.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGOSFileH
#define CGOSFileH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GFileSysEnums.h"
// ----------------------------------------------------------------------------
class CGOSFile
{
    public:

        // / Opens a OS dependant file in the given mode
        virtual bool bOpen(const CGString& _sFilename, EFileOpenMode _eOpenMode) = 0;

        // / Closes OS dependant file.
        virtual void Close() = 0;

        // / Reads a stream of data from the OS dependant file.
        virtual uint uiRead(pointer _pData, uint _uiSize) const = 0;

        // / Writes a stream of data to the OS dependant file.
        virtual uint uiWrite(pointer _pData, uint _uiSize) const = 0;

        // / Places the OS dependant file into the given position.
        virtual int iSeek(int _iOffset, EFileSeekMode _eSeekMode) const = 0;

        // / Retrieves the OS dependant file current position.
        virtual uint uiPos() const = 0;

        // / Returns the OS dependant file length.
        virtual uint uiLength() const = 0;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
