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
#ifndef CGSCNVRendererH
#define CGSCNVRendererH
// ---------------------------------------------------------------------
#include "CGSceneVisitor.h"
// ---------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGSCNVRenderer,public,CGSceneVisitor)
{
    public:
        void Render(CGSceneNode * _poNode);

        virtual void Visit(CGSceneNode * _poNode);

        virtual void Visit(CGSceneBSPNode * _poNode);

        virtual void Visit(CGSceneCamera * _poNode);

        virtual void Visit(CGSceneInstance * _poNode);

        virtual void Visit(CGSceneLeaf * _poNode);

        virtual void Visit(CGSceneMux * _poNode);

        virtual void Visit(CGSceneGroup * _poNode);

        virtual void Visit(CGSceneScreenRect * _poNode);

        virtual void Visit(CGSceneSwitch * _poNode);

        virtual void Visit(CGSceneTransf * _poNode);

        virtual void Visit(CGSceneAnimActionSet* _poNode);

        virtual void Visit(CGSceneAnimNode * _poNode);

        virtual void Visit(CGSceneAnimMesh * _poNode);

        virtual void Visit(CGSceneAnimGroup * _poNode);

        virtual void Visit(CGSceneAnimTransf * _poNode);

    protected:
        float m_fAnimFactor;
        uint m_uiIniFrame;
        uint m_uiEndFrame;
};
// ---------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------
