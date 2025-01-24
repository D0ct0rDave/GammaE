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

        virtual int iOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode);

        virtual void CloseFile(int _iHandler);

        virtual int iReadFile(int _iHandler, pointer _pData, int _uiSize);

        virtual int iWriteFile(int _iHandler, pointer _pData, int _uiSize);

        virtual int iSeekFile(int _iHandler, int _iOffset, eFile_SeekMode _eMode);

        virtual int iLengthFile(int _iHandler);

        virtual int iPosFile(int _iHandler);

    private:

        CGOSFile* poOSFile;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
