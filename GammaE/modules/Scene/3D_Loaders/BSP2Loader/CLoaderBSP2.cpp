//## begin module%3C5850920196.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C5850920196.cm

//## begin module%3C5850920196.cp preserve=no
//## end module%3C5850920196.cp

//## Module: CLoaderBSP2%3C5850920196; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\BSP2Loader\CLoaderBSP2.cpp

//## begin module%3C5850920196.additionalIncludes preserve=no
//## end module%3C5850920196.additionalIncludes

//## begin module%3C5850920196.includes preserve=yes
#include <stdio.h>
#include <string.h>
#include "Memory/GammaE_Mem.h"
#include "tex.h"
//## end module%3C5850920196.includes

// CLoaderBSP2
#include "Scene\3D_Loaders\BSP2Loader\CLoaderBSP2.h"
//## begin module%3C5850920196.additionalDeclarations preserve=yes

// Quake2 engine uses FRONT as cull face
#define _REVERSE_WINDING_

//## end module%3C5850920196.additionalDeclarations


// Class CLoaderBSP2 

























CLoaderBSP2::CLoaderBSP2()
  //## begin CLoaderBSP2::CLoaderBSP2%.hasinit preserve=no
      : pVXs(NULL), iNumVXs(0), pEdges(NULL), iNumEdges(0), pFaces(NULL), iNumFaces(0), pLFaces(NULL), iNumLFaces(0), pFEdges(NULL), iNumFEdges(0), pPlanes(NULL), iNumPlanes(0), pNodes(NULL), iNumNodes(0), pLeaves(NULL), iNumLeaves(0), pTexInfo(NULL), pExtTexInfo(NULL), iNumTexs(0), pVIS(NULL), iNumVis(0), poScnLeaves(NULL)
  //## end CLoaderBSP2::CLoaderBSP2%.hasinit
  //## begin CLoaderBSP2::CLoaderBSP2%.initialization preserve=yes
  //## end CLoaderBSP2::CLoaderBSP2%.initialization
{
  //## begin CLoaderBSP2::CLoaderBSP2%.body preserve=yes
  //## end CLoaderBSP2::CLoaderBSP2%.body
}


CLoaderBSP2::~CLoaderBSP2()
{
  //## begin CLoaderBSP2::~CLoaderBSP2%.body preserve=yes
	if (pVXs	   ) mDel []pVXs;
	if (pPlanes	   ) mDel []pPlanes;
	if (pNodes	   ) mDel []pNodes;
	if (pLeaves    ) mDel []pLeaves;
	if (pLFaces    ) mDel []pLFaces;
	if (pFaces     ) mDel []pFaces;
	if (pEdges     ) mDel []pEdges;
	if (pFEdges    ) mDel []pFEdges;
	if (pTexInfo   ) mDel []pTexInfo;
	if (pExtTexInfo) mDel []pExtTexInfo;
  //## end CLoaderBSP2::~CLoaderBSP2%.body
}



//## Other Operations (implementation)
CObject3D * CLoaderBSP2::pLoad (char* Filename)
{
  //## begin CLoaderBSP2::pLoad%1012420867.body preserve=yes
	FILE		*fd;	
		
	// open file
	fd = fopen(Filename,"rb");
	if (! fd)
	{
		return (NULL);
	}	

	//	read header
	fread(&oBSPhdr, 1, sizeof(bsp_header), fd);

	if ( strncmp((char*)&oBSPhdr.magic,"IBSP",4) || oBSPhdr.version != 38)
	{
		fclose(fd);
		return (NULL);
	}	
	
	
	//---------------------------------------------------------------
	bsp_lump	*pLump;

	#define READ_LUMP(LumpID,iNumElems,pBuffer,st_type)				\
																	\
					pLump     = &oBSPhdr.lump[ LumpID ];			\
					iNumElems = pLump->lenght / sizeof(st_type);	\
					pBuffer   = mNew st_type[iNumElems];			\
																	\
					fseek(fd,pLump->offset,SEEK_SET);				\
					fread(pBuffer,pLump->lenght,1,fd);
	
	//---------------------------------------------------------------




	// read Vertex lump
	READ_LUMP(BSP_VERTEXS_LUMP,iNumVXs,pVXs,bsp_point3f);

	// read plane lump
	READ_LUMP(BSP_PLANES_LUMP,iNumPlanes,pPlanes,bsp_plane);

	// read nodes lump
	READ_LUMP(BSP_NODES_LUMP,iNumNodes,pNodes,bsp_node);

	// read leaves lump
	READ_LUMP(BSP_LEAVES_LUMP,iNumLeaves,pLeaves,bsp_leaf);

	// read leaf face table lump
	READ_LUMP(BSP_LFT_LUMP,iNumLFaces,pLFaces,bsp_leaf_face);

	// read faces lump
	READ_LUMP(BSP_FACES_LUMP,iNumFaces,pFaces,bsp_face);
	
	// read edges lump
	READ_LUMP(BSP_EDGES_LUMP,iNumEdges,pEdges,bsp_edge);

	// read face edge table lump
	READ_LUMP(BSP_FET_LUMP,iNumFEdges,pFEdges,bsp_face_edge);
		
	// read tex info lump
	READ_LUMP(BSP_TEXINFO_LUMP,iNumTexs,pTexInfo,bsp_texinfo);
	pExtTexInfo = mNew ext_texinfo[iNumTexs];
	SetExtendedTexInfo();

	CObject3D *poObj = poProcessBSP();

	fclose(fd);
	
	return (poObj);
  //## end CLoaderBSP2::pLoad%1012420867.body
}

