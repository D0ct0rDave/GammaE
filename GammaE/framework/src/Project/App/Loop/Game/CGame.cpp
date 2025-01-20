// ----------------------------------------------------------------------------
#include "CGame.h"
#include "GameScene/CGameScene.h"
#include "GameMode/CGMProto.h"
// ----------------------------------------------------------------------------
void CGame::Init(uint _uiGMode,uint _uiLevel,uint _uiSkill)
{
	CGGameBase::Init(_uiGMode,_uiLevel,_uiSkill);


	switch (m_uiGMode)
	{
		default:
		{
			// Create prototype game
			m_poGM = mNew CGMProto;
			m_poGM->Init(_uiLevel,_uiSkill);
		}
	}
}
// ----------------------------------------------------------------------------
void CGame::Render()
{
	CGameScene::Render();

	/*
	if (m_poGM)
		m_poGM->Render();
	*/
}
// ----------------------------------------------------------------------------