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

CVect3* pCurrentVXs = NULL;

int SortVXs( const void* a, const void* b)
{
    static CVect3* pVXa,* pVXb;

    pVXa = (CVect3*)pCurrentVXs + *( (unsigned short*)a );
    pVXb = (CVect3*)pCurrentVXs + *( (unsigned short*)b );

    if ( pVXa->z < pVXb->z ) return(-1);
    else
    if ( pVXa->z > pVXb->z ) return(1);
    else return(0);
}

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
    bFrustumTest = 0;
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

    if ( Particle ) mFree(Particle);
    if ( poMesh ) mDel(poMesh);

    iMaxParticles = _iMaxParticles;
    Particle = mAlloc(iParticleBytes * iMaxParticles);
    memset(Particle,0,iParticleBytes * iMaxParticles);

    // -----------------------------------------------------
    // InitMesh
    // -----------------------------------------------------
    poMesh = mNew CMesh();
    poMesh->Init(iMaxParticles * 4,iMaxParticles,E3D_MESH_QUADS,
                 MESH_FIELD_VERTEXS |
                 MESH_FIELD_UVCOORDS |
                 MESH_FIELD_COLORS |
                 MESH_FIELD_INDEXES);

    for ( cPart = 0; cPart < iMaxParticles; cPart++ )
    {
        poMesh->Idxs[cPart * 4 + 0] = cPart * 4 + 1;
        poMesh->Idxs[cPart * 4 + 1] = cPart * 4 + 0;
        poMesh->Idxs[cPart * 4 + 2] = cPart * 4 + 3;
        poMesh->Idxs[cPart * 4 + 3] = cPart * 4 + 2;

        poMesh->UVs[cPart * 4 + 0].V2(0.0f,0.0f);
        poMesh->UVs[cPart * 4 + 1].V2(0.0f,1.0f);
        poMesh->UVs[cPart * 4 + 2].V2(1.0f,1.0f);
        poMesh->UVs[cPart * 4 + 3].V2(1.0f,0.0f);

        poMesh->VXs[cPart * 4 + 0].V3(0.0f,0.0f,10000.0f);
        poMesh->VXs[cPart * 4 + 1].V3(0.0f,0.0f,10000.0f);
        poMesh->VXs[cPart * 4 + 2].V3(0.0f,0.0f,10000.0f);
        poMesh->VXs[cPart * 4 + 3].V3(0.0f,0.0f,10000.0f);
    }

    // -----------------------------------------------------
    BVol = poMesh->GetBoundVol();
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
    CMatrix4x4 CurrentViewMat;
    bool bEnableZBuffer = false;

    if ( bDisableZBuffer )
        CGRenderer::I()->SetZPars(eE3D_ZTF_None,eE3D_ZW_Current);

    Think( CGRenderer::I()->REStats.DTime );

    CGRenderer::I()->GetWorldMatrix(&CurrentViewMat);

    UpdatePS(&CurrentViewMat);
    if ( bZOrder ) OrderPS ();
    CGRenderer::I()->ClearCameraMatrix();
    CGSceneLeaf::Render();

    CGRenderer::I()->SetWorldMatrix(&CurrentViewMat);

    if ( bEnableZBuffer )
        CGRenderer::I()->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Current);
    // ## end CGParticleSystem::Render%997390917.body
}

void CGParticleSystem::OrderPS ()
{
    // ## begin CGParticleSystem::OrderPS%998089257.body preserve=yes
    pCurrentVXs = poMesh->VXs;
    qsort(poMesh->Idxs,iMaxParticles,4 * sizeof(unsigned short),SortVXs);
    // ## end CGParticleSystem::OrderPS%998089257.body
}

// Additional Declarations
// ## begin CGParticleSystem%3B72F78101D1.declarations preserve=yes
// ## end CGParticleSystem%3B72F78101D1.declarations

// ## begin module%3B72F78101D1.epilog preserve=yes
// ## end module%3B72F78101D1.epilog
