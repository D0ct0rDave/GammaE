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
    m_poBV = CGGraphBVFactory::poCreate();
}
// ----------------------------------------------------------------------------
CGSceneBSPNode::~CGSceneBSPNode()
{
}
// ----------------------------------------------------------------------------
void CGSceneBSPNode::SetBV(CGGraphBV* _poBV)
{
    if (m_poBV)
        mDel m_poBV;

    m_poBV = _poBV;
}
// ----------------------------------------------------------------------------
CGGraphBV* CGSceneBSPNode::poGetBV()
{
    return m_poBV;
}
// ----------------------------------------------------------------------------