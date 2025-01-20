//## begin module%3BE867D00383.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE867D00383.cm

//## begin module%3BE867D00383.cp preserve=no
//## end module%3BE867D00383.cp

//## Module: SCNUt_TriSceneSplitter%3BE867D00383; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneSplitter.cpp

//## begin module%3BE867D00383.additionalIncludes preserve=no
//## end module%3BE867D00383.additionalIncludes

//## begin module%3BE867D00383.includes preserve=yes
#include <string.h>
//## end module%3BE867D00383.includes

// SCNUt_TriSceneSplitter
#include "Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneSplitter.h"
//## begin module%3BE867D00383.additionalDeclarations preserve=yes
//## end module%3BE867D00383.additionalDeclarations


// Class SCNUt_TriSceneSplitter 



SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter()
  //## begin SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter%.hasinit preserve=no
      : poFrontScene(NULL), poBackScene(NULL)
  //## end SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter%.hasinit
  //## begin SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter%.initialization preserve=yes
  //## end SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter%.initialization
{
  //## begin SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter%.body preserve=yes
  //## end SCNUt_TriSceneSplitter::SCNUt_TriSceneSplitter%.body
}


SCNUt_TriSceneSplitter::~SCNUt_TriSceneSplitter()
{
  //## begin SCNUt_TriSceneSplitter::~SCNUt_TriSceneSplitter%.body preserve=yes
  //## end SCNUt_TriSceneSplitter::~SCNUt_TriSceneSplitter%.body
}



//## Other Operations (implementation)
void SCNUt_TriSceneSplitter::SplitScene (SCNUt_TriScene& _poScene, CPlane& _roPlane, int _iBackTris, int _iFrontTris)
{
  //## begin SCNUt_TriSceneSplitter::SplitScene%1005085983.body preserve=yes

	//---------------------------------------------------------------------------
	// Subdivide la escena en 2 mitades segun esten a un lado del plano o al otro.
	// Si un triangulo cae en mitad del plano de corte, se generaran nuevos triangulos
	// Si un triangulo pertenece al plano de corte, este se incluirá en cualquiera de
	// los 2 lados de la particion
	//---------------------------------------------------------------------------
	int					cTri;	
	int		 			FrontIdx, BackIdx;
	SCNUt_Triangle 		A,B,C;
   	SCNUt_Triangle      *pCurTri;

	// Create the new 2 scenes
	poFrontScene = new SCNUt_TriScene;
	poBackScene  = new SCNUt_TriScene;
	poFrontScene->Init(_iFrontTris);
	poBackScene ->Init(_iBackTris );

	if (! _iFrontTris)
	{ 
		// Copy Input Scene data to Front
		memcpy(poBackScene->Tris,_poScene.Tris,_poScene.NumTris*sizeof(SCNUt_Triangle));
		return;
	}
else if (! _iBackTris)
	{
		// Copy Input Scene data to BackScene
		memcpy(poFrontScene->Tris,_poScene.Tris,_poScene.NumTris*sizeof(SCNUt_Triangle));
		return;
	}

	// Rearrange scene
	FrontIdx = 0;
	BackIdx  = 0;
    pCurTri   = _poScene.Tris;
	for (cTri=0;cTri<_poScene.NumTris;cTri++)
	{
		switch( pCurTri->Side )
		{
									// Add triangle to Front list
			case POLYSTATE_FRONT:	poFrontScene->Tris[FrontIdx++] = *pCurTri;
									break;

									// Add triangle to Back list
			case POLYSTATE_BACK:	poBackScene->Tris[BackIdx ++] = *pCurTri;
									break;
			case POLYSTATE_OVER:	if (_iFrontTris<_iBackTris)
										poFrontScene->Tris[FrontIdx++] = *pCurTri;
									else
										poBackScene ->Tris[BackIdx ++] = *pCurTri;
									break;
									// Split the triangle and insert into both lists
			case POLYSTATE_CROSS1:	SplitIn2Triangles(*pCurTri,A,B,_roPlane);

									if (A.Side == POLYSTATE_FRONT)
                                    {
										poFrontScene->Tris[FrontIdx++] = A;
                                        poBackScene ->Tris[BackIdx ++] = B;
                                    }
									else
                                    {
										poBackScene ->Tris[BackIdx ++] = A;
                                        poFrontScene->Tris[FrontIdx++] = B;
                                    }									
									
									// poFrontScene->Tris[FrontIdx++] = *pCurTri;
									// poBackScene ->Tris[BackIdx ++] = *pCurTri;
                                    break;
									// Split the triangle and insert into both lists
			case POLYSTATE_CROSS2:	SplitIn3Triangles(*pCurTri,A,B,C,_roPlane);

									if (A.Side == POLYSTATE_FRONT)
										poFrontScene->Tris[FrontIdx++] = A;
									else
										poBackScene ->Tris[BackIdx ++] = A;

									if (B.Side == POLYSTATE_FRONT) 
										poFrontScene->Tris[FrontIdx++] = B;
									else
										poBackScene ->Tris[BackIdx ++] = B;

									if (C.Side == POLYSTATE_FRONT)
										poFrontScene->Tris[FrontIdx++] = C;
									else
										poBackScene ->Tris[BackIdx ++] = C;
									
									// poFrontScene->Tris[FrontIdx++] = *pCurTri;
									// poBackScene ->Tris[BackIdx ++] = *pCurTri;
									break;
			default:
					break;
		}

        // Go for the next triangle
        pCurTri++;
	}

    // This should never happend
    if (BackIdx  != _iBackTris)
        poBackScene  ->NumTris = BackIdx;
        
    // This should never happend
    if (FrontIdx != _iFrontTris)
        poFrontScene ->NumTris = FrontIdx;
                
  //## end SCNUt_TriSceneSplitter::SplitScene%1005085983.body
}

