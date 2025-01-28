//-----------------------------------------------------------------------------
#include "CEnemyGroupExt.h"
#include "CEnemy.h"
#include "Collision/CGColliderResource.h"
//-----------------------------------------------------------------------------
CEnemyGroupExt::CEnemyGroupExt()
{
}
//-----------------------------------------------------------------------------
void CEnemyGroupExt::Init(unsigned int _uiNumElems,float _fSpawnTime,float _fEnergy,const CGVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,const CGString& _sPath,float _fScale,uint _uiIniColor,uint _uiEndColor)
{
	// Set the spanw time
	m_fSpawnTime = _fSpawnTime;

	CGPathResource* poPathRes = NULL;
	if (_sPath != "") poPathRes = CGPathResourceWH::I()->poFind(_sPath);
	if (poPathRes) m_poPath = poPathRes->poGetPath();

	CGColor oIniColor(_uiIniColor);
	CGColor oEndColor(_uiEndColor);

	// Create the group
	for (uint i=0;i<_uiNumElems;i++)
	{
		CEnemy* poEnt	= mNew CEnemy;

		float fScale = 1.0f + (Math::fSRand() * _fScale);
		
		// Initialize the entity		
		poEnt->Init(_fEnergy,_oPos,_sAIScript,_sGraphicRes,m_poPath,fScale);
		
		// Set entity color
		CGColor oColor;
		oColor.Lerp(oIniColor,oEndColor,Math::fRand());
		poEnt->SetColor(oColor);

		// Add the entity to the group
		m_oEntLst.uiAdd( poEnt );
	}

	// Add entity to the entity manager
	m_uiGID = CGGameEntityMgr::I()->uiRegister(this);

	// 
	Reset();
}
//-----------------------------------------------------------------------------
