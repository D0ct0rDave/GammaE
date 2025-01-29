// ----------------------------------------------------------------------------
/*! \class CGSceneMux
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneMuxH
#define CGSceneMuxH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGSceneGroup.h"
// ----------------------------------------------------------------------------
class CGSceneMux : public CGSceneGroup
{
    public:

        CGSceneMux();

        // / Initializes the class.
        virtual void Init(uint _uiMaxSubObjects);

        // / Selects all the childs in the node.
        void SelectAll();

        // / Deselects all the childs in the node.
        void SelectNone();

        // / Select an specific child in the node.
        void Select(uint _uiIdx);

        // / Deselect an specific child in the node.
        void Deselect(uint _uiIdx);

        // / Returns whether a given child is selected or not in the current node.
        bool bIsSelected(uint _uiIdx);

        // General Processing Functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGStArray <bool> m_bSelected;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