void SCNUt_TriSceneSplitter::ClassifyAndSplitScene (SCNUt_TriScene& _poScene, CPlane& _roPlane)
{
  //## begin SCNUt_TriSceneSplitter::ClassifyAndSplitScene%1006556673.body preserve=yes
	SCNUt_TriSceneClassifier	oScnClassifier;
	oScnClassifier.ClassifyScene(_poScene,_roPlane);

	SplitScene(_poScene,_roPlane,oScnClassifier.iBackTris,oScnClassifier.iFrontTris);
  //## end SCNUt_TriSceneSplitter::ClassifyAndSplitScene%1006556673.body
}

void SCNUt_TriSceneSplitter::SplitIn3Triangles (SCNUt_Triangle &SrcTri, SCNUt_Triangle &A, SCNUt_Triangle &B, SCNUt_Triangle &C, CPlane &Plane)
{
  //## begin SCNUt_TriSceneSplitter::SplitIn3Triangles%1005085987.body preserve=yes

	//---------------------------------------------------------------------------
	// Divide un triángulo en 2 mitades en función del plano Plane. Se generan 3
	// triágulos. 
	// T0 = A, AC,B 
	// T1 = B AC BC
	// T2 = BC AC C
	//---------------------------------------------------------------------------

	int		vC,vA,vB;
	float	fLambda1,fLambda2;

	GetSplitVertexs(SrcTri,vC,vA,vB);

	fLambda1 = GetSplitFactor(SrcTri.VXs[vA],SrcTri.VXs[vC],Plane);
	fLambda2 = GetSplitFactor(SrcTri.VXs[vB],SrcTri.VXs[vC],Plane);
	
	GenerateTriangleFromFactor  (SrcTri,   vA,vB,vC,fLambda1,         A);
	GenerateTriangleFrom2Factors(SrcTri,vC,vA,vB,vC,fLambda1,fLambda2,B);
	GenerateTriangleFrom2Factors(SrcTri,vB,vA,vB,vC,fLambda1,fLambda2,C);
	
	// Correct the triangle ordering
	CheckWinding(SrcTri,A);
	CheckWinding(SrcTri,B);
	CheckWinding(SrcTri,C);
/*
    A.VCs[0].V4(0.0f,0.0f,1.0f,0.0f);
    A.VCs[1].V4(0.0f,0.0f,1.0f,0.0f);
    A.VCs[2].V4(0.0f,0.0f,1.0f,0.0f);

    B.VCs[0].V4(0.0f,1.0f,0.0f,0.0f);
    B.VCs[1].V4(0.0f,1.0f,0.0f,0.0f);
    B.VCs[2].V4(0.0f,1.0f,0.0f,0.0f);

    C.VCs[0].V4(1.0f,0.0f,0.0f,0.0f);
    C.VCs[1].V4(1.0f,0.0f,0.0f,0.0f);
    C.VCs[2].V4(1.0f,0.0f,0.0f,0.0f);
*/
  //## end SCNUt_TriSceneSplitter::SplitIn3Triangles%1005085987.body
}

