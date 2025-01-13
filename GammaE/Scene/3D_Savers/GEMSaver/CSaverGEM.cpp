//## begin module%3B90D31E007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B90D31E007D.cm

//## begin module%3B90D31E007D.cp preserve=no
//## end module%3B90D31E007D.cp

//## Module: CSaverGEM%3B90D31E007D; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\3D_Savers\GEMSaver\CSaverGEM.cpp

//## begin module%3B90D31E007D.additionalIncludes preserve=no
//## end module%3B90D31E007D.additionalIncludes

//## begin module%3B90D31E007D.includes preserve=yes
#include <stdio.h>
//## end module%3B90D31E007D.includes

// CSaverGEM
#include "Scene\3D_Savers\GEMSaver\CSaverGEM.h"
//## begin module%3B90D31E007D.additionalDeclarations preserve=yes
#include <stdio.h>
#include <string.h>
#include "File.h"
#include "FileSys/GammaE_FileSys.h"

 

#include "Scene/3D_Loaders/GEMLoader/GEMFile.h"
//## end module%3B90D31E007D.additionalDeclarations


// Class CSaverGEM 

CSaverGEM::CSaverGEM()
  //## begin CSaverGEM::CSaverGEM%.hasinit preserve=no
  //## end CSaverGEM::CSaverGEM%.hasinit
  //## begin CSaverGEM::CSaverGEM%.initialization preserve=yes
  //## end CSaverGEM::CSaverGEM%.initialization
{
  //## begin CSaverGEM::CSaverGEM%.body preserve=yes
  //## end CSaverGEM::CSaverGEM%.body
}


CSaverGEM::~CSaverGEM()
{
  //## begin CSaverGEM::~CSaverGEM%.body preserve=yes
  //## end CSaverGEM::~CSaverGEM%.body
}



//## Other Operations (implementation)
int CSaverGEM::iSave (CFile& _roFile, CObject3D *_pObj)
{
  //## begin CSaverGEM::iSave%999339041.body preserve=yes
	assert (_pObj   &&  "NULL Object");

	int		      iRes;
	unsigned char ucMajorVersion = GEM_MAJOR_VERSION;
	unsigned char ucMinorVersion = GEM_MINOR_VERSION;

	CFileUtils::BeginRIFFBlock( GEM_FILE_IDENTIFIER, _roFile);
		
		_roFile.iWrite(&ucMajorVersion,1);
		_roFile.iWrite(&ucMinorVersion,1);
		
		iRes = iSave3DObject(_roFile,_pObj);
		
	CFileUtils::EndRIFFBlock(_roFile);

	return (iRes);
  //## end CSaverGEM::iSave%999339041.body
}

int CSaverGEM::iSave3DObject (CFile& _roFile, CObject3D *_pObj)
{
  //## begin CSaverGEM::iSave3DObject%999339042.body preserve=yes
	
	int				iRes;
	e3DObjectTypeID	eObjType = _pObj->eGetTypeID();

	CFileUtils::BeginRIFFBlock(GEMFile_Translate_TypeID2FileID(eObjType) ,_roFile);

	switch ( eObjType )
	{
		case e3DObj_Gen:			iRes = 1;
									break;
		case e3DObj_Leaf:			iRes = iSave3DObj_Leaf(_roFile,(CObject3D_Leaf*)_pObj);
									break;
		case e3DObj_Node:			iRes = iSave3DObj_Node(_roFile,(CObject3D_Node*)_pObj);
									break;
		case e3DObj_Transf:			iRes = iSave3DObj_Transf(_roFile,(CObject3D_Transf*)_pObj);
									break;
		case e3DObj_AnimGen:		iRes = 0;
									break;
		case e3DObj_AnimNode:		iRes = iSave3DObj_AnimNode(_roFile,(CObject3D_AnimNode*)_pObj);
									break;
		case e3DObj_AnimMesh:		iRes = iSave3DObj_AnimMesh(_roFile,(CObject3D_AnimMesh*)_pObj);
									break;
		case e3DObj_AnimTransf:		iRes = iSave3DObj_AnimTransf(_roFile,(CObject3D_AnimTransf*)_pObj);
									break;
		case e3DObj_AnimCfg:		iRes = iSave3DObj_AnimCfg(_roFile,(CObject3D_AnimCfg*)_pObj);
									break;
		case e3DObj_AnimCfgMgr:		iRes = iSave3DObj_AnimCfgMgr(_roFile,(CObject3D_AnimCfgMgr*)_pObj);
									break;
		case e3DObj_BSPNode:		iRes = iSave3DObj_BSPNode(_roFile,(CObject3D_BSPNode*)_pObj);
									break;
		case e3DObj_Mux:    		iRes = iSave3DObj_Mux(_roFile,(CObject3D_Mux*)_pObj);
									break;

		default:					iRes = 0;
									break;
	}

	CFileUtils::EndRIFFBlock(_roFile);

	return(iRes);
  //## end CSaverGEM::iSave3DObject%999339042.body
}

