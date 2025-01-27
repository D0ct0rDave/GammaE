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

#ifndef GSceneEnumsH
#define GSceneEnumsH

typedef enum
{
    SNT_NULL,                    // 0
    SNT_Node,                    // 1
    SNT_Leaf,                    // 2
    SNT_Group,                   // 3
    SNT_Transf,                  // 4
    
    SNT_Anim_Begin,              // 5
    SNT_AnimNode,                // 6
    SNT_AnimGroup,               // 7
    SNT_AnimMesh,                // 8
    SNT_AnimTransf,              // 9
    SNT_AnimCfg,                 // 10
    SNT_AnimInstance,            // 11
    SNT_Anim_End,                // 12

    SNT_Camera,                  // 13
    SNT_Mux,                     // 14
    SNT_BSPNode,                 // 15
    SNT_CompiledLeaf,            // 16
    SNT_ScreenRect,              // 17
    SNT_Switch,                  // 18
} ESceneNodeType;

#endif
