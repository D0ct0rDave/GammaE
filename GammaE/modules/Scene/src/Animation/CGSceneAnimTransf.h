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
#ifndef CGSceneAnimTransfH
#define CGSceneAnimTransfH
// --------------------------------------------------------------------------------
#include "Animation\CGSceneAnimNode.h"
// --------------------------------------------------------------------------------
class CGSceneAnimTransf : public CGSceneAnimNode
{
    public:
        CGSceneAnimTransf();
        virtual ~CGSceneAnimTransf();

        // / Sets up the data inside the animated object
        void Setup(CGMatrix4x4* _poTransforms, uint _uiNumStates);

        // Sets the animation between 2 states (frames) interpolated by a factor.
        virtual void SetAnimState(uint _uiSrc, uint _uiDst, float _fFactor);

        // Return the number of states this object has
        virtual uint uiGetNumStates() const;

        // / Recompute the bounding volume of all the frames
        virtual void ComputeBoundVols();

        // Return the bounding volume of the object for the given state
        virtual CGGraphBV* poGetStateBVol(int _iState);

        // Retrieves the current computed transform
        const CGMatrix4x4& GetCurrentStateTranform() const;

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        // Array to store the transform keyframes
        CGMatrix4x4* m_poTransforms;
        uint m_uiNumStates;

        CGMatrix4x4 m_oTrans;

};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
