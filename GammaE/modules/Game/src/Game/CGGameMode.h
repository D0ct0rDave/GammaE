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
/*! \class CGGameMode
 *  \brief Base class for specific game mode programming.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGGameModeH
#define CGGameModeH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// -----------------------------------------------------------------------------
#define GM_SKILLHARD    20
#define GM_SKILLMEDIUM  10
#define GM_SKILLEASY     0
// -----------------------------------------------------------------------------
typedef enum TGMState
{
    GM_STATE_NONE,
    GM_STATE_INIT,
    GM_STATE_FINISH,
    GM_STATE_RUN,
    GM_STATE_PAUSED,
    GM_STATE_NUMGMSTATES
}TGMState;
// -----------------------------------------------------------------------------
class CGGameMode
{
    public:
        virtual void Init(uint _uiLevel,uint _uiSkill) = 0;
        virtual void Finish() = 0;
        virtual void Reset() = 0;

        virtual void Think(float _fDeltaT) = 0;
        virtual void Render() = 0;

        virtual void HandleMessageQueue() = 0;
        TGMState eState()
        {
            return(m_eState);
        }

    protected:
        uint m_uiLevel;
        uint m_uiSkill;
        TGMState m_eState;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
