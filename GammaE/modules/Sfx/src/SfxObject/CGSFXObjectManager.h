// ----------------------------------------------------------------------------
#ifndef CGSFXObjectManagerH
#define CGSFXObjectManagerH
// ----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "GammaE_Scene.h"
#include "Billboard/CGBillboardRenderer.h"
// ----------------------------------------------------------------------------
// SFX Object Instance Manager. Provides functionality to 
// enable / disable / get / release / auto management with energy (lifetime) 
// sfx object instances
// ----------------------------------------------------------------------------
class CSFXObjectInstance
{
};
// ----------------------------------------------------------------------------
#define DECLARE_SFXOBJECTMANAGER(CLASSNAME,INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS)\
class CLASSNAME : public CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,CLASSNAME>

template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
class CGSFXObjectManager : public CGSingleton<BASECLASS>
{
	friend class CGSingleton<BASECLASS>;

	private:

		// Special node which renders all the sfx object instances in the system
		class CSFXObjectManagerNode : public CObject3D_Node
		{
			public:
				CSFXObjectManagerNode(CGSFXObjectManager* _poSFXObjectManager)
				{
					m_poSFXObjectManager = _poSFXObjectManager;
				}

			protected:
				virtual void Render()
				{
					// Update the Manager
					m_poSFXObjectManager->Update( CGRenderer::I()->REStats.DTime );

					// Render all the objects of the manager
					if (m_poSFXObjectManager->m_poRenderer)
						m_poSFXObjectManager->m_poRenderer->Render();
				}
			
				CGSFXObjectManager*		m_poSFXObjectManager;
		};

	public:

		CGSFXObjectManager()
		{
			m_poRenderingNode = mNew CSFXObjectManagerNode(this);
			Init();
		}

	public:

		/// Specialized nitialization Procedure
		virtual void Init();

		/// Creates a pool of instances for a given type of sfx object
		virtual uint uiCreatePool(const CGString& _sType,uint _uiMaxInstances);

		/// Retrieve sfx object instance and allow the user to handle it.
		handler hGet(const CGString& _sType);

		/// Retrieve sfx object instance and allow the user to handle it.
		handler hGet(uint _uiType);

		/// Self handled sfx object
		handler hGet(const CGString& _sType,float _fEnergy,const CVect3& _oPos);

		/// Self handled sfx object
		handler hGet(uint _uiType,float _fEnergy,const CVect3& _oPos);

		/// Retrieves the scene node for a specific sfx object
		CObject3D* poGetInstanceNode(handler _hSfxObj);

		/// Releases the sfx object instance
		void Release(handler _hSfxObj);

		/// Retrieves whether the given sfx object is enabled or not
		bool bEnabled(handler _hSfxObj);

		/// Enables or disables the instance
		void Enable(handler _hSfxObj,bool _bEnable);

		/// Sets the position of a given sfx objecft
		void SetPos(handler _hSfxObj,const CVect3& _oNewPos);

		/// Sets the direction of a given sfx object
		void SetDir(handler _hSfxObj,const CVect3& _oNewDir);

		/// Retrieves the scene node of the SFX Object Manager
		CObject3D*	poGetManagerNode() { return(m_poRenderingNode); };

		/// Specialized Updatinf process for the registered instances
		virtual void Update(float _fDeltaT);

	protected:
			
			// --------------------------------------------------------------------			
			typedef struct TSFXObject
			{
				/// The manager handles this instance or not
				bool m_bAutoManaged;

				/// The subobject index in the node of the auto managed PSIs
				uint m_uiNodeIdx;

				/// The switch node for this SFX Object Instance
				CObject3D_Switch*	m_poSwitch;

				/// The SFX Object Instance itself
				INSTANCECLASS* m_poInstance;

				/// The current energy of this instance
				float m_fEnergy;

				/// The type of the instance
				uint m_uiType;

			}TSFXInstanceData;

			typedef struct TSFXInstancePool
			{
				CGCircularArray<TSFXInstanceData>	m_oInsts;
				GENERATORCLASS*						m_poGen;

			}TSFXInstancePool;
			// --------------------------------------------------------------------

	protected:

		/// Lookup table for types of pools of PSIs
		CGLookupArray<TSFXInstancePool*>	m_oPool;

		/// The scene node of the SFX Object Manager
		CObject3D*							m_poRenderingNode;

