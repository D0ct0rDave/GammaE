// ----------------------------------------------------------------------------
/*! \class CGSceneGroup
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneGroupH
#define CGSceneGroupH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGSceneGroup : public CGSceneNode
{
    public:
        CGSceneGroup();

        // / Constructor with initialization.
        CGSceneGroup(uint _uiMaxSubObjs);

        // / Destructor of the class
        virtual ~CGSceneGroup();

        // / Creates the an array to store the number of objects.
        virtual void Init(uint _uiMaxSubObjs);

        // / Deletes all the objects in the group.
        virtual void Clear();

        // / Deletes an object in the given position.
        void DelObject(uint _uiPos);

        // / Adds a new object into the group.
        int iAddObject(CGSceneNode* _poObj);

        // / Sets the object at the given pos.
        virtual void SetObject(CGSceneNode* _poObj, uint _uiPos);

        // / Retrieves the object at the given pos.
        CGSceneNode* poGetObject(uint _uiPos);

        // / Retrieve the number of non NULL objects in the group.
        uint uiNumSubObjs();
        
        // Sets the bounding volume of the object
        void SetBV(CGGraphBV* _poBV);

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV();

        // General Processing Functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGStArray <CGSceneNode*> m_poSubObj;
        CGGraphBV* m_poBV;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
