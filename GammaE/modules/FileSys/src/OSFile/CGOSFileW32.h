// ----------------------------------------------------------------------------
/*! \class CGOSFileW32
 *  \brief WIN32 Platform dependent file class.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGOSFileW32H
#define CGOSFileW32H
// ----------------------------------------------------------------------------
#include <stdio.h>
#include "OSFile\CGOSFile.h"
// ----------------------------------------------------------------------------
class CGOSFileW32 : public CGOSFile
{
    public:
        CGOSFileW32();
        ~CGOSFileW32();

        // / Opens a OS dependant file in the given mode
        virtual bool bOpen(const CGString& _sFilename, EFileOpenMode _eOpenMode);

        // / Closes OS dependant file.
        virtual void Close();

        // / Reads a stream of data from the OS dependant file.
        virtual uint uiReadData(pointer _pData, uint _uiSize) const;

        // / Writes a stream of data to the OS dependant file.
        virtual uint uiWriteData(pointer _pData, uint _uiSize) const;

        // / Places the OS dependant file into the given position.
        virtual int iSeek(int _iOffset, EFileSeekMode _eSeekMode) const;

        // / Retrieves the OS dependant file current position.
        virtual uint uiPos() const;

        // / Returns the OS dependant file length.
        virtual uint uiLength() const;

    private:

        FILE* m_poFD;
        CGString m_sFilename;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
