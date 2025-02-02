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
    if (_poObj == NULL)
    {
        return;
    }

    switch ( _poObj->eGetNodeType() )
    {
        case SNT_Node:
        break;

        case SNT_Leaf:
        ( (CGSceneLeaf*)_poObj )->SetShader(_poShader);
        break;

        case SNT_Group:
        case SNT_Mux:
        {
            for (int iSubObj = 0; iSubObj < ((CGSceneGroup*)_poObj)->uiNumSubObjs(); iSubObj++)
            {
                if (((CGSceneGroup*)_poObj)->poGetObject(iSubObj))
                    AssignShader(_poShader, ((CGSceneGroup*)_poObj)->poGetObject(iSubObj));
            }
        }
        break;

        case SNT_Transf:
        AssignShader( _poShader, ( (CGSceneTransf*)_poObj )->poGetObject() );
        break;

        case SNT_Switch:
        AssignShader(_poShader, ((CGSceneSwitch*)_poObj)->poGetObject());
        break;

        case SNT_BSPNode:
        {
            AssignShader(_poShader, ((CGSceneBSPNode*)_poObj)->poGetBackNode());
            AssignShader(_poShader, ((CGSceneBSPNode*)_poObj)->poGetFrontNode());
        }
        break;

        case SNT_AnimNode:
        break;

        case SNT_AnimGroup:
        {
            for (uint iSubObj = 0; iSubObj < ((CGSceneAnimGroup*)_poObj)->uiNumAnimObjects(); iSubObj++)
            {
                CGSceneAnimNode* poAnimObj = ((CGSceneAnimGroup*)_poObj)->poGetAnimObject(iSubObj);
                if (poAnimObj != NULL)
                {
                    AssignShader(_poShader, poAnimObj);
                }
            }
        }
        break;

        case SNT_AnimMesh:
        {
            ((CGSceneAnimMesh*)_poObj)->SetShader(_poShader);
        }
        break;

        case SNT_AnimTransf:
        {
            AssignShader(_poShader, ((CGSceneAnimTransf*)_poObj)->poGetObject());
        }
        break;

        case SNT_AnimActionSet:
        {
            AssignShader(_poShader, ((CGSceneAnimActionSet*)_poObj)->poGetAnimObject());
        }
        break;

        default:
        break;
    }
}

// Additional Declarations
