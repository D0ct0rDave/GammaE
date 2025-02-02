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
// ## begin module%3B72F78101D1.cm preserve=no
// ## end module%3B72F78101D1.cm

// ## begin module%3B72F78101D1.cp preserve=no
// ## end module%3B72F78101D1.cp

// ## Module: CGParticleSystem%3B72F78101D1; Pseudo Package body
// ## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CGParticleSystem.cpp

// ## begin module%3B72F78101D1.additionalIncludes preserve=no
// ## end module%3B72F78101D1.additionalIncludes

// ## begin module%3B72F78101D1.includes preserve=yes
#include <stdlib.h>
#include <string.h>
// #include <iostream.h>

#include "GammaE_Mem.h"
// ## end module%3B72F78101D1.includes

// CGParticleSystem
#include "CGParticleSystem.h"
// ## begin module%3B72F78101D1.additionalDeclarations preserve=yes
// ## end module%3B72F78101D1.additionalDeclarations

// Class CGParticleSystem

CGParticleSystem::CGParticleSystem()
// ## begin CGParticleSystem::CGParticleSystem%.hasinit preserve=no
    : iMaxParticles(0), Particle(NULL), fDelta(0), bPSRegen(false), fPSInitialEnergy(0), fPSEnergyFact(0), iParticleBytes(0), bZOrder(false), bDisableZBuffer(false)
{
    // ## end CGParticleSystem::CGParticleSystem%.hasinit
    // ## begin CGParticleSystem::CGParticleSystem%.initialization preserve=yes
    // ## end CGParticleSystem::CGParticleSystem%.initialization
    // ## begin CGParticleSystem::CGParticleSystem%.body preserve=yes
    // ## end CGParticleSystem::CGParticleSystem%.body
}

CGParticleSystem::~CGParticleSystem()
{
    // ## begin CGParticleSystem::~CGParticleSystem%.body preserve=yes
    // ## end CGParticleSystem::~CGParticleSystem%.body
}

// ## Other Operations (implementation)
void CGParticleSystem::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
    // ## begin CGParticleSystem::InitPS%997390914.body preserve=yes
    int cPart;

    if ( Particle ) MEMFree(Particle);
    if (m_poMesh) mDel(m_poMesh);

    iMaxParticles = _iMaxParticles;
    Particle = MEMAlloc(iParticleBytes * iMaxParticles);
    memset(Particle,0,iParticleBytes * iMaxParticles);

    // -----------------------------------------------------
    // InitMesh
    // -----------------------------------------------------
    m_poMesh = mNew CGMesh();
    m_poMesh->Init(iMaxParticles * 4,iMaxParticles, E3D_PrimitiveType::E3D_PT_QUADS,
                 MESH_FIELD_VERTEXS |
                 MESH_FIELD_UVCOORDS |
                 MESH_FIELD_COLORS |
                 MESH_FIELD_INDEXES);

    for ( cPart = 0; cPart < iMaxParticles; cPart++ )
    {
        m_poMesh->m_pusIdx[cPart * 4 + 0] = cPart * 4 + 1;
        m_poMesh->m_pusIdx[cPart * 4 + 1] = cPart * 4 + 0;
        m_poMesh->m_pusIdx[cPart * 4 + 2] = cPart * 4 + 3;
        m_poMesh->m_pusIdx[cPart * 4 + 3] = cPart * 4 + 2;

        m_poMesh->m_poUV[cPart * 4 + 0].Set(0.0f,0.0f);
        m_poMesh->m_poUV[cPart * 4 + 1].Set(0.0f,1.0f);
        m_poMesh->m_poUV[cPart * 4 + 2].Set(1.0f,1.0f);
        m_poMesh->m_poUV[cPart * 4 + 3].Set(1.0f,0.0f);

        m_poMesh->m_poVX[cPart * 4 + 0].Set(0.0f,0.0f,10000.0f);
        m_poMesh->m_poVX[cPart * 4 + 1].Set(0.0f,0.0f,10000.0f);
        m_poMesh->m_poVX[cPart * 4 + 2].Set(0.0f,0.0f,10000.0f);
        m_poMesh->m_poVX[cPart * 4 + 3].Set(0.0f,0.0f,10000.0f);
    }

    // -----------------------------------------------------
    bZOrder = _bZOrder;
    bDisableZBuffer = _bDisableZBuffer;
    // ## end CGParticleSystem::InitPS%997390914.body
}

void CGParticleSystem::SetPSParams (bool _bPSRegen, float _fPSEnergy, float _fPSEnergyFact)
{
    // ## begin CGParticleSystem::SetPSParams%998089259.body preserve=yes
    bPSRegen = _bPSRegen;
    fPSInitialEnergy = _fPSEnergy;
    fPSEnergy = _fPSEnergy;
    fPSEnergyFact = _fPSEnergyFact;
    // ## end CGParticleSystem::SetPSParams%998089259.body
}

void CGParticleSystem::Think (float _fDelta)
{
    // ## begin CGParticleSystem::Think%997390915.body preserve=yes
    if ( fPSEnergy <= 0 ) return;

    fPSEnergy -= fPSEnergyFact;

    if ( fPSEnergy <= 0 )
    {
        if ( bPSRegen ) fPSEnergy = fPSInitialEnergy;
    }

    fDelta = _fDelta;
    // ## end CGParticleSystem::Think%997390915.body
}

void CGParticleSystem::Render ()
{
    // ## begin CGParticleSystem::Render%997390917.body preserve=yes
    CGMatrix4x4 CurrentViewMat;
    bool bEnableZBuffer = false;

    if ( bDisableZBuffer )
        CGRenderer::I()->SetZPars(E3D_ZTestFunc::E3D_ZTF_None, E3D_ZWrite::E3D_ZW_Current);

    Think( CGRenderer::I()->oGetStats().m_fDelta );

    CGRenderer::I()->GetWorldMatrix(&CurrentViewMat);

    UpdatePS(&CurrentViewMat);
    CGRenderer::I()->ClearCameraMatrix();
    
    CGSCNVRenderer::I()->Render(this);

    CGRenderer::I()->SetWorldMatrix(CurrentViewMat);

    if ( bEnableZBuffer )
        CGRenderer::I()->SetZPars(E3D_ZTestFunc::E3D_ZTF_Last, E3D_ZWrite::E3D_ZW_Current);
    // ## end CGParticleSystem::Render%997390917.body
}

// Additional Declarations
// ## begin CGParticleSystem%3B72F78101D1.declarations preserve=yes
// ## end CGParticleSystem%3B72F78101D1.declarations

// ## begin module%3B72F78101D1.epilog preserve=yes
// ## end module%3B72F78101D1.epilog
