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
        void Setup(uint _uiNumStates);

        // Sets the animation between 2 states (frames) interpolated by a factor.
        virtual void SetAnimState(uint _uiSrc, uint _uiDst, float _fFactor);

        // Return the number of states this object has
        virtual uint uiGetNumStates() const;

        // / Recompute the bounding volume of all the frames
        void ComputeStatesBVols();

        // Return the bounding volume of the object for the given state
        virtual CGGraphBV* poGetStateBVol(int _iState);
        
        // Sets (overrides) the bounding volume for the given state
        virtual void SetStateBVol(int _iState, CGGraphBV* _poBV);

        // Retrieves the current computed transform
        const CGMatrix4x4& GetCurrentTranform() const;

        // / Sets the object who will receive the transformation.
        void SetObject(CGSceneNode* _poObj);

        // / Retrieves the object who will receive the transformation.
        CGSceneNode* poGetObject();
        
        // Retrieve state transforms array
        CGMatrix4x4* poGetStateTransforms();

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV();

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        // Array to store the transform keyframes
        CGMatrix4x4* m_poTransforms;
        CGStArray<CGGraphBV*> m_poStateBVs;
        CGGraphBV* m_poBV;

        uint m_uiNumStates;

        CGMatrix4x4 m_oTrans;
        CGSceneNode* m_poObject;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
