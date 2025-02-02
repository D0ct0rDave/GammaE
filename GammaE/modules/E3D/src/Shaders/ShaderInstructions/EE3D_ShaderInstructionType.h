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
#ifndef EShaderInstructionType_h
#define E3D_ShaderInstructionType_H
// ----------------------------------------------------------------------------
typedef enum
{
    E3D_SHI_NULL,           // 0
    E3D_SHI_Texture,        // 1
    E3D_SHI_Color,          // 2
    E3D_SHI_Wireframe,      // 3
    E3D_SHI_Extension,      // 4
    E3D_SHI_GeoOp,          // 5
    E3D_SHI_TexOp,          // 6
    E3D_SHI_BlendOp,        // 7
    E3D_SHI_SetTMU,         // 8
    E3D_SHI_Program,        // 9
    E3D_SHI_ZOp,            // 10
    E3D_SHI_NumInsts
} E3D_ShaderInstructionType;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
