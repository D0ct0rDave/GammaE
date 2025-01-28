// -----------------------------------------------------------------------------
#include "CGParticleSystem_Generic_Quad.h"
// -----------------------------------------------------------------------------
CGParticleSystem_Generic_Quad::CGParticleSystem_Generic_Quad() : pParts(NULL)
{
    iParticleBytes = sizeof(TParticle_Quad);
}
// -----------------------------------------------------------------------------
CGParticleSystem_Generic_Quad::~CGParticleSystem_Generic_Quad()
{
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic_Quad::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
    iParticleBytes = sizeof(TParticle_Quad);

    CGParticleSystem::InitPS(_iMaxParticles,_bZOrder,_bDisableZBuffer);

    pParts = (TParticle_Quad*)Particle;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic_Quad::InitParticle (int iPart)
{
    TParticle_Quad* P = &pParts[iPart];

    P->Pos.Set(0,0,0);
    
    P->OldSpeed.Set  ( Math::fRand(),Math::fRand(),Math::fRand() );
    P->OldSpeed.Sub  (0.5f,0.5f,0.5f);
    P->OldSpeed.Scale(fPInitialSpeedFact);
    P->OldSpeed.Add  (PSSpeed);

    P->Speed.Assign  (P->OldSpeed);

    P->fSize = fPInitialSizeFact * Math::fRand();
    P->fEnergy = fPInitialEnergyFact * Math::fRand();

    P->Color = RGBAInitialValue;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic_Quad::UpdateParticle (int iPart)
{
    static CGVect3 Gravity(0,0,-9.8f);
    static CGVect3 Aux;

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
    P->Color.r = P->Color.r - RGBAFact.r;
    P->Color.g = P->Color.g - RGBAFact.g;
    P->Color.b = P->Color.b - RGBAFact.b;
    P->Color.a = P->Color.a - RGBAFact.a;
}
// -----------------------------------------------------------------------------
void CGParticleSystem_Generic_Quad::UpdatePS (CGMatrix4x4* _ViewMatrix)
{
    if ( fPSEnergy <= 0 ) return;

    /*
       if (bZOrder)
       {
        UpdatePSZOrder(_ViewMatrix);
        return;
       }
     */

    CGVect3 NewPos;
    TParticle_Quad* P = pParts;
    CGVect3* pVX = m_poMesh->m_poVX;
    CGColor* pVC = m_poMesh->m_poVC;
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
        _ViewMatrix->TransformPoint(&NewPos);

        pVX[0].Set(-P->fSize,-P->fSize,0);
        pVX[0].Add(NewPos);
        pVX[1].Set(-P->fSize, P->fSize,0);
        pVX[1].Add(NewPos);
        pVX[2].Set( P->fSize, P->fSize,0);
        pVX[2].Add(NewPos);
        pVX[3].Set( P->fSize,-P->fSize,0);
        pVX[3].Add(NewPos);

        pVC[0] = P->Color;
        pVC[1] = P->Color;
        pVC[2] = P->Color;
        pVC[3] = P->Color;

        pVX += 4;
        pVC += 4;
        P++;
    }
}
// -----------------------------------------------------------------------------
