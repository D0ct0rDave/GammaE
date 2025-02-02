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
#ifndef CGLiveGameEntityH
#define CGLiveGameEntityH
// -----------------------------------------------------------------------------
#include "CGGameEntity.h"
// -----------------------------------------------------------------------------
class CGLiveGameEntity : public CGGameEntity
{
    public:
        PUBLISH_GAMEENTITY_CLASSNAME;

        CGLiveGameEntity() : m_fEnergy(0)
        {
        }

        // / Sets the energy of the entity
        void SetEnergy(float _fEnergy)
        {
            m_fEnergy = _fEnergy;
        }

        // / Retrieves the current energy of the living entity
        float fGetEnergy()
        {
            return(m_fEnergy);
        }

        // / Inflicts damage over the current entity
        void InflictDamage(float _fEnergy);

        // / Specific function to be called once the entity energy reachs value 0
        virtual void Kill()
        {
        }

        // / Specific function to be called if the entity has been damaged
        virtual void Damage()
        {
        }

    protected:
        // / Stores the current energy of the entity
        float m_fEnergy;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
