//## begin module%3C2BD25F0321.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BD25F0321.cm

//## begin module%3C2BD25F0321.cp preserve=no
//## end module%3C2BD25F0321.cp

//## Module: SCNUt_Mesh2TriScene%3C2BD25F0321; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\Mesh2TriScn\SCNUt_Mesh2TriScene.cpp

//## begin module%3C2BD25F0321.additionalIncludes preserve=no
//## end module%3C2BD25F0321.additionalIncludes

//## begin module%3C2BD25F0321.includes preserve=yes
#include "Memory/GammaE_Mem.h"
//## end module%3C2BD25F0321.includes

// SCNUt_Mesh2TriScene
#include "Scene\SceneUtils\Mesh2TriScn\SCNUt_Mesh2TriScene.h"
//## begin module%3C2BD25F0321.additionalDeclarations preserve=yes
//## end module%3C2BD25F0321.additionalDeclarations


// Class SCNUt_Mesh2TriScene 

SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene()
  //## begin SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene%.hasinit preserve=no
  //## end SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene%.hasinit
  //## begin SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene%.initialization preserve=yes
  //## end SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene%.initialization
{
  //## begin SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene%.body preserve=yes
  //## end SCNUt_Mesh2TriScene::SCNUt_Mesh2TriScene%.body
}


SCNUt_Mesh2TriScene::~SCNUt_Mesh2TriScene()
{
  //## begin SCNUt_Mesh2TriScene::~SCNUt_Mesh2TriScene%.body preserve=yes
  //## end SCNUt_Mesh2TriScene::~SCNUt_Mesh2TriScene%.body
}



