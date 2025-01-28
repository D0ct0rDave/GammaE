
#include "GammaE.h"
#include "App/Loop/Game/CGameGlobals.h"
#include "Video/CVideo.h"
//## end module%3B65CB11028A.includes

// CGameMap
#include "CGameMap.h"

// -----------------------------------------------------------------------------
// Sprite collision utility functions
// -----------------------------------------------------------------------------
typedef struct TCOLRect{
	
	float fIX;
	float fIY;
	float fFX;
	float fFY;

}TCOLRect;

/*******************************************************
Retrieves the Collision rectangle for the specific sprite
*******************************************************/
void MAP_GetCOLRect(const CGVect3& _oPos,float _fWidth,float _fHeight,TCOLRect* _poRect)
{
	_poRect->fIX = _oPos.x - _fWidth*0.5f;
	_poRect->fIY = _oPos.y;
	_poRect->fFX = _oPos.x + _fWidth*0.5f;
	_poRect->fFY = _oPos.y + _fHeight;
}

float CGameMap::fGetGroundHeight(const CGVect3& _oPos)
{
	int i = (int)(_oPos.x);
	int j = (int)(-_oPos.y);
	
	while (( m_poTexMap->uiGetAt(i,j)  == 0) && (j < m_poTexMap->uiTY)) 
		j++;
	
	return( -1.0f * (float)j);
}
/*******************************************************
Tests if the tile below the coords is collidable
--------------------------------------------------------
Se deberia tener en cuenta si la coordenada que se nos 
supera el limite de la seccion, testear con los tiles de
la seccion anterior/posterior.
*******************************************************/
int CGameMap::iGetTile(const CGVect3& _oPos)
{
	// Convert world coords to map coords
	int i = (int)(_oPos.x / 100.0f);
	int j = (int)(-_oPos.y / 100.0f);
	
	if (i<0) return(-1);
	if (j<0) return(-1);

	return( m_poTexMap->uiGetAt(i,j) );
}

bool CGameMap::bCollAtPos(float _fX,float _fY)
{
	int iX				=  _fX / 100.0f;
	int iY				= -(_fY-200.0f) / 100.0f;

	if ((iX >= m_poTexMap->uiTX) || (iY >= m_poTexMap->uiTY))
		return(0);
	else
	{
		int iTileID	= m_poTexMap->uiGetAt(iX,iY);
		return (iTileID != 0);
	}
}

/*******************************************************
Checks wether the given sprite collides with the rest of
the map elements
--------------------------------------------------------
FIXED Tile size: 32x32 pixels
*******************************************************/
bool CGameMap::bCOLSpriteMap(const CGVect3& _oPos,float _fWidth,float _fHeight,uint _uiFlags)
{
	// Test first against the map
	TCOLRect oSrc;
	MAP_GetCOLRect(_oPos,_fWidth,_fHeight,&oSrc);

	// Test each 4 sprite corners against the map
	float fHWidth  = _fWidth * 0.5f;
	float fHHeight = _fHeight* 0.5f;

	if ((_uiFlags & COL_TEST_LEFT)	&& bCollAtPos(oSrc.fIX,oSrc.fIY)) return(true);
	if ((_uiFlags & COL_TEST_RIGHT) && bCollAtPos(oSrc.fFX,oSrc.fIY)) return(true);
	if ((_uiFlags & COL_TEST_UP)	&& bCollAtPos(oSrc.fIX,oSrc.fFY)) return(true);
	if ((_uiFlags & COL_TEST_DOWN)	&& bCollAtPos(oSrc.fFX,oSrc.fFY)) return(true);

	return(false);
}

CGameMap::CGameMap()
{
}

CGameMap::~CGameMap()
{
}

CGGraphBV *CGameMap::poGetBoundVol()
{
    return(NULL);
}

CGGraphBV *CGameMap::poCreateBoundVol()
{
	return(NULL);
}

void CGameMap::ComputeBoundVol()
{
}

static CGSceneTransf oTransf;
void CGameMap::Load(const CGString& _sFilename)
{
	// Cargar un mapa;
	CGConfigFile oFile(_sFilename);
	CGString szTexMap = oFile.sGetString("General.MapFile","none.ms");

	// Load the map
	CGString sDir		 = Utils::ExtractFileDir(_sFilename);
	CGString sTexMapPath = sDir + CGString("/") + szTexMap;

	m_poTexMap = mNew CTMSector_8_16;
	m_poTexMap->iLoad( (char*)sTexMapPath.szString() );

/*
	FILE* fd = fopen((char*)sTexMapPath.szString(),"rb");
if (fd)
	{
		m_poTexMap->LoadWithHandler(fd);
		m_poTexMap->LoadWithHandler(fd);
		fclose(fd);
	}
*/	

	uint uiNumTiles = oFile.iGetInteger("General.NumTiles",0);
	uiNumTiles = 256;
	m_oTile.Init(uiNumTiles);

	for (uint i=0;i<uiNumTiles;i++)
	{
		CGString oStr;
		oStr = CGString("General.Tile") + CGString(i);

		CGString sTileFilename = oFile.sGetString(oStr,"NULL_TILE");
		CGGraphicResource* poTile = CGGraphicResourceWH::I()->poLoad(sTileFilename);
		if ((poTile != NULL) && (poTile->poGetModel()!= NULL))
			poTile->poGetModel()->Ref();

		m_oTile.iAdd(poTile);
	}
}

inline int iClamp(int a,int b,int value)
{
		if (value<a)
			return(a);
	else if (value>b)
			return(b);
	else
		return(value);
}

const int HMARGIN = 8;
const int VMARGIN = 7;

void CGameMap::Render ()
{
	int iX = gameGlobals.m_oPerspCam.Pos.x;
	int iY = gameGlobals.m_oPerspCam.Pos.y;

	int iIX = iClamp(0,m_poTexMap->uiTX-1,iX-HMARGIN);
	int iIY = iClamp(0,m_poTexMap->uiTY-1,iY-VMARGIN);
	int iFX = iClamp(0,m_poTexMap->uiTX-1,iX+HMARGIN);
	int iFY = iClamp(0,m_poTexMap->uiTY-1,iY+VMARGIN);
	if ((iFX - iIX) < HMARGIN*2)
	{
		iFX += (HMARGIN*2 - (iFX - iIX))-1;
	}

	if ((iFY- iIY) < VMARGIN*2)
	{
		iFY += (VMARGIN*2 - (iFY - iIY))-1;
	}

	for (uint j=iIY;j<iFY;j++)
		for (uint i=iIX;i<iFX;i++)
		{
			uint uiIdx = m_poTexMap->uiGetAt(i,j); 
			CGGraphicResource* poTile = m_oTile[uiIdx];

			if (poTile != NULL)
			{
				CGVect3 oPos(i,-1.0f*j,0.0f);
				CGMatrix4x4 oMat;
				oMat.LoadIdentity();								
				oMat.Translate(oPos);
				oMat.Scale(0.01f,0.01f,0.01f);
				
				oTransf.SetObject( poTile->poGetModel() );
				oTransf.SetTransf(oMat);

				CGSCNVRenderer::I()->Render(&oTransf);
			}
		}
}
