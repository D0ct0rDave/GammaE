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
/*! \class CGGameMsgMgr
 *  \brief A message facility to ease communication between entities and the game modes
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGGameMsgMgrH
#define CGGameMsgMgrH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Entities/CGGameEntity.h"
// -----------------------------------------------------------------------------
class CGGameMessage
{
    public:

        CGGameMessage() : m_uiMsgID(0), m_poEnt(NULL), m_pData(NULL)
        {
        }
        CGGameMessage(uint _uiMsgID,CGGameEntity* _poEnt,void* _pData)
        {
            m_uiMsgID = _uiMsgID;
            m_poEnt = _poEnt;
            m_pData = _pData;
        }

        uint m_uiMsgID;
        CGGameEntity* m_poEnt;
        void* m_pData;
};
// -----------------------------------------------------------------------------
DECLARE_SINGLETON(CGGameMessageMgr)
{
    public:
        CGGameMessageMgr();

    public:
        // / Sends a message from the source entity to the receiver.
        void SendMsg(uint _uiMsgID,CGGameEntity * _poSrcEntity,void* _pData = NULL);

        // / Pick a message from the stack.
        CGGameMessage oPeekMessage();

        // / Retrieve the top most message of the stack, but do not take it out.
        CGGameMessage& oWatchMessage();

        // / Whether there are pending messages in the stack or not
        bool bPendingMessages();

    protected:

        CGDynArray <CGGameMessage> m_oMsgStack;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
