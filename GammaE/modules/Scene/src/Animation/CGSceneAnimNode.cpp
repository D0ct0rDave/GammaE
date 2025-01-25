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
#include "Animation\CGSceneAnimNode.h"

CGSceneAnimNode::CGSceneAnimNode()
{
    m_eTypeID = OBJ3D_AnimTransf;
}

CGSceneAnimNode::~CGSceneAnimNode()
{
}

void CGSceneAnimNode::ComputeBoundVols()
{
    for ( uint i = 0; i < m_poObjs.uiNumElems(); i++ )
    {
        m_poObjs[i]->ComputeBoundVols();
    }
}