void SCNUt_TriSceneSplitter::SplitIn2Triangles (SCNUt_Triangle &SrcTri, SCNUt_Triangle &A, SCNUt_Triangle &B, CPlane &Plane)
{
  //## begin SCNUt_TriSceneSplitter::SplitIn2Triangles%1005085988.body preserve=yes

	//---------------------------------------------------------------------------
	// Divide un triángulo en 2 mitades en función del plano Plane. Se generan 2
	// triágulos. 
	// T0 = vA, AC,B 
	// T1 = B AC BC
	//---------------------------------------------------------------------------
	int		vC,vA,vB;
	float	fLambda;

    // 1 vertex has the POLY_OVER property ( is over the plane)
    // a is the primary vertex, b is the POLY_OVER vertex, and c is the isolated vertex
	GetSplitVertexs(SrcTri,vC,vA,vB);

	fLambda = GetSplitFactor(SrcTri.VXs[vA],SrcTri.VXs[vC],Plane);

    GenerateTriangleFromFactor(SrcTri,vA,vB,vC,fLambda,A);
	GenerateTriangleFromFactor(SrcTri,vC,vB,vA,fLambda,B);

	// Correct the triangle ordering
	CheckWinding(SrcTri,A);
	CheckWinding(SrcTri,B);

/*
    A.VCs[0].V4(0.0f,1.0f,1.0f,0.25f);
    A.VCs[1].V4(0.0f,1.0f,1.0f,0.25f);
    A.VCs[2].V4(0.0f,1.0f,1.0f,0.25f);

    B.VCs[0].V4(0.0f,0.0f,0.0f,0.0f);
    B.VCs[1].V4(0.0f,0.0f,0.0f,0.0f);
    B.VCs[2].V4(0.0f,0.0f,0.0f,0.0f);
*/
  //## end SCNUt_TriSceneSplitter::SplitIn2Triangles%1005085988.body
}

void SCNUt_TriSceneSplitter::GenerateTriangleFrom2Factors (SCNUt_Triangle &SrcTri, int iIsolVX, int ipA, int ipB, int ipC, float fFactor1, float fFactor2, SCNUt_Triangle &DstTri)
{
  //## begin SCNUt_TriSceneSplitter::GenerateTriangleFrom2Factors%1005085989.body preserve=yes

	//---------------------------------------------------------------------------
	// A bit tricky. Just play with indexes.
	//---------------------------------------------------------------------------

	// Vertexs
	DstTri.VXs[0].Interpolate(SrcTri.VXs[ipA],SrcTri.VXs[ipC],fFactor1);
	DstTri.VXs[1] = SrcTri.VXs[iIsolVX];
	DstTri.VXs[2].Interpolate(SrcTri.VXs[ipB],SrcTri.VXs[ipC],fFactor2);

	// UVs
	DstTri.UVs[0].Interpolate(SrcTri.UVs[ipA],SrcTri.UVs[ipC],fFactor1);
	DstTri.UVs[1] = SrcTri.UVs[iIsolVX];
	DstTri.UVs[2].Interpolate(SrcTri.UVs[ipB],SrcTri.UVs[ipC],fFactor2);

	// Color
	DstTri.VCs[0].Interpolate(SrcTri.VCs[ipA],SrcTri.VCs[ipC],fFactor1);
	DstTri.VCs[1] = SrcTri.VCs[iIsolVX];
	DstTri.VCs[2].Interpolate(SrcTri.VCs[ipB],SrcTri.VCs[ipC],fFactor2);

	// Vertex normals
	DstTri.VNs[0].Interpolate(SrcTri.VNs[ipA],SrcTri.VNs[ipC],fFactor1);
	DstTri.VNs[1] = SrcTri.VNs[iIsolVX];
	DstTri.VNs[2].Interpolate(SrcTri.VNs[ipB],SrcTri.VNs[ipC],fFactor2);

	// Side of the triangle
	DstTri.Side     = SrcTri.VertexSide[iIsolVX];

	// Material of the triangle
	DstTri.Material = SrcTri.Material;
  //## end SCNUt_TriSceneSplitter::GenerateTriangleFrom2Factors%1005085989.body
}

