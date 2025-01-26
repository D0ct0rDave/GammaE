// ----------------------------------------------------------------------------
/*! \class CGSCNVBoundVolBuilder
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGSCNVBoundVolBuilderH
#define CGSCNVBoundVolBuilderH
// ---------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGSceneVisitor.h"
// ---------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGSCNVBoundVolBuilder,public,CGSceneVisitor)
{
    public:

        virtual void Visit(CGSceneNode * _poNode);

        virtual void Visit(CGSceneBSPNode * _poNode);

        virtual void Visit(CGSceneCamera * _poNode);

        virtual void Visit(CGSceneCompiledLeaf * _poNode);

        virtual void Visit(CGSceneInstance * _poNode);

        virtual void Visit(CGSceneLeaf * _poNode);

        virtual void Visit(CGSceneMux * _poNode);

        virtual void Visit(CGSceneGroup * _poNode);

        virtual void Visit(CGSceneScreenRect * _poNode);

        virtual void Visit(CGSceneSwitch * _poNode);

        virtual void Visit(CGSceneTransf * _poNode);

        virtual void Visit(CGSceneAnimCfg * _poNode);

        virtual void Visit(CGSceneAnimNode * _poNode);

        virtual void Visit(CGSceneAnimMesh * _poNode);

        virtual void Visit(CGSceneAnimInstance * _poNode);

        virtual void Visit(CGSceneAnimGroup * _poNode);

        virtual void Visit(CGSceneAnimTransf * _poNode);
};
// ---------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------
