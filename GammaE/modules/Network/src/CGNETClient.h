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
#ifndef CGNETClientH
#define CGNETClientH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
#define CLST_DISCONNECTED   0
#define CLST_CONNECTED      1
#define CLST_REGISTERED     2
// ----------------------------------------------------------------------------
class CGNETClient
{
    public:  CGNETClient();
        ~CGNETClient();

        bool bConnect(uint _uiServerIP,uint _uiServerPort);
        bool bConnect(char* _szServerName,uint _uiServerPort);

        bool bGetInfo(void* _pBuff,int &_iSize);
        bool bSendInfo(void* _pBuff,int _iSize);
        int iGetState();

    protected:
        uint m_uiState;
        uint m_uiClientSocket;
};

inline int CGNETClient::iGetState()
{
    return(m_uiState);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
