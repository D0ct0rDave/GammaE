// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "TransformMesh.h"
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
void TranslateMesh(CGMesh &Mesh,CGVect3 &T)
{
    uint cV;
    if ( Mesh.m_poVX )
    {
        for ( cV = 0; cV < Mesh.uiGetNumVXs(); cV++ ) Mesh.m_poVX[cV].Add(T);
    }
}
// ----------------------------------------------------------------------------
void ScaleMesh(CGMesh &Mesh,CGVect3 &S)
{
    uint cV;

    if ( Mesh.m_poVX )
    {
        // Transform vertexs
        for ( cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
        {
            Mesh.m_poVX[cV].x *= S.x;
            Mesh.m_poVX[cV].y *= S.y;
            Mesh.m_poVX[cV].z *= S.z;
        }
    }
}
// ----------------------------------------------------------------------------
void RotateMesh(CGMesh &Mesh,CGVect3 &R,float _fAngle)
{
    uint cV;
    CGMatrix4x4 M;

    M.LoadIdentity();
    M.RotateFromArbitraryAxis(R.x,R.y,R.z,_fAngle);

    // Transform vertexs
    if ( Mesh.m_poVX )
        for ( cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
            M.TransformPoint(&Mesh.m_poVX[cV]);

    // Transform vertexs normals
    if ( Mesh.m_poVN )
        for ( cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
            M.TransformVector(&Mesh.m_poVN[cV]);
}
// ----------------------------------------------------------------------------
void TransformMesh(CGMesh &Mesh,CGMatrix4x4 &M)
{
    uint cV;

    // Transform vertexs
    if ( Mesh.m_poVX )
        for ( cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
            M.TransformPoint(&Mesh.m_poVX[cV]);

    // Transform vertexs normals
    if ( Mesh.m_poVN )
        for ( cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
            M.TransformVector(&Mesh.m_poVN[cV]);
}
// ----------------------------------------------------------------------------
}; // MeshUtils
// ----------------------------------------------------------------------------
