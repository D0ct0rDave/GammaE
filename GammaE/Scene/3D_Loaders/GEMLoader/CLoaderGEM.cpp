//## begin module%3B8B8D1A011C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8B8D1A011C.cm

//## begin module%3B8B8D1A011C.cp preserve=no
//## end module%3B8B8D1A011C.cp

//## Module: CLoaderGEM%3B8B8D1A011C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\GEMLoader\CLoaderGEM.cpp

//## begin module%3B8B8D1A011C.additionalIncludes preserve=no
//## end module%3B8B8D1A011C.additionalIncludes

//## begin module%3B8B8D1A011C.includes preserve=yes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileSys/GammaE_FileSys.h"
#include "Memory/GammaE_Mem.h"
#include "GEMFile.h"

//## end module%3B8B8D1A011C.includes

// CLoaderGEM
#include "Scene\3D_Loaders\GEMLoader\CLoaderGEM.h"
//## begin module%3B8B8D1A011C.additionalDeclarations preserve=yes
//## end module%3B8B8D1A011C.additionalDeclarations


// Class CLoaderGEM 

CLoaderGEM::CLoaderGEM()
  //## begin CLoaderGEM::CLoaderGEM%.hasinit preserve=no
  //## end CLoaderGEM::CLoaderGEM%.hasinit
  //## begin CLoaderGEM::CLoaderGEM%.initialization preserve=yes
  //## end CLoaderGEM::CLoaderGEM%.initialization
{
  //## begin CLoaderGEM::CLoaderGEM%.body preserve=yes
  //## end CLoaderGEM::CLoaderGEM%.body
}


CLoaderGEM::~CLoaderGEM()
{
  //## begin CLoaderGEM::~CLoaderGEM%.body preserve=yes
  //## end CLoaderGEM::~CLoaderGEM%.body
}



//## Other Operations (implementation)
CObject3D * CLoaderGEM::pLoad (char* Filename)
{
  //## begin CLoaderGEM::pLoad%999007939.body preserve=yes
	CFile			oFile;	
	CObject3D		*pObj;
	
	unsigned int	uiID;
	unsigned int	uiLenght;

	if (! Filename) return(NULL);
	if (! oFile.iOpen(Filename,"rb")) 
		return(NULL);

	oFile.iRead(&uiID,4);
	
	if (uiID != GEM_FILE_IDENTIFIER ) 
	{
		// ERROR_SetError("GEMLD0002","Bad Gamma Engine Model file");
		oFile.Close();
		return (NULL);
	}

	oFile.iRead(&uiLenght,4);
	pObj = pLoad(oFile);

	oFile.Close();	
	return (pObj);
  //## end CLoaderGEM::pLoad%999007939.body
}

CObject3D * CLoaderGEM::pLoad (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad%999007940.body preserve=yes
	unsigned char ucMajorVersion;
	unsigned char ucMinorVersion;

	ucMajorVersion = _roFile.cRead();
	ucMinorVersion = _roFile.cRead();

	if (ucMajorVersion > GEM_MAJOR_VERSION) return (NULL);
	if (ucMinorVersion > GEM_MINOR_VERSION) return (NULL);	

	return ( pLoad3DObject(_roFile) );
  //## end CLoaderGEM::pLoad%999007940.body
}

