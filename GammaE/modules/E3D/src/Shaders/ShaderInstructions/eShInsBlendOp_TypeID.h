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
#ifndef eShInsBlendOp_TypeID_h
#define eShInsBlendOp_TypeID_H
// ----------------------------------------------------------------------------
typedef enum
{
    E3D_BM_NULL,    // 0
    E3D_BM_Copy,    // 1
    E3D_BM_Mult,    // 2
    E3D_BM_Mult2x,    // 3
    E3D_BM_Add,    // 4
    E3D_BM_AddAndMult,    // 5
    E3D_BM_MultAndAdd,    // 6
    E3D_BM_Alpha,    // 7
    E3D_BM_AlphaAdd,    // 8
    E3D_BM_AlphaInv,    // 9
    E3D_BM_AlphaThrough     // 10
} eShInsBlendOp_TypeID;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
