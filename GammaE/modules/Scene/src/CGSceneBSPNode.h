// ----------------------------------------------------------------------------
/*! \class CGSceneBSPNode
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSceneBSPNodeH
#define CGSceneBSPNodeH
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class CGSceneBSPNode : public CGSceneNode
{
    public:

        CGSceneBSPNode();
        virtual ~CGSceneBSPNode();

        // / Sets up the current bsp node.
        void Setup(CGSceneNode* _poBackNode, CGSceneNode* _poFrontNode, const CGPlane& _oPlane)
        {
            m_poBackNode = _poBackNode;
            m_poFrontNode = _poFrontNode;
            m_oPartitionPlane = _oPlane;
        }

        // / Sets the back child of this node.
        void SetBackNode(CGSceneNode* _poBackNode)
        {
            m_poBackNode = _poBackNode;
        }

        // / Sets the front child of this node.
        void SetFrontNode(CGSceneNode* _poFrontNode)
        {
            m_poFrontNode = _poFrontNode;
        }

        // / Retrieves the back child of this node.
        CGSceneNode* poGetBackNode()
        {
            return (m_poBackNode);
        }

        // / Retrieves the front child of this node.
        CGSceneNode* poGetFrontNode()
        {
            return(m_poFrontNode);
        }

        // / Sets the partition plane of this node.
        void SetPartitionPlane(const CGPlane& _oPlane)
        {
            m_oPartitionPlane = _oPlane;
        }

        // / Retrieves the partition plane for this node.
        const CGPlane& oGetPartitionPlane()
        {
            return(m_oPartitionPlane);
        }

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

        CGSceneNode* m_poBackNode;
        CGSceneNode* m_poFrontNode;
        CGPlane m_oPartitionPlane;
        CGGraphBV* m_poBV;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
