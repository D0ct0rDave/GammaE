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

// Class CCOL_Mesh_ColTester

CCOL_Mesh_ColTester::CCOL_Mesh_ColTester()
{
}

CCOL_Mesh_ColTester::~CCOL_Mesh_ColTester()
{
}

int CCOL_Mesh_ColTester::iTestCollision (CGMesh* _pMesh, CGBoundingVolume* _BVol, CCOL_TriList& _TriList)
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

    switch ( _pMesh>eMeshType )
    {
        case E3D_MESH_NONE:         
            return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_TRIS:
        {
            for ( cTri = 0; ( (cTri < _pMesh->usNumPrims) && _TriList.iFreeTris() ); cTri++ )
            {
                VXs[0].Assign( _pMesh->VXs[ _pMesh->Idxs[cTri * 3 + 0] ]);
                VXs[1].Assign( _pMesh->VXs[ _pMesh->Idxs[cTri * 3 + 1] ]);
                VXs[2].Assign( _pMesh->VXs[ _pMesh->Idxs[cTri * 3 + 2] ]);

                Tri.Init(VXs);
                Tri.ComputeAll();

                if ( CCOL_DT_ColTester::iTestTriangle(_BVol,Tri) )
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iTris++;
                }
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_QUADS:
        {
            for ( cTri = 0; ( (cTri < _pMesh->usNumPrims) && (_TriList.iFreeTris() > 2) ); cTri++ )
            {
                // First quad triangle
                VXs[0].Assign(_pMesh->VXs[ _pMesh->Idxs[cTri * 4 + 0] ]);
                VXs[1].Assign(_pMesh->VXs[ _pMesh->Idxs[cTri * 4 + 1] ]);
                VXs[2].Assign(_pMesh->VXs[ _pMesh->Idxs[cTri * 4 + 3] ]);

                Tri.Init(VXs);
                Tri.ComputeAll();
                if ( CCOL_DT_ColTester::iTestTriangle(_BVol,Tri) )
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iTris++;
                }

                // Second quad triangle
                VXs[0].Assign(_pMesh->VXs[ _pMesh->Idxs[cTri * 4 + 1] ]);
                VXs[1].Assign(_pMesh->VXs[ _pMesh->Idxs[cTri * 4 + 3] ]);
                VXs[2].Assign(_pMesh->VXs[ _pMesh->Idxs[cTri * 4 + 2] ]);

                Tri.Init(VXs);
                Tri.ComputeAll();
                if ( CCOL_DT_ColTester::iTestTriangle(_BVol,Tri) )
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iTris++;
                }
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_TRIFANS:      return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_TRISTRIPS:    return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_QUADSTRIPS:   return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_NITRIS:
        {
            pVXs = _pMesh->VXs;
            pVNs = _pMesh->VNs;
            for ( cTri = 0; ( (cTri < _pMesh->usNumPrims) && _TriList.iFreeTris() ); cTri++ )
            {
                Tri.Init(pVXs);
                Tri.ComputeAll();

                if ( CCOL_DT_ColTester::iTestTriangle(_BVol,Tri) )
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iTris++;
                }

                pVXs += 3;
                pVNs += 3;
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_NIQUADS:
        {
            for ( cTri = 0; ( (cTri < _pMesh->usNumPrims) && (_TriList.iFreeTris() > 2) ); cTri++ )
            {
                // First quad triangle
                VXs[0].Assign( _pMesh->VXs[cTri * 4 + 0] );
                VXs[1].Assign( _pMesh->VXs[cTri * 4 + 1] );
                VXs[2].Assign( _pMesh->VXs[cTri * 4 + 3] );

                Tri.Init(VXs);
                Tri.ComputeAll();

                if ( CCOL_DT_ColTester::iTestTriangle(_BVol,Tri) )
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iTris++;
                }

                // Second quad triangle
                VXs[0].Assign( _pMesh->VXs[ cTri * 4 + 1 ] );
                VXs[1].Assign( _pMesh->VXs[ cTri * 4 + 3 ] );
                VXs[2].Assign( _pMesh->VXs[ cTri * 4 + 2 ] );

                Tri.Init(VXs);
                Tri.ComputeAll();
                if ( CCOL_DT_ColTester::iTestTriangle(_BVol,Tri) )
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iTris++;
                }
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_NITRISTRIP:
        break;
    }

    return (iTris);
}

// Additional Declarations
