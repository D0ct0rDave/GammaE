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
#include "CGLiveGameEntity.h"

// -----------------------------------------------------------------------------
void CGLiveGameEntity::InflictDamage(float _fEnergy)
{
    m_fEnergy -= _fEnergy;
    if ( m_fEnergy < 0.0f )
    {
        m_fEnergy = 0.0f;
        Kill();
        Reset();
    }
    else
        Damage();
}
// -----------------------------------------------------------------------------
