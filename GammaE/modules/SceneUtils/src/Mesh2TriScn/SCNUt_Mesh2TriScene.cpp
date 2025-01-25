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
#include "GammaE_Mem.h"

// SCNUt_Mesh2TriScene
#include "Mesh2TriScn\SCNUt_Mesh2TriScene.h"

// Class SCNUt_Mesh2TriScene

SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene()
{
}

SCNUt_Mesh2TriScene::~SCNUt_Mesh2TriScene()
{
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate (CGMesh& _oMesh, int _iMat)
{
    switch ( _oMesh.eGetPrimitiveType() )
    {
        case E3D_PrimitiveType::E3D_PT_NONE:
        {
            return(NULL);
        }
        break;

        case E3D_PrimitiveType::E3D_PT_NITRIS:
        {
            return( Generate_FromIndexedTriMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_NIQUADS:
        {
            return( Generate_FromIndexedQuadMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_TRIFANS:
        {
            return( Generate_FromIndexedTriFanMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_TRISTRIPS:
        {
            return( Generate_FromIndexedTriStripMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_QUADSTRIPS:
        {
            return( Generate_FromIndexedQuadStripMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_NITRIS:
        {
            return( Generate_FromNonIndexedTriMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_NIQUADS:
        {
            return( Generate_FromNonIndexedQuadMesh(_oMesh,_iMat) );
        }
        break;

        case E3D_PrimitiveType::E3D_PT_NITRISTRIP:
        {
            return( Generate_FromNonIndexedTriStripMesh(_oMesh,_iMat) );
        }
        break;

        default:
        return(NULL);
    }
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriMesh (CGMesh& _oMesh, int _iMat)
{
    if ( !_oMesh.m_pusIdx ) return(NULL);

    if ( (!_oMesh.m_poVX) &&
        (!_oMesh.m_poVC) &&
        (!_oMesh.m_poVN) &&
        (!_oMesh.m_poUV) ) return(NULL);

    CGVect3 oDefVX(0.0f,0.0f,0.0f);
    CGVect3 oDefVN(0.0f,0.0f,1.0f);
    CGVect4 oDefVC(1.0f,1.0f,1.0f,1.0f);
    CGVect2 oDefUV(0.0f,0.0f);

    CGVect3 oCurVX;
    CGVect3 oCurVN;
    CGVect4 oCurVC;
    CGVect2 oCurUV;

    int iTri,iIdx,iVert;
    SCNUt_TriScene* poTriScn = mNew SCNUt_TriScene;
    poTriScn->Init(_oMesh.m_uiNumPrims);

    for ( iTri = 0; iTri < _oMesh.m_uiNumPrims; iTri++ )
    {
        for ( iVert = 0; iVert < 3; iVert++ )
        {
            iIdx = _oMesh.m_pusIdx[ iTri * 3 + iVert ];

            // Vertex
            if ( _oMesh.m_poVX )
                oCurVX.Assign( _oMesh.m_poVX[iIdx] );
            else
                oCurVX.Assign(oDefVX);

            // Normal
            if ( _oMesh.m_poVN )
                oCurVN.Assign( _oMesh.m_poVN[iIdx] );
            else
                oCurVN.Assign(oDefVN);

            // Color
            if ( _oMesh.m_poVC )
                oCurVC.Assign( *(CGVect4*)&_oMesh.m_poVC[iIdx] );
            else
                oCurVC.Assign(oDefVC);

            // TexCoord
            if ( _oMesh.m_poUV )
                oCurUV.Assign( _oMesh.m_poUV[iIdx] );
            else
                oCurUV.Assign(oDefUV);

            // --------------------------------------------
            // Setup triangle
            // --------------------------------------------
            poTriScn->Tris[iTri].VXs[iVert].Assign(oCurVX);
            poTriScn->Tris[iTri].VNs[iVert].Assign(oCurVN);
            poTriScn->Tris[iTri].VCs[iVert].Assign(oCurVC);
            poTriScn->Tris[iTri].UVs[iVert].Assign(oCurUV);
            poTriScn->Tris[iTri].Material = _iMat;
        }
    }
    return(poTriScn);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedQuadMesh (CGMesh& _oMesh, int _iMat)
{
    return(NULL);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriStripMesh (CGMesh& _oMesh, int _iMat)
{
    if ( !_oMesh.m_pusIdx ) return(NULL);

    if ( (!_oMesh.m_poVX) &&
        (!_oMesh.m_poVC) &&
        (!_oMesh.m_poVN) &&
        (!_oMesh.m_poUV) ) return(NULL);

    CGVect3 oDefVX(0.0f,0.0f,0.0f);
    CGVect3 oDefVN(0.0f,0.0f,1.0f);
    CGVect4 oDefVC(1.0f,1.0f,1.0f,1.0f);
    CGVect2 oDefUV(0.0f,0.0f);

    CGVect3 oCurVX;
    CGVect3 oCurVN;
    CGVect4 oCurVC;
    CGVect2 oCurUV;

    CGVect3 oVX[3];
    CGVect3 oVN[3];
    CGVect4 oVC[3];
    CGVect2 oUV[3];

    SCNUt_TriScene* poTriScn = mNew SCNUt_TriScene;
    poTriScn->Init( _oMesh.m_uiNumPrims );

    for ( uint i = 0; i < _oMesh.m_uiNumIdxs; i++ )
    {
        int iIdx = _oMesh.m_pusIdx[ i ];

        // Vertex
        if ( _oMesh.m_poVX )
            oCurVX.Assign( _oMesh.m_poVX[iIdx] );
        else
            oCurVX.Assign(oDefVX);

        // Normal
        if ( _oMesh.m_poVN )
            oCurVN.Assign( _oMesh.m_poVN[iIdx] );
        else
            oCurVN.Assign(oDefVN);

        // Color
        if ( _oMesh.m_poVC )
            oCurVC.Assign( *(CGVect4*)&_oMesh.m_poVC[iIdx] );
        else
            oCurVC.Assign(oDefVC);

        // TexCoord
        if ( _oMesh.m_poUV )
            oCurUV.Assign( _oMesh.m_poUV[iIdx] );
        else
            oCurUV.Assign(oDefUV);

        // Vertex 0 is swapped with previous iteration Vertex 1
        // Vertex 1 is swapped with previous iteration Vertex 2
        // Vertex 2 is always updated with new info

        if ( i < 3 )
        {
            // for the vertex 0 and 1
            oVX[i].Assign(oCurVX);
            oVN[i].Assign(oCurVN);
            oVC[i].Assign(oCurVC);
            oUV[i].Assign(oCurUV);
        }
        else
        {
            // Arrange vertices: Control winding
            oVX[0].Assign(oVX[1]);
            oVN[0].Assign(oVN[1]);
            oVC[0].Assign(oVC[1]);
            oUV[0].Assign(oUV[1]);

            oVX[1].Assign(oVX[2]);
            oVN[1].Assign(oVN[2]);
            oVC[1].Assign(oVC[2]);
            oUV[1].Assign(oUV[2]);

            // Last vertex is always the current vertex
            oVX[2].Assign(oCurVX);
            oVN[2].Assign(oCurVN);
            oVC[2].Assign(oCurVC);
            oUV[2].Assign(oCurUV);
        }

        if ( i >= 2 )
        {
            // --------------------------------------------
            // Setup triangle: only when 3 or more processed vertices
            // --------------------------------------------
            for ( uint uiVert = 0; uiVert < 3; uiVert++ )
            {
                uint uiTri = i - 2;

                if ( (uiTri & 0x01) == 0 )
                {
                    poTriScn->Tris[uiTri].VXs[uiVert].Assign(oVX[uiVert]);
                    poTriScn->Tris[uiTri].VNs[uiVert].Assign(oVN[uiVert]);
                    poTriScn->Tris[uiTri].VCs[uiVert].Assign(oVC[uiVert]);
                    poTriScn->Tris[uiTri].UVs[uiVert].Assign(oUV[uiVert]);
                    poTriScn->Tris[uiTri].Material = _iMat;
                }
                else
                {
                    poTriScn->Tris[uiTri].VXs[uiVert].Assign(oVX[2 - uiVert]);
                    poTriScn->Tris[uiTri].VNs[uiVert].Assign(oVN[2 - uiVert]);
                    poTriScn->Tris[uiTri].VCs[uiVert].Assign(oVC[2 - uiVert]);
                    poTriScn->Tris[uiTri].UVs[uiVert].Assign(oUV[2 - uiVert]);
                    poTriScn->Tris[uiTri].Material = _iMat;
                }
            }
        }
    }

    return(poTriScn);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriFanMesh (CGMesh& _oMesh, int _iMat)
{
    if ( !_oMesh.m_pusIdx ) return(NULL);

    if ( (!_oMesh.m_poVX) &&
        (!_oMesh.m_poVC) &&
        (!_oMesh.m_poVN) &&
        (!_oMesh.m_poUV) ) return(NULL);

    CGVect3 oDefVX(0.0f,0.0f,0.0f);
    CGVect3 oDefVN(0.0f,0.0f,1.0f);
    CGVect4 oDefVC(1.0f,1.0f,1.0f,1.0f);
    CGVect2 oDefUV(0.0f,0.0f);

    CGVect3 oCurVX;
    CGVect3 oCurVN;
    CGVect4 oCurVC;
    CGVect2 oCurUV;

    CGVect3 oVX[3];
    CGVect3 oVN[3];
    CGVect4 oVC[3];
    CGVect2 oUV[3];

    int iTri,iIdx,iVert;
    SCNUt_TriScene* poTriScn = mNew SCNUt_TriScene;
    poTriScn->Init( _oMesh.m_uiNumPrims );

    for ( iTri = 0; iTri < _oMesh.m_uiNumIdxs; iTri++ )
    {
        iIdx = _oMesh.m_pusIdx[ iTri ];

        // Vertex
        if ( _oMesh.m_poVX )
            oCurVX.Assign( _oMesh.m_poVX[iIdx] );
        else
            oCurVX.Assign(oDefVX);

        // Normal
        if ( _oMesh.m_poVN )
            oCurVN.Assign( _oMesh.m_poVN[iIdx] );
        else
            oCurVN.Assign(oDefVN);

        // Color
        if ( _oMesh.m_poVC )
            oCurVC.Assign( *(CGVect4*)&_oMesh.m_poVC[iIdx] );
        else
            oCurVC.Assign(oDefVC);

        // TexCoord
        if ( _oMesh.m_poUV )
            oCurUV.Assign( _oMesh.m_poUV[iIdx] );
        else
            oCurUV.Assign(oDefUV);

        // Vertex 0 is maintained throught all the mesh
        // Vertex 1 is swaped with previous iteration Vertex 2
        // Vertex 2 is always updated with new info

        if ( iTri < 3 )
        {
            // for the vertex 0 and 1
            oVX[iTri].Assign(oCurVX);
            oVN[iTri].Assign(oCurVN);
            oVC[iTri].Assign(oCurVC);
            oUV[iTri].Assign(oCurUV);
        }
        else
        {
            if ( iTri > 3 )
            {
                oVX[1].Assign(oVX[2]);
                oVN[1].Assign(oVN[2]);
                oVC[1].Assign(oVC[2]);
                oUV[1].Assign(oUV[2]);
            }

            // Last vertex is always the current vertex
            oVX[2].Assign(oCurVX);
            oVN[2].Assign(oCurVN);
            oVC[2].Assign(oCurVC);
            oUV[2].Assign(oCurUV);

            // --------------------------------------------
            // Setup triangle: only when 3 or more processed vertices
            // --------------------------------------------
            for ( iVert = 0; iVert < 3; iVert++ )
            {
                poTriScn->Tris[iTri].VXs[iVert].Assign(oVX[iVert]);
                poTriScn->Tris[iTri].VNs[iVert].Assign(oVN[iVert]);
                poTriScn->Tris[iTri].VCs[iVert].Assign(oVC[iVert]);
                poTriScn->Tris[iTri].UVs[iVert].Assign(oUV[iVert]);
                poTriScn->Tris[iTri].Material = _iMat;
            }
        }
    }
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedQuadStripMesh (CGMesh& _oMesh, int _iMat)
{
    return(NULL);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriMesh (CGMesh& _oMesh, int _iMat)
{
    if ( (!_oMesh.m_poVX) &&
        (!_oMesh.m_poVC) &&
        (!_oMesh.m_poVN) &&
        (!_oMesh.m_poUV) ) return(NULL);

    CGVect3 oDefVX(0.0f,0.0f,0.0f);
    CGVect3 oDefVN(0.0f,0.0f,1.0f);
    CGVect4 oDefVC(1.0f,1.0f,1.0f,1.0f);
    CGVect2 oDefUV(0.0f,0.0f);

    CGVect3 oCurVX;
    CGVect3 oCurVN;
    CGVect4 oCurVC;
    CGVect2 oCurUV;

    int iTri,iIdx,iVert;
    SCNUt_TriScene* poTriScn = mNew SCNUt_TriScene;
    poTriScn->Init(_oMesh.m_uiNumPrims);

    for ( iTri = 0; iTri < _oMesh.m_uiNumPrims; iTri++ )
    {
        for ( iVert = 0; iVert < 3; iVert++ )
        {
            iIdx = iTri * 3 + iVert;

            // Vertex
            if ( _oMesh.m_poVX )
                oCurVX.Assign( _oMesh.m_poVX[iIdx] );
            else
                oCurVX.Assign(oDefVX);

            // Normal
            if ( _oMesh.m_poVN )
                oCurVN.Assign( _oMesh.m_poVN[iIdx] );
            else
                oCurVN.Assign(oDefVN);

            // Color
            if ( _oMesh.m_poVC )
                oCurVC.Assign( *(CGVect4*)&_oMesh.m_poVC[iIdx] );
            else
                oCurVC.Assign(oDefVC);

            // TexCoord
            if ( _oMesh.m_poUV )
                oCurUV.Assign( _oMesh.m_poUV[iIdx] );
            else
                oCurUV.Assign(oDefUV);

            // --------------------------------------------
            // Setup triangle
            // --------------------------------------------
            poTriScn->Tris[iTri].VXs[iVert].Assign(oCurVX);
            poTriScn->Tris[iTri].VNs[iVert].Assign(oCurVN);
            poTriScn->Tris[iTri].VCs[iVert].Assign(oCurVC);
            poTriScn->Tris[iTri].UVs[iVert].Assign(oCurUV);
            poTriScn->Tris[iTri].Material = _iMat;
        }
    }
    return(poTriScn);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedQuadMesh (CGMesh& _oMesh, int _iMat)
{
    return(NULL);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriStripMesh (CGMesh& _oMesh, int _iMat)
{
    if ( (!_oMesh.m_poVX) &&
        (!_oMesh.m_poVC) &&
        (!_oMesh.m_poVN) &&
        (!_oMesh.m_poUV) ) return(NULL);

    CGVect3 oDefVX(0.0f,0.0f,0.0f);
    CGVect3 oDefVN(0.0f,0.0f,1.0f);
    CGVect4 oDefVC(1.0f,1.0f,1.0f,1.0f);
    CGVect2 oDefUV(0.0f,0.0f);

    CGVect3 oCurVX;
    CGVect3 oCurVN;
    CGVect4 oCurVC;
    CGVect2 oCurUV;

    CGVect3 oVX[3];
    CGVect3 oVN[3];
    CGVect4 oVC[3];
    CGVect2 oUV[3];

    int iTri,iIdx,iVert;
    SCNUt_TriScene* poTriScn = mNew SCNUt_TriScene;
    poTriScn->Init( _oMesh.m_uiNumPrims );

    for ( iTri = 0; iTri < _oMesh.m_uiNumIdxs; iTri++ )
    {
        iIdx = iTri;

        // Vertex
        if ( _oMesh.m_poVX )
            oCurVX.Assign( _oMesh.m_poVX[iIdx] );
        else
            oCurVX.Assign(oDefVX);

        // Normal
        if ( _oMesh.m_poVN )
            oCurVN.Assign( _oMesh.m_poVN[iIdx] );
        else
            oCurVN.Assign(oDefVN);

        // Color
        if ( _oMesh.m_poVC )
            oCurVC.Assign(*(CGVect4*)&_oMesh.m_poVC[iIdx] );
        else
            oCurVC.Assign(oDefVC);

        // TexCoord
        if ( _oMesh.m_poUV )
            oCurUV.Assign( _oMesh.m_poUV[iIdx] );
        else
            oCurUV.Assign(oDefUV);

        if ( iTri < 3 )
        {
            // for the vertex 0 and 1
            oVX[iTri].Assign(oCurVX);
            oVN[iTri].Assign(oCurVN);
            oVC[iTri].Assign(oCurVC);
            oUV[iTri].Assign(oCurUV);
        }
        else
        {
            if ( iTri > 3 )
            {
                // Arrange vertices
                oVX[0].Assign(oVX[1]);
                oVN[0].Assign(oVN[1]);
                oVC[0].Assign(oVC[1]);
                oUV[0].Assign(oUV[1]);

                oVX[1].Assign(oVX[2]);
                oVN[1].Assign(oVN[2]);
                oVC[1].Assign(oVC[2]);
                oUV[1].Assign(oUV[2]);
            }

            // Last vertex is always the current vertex
            oVX[2].Assign(oCurVX);
            oVN[2].Assign(oCurVN);
            oVC[2].Assign(oCurVC);
            oUV[2].Assign(oCurUV);

            // --------------------------------------------
            // Setup triangle: only when 3 or more processed vertices
            // --------------------------------------------
            for ( iVert = 0; iVert < 3; iVert++ )
            {
                poTriScn->Tris[iTri].VXs[iVert].Assign(oVX[iVert]);
                poTriScn->Tris[iTri].VNs[iVert].Assign(oVN[iVert]);
                poTriScn->Tris[iTri].VCs[iVert].Assign(oVC[iVert]);
                poTriScn->Tris[iTri].UVs[iVert].Assign(oUV[iVert]);
                poTriScn->Tris[iTri].Material = _iMat;
            }
        }
    }

    return(poTriScn);
}

// Additional Declarations
