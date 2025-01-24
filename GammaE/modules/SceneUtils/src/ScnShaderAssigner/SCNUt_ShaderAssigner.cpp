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
// SCNUt_ShaderAssigner
#include "ScnShaderAssigner\SCNUt_ShaderAssigner.h"

// Class SCNUt_ShaderAssigner

SCNUt_ShaderAssigner::SCNUt_ShaderAssigner()
{
}

SCNUt_ShaderAssigner::~SCNUt_ShaderAssigner()
{
}

void SCNUt_ShaderAssigner::AssignShader (CE3D_Shader* _poShader, CGSceneNode* _poObj)
{
    switch ( _poObj->eGetNodeType() )
    {
        case SNT_Gen:
        break;

        case SNT_Leaf:
        ( (CGSceneLeaf*)_poObj )->SetShader(_poShader);
        break;

        case SNT_Node:
        int iSubObj;
        for ( iSubObj = 0; iSubObj < ( (CGSceneGroup*)_poObj )->uiNumSubObjs(); iSubObj++ )
        {
            if ( ( (CGSceneGroup*)_poObj )->poGetObject(iSubObj) )
                AssignShader( _poShader,( (CGSceneGroup*)_poObj )->poGetObject(iSubObj) );
        }
        break;

        case SNT_Transf:
        AssignShader( _poShader, ( (CGSceneTransf*)_poObj )->poGetObject() );
        break;

        case SNT_AnimObject:
        break;

        case SNT_AnimNode:
        break;

        case SNT_AnimMesh:
        break;

        case SNT_AnimTransf:
        break;

        case SNT_AnimCfg:
        break;

        case SNT_AnimInstance:
        break;

        case SNT_BSPNode:
        AssignShader( _poShader, ( (CGSceneBSPNode*)_poObj )->poGetBackNode() );
        AssignShader( _poShader, ( (CGSceneBSPNode*)_poObj )->poGetFrontNode() );
        break;

        case SNT_Mux: 7 // iTest3DObj_Mux(_fd,(CGSceneMux*)_poObj);
        break;

        case SNT_CompiledLeaf:
        ( (CGSceneCompiledLeaf*)_poObj )->SetShader( _poShader);
        break;

        default:
        break;
    }
}

// Additional Declarations
