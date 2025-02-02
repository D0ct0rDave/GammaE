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
#include "CGNETClient.h"
#include "CGNETSystem.h"
// ----------------------------------------------------------------------------
CGNETClient::CGNETClient()
{
    m_uiState = CLST_DISCONNECTED;
}

CGNETClient::~CGNETClient()
{
}

bool CGNETClient::bConnect(uint _uiServerIP,uint _uiServerPort)
{
    // ----------------------------------------------------------------------------
    if ( ( m_uiClientSocket = CGNETSystem::ConnectToServer(_uiServerIP,_uiServerPort) ) > -1 )
    {
        m_uiState = CLST_CONNECTED;
        return(true);
    }
    else
        return(false);
}

bool CGNETClient::bConnect(char* _szServerName,uint _uiServerPort)
{
    if ( ( m_uiClientSocket = CGNETSystem::ConnectToServer(_szServerName,_uiServerPort) ) > -1 )
    {
        m_uiState = CLST_CONNECTED;
        return(true);
    }
    else
        return(false);
}

bool CGNETClient::bSendInfo (void* _pBuff,int _iSize)
{
    return(CGNETSystem::WriteToServer( _pBuff,_iSize) == _iSize);
}

bool CGNETClient::bGetInfo(void* _pBuff,int &_iSize)
{
    if ( !CGNETSystem::bPendingInfo(m_uiClientSocket) ) return(false);
    _iSize = CGNETSystem::ReadFromServer(_pBuff,_iSize);
    return(_iSize > 0);
}
// ----------------------------------------------------------------------------
