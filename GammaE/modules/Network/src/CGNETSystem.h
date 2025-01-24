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
#ifndef CGNETSystemH
#define CGNETSystemH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
#define MAXC_SNAME      256
#define MAX_CONNECTIONS 128
#define MAX_PACKET_SIZE (65536 - 8)
// ----------------------------------------------------------------------------
class CGNETSystem
{
    public:  CGNETSystem()
        {
        }
        ~CGNETSystem()
        {
        }

        static void Init();
        static void Finish();

        // ----------------------------------------------------------------------------
        static int CreateServer(uint&_uiServerIP,char* _szServerName,uint _uiPort);
        static int WriteToClient(int _iClSocket,void* _pBuff,int _iSize);
        static int ReadFromClient(int _iClSocket,void* _pBuff,int _iSize);
        static int AcceptConnections(int _iServerSocket);
        static bool bPendingInfo(int _iClSocket);

        // ----------------------------------------------------------------------------
        static int ConnectToServer(char* _szServerName,uint _uiPort);
        static int ConnectToServer(uint _uiServerIP,uint _uiPort);
        static void Disconnect();
        static int WriteToServer(void* _pBuff,int _iSize);
        static int ReadFromServer(void* _pBuff,int _iSize);

        // ----------------------------------------------------------------------------
        static void GetHostName(char* _szHostName);
        static uint uiGetHostByName(char* _szHostName);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
