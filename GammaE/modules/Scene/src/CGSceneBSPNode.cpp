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
#include "CGSceneBSPNode.h"
// ----------------------------------------------------------------------------
CGSceneBSPNode::CGSceneBSPNode() :
    m_poBackNode(NULL),
    m_poFrontNode(NULL)
{
    m_eNodeType = SNT_BSPNode;
}
// ----------------------------------------------------------------------------
CGSceneBSPNode::~CGSceneBSPNode()
{
}
// ----------------------------------------------------------------------------
