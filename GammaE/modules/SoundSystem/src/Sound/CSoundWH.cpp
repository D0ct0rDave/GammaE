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
#include "Sound\CSoundWH.h"
#include "Sound\CSampleWH.h"
// -----------------------------------------------------------------------------
CSound* CSoundWH::poLoadResource(const CGString& _sFilename)
{
    int iSmp = CSampleWH::I()->iLoad(_sFilename);

    CSound* poSound = mNew CSound;
    poSound->iAddLayer( false,CSampleWH::I()->poGet(iSmp) );

    return(poSound);
}
// -----------------------------------------------------------------------------
