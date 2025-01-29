#ifndef CGameMap_h
#define CGameMap_h 1

#include "GammaE.h"
#include "TileMap/CTileMap.h"

#define COL_TEST_LEFT	0x01
#define COL_TEST_RIGHT	0x02
#define COL_TEST_UP		0x04
#define COL_TEST_DOWN	0x08
#define COL_TEST_ALL	0x0f

class CGameMap : public CGSceneNode
{
	public:
		CGameMap();
		virtual ~CGameMap();
		
		void Load(const CGString& _sFilename);
		void Render ();

		int iGetTile(const CGVect3& _oPos);
		bool bCollAtPos(float _fX,float _fY);
		bool bCOLSpriteMap(const CGVect3& _oPos,float _fWidth,float _fHeight,uint _uiFlags);
		float fGetGroundHeight(const CGVect3& _oPos);
		
		virtual CGGraphBV* poGetBV();

		void Accept(CGSceneVisitor* _poVisitor)
		{
			_poVisitor->Visit(this);
		}

	protected:
		CTileMap* m_poTileMap;
		CGStArray<CGGraphicResource*> m_oTile;
};

#endif
