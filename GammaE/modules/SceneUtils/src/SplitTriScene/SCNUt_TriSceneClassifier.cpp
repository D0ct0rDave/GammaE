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
// SCNUt_TriSceneClassifier
#include "SplitTriScene\SCNUt_TriSceneClassifier.h"

// Class SCNUt_TriSceneClassifier

SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier()
    : iFrontTris(0), iBackTris(0)
{
}

SCNUt_TriSceneClassifier::~SCNUt_TriSceneClassifier()
{
}

void SCNUt_TriSceneClassifier::ClassifyScene (SCNUt_TriScene& _poScene, CGPlane& _oPlane)
{
    int cTri;
    SCNUt_Triangle A,B,C;
    SCNUt_Triangle* pCurTri;

    // -----------------------------------------------------------------------------
    // Clasifica los triangulos de la escena, según estén a un lado, u otro del plano.
    // -----------------------------------------------------------------------------

    // Classify the whole triangle list
    for ( cTri = 0; cTri < _poScene.NumTris; cTri++ )
        _poScene.Tris[cTri].Side = ClassifyTriangle(_poScene.Tris[cTri],_oPlane);

    // Count the triangles of both sides
    iFrontTris = 0;
    iBackTris = 0;
    pCurTri = _poScene.Tris;

    for ( cTri = 0; cTri < _poScene.NumTris; cTri++ )
    {
        switch ( pCurTri->Side )
        {
            // Add triangle to Front list
            case POLYSTATE_FRONT:   iFrontTris++;
            break;

            // Add triangle to Back list
            case POLYSTATE_BACK:    iBackTris++;
            break;

            case POLYSTATE_OVER:    if ( iFrontTris < iBackTris )
            {
                pCurTri->Side = POLYSTATE_FRONT;
                iFrontTris++;
            }
            else
            {
                pCurTri->Side = POLYSTATE_BACK;
                iBackTris++;
            }
            break;

            // Add triangle to both lists
            case POLYSTATE_CROSS1:  iFrontTris++;
            iBackTris++;
            break;

            // Add triangle to both lists
            case POLYSTATE_CROSS2:  if ( pCurTri->VertexSide[0] == POLYSTATE_FRONT )
            {
                if ( (pCurTri->VertexSide[1] == POLYSTATE_FRONT) ||
                    (pCurTri->VertexSide[2] == POLYSTATE_FRONT) )
                {
                    // 0 and 1 or 2 is front
                    iFrontTris += 2;
                    iBackTris++;
                }
                else
                {
                    // 0 front and 1 and 2 back
                    iBackTris += 2;
                    iFrontTris++;
                }
            }
            else
            {
                if ( (pCurTri->VertexSide[1] == POLYSTATE_BACK) ||
                    (pCurTri->VertexSide[2] == POLYSTATE_BACK) )
                {
                    // 0 and 1 or 2 is back
                    iBackTris += 2;
                    iFrontTris++;
                }
                else
                {
                    // 0 back and 1 and 2 front
                    iFrontTris += 2;
                    iBackTris++;
                }
            }
            break;
        }
        // Go for the next triangle
        pCurTri++;
    }
}

SCNUt_ePolyState SCNUt_TriSceneClassifier::ClassifyTriangle (SCNUt_Triangle& SrcTri, CGPlane &Plane)
{
    // -----------------------------------------------------------------------------
    // Clasifica el triángulo según esté a uno de los 2 lados del plano o
    // entre ambos.
    // Para simplificar las cosas puntos que pertenecen al plano (DProd=0; 90º )
    // son considerados como puntos "por delante" del plano.
    // -----------------------------------------------------------------------------

    SCNUt_ePolyState TriSide;
    int Zeros;
    int cVert;

    ClassifyTriangleVertexs(&SrcTri,Plane);

    // Todos los vértices al mismo lado del triangulo
    if ( (SrcTri.VertexSide[0] == SrcTri.VertexSide[1]) &&
        (SrcTri.VertexSide[1] == SrcTri.VertexSide[2]) )
    {
        TriSide = SrcTri.VertexSide[0];
        return(TriSide);
    }

    // 2 o 3 vértices en diferentes lados: El dot product de un vértice será 0
    // cuando el vértice pertenezca al plano -> angulo entre Plane.Origin y Vertex = 90º
    if ( SrcTri.DProds[0] * SrcTri.DProds[1] * SrcTri.DProds[2] == 0 )
    {
        // 1 o 2 vértices pertenecen al plano
        Zeros = 0;
        if ( !SrcTri.DProds[0] ) Zeros++;
        if ( !SrcTri.DProds[1] ) Zeros++;
        if ( !SrcTri.DProds[2] ) Zeros++;

        // De momento para simplificar: retornamos el polígono como si perteneciera

        switch ( Zeros )
        {
            case 1:                    // 1 puede estar a un lado y el otro al otro.
            if ( (SrcTri.VertexSide[0] != SrcTri.VertexSide[1]) &&
                (SrcTri.VertexSide[1] != SrcTri.VertexSide[2]) )
            {
                return(POLYSTATE_CROSS1);
            }
            else
            {
                // 2 vértice a un lado del plano
                for ( cVert = 0; cVert < 3; cVert++ )
                    if ( SrcTri.VertexSide[cVert] != POLYSTATE_OVER )
                        return(SrcTri.VertexSide[cVert]);

                // This should never happen
                return (SrcTri.VertexSide[0]);
            }
            break;

            case 2:                    // Como si el polígono perteneciera
            for ( cVert = 0; cVert < 3; cVert++ )
                if ( SrcTri.VertexSide[cVert] != POLYSTATE_OVER )
                    return(SrcTri.VertexSide[cVert]);
            break;
        }
    }

    // 2 vértices iguales y otro diferente. Caso simple de triangle-split
    return(POLYSTATE_CROSS2);
}

void SCNUt_TriSceneClassifier::ClassifyTriangleVertexs (SCNUt_Triangle* SrcTri, CGPlane &Plane)
{
    unsigned int uiVert;
    CGVect3 TriSegment;

    for ( uiVert = 0; uiVert < 3; uiVert++ )
    {
        // Obtener el vector del vértice actual del triángulo a
        // un punto cualquiera perteneciente al plano
        TriSegment.Assign(SrcTri->VXs[uiVert]);
        TriSegment.Sub   ( Plane.oGetOrigin() );
        TriSegment.Normalize();

        SrcTri->DProds[uiVert] = Plane.oGetNormal().fDotProd(TriSegment);
        SrcTri->VertexSide[uiVert] = ClassifyVertex(SrcTri,uiVert);
    }
}

SCNUt_ePolyState SCNUt_TriSceneClassifier::ClassifyVertex (SCNUt_Triangle* SrcTri, int iVertex)
{
    // -----------------------------------------------------------------------------
    // Classify a vertex depending on its dot product.
    // -----------------------------------------------------------------------------

    if ( SrcTri->DProds[iVertex] < 0 )
        return(POLYSTATE_BACK);
    else
    if ( SrcTri->DProds[iVertex] == 0 )
        return(POLYSTATE_OVER);
    else
        return(POLYSTATE_FRONT);
}

// Additional Declarations
