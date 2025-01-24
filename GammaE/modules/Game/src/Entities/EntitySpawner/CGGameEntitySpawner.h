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
/*! \class CGGameEntitySpawner
 *  \brief A game entity that handles the flow of the game play by scripting
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGGameEntitySpawnerH
#define CGGameEntitySpawnerH
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Entities/CGGameEntity.h"
// -----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGGameEntitySpawner,public,CGGameEntity)
{
    public:

        PUBLISH_GAMEENTITY_CLASSNAME;

        // / Initializes the entity spawner to handle a maximum number of entities
        void Init(uint _uiMaxEntities);

        // / Performs an update step to spawn entities when needed
        virtual void Think(float _fDeltaT);

        // / Adds a new entity to spawn in the given time.
        void Spawn(CGGameEntity * _poEnt,float _fTime);

    protected:

        typedef struct TSpawnEntityPair
        {
            CGGameEntity* m_poEntity;
            float m_fTime;
        }TSpawnEntityPair;

        CGCircularArray <TSpawnEntityPair> m_oEntities;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
