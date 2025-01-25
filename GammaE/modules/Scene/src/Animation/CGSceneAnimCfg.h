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
#ifndef CGSceneAnimCfgH
#define CGSceneAnimCfgH
// --------------------------------------------------------------------------------
// TFrameAnimation
// CGSceneAnimGen
#include "Animation/CGSceneAnimObject.h"
// --------------------------------------------------------------------------------
class CAnimAction
{
    public:

        uint m_uiIniFrame;
        uint m_uiEndFrame;
        float m_fFrameTime;
        bool m_bLoop;
};
// --------------------------------------------------------------------------------
class CGSceneAnimCfg
{
    public:
        CGSceneAnimCfg();

        virtual ~CGSceneAnimCfg();

        // / Sets up the configuration for an specific action
        uint uiAddAction(const CGString& _sActionName,uint _uiInitialFrame, uint _uiFinalFrame, float _fFrameAnimTime, bool _bLoop)
        {
            CAnimAction oAnim;                    // = mNew CAnimAction;

            oAnim.m_uiIniFrame = _uiInitialFrame;
            oAnim.m_uiEndFrame = _uiFinalFrame;
            oAnim.m_fFrameTime = _fFrameAnimTime;
            oAnim.m_bLoop = _bLoop;

            return ( m_oActions.uiAddVar(_sActionName, oAnim ) );
        }

        // / Retrieve the current number of actions this config object stores
        uint uiNumActions()
        {
            return ( m_oActions.uiNumElems() );
        }

        // / Retrieves the animated object associated to this config object
        CGSceneAnimObject* poGetAnimObj()
        {
            return (m_poAnimObj);
        }

        // / Sets the animated object associated to this config object
        void SetAnimObj (CGSceneAnimObject* _poAnimObj)
        {
            m_poAnimObj = _poAnimObj;
        }

        // / Retrieves the parameters associated to a given action by number
        CAnimAction& oGetFrameAnim(uint _uiAction)
        {
            return ( m_oActions.oGetElem(_uiAction) );
        }

        // / Retrieves the parameters associated to a given action by name
        CAnimAction& oGetFrameAnim(const CGString& _sActionName)
        {
            int iActionIdx = m_oActions.iGetIdx(_sActionName);

            if ( iActionIdx >= 0 )
                return ( oGetFrameAnim(iActionIdx) );
        }

        // / Retrieve the name associated to a given action
        const CGString& sGetActionName(uint _uiAction)
        {
            return( m_oActions.sGetElemName(_uiAction) );
        }

        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        CGLookupArray <CAnimAction> m_oActions;
        CGSceneAnimObject* m_poAnimObj;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