void CLoaderBSP2::SetExtendedTexInfo ()
{
  //## begin CLoaderBSP2::SetExtendedTexInfo%1012723808.body preserve=yes
	char		szMat[512];
	int			iTex;
	
	for (iTex=0;iTex<iNumTexs;iTex++)
	{
		sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ iTex ].texture_name);
		Texture* texture = poLoadTexture(szMat);
		if (texture != NULL)
		{
			pExtTexInfo[iTex].iWidth = texture->width;
			pExtTexInfo[iTex].iHeight= texture->height;
			pExtTexInfo[iTex].pBTI   = &pTexInfo[iTex];
		
			DestroyTexture(texture);
		}
	}

  //## end CLoaderBSP2::SetExtendedTexInfo%1012723808.body
}

CObject3D * CLoaderBSP2::poProcessBSP ()
{
  //## begin CLoaderBSP2::poProcessBSP%1012420868.body preserve=yes
	CObject3D  *poObj;	
	
	poObj = poGenerateNode(&pNodes[0]);
	poObj->ComputeBoundVol();

 	return (poObj);
  //## end CLoaderBSP2::poProcessBSP%1012420868.body
}

CObject3D * CLoaderBSP2::poGenerateLeaf (bsp_leaf *_pLeaf)
{
  //## begin CLoaderBSP2::poGenerateLeaf%1012428862.body preserve=yes
	if (! _pLeaf->num_leaf_faces) return(NULL);

	SCNUt_TriSceneAccumulator	oTScn;
	SCNUt_TriSceneSeparator		oTSep;
	SCNUt_MeshGenerator			oMGen;
	CE3D_Shader					*poShader;	
	
	int							iFace;
	int							iRealFace;
	char						szMat[512];

	for (iFace=0;iFace<_pLeaf->num_leaf_faces;iFace++)
	{
		iRealFace = pLFaces[_pLeaf->first_leaf_face + iFace].index;

		assert( ((iRealFace>=0) && (iRealFace<iNumFaces)) &&
				"BSP face index out bounds");

		AddFace(&pFaces[iRealFace],&oTScn);
	}

	// Now we have processed all the faces from this leaf node, convert q2 leaf into
	// a GammaE node
	CObject3D *poObj;
	oTSep.SeparateScene(oTScn);

	if (oTSep.NumMeshes > 1) 
	{
		CObject3D_Node	*poNode = mNew CObject3D_Node;
		CObject3D_Leaf	*poLeaf;
		CMesh			*poMesh;
		
		poNode->Init(oTSep.NumMeshes);

		for (int iObj=0;iObj<oTSep.NumMeshes;iObj++)
		{	
			sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[iObj] ].texture_name);

			poShader = CE3D_ShaderWH::poCreateShader(szMat);

			poLeaf = mNew CObject3D_Leaf;

			poMesh = oMGen.GenerateMesh(oTSep.Meshes[iObj]);			
			poLeaf->SetMesh  (poMesh);
			poLeaf->SetShader(poShader);	// que coño pasa con el material !!!!!

			poNode->iAddObject(poLeaf);
		}

		poObj = poNode;
	}
	else
	{
		sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[0] ].texture_name);

		CE3D_Shader		*poShader = CE3D_ShaderWH::poCreateShader(pTexInfo[ oTSep.piMatIdx[0] ].texture_name);

		CObject3D_Leaf	*poLeaf   = mNew CObject3D_Leaf;
		CMesh			*poMesh   = oMGen.GenerateMesh(oTSep.Meshes[0]);

		poLeaf->SetMesh  (poMesh);
		poLeaf->SetShader(poShader);	// que coño pasa con el material !!!!!
									
		poObj = poLeaf;
	}

	
	return (poObj);	
  //## end CLoaderBSP2::poGenerateLeaf%1012428862.body
}

