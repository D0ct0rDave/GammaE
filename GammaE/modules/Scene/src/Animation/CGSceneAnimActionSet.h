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
#ifndef CGSceneActionNodeH
#define CGSceneActionNodeH
// --------------------------------------------------------------------------------
// TFrameAnimation
// CGSceneAnimGen
#include "Animation/CGSceneAnimNode.h"
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
class CGSceneAnimActionSet : public CGSceneNode
{
    public:
        CGSceneAnimActionSet();

        virtual ~CGSceneAnimActionSet();

        // / Sets up the configuration for an specific action
        uint uiAddAction(const CGString& _sActionName,uint _uiInitialFrame, uint _uiFinalFrame, float _fTotalActionTime, bool _bLoop)
        {
            CAnimAction oAnim;

            oAnim.m_uiIniFrame = _uiInitialFrame;
            oAnim.m_uiEndFrame = _uiFinalFrame;
            oAnim.m_fFrameTime = _fTotalActionTime / (_uiFinalFrame - _uiInitialFrame + 1);
            oAnim.m_bLoop = _bLoop;

            return ( m_oActions.uiAddVar(_sActionName, oAnim ) );
        }

        // / Retrieve the current number of actions this config object stores
        uint uiNumActions() const
        {
            return ( m_oActions.uiNumElems() );
        }

        // / Retrieve the name associated to a given action
        const CGString& sGetActionName(uint _uiAction)
        {
            const CGString& s = m_oActions.sGetElemName(_uiAction);
            return(s);
        }

        // / Retrieves the parameters associated to a given action by number
        const CAnimAction& oGetAnimAction(uint _uiAction)
        {
            return (m_oActions.oGetElem(_uiAction));
        }

        // / Retrieves the parameters associated to a given action by name
        const CAnimAction& oGetAnimAction(const CGString& _sActionName)
        {
            int iActionIdx = m_oActions.iGetIdx(_sActionName);

            // This method should rreturn a pointer to object because previous action may fail. 
            assert(iActionIdx>=0 && "Unable to find action");
            if (iActionIdx >= 0)
            {
                return (oGetAnimAction(iActionIdx));
            }
        }

        // / Starts a new animation
        void SetAction(uint _uiAction);

        // / Plays / Stops the animation
        void Enable(bool _bEnable)
        {
            m_bEnabled = _bEnable;
        }

        /// Updates the current animation according the deltaT
        void UpdateAnimState(float _fDeltaT);
        
        // / Retrieves the animated object associated to this config object
        CGSceneAnimNode* poGetAnimObject()
        {
            return (m_poAnimObj);
        }

        // / Sets the animated object associated to this config object
        void SetAnimObject(CGSceneAnimNode* _poAnimObj)
        {
            m_poAnimObj = _poAnimObj;
        }

        // / Returns the node bounding volume.
        virtual CGGraphBV* poGetBV();
        
        // General Processing Functionalities
        virtual void Accept(CGSceneVisitor* _poVisitor)
        {
            _poVisitor->Visit(this);
        }

    protected:

        // Set of Actions
        CGLookupArray<CAnimAction> m_oActions;
        
        // The animation object handled
        CGSceneAnimNode* m_poAnimObj;
    
    private:
        // Current action being used
        uint m_uiAction;
        
        float m_fTime;
        bool m_bEnabled;

        int iNumFrameAnims;
        int iCurrentFrameAnim;
        int iLastFrame;

        float m_fTotalAnimTime;
        float m_fCurrentAnimTime;
};
// --------------------------------------------------------------------------------
#endif
// --------------------------------------------------------------------------------