int CSaverGEM::iSave3DObj_Leaf (CFile& _roFile, CObject3D_Leaf *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_Leaf%999339043.body preserve=yes
	char *MatName;
	char MaterialName[MAX_CARS];
				
		// Get material name
		MatName = CE3D_ShaderWH::szGetShaderName( *_pObj->poGetShader() );
		
		memset(MaterialName,0,MAX_CARS);
		if (MatName) strcpy(MaterialName, MatName);

		// Write material name
		_roFile.iWrite(MaterialName,MAX_CARS);

		// Write mesh
		iSaveMesh(_roFile,_pObj->poGetMesh());
	
	return (RES_OP_OK);

  //## end CSaverGEM::iSave3DObj_Leaf%999339043.body
}

int CSaverGEM::iSave3DObj_Node (CFile& _roFile, CObject3D_Node *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_Node%999339044.body preserve=yes

	// Count number of subobjects
	int iObj;
	int iNumSubObjects = 0;	
	for (iObj=0;iObj<_pObj->iNumSubObjs();iObj++)
		if (_pObj->poGetObject(iObj)) iNumSubObjects++;

	// Read subobject array props
	_roFile.iWrite(&iNumSubObjects,4);

	// Write subobjects
	for (iObj=0;iObj<_pObj->iNumSubObjs();iObj++)
		if ( _pObj->poGetObject(iObj) )
			iSave3DObject(_roFile,_pObj->poGetObject(iObj));			

	// Save the object bounding	volume
	CGraphBV_FileIO::iSaveGraphBV(_roFile,_pObj->poGetBoundVol());

	return (RES_OP_OK);

  //## end CSaverGEM::iSave3DObj_Node%999339044.body
}

int CSaverGEM::iSave3DObj_Transf (CFile& _roFile, CObject3D_Transf *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_Transf%1019380668.body preserve=yes

  	// Read node transformation parameters
	_roFile.iWrite(&_pObj->roPos() ,sizeof(CVect3));
	_roFile.iWrite(&_pObj->roDir() ,sizeof(CVect3));
	_roFile.iWrite(&_pObj->roSide(),sizeof(CVect3));
	_roFile.iWrite(&_pObj->roUp()  ,sizeof(CVect3));

	// Read attached object
	iSave3DObject(_roFile,_pObj->poGetObject());	

	return (RES_OP_OK);

  //## end CSaverGEM::iSave3DObj_Transf%1019380668.body
}

