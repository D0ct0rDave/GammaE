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
#ifndef CGFileSysMgrDirectH
#define CGFileSysMgrDirectH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GFileSysEnums.h"
#include "CGFileSysManager.h"
// ----------------------------------------------------------------------------
class CGFileSysMgrDirect : public CGFileSysManager
{
    public:

        // / Opens a file and retrieves its handler.
        virtual handler hOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode) const;

        // / Closes a file represented by its handler.
        virtual void CloseFile(handler _hHandler) const;

        // / Read a stream of bytes from a file.
        virtual uint uiReadFile(handler _hHandler, pointer _pData, uint _uiSize) const;

        // / Writes a stream of bytes to a file.
        virtual uint uiWriteFile(handler _hHandler, pointer _pData, uint _uiSize) const;

        // / Sets the file position to a given place.
        virtual int iSeekFile(handler _hHandler, int _iOffset, EFileSeekMode _eSeekMode) const;

        // / Retrieves the current position of a given file.
        virtual uint uiPosFile(handler _hHandler) const;

        // / Retrieves the length of a given file.
        virtual uint uiLengthFile(handler _hHandler) const;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
