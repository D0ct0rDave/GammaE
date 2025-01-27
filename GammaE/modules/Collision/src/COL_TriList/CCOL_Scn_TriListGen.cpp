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
#include "COL_TriList\CCOL_Scn_TriListGen.h"
// -----------------------------------------------------------------------------
inline void TEST_Triangle(CGVect3* _poVXs,int _iTri,int &_iTris,CGMesh* _poMesh,int _iMat, CCOL_TriList& _oTriList,const CGVect3 &_oPos,float _fSqrRadius)
{
    CGTriangle oTri;
    float fSqrDist;

    if ( _poMesh->m_poTN )
        oTri.Init(_poVXs,_poMesh->m_poTN[_iTri]);
    else
    {
        oTri.Init(_poVXs);
        oTri.Normal.Normalize();
    }
    oTri.ComputeAll();

    fSqrDist = Math::fTriPointSqDistance(oTri,_oPos);
    if ( fSqrDist < _fSqrRadius )
    {
        _oTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,0.0f);
        _iTris++;
    }
}
// -----------------------------------------------------------------------------

int CCOL_Scn_TriListGen::GetTriList (CCOL_TriList& _oTriList, const CGVect3& _oPos, float _fRadius)
{
    if ( !iNumMeshes ) return(0);

    int iMesh;
    int iNumTris = 0;

    // Get triangles
    for ( iMesh = 0; ( (iMesh < iNumMeshes) && _oTriList.iFreeTris() ); iMesh++ )
        iNumTris += GetTrisFromMesh(_oTriList,poMeshes[iMesh],piMats[iMesh],_oPos,_fRadius);

    return(iNumTris);
}
// -----------------------------------------------------------------------------
int CCOL_Scn_TriListGen::GetTrisFromMesh (CCOL_TriList& _oTriList, CGMesh* _poMesh, int _iMat, const CGVect3& _oPos, float _fRadius)
{
    if ( !_oTriList.iFreeTris() ) return(0);

    int cTri;
    CGVect3 VXs[3];
    CGVect3* pVXs;
    int iTris = 0;
    float fSqRadius = _SQ_( _fRadius );

    switch ( _poMesh->eGetPrimitiveType())
    {
        case E3D_PrimitiveType::E3D_PT_NONE:         
        return(0);
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_TRIS:
        {
            for ( cTri = 0; ( (cTri < _poMesh->uiGetNumPrims()) && _oTriList.iFreeTris() ); cTri++ )
            {
                VXs[0].Assign( _poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 3 + 0] ]);
                VXs[1].Assign( _poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 3 + 1] ]);
                VXs[2].Assign( _poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 3 + 2] ]);

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
            }
        }
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_QUADS:
        {
            for ( cTri = 0; ( (cTri < _poMesh->uiGetNumPrims()) && (_oTriList.iFreeTris() > 2) ); cTri++ )
            {
                // First quad triangle
                VXs[0].Assign(_poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 4 + 0] ]);
                VXs[1].Assign(_poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 4 + 1] ]);
                VXs[2].Assign(_poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 4 + 3] ]);

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);

                // Second quad triangle
                VXs[0].Assign(_poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 4 + 1] ]);
                VXs[1].Assign(_poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 4 + 3] ]);
                VXs[2].Assign(_poMesh->m_poVX[ _poMesh->m_pusIdx[cTri * 4 + 2] ]);

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
            }
        }
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_TRIFANS:      
        return(0);
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_TRISTRIPS:    
        return(0);
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_QUADSTRIPS:   
        return(0);
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_NITRIS:
        {
            pVXs = _poMesh->m_poVX;
            for ( cTri = 0; ( (cTri < _poMesh->uiGetNumPrims()) && _oTriList.iFreeTris() ); cTri++ )
            {
                TEST_Triangle(pVXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);
                pVXs += 3;
            }
        }
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_NIQUADS:
        {
            for ( cTri = 0; ( (cTri < _poMesh->uiGetNumPrims()) && (_oTriList.iFreeTris() > 2) ); cTri++ )
            {
                // First quad triangle
                VXs[0].Assign( _poMesh->m_poVX[cTri * 4 + 0] );
                VXs[1].Assign( _poMesh->m_poVX[cTri * 4 + 1] );
                VXs[2].Assign( _poMesh->m_poVX[cTri * 4 + 3] );

                TEST_Triangle(VXs,cTri,iTris,_poMesh,_iMat,_oTriList,_oPos,fSqRadius);

                // Second quad triangle
                VXs[0].Assign( _poMesh->m_poVX[ cTri * 4 + 1 ] );
                VXs[1].Assign( _poMesh->m_poVX[ cTri * 4 + 3 ] );
                VXs[2].Assign( _poMesh->m_poVX[ cTri * 4 + 2 ] );

                TEST_Triangle(VXs, cTri, iTris, _poMesh, _iMat, _oTriList, _oPos, fSqRadius);
            }
        }
        break;
        // -------------------------------------------------------------------------------------
        case E3D_PrimitiveType::E3D_PT_NITRISTRIP:
        break;
    }

    return (iTris);
}
// -----------------------------------------------------------------------------
// Additional Declarations
