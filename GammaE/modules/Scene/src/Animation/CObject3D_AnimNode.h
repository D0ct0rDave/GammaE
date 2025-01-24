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
// --------------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Animation\CGSceneAnimObject.h"
// --------------------------------------------------------------------------------
class CGSceneAnimNode : public CGSceneAnimObject
{
    public:

        CGSceneAnimNode();
        virtual ~CGSceneAnimNode();

        // / Adds a new animation object to the animation node
        uint uiAddObject(CGSceneAnimObject* _poObj)
        {
            return ( m_poObjs.uiAdd(_poObj) );
        }

        // / Retrieves the specific animation object
        CGSceneAnimObject* poGetAnimObject(uint _uiObj)
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

        // / Recomputes the bounding volumes
        virtual void ComputeBoundVols();

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGDynArray <CGSceneAnimObject*> m_poObjs;
};

// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
