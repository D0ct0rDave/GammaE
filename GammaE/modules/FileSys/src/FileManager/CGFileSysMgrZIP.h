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
#ifndef CGFileSysMgrZIPH
#define CGFileSysMgrZIPH
// ----------------------------------------------------------------------------
#include "OSFile/CGOSFile.h"
#include "FileManager\CGFileSysManager.h"
// ----------------------------------------------------------------------------
class CGFileSysMgrZIP : public CGFileSysManager
{
    public:
        CGFileSysMgrZIP();

        ~CGFileSysMgrZIP();

        virtual handler hOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode);

        virtual void CloseFile(handler _iHandler);

        virtual uint uiReadFile(handler _iHandler, pointer _pData, uint _uiSize);

        virtual uint uiWriteFile(handler _iHandler, pointer _pData, uint _uiSize);

        virtual int iSeekFile(handler _iHandler, int _iOffset, EFileSeekMode _eMode);

        virtual uint uiLengthFile(handler _iHandler);

        virtual uint uiPosFile(handler _iHandler);

    private:

        CGOSFile* poOSFile;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
