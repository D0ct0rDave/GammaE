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
// %X% %Q% %Z% %W%

#ifndef CGParticleSystem_Generic_Stretch_h
#define CGParticleSystem_Generic_Stretch_h 1

// CGParticleSystem_Generic
#include "ParticleSystems\CGParticleSystem_Generic.h"

typedef struct
{
    CVect3 Pos;
    CVect3 OldPos;

    CVect3 Speed;
    CVect3 OldSpeed;

    CGColor Color;

    float fSize;
    float fEnergy;
}TParticle_Stretch;

class CGParticleSystem_Generic_Stretch : public CGParticleSystem_Generic
{
    public:
        CGParticleSystem_Generic_Stretch();

        virtual ~CGParticleSystem_Generic_Stretch();

        virtual void InitPS(int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer);

        virtual void InitParticle(int iPart);

        virtual void UpdateParticle(int iPart);

        virtual void UpdatePS(CMatrix4x4* _ViewMatrix);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        TParticle_Stretch* pParts;

        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGParticleSystem_Generic_Stretch

#endif
