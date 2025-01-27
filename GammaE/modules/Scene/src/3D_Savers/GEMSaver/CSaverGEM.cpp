// ----------------------------------------------------------------------------
/*! \class CSaverGEM
 *  \brief Class to save a scene graph in GEM format.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------

#include <stdio.h>

// CSaverGEM
#include "3D_Savers\GEMSaver\CSaverGEM.h"
#include <stdio.h>
#include <string.h>
#include "GammaE_FileSys.h"

#include "../../3D_Loaders/GEMLoader/GEMFile.h"

#include "CGSceneNode.h"
#include "CGSceneLeaf.h"
#include "CGSceneNode.h"
#include "CGSceneTransf.h"
#include "CGSceneBSPNode.h"
#include "CGSceneMux.h"

/*
 #include "Animation\CGSceneAnimGroup.h"
 #include "Animation\CGSceneAnimMesh.h"
 #include "Animation\CGSceneAnimTransf.h"
 #include "Animation\CGSceneAnimCfg.h"
 */
// ----------------------------------------------------------------------------
CSaverGEM::CSaverGEM() :
    m_poFile(NULL),
    m_bResult(false)
{
}
// ----------------------------------------------------------------------------
CSaverGEM::~CSaverGEM()
{
}
// ----------------------------------------------------------------------------
void SaveBoundingVolume(CGGraphBV* _poBV)
{
}
// ----------------------------------------------------------------------------
/*
   void CSaverGEM::Visit( CGSceneNode* _poObj)
   {
    int iRes;
    ESceneNodeType eObjType = _poObj->eGetNodeType();

    CGFileUtils::BeginRIFFBlock(GEMFile_Translate_TypeID2FileID(eObjType),m_oFile);

    switch ( eObjType )
    {
        case SNT_Gen:             iRes = 1;
        break;

        case SNT_Leaf:            iRes = bVisit(CGSceneLeaf*)_poObj);
        break;

        case SNT_Node:            iRes = bVisit(CGSceneGroup*)_poObj);
        break;

        case SNT_Transf:          iRes = bVisit(CGSceneTransf*)_poObj);
        break;

        case SNT_AnimObject:      iRes = 0;
        break;

        case SNT_AnimNode:        iRes = bVisit(CGSceneAnimGroup*)_poObj);
        break;

        case SNT_AnimMesh:        iRes = bVisit(CGSceneAnimMesh*)_poObj);
        break;

        case SNT_AnimTransf:      iRes = bVisit(CGSceneAnimTransf*)_poObj);
        break;

        case SNT_AnimCfg:         iRes = bVisit(CGSceneAnimCfg*)_poObj);
        break;

        // case SNT_AnimInstance: iRes = bVisit(CGSceneAnimCfgMgr*)_poObj);
        // break;
        case SNT_BSPNode:         iRes = bVisit(CGSceneBSPNode*)_poObj);
        break;

        case SNT_Mux:             iRes = bVisit(CGSceneMux*)_poObj);
        break;

        default:                  iRes = 0;
        break;
    }

    CGFileUtils::EndRIFFBlock(m_oFile);

    return(iRes);
   }
 */
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneLeaf* _poObj)
{
    CGFileUtils::BeginRIFFBlock( GEM_LEAF_IDENTIFIER, *m_poFile);

    const char* MatName;

    // Get material name
    CGString sMaterialName = CGShaderWH::I()->sGetName( _poObj->poGetShader() );

    char szStr[MAX_CHARS];
    memset(szStr,0,MAX_CHARS);
    strcpy( szStr,sMaterialName.szString() );

    // Write material name
    m_poFile->uiWrite( (pointer)szStr,MAX_CHARS );

    // Write mesh
    SaveMesh( _poObj->poGetMesh() );

    // Bounding Volume was saved on the mesh

    //
    CGFileUtils::EndRIFFBlock( *m_poFile);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneGroup* _poObj)
{
    CGFileUtils::BeginRIFFBlock( GEM_GROUP_IDENTIFIER, *m_poFile);

    // Count number of subobjects
    uint uiObj;
    uint uiNumSubObjects = 0;
    for ( uint uiObj = 0; uiObj < _poObj->uiNumSubObjs(); uiObj++ )
        if ( _poObj->poGetObject(uiObj) )
            uiNumSubObjects++;

    // Write number of subobjects
    m_poFile->Write( (int)uiNumSubObjects );

    // Write subobjects
    for ( uiObj = 0; uiObj < _poObj->uiNumSubObjs(); uiObj++ )
        if ( _poObj->poGetObject(uiObj) )
            _poObj->poGetObject(uiObj)->Accept(this);

    // Save the object bounding	volume
    SaveBoundingVolume( _poObj->poGetBV() );

    //
    CGFileUtils::EndRIFFBlock( *m_poFile);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneTransf* _poObj)
{
    CGFileUtils::BeginRIFFBlock( GEM_TRANSF_IDENTIFIER, *m_poFile);

    // Save node transformation parameters
    m_poFile->WriteArray(_poObj->oTransf().pfGetData(),16);

    // Save attached object
    _poObj->poGetObject()->Accept( this );

    // Save the object bounding	volume
    SaveBoundingVolume( _poObj->poGetBV() );

    //
    CGFileUtils::EndRIFFBlock( *m_poFile);
}
// ----------------------------------------------------------------------------
bool CSaverGEM::bSaveMesh(CGMesh* poMesh)
{
    CGFileUtils::BeginRIFFBlock( GEM_MESH_IDENTIFIER, *m_poFile);

    // Setup Mesh mask
    uint uiMeshMask = 0;

    if ( poMesh->m_poVX ) uiMeshMask |= MESH_FIELD_VERTEXS;
    if ( poMesh->m_poUV ) uiMeshMask |= MESH_FIELD_UVCOORDS;
    if ( poMesh->m_poVC ) uiMeshMask |= MESH_FIELD_COLORS;
    if ( poMesh->m_poVN ) uiMeshMask |= MESH_FIELD_VNORMALS;
    if ( poMesh->m_poUV2 ) uiMeshMask |= MESH_FIELD_UVCOORD2;
    if ( poMesh->m_poTN ) uiMeshMask |= MESH_FIELD_TNORMALS;
    if ( poMesh->m_pusIdx ) uiMeshMask |= MESH_FIELD_INDEXES;

    m_poFile->Write( poMesh->uiGetNumVXs() );
    m_poFile->Write( poMesh->uiGetNumPrims() );
    m_poFile->Write( (uint)poMesh->eGetType() );

    // mesh mask
    m_poFile->Write(uiMeshMask);

    // mesh components
    if ( poMesh->m_poVX ) m_poFile->WriteArray( (float*)poMesh->m_poVX,poMesh->uiGetNumVXs() * 3 );
    if ( poMesh->m_poUV ) m_poFile->WriteArray( (float*)poMesh->m_poUV,poMesh->uiGetNumVXs() * 2 );
    if ( poMesh->m_poVC ) m_poFile->WriteArray( (float*)poMesh->m_poVC,poMesh->uiGetNumVXs() * 4 );
    if ( poMesh->m_poVN ) m_poFile->WriteArray( (float*)poMesh->m_poVN,poMesh->uiGetNumVXs() * 3 );
    if ( poMesh->m_poUV ) m_poFile->WriteArray( (float*)poMesh->m_poUV,poMesh->uiGetNumVXs() * 2 );

    if ( poMesh->m_poTN ) m_poFile->WriteArray( (float*)poMesh->m_poTN,poMesh->uiGetNumPrims() * 3 );
    if ( poMesh->m_pusIdx ) m_poFile->WriteArray( (short*)poMesh->m_pusIdx,poMesh->uiGetNumIndices());

    // Save the mesh bounding volume
    SaveBoundingVolume( poMesh->poGetBV() );

    CGFileUtils::EndRIFFBlock(*m_poFile);

    return (true);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneAnimGroup* _poObj)
{
/*
   uint uiNumSubObjects = _poObj->uiNumAnimObjects();
    uint uiNumKeyFrames = _poObj->uiGetNumKeyFrames();

    // Write subobject array props
    m_poFile->iWrite(&uiNumSubObjects,4);
    m_poFile->iWrite(&uiNumKeyFrames,4);

    // Save the the bounding volume state array
    for ( uint uiFrame = 0; uiFrame < uiNumKeyFrames; uiFrame++ )
        CGraphBV_FileIO::bVisit(uiFrame) );

    // Write subobjects
    for ( uint uiObj = 0; uiObj < uiNumSubObjects; uiObj++ )
    {
        if ( _poObj->poGetAnimObject(uiObj) )
            bVisit(uiObj) );
    }

    return (RES_OP_OK);
 */
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneAnimNode* _poObj)
{
    /*
       int iRes;
       ESceneNodeType eObjType = _poObj->eGetTypeID();

       CGFileUtils::BeginRIFFBlock(GEMFile_Translate_TypeID2FileID(eObjType),m_oFile);

       switch ( eObjType )
       {
        case SNT_AnimNode:        iRes = bVisit(CGSceneAnimGroup*)_poObj);
        break;

        case SNT_AnimMesh:        iRes = bVisit(CGSceneAnimMesh*)_poObj);
        break;

        case SNT_AnimTransf:      iRes = bVisit(CGSceneAnimTransf*)_poObj);
        break;

        case SNT_AnimCfg:         iRes = bVisit(CGSceneAnimCfg*)_poObj);
        break;

        // case SNT_AnimInstance:    iRes = bVisit(CGSceneAnimCfgMgr*)_poObj);
        // break;
        default:                    iRes = 0;
        break;
       }

       CGFileUtils::EndRIFFBlock(m_oFile);
       return(iRes);
     */
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneAnimMesh* _poObj)
{
    /*
       uint uiNumStateVXs;
       uint uiNumKeyFrames;

       uiNumStateVXs = _poObj->uiGetNumFrameVXs();
       uiNumKeyFrames = _poObj->uiGetNumKeyFrames();

       // Write object fields
       m_poFile->iWrite(&uiNumKeyFrames,4);
       m_poFile->iWrite(&uiNumStateVXs,4);

       // Save the the vertexs and normals state array
       m_poFile->iWrite( _poObj->poGetVertices(),uiNumKeyFrames * uiNumStateVXs * sizeof(CGVect3) );
       m_poFile->iWrite( _poObj->poGetNormals(),uiNumKeyFrames * uiNumStateVXs * sizeof(CGVect3) );

       // Save the the bounding volume state array
       for ( uint uiFrame = 0; uiFrame < uiNumKeyFrames; uiFrame++ )
        CGraphBV_FileIO::bVisit(uiFrame) );

       return (RES_OP_OK);
     */
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneAnimTransf* _poObj)
{
    /*
       uint uiNumKeyFrames = _poObj->uiGetNumKeyFrames();

       // Write object fields
       m_poFile->iWrite(&uiNumKeyFrames,4);
       m_poFile->iWrite( _poObj->poGetTransforms(),uiNumKeyFrames * sizeof(CGMatrix4x4) );

       return (RES_OP_OK);
     */
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneAnimCfg* _poObj)
{
    /*
       uint uiNumActions = _poObj->uiNumActions();

       // Write the number of object actions
       m_poFile->iWrite(&uiNumActions,4);

       // Write frame animations
       for ( uint i = 0; i < uiNumActions; i++ )
       {
        // write action name
        CGString sName = _poObj->sGetActionName(i);
        m_poFile->iWrite( (void*)sName.szString(),32 );

        // read action data
        CAnimAction oAction = _poObj->oGetFrameAnim(i);
        m_poFile->iWrite( &oAction,sizeof(CAnimAction) );
       }

       // Write attached object
       bVisit();

       return (RES_OP_OK);
     */
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneBSPNode* _poObj)
{
    CGFileUtils::BeginRIFFBlock( GEM_BSPNODE_IDENTIFIER, *m_poFile);

    // Write node transformation parameters
    m_poFile->uiWrite( (pointer) & _poObj->oGetPartitionPlane(),sizeof(CGPlane) );

    // Save children
    _poObj->poGetBackNode()->Accept(this);
    _poObj->poGetFrontNode()->Accept(this);

    // Save the object bounding	volume
    SaveBoundingVolume( _poObj->poGetBV() );

    CGFileUtils::EndRIFFBlock(*m_poFile);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneMux* _poObj)
{
    CGFileUtils::BeginRIFFBlock( GEM_MUX_IDENTIFIER, *m_poFile);
    // return(RES_OP_ERROR);
    CGFileUtils::EndRIFFBlock(*m_poFile);
}
// ----------------------------------------------------------------------------
bool CSaverGEM::bSave(const CGFile& _oFile, CGSceneNode* _poObj)
{
    // Set file object
    m_poFile = (CGFile*)&_oFile;

    int iRes;
    unsigned char ucMajorVersion = GEM_MAJOR_VERSION;
    unsigned char ucMinorVersion = GEM_MINOR_VERSION;

    CGFileUtils::BeginRIFFBlock( GEM_FILE_IDENTIFIER, _oFile);

    m_poFile->uiWrite(&ucMajorVersion,1);
    m_poFile->uiWrite(&ucMinorVersion,1);

    // Start serialization
    _poObj->Accept(this);

    CGFileUtils::EndRIFFBlock(_oFile);

    //
    return(m_bResult);
}
// ----------------------------------------------------------------------------
bool CSaverGEM::bSave(const CGString& _sFilename, CGSceneNode* _poObj)
{
    CGFile oFile;
    if ( !oFile.bOpen(_sFilename, FOM_WRITE) )
    {
        CGErrorLC::I()->Write( "Unable to open file for saving: %s",_sFilename.szString() );
        return(false);
    }

    // Save the scene
    m_bResult = bSave(oFile,_poObj);

    // Close the file
    oFile.Close();

    //
    return(m_bResult);
}
// ----------------------------------------------------------------------------
