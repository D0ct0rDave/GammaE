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
#include "Animation\CGSceneAnimObject.h"
// --------------------------------------------------------------------------------
CGSceneAnimNode::CGSceneAnimNode() :
    m_uiNumKeyFrames(0),
    m_eTypeID(OBJ3D_AnimObject)
{
}
// --------------------------------------------------------------------------------
void CGSceneAnimNode::Init(uint _uiNumKeyFrames)
{
    m_uiNumKeyFrames = _uiNumKeyFrames;

    // OPTIMIZE (SIZE): Memory sucker!
    m_poFrameBVol.Init(m_uiNumKeyFrames);

    for ( uint i = 0; i < m_uiNumKeyFrames; i++ )
        m_poFrameBVol.iAdd( CGraphBV_Manager::poCreate() );
}
// --------------------------------------------------------------------------------
