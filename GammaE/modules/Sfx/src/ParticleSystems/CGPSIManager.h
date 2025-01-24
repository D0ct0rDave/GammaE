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
// ----------------------------------------------------------------------------
#ifndef CGPSIManagerH
#define CGPSIManagerH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GammaE_Sfx.h"
// ----------------------------------------------------------------------------
// Particle System Instance Manager. Provides functionality to
// enable / disable / get / release / auto management with energy (lifetime) instances
// ----------------------------------------------------------------------------
DECLARE_SINGLETON(CGPSIManager)
{
    friend class CGPSIManagerNode;

    public:

        CGPSIManager();

        // / Creates a pool of instances for a given type of particle system generator
        uint uiCreatePool(const CGString &_sType,uint _uiMaxInstances);

        // / Retrieve particle system instance and allow the user to handle it.
        CGParticleSystemInstance* poGet(const CGString& _sType);

        // / Retrieve particle system instance and allow the user to handle it.
        CGParticleSystemInstance* poGet(uint _uiType);

        // / Self handled particle systems
        CGSceneTransf* poGet(const CGString& _sType,float _fEnergy,const CVect3& _oPos);

        // / Self handled particle systems
        CGSceneTransf* poGet(uint _uiType,float _fEnergy,const CVect3& _oPos);

        // / Releases the particle system instance
        void Release(CGParticleSystemInstance * _poPSI);

        // / Retrieves the scene node of the Particle Instance Manager
        CGSceneNode* poGetNode()
        {
            return(m_poRenderingNode);
        }

    protected:

        // --------------------------------------------------------------------
        typedef struct TPSIData
        {
            // / Controls whether the instance is free or not
            bool m_bFree;

            // / The PSI manager handles this PSI or not
            bool m_bAutoManaged;

            // / The subobject index in the node of the auto managed PSIs
            uint m_uiNodeIdx;

            // / The transformation node for this PSI in case is auto managed
            CGSceneTransf* m_poTransf;

            // / The particle system instance itself
            CGParticleSystemInstance* m_poPSI;

            // / The current energy of this instance
            float m_fEnergy;
        }TPSIData;

        typedef class CGStArray <TPSIData> TPSIPool;
        // --------------------------------------------------------------------

        // / Updates the registered instances
        void Update(float _fDeltaT);

        // / Retrieve a free particle instance
        TPSIData* poGetFreeInstance(uint _uiType);

        // / Releases the particle system instance
        void Release(TPSIData * _poPSID);

    protected:
        // / Lookup table for types of pools of PSIs
        CGLookupArray <TPSIPool*> m_oPool;

        // / Node which has attached all the active self handled PSIs
        CGSceneNode* m_poRenderingNode;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
