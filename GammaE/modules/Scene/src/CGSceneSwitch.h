// ----------------------------------------------------------------------------
/*! \class CGSceneSwitch
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneSwitchH
#define CGSceneSwitchH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class CGSceneSwitch : public CGSceneNode
{
    public:

        CGSceneSwitch();
        virtual ~CGSceneSwitch();

        // / Sets the object linked to this node.
        void SetObject(CGSceneNode* _poObj)
        {
            if ( m_poObj )
                m_poObj->Deref();

            m_poObj = _poObj;

            if ( m_poObj != NULL )
                m_poObj->Ref();
        }

        // / Retrieves the object linked to this node.
        CGSceneNode* poGetObject()
        {
            return(m_poObj);
        }

        // / Renders the geometry associated to this node.
        virtual void Render();

        // / Enables or disables the rendering of this node. By default enables it.
        void Enable(bool _bEnable = true)
        {
            m_bEnabled = _bEnable;
        }

        // / Disables the rendering of this node.
        void Disable()
        {
            m_bEnabled = false;
        }

        // / Retrieves whether this node is enabled for rendering or not.
        bool bEnabled()
        {
            return(m_bEnabled);
        }

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV();

        // General Processing Functionalities.
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:
        CGSceneNode* m_poObj;
        bool m_bEnabled;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
