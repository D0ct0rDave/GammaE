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

        virtual handler hOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode);

        virtual void CloseFile(handler _iHandler);

        virtual uint uiReadFile(handler _iHandler, pointer _pData, uint _uiSize);

        virtual uint uiWriteFile(handler _iHandler, pointer _pData, uint _uiSize);

        virtual int iSeekFile(handler _iHandler, int _iOffset, EFileSeekMode _eMode);

        virtual uint uiLengthFile(handler _iHandler);

        virtual uint uiPosFile(handler _iHandler);

        CGFileSysMgrZIP* poGetZIP();
        void SetZIP(CGFileSysMgrZIP* _poZIP);

        // Data Members for Associations

        CGFileSysMgrZIP* m_poZIP;

    protected:

    private:

    private:
};

inline CGFileSysMgrZIP* CGFileSysMgrMultiZIP::poGetZIP ()
{
    return(m_poZIP);
}

inline void CGFileSysMgrMultiZIP::SetZIP (CGFileSysMgrZIP* _poZIP)
{
    m_poZIP = _poZIP;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
