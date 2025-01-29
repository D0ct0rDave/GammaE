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
#include "GammaE_Mem.h"
#include "GammaE_Scene.h"
// SCNUt_TriSceneAccumulator
#include "SCNUt_TriSceneAccumulator.h"
// SCNUt_Scn2TriScnBuilder
#include "Scn2TriScnBuilder\SCNUt_Scn2TriScnBuilder.h"
// SCNUt_TransformTriScene
#include "TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_Mesh2TriScene
#include "Mesh2TriScn\SCNUt_Mesh2TriScene.h"
#define TRANSF_STACK_SIZE   64

// Class SCNUt_Scn2TriScnBuilder

SCNUt_Scn2TriScnBuilder::SCNUt_Scn2TriScnBuilder()
{
}

SCNUt_Scn2TriScnBuilder::~SCNUt_Scn2TriScnBuilder()
{
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuild (CGSceneNode* _poScene, SCNUt_MaterialTable& _oMTable)
{
    CGMatrix4x4 oMatStack[TRANSF_STACK_SIZE];
    oMatStack[0].LoadIdentity();

    return ( poBuildRec(_poScene,oMatStack,0,_oMTable) );
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuildRec (CGSceneNode* _poScene, CGMatrix4x4* _poMStack, int _iMPos, SCNUt_MaterialTable& _poMTab)
{
    if ( !_poScene ) return(NULL);

    switch ( _poScene->eGetNodeType() )
    {
        case SNT_Node:
        break;

        case SNT_Leaf:
        {
            CGSceneLeaf* poLeaf = (CGSceneLeaf*)_poScene;
            if (poLeaf->poGetMesh()->eGetType() == E3D_MeshType::E3D_MT_Mesh)
            {
                CGMesh* poMesh = (CGMesh*)poLeaf->poGetMesh();
                const CGShader* poShader = poLeaf->poGetShader();
                const char* szShaderName = CGShaderWH::I()->sGetName( poShader ).szString();

                int iMatID = _poMTab.iGetIdx(poShader);

                if (iMatID == -1 )
                    iMatID = _poMTab.uiAdd(poShader, szShaderName);

                return( poBuildMesh(*poMesh, iMatID, _poMStack[_iMPos]) );
            }
        }
        break;

        case SNT_Group:
        {
            CGSceneGroup* poNode;
            SCNUt_TriSceneAccumulator* poTSA;
            SCNUt_TriScene* poTS = NULL;

            poNode = (CGSceneGroup*)_poScene;

            // Create a triangle scene accumulator
            poTSA = mNew SCNUt_TriSceneAccumulator;

            for ( uint uiObj = 0; uiObj < poNode->uiNumSubObjs(); uiObj++ )
            {
                if ( poNode->poGetObject(uiObj) )
                {
                    poTS = poBuildRec(poNode->poGetObject(uiObj),_poMStack,_iMPos,_poMTab);
                    poTSA->AddTriScene(poTS);

                    // Delete retrieved scene
                    mDel poTS;
                }
            }

            return(poTSA);
        }
        break;

        case SNT_Transf:
        {
            if ( _iMPos == TRANSF_STACK_SIZE ) return(NULL);

            CGSceneTransf* poTransf;
            poTransf = (CGSceneTransf*)_poScene;

            // ----------------------------------
            // Update the top of the matrix stack
            // ----------------------------------
            _iMPos++;

            // Multiply by the node matrix
            _poMStack[_iMPos].Multiply( _poMStack[_iMPos - 1],poTransf->oTransf() );

            return( poBuildRec(poTransf->poGetObject(),_poMStack,_iMPos,_poMTab) );
        }
        break;

        case SNT_AnimNode:
        break;

        case SNT_AnimGroup:
        break;

        case SNT_AnimMesh:
        break;

        case SNT_AnimTransf:
        break;

        case SNT_AnimActionSet:
        break;

        case SNT_BSPNode:
        {
            SCNUt_TriSceneAccumulator* poTSA;
            SCNUt_TriScene* poTS;
            CGSceneBSPNode* poBSPNode;

            poBSPNode = (CGSceneBSPNode*)_poScene;

            // Create a triangle scene accumulator
            poTSA = mNew SCNUt_TriSceneAccumulator;

            if ( poBSPNode->poGetBackNode() )
            {
                poTS = poBuildRec(poBSPNode->poGetBackNode(),_poMStack,_iMPos,_poMTab);
                poTSA->AddTriScene(poTS);
                // Delete retrieved scene
                mDel poTS;
            }

            if ( poBSPNode->poGetFrontNode() )
            {
                poTS = poBuildRec(poBSPNode->poGetFrontNode(),_poMStack,_iMPos,_poMTab);
                poTSA->AddTriScene(poTS);
                // Delete retrieved scene
                mDel poTS;
            }

            return(poTSA);
        }
        break;

        case SNT_Mux:
        break;

        default:
        break;
    }

    return(NULL);
}

SCNUt_TriScene* SCNUt_Scn2TriScnBuilder::poBuildMesh(const CGMesh& _oMesh, int _iMat, const CGMatrix4x4& _oMat)
{
    SCNUt_Mesh2TriScene oM2TS;
    SCNUt_TransformTriScene oTrTS;
    SCNUt_TriScene* poTScn;

    poTScn = oM2TS.Generate(_oMesh,_iMat);
    if ( !poTScn ) return(NULL);

    oTrTS.Transform(poTScn,_oMat);

    return(poTScn);
}

// Additional Declarations