void SCNUt_TriSceneSplitter::GenerateTriangleFromFactor (SCNUt_Triangle &SrcTri, int ipA, int ipB, int ipC, float fFactor, SCNUt_Triangle &DstTri)
{
  //## begin SCNUt_TriSceneSplitter::GenerateTriangleFromFactor%1005085990.body preserve=yes

	//---------------------------------------------------------------------------
	// A bit tricky. Just play with indexes.
	//---------------------------------------------------------------------------

	// Vertexs
	DstTri.VXs[0] = SrcTri.VXs[ipA];
	DstTri.VXs[1].Interpolate(SrcTri.VXs[ipA],SrcTri.VXs[ipC],fFactor);
	DstTri.VXs[2] = SrcTri.VXs[ipB];

	// UVs
	DstTri.UVs[0] = SrcTri.UVs[ipA];
	DstTri.UVs[1].Interpolate(SrcTri.UVs[ipA],SrcTri.UVs[ipC],fFactor);
	DstTri.UVs[2] = SrcTri.UVs[ipB];

	// Color
	DstTri.VCs[0] = SrcTri.VCs[ipA];
	DstTri.VCs[1].Interpolate(SrcTri.VCs[ipA],SrcTri.VCs[ipC],fFactor);
	DstTri.VCs[2] = SrcTri.VCs[ipB];

	// Vertex normals
	DstTri.VNs[0] = SrcTri.VNs[ipA];
	DstTri.VNs[1].Interpolate(SrcTri.VNs[ipA],SrcTri.VNs[ipC],fFactor);
	DstTri.VNs[2] = SrcTri.VNs[ipB];

	// Side of the triangle
    DstTri.Side = SrcTri.VertexSide[ipA];

	// Material of the triangle
	DstTri.Material = SrcTri.Material;
  //## end SCNUt_TriSceneSplitter::GenerateTriangleFromFactor%1005085990.body
}

float SCNUt_TriSceneSplitter::GetSplitFactor (CVect3 &pA, CVect3 &pB, CPlane &Plane)
{
  //## begin SCNUt_TriSceneSplitter::GetSplitFactor%1005085991.body preserve=yes

	//---------------------------------------------------------------------------
	// Ray-plane intersection. Substitute the line equation inside plane equation
	// and get the t factor = (fLambdaNumerator / fDotProduct)
	//---------------------------------------------------------------------------
    // Plane equation:  Ax + By +Cz + D = 0
    // Line equation:   (x,y,z) = (x0,y0,z0) + Lambda(a,b,c)
    //                  x = x0 + La
    //                  y = y0 + Lb
    //                  z = z0 + Lc
    //
    //  Substitute line eq inside plane eq
    //                  A(x0 + La) + B(y0 + Lb) + C(z0 + Lc) + D = 0
    //                  Ax0 + ALa + By0 + BLb + Cz0 + CLc + D = 0
    //  Then:
    //                  L(Aa + Bb + Cc) = - (Ax0 + By0 + Cz0 + D)
    //  Finally:
    //                  L = - (Ax0 + By0 + Cz0 + D)
    //                      -----------------------
    //                          (Aa + Bb + Cc)
    //
    //              (a,b,c) = line director vector
    //              (A,B,C) = Plane normal
    //
    //  (Aa + Bb + Cc) = Dot product between Plane normal and line director vector
    //  Ax0 + By0 + Cz0 = Dot procutc between Plane normal and a point belonging to the line
    //---------------------------------------------------------------------------

	CVect3  vDirector;
	float	fDotProduct;
	float	fLambdaNumerator;
    float   fSegLen;

	vDirector.Assign(pB);
	vDirector.Sub(pA);
    fSegLen = vDirector.Module();
    vDirector.Normalize();

	// Angulo de incidencia entre la recta y el plano. Si es 0, el plano no corta la recta
	fDotProduct         =    vDirector.DotProd(Plane.Normal());
	fLambdaNumerator    = -( pA.DotProd(Plane.Normal()) + Plane.D() );

    // In order to make point,color and uvs computations, we need to make linear
    // interpolation. We need to get the relationship between the line equation factor
    // lambda and the linear interpolation factor (t)
    //
    // Interpolation: X = A(1-t) + B(t)
    // Line equation: X = A + Lambda( vDir(AB) )
    // X is the same for both the 2 equations:
    //
    //  A(1-t) + B(t) = A + L(vDir(AB))
    //  A-At + Bt     = A + L(vDir(AB))
    //  A + (B-A)t    = A + L(vDir(AB))
    //
    // vDir(AB) = (B - A)
    //            -------
    //           ||B - A||
    //
    //  A + (B-A)t = A + L(B-A) / ||B - A||
    //
    // Sub A
    //      (B-A)t = L(B-A) / ||B - A||
    // Finally divide by (B-A)
    //
    //        t =    L
    //           -------
    //          ||B - A||

	if ((! fDotProduct) || (! fSegLen))
		return(0.0f);
	else
		return( (fLambdaNumerator / fDotProduct) / fSegLen );


  //## end SCNUt_TriSceneSplitter::GetSplitFactor%1005085991.body
}

