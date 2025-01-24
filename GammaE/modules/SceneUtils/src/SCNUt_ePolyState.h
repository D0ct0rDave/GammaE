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
// %X% %Q% %Z% %W%

#ifndef SCNUt_ePolyState_h
#define SCNUt_ePolyState_h 1

typedef enum
{
    POLYSTATE_NONE,                    // 0
    POLYSTATE_FRONT,                    // 1
    POLYSTATE_BACK,                    // 2
    POLYSTATE_OVER,                    // 3
    POLYSTATE_ONEOVER,                    // 4
    POLYSTATE_TWOOVER,                    // 5
    POLYSTATE_CROSS1,                    // 6
    POLYSTATE_CROSS2,                    // 7
    POLYSTATE_NUMSTATES                    // 8
} SCNUt_ePolyState;

#endif
