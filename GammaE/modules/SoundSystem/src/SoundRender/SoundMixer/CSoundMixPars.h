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

#ifndef CSoundMixPars_h
#define CSoundMixPars_h 1

// -----------------------------------------------------------------------------
#include "Sound\CSound.h"

class CSoundMixPars
{
    public:

        CSoundMixPars();

        ~CSoundMixPars();

        // -----------------------------------------------------------------------------

        float fLVol;

        float fRVol;

        int iSPos;

        int iCLayer;

        bool bLUnlock;

        bool bEnd;

        // -----------------------------------------------------------------------------

        CSound* poSound;

    protected:
    private:
    private:
};

// -----------------------------------------------------------------------------

#endif
