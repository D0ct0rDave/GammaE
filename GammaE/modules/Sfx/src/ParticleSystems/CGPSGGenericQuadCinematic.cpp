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
#include "ParticleSystems\CGPSGGenericQuadCinematic.h"
#include "CGParticleSystemInstance.h"
// -----------------------------------------------------------------------------
inline float fSRand()
{
    return( (MATH_fRand() - 0.5f) * 2.0f );
}
// -----------------------------------------------------------------------------
CGParticle* CGPSGGenericQuadCinematic::poCreateParticlePool()
{
    CGPSGGenericQuadCinematicParticle* poParts = mNew CGPSGGenericQuadCinematicParticle[m_uiMaxParticles];
    return(poParts);
}
// -----------------------------------------------------------------------------
void CGPSGGenericQuadCinematic::InitParticle(CGPSGGenericQuadCinematicParticle* _poPart)
{
    // Compute energy
    _poPart->m_fEnergy = m_fInitialEnergy * (1.0f + fSRand() * m_fERandomness);
    if ( _poPart->m_fEnergy <= 0.0f )
    {
        _poPart->m_fEnergy = 0.0f;
        return;
    }

    //
    float f1OverNrg = 1.0f / _poPart->m_fEnergy;
    _poPart->m_fIEnergy = _poPart->m_fEnergy;

    // Compute initial color
    CGColor oIColor,oFColor;

    oIColor.r = MATH_fClamp( 0.0f,1.0f,m_oInitialColor.r * ( 1.0f + fSRand() ) );
    oIColor.g = MATH_fClamp( 0.0f,1.0f,m_oInitialColor.g * ( 1.0f + fSRand() ) );
    oIColor.b = MATH_fClamp( 0.0f,1.0f,m_oInitialColor.b * ( 1.0f + fSRand() ) );
    oIColor.a = MATH_fClamp( 0.0f,1.0f,m_oInitialColor.a * ( 1.0f + fSRand() ) );

    oFColor.r = MATH_fClamp( 0.0f,1.0f,m_oFinalColor.r * ( 1.0f + fSRand() ) );
    oFColor.g = MATH_fClamp( 0.0f,1.0f,m_oFinalColor.g * ( 1.0f + fSRand() ) );
    oFColor.b = MATH_fClamp( 0.0f,1.0f,m_oFinalColor.b * ( 1.0f + fSRand() ) );
    oFColor.a = MATH_fClamp( 0.0f,1.0f,m_oFinalColor.a * ( 1.0f + fSRand() ) );

    // Set delta color
    _poPart->m_oDColor.r = (oFColor.r - oIColor.r) * f1OverNrg;
    _poPart->m_oDColor.g = (oFColor.g - oIColor.g) * f1OverNrg;
    _poPart->m_oDColor.b = (oFColor.b - oIColor.b) * f1OverNrg;
    _poPart->m_oDColor.a = (oFColor.a - oIColor.a) * f1OverNrg;

    // Set initial color
    _poPart->m_oColor = oIColor;

    // Compute size
    float m_fISize = MATH_fMax( 0.0f, m_fInitialSize * (1.0f + fSRand() * m_fISRandomness) );
    float m_fFSize = MATH_fMax( 0.0f, m_fFinalSize * (1.0f + fSRand() * m_fFSRandomness) );
    _poPart->m_fSize = m_fISize;
    _poPart->m_fDSize = (m_fFSize - m_fISize) * f1OverNrg;

    // Compute angle
    float m_fIAngle = MATH_fMax( 0.0f, m_fInitialAngle * (1.0f + fSRand() * m_fIARandomness) );
    float m_fFAngle = MATH_fMax( 0.0f, m_fFinalAngle * (1.0f + fSRand() * m_fFARandomness) );
    _poPart->m_fAngle = m_fIAngle;
    _poPart->m_fDAngle = (m_fFAngle - m_fIAngle) * f1OverNrg;

    // Compute radius
    float m_fIRadius = MATH_fMax( 0.0f, m_fInnerRadius * (1.0f + fSRand() * m_fIRRandomness) );
    float m_fORadius = MATH_fMax( 0.0f, m_fOuterRadius * (1.0f + fSRand() * m_fORRandomness) );

    _poPart->m_fRadius = m_fIRadius;
    _poPart->m_fDRadius = (m_fORadius - m_fIRadius) * f1OverNrg;

    // Create a random vector
    _poPart->m_oDir.x = fSRand();
    _poPart->m_oDir.y = fSRand();
    _poPart->m_oDir.z = fSRand();

    _poPart->m_oDir.Normalize();

    // Set position
    _poPart->m_oPos = CGVect3::oZero();
}
// -----------------------------------------------------------------------------
void CGPSGGenericQuadCinematic::UpdateParticle(CGPSGGenericQuadCinematicParticle* _poPart,float _fDeltaT)
{
    // Update energy
    if ( (_poPart->m_fEnergy - _fDeltaT) <= 0.0f )
    {
        _fDeltaT = _poPart->m_fEnergy;
        _poPart->m_fEnergy = 0.0f;
    }
    else
        _poPart->m_fEnergy -= _fDeltaT;

    // Update color
    _poPart->m_oColor.r += _poPart->m_oDColor.r * _fDeltaT;
    _poPart->m_oColor.g += _poPart->m_oDColor.g * _fDeltaT;
    _poPart->m_oColor.b += _poPart->m_oDColor.b * _fDeltaT;
    _poPart->m_oColor.a += _poPart->m_oDColor.a * _fDeltaT;

    _poPart->m_oColor.r = MATH_fMax(_poPart->m_oColor.r,0.0f);
    _poPart->m_oColor.g = MATH_fMax(_poPart->m_oColor.g,0.0f);
    _poPart->m_oColor.b = MATH_fMax(_poPart->m_oColor.b,0.0f);
    _poPart->m_oColor.a = MATH_fMax(_poPart->m_oColor.a,0.0f);

    // Update size
    _poPart->m_fSize += _poPart->m_fDSize * _fDeltaT;

    // Update angle
    _poPart->m_fAngle += _poPart->m_fDAngle * _fDeltaT;

    // Update radius
    _poPart->m_fRadius += _poPart->m_fDRadius * _fDeltaT;
}
// -----------------------------------------------------------------------------
void CGPSGGenericQuadCinematic::UpdateInstance(CGParticleSystemInstance& _oPSI,float _fDeltaT,const CGMatrix4x4& _oViewMatrix)
{
    CGPSGGenericQuadCinematicParticle* poPart = (CGPSGGenericQuadCinematicParticle*)_oPSI.poGetParticlePool();

    CGMesh* poMesh = _oPSI.poGetMesh();
    CGVect3 NewPos;
    CGVect3* pVX = poMesh->m_poVX;
    CGVect4* pVC = poMesh->m_poVC;
    uint uiNumParts = 0;

    for ( uint i = 0; i < m_uiMaxParticles; i++,poPart++ )
    {
        if ( poPart->m_fEnergy <= 0.0f )
        {
            if ( _oPSI.bRegenerate() )
                InitParticle( poPart );
            else
            {
                // Next particle
                continue;
            }
        }
        else
        {
            // update particle
            UpdateParticle( poPart, _fDeltaT );
        }

        // La direccion deber�a estar tambi�n transformada ????
        // Generate the geometry for this particle
        CGVect3 oNewPos;
        oNewPos.LineEq(poPart->m_oPos,poPart->m_oDir,poPart->m_fRadius);
        _oViewMatrix.TransformPoint(oNewPos);

        float _fA = MATH_fCos(poPart->m_fAngle) * poPart->m_fSize;
        float _fB = MATH_fSin(poPart->m_fAngle) * poPart->m_fSize;

        pVX[0].Set( _fA, _fB,0);
        pVX[0].Add(oNewPos);
        pVX[1].Set(-_fB, _fA,0);
        pVX[1].Add(oNewPos);
        pVX[2].Set(-_fA,-_fB,0);
        pVX[2].Add(oNewPos);
        pVX[3].Set( _fB,-_fA,0);
        pVX[3].Add(oNewPos);

        pVC[0] = poPart->m_oColor;
        pVC[1] = poPart->m_oColor;
        pVC[2] = poPart->m_oColor;
        pVC[3] = poPart->m_oColor;

        pVX += 4;
        pVC += 4;

        uiNumParts++;
    }

    poMesh->m_uiNumPrims = uiNumParts;
    poMesh->m_usNumVXs = poMesh->m_uiNumPrims * 4;
    poMesh->m_uiNumIdxs = poMesh->m_uiNumPrims * 4;                    // Either is indexed or not we can do that

    // Stablishes the number of live particles detected during the update step
    _oPSI.SetLiveParticles( uiNumParts );
}
// -----------------------------------------------------------------------------
