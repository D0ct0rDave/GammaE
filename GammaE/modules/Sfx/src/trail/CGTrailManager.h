// ----------------------------------------------------------------------------
#ifndef CGTrailManager_h
#define CGTrailManager_h 1
// ----------------------------------------------------------------------------
// CObject3D_Node
#include "GammaE_Scene.h"
#include "CGTrailInstance.h"
// ----------------------------------------------------------------------------
DECLARE_SINGLETON(CGTrailManager)
{
	friend class CGTrailManagerNode;
	
	public:

		/// Initializes the trail manager
		void Init();

		/// Retrieve a trail instance and allow the user to handle it.
		CGTrailInstance* poGet(const CGString& _sType);

		/// Returns the scene node that renders all the trail instances
		CObject3D*	poGetNode() { return(m_poSceneNode); };
							
    protected:        

		/// Performs an update step over all the active instances of the manager
		void Update(float _fDeltaT);

		//
		class CGGenInstsPair
		{
			public:
				CGTrailGenerator*			m_poTG;
				CGStArray<CGTrailInstance*>	m_oInsts;
		};

		// The list of generator / instances pairs
		CGLookupArray<CGGenInstsPair*>		m_oGIList;
		
		// The billboard renderer shared among all the generators
		CGBillboardRenderer*				m_poRenderer;

		// The scene node with the trail instances geometry
		CObject3D*							m_poSceneNode;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------

