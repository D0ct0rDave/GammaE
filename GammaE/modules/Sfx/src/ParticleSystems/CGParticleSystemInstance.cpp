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
    m_poMeshGeometry = mNew CGMesh();
    m_poMeshGeometry->Init( uiMaxParticles * 4,uiMaxParticles,
                    E3D_PrimitiveType::E3D_PT_QUADS,
                    MESH_FIELD_VERTEXS |
                    MESH_FIELD_UVCOORDS |
                    MESH_FIELD_COLORS |
                    MESH_FIELD_INDEXES);

    for ( uint i = 0; i < uiMaxParticles; i++ )
    {
        m_poMeshGeometry->m_pusIdx[i * 4 + 0] = i * 4 + 1;
        m_poMeshGeometry->m_pusIdx[i * 4 + 1] = i * 4 + 0;
        m_poMeshGeometry->m_pusIdx[i * 4 + 2] = i * 4 + 3;
        m_poMeshGeometry->m_pusIdx[i * 4 + 3] = i * 4 + 2;

        m_poMeshGeometry->m_poUV[i * 4 + 0].Set(0.0f,0.0f);
        m_poMeshGeometry->m_poUV[i * 4 + 1].Set(0.0f,1.0f);
        m_poMeshGeometry->m_poUV[i * 4 + 2].Set(1.0f,1.0f);
        m_poMeshGeometry->m_poUV[i * 4 + 3].Set(1.0f,0.0f);

        m_poMeshGeometry->m_poVX[i * 4 + 0].Set(0.0f,0.0f,10000.0f);
        m_poMeshGeometry->m_poVX[i * 4 + 1].Set(0.0f,0.0f,10000.0f);
        m_poMeshGeometry->m_poVX[i * 4 + 2].Set(0.0f,0.0f,10000.0f);
        m_poMeshGeometry->m_poVX[i * 4 + 3].Set(0.0f,0.0f,10000.0f);
    }
    
    m_poMesh = mNew CGUnmanagedMesh();
    m_poMesh->SetPrimitiveType(m_poMeshGeometry->eGetPrimitiveType());
    m_poMesh->m_poVX = m_poMeshGeometry->m_poVX;
    m_poMesh->m_poUV = m_poMeshGeometry->m_poUV;
    m_poMesh->m_poVX = m_poMeshGeometry->m_poVX;
    m_poMesh->m_poVC = m_poMeshGeometry->m_poVC;
    m_poMesh->m_pusIdx = m_poMeshGeometry->m_pusIdx;

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
CGParticleSystemInstance::~CGParticleSystemInstance()
{
    mDel m_poMeshGeometry;
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
    Update( CGRenderer::I()->oGetStats().m_fDelta);

    // Renders the geometry
    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->PushWorldMatrix();

    CGRenderer::I()->ClearCameraMatrix();
    CGRenderer::I()->ClearWorldMatrix();

    CGSCNVRenderer::I()->Render(m_poObj);

    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
}
// -----------------------------------------------------------------------------
