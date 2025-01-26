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

#include "CGSceneCompiledLeaf.h"
// ----------------------------------------------------------------------------
CGSceneCompiledLeaf::CGSceneCompiledLeaf() :
    m_poCMesh(NULL),
    m_poShader(NULL)
{
    m_eNodeType = SNT_CompiledLeaf;
}
// ----------------------------------------------------------------------------
CGSceneCompiledLeaf::CGSceneCompiledLeaf(CGCompiledMesh* _poCMesh, CGShader* _poShader)
{
    m_eNodeType = SNT_CompiledLeaf;
    Init(_poCMesh,_poShader);
}
// ----------------------------------------------------------------------------
