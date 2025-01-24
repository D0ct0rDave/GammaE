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
#ifndef CGFileSysMgrMultiPAKH
#define CGFileSysMgrMultiPAKH
// ----------------------------------------------------------------------------
#include "FileManager\CGFileSysManager.h"
// CGFileSysMgrPAK
#include "FileManager\CGFileSysMgrPAK.h"
// ----------------------------------------------------------------------------
class CGFileSysMgrMultiPAK : public CGFileSysManager
{
    public:
        CGFileSysMgrMultiPAK();

        ~CGFileSysMgrMultiPAK();

        virtual handler hOpenFile(const CGString& _sFilename, EFileOpenMode _eOpenMode);

        virtual void CloseFile(handler _iHandler);

        virtual uint uiReadFile(handler _iHandler, pointer _pData, uint _uiSize);

        virtual uint uiWriteFile(handler _iHandler, pointer _pData, uint _uiSize);

        virtual int iSeekFile(handler _iHandler, int _iOffset, EFileSeekMode _eMode);

        virtual uint uiLengthFile(handler _iHandler);

        virtual uint uiPosFile(handler _iHandler);

        CGFileSysMgrPAK* poGetPAK();
        void SetpoPAK(CGFileSysMgrPAK* _poPAK);

        // Data Members for Associations

        CGFileSysMgrPAK* m_poPAK;

    protected:

    private:

    private:
};

inline CGFileSysMgrPAK* CGFileSysMgrMultiPAK::poGetPAK ()
{
    return(m_poPAK);
}

inline void CGFileSysMgrMultiPAK::SetpoPAK (CGFileSysMgrPAK* _poPAK )
{
    m_poPAK = _poPAK;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
