// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GammaE_FileSys.h"
#include "GammaE_Mem.h"
#include "GEMFile.h"

#include "CGSceneBSPNode.h"
#include "CGSceneCamera.h"
#include "CGSceneInstance.h"
#include "CGSceneLeaf.h"
#include "CGSceneMux.h"
#include "CGSceneNode.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"
#include "CGSceneTransf.h"
#include "CGSceneScreenRect.h"

#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimCfgGen.h"
#include "Animation/CGSceneAnimCfgMgr.h"
#include "Animation/CGSceneAnimGen.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimMeshInstance.h"
#include "Animation/CGSceneAnimNode.h"
#include "Animation/CGSceneAnimTransf.h"

// ---------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "CGVLoaderGEM.h"

#include "CGSceneBSPNode.h"
#include "CGSceneCamera.h"
#include "CGSceneCompiledLeaf.h"
#include "CGSceneInstance.h"
#include "CGSceneLeaf.h"
#include "CGSceneMux.h"
#include "CGSceneNode.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"
#include "CGSceneTransf.h"
#include "CGSceneScreenRect.h"

#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimCfgGen.h"
#include "Animation/CGSceneAnimCfgMgr.h"
#include "Animation/CGSceneAnimGen.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimMeshInstance.h"
#include "Animation/CGSceneAnimNode.h"
#include "Animation/CGSceneAnimTransf.h"
// ----------------------------------------------------------------------------
CObject3D* CGVLoaderGEM::poLoad(CFile* _poFile)
{
    m_poFile = _poFile;
    Visit (
        return(CObject3D * m_poReturnValue);
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CObject3D * _poNode)
        {
        }
// ----------------------------------------------------------------------------
// Visitor for BSP Nodes
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneBSPNode * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneCamera * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneCompiledLeaf * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneInstance * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneLeaf * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneMux * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneNode * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneScreenRect * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneSwitch * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneTransf * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimCfg * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimCfgGen * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimCfgMgr * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimObject * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimMesh * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimMeshInstance * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimNode * _poNode)
        {
            m_poReturnValue
        }
// ----------------------------------------------------------------------------
        void CGVLoaderGEM::Visit(CGSceneAnimTransf * _poNode)
        {
            m_poReturnValue
        }
// ---------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Class CLoaderGEM
        CLoaderGEM::CLoaderGEM()
        {
        }
// -----------------------------------------------------------------------------
        CLoaderGEM::~CLoaderGEM()
        {
        }
// -----------------------------------------------------------------------------
        CObject3D* CLoaderGEM::pLoad (char* Filename)
        {
        }
// -----------------------------------------------------------------------------
        CObject3D* CLoaderGEM::pLoad (CFile & _oFile)
        {
        }
// -----------------------------------------------------------------------------
        CObject3D* CLoaderGEM::pLoad3DObject (CFile & _oFile)
        {
            return (NULL);
        }
// -----------------------------------------------------------------------------
        CMesh* CLoaderGEM::pLoadMesh (CFile & _oFile)
        {
            unsigned int uiBlockSize;
            unsigned int uiID;

            _oFile.iRead(&uiID,4);
            _oFile.iRead(&uiBlockSize,4);

            if ( uiID != GEM_MESH_IDENTIFIER )
            {
                // ERROR_SetError("GEMLD001","Mesh not found");
                _oFile.uiSeek(-8,eFile_SM_Cur);
                return (NULL);
            }

            unsigned int uiMeshMask;
            CMesh* Mesh = mNew CMesh;

            _oFile.iRead(&Mesh->usNumVerts,2);
            _oFile.iRead(&Mesh->usNumPrims,2);
            _oFile.iRead(&Mesh->eMeshType,4);

            // mesh mask
            _oFile.iRead( &uiMeshMask,4);

            Mesh->Init(Mesh->usNumVerts,Mesh->usNumPrims,Mesh->eMeshType,uiMeshMask);

            // mesh components
            if ( Mesh->VXs ) _oFile.iRead( Mesh->VXs,Mesh->usNumVerts * sizeof(CGVect3) );
            if ( Mesh->UVs ) _oFile.iRead( Mesh->UVs,Mesh->usNumVerts * sizeof(CGVect2) );
            if ( Mesh->VCs ) _oFile.iRead( Mesh->VCs,Mesh->usNumVerts * sizeof(CGVect4) );
            if ( Mesh->VNs ) _oFile.iRead( Mesh->VNs,Mesh->usNumVerts * sizeof(CGVect3) );
            if ( Mesh->UVs2 ) _oFile.iRead( Mesh->UVs2,Mesh->usNumVerts * sizeof(CGVect2) );
            if ( Mesh->TNs ) _oFile.iRead( Mesh->TNs,Mesh->usNumPrims * sizeof(CGVect3) );
            if ( Mesh->Idxs ) _oFile.iRead( Mesh->Idxs,Mesh->usNumIdxs * sizeof(unsigned short) );

            // Save the mesh bounding volume
            if ( Mesh->BVol ) mDel Mesh->BVol;
            Mesh->BVol = CGraphBV_FileIO::pLoadGraphBV(_oFile);

            return (Mesh);
        }
