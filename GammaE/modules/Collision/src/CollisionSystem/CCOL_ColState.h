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
#ifndef CCOL_ColState_h
#define CCOL_ColState_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
class CCOL_ColState
{
    public:

        // / The initial position of the source entity at the start of the frame
        static CVect3 SrcIPos;

        // / The final position of the source entity at the end of the frame
        static CVect3 SrcFPos;

        // / The initial position of the destination entity at the start of the frame
        static CVect3 DstIPos;

        // / The final position of the destination entity at the end of the frame
        static CVect3 DstFPos;

        // / Speed of the source entity this frame
        static CVect3 SrcSp;

        // / Speed of the destination entity this frame
        static CVect3 DstSp;

        // / Destination to Source relative speed
        static CVect3 DSSp;

        // / Delta Time this frame
        static float fDeltaT;

        // / Minimum time of collision
        static float fMinColTime;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
