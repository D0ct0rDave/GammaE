// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include "CGGameMessageMgr.h"
// -----------------------------------------------------------------------------
CGGameMessageMgr::CGGameMessageMgr()
{
}
// -----------------------------------------------------------------------------
void CGGameMessageMgr::SendMsg(unsigned int _uiMsgID,CGGameEntity* _poSrcEntity,void* _pData)
{
    CGGameMessage oMsg(_uiMsgID,_poSrcEntity,_pData);
    m_oMsgStack.uiAdd(oMsg);
}
// -----------------------------------------------------------------------------
CGGameMessage CGGameMessageMgr::oPeekMessage()
{
    CGGameMessage oMsg = m_oMsgStack[0];
    m_oMsgStack.Del(0);

    return(oMsg);
}
// -----------------------------------------------------------------------------
CGGameMessage& CGGameMessageMgr::oWatchMessage()
{
    return (m_oMsgStack[0]);
}
// -----------------------------------------------------------------------------
bool CGGameMessageMgr::bPendingMessages()
{
    return (m_oMsgStack.uiNumElems() > 0);
}
// -----------------------------------------------------------------------------