//## Other Operations (implementation)
SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate%1009496924.body preserve=yes
	switch (_roMesh.eMeshType)
	{		
		case E3D_MESH_NONE:			
		{
			return(NULL);
		}
		break;

		case E3D_MESH_TRIS:
		{
			return(Generate_FromIndexedTriMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_QUADS:
		{
			return(Generate_FromIndexedQuadMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_TRIFANS:
		{
			return(Generate_FromIndexedTriFanMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_TRISTRIPS:
		{
			return(Generate_FromIndexedTriStripMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_QUADSTRIPS:
		{
			return(Generate_FromIndexedQuadStripMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_NITRIS:		
		{
			return(Generate_FromNonIndexedTriMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_NIQUADS:	
		{
			return(Generate_FromNonIndexedQuadMesh(_roMesh,_iMat));
		}
		break;
		
		case E3D_MESH_NITRISTRIP:
		{
			return(Generate_FromNonIndexedTriStripMesh(_roMesh,_iMat));
		}
		break;

		default:
		return(NULL);
	}
		
  //## end SCNUt_Mesh2TriScene::Generate%1009496924.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromIndexedTriMesh%1009552653.body preserve=yes
	if (! _roMesh.Idxs) return(NULL);

	if ((! _roMesh.VXs) &&
		(! _roMesh.VCs) &&
		(! _roMesh.VNs) &&
		(! _roMesh.UVs)) return(NULL);

	CVect3			oDefVX(0.0f,0.0f,0.0f);
	CVect3			oDefVN(0.0f,0.0f,1.0f);
	CVect4			oDefVC(1.0f,1.0f,1.0f,1.0f);
	CVect2			oDefUV(0.0f,0.0f);

	CVect3			oCurVX;
	CVect3			oCurVN;
	CVect4			oCurVC;
	CVect2			oCurUV;

	int				iTri,iIdx,iVert;
	SCNUt_TriScene *poTriScn = mNew SCNUt_TriScene;	
	poTriScn->Init(_roMesh.usNumPrims);
	
	for (iTri=0;iTri<_roMesh.usNumPrims;iTri++)
	{	
		for (iVert=0;iVert<3;iVert++)
		{
			iIdx = _roMesh.Idxs[ iTri*3+iVert ];

			// Vertex
			if (_roMesh.VXs)
				oCurVX.Assign( _roMesh.VXs[iIdx] );
			else
				oCurVX.Assign(oDefVX);
			
			// Normal
			if (_roMesh.VNs)
				oCurVN.Assign( _roMesh.VNs[iIdx] );
			else
				oCurVN.Assign(oDefVN);
			
			// Color
			if (_roMesh.VCs)
				oCurVC.Assign( _roMesh.VCs[iIdx] );
			else
				oCurVC.Assign(oDefVC);
			
			// TexCoord
			if (_roMesh.UVs)
				oCurUV.Assign( _roMesh.UVs[iIdx] );
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
	return( poTriScn );
  //## end SCNUt_Mesh2TriScene::Generate_FromIndexedTriMesh%1009552653.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedQuadMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromIndexedQuadMesh%1009552654.body preserve=yes
	return(NULL);
  //## end SCNUt_Mesh2TriScene::Generate_FromIndexedQuadMesh%1009552654.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriStripMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromIndexedTriStripMesh%1009552655.body preserve=yes
  	if (! _roMesh.Idxs) return(NULL);
	
	if ((! _roMesh.VXs) &&
		(! _roMesh.VCs) &&
		(! _roMesh.VNs) &&
		(! _roMesh.UVs)) return(NULL);

	CVect3			oDefVX(0.0f,0.0f,0.0f);
	CVect3			oDefVN(0.0f,0.0f,1.0f);
	CVect4			oDefVC(1.0f,1.0f,1.0f,1.0f);
	CVect2			oDefUV(0.0f,0.0f);

	CVect3			oCurVX;
	CVect3			oCurVN;
	CVect4			oCurVC;
	CVect2			oCurUV;	

	CVect3			oVX[3];
	CVect3			oVN[3];
	CVect4			oVC[3];
	CVect2			oUV[3];

	int				iTri,iIdx,iVert;
	SCNUt_TriScene *poTriScn = mNew SCNUt_TriScene;	
	poTriScn->Init( _roMesh.usNumPrims );
	
	for (iTri=0;iTri<_roMesh.usNumIdxs;iTri++)
	{	
		iIdx = _roMesh.Idxs[ iTri ];

		// Vertex
		if (_roMesh.VXs)
			oCurVX.Assign( _roMesh.VXs[iIdx] );
		else
			oCurVX.Assign(oDefVX);
		
		// Normal
		if (_roMesh.VNs)
			oCurVN.Assign( _roMesh.VNs[iIdx] );
		else
			oCurVN.Assign(oDefVN);
		
		// Color
		if (_roMesh.VCs)
			oCurVC.Assign( _roMesh.VCs[iIdx] );
		else
			oCurVC.Assign(oDefVC);
		
		// TexCoord
		if (_roMesh.UVs)
			oCurUV.Assign( _roMesh.UVs[iIdx] );
		else
			oCurUV.Assign(oDefUV);
		
		// Vertex 0 is swapped with previous iteration Vertex 1
		// Vertex 1 is swapped with previous iteration Vertex 2
		// Vertex 2 is always updated with new info
				
		if (iTri<3)
		{
			// for the vertex 0 and 1
			oVX[iTri].Assign(oCurVX);				
			oVN[iTri].Assign(oCurVN);
			oVC[iTri].Assign(oCurVC);
			oUV[iTri].Assign(oCurUV);
		}
		else
		{
			if (iTri>3)
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
			for (iVert=0;iVert<3;iVert++)
			{
				poTriScn->Tris[iTri].VXs[iVert].Assign(oVX[iVert]);
				poTriScn->Tris[iTri].VNs[iVert].Assign(oVN[iVert]);
				poTriScn->Tris[iTri].VCs[iVert].Assign(oVC[iVert]);
				poTriScn->Tris[iTri].UVs[iVert].Assign(oUV[iVert]);
				poTriScn->Tris[iTri].Material = _iMat;
			}
		}
	}

	return( poTriScn );
  //## end SCNUt_Mesh2TriScene::Generate_FromIndexedTriStripMesh%1009552655.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriFanMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromIndexedTriFanMesh%1009552651.body preserve=yes
  	if (! _roMesh.Idxs) return(NULL);
	
	if ((! _roMesh.VXs) &&
		(! _roMesh.VCs) &&
		(! _roMesh.VNs) &&
		(! _roMesh.UVs)) return(NULL);

	CVect3			oDefVX(0.0f,0.0f,0.0f);
	CVect3			oDefVN(0.0f,0.0f,1.0f);
	CVect4			oDefVC(1.0f,1.0f,1.0f,1.0f);
	CVect2			oDefUV(0.0f,0.0f);

	CVect3			oCurVX;
	CVect3			oCurVN;
	CVect4			oCurVC;
	CVect2			oCurUV;	

	CVect3			oVX[3];
	CVect3			oVN[3];
	CVect4			oVC[3];
	CVect2			oUV[3];

	int				iTri,iIdx,iVert;
	SCNUt_TriScene *poTriScn = mNew SCNUt_TriScene;	
	poTriScn->Init( _roMesh.usNumPrims );
	
	for (iTri=0;iTri<_roMesh.usNumIdxs;iTri++)
	{	
		iIdx = _roMesh.Idxs[ iTri ];

		// Vertex
		if (_roMesh.VXs)
			oCurVX.Assign( _roMesh.VXs[iIdx] );
		else
			oCurVX.Assign(oDefVX);
		
		// Normal
		if (_roMesh.VNs)
			oCurVN.Assign( _roMesh.VNs[iIdx] );
		else
			oCurVN.Assign(oDefVN);
		
		// Color
		if (_roMesh.VCs)
			oCurVC.Assign( _roMesh.VCs[iIdx] );
		else
			oCurVC.Assign(oDefVC);
		
		// TexCoord
		if (_roMesh.UVs)
			oCurUV.Assign( _roMesh.UVs[iIdx] );
		else
			oCurUV.Assign(oDefUV);

		// Vertex 0 is maintained throught all the mesh
		// Vertex 1 is swaped with previous iteration Vertex 2
		// Vertex 2 is always updated with new info
		
		if (iTri<3)
		{
			// for the vertex 0 and 1
			oVX[iTri].Assign(oCurVX);				
			oVN[iTri].Assign(oCurVN);
			oVC[iTri].Assign(oCurVC);
			oUV[iTri].Assign(oCurUV);
		}
		else
		{
			if (iTri>3)
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
			for (iVert=0;iVert<3;iVert++)
			{
				poTriScn->Tris[iTri].VXs[iVert].Assign(oVX[iVert]);
				poTriScn->Tris[iTri].VNs[iVert].Assign(oVN[iVert]);
				poTriScn->Tris[iTri].VCs[iVert].Assign(oVC[iVert]);
				poTriScn->Tris[iTri].UVs[iVert].Assign(oUV[iVert]);
				poTriScn->Tris[iTri].Material = _iMat;
			}
		}
	}

  //## end SCNUt_Mesh2TriScene::Generate_FromIndexedTriFanMesh%1009552651.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedQuadStripMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromIndexedQuadStripMesh%1009552652.body preserve=yes
  	return(NULL);
  //## end SCNUt_Mesh2TriScene::Generate_FromIndexedQuadStripMesh%1009552652.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriMesh%1009552656.body preserve=yes
	if ((! _roMesh.VXs) &&
		(! _roMesh.VCs) &&
		(! _roMesh.VNs) &&
		(! _roMesh.UVs)) return(NULL);

	CVect3			oDefVX(0.0f,0.0f,0.0f);
	CVect3			oDefVN(0.0f,0.0f,1.0f);
	CVect4			oDefVC(1.0f,1.0f,1.0f,1.0f);
	CVect2			oDefUV(0.0f,0.0f);

	CVect3			oCurVX;
	CVect3			oCurVN;
	CVect4			oCurVC;
	CVect2			oCurUV;	

	int				iTri,iIdx,iVert;
	SCNUt_TriScene *poTriScn = mNew SCNUt_TriScene;	
	poTriScn->Init(_roMesh.usNumPrims);
	
	for (iTri=0;iTri<_roMesh.usNumPrims;iTri++)
	{	
		for (iVert=0;iVert<3;iVert++)
		{
			iIdx = iTri*3+iVert;

			// Vertex
			if (_roMesh.VXs)
				oCurVX.Assign( _roMesh.VXs[iIdx] );
			else
				oCurVX.Assign(oDefVX);
			
			// Normal
			if (_roMesh.VNs)
				oCurVN.Assign( _roMesh.VNs[iIdx] );
			else
				oCurVN.Assign(oDefVN);
			
			// Color
			if (_roMesh.VCs)
				oCurVC.Assign( _roMesh.VCs[iIdx] );
			else
				oCurVC.Assign(oDefVC);
			
			// TexCoord
			if (_roMesh.UVs)
				oCurUV.Assign( _roMesh.UVs[iIdx] );
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
	return( poTriScn );
  //## end SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriMesh%1009552656.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedQuadMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromNonIndexedQuadMesh%1009552657.body preserve=yes
	return(NULL);
  //## end SCNUt_Mesh2TriScene::Generate_FromNonIndexedQuadMesh%1009552657.body
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriStripMesh (CMesh& _roMesh, int _iMat)
{
  //## begin SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriStripMesh%1009552658.body preserve=yes
	if ((! _roMesh.VXs) &&
		(! _roMesh.VCs) &&
		(! _roMesh.VNs) &&
		(! _roMesh.UVs)) return(NULL);

	CVect3			oDefVX(0.0f,0.0f,0.0f);
	CVect3			oDefVN(0.0f,0.0f,1.0f);
	CVect4			oDefVC(1.0f,1.0f,1.0f,1.0f);
	CVect2			oDefUV(0.0f,0.0f);

	CVect3			oCurVX;
	CVect3			oCurVN;
	CVect4			oCurVC;
	CVect2			oCurUV;	

	CVect3			oVX[3];
	CVect3			oVN[3];
	CVect4			oVC[3];
	CVect2			oUV[3];

	int				iTri,iIdx,iVert;
	SCNUt_TriScene *poTriScn = mNew SCNUt_TriScene;	
	poTriScn->Init( _roMesh.usNumPrims );
	
	for (iTri=0;iTri<_roMesh.usNumIdxs;iTri++)
	{	
		iIdx = iTri;

		// Vertex
		if (_roMesh.VXs)
			oCurVX.Assign( _roMesh.VXs[iIdx] );
		else
			oCurVX.Assign(oDefVX);
		
		// Normal
		if (_roMesh.VNs)
			oCurVN.Assign( _roMesh.VNs[iIdx] );
		else
			oCurVN.Assign(oDefVN);
		
		// Color
		if (_roMesh.VCs)
			oCurVC.Assign( _roMesh.VCs[iIdx] );
		else
			oCurVC.Assign(oDefVC);
		
		// TexCoord
		if (_roMesh.UVs)
			oCurUV.Assign( _roMesh.UVs[iIdx] );
		else
			oCurUV.Assign(oDefUV);
		
		if (iTri<3)
		{
			// for the vertex 0 and 1
			oVX[iTri].Assign(oCurVX);				
			oVN[iTri].Assign(oCurVN);
			oVC[iTri].Assign(oCurVC);
			oUV[iTri].Assign(oCurUV);
		}
		else
		{
			if (iTri>3)
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
			for (iVert=0;iVert<3;iVert++)
			{
				poTriScn->Tris[iTri].VXs[iVert].Assign(oVX[iVert]);
				poTriScn->Tris[iTri].VNs[iVert].Assign(oVN[iVert]);
				poTriScn->Tris[iTri].VCs[iVert].Assign(oVC[iVert]);
				poTriScn->Tris[iTri].UVs[iVert].Assign(oUV[iVert]);
				poTriScn->Tris[iTri].Material = _iMat;
			}
		}
	}

	return( poTriScn );
  //## end SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriStripMesh%1009552658.body
}

// Additional Declarations
  //## begin SCNUt_Mesh2TriScene%3C2BD25F0321.declarations preserve=yes
  //## end SCNUt_Mesh2TriScene%3C2BD25F0321.declarations

//## begin module%3C2BD25F0321.epilog preserve=yes
//## end module%3C2BD25F0321.epilog
