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
#ifndef eShInsTexOp_TypeID_h
#define eShInsTexOp_TypeID_H
// ----------------------------------------------------------------------------

typedef enum
{
    eSITexOp_NULL,    // 0
    eSITexOp_Rotate,    // 1
    eSITexOp_Scale,    // 2
    eSITexOp_ScaleU,    // 3
    eSITexOp_ScaleV,    // 4
    eSITexOp_TransU,    // 5
    eSITexOp_TransV,    // 6
    eSITexOp_ReflectMap,    // 7
    eSITexOp_EnvMap,    // 8
    eSITexOp_Matrix,    // 9
    eSITexOp_FrameSet     // 10
} eShInsTexOp_TypeID;

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