void SCNUt_TriSceneSplitter::GetSplitVertexs (SCNUt_Triangle &SrcTri, int &C, int &A, int &B)
{
  //## begin SCNUt_TriSceneSplitter::GetSplitVertexs%1005085992.body preserve=yes

	//---------------------------------------------------------------------------
	// En el caso normal, en el que ninguno de los vértices del triángulo pertenece al
	// propio plano, existe un vértice que se aisla C, y 2 que se mantienen A,B.
	//---------------------------------------------------------------------------

	// Hallar el ángulo entre este vector y la normal del plano
	 if (SrcTri.VertexSide[1]==SrcTri.VertexSide[0])
	 {
		// Ya hemos encontrado 2 vértices en el mismo lado del plano
		C = 2;
		A = 0;
		B = 1;
	 }
else if (SrcTri.VertexSide[2]==SrcTri.VertexSide[1])
	 {
		C = 0;
	    A = 1;
		B = 2;
     }
else if (SrcTri.VertexSide[2]==SrcTri.VertexSide[0])
     {
        // 0 y 2 en el mismo lado, y 1 en el otro
        C = 1;
        A = 0;
        B = 2;
     }
else {
        // 1 vertex is on the plane, 1 in front, and 1 back off the plane
        if (SrcTri.VertexSide[0] == POLYSTATE_OVER)
        {
            if (SrcTri.VertexSide[1] == POLYSTATE_FRONT)
            {
                A = 1;
                B = 0;
                C = 2;
            }
            else
            {
                A = 2;
                B = 0;
                C = 1;
            }
        }
   else if (SrcTri.VertexSide[1] == POLYSTATE_OVER)
        {
            if (SrcTri.VertexSide[2] == POLYSTATE_FRONT)
            {
                A = 2;
                B = 1;
                C = 0;
            }
            else
            {
                A = 0;
                B = 1;
                C = 2;
            }
        }
   else if (SrcTri.VertexSide[2] == POLYSTATE_OVER)
        {
            if (SrcTri.VertexSide[0] == POLYSTATE_FRONT)
            {
                A = 0;
                B = 2;
                C = 1;
            }
            else
            {
                A = 1;
                B = 2;
                C = 0;
            }
        }
	}
  //## end SCNUt_TriSceneSplitter::GetSplitVertexs%1005085992.body
}

void SCNUt_TriSceneSplitter::CheckWinding (SCNUt_Triangle& _roRefTri, SCNUt_Triangle& _roTri)
{
  //## begin SCNUt_TriSceneSplitter::CheckWinding%1006687670.body preserve=yes
	CPlane oRefPlane;
	CPlane oTriPlane;

	oRefPlane.GenerateFromPoints(_roRefTri.VXs[0],_roRefTri.VXs[1],_roRefTri.VXs[2]);
	oTriPlane.GenerateFromPoints(_roTri.VXs[0],	  _roTri.VXs[1],   _roTri.VXs[2]   );

	if ( oRefPlane.Normal().DotProd(oTriPlane.Normal()) < 0.0f)
		SCNUt_TriUtils::ChangeWinding(_roTri);
  //## end SCNUt_TriSceneSplitter::CheckWinding%1006687670.body
}

// Additional Declarations
  //## begin SCNUt_TriSceneSplitter%3BE867D00383.declarations preserve=yes
  //## end SCNUt_TriSceneSplitter%3BE867D00383.declarations

//## begin module%3BE867D00383.epilog preserve=yes
//## end module%3BE867D00383.epilog
