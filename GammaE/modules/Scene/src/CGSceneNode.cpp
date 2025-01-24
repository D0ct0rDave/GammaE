// ----------------------------------------------------------------------------
/*! \class CGSceneNode
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
CGSceneNode::CGSceneNode() :
    m_poBV(NULL)
{
    m_eNodeType = SNT_Node;
}
// ----------------------------------------------------------------------------
CGSceneNode::~CGSceneNode()
{
}
// ----------------------------------------------------------------------------
void CGSceneNode::Deref ()
{
    CGReferenceCounter::Deref();

    if ( m_uiNumRefs == 0 )
        mDel this;
}
// ----------------------------------------------------------------------------
