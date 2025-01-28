//-----------------------------------------------------------------------------
#ifndef CGModelWHH
#define CGModelWHH
//-----------------------------------------------------------------------------
#include "GammaE.h"
//-----------------------------------------------------------------------------
DECLARE_SINGLETON(CGModelWH)
{
	public:
		CGSceneNode* poGetInstance(const CGString& _sModelName);
		
		CGSceneNode* poGetModel(const CGString& _sModelName);
        CGSceneNode* poInstantiate(CGSceneNode* _poObj);

	protected:
		
		CGSceneAnimNode* poInstantiate(CGSceneAnimNode* _poObj);
		CGSceneAnimMesh* poInstantiate(CGSceneAnimMesh* _poObj);
		CGSceneAnimTransf* poInstantiate(CGSceneAnimTransf* _poObj);
		CGSceneAnimCfg* poInstantiate(CGSceneAnimCfg* _poObj);
		CGSceneAnimCfgMgr* poInstantiate(CGSceneAnimCfgMgr* _poObj);
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------