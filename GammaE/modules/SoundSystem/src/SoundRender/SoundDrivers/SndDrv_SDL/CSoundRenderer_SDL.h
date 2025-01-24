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

#ifndef CSoundRenderer_SDL_h
#define CSoundRenderer_SDL_h 1

// -----------------------------------------------------------------------------
#include "SoundRender\CSoundRenderer.h"

class CSoundRenderer_SDL : public CSoundRenderer
{
    public:

        CSoundRenderer_SDL();

        ~CSoundRenderer_SDL();

        virtual int Init(void* _HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters);

        virtual void Render(float _fDelta);

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
