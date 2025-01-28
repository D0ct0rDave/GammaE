// -----------------------------------------------------------------------------
#include "CFollowerEntity.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"
// -----------------------------------------------------------------------------
CFollowerEntity::CFollowerEntity()
{
}
// -----------------------------------------------------------------------------
CFollowerEntity::~CFollowerEntity()
{
}
// -----------------------------------------------------------------------------
void CFollowerEntity::Init(char* _szFilename)
{
	// Add path
	ParsePath(_szFilename);
}
// -----------------------------------------------------------------------------
void CFollowerEntity::ParsePath(char* _szFilename)
{
	m_oPoints.Reset();

	CINIFile oFile;
	oFile.Init(_szFilename);

	int iNumPoints = oFile.iGetInteger("General","NumEventPoints",0);	
	int i;
	MTH_CPoint3 oPt;

	for (i=0;i<iNumPoints;i++)
	{
		char szVar[MAX_CHARS];
		sprintf(szVar,"Point%d",i);

		float fTime = oFile.fGetFloat(szVar,"Time",0.0f);
		float fX	= oFile.fGetFloat(szVar,"X",0.0f);
		float fY	= oFile.fGetFloat(szVar,"Y",0.0f);

		oPt.x = fX;
		oPt.y = fY;		
		oPt.z = fTime;

		m_oPoints.iAdd(oPt);
	}

	// Path time is the time of the last entry
	m_fPathTime = oPt.z;

	// Intialize curve
	m_oCurve.Init(m_oPoints.poData(),m_oPoints.iGetNbElem());
}
// -----------------------------------------------------------------------------