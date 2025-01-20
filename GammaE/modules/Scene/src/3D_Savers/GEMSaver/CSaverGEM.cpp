#include <stdio.h>

// CSaverGEM
#include "3D_Savers\GEMSaver\CSaverGEM.h"
#include <stdio.h>
#include <string.h>
#include "GammaE_FileSys.h"

#include "../../3D_Loaders/GEMLoader/GEMFile.h"

// Class CSaverGEM

CSaverGEM::CSaverGEM()
{
}

CSaverGEM::~CSaverGEM()
{
}

int CSaverGEM::iSave (CFile & _oFile, CObject3D *_pObj)
{
    assert (_pObj   &&  "NULL Object");

    int iRes;
    unsigned char ucMajorVersion = GEM_MAJOR_VERSION;
    unsigned char ucMinorVersion = GEM_MINOR_VERSION;

    CFileUtils::BeginRIFFBlock( GEM_FILE_IDENTIFIER, _oFile);

    _oFile.iWrite(&ucMajorVersion,1);
    _oFile.iWrite(&ucMinorVersion,1);

    iRes = iSave3DObject(_oFile,_pObj);

    CFileUtils::EndRIFFBlock(_oFile);

    return ( iRes );
}

int CSaverGEM::iSave3DObject (CFile & _oFile, CObject3D *_pObj)
{

   int iRes;
   e3DObjectTypeID eObjType = _pObj->eGetTypeID();

   CFileUtils::BeginRIFFBlock(GEMFile_Translate_TypeID2FileID(eObjType),_oFile);

    switch ( eObjType )
    {
        case e3DObj_Gen:            iRes = 1;
            break;
        case e3DObj_Leaf:           iRes = iSave3DObj_Leaf(_oFile,(CObject3D_Leaf *)_pObj);
            break;
        case e3DObj_Node:           iRes = iSave3DObj_Node(_oFile,(CObject3D_Node *)_pObj);
            break;
        case e3DObj_Transf:         iRes = iSave3DObj_Transf(_oFile,(CObject3D_Transf *)_pObj);
            break;
        case e3DObj_AnimGen:        iRes = 0;
            break;
        case e3DObj_AnimNode:       iRes = iSave3DObj_AnimNode(_oFile,(CObject3D_AnimNode *)_pObj);
            break;
        case e3DObj_AnimMesh:       iRes = iSave3DObj_AnimMesh(_oFile,(CObject3D_AnimMesh *)_pObj);
            break;
        case e3DObj_AnimTransf:     iRes = iSave3DObj_AnimTransf(_oFile,(CObject3D_AnimTransf *)_pObj);
            break;
        case e3DObj_AnimCfg:        iRes = iSave3DObj_AnimCfg(_oFile,(CObject3D_AnimCfg *)_pObj);
            break;
        case e3DObj_AnimCfgMgr:     iRes = iSave3DObj_AnimCfgMgr(_oFile,(CObject3D_AnimCfgMgr *)_pObj);
            break;
        case e3DObj_BSPNode:        iRes = iSave3DObj_BSPNode(_oFile,(CObject3D_BSPNode *)_pObj);
            break;
        case e3DObj_Mux:            iRes = iSave3DObj_Mux(_oFile,(CObject3D_Mux *)_pObj);
            break;

        default:                    iRes = 0;
            break;
    }

    CFileUtils::EndRIFFBlock(_oFile);

    return( iRes );
} // iSave3DObject

int CSaverGEM::iSave3DObj_Leaf (CFile & _oFile, CObject3D_Leaf *_pObj)
{
   const char *MatName;
   char MaterialName[MAX_CHARS];

     // Get material name
    MatName = CE3D_ShaderWH::I()->sGetName( _pObj->poGetShader() ).szString();

    memset(MaterialName,0,MAX_CHARS);

    if (MatName) strcpy(MaterialName, MatName);

     // Write material name
    _oFile.iWrite(MaterialName,MAX_CHARS);

     // Write mesh
    iSaveMesh( _oFile,_pObj->poGetMesh() );

    return ( RES_OP_OK );

}

