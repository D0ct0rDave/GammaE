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

// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_MT_CommonMesh
#include "COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_CommonMesh.h"

inline void TEST_Triangle(CVect3* _poVXs,CVect3* _poVN,int &_iTris,int _iMat,CGraphBV* _poBVol, CCOL_TriList& _oTriList)
{
    CTriangle oTri;
    float fTime;

    if ( _poVN )
        oTri.Init(_poVXs,*_poVN);
    else
    {
        oTri.Init(_poVXs);
        oTri.Normal.Normalize();
    }
    oTri.ComputeAll();

    fTime = CCOL_DT_ColTester::fTestTriangle(_poBVol,oTri);
    if ( fTime >= 0.0f )
    {
        _oTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,fTime);
        _iTris++;
    }
}

// Class CCOL_MT_CommonMesh

CCOL_MT_CommonMesh::CCOL_MT_CommonMesh()
{
}

CCOL_MT_CommonMesh::~CCOL_MT_CommonMesh()
{
}

int CCOL_MT_CommonMesh::iTestCollision (CGMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _oTriList)
{
    if ( !_poMesh ) return(0);
    if ( !_oTriList.iFreeTris() ) return(0);

    int cTri;
    CTriangle Tri;
    CVect3 VXs[3];
    CVect3 VN;
    CVect3* pVXs;
    float fSqDist;
    int iTris = 0;
    float fTime;
    int i0,i1,i2;

    switch ( _poMesh->m_eMeshType )
    {
        case E3D_MESH_NONE:         return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_TRIS:
        {
            for ( cTri = 0; ( (cTri < _poMesh->m_uiNumPrims) && _oTriList.iFreeTris() ); cTri++ )
            {
                i0 = _poMesh->m_pusIdx[cTri * 3 + 0];
                i1 = _poMesh->m_pusIdx[cTri * 3 + 1];
                i2 = _poMesh->m_pusIdx[cTri * 3 + 2];

                // -----------------------------
                VXs[0].Assign( _poMesh->m_poVX[ i0 ]);
                VXs[1].Assign( _poMesh->m_poVX[ i1 ]);
                VXs[2].Assign( _poMesh->m_poVX[ i2 ]);

                if ( _poMesh->m_poTN )
                {
                    TEST_Triangle(VXs,&_poMesh->m_poTN[cTri],iTris,_iMat,_poBVol,_oTriList);
                }
                /*
                   else if (_poMesh->VNs)
                    {
                        VN.Assign( _poMesh->VNs[ i0 ] );
                        VN.Add   ( _poMesh->VNs[ i1 ] );
                        VN.Add   ( _poMesh->VNs[ i2 ] );
                        VN.Scale ( 1.0f / 3.0f);

                        TEST_Triangle(VXs,&VN,iTris,_iMat,_poBVol,_oTriList);
                    }
                 */
                else
                    TEST_Triangle(VXs,NULL,iTris,_iMat,_poBVol,_oTriList);
                // -----------------------------
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_QUADS:
        {
            /*
               for (cTri=0;((cTri<_poMesh->usNumPrims) && (_oTriList.iFreeTris()>2));cTri++)
               {
                // First quad triangle
                VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+0] ]);
                VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
                VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_oTriList);

                // Second quad triangle
                VXs[0].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+1] ]);
                VXs[1].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+3] ]);
                VXs[2].Assign(_poMesh->VXs[ _poMesh->Idxs[cTri*4+2] ]);

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_oTriList);
               }
             */
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_TRIFANS:      return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_TRISTRIPS:
        {
            for ( cTri = 0; ( (cTri < _poMesh->m_uiNumPrims) && _oTriList.iFreeTris() ); cTri++ )
            {
                i0 = _poMesh->m_pusIdx[cTri  ];
                i1 = _poMesh->m_pusIdx[cTri + 1];
                i2 = _poMesh->m_pusIdx[cTri + 2];

                // -----------------------------
                VXs[0].Assign( _poMesh->m_poVX[i0]);
                VXs[1].Assign( _poMesh->m_poVX[i1]);
                VXs[2].Assign( _poMesh->m_poVX[i2]);

                if ( _poMesh->m_poTN )
                {
                    TEST_Triangle(VXs,&_poMesh->m_poTN[cTri],iTris,_iMat,_poBVol,_oTriList);
                }
                /*
                   else if (_poMesh->VNs)
                    {
                        VN.Assign( _poMesh->VNs[i0] );
                        VN.Add   ( _poMesh->VNs[i1] );
                        VN.Add   ( _poMesh->VNs[i2] );
                        VN.Scale (1.0f / 3.0f);

                        TEST_Triangle(VXs,&VN,iTris,_iMat,_poBVol,_oTriList);
                    }
                 */
                else
                    TEST_Triangle(VXs,NULL,iTris,_iMat,_poBVol,_oTriList);
                // -----------------------------
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_QUADSTRIPS:   return(0);
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_NITRIS:
        {
            for ( cTri = 0; ( (cTri < _poMesh->m_uiNumPrims) && _oTriList.iFreeTris() ); cTri++ )
            {
                i0 = cTri * 3 + 0;
                i1 = cTri * 3 + 1;
                i2 = cTri * 3 + 2;

                // -----------------------------
                VXs[0].Assign( _poMesh->m_poVX[i0]);
                VXs[1].Assign( _poMesh->m_poVX[i1]);
                VXs[2].Assign( _poMesh->m_poVX[i2]);

                if ( _poMesh->m_poTN )
                {
                    TEST_Triangle(VXs,&_poMesh->m_poTN[cTri],iTris,_iMat,_poBVol,_oTriList);
                }
                /*
                   else if (_poMesh->VNs)
                    {
                        VN.Assign( _poMesh->VNs[i0] );
                        VN.Add   ( _poMesh->VNs[i1] );
                        VN.Add   ( _poMesh->VNs[i2] );
                        VN.Scale (1.0f / 3.0f);

                        TEST_Triangle(VXs,&VN,iTris,_iMat,_poBVol,_oTriList);
                    }
                 */
                else
                    TEST_Triangle(VXs,NULL,iTris,_iMat,_poBVol,_oTriList);
                // -----------------------------
            }
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_NIQUADS:
        {
            /*
               for (cTri=0;((cTri<_poMesh->usNumPrims) && (_oTriList.iFreeTris()>2));cTri++)
               {
                // First quad triangle
                VXs[0].Assign( _poMesh->VXs[cTri*4+0] );
                VXs[1].Assign( _poMesh->VXs[cTri*4+1] );
                VXs[2].Assign( _poMesh->VXs[cTri*4+3] );

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_oTriList);

                // Second quad triangle
                VXs[0].Assign( _poMesh->VXs[ cTri*4+1 ] );
                VXs[1].Assign( _poMesh->VXs[ cTri*4+3 ] );
                VXs[2].Assign( _poMesh->VXs[ cTri*4+2 ] );

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_poBVol,_oTriList);
               }
             */
        }
        break;

        // -------------------------------------------------------------------------------------
        case E3D_MESH_NITRISTRIP:

        for ( cTri = 0; ( (cTri < _poMesh->m_uiNumPrims) && _oTriList.iFreeTris() ); cTri++ )
        {
            i0 = cTri;
            i1 = cTri + 1;
            i2 = cTri + 2;

            // -----------------------------
            VXs[0].Assign( _poMesh->m_poVX[i0]);
            VXs[1].Assign( _poMesh->m_poVX[i1]);
            VXs[2].Assign( _poMesh->m_poVX[i2]);

            if ( _poMesh->m_poTN )
            {
                TEST_Triangle(VXs,&_poMesh->m_poTN[cTri],iTris,_iMat,_poBVol,_oTriList);
            }
            /*
               else if (_poMesh->VNs)
                {
                    VN.Assign( _poMesh->VNs[i0] );
                    VN.Add   ( _poMesh->VNs[i1] );
                    VN.Add   ( _poMesh->VNs[i2] );
                    VN.Scale (1.0f / 3.0f);

                    TEST_Triangle(VXs,&VN,iTris,_iMat,_poBVol,_oTriList);
                }
             */
            else
                TEST_Triangle(VXs,NULL,iTris,_iMat,_poBVol,_oTriList);
            // -----------------------------
        }

        break;
    }

    return (iTris);
}

// Additional Declarations
