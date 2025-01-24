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

#ifndef CSoundRenderer_OpenAL_h
#define CSoundRenderer_OpenAL_h 1

// -----------------------------------------------------------------------------
#include "SoundRender\CSoundRenderer.h"

#include "SoundRender\SoundDrivers\SndDrv_OpenAL\CSoundEmiter_OpenAL.h"

class CSoundRenderer_OpenAL : public CSoundRenderer
{
    public:

        CSoundRenderer_OpenAL();

        ~CSoundRenderer_OpenAL();

        virtual int Init(void* _HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters);

        virtual void Render(float _fDelta);

        // -----------------------------------------------------------------------------

        virtual CSoundEmiter* poAddOmniEmiter(CSound* _poSound, float _fVol);
        virtual CSoundEmiter* poGetFreeEmiter();
        void InvalidateEmiters();
        virtual void UploadSound(CSound* _poSound);

    protected:
        // -----------------------------------------------------------------------------

        void AddEmiterCommon(CSoundEmiter_OpenAL* _poEmiter,CSound* _poSound, float _fVol);

    private:
        // -----------------------------------------------------------------------------

        CGStArray <CSoundEmiter_OpenAL> oEmiters;

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

#endif
