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
#ifndef CGParticleSystemInstance_h
#define CGParticleSystemInstance_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GammaE_Scene.h"
#include "CGParticleSystemGenerator.h"
// -----------------------------------------------------------------------------
class CGParticleSystemGenerator;
class CGParticleSystemInstance : public CGSceneSwitch
{
    public:

        // / Creates the particle system instance and associates it to the given generator
        CGParticleSystemInstance(CGParticleSystemGenerator* _poPSG);

        // / Renders the particle system instance
        virtual void Render();

        // / Sets whether the particles in the system will regenerate when their energy expires or not
        void Regenerate(bool _bRegen)
        {
            m_bRegen = _bRegen;
        }

        // / Retrieves the regeneration value of the particle system instance
        bool bRegenerate() const
        {
            return(m_bRegen);
        }

        // --------------
        // BEGIN: These functions should only be accessible by the particle system generator

        // / Retrieves the particle pool associated to this instance
        CGParticle* poGetParticlePool() const
        {
            return(m_poParticlePool);
        }

        // / Retrieves the mesh of this instance
        CGMesh* poGetMesh() const
        {
            return(m_poMesh);
        }

        // / Sets the number of living particles detected by the generator
        void SetLiveParticles(uint _uiLiveParticles)
        {
            m_uiLiveParticles = _uiLiveParticles;
        }

        // END:
        // --------------

        // / Retrieves the current number of particles in this instance
        uint uiLiveParticles()
        {
            return (m_uiLiveParticles);
        }

    protected:
        // / Update the particles in the particle system
        virtual void Update(float _fDeltaT);

    protected:

        // / Regeneration of the particles of the instance
        bool m_bRegen;

        // / The particle system generator associated to this instance
        CGParticleSystemGenerator* m_poPSG;

        // / The leaf node containing the particle geometry
        CGSceneLeaf* m_poLeaf;

        // / The mesh that contains all the particle geometry to be rendered
        CGMesh* m_poMesh;

        // / The particle pool used by the particle system generator.
        // / (WARNING: Cannot be used as an array, since particle size varies from system to system)
        CGParticle* m_poParticlePool;

        // / Number of live particles in the instance
        uint m_uiLiveParticles;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
