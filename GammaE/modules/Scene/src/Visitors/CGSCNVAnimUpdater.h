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
#ifndef CGSCNVAnimUpdaterH
#define CGSCNVAnimUpdaterH
// ---------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGSceneVisitor.h"
// ---------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGSCNVAnimUpdater,public,CGSceneVisitor)
{
    public:
        void SetAnimState(CGSceneAnimInstance * _poInst,uint _uiIFrame,uint _uiEFrame,float _fFact);

        virtual void Visit(CGSceneAnimNode * _poNode);

        virtual void Visit(CGSceneAnimMesh * _poNode);

        virtual void Visit(CGSceneAnimGroup * _poNode);

        virtual void Visit(CGSceneAnimTransf * _poNode);

    protected:

        uint m_uiIFrame;
        uint m_uiEFrame;
        float m_fFact;
};
// ---------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------
