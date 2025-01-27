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
#ifndef CGSceneAnimInstanceH
#define CGSceneAnimInstanceH
// --------------------------------------------------------------------------------
#include "CGSceneNode.h"
#include "CGSceneAnimCfg.h"
// --------------------------------------------------------------------------------
class CGSceneAnimInstance : public CGSceneNode
{
    public:

        CGSceneAnimInstance();
        ~CGSceneAnimInstance();

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

        // / Starts a new animation
        void SetAnim(uint _uiAnim);

        // / Plays / Stops the animation
        void Enable(bool _bEnable)
        {
            m_bEnabled = _bEnable;
        }

        // /
        void SetAnimatedObject(CGSceneAnimNode* _poObj)
        {
            m_poObj = _poObj;
        }

        CGSceneAnimNode* poGetAnimatedObject()
        {
            return (m_poObj);
        }

        // /
        void SetAnimConfig(CGSceneAnimCfg* _poCfg)
        {
            m_poCfg = _poCfg;
        }

        CGSceneAnimCfg* poGetAnimConfig()
        {
            return (m_poCfg);
        }

        void UpdateAnimState();

    protected:

        // The config used by object to be rendered
        CGSceneAnimNode* m_poObj;

        // The object to be rendered
        CGSceneAnimCfg* m_poCfg;

        // Current action being used
        uint m_uiAnim;
        float m_fTime;
        bool m_bEnabled;

        int iNumFrameAnims;
        int iCurrentFrameAnim;
        int iLastFrame;
        
        CAnimAction m_oAnimAction;
        float m_fTotalAnimTime;

        float m_fCurrentAnimTime;
        
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
