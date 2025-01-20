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

	// Graphic instance
	m_poGI	= pNew CGraphicInstance("Enemy");
	m_poGI->Scale(0.25f);

	// Hide entity
	HideDisable();
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
void CFollowerEnemy::Think(float _fDeltaT)
{
	switch (m_eState)
	{
		case ENTSTATE_IDLE:
		{
			// Add this entity to the render list
			m_iRI = CEntRend::iAdd(this);

			//
			ShowEnable();

			// Awake entities
			m_eState = ENTSTATE_ALIVE;
		}
		break;

		case ENTSTATE_ALIVE:
		{
			float fFact = m_fTime / m_fPathTime;
			MTH_CPoint3 oPos = m_oCurve.oGetPos(fFact);
			oPos.z = 0.0f;

			Pos( oPos );

			if (m_fTime > m_fPathTime)
				HideDisable();
		}
	}
}
// -----------------------------------------------------------------------------
