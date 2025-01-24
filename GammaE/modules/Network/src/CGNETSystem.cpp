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
#include <stdlib.h>
#include <stdio.h>

#ifdef WIN32
    #include <winsock2.h>
#endif

#include "CGNETSystem.h"
#include "CGNETTimeStampList.h"
// ----------------------------------------------------------------------------

#define CONID ( ('C' << 24) | ('O' << 16) | ('N' << 8) | ('N' << 0) )

// ----------------------------------------------------------------------------
#define SOCK_CONNTYPE SOCK_DGRAM
#define SOCK_PROTO    IPPROTO_UDP
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

typedef struct TNETPacket
{
    uint m_uiStamp;
    uint m_uiSize;
    char m_pucData[1];
}TNETPacket;

inline void Block(int _iSocket)
{
    unsigned long pars = 0;
    ioctlsocket(_iSocket,FIONBIO,&pars);
}

inline void Unblock(int _iSocket)
{
    unsigned long pars = 1;
    ioctlsocket(_iSocket,FIONBIO,&pars);
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#define MAX_TIME_STAMPS 10

typedef struct TClientData
{
    int iSocket;
    SOCKADDR_IN InAddr;
    bool bValid;
    uint uiTimeStamp;           // ----------------------------------------------------------------------------
    uint uiRcvTimeStamp;        // ----------------------------------------------------------------------------

    CGNETTimeStampList oTSL;             // ----------------------------------------------------------------------------
}TClientData;

TClientData goCD[MAX_CONNECTIONS + 1];
#define CLIENT_SOCKET MAX_CONNECTIONS
// ----------------------------------------------------------------------------
void InitClientData(TClientData* _poData,uint _uiPort,uint _uiAddress,int _iSocket)
{
    _poData->bValid = true;
    _poData->iSocket = _iSocket;
    _poData->uiTimeStamp = 0;

    _poData->InAddr.sin_family = AF_INET;
    _poData->InAddr.sin_port = htons(_uiPort);
    _poData->InAddr.sin_addr.s_addr = _uiAddress;
    for ( int j = 0; j < 8; j++ )
        _poData->InAddr.sin_zero[j] = 0;
}
// ----------------------------------------------------------------------------
int iInsertClient(SOCKADDR_IN* _pInAddr,int _iSocket)
{
    for ( int i = 0; i < MAX_CONNECTIONS; i++ )
    {
        if ( !goCD[i].bValid )
        {
            goCD[i].iSocket = _iSocket;
            goCD[i].bValid = true;
            goCD[i].InAddr = *_pInAddr;

            return(i);
        }
    }

    return(-1);
}
// ----------------------------------------------------------------------------
inline bool INTPendingInfo(uint _iSocket,SOCKADDR_IN* _pInAddr)
{
    int iRes;
    char cBuffer[MAX_PACKET_SIZE + 8];
    TNETPacket* poPacket = (TNETPacket*)cBuffer;
    int iAddrSize = sizeof(SOCKADDR);
    int iError = 0;

    iRes = recvfrom(
        _iSocket,                           // ----------------------------------------------------------------------------
        (char*)cBuffer,                     // ----------------------------------------------------------------------------
        MAX_PACKET_SIZE + 8,                  // ----------------------------------------------------------------------------
        MSG_PEEK,                           // ----------------------------------------------------------------------------
        (LPSOCKADDR)_pInAddr,               // ----------------------------------------------------------------------------
        &iAddrSize                          // ----------------------------------------------------------------------------
        );
    if ( iRes == SOCKET_ERROR )
    {
        iError = WSAGetLastError();
    }
    else
    {
        #ifdef _DEBUG
        unsigned char* IP = (unsigned char*)&_pInAddr->sin_addr;
        char szStr[1024];
        sprintf(szStr,"Pending Info from: %d.%d.%d.%d size: %d msg: %s\n",IP[0],IP[1],IP[2],IP[3],iRes,cBuffer);
        OutputDebugStr(szStr);
        #endif
    }

    return(iRes > 0);
}
// ----------------------------------------------------------------------------
inline bool INTPendingInfo(uint _iSocket,SOCKADDR_IN* _pInAddr,void* _pBuf,int _iSize)
{
    int iRes;
    char cBuffer[MAX_PACKET_SIZE + 8];
    TNETPacket* poPacket = (TNETPacket*)cBuffer;
    int iAddrSize = sizeof(SOCKADDR);

    iRes = recvfrom(
        _iSocket,                           // ----------------------------------------------------------------------------
        (char*)poPacket,                    // ----------------------------------------------------------------------------
        _iSize + 8,                           // ----------------------------------------------------------------------------
        MSG_PEEK,                           // ----------------------------------------------------------------------------
        (LPSOCKADDR)_pInAddr,               // ----------------------------------------------------------------------------
        &iAddrSize                          // ----------------------------------------------------------------------------
        );

    if ( iRes == SOCKET_ERROR )
    {
        int i = WSAGetLastError();
    }
    else
        memcpy(_pBuf,poPacket->m_pucData,poPacket->m_uiSize);

    return(iRes > 0);
}
// ----------------------------------------------------------------------------
inline int INTSend(TClientData* _pCD,void* _pBuf,int _iSize)
{
    char cBuffer[MAX_PACKET_SIZE];
    TNETPacket* poPacket = (TNETPacket*)cBuffer;

    poPacket->m_uiSize = _iSize;
    poPacket->m_uiStamp = _pCD->uiTimeStamp;
    memcpy(poPacket->m_pucData,_pBuf,_iSize);

    int iRes = sendto(
        _pCD->iSocket,                          // ----------------------------------------------------------------------------
        (char*)poPacket,                        // ----------------------------------------------------------------------------
        _iSize + 8,                               // ----------------------------------------------------------------------------
        0,                                      // ----------------------------------------------------------------------------
        (LPSOCKADDR)&_pCD->InAddr,              // ----------------------------------------------------------------------------
        sizeof(struct sockaddr)                   // ----------------------------------------------------------------------------
        );

    _pCD->uiTimeStamp++;

    if ( iRes == SOCKET_ERROR )
        int i = WSAGetLastError();

    return(iRes);
}
// ----------------------------------------------------------------------------
inline int INTRecv(TClientData* _pCD,void* _pBuf,int _iSize)
{
    int iAddrSize = sizeof(SOCKADDR);

    char cBuffer[MAX_PACKET_SIZE];
    TNETPacket* poPacket = (TNETPacket*)cBuffer;

    int iRes = recvfrom(
        _pCD->iSocket,                          // ----------------------------------------------------------------------------
        (char*)poPacket,                        // ----------------------------------------------------------------------------
        _iSize + 8,                               // ----------------------------------------------------------------------------
        0,                          // ----------------------------------------------------------------------------
        (LPSOCKADDR)&_pCD->InAddr,              // ----------------------------------------------------------------------------
        &iAddrSize                              // ----------------------------------------------------------------------------
        );

    if ( iRes == SOCKET_ERROR )
    {
        int i = WSAGetLastError();
        return(-1);
    }
    else
    {
        #ifdef _DEBUG
        unsigned char* IP = (unsigned char*)&_pCD->InAddr.sin_addr;
        char szStr[1024];
        sprintf(szStr,"Server (RecvFrom): %d.%d.%d.%d \n",IP[0],IP[1],IP[2],IP[3]);
        OutputDebugStr(szStr);
        #endif

        // ----------------------------------------------------------------------------
        if ( _pCD->oTSL.bExists( poPacket->m_uiStamp) )
            return(-1);
        else
        {
            _pCD->oTSL.Add(poPacket->m_uiStamp);
            memcpy(_pBuf,poPacket->m_pucData,poPacket->m_uiSize);
            _pCD->uiRcvTimeStamp = poPacket->m_uiStamp;
            return(poPacket->m_uiSize);
        }
    }
}
// ----------------------------------------------------------------------------
void CGNETSystem::Init()
{
    // ----------------------------------------------------------------------------
    #ifdef WIN32
    WSADATA WSAData;
    LPWSADATA lpWSAData = &WSAData;

    WSAStartup(2,lpWSAData);

    // ----------------------------------------------------------------------------
    for ( int i = 0; i < MAX_CONNECTIONS + 1; i++ )
    {
        goCD[i].bValid = false;
        // ----------------------------------------------------------------------------
        goCD[i].iSocket = 0;
        goCD[i].uiTimeStamp = 0;
    }
    #endif
}
// ----------------------------------------------------------------------------
void CGNETSystem::Finish()
{
    #ifdef WIN32
    WSACleanup ();
    #endif
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
bool CGNETSystem::bPendingInfo(int _iSocket)
{
    SOCKADDR_IN oInAddr;
    bool bInfoAvailable = INTPendingInfo(goCD[_iSocket].iSocket,&oInAddr);

    if ( bInfoAvailable )
    {
        return ( *( (unsigned int*)&oInAddr.sin_addr ) == *( (unsigned int*)&goCD[_iSocket].InAddr.sin_addr ) );
    }
    else
        return(0);
}
// ----------------------------------------------------------------------------
int CGNETSystem::CreateServer(uint&_uiServerIP,char* _szServerName,uint _uiPort)
{
    // ----------------------------------------------------------------------------
    // ----------------------------------------------------------------------------
    // ----------------------------------------------------------------------------
    int iServerSocket;
    struct sockaddr_in indir;
    int i;

    // ----------------------------------------------------------------------------
    if ( ( iServerSocket = socket(AF_INET,SOCK_CONNTYPE, SOCK_PROTO) ) < 0 )
        return(-1);

    // ----------------------------------------------------------------------------
    Unblock(iServerSocket);

    GetHostName(_szServerName);
    _uiServerIP = uiGetHostByName(_szServerName);

    // ----------------------------------------------------------------------------
    indir.sin_port = htons(_uiPort);
    indir.sin_addr.s_addr = INADDR_ANY; // ----------------------------------------------------------------------------
    indir.sin_family = AF_INET;
    for ( i = 0; i < 8; i++ ) indir.sin_zero[i] = 0;

    // ----------------------------------------------------------------------------
    if ( ( i = bind( iServerSocket,(struct sockaddr*) &indir,sizeof(indir) ) ) < 0 )
    {
        closesocket(iServerSocket);
        return(-1);
    }

    return(iServerSocket);
}
// ----------------------------------------------------------------------------
int CGNETSystem::AcceptConnections(int _iServerSocket)
{
    // ----------------------------------------------------------------------------
    SOCKADDR_IN sClDir;
    int _CONID;
    TClientData oCD;
    InitClientData(&oCD,0,0,0);

    if ( !INTPendingInfo(_iServerSocket,&sClDir,&_CONID,4) )
        return(-1);

    if ( _CONID != CONID )
        return(-1);

    oCD.InAddr = sClDir;
    oCD.iSocket = _iServerSocket;
    oCD.bValid = true;

    INTRecv(&oCD,&_CONID,4);

    #ifdef _DEBUG
    unsigned char* IP = (unsigned char*)&sClDir.sin_addr;
    char szStr[1024];
    sprintf(szStr,"Server (NewClient): %d.%d.%d.%d \n",IP[0],IP[1],IP[2],IP[3]);
    OutputDebugStr(szStr);
    #endif

    // ----------------------------------------------------------------------------
    int iIdx = iInsertClient(&sClDir,_iServerSocket);

    return(iIdx);
}
// ----------------------------------------------------------------------------
void CGNETSystem::GetHostName(char* _szHostName)
{
    gethostname(_szHostName,MAXC_SNAME);
}
// ----------------------------------------------------------------------------
uint CGNETSystem::uiGetHostByName(char* _szHostName)
{
    struct hostent* st;

    if ( ( st = gethostbyname(_szHostName) ) == 0 ) return(-1);
    return ( *(unsigned int*)(st->h_addr_list[0]) );
}
// ----------------------------------------------------------------------------

int CGNETSystem::WriteToClient(int _iClSocket,void* _pBuff,int _iSize)
{
    Block(goCD[_iClSocket].iSocket);

    int iRes = INTSend(&goCD[_iClSocket],(char*)_pBuff,_iSize);

    Unblock(goCD[_iClSocket].iSocket);

    if ( iRes != -1 )
    {
        #ifdef _DEBUG
        char szStr[1024];
        sprintf(szStr,"Server (Write): %d, Size:%d, Msg: %s\n",goCD[_iClSocket].uiTimeStamp,iRes,_pBuff);
        OutputDebugStr(szStr);
        #endif

        return(1);
    }
    else
        return(0);
}
// ----------------------------------------------------------------------------
int CGNETSystem::ReadFromClient(int _iClSocket,void* _pBuff,int _iSize)
{
    Block(goCD[_iClSocket].iSocket);

    int iRes = INTRecv(&goCD[_iClSocket],(char*)_pBuff,_iSize);

    Unblock(goCD[_iClSocket].iSocket);

    if ( iRes != -1 )
    {
        #ifdef _DEBUG
        char szStr[1024];
        sprintf(szStr,"Server (Read): %d, Size:%d, Msg: %s\n",goCD[_iClSocket].uiRcvTimeStamp,iRes,_pBuff);
        OutputDebugStr(szStr);
        #endif

        return(1);
    }
    else
        return(0);
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
int CGNETSystem::ConnectToServer(char* _szServerName,uint _uiPort)
{
    uint uiServerIP = uiGetHostByName(_szServerName);
    if ( !uiServerIP ) return(-1);
    return ( ConnectToServer(uiServerIP,_uiPort) );
}
// ----------------------------------------------------------------------------
int CGNETSystem::ConnectToServer(uint _uiServerIP,uint _uiPort)
{
    int iClientSocket;
    if ( ( iClientSocket = socket(AF_INET, SOCK_CONNTYPE, SOCK_PROTO) ) < 0 )
        return(-1);

    // ----------------------------------------------------------------------------
    Unblock(iClientSocket);

    #ifdef _DEBUG
    #ifdef WIN32
    int i = WSAGetLastError();
    #endif
    #endif

    InitClientData(&goCD[CLIENT_SOCKET],_uiPort,_uiServerIP,iClientSocket);

    uint _CONID = CONID;
    INTSend(&goCD[CLIENT_SOCKET],&_CONID,4);

    #ifdef _DEBUG
    unsigned char* IP = (unsigned char*)&_uiServerIP;
    char szStr[1024];
    sprintf(szStr,"Client (Connect): %d.%d.%d.%d \n",IP[0],IP[1],IP[2],IP[3]);
    OutputDebugStr(szStr);
    #endif

    return (CLIENT_SOCKET);
}
// ----------------------------------------------------------------------------
int CGNETSystem::WriteToServer (void* _pBuff,int _iSize)
{
    Block(goCD[CLIENT_SOCKET].iSocket);

    int iRes = INTSend(&goCD[CLIENT_SOCKET],(char*)_pBuff,_iSize);

    Unblock(goCD[CLIENT_SOCKET].iSocket);

    if ( iRes != -1 )
    {
        #ifdef _DEBUG
        char szStr[1024];
        sprintf(szStr,"Client (Write): %d, Size:%d, Msg: %s\n",goCD[CLIENT_SOCKET].uiTimeStamp,iRes,_pBuff);
        OutputDebugStr(szStr);
        #endif

        return(1);
    }
    else
        return (0);
}
// ----------------------------------------------------------------------------
int CGNETSystem::ReadFromServer(void* _pBuff,int _iSize)
{
    Block(goCD[CLIENT_SOCKET].iSocket);

    int iRes = INTRecv(&goCD[CLIENT_SOCKET],(char*)_pBuff,_iSize);

    Unblock(goCD[CLIENT_SOCKET].iSocket);

    if ( iRes != -1 )
    {
        #ifdef _DEBUG
        char szStr[1024];
        sprintf(szStr,"Client (Read): %d, Size:%d, Msg: %s\n",goCD[CLIENT_SOCKET].uiRcvTimeStamp,iRes,_pBuff);
        OutputDebugStr(szStr);
        #endif
    }

    return(iRes);
}
// ----------------------------------------------------------------------------
void CGNETSystem::Disconnect()
{
    closesocket( goCD[CLIENT_SOCKET].iSocket );
}
// ----------------------------------------------------------------------------
