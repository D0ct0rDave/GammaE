//## begin module%3CDE422E0353.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDE422E0353.cm

//## begin module%3CDE422E0353.cp preserve=no
//## end module%3CDE422E0353.cp

//## Module: CRTME_Trigger%3CDE422E0353; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Trigger.cpp

//## begin module%3CDE422E0353.additionalIncludes preserve=no
//## end module%3CDE422E0353.additionalIncludes

//## begin module%3CDE422E0353.includes preserve=yes
#include "Game/Entities/CGPEntityType.h"
//## end module%3CDE422E0353.includes

// CRTME_Trigger
#include "Game\Entities\RTMapEntities\CRTME_Trigger.h"
//## begin module%3CDE422E0353.additionalDeclarations preserve=yes
#include "Game/Globals/Globals.h"
//## end module%3CDE422E0353.additionalDeclarations


// Class CRTME_Trigger 






CRTME_Trigger::CRTME_Trigger()
  //## begin CRTME_Trigger::CRTME_Trigger%.hasinit preserve=no
      : poTrigInfo(NULL)
  //## end CRTME_Trigger::CRTME_Trigger%.hasinit
  //## begin CRTME_Trigger::CRTME_Trigger%.initialization preserve=yes
  //## end CRTME_Trigger::CRTME_Trigger%.initialization
{
  //## begin CRTME_Trigger::CRTME_Trigger%.body preserve=yes
	oColObj.Init(0,NULL,NULL,eCOL_CT_Static,eCOL_TT_BV,eCOL_TT_BV,NULL,0,5);	
  //## end CRTME_Trigger::CRTME_Trigger%.body
}


CRTME_Trigger::~CRTME_Trigger()
{
  //## begin CRTME_Trigger::~CRTME_Trigger%.body preserve=yes
  //## end CRTME_Trigger::~CRTME_Trigger%.body
}



//## Other Operations (implementation)
void CRTME_Trigger::Think (float _fDelta)
{
  //## begin CRTME_Trigger::Think%1021199188.body preserve=yes
	if (! bTriggered()) return;


	CObject3D_Node	oNode;
	oNode.poGetBoundVol()->Init(poTrigInfo->oMax,poTrigInfo->oMin);

	oColObj.GrObj = &oNode;
	if (gCollisionSystem.bCheckCollision(oColObj,gDeltaT))
	{
		int iCol;
		for (iCol=0;iCol<oColObj.ColStack.GetNumCollisions();iCol++)
		{
			if ( ((CCOL_Collider*)oColObj.GetColStack().Collided[iCol].poCObj)->UserID == CGPET_Player)
			{
				if (Target)
				{
					Target->Think(_fDelta);
					if (SecTarget)
						SecTarget->Think(_fDelta);
				}
			}
		}
	}
  //## end CRTME_Trigger::Think%1021199188.body
}

void CRTME_Trigger::Init (CMapEnt_Trigger* _poTrigInfo)
{
  //## begin CRTME_Trigger::Init%1021237871.body preserve=yes
	poTargetInfo = _poTrigInfo;
	poTrigInfo   = _poTrigInfo;
  //## end CRTME_Trigger::Init%1021237871.body
}

// Additional Declarations
  //## begin CRTME_Trigger%3CDE422E0353.declarations preserve=yes
  //## end CRTME_Trigger%3CDE422E0353.declarations

//## begin module%3CDE422E0353.epilog preserve=yes
//## end module%3CDE422E0353.epilog
