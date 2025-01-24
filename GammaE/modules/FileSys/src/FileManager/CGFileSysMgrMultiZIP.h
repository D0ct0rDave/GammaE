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
#ifndef CGFileSysMgrMultiZIPH
#define CGFileSysMgrMultiZIPH
// ----------------------------------------------------------------------------
#include "FileManager\CGFileSysMgrZIP.h"
// CGFileSysManager
#include "FileManager\CGFileSysManager.h"
// ----------------------------------------------------------------------------
class CGFileSysMgrMultiZIP : public CGFileSysManager
{
    public:
        CGFileSysMgrMultiZIP();

        ~CGFileSysMgrMultiZIP();

        virtual int iOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode);

        virtual void CloseFile(int _iHandler);

        virtual int iReadFile(int _iHandler, pointer _pData, int _uiSize);

        virtual int iWriteFile(int _iHandler, pointer _pData, int _uiSize);

        virtual int iSeekFile(int _iHandler, int _iOffset, eFile_SeekMode _eMode);

        virtual int iLengthFile(int _iHandler);

        virtual int iPosFile(int _iHandler);

        CGFileSysMgrZIP* GetpoZIP();
        void SetpoZIP(CGFileSysMgrZIP* value);

        // Data Members for Associations

        CGFileSysMgrZIP* poZIP;

    protected:

    private:

    private:
};

inline CGFileSysMgrZIP* CGFileSysMgrMultiZIP::GetpoZIP ()
{
    return(poZIP);
}

inline void CGFileSysMgrMultiZIP::SetpoZIP (CGFileSysMgrZIP* value)
{
    poZIP = value;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
