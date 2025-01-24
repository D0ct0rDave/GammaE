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

#ifndef CSR_DS_Channel_h
#define CSR_DS_Channel_h 1

#include <DSound.h>

// -----------------------------------------------------------------------------
#include "SoundRender\CSoundEmiter.h"

class CSR_DS_Channel
{
    public:

        CSR_DS_Channel();

        ~CSR_DS_Channel();

        int CreateChannel(LPDIRECTSOUND _lpDS, CSoundEmiter* _pEmiter, CSample* _pSample);

        void UpdateChannel(CSoundEmiter* _pEmiter);

        // -----------------------------------------------------------------------------

        LPDIRECTSOUNDBUFFER lpDSBuff;

        LPDIRECTSOUND3DBUFFER lpDS3DBuff;

        // -----------------------------------------------------------------------------

    protected:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

#endif