CObject3D * CLoaderBSP2::poGenerateNode (bsp_node* _pNode)
{
  //## begin CLoaderBSP2::poGenerateNode%1012576246.body preserve=yes
	CObject3D_BSPNode	*poBSPNode = NULL;
	CObject3D			*poBackScn = NULL;
	CObject3D			*poFrontScn= NULL;
	CObject3D			*poNodeScn = NULL;

	// Set the back node
	if (_pNode->back_child >= 0)
		// A node
		poBackScn = poGenerateNode(&pNodes[_pNode->back_child]);
	else 
		// A Leaf		
		poBackScn = poGenerateLeaf(&pLeaves[-1*_pNode->back_child]);

	// Set the front node
	if (_pNode->front_child >= 0)
		// A node
		poFrontScn = poGenerateNode(&pNodes[_pNode->front_child]);
	else
		// A Leaf
		poFrontScn = poGenerateLeaf(&pLeaves[-1*_pNode->front_child]);
	
	// DO NOT Load intermediate geometry (only leaf geometry)
	// poNodeScn = poGenerateNodeMesh(_pNode,_MatWH);


	if ((! poBackScn) && (! poFrontScn) && (! poNodeScn))
		return(NULL);	// NULL Node ???


	if ((poBackScn) || (poFrontScn))
	{
		// Get the partition plane
		CPlane		oPlane;
		CVect3		oOrigin;
		CVect3		oPNormal;

		bsp_plane	*pPlane = &pPlanes[ _pNode->plane ];
		oPNormal.V3(pPlane->normal.x,
					pPlane->normal.y,
					pPlane->normal.z);
		oOrigin.Assign(oPNormal);
		oOrigin.Scale (pPlane->distance);
		oPlane.GeneratePlaneFromFields(oOrigin,oPNormal);

		// Create & Setup BSP
		poBSPNode = mNew CObject3D_BSPNode;	
		poBSPNode->SetBackNode (poBackScn );
		poBSPNode->SetFrontNode(poFrontScn);
		poBSPNode->SetPartitionPlane(oPlane);
	}

	if (poNodeScn)
	{
		if (poBSPNode)
		{
			CObject3D_Node *poNode;
			poNode = mNew CObject3D_Node;

			poNode->Init(poBSPNode?2:1);
			poNode->iAddObject(poNodeScn);
			poNode->iAddObject(poBSPNode);
			
			return (poNode);
		}
		else
			return (poNodeScn);
	}
	else
		return (poBSPNode);
  //## end CLoaderBSP2::poGenerateNode%1012576246.body
}

CObject3D * CLoaderBSP2::poGenerateNodeMesh (bsp_node* _pNode)
{
  //## begin CLoaderBSP2::poGenerateNodeMesh%1012576247.body preserve=yes
	if (! _pNode->num_faces) return(NULL);

	SCNUt_TriSceneAccumulator	oTScn;
	SCNUt_TriSceneSeparator		oTSep;
	SCNUt_MeshGenerator			oMGen;
	CE3D_Shader					*poShader;	
	
	int							iFace;
	int							iRealFace;
	char						szMat[512];

	for (iFace=0;iFace<_pNode->num_faces;iFace++)
	{
		iRealFace = pLFaces[_pNode->num_faces + iFace].index;

		assert( ((iRealFace>=0) && (iRealFace<iNumFaces)) &&
				"BSP face index out bounds");

		AddFace(&pFaces[iRealFace],&oTScn);
	}

	// Now we have processed all the faces from this leaf node, convert q2 leaf into
	// a GammaE node
	CObject3D *poObj;
	oTSep.SeparateScene(oTScn);

	if (oTSep.NumMeshes > 1) 
	{
		CObject3D_Node	*poNode = mNew CObject3D_Node;
		CObject3D_Leaf	*poLeaf;
		CMesh			*poMesh;
		
		poNode->Init(oTSep.NumMeshes);

		for (int iObj=0;iObj<oTSep.NumMeshes;iObj++)
		{	
			sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[iObj] ].texture_name);

			poShader = CE3D_ShaderWH::poCreateShader(szMat);

			poLeaf = mNew CObject3D_Leaf;

			poMesh = oMGen.GenerateMesh(oTSep.Meshes[iObj]);
			poLeaf->SetMesh(poMesh);
			poLeaf->SetShader(poShader);	// que coño pasa con el material !!!!!

			poNode->iAddObject(poLeaf);
		}

		poObj = poNode;
	}
	else
	{
		sprintf(szMat,"%s/%s.wal",szQ2BaseDir,pTexInfo[ oTSep.piMatIdx[0] ].texture_name);
		
		poShader = CE3D_ShaderWH::poCreateShader(szMat);

		CObject3D_Leaf	*poLeaf = mNew CObject3D_Leaf;
		CMesh			*poMesh = oMGen.GenerateMesh(oTSep.Meshes[0]);

		poLeaf->SetMesh(poMesh);
		poLeaf->SetShader(poShader);		// que coño pasa con el material !!!!!
									
		poObj = poLeaf;
	}

	return (poObj);	
  //## end CLoaderBSP2::poGenerateNodeMesh%1012576247.body
}

