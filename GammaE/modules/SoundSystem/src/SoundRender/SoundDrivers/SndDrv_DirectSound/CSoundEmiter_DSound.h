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
// %X% %Q% %Z% %W%

#ifndef CSoundEmiter_DSound_h
#define CSoundEmiter_DSound_h 1

#include "SoundRender\SoundMixer\CSoundMixPars.h"

// CSoundEntity
#include "SoundRender\CSoundEmiter.h"
// CSoundMixPars

class CSoundEmiter_DSound : public CSoundEmiter
{
    public:
        CSoundEmiter_DSound();

        ~CSoundEmiter_DSound();

        // Additional Public Declarations
        CSoundMixPars oSMP;

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSoundEmiter_DSound

#endif
