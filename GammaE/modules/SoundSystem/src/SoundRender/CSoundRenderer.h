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

#ifndef CSoundRenderer_h
#define CSoundRenderer_h 1

#include "GammaE_Misc.h"

// -----------------------------------------------------------------------------
#include "SoundRender\CSoundEmiter.h"
// -----------------------------------------------------------------------------
#include "SoundRender\CSoundReceiver.h"

class CSoundRenderer
{
    public:

        CSoundRenderer();

        ~CSoundRenderer();

        virtual int Init(void* _HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters) = 0;

        virtual void Render(float _fDelta) = 0;

        virtual CSoundEmiter* poAddDirEmiter(CSound* _poSound, float _fVol, CGVect3& _oPos, float _fRadius, CGVect3& _oDir);

        virtual CSoundEmiter* poAddEmiter(CSound* _poSound, float _fVol, CGVect3& _oPos, float _fRadius);

        virtual CSoundEmiter* poAddOmniEmiter(CSound* _poSound, float _fVol);

        void SetReceiver(CSoundReceiver* _poReceiver);

        CSoundReceiver* poGetReceiver();

        virtual void InvalidateEmiters ()
        {
        }

        void SetGlobalVolume(float _fGlbVol);

        float fGetGlobalVolume();

        // -----------------------------------------------------------------------------

        virtual CSoundEmiter* poGetFreeEmiter()
        {
            return(NULL);
        }
        virtual void UploadSound(CSound* _poSound)
        {
        }

    protected:
        // -----------------------------------------------------------------------------

        int iMaxEmiters;

        CSoundReceiver* poReceiver;

        float fGlbVol;

        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

inline void CSoundRenderer::SetGlobalVolume (float _fGlbVol)
{
    if ( _fGlbVol < 0.0f )
        fGlbVol = 0.0f;
    else if ( _fGlbVol > 1.0f )
        fGlbVol = 1.0f;
    else fGlbVol = _fGlbVol;
}

inline float CSoundRenderer::fGetGlobalVolume ()
{
    return(fGlbVol);
}

#endif