int CSaverGEM::iSaveMesh (CFile& _roFile, CMesh *Mesh)
{
  //## begin CSaverGEM::iSaveMesh%999339045.body preserve=yes
  	unsigned int uiMeshMask;

	CFileUtils::BeginRIFFBlock( GEM_MESH_IDENTIFIER, _roFile);

		// Setup Mesh mask
		uiMeshMask = 0;
				
		if (Mesh->VXs)  uiMeshMask |= MESH_FIELD_VERTEXS;
		if (Mesh->UVs)  uiMeshMask |= MESH_FIELD_UVCOORDS;
		if (Mesh->VCs)  uiMeshMask |= MESH_FIELD_COLORS;		
		if (Mesh->VNs)  uiMeshMask |= MESH_FIELD_VNORMALS;		
		if (Mesh->UVs2) uiMeshMask |= MESH_FIELD_UVCOORD2;
		if (Mesh->TNs)  uiMeshMask |= MESH_FIELD_TNORMALS;
		if (Mesh->Idxs) uiMeshMask |= MESH_FIELD_INDEXES;
		
		_roFile.iWrite( &Mesh->usNumVerts,2);
		_roFile.iWrite( &Mesh->usNumPrims,2);
		_roFile.iWrite( &Mesh->eMeshType ,4);

		// mesh mask
		_roFile.iWrite( &uiMeshMask,4);

		// mesh components
		if (Mesh->VXs) _roFile.iWrite(Mesh->VXs ,Mesh->usNumVerts*sizeof(CVect3));
		if (Mesh->UVs) _roFile.iWrite(Mesh->UVs ,Mesh->usNumVerts*sizeof(CVect2));
		if (Mesh->VCs) _roFile.iWrite(Mesh->VCs ,Mesh->usNumVerts*sizeof(CVect4));
		if (Mesh->VNs) _roFile.iWrite(Mesh->VNs ,Mesh->usNumVerts*sizeof(CVect3));
		if (Mesh->UVs2)_roFile.iWrite(Mesh->UVs2,Mesh->usNumVerts*sizeof(CVect2));

		if (Mesh->TNs ) _roFile.iWrite(Mesh->TNs ,Mesh->usNumPrims*sizeof(CVect3));
		if (Mesh->Idxs) _roFile.iWrite(Mesh->Idxs,Mesh->usNumIdxs *sizeof(unsigned short));

		// Save the mesh bounding volume
		CGraphBV_FileIO::iSaveGraphBV(_roFile,Mesh->GetBoundVol());		
	
	CFileUtils::EndRIFFBlock(_roFile);
	
	return (RES_OP_OK);
  //## end CSaverGEM::iSaveMesh%999339045.body
}

int CSaverGEM::iSave3DObj_AnimNode (CFile& _roFile, CObject3D_AnimNode *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_AnimNode%1000932997.body preserve=yes
	int iMaxSubObjects;
	int iNumSubObjects;
	int iNumStates;
	int iObj;
	int iState;

	iNumSubObjects = _pObj->iNumObjs;	
	iMaxSubObjects = _pObj->iMaxObjs;
	iNumStates     = _pObj->iGetNumStates();

	// Write subobject array props
	_roFile.iWrite(&iNumSubObjects,4);
	_roFile.iWrite(&iMaxSubObjects,4);
	_roFile.iWrite(&iNumStates	  ,4);

	// Save the the bounding volume state array
	for (iState=0;iState<iNumStates;iState++)
		CGraphBV_FileIO::iSaveGraphBV(_roFile,_pObj->poGetStateBVol(iState));	

	// Write subobjects
	for (iObj=0;iObj<iMaxSubObjects;iObj++)
		if ( _pObj->poObjs[iObj] ) iSave3DObject(_roFile,_pObj->poObjs[iObj]);

	return (RES_OP_OK);
  //## end CSaverGEM::iSave3DObj_AnimNode%1000932997.body
}

int CSaverGEM::iSave3DObj_AnimMesh (CFile& _roFile, CObject3D_AnimMesh *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_AnimMesh%1000932998.body preserve=yes
	int iNumStateVXs;
	int iNumStates;
	int iState;
			
	iNumStateVXs   = _pObj->iNumStateVXs;
	iNumStates     = _pObj->iGetNumStates();

	// Write object fields
	_roFile.iWrite(&iNumStates	,4);
	_roFile.iWrite(&iNumStateVXs,4);

	// Save the the vertexs and normals state array
	_roFile.iWrite(_pObj->pMeshStates ,iNumStates*iNumStateVXs*sizeof(CVect3));
	_roFile.iWrite(_pObj->pNMeshStates,iNumStates*iNumStateVXs*sizeof(CVect3));

	// Save the the bounding volume state array
	for (iState=0;iState<iNumStates;iState++)
		CGraphBV_FileIO::iSaveGraphBV(_roFile,_pObj->poGetStateBVol(iState));	
	
	// Save leaf node
	iSave3DObject( _roFile,_pObj->GetLeaf() );
	
	return (RES_OP_OK);
  //## end CSaverGEM::iSave3DObj_AnimMesh%1000932998.body
}

