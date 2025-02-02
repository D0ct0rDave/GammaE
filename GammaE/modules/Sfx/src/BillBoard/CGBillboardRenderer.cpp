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
#include "CGBillboardRenderer.h"

// ----------------------------------------------------------------------------
CGBillboardRenderer::CGBillboardRenderer(uint _uiMaxShaders,uint _uiMaxBillboards)
{
    // Create the geometry that will store the billboards
    m_oGeoPool.Init(_uiMaxBillboards * 4,
                    _uiMaxBillboards,
                    E3D_PrimitiveType::E3D_PT_NIQUADS,
                    MESH_FIELD_VERTEXS
                    | MESH_FIELD_UVCOORDS
                    | MESH_FIELD_COLORS );

    // Initialize the list of billboards ordered by shader
    m_oBBRL.Init(_uiMaxShaders);

    // Initialize the pool of meshes
    m_oMeshes.Init(_uiMaxShaders);

    // Create the pool of billboards
    m_oBBPool.Init(_uiMaxBillboards);
}
// ----------------------------------------------------------------------------
void CGBillboardRenderer::Reset()
{
    m_oBBRL.Clear();
    m_oBBPool.Clear();
}
// ----------------------------------------------------------------------------
void CGBillboardRenderer::Begin(CGShader* _poShader)
{
    // Look for the shader on the array
    for ( uint i = 0; i < m_oBBRL.uiNumElems(); i++ )
    {
        if ( m_oBBRL[i].m_poShader == _poShader )
        {
            m_uiCurList = i;
            return;
        }
    }

    // / WARNING: Sanity checks here!!!

    // Insert a new list
    CGBBRListNode oNode;
    oNode.m_poFirst = NULL;
    oNode.m_poShader = _poShader;

    m_uiCurList = m_oBBRL.iAdd(oNode);
}
// ----------------------------------------------------------------------------
void CGBillboardRenderer::AddBillboards(CGVect3* _poVX,CGVect2* _poUV,CGColor* _poVC,uint _uiNumBillboards)
{
    // / WARNING: Sanity checks here!!!
    for ( uint i = 0; i < _uiNumBillboards; i++ )
    {
        // Get a free billboard from the pool
        CGBillboardNode& oBB = m_oBBPool.oGet();

        oBB.m_oVX[0] = _poVX[0];
        oBB.m_oVX[1] = _poVX[1];
        oBB.m_oVX[2] = _poVX[2];
        oBB.m_oVX[3] = _poVX[3];

        oBB.m_oUV[0] = _poUV[0];
        oBB.m_oUV[1] = _poUV[1];
        oBB.m_oUV[2] = _poUV[2];
        oBB.m_oUV[3] = _poUV[3];

        oBB.m_oVC[0] = _poVC[0];
        oBB.m_oVC[1] = _poVC[1];
        oBB.m_oVC[2] = _poVC[2];
        oBB.m_oVC[3] = _poVC[3];

        // Add billboard to the list
        if ( m_oBBRL[m_uiCurList].m_poFirst == NULL )
        {
            m_oBBRL[m_uiCurList].m_poFirst = &oBB;
            oBB.m_poNext = NULL;
        }
        else
        {
            oBB.m_poNext = m_oBBRL[m_uiCurList].m_poFirst;
            m_oBBRL[m_uiCurList].m_poFirst = &oBB;
        }

        // Next billboard from input
        _poVX += 4;
        _poUV += 4;
        _poVC += 4;
    }
}
// ----------------------------------------------------------------------------
void CGBillboardRenderer::End()
{
}
// ----------------------------------------------------------------------------
void CGBillboardRenderer::Render()
{
    // Renders the geometry
    CGRenderer::I()->PushCameraMatrix();
    CGRenderer::I()->PushWorldMatrix();

    CGRenderer::I()->ClearCameraMatrix();
    CGRenderer::I()->ClearWorldMatrix();

    // Reset the mesh pool
    m_oMeshes.Clear();

    // Build the meshes
    CGVect3* poVX = m_oGeoPool.m_poVX;
    CGVect2* poUV = m_oGeoPool.m_poUV;
    CGColor* poVC = m_oGeoPool.m_poVC;

    for ( uint j = 0; j < m_oBBRL.uiNumElems(); j++ )
    {
        CGUnmanagedMesh& oMesh = m_oMeshes.oGet();

        oMesh.SetPrimitiveType(m_oGeoPool.eGetPrimitiveType());
        oMesh.m_poVX = poVX;
        oMesh.m_poUV = poUV;
        oMesh.m_poVC = poVC;

        //
        CGBillboardNode* poBB = m_oBBRL[j].m_poFirst;
        uint uiNumBBs = 0;
        while ( poBB )
        {
            poVX[0] = poBB->m_oVX[0];
            poVX[1] = poBB->m_oVX[1];
            poVX[2] = poBB->m_oVX[2];
            poVX[3] = poBB->m_oVX[3];

            poUV[0] = poBB->m_oUV[0];
            poUV[1] = poBB->m_oUV[1];
            poUV[2] = poBB->m_oUV[2];
            poUV[3] = poBB->m_oUV[3];

            poVC[0] = poBB->m_oVC[0];
            poVC[1] = poBB->m_oVC[1];
            poVC[2] = poBB->m_oVC[2];
            poVC[3] = poBB->m_oVC[3];

            poVX += 4;
            poUV += 4;
            poVC += 4;

            uiNumBBs++;

            // Next BB
            poBB = poBB->m_poNext;
        }

        if ( uiNumBBs > 0 )
        {
            oMesh.SetNumVXs(uiNumBBs * 4);
            oMesh.SetNumPrims(uiNumBBs);

            // Render the recently built mesh
            CGRenderer::I()->RenderMesh(&oMesh,m_oBBRL[j].m_poShader);
        }
    }

    CGRenderer::I()->PopWorldMatrix();
    CGRenderer::I()->PopCameraMatrix();
}
// ----------------------------------------------------------------------------
