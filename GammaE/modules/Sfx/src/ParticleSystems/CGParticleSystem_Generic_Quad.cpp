// -----------------------------------------------------------------------------
#include "ParticleSystems\CParticleSystem_Generic_Quad.h"
// -----------------------------------------------------------------------------
CParticleSystem_Generic_Quad::CParticleSystem_Generic_Quad() : pParts(NULL)
{
    iParticleBytes = sizeof(TParticle_Quad);
}
// -----------------------------------------------------------------------------
CParticleSystem_Generic_Quad::~CParticleSystem_Generic_Quad()
{
}
// -----------------------------------------------------------------------------
void CParticleSystem_Generic_Quad::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
    iParticleBytes = sizeof(TParticle_Quad);

    CParticleSystem::InitPS(_iMaxParticles,_bZOrder,_bDisableZBuffer);

    pParts = (TParticle_Quad*)Particle;
}
// -----------------------------------------------------------------------------
void CParticleSystem_Generic_Quad::InitParticle (int iPart)
{
    TParticle_Quad* P = &pParts[iPart];

    P->Pos.V3   (0,0,0);

    P->OldSpeed.V3   ( MATH_fRand(),MATH_fRand(),MATH_fRand() );
    P->OldSpeed.Sub  (0.5f,0.5f,0.5f);
    P->OldSpeed.Scale(fPInitialSpeedFact);
    P->OldSpeed.Add  (PSSpeed);

    P->Speed.Assign  (P->OldSpeed);

    P->fSize = fPInitialSizeFact * MATH_fRand();
    P->fEnergy = fPInitialEnergyFact * MATH_fRand();

    P->Color.Assign(RGBAInitialValue);
}
// -----------------------------------------------------------------------------
void CParticleSystem_Generic_Quad::UpdateParticle (int iPart)
{
    static CVect3 Gravity(0,0,-9.8f);
    static CVect3 Aux;

    TParticle_Quad* P = &pParts[iPart];
    P->fEnergy -= fPEnergyFact;

    // x = x0 + vt
    Aux.Assign(P->OldSpeed);
    Aux.Scale(fDelta);

    P->Pos.Add(Aux);

    // v = v0 + at
    Aux.Assign(Gravity);
    Aux.Scale (fDelta);

    P->OldSpeed.Assign(P->Speed);
    P->Speed.Add(Aux);

    // Setup alpha
    P->Color.Sub(RGBAFact);
}
// -----------------------------------------------------------------------------
void CParticleSystem_Generic_Quad::UpdatePS (CMatrix4x4* _ViewMatrix)
{
    if ( fPSEnergy <= 0 ) return;

    /*
       if (bZOrder)
       {
        UpdatePSZOrder(_ViewMatrix);
        return;
       }
     */

    CVect3 NewPos;
    TParticle_Quad* P = pParts;
    CVect3* pVX = poMesh->VXs;
    CVect4* pVC = poMesh->VCs;
    int CPart;

    for ( CPart = 0; CPart < iMaxParticles; CPart++ )
    {
        if ( P->fEnergy <= 0 )
        {
            if ( (bPSRegen) && (fPSEnergy >= 0) )
                InitParticle(CPart);
        }
        UpdateParticle (CPart);

        NewPos.Assign( P->Pos );
        _ViewMatrix->TransformPoint(NewPos);

        pVX[0].V3(-P->fSize,-P->fSize,0);
        pVX[0].Add(NewPos);
        pVX[1].V3(-P->fSize, P->fSize,0);
        pVX[1].Add(NewPos);
        pVX[2].V3( P->fSize, P->fSize,0);
        pVX[2].Add(NewPos);
        pVX[3].V3( P->fSize,-P->fSize,0);
        pVX[3].Add(NewPos);

        pVC[0].Assign(P->Color);
        pVC[1].Assign(P->Color);
        pVC[2].Assign(P->Color);
        pVC[3].Assign(P->Color);

        pVX += 4;
        pVC += 4;
        P++;
    }
}
// -----------------------------------------------------------------------------