int CSaverGEM::iSave3DObj_Node (CFile & _oFile, CObject3D_Node *_pObj)
{

     // Count number of subobjects
    int iObj;
    int iNumSubObjects = 0;

    for (iObj = 0; iObj < _pObj->uiNumSubObjs(); iObj++)
        if ( _pObj->poGetObject(iObj) ) iNumSubObjects++;

     // Read subobject array props
    _oFile.iWrite(&iNumSubObjects,4);

     // Write subobjects
    for (iObj = 0; iObj < _pObj->uiNumSubObjs(); iObj++)
        if ( _pObj->poGetObject(iObj) )
            iSave3DObject( _oFile,_pObj->poGetObject(iObj) );

     // Save the object bounding	volume
    CGraphBV_FileIO::iSaveGraphBV( _oFile,_pObj->poGetBoundVol() );

    return ( RES_OP_OK );

}

int CSaverGEM::iSave3DObj_Transf (CFile & _oFile, CObject3D_Transf *_pObj)
{

     // Read node transformation parameters
    _oFile.iWrite( &_pObj->oPos(),sizeof( CVect3 ) );
    _oFile.iWrite( &_pObj->oDir(),sizeof( CVect3 ) );
    _oFile.iWrite( &_pObj->oSide(),sizeof( CVect3 ) );
    _oFile.iWrite( &_pObj->oUp(),sizeof( CVect3 ) );

     // Read attached object
    iSave3DObject( _oFile,_pObj->poGetObject() );

    return ( RES_OP_OK );

}

int CSaverGEM::iSaveMesh (CFile & _oFile, CMesh *Mesh)
{
   unsigned int uiMeshMask;

   CFileUtils::BeginRIFFBlock( GEM_MESH_IDENTIFIER, _oFile);

     // Setup Mesh mask
    uiMeshMask = 0;

    if (Mesh->VXs) uiMeshMask |= MESH_FIELD_VERTEXS;

    if (Mesh->UVs) uiMeshMask |= MESH_FIELD_UVCOORDS;

    if (Mesh->VCs) uiMeshMask |= MESH_FIELD_COLORS;

    if (Mesh->VNs) uiMeshMask |= MESH_FIELD_VNORMALS;

    if (Mesh->UVs2) uiMeshMask |= MESH_FIELD_UVCOORD2;

    if (Mesh->TNs) uiMeshMask |= MESH_FIELD_TNORMALS;

    if (Mesh->Idxs) uiMeshMask |= MESH_FIELD_INDEXES;

    _oFile.iWrite( &Mesh->usNumVerts,2);
    _oFile.iWrite( &Mesh->usNumPrims,2);
    _oFile.iWrite( &Mesh->eMeshType,4);

     // mesh mask
    _oFile.iWrite( &uiMeshMask,4);

     // mesh components
    if (Mesh->VXs) _oFile.iWrite( Mesh->VXs,Mesh->usNumVerts * sizeof( CVect3 ) );

    if (Mesh->UVs) _oFile.iWrite( Mesh->UVs,Mesh->usNumVerts * sizeof( CVect2 ) );

    if (Mesh->VCs) _oFile.iWrite( Mesh->VCs,Mesh->usNumVerts * sizeof( CVect4 ) );

    if (Mesh->VNs) _oFile.iWrite( Mesh->VNs,Mesh->usNumVerts * sizeof( CVect3 ) );

    if (Mesh->UVs2) _oFile.iWrite( Mesh->UVs2,Mesh->usNumVerts * sizeof( CVect2 ) );

    if (Mesh->TNs ) _oFile.iWrite( Mesh->TNs,Mesh->usNumPrims * sizeof( CVect3 ) );

    if (Mesh->Idxs) _oFile.iWrite( Mesh->Idxs,Mesh->usNumIdxs * sizeof( unsigned short ) );

     // Save the mesh bounding volume
    CGraphBV_FileIO::iSaveGraphBV( _oFile,Mesh->GetBoundVol() );

    CFileUtils::EndRIFFBlock(_oFile);

    return ( RES_OP_OK );
} // iSaveMesh

int CSaverGEM::iSave3DObj_AnimNode (CFile & _oFile, CObject3D_AnimNode *_pObj)
{
   int iMaxSubObjects;
   int iNumSubObjects;
   int iNumStates;
   int iObj;
   int iState;

    iNumSubObjects = _pObj->iNumObjs;
    iMaxSubObjects = _pObj->iMaxObjs;
    iNumStates     = _pObj->iGetNumStates();

     // Write subobject array props
    _oFile.iWrite(&iNumSubObjects,4);
    _oFile.iWrite(&iMaxSubObjects,4);
    _oFile.iWrite(&iNumStates,4);

     // Save the the bounding volume state array
    for (iState = 0; iState < iNumStates; iState++)
        CGraphBV_FileIO::iSaveGraphBV( _oFile,_pObj->poGetStateBVol(iState) );

     // Write subobjects
    for (iObj = 0; iObj < iMaxSubObjects; iObj++)
        if ( _pObj->poObjs[iObj] ) iSave3DObject(_oFile,_pObj->poObjs[iObj]);

    return ( RES_OP_OK );
}

