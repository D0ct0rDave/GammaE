#ifndef CGMArcadeH
#define CGMArcadeH

#include "GammaE.h"
#include "CGameMode.h"
#include "CGMAEnemySpawner.h"          

#include "Menu/CMenuTextGrid.h"
#include "Game/Scene/HUDElems/CHUDIcon.h"
#include "Game/Scene/HUDElems/CHUDLabel.h"

class CGMArcade : public CGameMode
{
	public:	 CGMArcade();
			~CGMArcade();
			virtual void Init();
			virtual void Loop();

	protected:
			void UpdateMiniMap();
			void UpdateMiniMapCell(int _iCellX,int _iCellY,TFColor _oColor);

			void UpdateEnergyBars();

			void UpdateScore();

			void SetOption(int _iOpt,bool _bDisabled,bool _bSelected);
			void UpdateWeaponSelector();
			void UpdateSelectedWeapons();

			void UpdateHUD();

	protected:
			// HUD Stuff
			
			bool			*pbVisitedSecs;
		
			CObject3D_Leaf	*poMiniMap;
			CMesh			*poMiniMapMesh;
			CE3D_Shader		*poMiniMapSh;

			CObject3D_Leaf	*poEnergyBar;
			CMesh			*poEnergyBarMesh;
			CE3D_Shader		*poEnergyBarSh;

			CHUDIcon		*poEBFrame;
			CHUDLabel		*poScore;

			CMesh			*poWSMesh;


			CE3D_Shader		*poWeapIcon[9];			// Weapon icon shaders
			CHUDIcon		*poPWIcon;				// Primary weapon icon
			CHUDIcon		*poSWIcon;				// Secondary weapon icon			
			CHUDLabel		*poPWLabel;
			CHUDLabel		*poSWLabel;

			CGMAEnemySpawner oSpawner;
};

#endif