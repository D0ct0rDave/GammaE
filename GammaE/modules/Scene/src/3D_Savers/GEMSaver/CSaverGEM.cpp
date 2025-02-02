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
#include "GraphBVUtils/CGGraphBVFileIO.h"
#include "3D_Loaders/GEMLoader/GEMFile.h"

#include "CGSceneNode.h"
#include "CGSceneLeaf.h"
#include "CGSceneNode.h"
#include "CGSceneTransf.h"
#include "CGSceneBSPNode.h"
#include "CGSceneMux.h"
 
#include "Animation\CGSceneAnimGroup.h"
#include "Animation\CGSceneAnimMesh.h"
#include "Animation\CGSceneAnimTransf.h"
#include "Animation\CGSceneAnimActionSet.h"

#include <assert.h>
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
void CSaverGEM::Visit(CGSceneNode* _poObj)
{
    // fallback to any unknown node
    assert(false && "Warning Not Implemented");
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneLeaf* _poObj)
{
    CGFileUtils::BeginRIFFBlock( GEM_LEAF_IDENTIFIER, *m_poFile);

    const char* MatName;

    // Get material name
    CGString sMaterialName = CGShaderWH::I()->sGetName( _poObj->poGetShader() );

    char szStr[MAX_CHARS];
    memset(szStr,0,MAX_CHARS);
    strcpy_s(szStr, MAX_CHARS, sMaterialName.szString() );

    // Write material name
    m_poFile->uiWriteData((pointer)szStr, MAX_CHARS);

    // Write mesh
    bSaveMesh( _poObj->poGetMesh() );

    // Bounding Volume was saved on the mesh

    //
    CGFileUtils::EndRIFFBlock( *m_poFile);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneGroup* _poObj)
{
    SaveGroup(_poObj, GEM_GROUP_IDENTIFIER);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneMux* _poObj)
{
    SaveGroup(_poObj, GEM_MUX_IDENTIFIER);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneTransf* _poObj)
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
void CSaverGEM::Visit(CGSceneBSPNode* _poObj)
{
    CGFileUtils::BeginRIFFBlock(GEM_BSPNODE_IDENTIFIER, *m_poFile);

    // Write node transformation parameters
    m_poFile->uiWriteData((pointer)&_poObj->oGetPartitionPlane(), sizeof(CGPlane));

    // Save children
    _poObj->poGetBackNode()->Accept(this);
    _poObj->poGetFrontNode()->Accept(this);

    // Save the object bounding	volume
    SaveBoundingVolume(_poObj->poGetBV());

    CGFileUtils::EndRIFFBlock(*m_poFile);
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneAnimGroup* _poObj)
{
    CGFileUtils::BeginRIFFBlock(GEM_MESH_IDENTIFIER, *m_poFile); 
    
    uint uiNumSubObjects = _poObj->uiNumAnimObjects();
    uint uiNumStates = _poObj->uiGetNumStates();

    // Write subobject array props
    m_poFile->Write(uiNumSubObjects);
    m_poFile->Write(uiNumStates);

    // Save the the bounding volume state array
    for (uint uiState = 0; uiState < uiNumStates; uiState++ )
    {
        SaveBoundingVolume(_poObj->poGetStateBVol(uiState));
    }

    // Write subobjects
    for (uint uiObj = 0; uiObj < uiNumSubObjects; uiObj++ )
    {
        if ( _poObj->poGetAnimObject(uiObj) )
            _poObj->poGetAnimObject(uiObj)->Accept(this);
    }

    CGFileUtils::EndRIFFBlock(*m_poFile); 
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit( CGSceneAnimMesh* _poObj)
{
    uint uiNumStateVXs = _poObj->uiGetNumFrameVXs();
    uint uiNumStates = _poObj->uiGetNumStates();

    // Write object fields
    m_poFile->Write(uiNumStates);
    m_poFile->Write(uiNumStateVXs);

    // Save the the vertices and normals state array
    m_poFile->WriteArray((float*)_poObj->poGetVertices(), uiNumStates * uiNumStateVXs * sizeof(CGVect3));
    m_poFile->WriteArray((float*)_poObj->poGetNormals(), uiNumStates * uiNumStateVXs * sizeof(CGVect3));

    // Save the the bounding volume state array
    for (uint uiState = 0; uiState < uiNumStates; uiState++)
    {
        SaveBoundingVolume(_poObj->poGetStateBVol(uiState));
    }
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneAnimTransf* _poObj)
{
    uint uiNumStates = _poObj->uiGetNumStates();

    // Write object fields
    m_poFile->Write(uiNumStates);

    // Save the the vertices and normals state array
    m_poFile->WriteArray((float*)_poObj->poGetStateTransforms(), uiNumStates * sizeof(CGMatrix4x4));

    // Save the the bounding volume state array
    for (uint uiState = 0; uiState < uiNumStates; uiState++)
    {
        SaveBoundingVolume(_poObj->poGetStateBVol(uiState));
    }

    if (_poObj->poGetObject())
    {
        _poObj->poGetObject()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneAnimActionSet* _poObj)
{    
    uint uiNumActions = _poObj->uiNumActions();

    // Write the number of object actions
    m_poFile->Write(uiNumActions);

    // Write frame animations
    for ( uint i = 0; i < uiNumActions; i++ )
    {
        // write action name
        CGString sName = _poObj->sGetActionName(i);
        m_poFile->WriteArray(sName.szString(), 32);

        // read action data
        CAnimAction oAction = _poObj->oGetAnimAction(i);
        m_poFile->uiWriteData((pointer)&oAction, sizeof(CAnimAction));
    }

    // Write attached object
    if (_poObj->poGetAnimObject())
    {
        _poObj->poGetAnimObject()->Accept(this);
    }
}
// ----------------------------------------------------------------------------
void CSaverGEM::SaveGroup(CGSceneGroup* _poObj, uint _uiID)
{
    CGFileUtils::BeginRIFFBlock(_uiID, *m_poFile);

    // Count number of subobjects
    uint uiObj;
    uint uiNumSubObjects = 0;
    for (uint uiObj = 0; uiObj < _poObj->uiNumSubObjs(); uiObj++)
        if (_poObj->poGetObject(uiObj))
            uiNumSubObjects++;

    // Write number of subobjects
    m_poFile->Write((int)uiNumSubObjects);

    // Write subobjects
    for (uiObj = 0; uiObj < _poObj->uiNumSubObjs(); uiObj++)
        if (_poObj->poGetObject(uiObj))
            _poObj->poGetObject(uiObj)->Accept(this);

    // Save the object bounding	volume
    SaveBoundingVolume(_poObj->poGetBV());

    //
    CGFileUtils::EndRIFFBlock(*m_poFile);
}
// ----------------------------------------------------------------------------
bool CSaverGEM::bSaveMesh(CGBaseMesh* _poMesh)
{
    if (_poMesh->eGetType() != E3D_MeshType::E3D_MT_Mesh)
    {
        assert(false && "Warning Not Implemented");
        return false;
    }

    CGMesh* poMesh = (CGMesh*)_poMesh;
    CGFileUtils::BeginRIFFBlock(GEM_MESH_IDENTIFIER, *m_poFile);

    // Setup Mesh mask
    uint uiMeshMask = 0;

    if (poMesh->m_poVX) uiMeshMask |= MESH_FIELD_VERTEXS;
    if (poMesh->m_poUV) uiMeshMask |= MESH_FIELD_UVCOORDS;
    if (poMesh->m_poVC) uiMeshMask |= MESH_FIELD_COLORS;
    if (poMesh->m_poVN) uiMeshMask |= MESH_FIELD_VNORMALS;
    if (poMesh->m_poUV2) uiMeshMask |= MESH_FIELD_UVCOORD2;
    if (poMesh->m_poTN) uiMeshMask |= MESH_FIELD_TNORMALS;
    if (poMesh->m_pusIdx) uiMeshMask |= MESH_FIELD_INDEXES;

    m_poFile->Write(poMesh->uiGetNumVXs());
    m_poFile->Write(poMesh->uiGetNumPrims());
    m_poFile->Write((uint)poMesh->eGetType());

    // mesh mask
    m_poFile->Write(uiMeshMask);

    // mesh components
    if (poMesh->m_poVX) m_poFile->WriteArray((float*)poMesh->m_poVX, poMesh->uiGetNumVXs() * 3);
    if (poMesh->m_poUV) m_poFile->WriteArray((float*)poMesh->m_poUV, poMesh->uiGetNumVXs() * 2);
    if (poMesh->m_poVC) m_poFile->WriteArray((float*)poMesh->m_poVC, poMesh->uiGetNumVXs() * 4);
    if (poMesh->m_poVN) m_poFile->WriteArray((float*)poMesh->m_poVN, poMesh->uiGetNumVXs() * 3);
    if (poMesh->m_poUV) m_poFile->WriteArray((float*)poMesh->m_poUV, poMesh->uiGetNumVXs() * 2);

    if (poMesh->m_poTN) m_poFile->WriteArray((float*)poMesh->m_poTN, poMesh->uiGetNumPrims() * 3);
    if (poMesh->m_pusIdx) m_poFile->WriteArray((short*)poMesh->m_pusIdx, poMesh->uiGetNumIndices());

    // Save the mesh bounding volume
    SaveBoundingVolume(poMesh->poGetBV());

    CGFileUtils::EndRIFFBlock(*m_poFile);

    return (true);
}
// ----------------------------------------------------------------------------
void CSaverGEM::SaveBoundingVolume(CGGraphBV* _poBV)
{
    CGGraphBVFileIO::iSaveGraphBV(*m_poFile, _poBV);
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

    m_poFile->uiWriteData(&ucMajorVersion,1);
    m_poFile->uiWriteData(&ucMinorVersion,1);

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
void CSaverGEM::Visit(CGSceneAnimNode*)
{
    assert(false && "Warning Not Implemented");
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneSwitch*)
{
    assert(false && "Warning Not Implemented");
}// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneScreenRect*)
{
    assert(false && "Warning Not Implemented");
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneInstance*)
{
    assert(false && "Warning Not Implemented");
}
// ----------------------------------------------------------------------------
void CSaverGEM::Visit(CGSceneCamera*)
{
    assert(false && "Warning Not Implemented");
}
// ----------------------------------------------------------------------------