int CSaverGEM::iSave3DObj_AnimMesh (CFile & _oFile, CObject3D_AnimMesh *_pObj)
{
   int iNumStateVXs;
   int iNumStates;
   int iState;

    iNumStateVXs   = _pObj->iNumStateVXs;
    iNumStates     = _pObj->iGetNumStates();

     // Write object fields
    _oFile.iWrite(&iNumStates,4);
    _oFile.iWrite(&iNumStateVXs,4);

     // Save the the vertexs and normals state array
    _oFile.iWrite( _pObj->pMeshStates,iNumStates * iNumStateVXs * sizeof( CVect3 ) );
    _oFile.iWrite( _pObj->pNMeshStates,iNumStates * iNumStateVXs * sizeof( CVect3 ) );

     // Save the the bounding volume state array
    for (iState = 0; iState < iNumStates; iState++)
        CGraphBV_FileIO::iSaveGraphBV( _oFile,_pObj->poGetStateBVol(iState) );

     // Save leaf node
    iSave3DObject( _oFile,_pObj->GetLeaf() );

    return ( RES_OP_OK );
}

int CSaverGEM::iSave3DObj_AnimTransf (CFile & _oFile, CObject3D_AnimTransf *_pObj)
{
   int iNumStates = _pObj->iGetNumStates();

     // Write object fields
    _oFile.iWrite(&iNumStates,4);
    _oFile.iWrite( _pObj->pTransStates,iNumStates * sizeof( CMatrix4x4 ) );

    return ( RES_OP_OK );
}

int CSaverGEM::iSave3DObj_AnimCfg (CFile & _oFile, CObject3D_AnimCfg *_pObj)
{

     // Write object fields
    _oFile.iWrite(&_pObj->iNumFrameAnims,4);
    _oFile.iWrite( _pObj->GetFrameAnim(),_pObj->iNumFrameAnims * sizeof( TFrameAnimation ) );

     // Save attached object
    iSave3DObject( _oFile, _pObj->GetAnimObj() );

    return ( RES_OP_OK );
}

int CSaverGEM::iSave3DObj_AnimCfgMgr (CFile & _oFile, CObject3D_AnimCfgMgr *_pObj)
{
     // Write object fields
    _oFile.iWrite(&_pObj->iMaxAnimObjs,4);
    _oFile.iWrite(&_pObj->iNumAnimObjs,4);

    for (int iObj = 0; iObj < _pObj->iMaxAnimObjs; iObj++)
        if (_pObj->pAnimObjs[iObj])
             // Save attached objects
            iSave3DObject(_oFile, _pObj->pAnimObjs[iObj] );

    return ( RES_OP_OK );
}

int CSaverGEM::iSave3DObj_BSPNode (CFile & _oFile, CObject3D_BSPNode *_pObj)
{

     // Write node transformation parameters
    _oFile.iWrite( _pObj->poGetPartitionPlane(),sizeof( CPlane ) );

    iSave3DObject( _oFile,_pObj->poGetBackNode() );
    iSave3DObject( _oFile,_pObj->poGetFrontNode() );

     // Save the object bounding	volume
    CGraphBV_FileIO::iSaveGraphBV( _oFile,_pObj->poGetBoundVol() );

    return ( RES_OP_OK );
}

int CSaverGEM::iSave3DObj_Mux (CFile & _oFile, CObject3D_Mux *_pObj)
{
    return( RES_OP_ERROR );
}

int CSaverGEM::iSave (char *_Filename, CObject3D *_pObj)
{
   CFile oFile;
   int iRes;

    if ( !oFile.bOpen(_Filename,"wb") )
    {
         // ERROR_SetError("GEMSAV0002","Unable to open file for saving:",_Filename);
        return( RES_OP_ERROR );
    }

    iRes = iSave(oFile,_pObj);

    oFile.Close();

    return ( iRes );
}

// Additional Declarations