void CLoaderBSP2::AddFace (bsp_face *pFace, SCNUt_TriSceneAccumulator *_pTScn)
{
  //## begin CLoaderBSP2::AddFace%1012428863.body preserve=yes
	SCNUt_TriScene oTScn;
	SCNUt_Triangle *pTri;	

	int			iEdge;
	int			iRealEdge;
	int			iVXs[32];		

	// Create vertex and edge lists
	for (iEdge=0;iEdge<pFace->num_edges;iEdge++)
	{
		iRealEdge = pFEdges[pFace->first_edge + iEdge].index;
		
		if (iRealEdge > 0)
		{
			iVXs[iEdge] = pEdges[iRealEdge].start;			
		}
		else
		{
			iVXs[iEdge] = pEdges[-iRealEdge].end;		
		}
	}

	// triangulate face	
	ext_texinfo *pETI = &pExtTexInfo[pFace->texture_info];
	
	int			i0,i1,i2;

	// ----------------------------------------------------------
	#define COMPUTE_UCOORD(VX,ETI)		\
				((VX.X() * ETI->pBTI->u_axis.x +	\
				  VX.Y() * ETI->pBTI->u_axis.y +	\
				  VX.Z() * ETI->pBTI->u_axis.z + ETI->pBTI->u_offset)/ETI->iWidth)

	#define COMPUTE_VCOORD(VX,ETI)		\
				((VX.X() * ETI->pBTI->v_axis.x +	\
				  VX.Y() * ETI->pBTI->v_axis.y +	\
				  VX.Z() * ETI->pBTI->v_axis.z + ETI->pBTI->v_offset)/ETI->iHeight)

	// En realidad se debe dividir por el Width y height de la
	// textura!!!->GL_BuildPolygonFromSurface del src de Q2
	// ----------------------------------------------------------

	oTScn.Init(pFace->num_edges-2);
	pTri	= oTScn.Tris;
	i0		= iVXs[0];

	// Setup other triangle data
	for (iEdge=2;iEdge<pFace->num_edges;iEdge++)
	{		
		i1 = iVXs[iEdge -1];
		i2 = iVXs[iEdge   ];
		
		#ifdef _REVERSE_WINDING_
		pTri->VXs[2].V3(pVXs[i0].x,pVXs[i0].y,pVXs[i0].z);
		pTri->VXs[1].V3(pVXs[i1].x,pVXs[i1].y,pVXs[i1].z);
		pTri->VXs[0].V3(pVXs[i2].x,pVXs[i2].y,pVXs[i2].z);
		#else
		pTri->VXs[0].V3(pVXs[i0].x,pVXs[i0].y,pVXs[i0].z);
		pTri->VXs[1].V3(pVXs[i1].x,pVXs[i1].y,pVXs[i1].z);
		pTri->VXs[2].V3(pVXs[i2].x,pVXs[i2].y,pVXs[i2].z);
		#endif
	
		pTri->UVs[0].V2(COMPUTE_UCOORD(pTri->VXs[0],pETI),COMPUTE_VCOORD(pTri->VXs[0],pETI));
		pTri->UVs[1].V2(COMPUTE_UCOORD(pTri->VXs[1],pETI),COMPUTE_VCOORD(pTri->VXs[1],pETI));
		pTri->UVs[2].V2(COMPUTE_UCOORD(pTri->VXs[2],pETI),COMPUTE_VCOORD(pTri->VXs[2],pETI));
		SCNUt_TriUtils::MinimizeMappingOffset(*pTri);

		pTri->VCs[0].V4(1.0f,1.0f,1.0f,1.0f);
		pTri->VCs[1].V4(1.0f,1.0f,1.0f,1.0f);
		pTri->VCs[2].V4(1.0f,1.0f,1.0f,1.0f);

		// VNs ???
		pTri->Material = pFace->texture_info;

		pTri++;
	}

	// Add the new triangles!
	_pTScn->AddTriScene(&oTScn);
  //## end CLoaderBSP2::AddFace%1012428863.body
}

void CLoaderBSP2::SetQ2BaseDir (char *_szDirectory)
{
  //## begin CLoaderBSP2::SetQ2BaseDir%1012510461.body preserve=yes
	strcpy(szQ2BaseDir,_szDirectory);
  //## end CLoaderBSP2::SetQ2BaseDir%1012510461.body
}

// Additional Declarations
  //## begin CLoaderBSP2%3C5850920196.declarations preserve=yes
  //## end CLoaderBSP2%3C5850920196.declarations

//## begin module%3C5850920196.epilog preserve=yes
//## end module%3C5850920196.epilog
