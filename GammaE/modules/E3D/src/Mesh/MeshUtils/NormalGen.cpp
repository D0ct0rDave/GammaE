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
#include <assert.h>
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
const CGVect3& ComputeVertexNormal(const CGMesh& _oMesh,CGVect3* _poPNs, uint _uiVX)
{
    CGVect3 oAccum;
    uint uiNumFaces;
    uint uiNumVXPerFace;

    oAccum.Set(0,0,0);
    uiNumFaces = 0;

    if ( _oMesh.eGetPrimitiveType() == E3D_PT_TRIS ) uiNumVXPerFace = 3;
    else uiNumVXPerFace = 4;

    // Get the average of the normals of the faces from the vertex belongs
    for ( uint p = 0; p < _oMesh.uiGetNumPrims(); p++ )
    {
        for ( uint v = 0; v < uiNumVXPerFace; v++ )
        {
            if ( _oMesh.m_pusIdx[p * uiNumVXPerFace + v] == _uiVX )
            {
                oAccum.Add(_poPNs[p]);
                uiNumFaces++;
            }
        }
    }

    if ( uiNumFaces ) oAccum.Scale(1.0f / (float)uiNumFaces);
    return (oAccum);
}
// ----------------------------------------------------------------------------
void ComputePrimitiveNormals(CGMesh &_oMesh)
{
    if (_oMesh.m_poTN != NULL)
    {
        mDel _oMesh.m_poTN;
    }

    CGVect3* pPNs = mNew CGVect3[_oMesh.uiGetNumPrims()];
    switch ( _oMesh.eGetPrimitiveType() )
    {
        // --------------------------------
        // Compute triangle normal
        // --------------------------------
        case E3D_PT_TRIS:
        {
            for (uint cPri = 0; cPri < _oMesh.uiGetNumPrims(); cPri++ )
            {
                // Compute triangle normal
                pPNs[cPri].Normal(_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 3 + 0] ],
                                  _oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 3 + 1] ],
                                  _oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 3 + 2] ]);
                pPNs[cPri].Normalize();
            }
        }
        break;

        // --------------------------------
        // Compute quad normal
        // --------------------------------
        case E3D_PT_QUADS:
        {
            CGVect3 ab, cb, db, na, nb;

            for (uint cPri = 0; cPri < _oMesh.uiGetNumPrims(); cPri++ )
            {
                // Get triagle segments
                ab.Assign(_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 4 + 0] ]);
                ab.Sub   (_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 4 + 1] ]);
                cb.Assign(_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 4 + 2] ]);
                cb.Sub   (_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 4 + 1] ]);
                db.Assign(_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 4 + 3] ]);
                db.Sub   (_oMesh.m_poVX[ _oMesh.m_pusIdx[cPri * 4 + 1] ]);

                // Compute quad normal
                na.CrossProd(ab,cb);

                pPNs[cPri].CrossProd(cb,db);
                pPNs[cPri].Add(na);
                pPNs[cPri].Scale(0.5);
                pPNs[cPri].Normalize();
            }
        }
        break;

        default:
        assert(false && "Warning Not Implemented");
        break;
    }

    _oMesh.m_poTN = pPNs;
}
// ----------------------------------------------------------------------------
void ComputeVertexNormals(CGMesh &_oMesh)
{
    bool bDeletePNs = (_oMesh.m_poTN == NULL);

    // Compute primitive normals
    ComputePrimitiveNormals(_oMesh);

    // --------------------------------
    // Compute vertexs normal
    // --------------------------------
    for ( uint cVert = 0; cVert < _oMesh.uiGetNumVXs(); cVert++ )
        _oMesh.m_poVN[cVert] = ComputeVertexNormal(_oMesh,_oMesh.m_poTN,cVert);

    if (bDeletePNs)
    {
        mDel [] _oMesh.m_poTN;
        _oMesh.m_poTN = NULL;
    }
}
// ----------------------------------------------------------------------------
}; // MeshUtils
// ----------------------------------------------------------------------------
