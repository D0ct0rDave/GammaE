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
#ifndef CGGameApplication_h
#define CGGameApplication_h 1
// -----------------------------------------------------------------------------

#include "GammaE_Scene.h"
#include "Entities\CGGameEntity.h"

// -----------------------------------------------------------------------------
typedef enum EGGameAppState
{
    GAPPST_INIT,
    GAPPST_OPENING,
    GAPPST_OPEN,
    GAPPST_CLOSING,
    GAPPST_CLOSED
};
// -----------------------------------------------------------------------------
class CGGameApplication : public CGGameEntity
{
    public:
        PUBLISH_GAMEENTITY_CLASSNAME;

        CGGameApplication();
        ~CGGameApplication();

        virtual void Init();
        virtual void Think(float _fDeltaT);

        virtual void ReceiveChar(int _iKey);
        virtual void Exec(const CGString& _sCommand);

        virtual void Toggle();
        virtual void FullOpen();
        virtual void FullClose();

        EGGameAppState eGameAppState()
        {
            return (m_eGAState);
        }

    protected:
        EGGameAppState m_eGAState;
        float m_fSize;
        float m_fSecs;

    protected:
        CGString m_sLine;
        // -----------------------------------------------------------------------------

        CGString m_sLastCommand;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
