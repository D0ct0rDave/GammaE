// -----------------------------------------------------------------------------
#include "CFollowerEnemy.h"
#include "Loop/Special/Game/Ents/CEntityMgr.h"
#include "Loop/Special/Game/GameGraphics/CEntRend.h"
// -----------------------------------------------------------------------------
CFollowerEnemy::CFollowerEnemy()
{
}
// -----------------------------------------------------------------------------
CFollowerEnemy::~CFollowerEnemy()
{
}
// -----------------------------------------------------------------------------
void CFollowerEnemy::Init(int _iSubType,char*_szFilename)
{
	// Add path
	ParsePath(_szFilename);
}
// -----------------------------------------------------------------------------
void CFollowerEnemy::ParsePath(char* _szFilename)
{
	m_oPoints.Reset();

	CINIFile oFile;
	oFile.Init(_szFilename);

	int iNumPoints = oFile.iGetInteger("General","NumEventPoints",0);	
	int i;
	for (i=0;i<iNumPoints;i++)
	{
		char szVar[MAX_CHARS];
		sprintf(szVar,"Point%d",i);
		
		MTH_CPoint3 oPt;
		float fTime = oFile.fGetFloat(szVar,"Time",0.0f);
		float fX	= oFile.fGetFloat(szVar,"X",0.0f);
		float fY	= oFile.fGetFloat(szVar,"Y",0.0f);
		
		oPt.x = fX;
		oPt.y = fY;		
		oPt.z = fTime;
	
		// Compute total path time
		m_fPathTime += fTime;

		m_oPoints.iAdd(oPt);
	}

	// Intialize curve
	m_oCurve.Init(m_oPoints.poData(),m_oPoints.iGetNbElem());

	m_eState = ENTSTATE_IDLE;
}
// -----------------------------------------------------------------------------
