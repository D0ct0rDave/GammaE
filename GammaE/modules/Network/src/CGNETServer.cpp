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
#include "CGNETServer.h"
#include <stdlib.h>
// ----------------------------------------------------------------------------
char CGNETServer::szServerName[MAXC_SNAME];
uint CGNETServer::uiServerIP = 0;
uint CGNETServer::uiServerPort = 0;
int CGNETServer::iServerSocket = 0;
bool CGNETServer::bNetInit = false;
TConnectionCallback CGNETServer::pConnectionCallback = NULL;

void CGNETServer::SetConnectionCallback(TConnectionCallback _pCB)
{
    pConnectionCallback = _pCB;
}

void CGNETServer::Init(uint _uiServerPort)
{
    uiServerPort = _uiServerPort;
    iServerSocket = CGNETSystem::CreateServer(uiServerIP,szServerName,_uiServerPort);
    bNetInit = (iServerSocket != -1);
}

void CGNETServer::Loop()
{
    if ( !bNetInit ) return;

    // ----------------------------------------------------------------------------
    int iClientSocket = CGNETSystem::AcceptConnections(iServerSocket);

    if ( iClientSocket >= 0 )
    {
        if ( pConnectionCallback )
            pConnectionCallback(iClientSocket);
    }
}

bool CGNETServer::bSendInfo(int _uiID,void* pBuff,uint _uiSize)
{
    if ( !bNetInit ) return(false);
    return(CGNETSystem::WriteToClient(_uiID,pBuff,_uiSize) == _uiSize);
}

bool CGNETServer::bGetInfo (int _uiID,void* pBuff,uint&_uiSize)
{
    if ( !bNetInit ) return(false);
    if ( !CGNETSystem::bPendingInfo(_uiID) ) return(false);

    _uiSize = CGNETSystem::ReadFromClient(_uiID,pBuff,_uiSize);
    return(_uiSize > 0);
}
// ----------------------------------------------------------------------------
