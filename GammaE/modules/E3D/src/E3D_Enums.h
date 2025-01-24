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
#ifndef E3D_EnumsH
#define E3D_EnumsH
// ----------------------------------------------------------------------------
typedef enum
{
    E3D_CM_Enable,      // 0
    E3D_CM_Disable,     // 1
    E3D_CM_Current,     // 2
    E3D_CM_Last,        // 3
    E3D_CM_NumCMs       // 4
} E3D_ChannelMask;

typedef enum
{
    E3D_FM_None,        // 0
    E3D_FM_Linear,      // 1
    E3D_FM_Exp,         // 2
    E3D_FM_Exp2,        // 3
    E3D_FM_Current,     // 4
    E3D_FM_Last,        // 5
    E3D_FM_NumFMs       // 6
} E3D_FogMode;

typedef enum
{
    E3D_RB_None,        // 0
    E3D_RB_Front,       // 1
    E3D_RB_Back,        // 2
    E3D_RB_Z,           // 3
    E3D_RB_Stencil,     // 4
    E3D_RB_NumTypes     // 5
} E3D_RenderBuffer_Type;

typedef enum
{
    E3D_SA_None,        // 0
    E3D_SA_Keep,        // 1
    E3D_SA_Zero,        // 2
    E3D_SA_Inc,         // 3
    E3D_SA_Dec,         // 4
    E3D_SA_Inv,         // 5
    E3D_SA_Replace,     // 6
    E3D_SA_NumSAs       // 7
} E3D_StencilAction;

typedef enum
{
    E3D_SF_None,        // 0
    E3D_SF_Never,       // 1
    E3D_SF_Less,        // 2
    E3D_SF_LEqual,      // 3
    E3D_SF_Greater,     // 4
    E3D_SF_GEqual,      // 5
    E3D_SF_Equal,       // 6
    E3D_SF_NotEqual,    // 7
    E3D_SF_Always,      // 8
    E3D_SF_Current,     // 9
    E3D_SF_Last,        // 10
    E3D_SF_NumSFs       // 11
} E3D_StencilFunc;

typedef enum
{
    E3D_ZTF_None,       // 0
    E3D_ZTF_Never,      // 1
    E3D_ZTF_Less,       // 2
    E3D_ZTF_LEqual,     // 3
    E3D_ZTF_Greater,    // 4
    E3D_ZTF_GEqual,     // 5
    E3D_ZTF_Equal,      // 6
    E3D_ZTF_NotEqual,   // 7
    E3D_ZTF_Always,     // 8
    E3D_ZTF_Current,    // 9
    E3D_ZTF_Last,       // 10
    E3D_ZTF_NumZTFs     // 11
} E3D_ZTestFunc;

typedef enum
{
    E3D_ZW_Enable,      // 0
    E3D_ZW_Disable,     // 1
    E3D_ZW_Current,     // 2
    E3D_ZW_Last,        // 3
    E3D_FM_NumZWs       // 4
} E3D_ZWrite;

typedef enum
{
    E3D_BM_NULL,        // 0
    E3D_BM_Copy,        // 1
    E3D_BM_Mult,        // 2
    E3D_BM_Mult2x,      // 3
    E3D_BM_Add,         // 4
    E3D_BM_AddAndMult,  // 5
    E3D_BM_MultAndAdd,  // 6
    E3D_BM_Alpha,       // 7
    E3D_BM_AlphaAdd,    // 8
    E3D_BM_AlphaInv,    // 9
    E3D_BM_AlphaThrough // 10
} E3D_BlendMode;

typedef enum
{
    E3D_PT_Perspective, // 0
    E3D_PT_Orthogonal   // 1
} E3D_ProjectorType;

typedef enum
{
    E3D_MT_None,

    E3D_MT_Mesh,
    E3D_MT_CompiledMesh,

    E3D_MT_NumTypes
} E3D_MeshType;

// ----------------------------------------------------------------------------
typedef enum
{
    E3D_PT_NONE,

    E3D_PT_TRIS,
    E3D_PT_QUADS,

    E3D_PT_TRIFANS,
    E3D_PT_TRISTRIPS,
    E3D_PT_QUADSTRIPS,

    // Non-indexed primitives
    E3D_PT_NITRIS,
    E3D_PT_NIQUADS,
    E3D_PT_NITRISTRIP,

    E3D_PT_NUM_MESHTYPES
}E3D_PrimitiveType;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
