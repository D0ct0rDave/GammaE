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

#ifndef CSoundEmiter_OpenAL_h
#define CSoundEmiter_OpenAL_h 1

// -----------------------------------------------------------------------------
#include "SoundRender\CSoundEmiter.h"
// -----------------------------------------------------------------------------

class CSoundEmiter_OpenAL : public CSoundEmiter
{
    public:

        CSoundEmiter_OpenAL();

        ~CSoundEmiter_OpenAL();

        // -----------------------------------------------------------------------------

        unsigned int uiSourceHandler;
        bool bPlaying;
};

// -----------------------------------------------------------------------------

#endif
// -----------------------------------------------------------------------------
