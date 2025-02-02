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
#include "SoundRender\SoundDrivers\SndDrv_DirectSound\CSR_DS_EmiterPars.h"

// -----------------------------------------------------------------------------

CSR_DS_EmiterPars::CSR_DS_EmiterPars()

    : iCurrLayer(0), iCurSmpPos(0), iNextSmpPos(0), iNextLayer(0), poEmit(NULL)
{
    Channel = mNew CSR_DS_Channel;
}

CSR_DS_EmiterPars::~CSR_DS_EmiterPars()
{
    mDel Channel;
}

// -----------------------------------------------------------------------------
