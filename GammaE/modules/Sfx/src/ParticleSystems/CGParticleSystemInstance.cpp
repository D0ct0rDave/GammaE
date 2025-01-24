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
#include <stdlib.h>
#include <string.h>
#include "GammaE_Mem.h"
#include "CGParticleSystemInstance.h"
// -----------------------------------------------------------------------------
CGParticleSystemInstance::CGParticleSystemInstance(CGParticleSystemGenerator* _poPSG)
{
    // Set the generator for this particle instance
    m_poPSG = _poPSG;

    // Creates the particle pool for this instance
    m_poParticlePool = m_poPSG->poCreateParticlePool();

    uint uiMaxParticles = m_poPSG->uiMaxParticles();

    // Create the mesh object
    m_poMesh = mNew CGMesh();
    m_poMesh->Init( uiMaxParticles * 4,uiMaxParticles,
                    E3D_MESH_QUADS,
                    MESH_FIELD_VERTEXS |
                    MESH_FIELD_UVCOORDS |
                    MESH_FIELD_COLORS |
                    MESH_FIELD_INDEXES);

    for ( uint i = 0; i < uiMaxParticles; i++ )
    {
        m_poMesh->m_pusIdx[i * 4 + 0] = i * 4 + 1;
        m_poMesh->m_pusIdx[i * 4 + 1] = i * 4 + 0;
        m_poMesh->m_pusIdx[i * 4 + 2] = i * 4 + 3;
        m_poMesh->m_pusIdx[i * 4 + 3] = i * 4 + 2;

        m_poMesh->m_poUV[i * 4 + 0].V2(0.0f,0.0f);
        m_poMesh->m_poUV[i * 4 + 1].V2(0.0f,1.0f);
        m_poMesh->m_poUV[i * 4 + 2].V2(1.0f,1.0f);
        m_poMesh->m_poUV[i * 4 + 3].V2(1.0f,0.0f);

        m_poMesh->m_poVX[i * 4 + 0].V3(0.0f,0.0f,10000.0f);
        m_poMesh->m_poVX[i * 4 + 1].V3(0.0f,0.0f,10000.0f);
        m_poMesh->m_poVX[i * 4 + 2].V3(0.0f,0.0f,10000.0f);
        m_poMesh->m_poVX[i * 4 + 3].V3(0.0f,0.0f,10000.0f);
    }

    // Create leaf object
    m_poLeaf = mNew CGSceneLeaf();
    m_poLeaf->SetMesh(m_poMesh);
    m_poLeaf->SetShader( m_poPSG->poGetShader() );

    // Set the leaf as the object associated to the node
    SetObject(m_poLeaf);

    // Setup properties
    m_bRegen = false;
}
// -----------------------------------------------------------------------------
void CGParticleSystemInstance::Update(float _fDeltaT)
{
    if ( !bEnabled() ) return;
    m_poPSG->UpdateInstance(*this,_fDeltaT);
}
// -----------------------------------------------------------------------------
void CGParticleSystemInstance::Render ()
{
    if ( !bEnabled() ) return;

    // Update the particles in this instance
    Update( CGRenderer::I()->REStats.DTime );

    // Renders the geometry
    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->PushWorldMatrix();

    CGRenderer::I()->ClearCameraMatrix();
    CGRenderer::I()->ClearWorldMatrix();

    m_poObj->Render();

    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
}
// -----------------------------------------------------------------------------
