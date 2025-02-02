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
#include "SceneCompiler\SCNUt_SceneCompiler.h"
// -----------------------------------------------------------------------------
SCNUt_SceneCompiler::SCNUt_SceneCompiler()
{
}
// -----------------------------------------------------------------------------
SCNUt_SceneCompiler::~SCNUt_SceneCompiler()
{
}
// -----------------------------------------------------------------------------
void SCNUt_SceneCompiler::CompileScene (CGSceneNode* _poScn)
{
    int iObj;
    CGSceneNode* poSubObj;    
    CGSceneLeaf* poLeaf;

    switch ( _poScn->eGetNodeType() )
    {
        case SNT_Node:       break;

        case SNT_Leaf:      
            CompileMeshInLeaf((CGSceneLeaf*)_poScn);
        break;

        case SNT_Mux:
        case SNT_Group:
        {
            for ( iObj = 0; iObj < ( (CGSceneGroup*)_poScn )->uiNumSubObjs(); iObj++ )
            {
                CompileScene( ((CGSceneGroup*)_poScn)->poGetObject(iObj) );
            }
        }
        break;

        case SNT_Transf:
        {
            CompileScene( ((CGSceneTransf*)_poScn)->poGetObject() );
        }
        break;
        
        case SNT_Switch:
        {
            CompileScene(((CGSceneSwitch*)_poScn)->poGetObject());
        }
        break;

        case SNT_BSPNode:
        {
            CompileScene(((CGSceneBSPNode*)_poScn)->poGetBackNode());
            CompileScene(((CGSceneBSPNode*)_poScn)->poGetFrontNode());
        }
        break;
        
        case SNT_AnimNode:        break;

        case SNT_AnimGroup:       break;

        case SNT_AnimMesh:        break;

        case SNT_AnimTransf:      break;

        case SNT_AnimActionSet:   break;

        default:                  break;
    }
}
// -----------------------------------------------------------------------------
void SCNUt_SceneCompiler::CompileMeshInLeaf(CGSceneLeaf* _poLeaf)
{
    if (_poLeaf->poGetMesh()->eGetType() == E3D_MeshType::E3D_MT_Mesh)
    {
        CGMesh* poMesh = (CGMesh*)_poLeaf->poGetMesh();

        CGCompiledMesh* poCGMesh = CGRenderer::I()->poCompileMesh(poMesh, _poLeaf->poGetShader());
        _poLeaf->SetMesh(poCGMesh);

        mDel poMesh;
    }
}
// -----------------------------------------------------------------------------