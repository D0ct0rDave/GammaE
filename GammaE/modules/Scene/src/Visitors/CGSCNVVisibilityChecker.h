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
#ifndef CGSCNVVisibilityCheckerH
#define CGSCNVVisibilityCheckerH
// ---------------------------------------------------------------------
#include "CGSceneVisitor.h"
#include "CGSceneNode.h"
// ---------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGSCNVVisibilityChecker,public,CGSceneVisitor)
{
    public:

        // / Primary accessor function
        bool bIsVisible(CGSceneNode* _poNode)
        {
            _poNode->Accept(this);
            return (m_bVisible);
        }

        // / Visit functions
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

        virtual void Visit(CGSceneAnimCfgGen * _poNode);

        virtual void Visit(CGSceneAnimCfgMgr * _poNode);

        virtual void Visit(CGSceneAnimNode * _poNode);

        virtual void Visit(CGSceneAnimMesh * _poNode);

        virtual void Visit(CGSceneAnimInstance * _poNode);

        virtual void Visit(CGSceneAnimGroup * _poNode);

        virtual void Visit(CGSceneAnimTransf * _poNode);

    protected:

        bool m_bVisible;
};
// ---------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------
