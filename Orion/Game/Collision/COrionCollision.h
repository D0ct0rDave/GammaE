
#ifndef COrionCollisionH
#define COrionCollisionH

#include "GammaE.h"
#include "Game/Entities/COrionEnt.h"
#include "Game/Entities/Player/CPlayer.h"

class COrionCOL 
{
	public:
		 COrionCOL();
		~COrionCOL();

		static void HandleCollisions();
		
	private:
		static bool bTestObjTRN_Broad(COrionEnt *_poCol);
		static bool bTestObjTRN_Fine (COrionEnt *_poCol);
	
		static bool bTestObjST_Broad (COrionEnt *_poCol);
		static bool bTestObjST_Fine  (COrionEnt *_poCol);

		static bool bTestObjObj_Broad(COrionEnt *_poCol,COrionEnt *_poDst);
		static bool bTestObjObj_Fine (COrionEnt *_poCol,COrionEnt *_poDst);
		static bool bTestObj2Entities(COrionEnt *_poCol);	
		
		static bool bTestCollision(COrionEnt *_poCol);
		static void HandlePlayerCollisions(CPlayer *_poPlayer);		

	private:
		static CCOL_TriList				oColTriList;
		static CCOL_MT_CommonMesh		oStMeshTest;
};

#endif