CObject3D * CLoaderGEM::pLoad3DObject (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObject%999007941.body preserve=yes
	unsigned int uiObjectID;
	unsigned int uiBlockLenght;

	_roFile.iRead(&uiObjectID,4);
	_roFile.iRead(&uiBlockLenght,4);

	switch (GEMFile_Translate_FileID2TypeID2(uiObjectID))
	{
		case e3DObj_NULL:		return (NULL);
								break;
		case e3DObj_Gen:		return (NULL);
								break;
		case e3DObj_Leaf:		return (pLoad3DObj_Leaf(_roFile));
								break;
		case e3DObj_Node:		return (pLoad3DObj_Node(_roFile));
								break;
		case e3DObj_Transf:		return (pLoad3DObj_Transf(_roFile));
								break;
		case e3DObj_AnimGen:	return (NULL);
								break;
		case e3DObj_AnimNode:	return (pLoad3DObj_AnimNode(_roFile));
								break;
		case e3DObj_AnimMesh:	return (pLoad3DObj_AnimMesh(_roFile));
								break;
		case e3DObj_AnimTransf:	return (pLoad3DObj_AnimTransf(_roFile));
								break;
		case e3DObj_AnimCfg:	return (pLoad3DObj_AnimCfg(_roFile));
								break;
		case e3DObj_AnimCfgMgr:	return (pLoad3DObj_AnimCfgMgr(_roFile));
								break;

		case e3DObj_Camera:
								break;
		case e3DObj_BSPNode:    return (pLoad3DObj_BSPNode(_roFile));
								break;
		case e3DObj_Mux:        return (pLoad3DObj_Mux(_roFile));
								break;
	}

	return (NULL);
  //## end CLoaderGEM::pLoad3DObject%999007941.body
}

CMesh * CLoaderGEM::pLoadMesh (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoadMesh%999339038.body preserve=yes
	unsigned int uiBlockSize;
	unsigned int uiID;
	
	_roFile.iRead(&uiID,4);
	_roFile.iRead(&uiBlockSize,4);

	if (uiID != GEM_MESH_IDENTIFIER)
	{
		//ERROR_SetError("GEMLD001","Mesh not found");
		_roFile.iSeek(-8,eFile_SM_Cur);
		return (NULL);
	}
	
	unsigned int uiMeshMask;
	CMesh		*Mesh = mNew CMesh;
			
	_roFile.iRead(&Mesh->usNumVerts,2);
	_roFile.iRead(&Mesh->usNumPrims,2);
	_roFile.iRead(&Mesh->eMeshType ,4);

	// mesh mask
	_roFile.iRead( &uiMeshMask,4);

	Mesh->Init(Mesh->usNumVerts,Mesh->usNumPrims,Mesh->eMeshType,uiMeshMask);

	// mesh components
	if (Mesh->VXs ) _roFile.iRead(Mesh->VXs ,Mesh->usNumVerts*sizeof(CVect3));
	if (Mesh->UVs ) _roFile.iRead(Mesh->UVs ,Mesh->usNumVerts*sizeof(CVect2));
	if (Mesh->VCs ) _roFile.iRead(Mesh->VCs ,Mesh->usNumVerts*sizeof(CVect4));
	if (Mesh->VNs ) _roFile.iRead(Mesh->VNs ,Mesh->usNumVerts*sizeof(CVect3));
	if (Mesh->UVs2) _roFile.iRead(Mesh->UVs2,Mesh->usNumVerts*sizeof(CVect2));
	if (Mesh->TNs ) _roFile.iRead(Mesh->TNs ,Mesh->usNumPrims*sizeof(CVect3));
	if (Mesh->Idxs) _roFile.iRead(Mesh->Idxs,Mesh->usNumIdxs *sizeof(unsigned short));
	
	// Save the mesh bounding volume
	Mesh->BVol = CGraphBV_FileIO::pLoadGraphBV(_roFile);
	
	return (Mesh);
  //## end CLoaderGEM::pLoadMesh%999339038.body
}

CObject3D_Leaf * CLoaderGEM::pLoad3DObj_Leaf (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_Leaf%999639507.body preserve=yes
	char			MaterialName[MAX_CARS];
	CE3D_Shader		*poShader;

	CObject3D_Leaf	*pObj = mNew CObject3D_Leaf();
				
		// Read material name
		_roFile.iRead(MaterialName,MAX_CARS);
		
		// Get material object
		poShader = CE3D_ShaderWH::poCreateShader(MaterialName);

		pObj->SetShader( poShader );

		// Write mesh
		pObj->SetMesh( pLoadMesh(_roFile) );
		pObj->SetBoundVol( pObj->poGetMesh()->GetBoundVol() );

	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_Leaf%999639507.body
}

