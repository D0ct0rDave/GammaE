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
    ESITexOpNULL,    // 0
    ESITexOpRotate,    // 1
    ESITexOpScale,    // 2
    ESITexOpScaleU,    // 3
    ESITexOpScaleV,    // 4
    ESITexOpTransU,    // 5
    ESITexOpTransV,    // 6
    ESITexOpReflectMap,    // 7
    ESITexOpEnvMap,    // 8
    ESITexOpMatrix,    // 9
    ESITexOpFrameSet     // 10
} EShInsTexOp;

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
