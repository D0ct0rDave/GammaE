// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GammaE_FileSys.h"
#include "GammaE_Mem.h"
#include "GammaE_Misc.h"
#include "GEMFile.h"
#include "GraphBVUtils/CGGraphBVFileIO.h"
#include "Animation/CGSceneAnimActionSet.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimTransf.h"
#include "Animation/CGSceneAnimGroup.h"

// ----------------------------------------------------------------------------
#include "3D_Loaders\GEMLoader\CLoaderGEM.h"
// ----------------------------------------------------------------------------
CGGraphBV* poLoadBoundingVolume(CGFile* _poFile)
{
    return CGGraphBVFileIO::pLoadGraphBV(*_poFile);
}
// ----------------------------------------------------------------------------
CLoaderGEM::CLoaderGEM() :
    m_poFile(NULL)
{
}
// ----------------------------------------------------------------------------
CLoaderGEM::~CLoaderGEM()
{
}
// ----------------------------------------------------------------------------
CGSceneNode* CLoaderGEM::poLoad(const CGString& _sFilename)
{
    CGFile oFile;
    if ( !oFile.bOpen(_sFilename,FOM_READ) )
        return(NULL);

    uint uiID = oFile.iRead();
    if ( uiID != GEM_FILE_IDENTIFIER )
    {
        oFile.Close();
        return (NULL);
    }

    uint uiLenght = oFile.iRead();

    // Stablish alternate texture path
    CGString sDir = Utils::ExtractFileDir( _sFilename );
    CGMipMapWH::I()->AlternatePath( sDir );

    CGSceneNode* poObj = poLoad(oFile);

    // Restore alternate path to default
    CGMipMapWH::I()->AlternatePath( "" );

    oFile.Close();
    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneNode* CLoaderGEM::poLoad (const CGFile& _oFile)
{
    unsigned char ucMajorVersion;
    unsigned char ucMinorVersion;

    m_poFile = (CGFile*)&_oFile;
    
    ucMajorVersion = m_poFile->cRead();
    ucMinorVersion = m_poFile->cRead();

    if ( ucMajorVersion > GEM_MAJOR_VERSION ) return (NULL);
    if ( ucMinorVersion > GEM_MINOR_VERSION ) return (NULL);

    return ( poLoad3DObject() );
}
// ----------------------------------------------------------------------------
CGSceneNode* CLoaderGEM::poLoad3DObject ()
{
    uint uiObjectID = m_poFile->iRead();
    uint uiBlockLengh = m_poFile->iRead();

    switch ( uiObjectID )
    {
        case GEM_NULL_IDENTIFIER:   
        return (NULL);
        break;

        case GEM_LEAF_IDENTIFIER:   
        return ( poLoad3DObj_Leaf() );
        break;

        case GEM_NODE_IDENTIFIER:   
        return ( poLoad3DObj_Node() );
        break;

        case GEM_TRANSF_IDENTIFIER:  
        return ( poLoad3DObj_Transf() );
        break;

        case GEM_CAMERA_IDENTIFIER:
        break;

        case GEM_BSPNODE_IDENTIFIER: 
        return ( poLoad3DObj_BSPNode() );
        break;

        case GEM_MUX_IDENTIFIER:    
        return ( poLoad3DObj_Mux() );
        break;
        case GEM_ANIMACTIONSET_IDENTIFIER:
        return ( poLoad3DObj_AnimActionSet() );
        break;
    }

    return (NULL);
}
// ----------------------------------------------------------------------------
CGMesh* CLoaderGEM::poLoadMesh ()
{
    uint uiID = m_poFile->iRead();
    uint uiBlockSize = m_poFile->iRead();

    if ( uiID != GEM_MESH_IDENTIFIER )
    {
        m_poFile->iSeek(-8,FSM_CUR);
        return (NULL);
    }

    uint uiNumVXs = (uint)m_poFile->usRead();
    uint uiNumPrims = (uint)m_poFile->usRead();
    E3D_PrimitiveType ePrimType = (E3D_PrimitiveType)m_poFile->uiReadData();

    // mesh mask
    uint uiMeshMask = m_poFile->uiReadData();

    CGMesh* poMesh = mNew CGMesh;
    poMesh->Init(uiNumVXs,uiNumPrims,ePrimType,uiMeshMask);

    // mesh components
    if ( poMesh->m_poVX ) m_poFile->ReadArray( (float*)poMesh->m_poVX,uiNumVXs * 3 );
    if ( poMesh->m_poUV ) m_poFile->ReadArray( (float*)poMesh->m_poUV,uiNumVXs * 2 );
    if ( poMesh->m_poVC ) m_poFile->ReadArray( (float*)poMesh->m_poVC,uiNumVXs * 4 );
    if ( poMesh->m_poVN ) m_poFile->ReadArray( (float*)poMesh->m_poVN,uiNumVXs * 3 );
    if ( poMesh->m_poUV2 ) m_poFile->ReadArray( (float*)poMesh->m_poUV2,uiNumVXs * 2 );
    if ( poMesh->m_poTN ) m_poFile->ReadArray( (float*)poMesh->m_poTN,uiNumVXs * 3 );
    if ( poMesh->m_pusIdx ) m_poFile->ReadArray( (short*)poMesh->m_pusIdx,poMesh->uiGetNumIndices());

    // Save the mesh bounding volume
    poMesh->SetBV( poLoadBoundingVolume(m_poFile) );

    return (poMesh);
}
// ----------------------------------------------------------------------------
CGSceneLeaf* CLoaderGEM::poLoad3DObj_Leaf ()
{
    // Read material name
    char szMaterialName[MAX_CHARS];
    m_poFile->uiReadData( (pointer)szMaterialName,MAX_CHARS );

    // Get material object
    CGShader* poShader = CGShaderWH::I()->poCreateShader(szMaterialName);

    // Create the leaf object
    CGSceneLeaf* poObj = mNew CGSceneLeaf();
    poObj->SetShader( poShader );

    // Write mesh
    poObj->SetMesh( poLoadMesh() );

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneGroup* CLoaderGEM::poLoad3DObj_Node ()
{
    // Read subobject array props
    uint uiNumSubObjs = m_poFile->uiReadData();
    CGSceneGroup* poObj = mNew CGSceneGroup();

    poObj->Init(uiNumSubObjs);

    // read subobjects
    for ( uint uiObj = 0; uiObj < uiNumSubObjs; uiObj++ )
    {
        CGSceneNode* poChild = poLoad3DObject();

        if ( poChild->eGetNodeType() != SNT_NULL )
            poObj->iAddObject(poChild);
    }

    // Load the bounding volume
    poObj->SetBV( poLoadBoundingVolume(m_poFile) );

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneTransf* CLoaderGEM::poLoad3DObj_Transf ()
{
    CGSceneTransf* poObj = mNew CGSceneTransf();

    CGVect3 oDir;
    CGVect3 oSide;
    CGVect3 oUp;
    CGVect3 oPos;

    // Read node transformation parameters
    m_poFile->ReadArray( (float*)&oPos,3 );
    m_poFile->ReadArray( (float*)&oDir,3 );
    m_poFile->ReadArray( (float*)&oSide,3 );
    m_poFile->ReadArray( (float*)&oUp,3 );

    // Read attached object
    poObj->SetObject( poLoad3DObject() );

    // Set node transformation parameters
    poObj->Setup(oPos,oDir,oSide,oUp);

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneAnimGroup* CLoaderGEM::poLoad3DObj_AnimGroup()
{
    // Read subobject array props
    uint uiNumSubObjects = m_poFile->uiReadData();
    uint uiNumKeyFrames = m_poFile->uiReadData();

    // Initialize object
    CGSceneAnimGroup* poObj = mNew CGSceneAnimGroup;
    poObj->Setup(uiNumKeyFrames);

    // Load the the bounding volume state array
    for ( uint uiFrame = 0; uiFrame < uiNumKeyFrames; uiFrame++ )
    {
        poObj->SetStateBVol(uiFrame, poLoadBoundingVolume(m_poFile) );
    }

    // Read subobjects
    for (uint uiObj = 0; uiObj < uiNumSubObjects; uiObj++)
    {
        poObj->uiAddAnimObject(poLoad3DObj_AnimObject());
    }

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneAnimMesh* CLoaderGEM::poLoad3DObj_AnimMesh ()
{
    // Write object fields
    uint uiNumStates = m_poFile->uiReadData();

    // Load the startup mesh
    CGMesh* poMesh = poLoadMesh();
       
    CGSceneAnimMesh* poObj = mNew CGSceneAnimMesh;
    poObj->Setup(poMesh, uiNumStates, poMesh->uiGetNumVXs());

    // Load the the vertexs and normals state array
    uint uiNumVXs = poMesh->uiGetNumVXs();
    CGVect3* poVXs = mNew CGVect3[uiNumVXs];
    CGVect3* poVNs = mNew CGVect3[uiNumVXs];

    m_poFile->uiReadData((pointer)poObj->poGetVertices(), uiNumStates * poMesh->uiGetNumVXs() * sizeof(CGVect3));
    m_poFile->uiReadData((pointer)poObj->poGetNormals(), uiNumStates * poMesh->uiGetNumVXs() * sizeof(CGVect3));

    // Load the the bounding volume state array
    for (uint uiFrame = 0; uiFrame < uiNumStates; uiFrame++ )
    {
        poObj->SetStateBVol(uiFrame, poLoadBoundingVolume(m_poFile));
    }

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneAnimTransf* CLoaderGEM::poLoad3DObj_AnimTransf ()
{
    uint uiNumKeyFrames = m_poFile->uiReadData();

    // Create and initialize object
    CGSceneAnimTransf* poObj = mNew CGSceneAnimTransf;
    poObj->Setup(uiNumKeyFrames);

    m_poFile->uiReadData((pointer)poObj->poGetStateTransforms(), uiNumKeyFrames * sizeof(CGMatrix4x4));

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneAnimActionSet* CLoaderGEM::poLoad3DObj_AnimActionSet()
{
    CGSceneAnimActionSet* poObj;

       // Read object number of object actions
       uint uiNumActions = m_poFile->uiReadData();

       // Create and initialize object
       poObj = mNew CGSceneAnimActionSet();

       // Read frame animations
       for ( uint i = 0; i < uiNumActions; i++ )
       {
            // read action name
            char szActionName[32];
            m_poFile->ReadArray(szActionName, 32);

            // read action data
            CAnimAction oAction;
            m_poFile->uiReadData((pointer)&oAction, sizeof(CAnimAction));

            poObj->uiAddAction(CGString(szActionName), oAction.m_uiIniFrame, oAction.m_uiEndFrame, (oAction.m_uiEndFrame - oAction.m_uiIniFrame + 1 ) * oAction.m_fFrameTime, oAction.m_bLoop);
       }

       // Load attached object
       poObj->SetAnimObject(poLoad3DObj_AnimObject());

       return (poObj);

    return(NULL);
}
// ----------------------------------------------------------------------------
CGSceneAnimNode* CLoaderGEM::poLoad3DObj_AnimObject()
{
    uint uiObjectID = m_poFile->uiReadData();
    uint uiBlockLenght = m_poFile->uiReadData();

    switch (uiObjectID)
    {
        case GEM_ANIMMESH_IDENTIFIER:
        return (poLoad3DObj_AnimMesh());
        break;

        case GEM_ANIMGROUP_IDENTIFIER:
        return (poLoad3DObj_AnimGroup() );
        break;

        case GEM_ANIMTRANSF_IDENTIFIER: 
        return ( poLoad3DObj_AnimTransf() );
        break;

        default:
        m_poFile->Skip(uiBlockLenght);
        return(NULL);
        break;
    }

    return(NULL);
}
// ----------------------------------------------------------------------------
CGSceneBSPNode* CLoaderGEM::poLoad3DObj_BSPNode ()
{
    CGSceneBSPNode* poObj = mNew CGSceneBSPNode();

    // Write node transformation parameters
    CGPlane oPlane;
    m_poFile->ReadArray( (float*)&oPlane,sizeof(CGPlane) / sizeof(float) );

    poObj->SetPartitionPlane(oPlane);
    poObj->SetBackNode ( poLoad3DObject() );
    poObj->SetFrontNode( poLoad3DObject() );

    // Load the bounding volume
    poObj->SetBV( poLoadBoundingVolume(m_poFile) );

    return (poObj);
}
// ----------------------------------------------------------------------------
CGSceneMux* CLoaderGEM::poLoad3DObj_Mux ()
{
    return (NULL);
}
// ----------------------------------------------------------------------------
