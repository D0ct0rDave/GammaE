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
#ifndef CGSceneAnimNodeH
#define CGSceneAnimNodeH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class CGSceneAnimNode : public CGSceneNode
{
    public:
        CGSceneAnimNode();

        // Sets the animation between 2 states (frames) interpolated by a factor.
        virtual void SetAnimState(uint _uiSrc, uint _uiDst, float _fFactor) = 0;

        // Return the number of states this object has
        virtual uint uiGetNumStates() const = 0;

        // Return the bounding volume of the object for the given state
        virtual CGGraphBV* poGetStateBVol(int _iState) = 0;

        // Sets (overrides) the bounding volume for the given state
        virtual void SetStateBVol(int _iState, CGGraphBV* _poBV) = 0;
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
