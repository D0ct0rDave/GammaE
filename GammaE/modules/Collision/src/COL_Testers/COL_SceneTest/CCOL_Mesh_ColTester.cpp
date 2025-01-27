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
// %X% %Q% %Z% %W%

// CCOL_Mesh_ColTester
#include "CCOL_Mesh_ColTester.h"

int CCOL_Mesh_ColTester::iTestCollision (CGMesh* _pMesh, CGGraphBV* _BVol, CCOL_TriList& _TriList)
{
    if ( !_pMesh ) return(0);
    if ( !_TriList.iFreeTris() ) return(0);

    int cTri;
    CGTriangle Tri;
    CGVect3 VXs[3];
    CGVect3 VN;
    CGVect3* pVXs;
    CGVect3* pVNs;
    float fSqDist;
    int iTris = 0;

    switch ( _pMesh->eGetPrimitiveType())
    {
        case E3D_PrimitiveType::E3D_PT_NONE:
            return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_TRIS:
        {
            for ( cTri = 0; ( (cTri < _pMesh->uiGetNumPrims()) && _TriList.iFreeTris() ); cTri++ )
            {
                VXs[0].Assign( _pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 3 + 0] ]);
                VXs[1].Assign( _pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 3 + 1] ]);
                VXs[2].Assign( _pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 3 + 2] ]);

                Tri.Init(VXs);
                Tri.ComputeAll();

                if (Math::bInRange(CCOL_DT_ColTester::fTestTriangle(_BVol, Tri), 0.0f, 1.0f))
                {
                    _TriList.iAddTri(Tri.VXs, Tri.Normal, 0, 0);
                    iTris++;
                }
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_QUADS:
        {
            for ( cTri = 0; ( (cTri < _pMesh->uiGetNumPrims()) && (_TriList.iFreeTris() > 2) ); cTri++ )
            {
                // First quad triangle
                VXs[0].Assign(_pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 4 + 0] ]);
                VXs[1].Assign(_pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 4 + 1] ]);
                VXs[2].Assign(_pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 4 + 3] ]);

                Tri.Init(VXs);
                Tri.ComputeAll();
                if (Math::bInRange(CCOL_DT_ColTester::fTestTriangle(_BVol,Tri), 0.0f, 1.0f))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal,0,0);
                    iTris++;
                }

                // Second quad triangle
                VXs[0].Assign(_pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 4 + 1] ]);
                VXs[1].Assign(_pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 4 + 3] ]);
                VXs[2].Assign(_pMesh->m_poVX[ _pMesh->m_pusIdx[cTri * 4 + 2] ]);

                Tri.Init(VXs);
                Tri.ComputeAll();
                if (Math::bInRange(CCOL_DT_ColTester::fTestTriangle(_BVol,Tri), 0.0f, 1.0f))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal,0,0);
                    iTris++;
                }
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_TRIFANS:     return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_TRISTRIPS:   return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_QUADSTRIPS:  return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_NITRIS:
        {
            pVXs = _pMesh->m_poVX;
            pVNs = _pMesh->m_poVN;
            for ( cTri = 0; ( (cTri < _pMesh->uiGetNumPrims()) && _TriList.iFreeTris() ); cTri++ )
            {
                Tri.Init(pVXs);
                Tri.ComputeAll();

                if (Math::bInRange(CCOL_DT_ColTester::fTestTriangle(_BVol,Tri), 0.0f, 1.0f))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal,0,0);
                    iTris++;
                }

                pVXs += 3;
                pVNs += 3;
            }
        }
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_NIQUADS:
        {
            for ( cTri = 0; ( (cTri < _pMesh->uiGetNumPrims()) && (_TriList.iFreeTris() > 2) ); cTri++ )
            {
                // First quad triangle
                VXs[0].Assign( _pMesh->m_poVX[cTri * 4 + 0] );
                VXs[1].Assign( _pMesh->m_poVX[cTri * 4 + 1] );
                VXs[2].Assign( _pMesh->m_poVX[cTri * 4 + 3] );

                Tri.Init(VXs);
                Tri.ComputeAll();

                if (Math::bInRange(CCOL_DT_ColTester::fTestTriangle(_BVol,Tri), 0.0f, 1.0f))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal,0,0);
                    iTris++;
                }

                // Second quad triangle
                VXs[0].Assign( _pMesh->m_poVX[ cTri * 4 + 1 ] );
                VXs[1].Assign( _pMesh->m_poVX[ cTri * 4 + 3 ] );
                VXs[2].Assign( _pMesh->m_poVX[ cTri * 4 + 2 ] );

                Tri.Init(VXs);
                Tri.ComputeAll();
                if (Math::bInRange(CCOL_DT_ColTester::fTestTriangle(_BVol,Tri), 0.0f, 1.0f))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal,0,0);
                    iTris++;
                }
            }
        }
        break;


        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_NITRISTRIP:
        break;
    }

    return (iTris);
}

// Additional Declarations
