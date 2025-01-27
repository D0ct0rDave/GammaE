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
#ifndef CGSceneAnimGroupH
#define CGSceneAnimGroupH
// --------------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Animation\CGSceneAnimNode.h"
// --------------------------------------------------------------------------------
class CGSceneAnimGroup : public CGSceneAnimNode
{
    public:

        CGSceneAnimGroup();
        virtual ~CGSceneAnimGroup();

        void Setup(uint _uiNumStates);
        
        // Sets the animation between 2 states (frames) interpolated by a factor.
        virtual void SetAnimState(uint _uiSrc, uint _uiDst, float _fFactor);

        // Return the number of states this object has
        virtual uint uiGetNumStates() const;

        // / Recomputes the bounding volumes for each state
        virtual void ComputeStatesBVols();

        // Return the bounding volume of the object for the given state
        virtual CGGraphBV* poGetStateBVol(int _iState);

        // / Adds a new animation object to the animation node
        uint uiAddAnimObject(CGSceneAnimNode* _poObj)
        {
            return ( m_poObjs.uiAdd(_poObj) );
        }

        // / Retrieves the specific animation object
        CGSceneAnimNode* poGetAnimObject(uint _uiObj)
        {
            return(m_poObjs[_uiObj]);
        }

        // / Retrieves the number of child animated objects
        uint uiNumAnimObjects()
        {
            return ( m_poObjs.uiNumElems() );
        }

        // / Clears all the array of animated objects
        void Clear()
        {
            m_poObjs.Clear();
        }

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:
        uint m_uiNumStates;
        CGDynArray<CGSceneAnimNode*> m_poObjs;
        CGStArray<CGGraphBV*> m_poBVolStates;
        CGGraphBV* m_poBV;
};

// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
