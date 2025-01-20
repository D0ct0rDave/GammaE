//## begin module%3BFED7400167.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BFED7400167.cm

//## begin module%3BFED7400167.cp preserve=no
//## end module%3BFED7400167.cp

//## Module: SCNUt_TriSceneClassifier%3BFED7400167; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneClassifier.cpp

//## begin module%3BFED7400167.additionalIncludes preserve=no
//## end module%3BFED7400167.additionalIncludes

//## begin module%3BFED7400167.includes preserve=yes
//## end module%3BFED7400167.includes

// SCNUt_TriSceneClassifier
#include "Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneClassifier.h"
//## begin module%3BFED7400167.additionalDeclarations preserve=yes
//## end module%3BFED7400167.additionalDeclarations


// Class SCNUt_TriSceneClassifier 



SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier()
  //## begin SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier%.hasinit preserve=no
      : iFrontTris(0), iBackTris(0)
  //## end SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier%.hasinit
  //## begin SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier%.initialization preserve=yes
  //## end SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier%.initialization
{
  //## begin SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier%.body preserve=yes
  //## end SCNUt_TriSceneClassifier::SCNUt_TriSceneClassifier%.body
}


SCNUt_TriSceneClassifier::~SCNUt_TriSceneClassifier()
{
  //## begin SCNUt_TriSceneClassifier::~SCNUt_TriSceneClassifier%.body preserve=yes
  //## end SCNUt_TriSceneClassifier::~SCNUt_TriSceneClassifier%.body
}



