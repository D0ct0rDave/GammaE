// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Entity Message Manager
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#include "CGameMsgMgr.h"

MEM_DynamicArray <TEntityMessage> CGameMsgMgr::m_oMsgStack;
// -----------------------------------------------------------------------------
// Queue a message from the source entity
void CGameMsgMgr::SendMessage(unsigned int _uiMsgID,CEntity* _poSrcEntity,void* _pData)
{
	TEntityMessage oMsg = { _uiMsgID, _poSrcEntity, _pData };
	m_oMsgStack.iAdd(oMsg);
}
// -----------------------------------------------------------------------------
// Retrieve the top most message
// -----------------------------------------------------------------------------
TEntityMessage CGameMsgMgr::oPeekMessage()
{
	TEntityMessage oMsg = m_oMsgStack.oGetAt(0);
	m_oMsgStack.Del(0);

	return(oMsg);
}
// -----------------------------------------------------------------------------
// Retrieve the top most message but do not deque it
// -----------------------------------------------------------------------------
TEntityMessage& CGameMsgMgr::oWatchMessage()
{
	return ( m_oMsgStack.roGetAt(0) );
}
// -----------------------------------------------------------------------------
// Returns whether there are still pending messages in the queue or not
// -----------------------------------------------------------------------------
bool CGameMsgMgr::bPendingMessages()
{
	return (m_oMsgStack.iGetNbElem() > 0);
}
// -----------------------------------------------------------------------------