		/// The object which renders all the automanaged enabled instances
		CObject3D*							m_poRenderer;
};
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
uint CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::uiCreatePool(const CGString& _sType,uint _uiMaxInstances)
{
	void* poCG = GENWAREHOUSECLASS::I()->poFind(_sType);
	if (poCG == NULL) return(-1);

	TSFXInstancePool* poCIs = mNew TSFXInstancePool;
	poCIs->m_poGen = (GENERATORCLASS*)poCG;
	poCIs->m_poGen->SetBillboardRenderer((CGBillboardRenderer*)m_poRenderer);

	// Add this instance pool to the pool table
	uint uiType = m_oPool.uiAddVar(_sType,poCIs);

	// Create instances for this specific sfx object type
	poCIs->m_oInsts.Init( _uiMaxInstances );

	for (uint i=0;i<_uiMaxInstances;i++)
	{
		TSFXInstanceData* poCI = poCIs->m_oInsts.poGet();
		poCI->m_poInstance	= mNew INSTANCECLASS((GENERATORCLASS*)poCG);
		poCI->m_poSwitch	= mNew CObject3D_Switch;
		poCI->m_uiType		= uiType;

		poCI->m_poSwitch->SetObject( poCI->m_poInstance );
	}
	
	// Set them ready to be used
	poCIs->m_oInsts.FreeAll();
	
	// Return the index into the lookup array
	return( uiType );
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
void CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::Init()
{
	m_poRenderer = mNew CGBillboardRenderer(128,1000);
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
handler CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::hGet(const CGString& _sType)
{
	int iIdx = m_oPool.iGetIdx(_sType);
	if (iIdx == -1) return(NULL);

	return( hGet(iIdx) );
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
handler CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::hGet(uint _uiType)
{
	TSFXInstanceData* poInst = m_oPool.oGetElem(_uiType)->m_oInsts.poGet();

	if (poInst == NULL)
		return(NULL);
	else
	{
		poInst->m_poInstance->Reinit();
		poInst->m_bAutoManaged = false;
		return( poInst );
	}
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
handler CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::hGet(const CGString& _sType,float _fEnergy,const CVect3& _oPos)
{
	int iIdx = m_oPool.iGetIdx(_sType);
	if (iIdx == -1) return(NULL);

	return( hGet(iIdx,_fEnergy,_oPos) );
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
handler CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::hGet(uint _uiType,float _fEnergy,const CVect3& _oPos)
{
	TSFXInstanceData* poInst = m_oPool.oGetElem(_uiType)->m_oInsts.poGet();

	if (poInst == NULL)
		return(NULL);
	else
	{
		poInst->m_bAutoManaged = true;
		poInst->m_fEnergy      = _fEnergy;
		poInst->m_poInstance->SetPos(_oPos);
		poInst->m_poInstance->Reinit();
	
		return( (handler)poInst );
	}
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
void CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::Release(handler _hSfxObj)
{
	TSFXInstanceData* poInst = (TSFXInstanceData*)_hSfxObj;
	m_oPool[ poInst->m_uiType ]->m_oInsts.Release( poInst );
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
CObject3D* CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::poGetInstanceNode(handler _hSfxObj)
{
	TSFXInstanceData* poInst = (TSFXInstanceData*)_hSfxObj;
	return ( poInst->m_poSwitch );
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
bool CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::bEnabled(handler _hSfxObj)
{
	TSFXInstanceData* poInst = (TSFXInstanceData*)_hSfxObj;
	return( poInst->m_poSwitch->bEnabled());
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
void CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::Enable(handler _hSfxObj,bool _bEnable)
{
	TSFXInstanceData* poInst = (TSFXInstanceData*)_hSfxObj;
	poInst->m_poSwitch->Enable(_bEnable);
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
void CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::SetPos(handler _hSfxObj,const CVect3& _oNewPos)
{
	TSFXInstanceData* poInst = (TSFXInstanceData*)_hSfxObj;
	poInst->m_poInstance->SetPos(_oNewPos);
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
void CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::SetDir(handler _hSfxObj,const CVect3& _oNewDir)
{
	TSFXInstanceData* poInst = (TSFXInstanceData*)_hSfxObj;
	poInst->m_poInstance->SetDir(_oNewDir);
}
// ----------------------------------------------------------------------------
template <typename INSTANCECLASS, typename GENERATORCLASS,typename GENWAREHOUSECLASS, typename BASECLASS>
void CGSFXObjectManager<INSTANCECLASS,GENERATORCLASS,GENWAREHOUSECLASS,BASECLASS>::Update(float _fDeltaT)
{
	CGBillboardRenderer* poRenderer = (CGBillboardRenderer*)m_poRenderer;
	
	// Updates ALL the instances of the manager both automanaged and user managed
	poRenderer->Reset();

	for (uint j=0;j<m_oPool.uiNumElems();j++)
	{
		TSFXInstancePool* poPool = m_oPool[j];
		poRenderer->Begin( poPool->m_poGen->poGetShader() );

			for (uint i=0;i<poPool->m_oInsts.uiMaxElems();i++)
			{
				TSFXInstanceData* poID = poPool->m_oInsts.poElem(i);

				if (poID)
				{
					if ( poID->m_bAutoManaged )
					{
						if (poID->m_fEnergy <= 0.0f)
							Release( poID );
						else
							poID->m_fEnergy -= _fDeltaT;
					}

					poID->m_poSwitch->Render();
				}
			}

		poRenderer->End();
	}
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