//## Other Operations (implementation)
void SCNUt_TriSceneClassifier::ClassifyScene (SCNUt_TriScene& _poScene, CPlane& _roPlane)
{
  //## begin SCNUt_TriSceneClassifier::ClassifyScene%1006556674.body preserve=yes
	int					cTri;
	SCNUt_Triangle 		A,B,C;
   	SCNUt_Triangle      *pCurTri;
	
  	//---------------------------------------------------------------------------
	// Clasifica los triangulos de la escena, según estén a un lado, u otro del plano.
	//---------------------------------------------------------------------------

	// Classify the whole triangle list
	for (cTri=0;cTri<_poScene.NumTris;cTri++)
		_poScene.Tris[cTri].Side = ClassifyTriangle(_poScene.Tris[cTri],_roPlane);


	// Count the triangles of both sides
    iFrontTris = 0;
    iBackTris  = 0;
    pCurTri   = _poScene.Tris;

	for (cTri=0;cTri<_poScene.NumTris;cTri++)
	{
		switch(pCurTri->Side)
		{
								    // Add triangle to Front list
			case POLYSTATE_FRONT:   iFrontTris++;
								    break;

								    // Add triangle to Back list
			case POLYSTATE_BACK:    iBackTris++;
								    break;
			case POLYSTATE_OVER:	if (iFrontTris<iBackTris)
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
			case POLYSTATE_CROSS2:  if (pCurTri->VertexSide[0] == POLYSTATE_FRONT)
                                    {
                                        if( (pCurTri->VertexSide[1] == POLYSTATE_FRONT) ||
                                            (pCurTri->VertexSide[2] == POLYSTATE_FRONT))
                                        {
                                            // 0 and 1 or 2 is front
                                            iFrontTris += 2;
                                            iBackTris  ++;
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
                                        if( (pCurTri->VertexSide[1] == POLYSTATE_BACK) ||
                                            (pCurTri->VertexSide[2] == POLYSTATE_BACK))
                                        {
                                            // 0 and 1 or 2 is back
                                            iBackTris += 2;
                                            iFrontTris++;
                                        }
                                        else
                                        {
                                            // 0 back and 1 and 2 front
                                            iFrontTris += 2;
                                            iBackTris  ++;
                                        }
                                    }
                                    break;
		}
        // Go for the next triangle
        pCurTri++;
	}

  //## end SCNUt_TriSceneClassifier::ClassifyScene%1006556674.body
}

SCNUt_ePolyState SCNUt_TriSceneClassifier::ClassifyTriangle (SCNUt_Triangle& SrcTri, CPlane &Plane)
{
  //## begin SCNUt_TriSceneClassifier::ClassifyTriangle%1006556675.body preserve=yes
  
	//---------------------------------------------------------------------------
	// Clasifica el triángulo según esté a uno de los 2 lados del plano o
	// entre ambos.
	// Para simplificar las cosas puntos que pertenecen al plano (DProd=0; 90º )
	// son considerados como puntos "por delante" del plano.
	//---------------------------------------------------------------------------

	SCNUt_ePolyState	TriSide;
	int					Zeros;
	int					cVert;

	ClassifyTriangleVertexs(&SrcTri,Plane);

	// Todos los vértices al mismo lado del triangulo
	if ((SrcTri.VertexSide[0] == SrcTri.VertexSide[1]) &&
		(SrcTri.VertexSide[1] == SrcTri.VertexSide[2]))
	{
		TriSide = SrcTri.VertexSide[0];		
		return(TriSide);
	}

	// 2 o 3 vértices en diferentes lados: El dot product de un vértice será 0
    // cuando el vértice pertenezca al plano -> angulo entre Plane.Origin y Vertex = 90º 
	if (SrcTri.DProds[0]*SrcTri.DProds[1]*SrcTri.DProds[2] == 0)
	{
		// 1 o 2 vértices pertenecen al plano
		Zeros = 0;
		if (! SrcTri.DProds[0]) Zeros++;
		if (! SrcTri.DProds[1]) Zeros++;
		if (! SrcTri.DProds[2]) Zeros++;


		// De momento para simplificar: retornamos el polígono como si perteneciera
		
		switch (Zeros)
		{
			case 1: // 1 puede estar a un lado y el otro al otro.
					if ((SrcTri.VertexSide[0] != SrcTri.VertexSide[1]) &&
						(SrcTri.VertexSide[1] != SrcTri.VertexSide[2]))
					{
						return(POLYSTATE_CROSS1);							
					}
					else
					{
						// 2 vértice a un lado del plano
						for (cVert=0;cVert<3;cVert++)
							if (SrcTri.VertexSide[cVert] != POLYSTATE_OVER)
								return( SrcTri.VertexSide[cVert] );

                        // This should never happen
                        return ( SrcTri.VertexSide[0] );
					}
					break;

			case 2: // Como si el polígono perteneciera
					for (cVert=0;cVert<3;cVert++)
						if (SrcTri.VertexSide[cVert] != POLYSTATE_OVER)
							return( SrcTri.VertexSide[cVert] );
					break;			
		}
	}

	// 2 vértices iguales y otro diferente. Caso simple de triangle-split
	return(POLYSTATE_CROSS2);


  //## end SCNUt_TriSceneClassifier::ClassifyTriangle%1006556675.body
}

void SCNUt_TriSceneClassifier::ClassifyTriangleVertexs (SCNUt_Triangle *SrcTri, CPlane &Plane)
{
  //## begin SCNUt_TriSceneClassifier::ClassifyTriangleVertexs%1006556676.body preserve=yes
	
	unsigned int uiVert;
	CVect3	TriSegment;

	for (uiVert=0;uiVert<3;uiVert++)
	{
		// Obtener el vector del vértice actual del triángulo a
		// un punto cualquiera perteneciente al plano
		TriSegment.Assign(SrcTri->VXs[uiVert]);
		TriSegment.Sub   ( Plane.Origin() );
        TriSegment.Normalize();
        
		SrcTri->DProds[uiVert]     = Plane.Normal().DotProd(TriSegment);
		SrcTri->VertexSide[uiVert] = ClassifyVertex(SrcTri,uiVert);
	}

  //## end SCNUt_TriSceneClassifier::ClassifyTriangleVertexs%1006556676.body
}

SCNUt_ePolyState SCNUt_TriSceneClassifier::ClassifyVertex (SCNUt_Triangle *SrcTri, int iVertex)
{
  //## begin SCNUt_TriSceneClassifier::ClassifyVertex%1006556677.body preserve=yes
  	
	//---------------------------------------------------------------------------
	// Classify a vertex depending on its dot product.									
	//---------------------------------------------------------------------------

	 if (SrcTri->DProds[iVertex] < 0) 
		return(POLYSTATE_BACK);
else if (SrcTri->DProds[iVertex] == 0) 
		return(POLYSTATE_OVER);
else 		
	    return(POLYSTATE_FRONT);

  //## end SCNUt_TriSceneClassifier::ClassifyVertex%1006556677.body
}

// Additional Declarations
  //## begin SCNUt_TriSceneClassifier%3BFED7400167.declarations preserve=yes
  //## end SCNUt_TriSceneClassifier%3BFED7400167.declarations

//## begin module%3BFED7400167.epilog preserve=yes
//## end module%3BFED7400167.epilog