// -----------------------------------------------------------------------------
        CGSceneLeaf* CLoaderGEM::pLoad3DObj_Leaf (CFile & _oFile)
        {
            char MaterialName[MAX_CHARS];
            CGShader* poShader;

            CGSceneLeaf* pObj = mNew CGSceneLeaf();

            // Read material name
            _oFile.iRead(MaterialName,MAX_CHARS);

            // Get material object
            poShader = CE3D_ShaderWH::I()->poCreateShader(MaterialName);

            pObj->SetShader( poShader );

            // Write mesh
            pObj->SetMesh( pLoadMesh(_oFile) );
            pObj->SetBoundVol( pObj->poGetMesh()->GetBoundVol() );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneNode* CLoaderGEM::pLoad3DObj_Node (CFile & _oFile)
        {
            CGSceneNode* pObj = mNew CGSceneNode();
            CObject3D* pChild;

            unsigned int uiNumSubObjs;
            unsigned int uiObj;

            // Read subobject array props
            _oFile.iRead(&uiNumSubObjs,4);

            pObj->Init(uiNumSubObjs);

            // read subobjects
            for ( uiObj = 0; uiObj < uiNumSubObjs; uiObj++ )
            {
                pChild = pLoad3DObject(_oFile);

                if ( pChild->eGetTypeID() != OBJ3D_NULL )
                    pObj->iAddObject(pChild );
            }

            // Load the bounding volume
            if ( pObj->poGetBoundVol() ) mDel pObj->poGetBoundVol();
            pObj->SetBoundVol( CGraphBV_FileIO::pLoadGraphBV(_oFile) );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneTransf* CLoaderGEM::pLoad3DObj_Transf (CFile & _oFile)
        {
            CGSceneTransf* pObj = mNew CGSceneTransf();

            CGVect3 oDir;
            CGVect3 oSide;
            CGVect3 oUp;
            CGVect3 oPos;

            // Read node transformation parameters
            _oFile.iRead( &oPos,sizeof(CGVect3) );
            _oFile.iRead( &oDir,sizeof(CGVect3) );
            _oFile.iRead( &oSide,sizeof(CGVect3) );
            _oFile.iRead( &oUp,sizeof(CGVect3) );

            // Read attached object
            pObj->SetObject( pLoad3DObject(_oFile) );

            // Set node transformation parameters
            pObj->Setup(oPos,oDir,oSide,oUp);

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneAnimNode* CLoaderGEM::pLoad3DObj_AnimNode (CFile & _oFile)
        {
            int iMaxSubObjects;
            int iNumSubObjects;
            int iNumStates;
            int iObj;
            int iState;
            CGSceneAnimNode* pObj;

            // Read subobject array props
            _oFile.iRead(&iNumSubObjects,4);
            _oFile.iRead(&iMaxSubObjects,4);
            _oFile.iRead(&iNumStates,4);

            // Initialize object
            pObj = mNew CGSceneAnimNode;
            pObj->Init(iMaxSubObjects);
            pObj->CreateStates(iNumStates);

            // Load the the bounding volume state array
            for ( iState = 0; iState < iNumStates; iState++ )
            {
                mDel pObj->poBVolStates[iState];
                pObj->poBVolStates[iState] = CGraphBV_FileIO::pLoadGraphBV(_oFile);
            }
            pObj->SetBoundVol(pObj->poBVolStates[0]);

            // Read subobjects
            for ( iObj = 0; iObj < iNumSubObjects; iObj++ )
                pObj->AddObject( (CGSceneAnimObject*)pLoad3DObject( _oFile ) );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneAnimMesh* CLoaderGEM::pLoad3DObj_AnimMesh (CFile & _oFile)
        {
            int iNumStateVXs;
            int iNumStates;
            int iState;
            CGSceneAnimMesh* pObj;

            // Write object fields
            _oFile.iRead(&iNumStates,4);
            _oFile.iRead(&iNumStateVXs,4);

            pObj = mNew CGSceneAnimMesh;
            pObj->CreateStates(iNumStates,iNumStateVXs);

            // Load the the vertexs and normals state array
            _oFile.iRead( pObj->pMeshStates,iNumStates * iNumStateVXs * sizeof(CGVect3) );
            _oFile.iRead( pObj->pNMeshStates,iNumStates * iNumStateVXs * sizeof(CGVect3) );

            // Load the the bounding volume state array
            for ( iState = 0; iState < iNumStates; iState++ )
            {
                mDel pObj->pBVolStates[iState];
                pObj->pBVolStates[iState] = CGraphBV_FileIO::pLoadGraphBV(_oFile);
            }
            // pObj->SetBoundVol(pObj->pBVolStates[0]);

            // Load leaf node
            pObj->SetLeaf( (CGSceneLeaf*) pLoad3DObject( _oFile ) );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneAnimTransf* CLoaderGEM::pLoad3DObj_AnimTransf (CFile & _oFile)
        {
            CGSceneAnimTransf* pObj;

            int iNumStates;

            // Read object fields
            _oFile.iRead(&iNumStates,4);

            // Create and initialize object
            pObj = mNew CGSceneAnimTransf;
            pObj->CreateStates(iNumStates);

            _oFile.iRead( pObj->pTransStates,iNumStates * sizeof(CGMatrix4x4) );
            pObj->ComputeBoundVol();

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneAnimCfg* CLoaderGEM::pLoad3DObj_AnimCfg (CFile & _oFile)
        {
            CGSceneAnimCfg* pObj;
            int iNumFrameAnims;

            // Read object number of object animations
            _oFile.iRead(&iNumFrameAnims,4);

            // Create and initialize object
            pObj = mNew CGSceneAnimCfg;
            pObj->CreateFrameAnims(iNumFrameAnims);

            // Read frame animations
            _oFile.iRead( pObj->GetFrameAnim(),iNumFrameAnims * sizeof(TFrameAnimation) );

            // Load attached object
            pObj->SetAnimObj ( (CGSceneAnimObject*)pLoad3DObject( _oFile ) );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneAnimCfgMgr* CLoaderGEM::pLoad3DObj_AnimCfgMgr (CFile & _oFile)
        {
            CGSceneAnimCfgMgr* pObj;
            int iMaxAnimObjs;
            int iNumAnimObjs;
            int iObj;

            // Read object fields
            _oFile.iRead(&iMaxAnimObjs,4);
            _oFile.iRead(&iNumAnimObjs,4);

            // Create and initialize object
            pObj = mNew CGSceneAnimCfgMgr;
            pObj->Init(iMaxAnimObjs);

            // Load attached objects
            for ( iObj = 0; iObj < iNumAnimObjs; iObj++ )
                pObj->AddAnimObj( (CGSceneAnimCfg*)pLoad3DObject( _oFile ) );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneBSPNode* CLoaderGEM::pLoad3DObj_BSPNode (CFile & _oFile)
        {
            CGSceneBSPNode* pObj = mNew CGSceneBSPNode();

            // Write node transformation parameters
            _oFile.iRead( pObj->poGetPartitionPlane(),sizeof(CGPlane) );

            pObj->SetBackNode ( pLoad3DObject(_oFile) );
            pObj->SetFrontNode( pLoad3DObject(_oFile) );

            // Load the bounding volume
            if ( pObj->poGetBoundVol() ) mDel pObj->poGetBoundVol();
            pObj->SetBoundVol( CGraphBV_FileIO::pLoadGraphBV(_oFile) );

            return (pObj);
        }
// -----------------------------------------------------------------------------
        CGSceneMux* CLoaderGEM::pLoad3DObj_Mux (CFile & _oFile)
        {
            return (NULL);
        }
// -----------------------------------------------------------------------------
        }     // namespace GammaE // namespace Math