int CSaverGEM::iSave3DObj_AnimTransf (CFile& _roFile, CObject3D_AnimTransf *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_AnimTransf%1000932999.body preserve=yes
	int iNumStates= _pObj->iGetNumStates();

	// Write object fields
	_roFile.iWrite(&iNumStates	 ,4);
	_roFile.iWrite(_pObj->pTransStates,iNumStates*sizeof(CMatrix4x4));
	
	return (RES_OP_OK);
  //## end CSaverGEM::iSave3DObj_AnimTransf%1000932999.body
}

int CSaverGEM::iSave3DObj_AnimCfg (CFile& _roFile, CObject3D_AnimCfg *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_AnimCfg%1000933000.body preserve=yes

	// Write object fields
	_roFile.iWrite(&_pObj->iNumFrameAnims,4);
	_roFile.iWrite(_pObj->GetFrameAnim(),_pObj->iNumFrameAnims*sizeof(TFrameAnimation));

	// Save attached object
	iSave3DObject( _roFile, _pObj->GetAnimObj() );
	
	return (RES_OP_OK);
  //## end CSaverGEM::iSave3DObj_AnimCfg%1000933000.body
}

int CSaverGEM::iSave3DObj_AnimCfgMgr (CFile& _roFile, CObject3D_AnimCfgMgr *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_AnimCfgMgr%1000933001.body preserve=yes
	// Write object fields
	_roFile.iWrite(&_pObj->iMaxAnimObjs,4);
	_roFile.iWrite(&_pObj->iNumAnimObjs,4);
	
	for (int iObj=0;iObj<_pObj->iMaxAnimObjs;iObj++)
		if (_pObj->pAnimObjs[iObj])
			// Save attached objects
			iSave3DObject(_roFile, _pObj->pAnimObjs[iObj] );
	
	return (RES_OP_OK);
  //## end CSaverGEM::iSave3DObj_AnimCfgMgr%1000933001.body
}

int CSaverGEM::iSave3DObj_BSPNode (CFile& _roFile, CObject3D_BSPNode *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_BSPNode%1006615360.body preserve=yes

	// Write node transformation parameters
	_roFile.iWrite(_pObj->poGetPartitionPlane(),sizeof(CPlane));
	
	iSave3DObject(_roFile,_pObj->poGetBackNode());
	iSave3DObject(_roFile,_pObj->poGetFrontNode());

	// Save the object bounding	volume
	CGraphBV_FileIO::iSaveGraphBV(_roFile,_pObj->poGetBoundVol());

	return (RES_OP_OK);
  //## end CSaverGEM::iSave3DObj_BSPNode%1006615360.body
}

int CSaverGEM::iSave3DObj_Mux (CFile& _roFile, CObject3D_Mux *_pObj)
{
  //## begin CSaverGEM::iSave3DObj_Mux%1006615361.body preserve=yes
	return(RES_OP_ERROR);
  //## end CSaverGEM::iSave3DObj_Mux%1006615361.body
}

int CSaverGEM::iSave (char *_Filename, CObject3D* _pObj)
{
  //## begin CSaverGEM::iSave%999339047.body preserve=yes
	CFile	oFile;
	int		iRes;

	if (! oFile.iOpen(_Filename,"wb"))
	{
		// ERROR_SetError("GEMSAV0002","Unable to open file for saving:",_Filename);
		return(RES_OP_ERROR);
	}
	
	iRes = iSave(oFile,_pObj);

	oFile.Close();

	return ( iRes );
  //## end CSaverGEM::iSave%999339047.body
}

// Additional Declarations
  //## begin CSaverGEM%3B90D31E007D.declarations preserve=yes
  //## end CSaverGEM%3B90D31E007D.declarations

//## begin module%3B90D31E007D.epilog preserve=yes
//## end module%3B90D31E007D.epilog
