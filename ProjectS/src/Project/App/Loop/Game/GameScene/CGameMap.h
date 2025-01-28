#ifndef CGameMap_h
#define CGameMap_h 1

#include "GammaE.h"
#include "TexMap/TexMap.h"

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

		virtual CGraphBV *poGetBoundVol();
		virtual CGraphBV *poCreateBoundVol();
		virtual void ComputeBoundVol();
		int iGetTile(const CVect3& _oPos);
		bool bCollAtPos(float _fX,float _fY);
		bool bCOLSpriteMap(const CVect3& _oPos,float _fWidth,float _fHeight,uint _uiFlags);
		float fGetGroundHeight(const CVect3& _oPos);
  protected:

	TTexMap* m_poTexMap;
		CGStArray<CGGraphicResource*> m_oTile;
};

#endif
