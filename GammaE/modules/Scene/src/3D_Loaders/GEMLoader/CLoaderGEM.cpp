//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GammaE_FileSys.h"
#include "GammaE_Mem.h"
#include "GEMFile.h"
//-----------------------------------------------------------------------------
// CLoaderGEM
#include "3D_Loaders\GEMLoader\CLoaderGEM.h"
//-----------------------------------------------------------------------------
// Class CLoaderGEM
CLoaderGEM::CLoaderGEM()
{
}
//-----------------------------------------------------------------------------
CLoaderGEM::~CLoaderGEM()
{
}
//-----------------------------------------------------------------------------
CObject3D *CLoaderGEM::pLoad (char *Filename)
{
   CFile oFile;
   CObject3D       *pObj;

   unsigned int uiID;
   unsigned int uiLenght;

    if (!Filename) return( NULL );

    if ( !oFile.bOpen(Filename,"rb") )
        return( NULL );

    oFile.iRead(&uiID,4);

    if (uiID != GEM_FILE_IDENTIFIER )
    {
         // ERROR_SetError("GEMLD0002","Bad Gamma Engine Model file");
        oFile.Close();
        return ( NULL );
    }

    oFile.iRead(&uiLenght,4);

     // Stablish alternate texture path
    CGString sDir = ExtractFileDir( CGString(Filename) );
    CMipMapWH::I()->AlternatePath( sDir );

    pObj = pLoad(oFile);

     // Restore alternate path to default
    CMipMapWH::I()->AlternatePath( "" );

    oFile.Close();
    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D *CLoaderGEM::pLoad (CFile & _oFile)
{
   unsigned char ucMajorVersion;
   unsigned char ucMinorVersion;

    ucMajorVersion = _oFile.cRead();
    ucMinorVersion = _oFile.cRead();

    if (ucMajorVersion > GEM_MAJOR_VERSION) return ( NULL );

    if (ucMinorVersion > GEM_MINOR_VERSION) return ( NULL );

    return ( pLoad3DObject(_oFile) );
}
//-----------------------------------------------------------------------------
CObject3D *CLoaderGEM::pLoad3DObject (CFile & _oFile)
{
   unsigned int uiObjectID;
   unsigned int uiBlockLenght;

   _oFile.iRead(&uiObjectID,4);
   _oFile.iRead(&uiBlockLenght,4);

    switch ( GEMFile_Translate_FileID2TypeID2(uiObjectID) )
    {
        case e3DObj_NULL:       return ( NULL );

            break;
        case e3DObj_Gen:        return ( NULL );

            break;
        case e3DObj_Leaf:       return ( pLoad3DObj_Leaf(_oFile) );

            break;
        case e3DObj_Node:       return ( pLoad3DObj_Node(_oFile) );

            break;
        case e3DObj_Transf:     return ( pLoad3DObj_Transf(_oFile) );

            break;
        case e3DObj_AnimGen:    return ( NULL );

            break;
        case e3DObj_AnimNode:   return ( pLoad3DObj_AnimNode(_oFile) );

            break;
        case e3DObj_AnimMesh:   return ( pLoad3DObj_AnimMesh(_oFile) );

            break;
        case e3DObj_AnimTransf: return ( pLoad3DObj_AnimTransf(_oFile) );

            break;
        case e3DObj_AnimCfg:    return ( pLoad3DObj_AnimCfg(_oFile) );

            break;
        case e3DObj_AnimCfgMgr: return ( pLoad3DObj_AnimCfgMgr(_oFile) );

            break;

        case e3DObj_Camera:
            break;
        case e3DObj_BSPNode:    return ( pLoad3DObj_BSPNode(_oFile) );

            break;
        case e3DObj_Mux:        return ( pLoad3DObj_Mux(_oFile) );

            break;
    }

    return ( NULL );
} // pLoad3DObject
//-----------------------------------------------------------------------------
CMesh *CLoaderGEM::pLoadMesh (CFile & _oFile)
{
   unsigned int uiBlockSize;
   unsigned int uiID;

   _oFile.iRead(&uiID,4);
   _oFile.iRead(&uiBlockSize,4);

    if (uiID != GEM_MESH_IDENTIFIER)
    {
         //ERROR_SetError("GEMLD001","Mesh not found");
        _oFile.uiSeek(-8,eFile_SM_Cur);
        return ( NULL );
    }

    unsigned int uiMeshMask;
    CMesh       *Mesh = mNew CMesh;

    _oFile.iRead(&Mesh->usNumVerts,2);
    _oFile.iRead(&Mesh->usNumPrims,2);
    _oFile.iRead(&Mesh->eMeshType,4);

     // mesh mask
    _oFile.iRead( &uiMeshMask,4);

    Mesh->Init(Mesh->usNumVerts,Mesh->usNumPrims,Mesh->eMeshType,uiMeshMask);

     // mesh components
    if (Mesh->VXs ) _oFile.iRead( Mesh->VXs,Mesh->usNumVerts * sizeof( CVect3 ) );

    if (Mesh->UVs ) _oFile.iRead( Mesh->UVs,Mesh->usNumVerts * sizeof( CVect2 ) );

    if (Mesh->VCs ) _oFile.iRead( Mesh->VCs,Mesh->usNumVerts * sizeof( CVect4 ) );

    if (Mesh->VNs ) _oFile.iRead( Mesh->VNs,Mesh->usNumVerts * sizeof( CVect3 ) );

    if (Mesh->UVs2) _oFile.iRead( Mesh->UVs2,Mesh->usNumVerts * sizeof( CVect2 ) );

    if (Mesh->TNs ) _oFile.iRead( Mesh->TNs,Mesh->usNumPrims * sizeof( CVect3 ) );

    if (Mesh->Idxs) _oFile.iRead( Mesh->Idxs,Mesh->usNumIdxs * sizeof( unsigned short ) );

     // Save the mesh bounding volume
    if (Mesh->BVol) mDel Mesh->BVol;
    Mesh->BVol = CGraphBV_FileIO::pLoadGraphBV(_oFile);

    return ( Mesh );
} // pLoadMesh
//-----------------------------------------------------------------------------
CObject3D_Leaf *CLoaderGEM::pLoad3DObj_Leaf (CFile & _oFile)
{
   char MaterialName[MAX_CHARS];
   CE3D_Shader     *poShader;

   CObject3D_Leaf  *pObj = mNew CObject3D_Leaf();

     // Read material name
    _oFile.iRead(MaterialName,MAX_CHARS);

     // Get material object
    poShader = CE3D_ShaderWH::I()->poCreateShader(MaterialName);

    pObj->SetShader( poShader );

     // Write mesh
    pObj->SetMesh( pLoadMesh(_oFile) );
    pObj->SetBoundVol( pObj->poGetMesh()->GetBoundVol() );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_Node *CLoaderGEM::pLoad3DObj_Node (CFile & _oFile)
{
   CObject3D_Node *pObj = mNew CObject3D_Node();
   CObject3D      *pChild;

   unsigned int uiNumSubObjs;
   unsigned int uiObj;

     // Read subobject array props
    _oFile.iRead(&uiNumSubObjs,4);

    pObj->Init(uiNumSubObjs);

     // read subobjects
    for (uiObj = 0; uiObj < uiNumSubObjs; uiObj++)
    {
        pChild = pLoad3DObject(_oFile);

        if (pChild->eGetTypeID() != e3DObj_NULL)
            pObj->iAddObject(pChild );
    }

     // Load the bounding volume
    if ( pObj->poGetBoundVol() ) mDel pObj->poGetBoundVol();
    pObj->SetBoundVol( CGraphBV_FileIO::pLoadGraphBV(_oFile) );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_Transf *CLoaderGEM::pLoad3DObj_Transf (CFile & _oFile)
{
   CObject3D_Transf *pObj = mNew CObject3D_Transf();

   CVect3 oDir;
   CVect3 oSide;
   CVect3 oUp;
   CVect3 oPos;

     // Read node transformation parameters
    _oFile.iRead( &oPos,sizeof( CVect3 ) );
    _oFile.iRead( &oDir,sizeof( CVect3 ) );
    _oFile.iRead( &oSide,sizeof( CVect3 ) );
    _oFile.iRead( &oUp,sizeof( CVect3 ) );

     // Read attached object
    pObj->SetObject( pLoad3DObject(_oFile) );

     // Set node transformation parameters
    pObj->Setup(oPos,oDir,oSide,oUp);

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_AnimNode *CLoaderGEM::pLoad3DObj_AnimNode (CFile & _oFile)
{
   int iMaxSubObjects;
   int iNumSubObjects;
   int iNumStates;
   int iObj;
   int iState;
   CObject3D_AnimNode  *pObj;

     // Read subobject array props
    _oFile.iRead(&iNumSubObjects,4);
    _oFile.iRead(&iMaxSubObjects,4);
    _oFile.iRead(&iNumStates,4);

     // Initialize object
    pObj = mNew CObject3D_AnimNode;
    pObj->Init(iMaxSubObjects);
    pObj->CreateStates(iNumStates);

     // Load the the bounding volume state array
    for (iState = 0; iState < iNumStates; iState++)
    {
   mDel pObj->poBVolStates[iState];
        pObj->poBVolStates[iState] = CGraphBV_FileIO::pLoadGraphBV(_oFile);
    }
    pObj->SetBoundVol(pObj->poBVolStates[0]);

     // Read subobjects
    for (iObj = 0; iObj < iNumSubObjects; iObj++)
        pObj->AddObject( (CObject3D_AnimGen *)pLoad3DObject( _oFile ) );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_AnimMesh *CLoaderGEM::pLoad3DObj_AnimMesh (CFile & _oFile)
{
   int iNumStateVXs;
   int iNumStates;
   int iState;
   CObject3D_AnimMesh  *pObj;

     // Write object fields
    _oFile.iRead(&iNumStates,4);
    _oFile.iRead(&iNumStateVXs,4);

    pObj = mNew CObject3D_AnimMesh;
    pObj->CreateStates(iNumStates,iNumStateVXs);

     // Load the the vertexs and normals state array
    _oFile.iRead( pObj->pMeshStates,iNumStates * iNumStateVXs * sizeof( CVect3 ) );
    _oFile.iRead( pObj->pNMeshStates,iNumStates * iNumStateVXs * sizeof( CVect3 ) );

     // Load the the bounding volume state array
    for (iState = 0; iState < iNumStates; iState++)
    {
   mDel pObj->pBVolStates[iState];
        pObj->pBVolStates[iState] = CGraphBV_FileIO::pLoadGraphBV(_oFile);
    }
    // pObj->SetBoundVol(pObj->pBVolStates[0]);

     // Load leaf node
    pObj->SetLeaf( (CObject3D_Leaf *) pLoad3DObject( _oFile ) );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_AnimTransf *CLoaderGEM::pLoad3DObj_AnimTransf (CFile & _oFile)
{
   CObject3D_AnimTransf    *pObj;

   int iNumStates;

     // Read object fields
    _oFile.iRead(&iNumStates,4);

     // Create and initialize object
    pObj = mNew CObject3D_AnimTransf;
    pObj->CreateStates(iNumStates);

    _oFile.iRead( pObj->pTransStates,iNumStates * sizeof( CMatrix4x4 ) );
    pObj->ComputeBoundVol();

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_AnimCfg *CLoaderGEM::pLoad3DObj_AnimCfg (CFile & _oFile)
{
   CObject3D_AnimCfg *pObj;
   int iNumFrameAnims;

     // Read object number of object animations
    _oFile.iRead(&iNumFrameAnims,4);

     // Create and initialize object
    pObj = mNew CObject3D_AnimCfg;
    pObj->CreateFrameAnims(iNumFrameAnims);

     // Read frame animations
    _oFile.iRead( pObj->GetFrameAnim(),iNumFrameAnims * sizeof( TFrameAnimation ) );

     // Load attached object
    pObj->SetAnimObj ( (CObject3D_AnimGen *)pLoad3DObject( _oFile ) );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_AnimCfgMgr *CLoaderGEM::pLoad3DObj_AnimCfgMgr (CFile & _oFile)
{
   CObject3D_AnimCfgMgr    *pObj;
   int iMaxAnimObjs;
   int iNumAnimObjs;
   int iObj;

     // Read object fields
    _oFile.iRead(&iMaxAnimObjs,4);
    _oFile.iRead(&iNumAnimObjs,4);

     // Create and initialize object
    pObj = mNew CObject3D_AnimCfgMgr;
    pObj->Init(iMaxAnimObjs);

     // Load attached objects
    for (iObj = 0; iObj < iNumAnimObjs; iObj++)
        pObj->AddAnimObj( (CObject3D_AnimCfg *)pLoad3DObject( _oFile ) );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_BSPNode *CLoaderGEM::pLoad3DObj_BSPNode (CFile & _oFile)
{
   CObject3D_BSPNode *pObj = mNew CObject3D_BSPNode();

     // Write node transformation parameters
    _oFile.iRead( pObj->poGetPartitionPlane(),sizeof( CPlane ) );

    pObj->SetBackNode ( pLoad3DObject(_oFile) );
    pObj->SetFrontNode( pLoad3DObject(_oFile) );

     // Load the bounding volume
    if ( pObj->poGetBoundVol() ) mDel pObj->poGetBoundVol();
    pObj->SetBoundVol( CGraphBV_FileIO::pLoadGraphBV(_oFile) );

    return ( pObj );
}
//-----------------------------------------------------------------------------
CObject3D_Mux *CLoaderGEM::pLoad3DObj_Mux (CFile & _oFile)
{
    return ( NULL );
}
//-----------------------------------------------------------------------------
