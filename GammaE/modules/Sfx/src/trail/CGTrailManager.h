// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#ifndef CGTrailManager_h
#define CGTrailManager_h 1
// ----------------------------------------------------------------------------
// CGSceneNode
#include "GammaE_Scene.h"
#include "CGTrailInstance.h"
// ----------------------------------------------------------------------------
DECLARE_SINGLETON(CGTrailManager)
{
    friend class CGTrailManagerNode;

    public:

        // / Initializes the trail manager
        void Init();

        // / Retrieve a trail instance and allow the user to handle it.
        CGTrailInstance* poGet(const CGString& _sType);

        // / Returns the scene node that renders all the trail instances
        CGSceneNode* poGetNode()
        {
            return(m_poSceneNode);
        }

    protected:

        // / Performs an update step over all the active instances of the manager
        void Update(float _fDeltaT);

        //
        class CGGenInstsPair
        {
            public:
                CGTrailGenerator* m_poTG;
                CGStArray <CGTrailInstance*> m_oInsts;
        };

        // The list of generator / instances pairs
        CGLookupArray <CGGenInstsPair*> m_oGIList;

        // The billboard renderer shared among all the generators
        CGBillboardRenderer* m_poRenderer;

        // The scene node with the trail instances geometry
        CGSceneNode* m_poSceneNode;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