CObject3D_Node * CLoaderGEM::pLoad3DObj_Node (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_Node%999639508.body preserve=yes
	CObject3D_Node *pObj = mNew CObject3D_Node();
	CObject3D	   *pChild;

  	unsigned int uiNumSubObjs;
	unsigned int uiObj;
		
	// Read subobject array props
	_roFile.iRead(&uiNumSubObjs,4);	
		
	pObj->Init(uiNumSubObjs);

	// read subobjects
	for (uiObj=0;uiObj<uiNumSubObjs;uiObj++)
	{
		pChild = pLoad3DObject(_roFile);
		
		if (pChild->eGetTypeID() != e3DObj_NULL)				
			pObj->iAddObject(pChild );
	}

	// Load the bounding volume
	pObj->SetBoundVol( CGraphBV_FileIO::pLoadGraphBV(_roFile) );

	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_Node%999639508.body
}

CObject3D_Transf * CLoaderGEM::pLoad3DObj_Transf (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_Transf%1019380667.body preserve=yes
	CObject3D_Transf *pObj = mNew CObject3D_Transf();	

	CVect3		oDir;
	CVect3		oSide;
	CVect3		oUp;
	CVect3		oPos;

  	// Read node transformation parameters
	_roFile.iRead(&oPos ,sizeof(CVect3));
	_roFile.iRead(&oDir ,sizeof(CVect3));
	_roFile.iRead(&oSide,sizeof(CVect3));
	_roFile.iRead(&oUp  ,sizeof(CVect3));

	// Read attached object
	pObj->SetObject( pLoad3DObject(_roFile) );

	// Set node transformation parameters
	pObj->Setup(oPos,oDir,oSide,oUp);

	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_Transf%1019380667.body
}

CObject3D_AnimNode * CLoaderGEM::pLoad3DObj_AnimNode (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_AnimNode%1001017621.body preserve=yes
	int					iMaxSubObjects;
	int					iNumSubObjects;
	int					iNumStates;
	int					iObj;
	int					iState;
	CObject3D_AnimNode	*pObj;

	// Read subobject array props
	_roFile.iRead(&iNumSubObjects,4);
	_roFile.iRead(&iMaxSubObjects,4);	
	_roFile.iRead(&iNumStates	 ,4);

	// Initialize object
	pObj = mNew CObject3D_AnimNode;
	pObj->Init(iMaxSubObjects);
	pObj->CreateStates(iNumStates);

	// Load the the bounding volume state array
	for (iState=0;iState<iNumStates;iState++)
	{
		mDel pObj->poBVolStates[iState];
		pObj->poBVolStates[iState] = CGraphBV_FileIO::pLoadGraphBV(_roFile);
	}
	pObj->SetBoundVol(pObj->poBVolStates[0]);

	// Read subobjects
	for (iObj=0;iObj<iNumSubObjects;iObj++)
		pObj->AddObject( (CObject3D_AnimGen *)pLoad3DObject( _roFile ) );

	return (pObj);	
  //## end CLoaderGEM::pLoad3DObj_AnimNode%1001017621.body
}

CObject3D_AnimMesh * CLoaderGEM::pLoad3DObj_AnimMesh (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_AnimMesh%1001017622.body preserve=yes
	int					iNumStateVXs;
	int					iNumStates;
	int					iState;
	CObject3D_AnimMesh	*pObj;
			
	// Write object fields
	_roFile.iRead(&iNumStates  ,4);
	_roFile.iRead(&iNumStateVXs,4);
	
	pObj = mNew CObject3D_AnimMesh;
	pObj->CreateStates(iNumStates,iNumStateVXs);
	
	// Load the the vertexs and normals state array
	_roFile.iRead(pObj->pMeshStates ,iNumStates*iNumStateVXs*sizeof(CVect3));
	_roFile.iRead(pObj->pNMeshStates,iNumStates*iNumStateVXs*sizeof(CVect3));

	// Load the the bounding volume state array
	for (iState=0;iState<iNumStates;iState++)
	{
		mDel pObj->pBVolStates[iState];
		pObj->pBVolStates[iState] = CGraphBV_FileIO::pLoadGraphBV(_roFile);
	}
	// pObj->SetBoundVol(pObj->pBVolStates[0]);
	
	// Load leaf node
	pObj->SetLeaf( (CObject3D_Leaf*) pLoad3DObject( _roFile ) );

	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_AnimMesh%1001017622.body
}

