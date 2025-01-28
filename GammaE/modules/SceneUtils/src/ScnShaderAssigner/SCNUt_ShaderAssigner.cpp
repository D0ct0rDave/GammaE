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

void SCNUt_ShaderAssigner::AssignShader (CGShader* _poShader, CGSceneNode* _poObj)
{
    switch ( _poObj->eGetNodeType() )
    {
        case SNT_Node:
        break;

        case SNT_Leaf:
        ( (CGSceneLeaf*)_poObj )->SetShader(_poShader);
        break;

        case SNT_Group:
        case SNT_Mux:
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
        case SNT_Switch:
        AssignShader(_poShader, ((CGSceneSwitch*)_poObj)->poGetObject());
        break;

        case SNT_AnimNode:
        break;

        case SNT_AnimGroup:
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

        

        default:
        break;
    }
}

// Additional Declarations
