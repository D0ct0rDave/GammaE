// -----------------------------------------------------------------------------
#ifndef CGameMsgMgrH
#define CGameMsgMgrH

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CEntity.h"

typedef struct TEntityMessage{

	unsigned int	m_uiMsgID;
	CEntity*		m_poEnt;
	void*			m_pData;

}TEntityMessage;
// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
class CGameMsgMgr
{
	public:
		// Queue a message from the source entity
		static void SendMessage(unsigned int _uiMsgID,CEntity* _poSrcEntity,void* _pData = NULL);
		
		// Retrieve the top most message
		static TEntityMessage oPeekMessage();
		
		// Retrieve the top most message but do not deque it
		static TEntityMessage& oWatchMessage();
		
		// Returns whether there are still pending messages in the queue or not
		static bool bPendingMessages();

	protected:

		//
		static MEM_DynamicArray <TEntityMessage> m_oMsgStack;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
