//-----------------------------------------------------------------------------
#ifndef CEnemyGroupExtH
#define CEnemyGroupExtH
//-----------------------------------------------------------------------------
#include "GammaE.h"
#include "CEnemyGroup.h"
//-----------------------------------------------------------------------------
class CEnemyGroupExt : public CEnemyGroup
{
	public:
		PUBLISH_GAMEENTITY_CLASSNAME;

		CEnemyGroupExt();

		/// Initializes the enemy group
		virtual void Init(unsigned int _uiNumElems,float _fSpawnTime,float _fEnergy,const CVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,const CGString& _sPath,float _fScale,uint _uiIniColor,uint _uiEndColor);
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------