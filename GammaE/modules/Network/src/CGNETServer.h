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
#ifndef CGNETServerH
#define CGNETServerH
// ----------------------------------------------------------------------------
#include "CGNETSystem.h"
// ----------------------------------------------------------------------------
typedef void (*TConnectionCallback)(int _iClientSocket);

class CGNETServer
{
    public:  CGNETServer()
        {
        }
        ~CGNETServer()
        {
        }

        static void Init(uint _uiServerPort);
        static void Loop();
        static bool bSendInfo(int _uiID,void* pBuff,uint _uiSize);
        static bool bGetInfo(int _uiID,void* pBuff,uint&_uiSize);
        static void SetConnectionCallback(TConnectionCallback _pCB);

    protected:

        static bool bNetInit;
        static char szServerName[MAXC_SNAME];
        static uint uiServerIP;
        static uint uiServerPort;
        static int iServerSocket;
        static TConnectionCallback pConnectionCallback;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
