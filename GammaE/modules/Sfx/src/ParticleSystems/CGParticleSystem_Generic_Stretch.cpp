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
// CGParticleSystem_Generic_Stretch
#include "ParticleSystems\CGParticleSystem_Generic_Stretch.h"

// Class CGParticleSystem_Generic_Stretch

CGParticleSystem_Generic_Stretch::CGParticleSystem_Generic_Stretch()
    : pParts(NULL)
{
}

CGParticleSystem_Generic_Stretch::~CGParticleSystem_Generic_Stretch()
{
}

void CGParticleSystem_Generic_Stretch::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
    iParticleBytes = sizeof(TParticle_Stretch);
    CGParticleSystem::InitPS(_iMaxParticles,_bZOrder,_bDisableZBuffer);
    pParts = (TParticle_Stretch*)Particle;
}

void CGParticleSystem_Generic_Stretch::InitParticle (int iPart)
{
    TParticle_Stretch* P = &pParts[iPart];

    P->Pos.V3   (0,0,0);
    P->OldPos.Set(0,0,0);

    P->OldSpeed.V3   ( MATH_fRand(),MATH_fRand(),MATH_fRand() );
    P->OldSpeed.Sub  (0.5f,0.5f,0.5f);
    P->OldSpeed.Scale(fPInitialSpeedFact);
    P->OldSpeed.Add  (PSSpeed);

    P->Speed.Assign  (P->OldSpeed);

    P->fSize = fPInitialSizeFact * MATH_fRand();
    P->fEnergy = fPInitialEnergyFact * MATH_fRand();

    P->Color = RGBAInitialValue;
}

void CGParticleSystem_Generic_Stretch::UpdateParticle (int iPart)
{
    static CGVect3 Gravity(0,0,-9.8f);
    static CGVect3 Aux;

    TParticle_Stretch* P = &pParts[iPart];
    P->fEnergy -= fPEnergyFact;

    // x = x0 + vt
    Aux.Assign(P->OldSpeed);
    Aux.Scale(fDelta);

    P->OldPos.Assign(P->Pos);
    P->Pos.Add(Aux);

    // v = v0 + at
    Aux.Assign(Gravity);
    Aux.Scale (fDelta);

    P->OldSpeed.Assign(P->Speed);
    P->Speed.Add(Aux);

    // Setup alpha
    // P->Color.Sub(RGBAFact);

    P->Color.r -= RGBAFact.r;
    P->Color.g -= RGBAFact.g;
    P->Color.b -= RGBAFact.b;
    P->Color.a -= RGBAFact.a;
}

void CGParticleSystem_Generic_Stretch::UpdatePS (CGMatrix4x4* _ViewMatrix)
{
    if ( fPSEnergy <= 0 ) return;

    CGVect3 NewPos;
    CGVect3 OldPos;
    TParticle_Stretch* P = pParts;
    CGVect3* pVX = poMesh->VXs;
    CGColor* pVC = poMesh->VCs;
    int cPart;

    for ( cPart = 0; cPart < iMaxParticles; cPart++ )
    {
        if ( P->fEnergy <= 0 )
        {
            if ( (bPSRegen) && (fPSEnergy >= 0) )
                InitParticle(cPart);
        }

        UpdateParticle (cPart);

        NewPos.Assign( P->Pos );
        _ViewMatrix->TransformPoint(NewPos);

        OldPos.Assign( P->OldPos );
        _ViewMatrix->TransformPoint(OldPos);

        pVX[0].Set(-P->fSize,-P->fSize,0);
        pVX[0].Add(NewPos);
        pVX[1].Set(-P->fSize, P->fSize,0);
        pVX[1].Add(NewPos);
        pVX[2].Set( P->fSize, P->fSize,0);
        pVX[2].Add(OldPos);
        pVX[3].Set( P->fSize,-P->fSize,0);
        pVX[3].Add(OldPos);

        pVC[0] = P->Color;
        pVC[1] = P->Color;
        pVC[2] = P->Color;
        pVC[3] = P->Color;

        pVX += 4;
        pVC += 4;
        P++;
    }
}

// Additional Declarations
