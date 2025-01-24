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

// -----------------------------------------------------------------------------
#include "Sound\CSound.h"

#include <assert.h>
#include <string.h>
#include "GammaE_Mem.h"

// -----------------------------------------------------------------------------

CSound::CSound()

    : iNumLayers(0), poSLayer(NULL)
{
}

CSound::~CSound()
{
    mDel [] poSLayer;
}

int CSound::iAddLayer (CSoundLayer& _oSLayer)
{
    return( iAddLayer(_oSLayer.bLoop,_oSLayer.poSample) );
}

int CSound::iAddLayer (bool _bLoop, CSample* _poSample)
{
    CSoundLayer* poNewSLayer;
    poNewSLayer = mNew CSoundLayer[iNumLayers + 1];

    if ( poSLayer )
    {
        memcpy( poNewSLayer,poSLayer,iNumLayers * sizeof(CSoundLayer) );
        mDel [] poSLayer;
    }

    // -----------------------------------------------------------------------------
    poNewSLayer[iNumLayers].bLoop = _bLoop;
    poNewSLayer[iNumLayers].poSample = _poSample;

    // -----------------------------------------------------------------------------
    poSLayer = poNewSLayer;

    // -----------------------------------------------------------------------------
    iNumLayers++;

    return(iNumLayers - 1);
}

// -----------------------------------------------------------------------------