CObject3D_AnimTransf * CLoaderGEM::pLoad3DObj_AnimTransf (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_AnimTransf%1001017623.body preserve=yes
	CObject3D_AnimTransf	*pObj;
	
  	int iNumStates;

	// Read object fields
	_roFile.iRead(&iNumStates,4);
	
	// Create and initialize object
	pObj = mNew CObject3D_AnimTransf;
	pObj->CreateStates(iNumStates);

	_roFile.iRead(pObj->pTransStates,iNumStates*sizeof(CMatrix4x4));
	pObj->ComputeBoundVol();
	
	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_AnimTransf%1001017623.body
}

CObject3D_AnimCfg * CLoaderGEM::pLoad3DObj_AnimCfg (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_AnimCfg%1001017624.body preserve=yes
	CObject3D_AnimCfg *pObj;  	
	int iNumFrameAnims;
		
	// Read object number of object animations
	_roFile.iRead(&iNumFrameAnims,4);

	// Create and initialize object
	pObj = mNew CObject3D_AnimCfg;
	pObj->CreateFrameAnims(iNumFrameAnims);

	// Read frame animations
	_roFile.iRead(pObj->GetFrameAnim(),iNumFrameAnims*sizeof(TFrameAnimation));

	// Load attached object
	pObj->SetAnimObj ( (CObject3D_AnimGen*)pLoad3DObject( _roFile ) );
	
	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_AnimCfg%1001017624.body
}

CObject3D_AnimCfgMgr * CLoaderGEM::pLoad3DObj_AnimCfgMgr (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_AnimCfgMgr%1001017625.body preserve=yes
	CObject3D_AnimCfgMgr	*pObj;
	int						iMaxAnimObjs;
	int						iNumAnimObjs;
	int						iObj;

  	// Read object fields
	_roFile.iRead(&iMaxAnimObjs,4);
	_roFile.iRead(&iNumAnimObjs,4);

	// Create and initialize object
	pObj = mNew CObject3D_AnimCfgMgr;
	pObj->Init(iMaxAnimObjs);
	
	// Load attached objects
	for (iObj=0;iObj<iNumAnimObjs;iObj++)
		pObj->AddAnimObj( (CObject3D_AnimCfg*)pLoad3DObject( _roFile ) );
	
	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_AnimCfgMgr%1001017625.body
}

CObject3D_BSPNode * CLoaderGEM::pLoad3DObj_BSPNode (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_BSPNode%1006615362.body preserve=yes
	CObject3D_BSPNode *pObj = mNew CObject3D_BSPNode();

	// Write node transformation parameters
	_roFile.iRead(pObj->poGetPartitionPlane(),sizeof(CPlane));
	
	pObj->SetBackNode ( pLoad3DObject(_roFile) );
	pObj->SetFrontNode( pLoad3DObject(_roFile) );
	
	// Load the bounding volume
	pObj->SetBoundVol( CGraphBV_FileIO::pLoadGraphBV(_roFile) );

	return (pObj);
  //## end CLoaderGEM::pLoad3DObj_BSPNode%1006615362.body
}

CObject3D_Mux * CLoaderGEM::pLoad3DObj_Mux (CFile& _roFile)
{
  //## begin CLoaderGEM::pLoad3DObj_Mux%1006615363.body preserve=yes
	return (NULL);
  //## end CLoaderGEM::pLoad3DObj_Mux%1006615363.body
}

// Additional Declarations
  //## begin CLoaderGEM%3B8B8D1A011C.declarations preserve=yes
  //## end CLoaderGEM%3B8B8D1A011C.declarations

//## begin module%3B8B8D1A011C.epilog preserve=yes
//## end module%3B8B8D1A011C.epilog
