



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



SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate (CMesh& _oMesh, int _iMat)
{
  	switch (_oMesh.eMeshType)
	{		
		case E3D_MESH_NONE:			
		{
			return(NULL);
		}
		break;

		case E3D_MESH_TRIS:
		{
			return(Generate_FromIndexedTriMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_QUADS:
		{
			return(Generate_FromIndexedQuadMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_TRIFANS:
		{
			return(Generate_FromIndexedTriFanMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_TRISTRIPS:
		{
			return(Generate_FromIndexedTriStripMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_QUADSTRIPS:
		{
			return(Generate_FromIndexedQuadStripMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_NITRIS:		
		{
			return(Generate_FromNonIndexedTriMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_NIQUADS:	
		{
			return(Generate_FromNonIndexedQuadMesh(_oMesh,_iMat));
		}
		break;
		
		case E3D_MESH_NITRISTRIP:
		{
			return(Generate_FromNonIndexedTriStripMesh(_oMesh,_iMat));
		}
		break;

		default:
		return(NULL);
	}
		
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriMesh (CMesh& _oMesh, int _iMat)
{
  	if (! _oMesh.Idxs) return(NULL);

	if ((! _oMesh.VXs) &&
		(! _oMesh.VCs) &&
		(! _oMesh.VNs) &&
		(! _oMesh.UVs)) return(NULL);

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
	poTriScn->Init(_oMesh.usNumPrims);
	
	for (iTri=0;iTri<_oMesh.usNumPrims;iTri++)
	{	
		for (iVert=0;iVert<3;iVert++)
		{
			iIdx = _oMesh.Idxs[ iTri*3+iVert ];

			// Vertex
			if (_oMesh.VXs)
				oCurVX.Assign( _oMesh.VXs[iIdx] );
			else
				oCurVX.Assign(oDefVX);
			
			// Normal
			if (_oMesh.VNs)
				oCurVN.Assign( _oMesh.VNs[iIdx] );
			else
				oCurVN.Assign(oDefVN);
			
			// Color
			if (_oMesh.VCs)
				oCurVC.Assign( *(CVect4*)&_oMesh.VCs[iIdx] );
			else
				oCurVC.Assign(oDefVC);
			
			// TexCoord
			if (_oMesh.UVs)
				oCurUV.Assign( _oMesh.UVs[iIdx] );
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
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedQuadMesh (CMesh& _oMesh, int _iMat)
{
  	return(NULL);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriStripMesh (CMesh& _oMesh, int _iMat)
{
    	if (! _oMesh.Idxs) return(NULL);
	
	if ((! _oMesh.VXs) &&
		(! _oMesh.VCs) &&
		(! _oMesh.VNs) &&
		(! _oMesh.UVs)) return(NULL);

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
	
	SCNUt_TriScene *poTriScn = mNew SCNUt_TriScene;	
	poTriScn->Init( _oMesh.usNumPrims );
	
	for (uint i=0;i<_oMesh.usNumIdxs;i++)
	{	
		int iIdx = _oMesh.Idxs[ i ];

		// Vertex
		if (_oMesh.VXs)
			oCurVX.Assign( _oMesh.VXs[iIdx] );
		else
			oCurVX.Assign(oDefVX);
		
		// Normal
		if (_oMesh.VNs)
			oCurVN.Assign( _oMesh.VNs[iIdx] );
		else
			oCurVN.Assign(oDefVN);
		
		// Color
		if (_oMesh.VCs)
			oCurVC.Assign( *(CVect4*)&_oMesh.VCs[iIdx] );
		else
			oCurVC.Assign(oDefVC);
		
		// TexCoord
		if (_oMesh.UVs)
			oCurUV.Assign( _oMesh.UVs[iIdx] );
		else
			oCurUV.Assign(oDefUV);
		
		// Vertex 0 is swapped with previous iteration Vertex 1
		// Vertex 1 is swapped with previous iteration Vertex 2
		// Vertex 2 is always updated with new info
				
		if (i<3)
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

		if (i >= 2)
		{
			// --------------------------------------------
			// Setup triangle: only when 3 or more processed vertices 
			// --------------------------------------------
			for (uint uiVert=0;uiVert<3;uiVert++)
			{
				uint uiTri = i-2;
				
				if ((uiTri & 0x01) == 0)
				{
					poTriScn->Tris[uiTri].VXs[uiVert].Assign(oVX[uiVert]);
					poTriScn->Tris[uiTri].VNs[uiVert].Assign(oVN[uiVert]);
					poTriScn->Tris[uiTri].VCs[uiVert].Assign(oVC[uiVert]);
					poTriScn->Tris[uiTri].UVs[uiVert].Assign(oUV[uiVert]);
					poTriScn->Tris[uiTri].Material = _iMat;
				}
				else
				{
					poTriScn->Tris[uiTri].VXs[uiVert].Assign(oVX[2-uiVert]);
					poTriScn->Tris[uiTri].VNs[uiVert].Assign(oVN[2-uiVert]);
					poTriScn->Tris[uiTri].VCs[uiVert].Assign(oVC[2-uiVert]);
					poTriScn->Tris[uiTri].UVs[uiVert].Assign(oUV[2-uiVert]);
					poTriScn->Tris[uiTri].Material = _iMat;				
				}
			}
		}
	}

	return( poTriScn );
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedTriFanMesh (CMesh& _oMesh, int _iMat)
{
    	if (! _oMesh.Idxs) return(NULL);
	
	if ((! _oMesh.VXs) &&
		(! _oMesh.VCs) &&
		(! _oMesh.VNs) &&
		(! _oMesh.UVs)) return(NULL);

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
	poTriScn->Init( _oMesh.usNumPrims );
	
	for (iTri=0;iTri<_oMesh.usNumIdxs;iTri++)
	{	
		iIdx = _oMesh.Idxs[ iTri ];

		// Vertex
		if (_oMesh.VXs)
			oCurVX.Assign( _oMesh.VXs[iIdx] );
		else
			oCurVX.Assign(oDefVX);
		
		// Normal
		if (_oMesh.VNs)
			oCurVN.Assign( _oMesh.VNs[iIdx] );
		else
			oCurVN.Assign(oDefVN);
		
		// Color
		if (_oMesh.VCs)
			oCurVC.Assign( *(CVect4*)&_oMesh.VCs[iIdx] );
		else
			oCurVC.Assign(oDefVC);
		
		// TexCoord
		if (_oMesh.UVs)
			oCurUV.Assign( _oMesh.UVs[iIdx] );
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

}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromIndexedQuadStripMesh (CMesh& _oMesh, int _iMat)
{
    	return(NULL);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriMesh (CMesh& _oMesh, int _iMat)
{
  	if ((! _oMesh.VXs) &&
		(! _oMesh.VCs) &&
		(! _oMesh.VNs) &&
		(! _oMesh.UVs)) return(NULL);

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
	poTriScn->Init(_oMesh.usNumPrims);
	
	for (iTri=0;iTri<_oMesh.usNumPrims;iTri++)
	{	
		for (iVert=0;iVert<3;iVert++)
		{
			iIdx = iTri*3+iVert;

			// Vertex
			if (_oMesh.VXs)
				oCurVX.Assign( _oMesh.VXs[iIdx] );
			else
				oCurVX.Assign(oDefVX);
			
			// Normal
			if (_oMesh.VNs)
				oCurVN.Assign( _oMesh.VNs[iIdx] );
			else
				oCurVN.Assign(oDefVN);
			
			// Color
			if (_oMesh.VCs)
				oCurVC.Assign( *(CVect4*)&_oMesh.VCs[iIdx] );
			else
				oCurVC.Assign(oDefVC);
			
			// TexCoord
			if (_oMesh.UVs)
				oCurUV.Assign( _oMesh.UVs[iIdx] );
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
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedQuadMesh (CMesh& _oMesh, int _iMat)
{
  	return(NULL);
}

SCNUt_TriScene* SCNUt_Mesh2TriScene::Generate_FromNonIndexedTriStripMesh (CMesh& _oMesh, int _iMat)
{
  	if ((! _oMesh.VXs) &&
		(! _oMesh.VCs) &&
		(! _oMesh.VNs) &&
		(! _oMesh.UVs)) return(NULL);

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
	poTriScn->Init( _oMesh.usNumPrims );
	
	for (iTri=0;iTri<_oMesh.usNumIdxs;iTri++)
	{	
		iIdx = iTri;

		// Vertex
		if (_oMesh.VXs)
			oCurVX.Assign( _oMesh.VXs[iIdx] );
		else
			oCurVX.Assign(oDefVX);
		
		// Normal
		if (_oMesh.VNs)
			oCurVN.Assign( _oMesh.VNs[iIdx] );
		else
			oCurVN.Assign(oDefVN);
		
		// Color
		if (_oMesh.VCs)
			oCurVC.Assign(*(CVect4*)& _oMesh.VCs[iIdx] );
		else
			oCurVC.Assign(oDefVC);
		
		// TexCoord
		if (_oMesh.UVs)
			oCurUV.Assign( _oMesh.UVs[iIdx] );
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
}

// Additional Declarations
    
