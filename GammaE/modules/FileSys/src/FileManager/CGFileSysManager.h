// ----------------------------------------------------------------------------
/*! \class CGFileSysManager
 *  \brief File System Manager base class. Represents a file system where to read/write files.
 *  every file system manager type should derive from this class.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGFileSysManagerH
#define CGFileSysManagerH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GFileSysEnums.h"
// ----------------------------------------------------------------------------
class CGFileSysManager
{
    public:

        // / Opens a file and retrieves its handler.
        virtual handler hOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode) const = 0;

        // / Closes a file represented by its handler.
        virtual void CloseFile(handler _hHandler) const = 0;

        // / Read a stream of bytes from a file.
        virtual uint uiReadFile(handler _hHandler, pointer _pData, uint _uiSize) const = 0;

        // / Writes a stream of bytes to a file.
        virtual uint uiWriteFile(handler _hHandler, pointer _pData, uint _uiSize) const = 0;

        // / Sets the file position to a given place.
        virtual int iSeekFile(handler _hHandler, int _iOffset, EFileSeekMode _eSeekMode) const = 0;

        // / Retrieves the current position of a given file.
        virtual uint uiPosFile(handler _hHandler) const = 0;

        // / Retrieves the length of a given file.
        virtual uint uiLengthFile(handler _hHandler) const = 0;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
