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
#ifndef CGParticleSystem_Generic_Quad_h
#define CGParticleSystem_Generic_Quad_h 1
// -----------------------------------------------------------------------------
#include "ParticleSystems\CGParticleSystem_Generic.h"
// -----------------------------------------------------------------------------
typedef struct
{
    CGVect3 Pos;

    CGVect3 Speed;
    CGVect3 OldSpeed;

    CGVect4 Color;

    float fSize;
    float fEnergy;
}TParticle_Quad;
// -----------------------------------------------------------------------------
class CGParticleSystem_Generic_Quad : public CGParticleSystem_Generic
{
    public:
        CGParticleSystem_Generic_Quad();

        virtual ~CGParticleSystem_Generic_Quad();

        virtual void InitPS(int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer);

        virtual void InitParticle(int iPart);

        virtual void UpdateParticle(int iPart);

        virtual void UpdatePS(CGMatrix4x4* _ViewMatrix);

    protected:
        TParticle_Quad* pParts;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
