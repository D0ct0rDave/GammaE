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
#ifndef CGPSGGenericQuad_h
#define CGPSGGenericQuad_h 1
// -----------------------------------------------------------------------------
#include "CGParticle.h"
#include "CGPSGGeneric.h"
// -----------------------------------------------------------------------------
class CGPSGGenericQuadParticle : public CGParticle
{
    public:

        // Current values
        CGColor m_oColor;
        float m_fSize;
        float m_fAngle;
        float m_fRadius;

        // Delta vars
        CGColor m_oDColor;
        float m_fDSize;
        float m_fDAngle;
        float m_fDRadius;

        // Precomputed vars
        CGVect3 m_oPos;                    // This should be always WORLD coordinates
        CGVect3 m_oDir;                    // This should be always WORLD coordinates
        float m_fIEnergy;
};
// -----------------------------------------------------------------------------
class CGPSGGenericQuad : public CGPSGGeneric
{
    public:
        // / Creates and initilaizes a pool of particles	specific to the generator.
        virtual CGParticle* poCreateParticlePool();

        // / Updates the particles of the particle system instance
        virtual void UpdateInstance(CGParticleSystemInstance& _oPSI,float _fDeltaT);

    protected:
        // / Initializes an independent particle of the particle system instance
        virtual void InitParticle(CGPSGGenericQuadParticle* _poPart);

        // / Updates an independent particle of the particle system instance
        virtual void UpdateParticle(CGPSGGenericQuadParticle* _poPart,float _fDeltaT);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
