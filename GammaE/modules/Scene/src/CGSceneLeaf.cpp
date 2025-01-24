// ----------------------------------------------------------------------------
/*! \class CGSceneLeaf
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "CGSceneLeaf.h"
// ----------------------------------------------------------------------------
CGSceneLeaf::CGSceneLeaf() :
    m_poMesh(NULL),
    m_poShader(NULL)
{
    m_eNodeType = SNT_Leaf;
}
// ----------------------------------------------------------------------------
CGSceneLeaf::~CGSceneLeaf()
{
    Clear();
}
// ----------------------------------------------------------------------------
void CGSceneLeaf::Clear ()
{
    mDel m_poMesh;
    m_poMesh = NULL;
}
// ----------------------------------------------------------------------------
