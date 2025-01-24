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

// SCNUt_SceneCompiler
#include "SceneCompiler\SCNUt_SceneCompiler.h"

// Class SCNUt_SceneCompiler

SCNUt_SceneCompiler::SCNUt_SceneCompiler()
    : bNULLMaterials(true)
{
}

SCNUt_SceneCompiler::~SCNUt_SceneCompiler()
{
}

void SCNUt_SceneCompiler::CompileScene (CGSceneNode* _poScn)
{
    int iObj;
    CGSceneNode* poSubObj;
    CGCompiledMesh* poCGMesh;
    CGSceneCompiledLeaf* poCLeaf;
    CGSceneLeaf* poLeaf;

    switch ( _poScn->eGetNodeType() )
    {
        case SNT_Gen:         break;

        case SNT_Leaf:            break;

        case SNT_Node:
        {
            for ( iObj = 0; iObj < ( (CGSceneGroup*)_poScn )->uiNumSubObjs(); iObj++ )
            {
                poSubObj = ( (CGSceneGroup*)_poScn )->poGetObject(iObj);

                if ( poSubObj )
                {
                    if ( poSubObj->eGetNodeType() == SNT_Leaf )
                    {
                        poLeaf = (CGSceneLeaf*)poSubObj;

                        // Generate a compiled mesh
                        poCGMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

                        // Create and setup the compiled node
                        poCLeaf = mNew CGSceneCompiledLeaf;

                        poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader() );

                        poCLeaf->SetCGMesh(poCGMesh);

                        // Substitute the old non-compiled leaf node
                        ( (CGSceneGroup*)_poScn )->SetObject(poCLeaf,iObj);

                        // We didn't need the old node anymore
                        poLeaf->Deref();
                    }
                    else
                        CompileScene(poSubObj);
                }
            }
        }
        break;

        case SNT_Transf:
        {
            poSubObj = ( (CGSceneTransf*)_poScn )->poGetObject();
            if ( poSubObj->eGetNodeType() == SNT_Leaf )
            {
                poLeaf = (CGSceneLeaf*) poSubObj;

                // Generate a compiled mesh
                poCGMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

                // Create and setup the compiled node
                poCLeaf = mNew CGSceneCompiledLeaf;

                poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader() );

                poCLeaf->SetCGMesh(poCGMesh);

                // Substitute the old non-compiled leaf node
                ( (CGSceneTransf*)_poScn )->SetObject(poCLeaf);

                // We didn't need the old node anymore
                poCLeaf->Deref();
            }
            else
            {
                CompileScene(poSubObj);
            }
        }
        break;

        case SNT_AnimObject:      break;

        case SNT_AnimNode:        break;

        case SNT_AnimMesh:        break;

        case SNT_AnimTransf:      break;

        case SNT_AnimCfg:         break;

        case SNT_AnimInstance:    break;

        case SNT_BSPNode:
        {
            // Back node
            poSubObj = ( (CGSceneBSPNode*)_poScn )->poGetBackNode();
            if ( poSubObj )
            {
                if ( poSubObj->eGetNodeType() == SNT_Leaf )
                {
                    poLeaf = (CGSceneLeaf*)poSubObj;

                    // Generate a compiled mesh
                    poCGMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

                    // Create and setup the compiled node
                    poCLeaf = mNew CGSceneCompiledLeaf;
                    poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader() );
                    poCLeaf->SetCGMesh(poCGMesh);

                    // Substitute the old non-compiled leaf node
                    ( (CGSceneBSPNode*)_poScn )->SetBackNode(poSubObj);

                    // We didn't need the old node anymore
                    poLeaf->Deref();
                }
                else
                    CompileScene( poSubObj );
            }

            // Front node
            poSubObj = ( (CGSceneBSPNode*)_poScn )->poGetFrontNode();
            if ( poSubObj )
            {
                if ( poSubObj->eGetNodeType() == SNT_Leaf )
                {
                    poLeaf = (CGSceneLeaf*)poSubObj;

                    // Generate a compiled mesh
                    poCGMesh = CGRenderer::I()->poCompileMesh( poLeaf->poGetMesh(),poLeaf->poGetShader() );

                    // Create and setup the compiled node
                    poCLeaf = mNew CGSceneCompiledLeaf;
                    poCLeaf->SetShader( bNULLMaterials?NULL:poLeaf->poGetShader() );
                    poCLeaf->SetCGMesh(poCGMesh);

                    // Substitute the old non-compiled leaf node
                    ( (CGSceneBSPNode*)_poScn )->SetFrontNode(poSubObj);

                    // We didn't need the old node anymore
                    poLeaf->Deref();
                }
                else
                    CompileScene( poSubObj );
            }
        }
        break;

        case SNT_Mux:                    // iTest3DObj_Mux(_fd,(CGSceneMux*)_pObj);
        break;

        default:                    break;
    }
}

// Additional Declarations
