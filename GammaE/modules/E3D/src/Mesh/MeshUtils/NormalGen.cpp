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
#include "GammaE_Mem.h"
#include "NormalGen.h"
// ----------------------------------------------------------------------------

namespace MeshUtils {
// ----------------------------------------------------------------------------
CGVect3 ComputeVertexNormal(CGMesh &Mesh,CGVect3* pPNs,int iVX)
{
    CGVect3 Accum;
    uint uiNumFaces;
    uint uiNumVXPerFace;

    Accum.Set(0,0,0);
    uiNumFaces = 0;

    if ( Mesh.eGetPrimitiveType() == E3D_PT_TRIS ) uiNumVXPerFace = 3;
    else uiNumVXPerFace = 4;

    // Get the average of the normals of the faces from the vertex belongs
    for ( uint p = 0; p < Mesh.uiGetNumPrims(); p++ )
    {
        for ( uint v = 0; v < uiNumVXPerFace; v++ )
        {
            if ( Mesh.m_pusIdx[p * uiNumVXPerFace + v] == iVX )
            {
                Accum.Add(pPNs[p]);
                uiNumFaces++;
            }
        }
    }

    if ( uiNumFaces ) Accum.Scale(1.0f / (float)uiNumFaces);
    return (Accum);
}
// ----------------------------------------------------------------------------
void ComputePrimitiveNormals(CGMesh &Mesh)
{
    uint cPri;
    CGVect3 ab,cb,db,na,nb;
    CGVect3 VSum;

    CGVect3* pPNs;

    pPNs = mNew CGVect3[Mesh.uiGetNumPrims()];

    switch ( Mesh.eGetPrimitiveType() )
    {
        // --------------------------------
        // Compute triangle normal
        // --------------------------------
        case E3D_PT_TRIS:
        {
            for ( cPri = 0; cPri < Mesh.uiGetNumPrims(); cPri++ )
            {
                // Compute triangle normal
                pPNs[cPri].Normal(Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 3 + 0] ],
                                  Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 3 + 1] ],
                                  Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 3 + 2] ]);
                pPNs[cPri].Normalize();
            }
        }
        break;

        // --------------------------------
        // Compute quad normal
        // --------------------------------
        case E3D_PT_QUADS:
        {
            for ( cPri = 0; cPri < Mesh.uiGetNumPrims(); cPri++ )
            {
                // Get triagle segments
                ab.Assign(Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 4 + 0] ]);
                ab.Sub   (Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 4 + 1] ]);
                cb.Assign(Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 4 + 2] ]);
                cb.Sub   (Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 4 + 1] ]);
                db.Assign(Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 4 + 3] ]);
                db.Sub   (Mesh.m_poVX[ Mesh.m_pusIdx[cPri * 4 + 1] ]);

                // Compute quad normal
                na.CrossProd(ab,cb);

                pPNs[cPri].CrossProd(cb,db);
                pPNs[cPri].Add(na);
                pPNs[cPri].Scale(0.5);
                pPNs[cPri].Normalize();
            }
        }
        break;
    }

    Mesh.m_poTN = pPNs;
}
// ----------------------------------------------------------------------------
void ComputeNormals(CGMesh &Mesh)
{
    bool bErasePNs = (Mesh.m_poTN == NULL);

    // Compute primitive normals
    ComputePrimitiveNormals(Mesh);

    // --------------------------------
    // Compute vertexs normal
    // --------------------------------
    for ( uint cVert = 0; cVert < Mesh.uiGetNumVXs(); cVert++ )
        Mesh.m_poVN[cVert] = ComputeVertexNormal(Mesh,Mesh.m_poTN,cVert);

    if ( bErasePNs )
    {
        mDel [] Mesh.m_poTN;
        Mesh.m_poTN = NULL;
    }
}
// ----------------------------------------------------------------------------
}; // MeshUtils
// ----------------------------------------------------------------------------
