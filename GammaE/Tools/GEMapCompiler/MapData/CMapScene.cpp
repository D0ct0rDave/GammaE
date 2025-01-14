//## begin module%3C7423860247.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7423860247.cm

//## begin module%3C7423860247.cp preserve=no
//## end module%3C7423860247.cp

//## Module: CMapScene%3C7423860247; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\CMapScene.cpp

//## begin module%3C7423860247.additionalIncludes preserve=no
//## end module%3C7423860247.additionalIncludes

//## begin module%3C7423860247.includes preserve=yes
#include "memory/gammae_mem.h"
#include <string.h>
//## end module%3C7423860247.includes

// CMapScene
#include "Tools\GEMapCompiler\MapData\CMapScene.h"
//## begin module%3C7423860247.additionalDeclarations preserve=yes
//## end module%3C7423860247.additionalDeclarations


// Class CMapScene 








CMapScene::CMapScene()
  //## begin CMapScene::CMapScene%.hasinit preserve=no
      : iNumBrushes(0), iNumEntities(0)
  //## end CMapScene::CMapScene%.hasinit
  //## begin CMapScene::CMapScene%.initialization preserve=yes
  //## end CMapScene::CMapScene%.initialization
{
  //## begin CMapScene::CMapScene%.body preserve=yes
	poEntity = NULL;
	poBrush  = NULL;
  //## end CMapScene::CMapScene%.body
}


CMapScene::~CMapScene()
{
  //## begin CMapScene::~CMapScene%.body preserve=yes
	if (poEntity) mDel []poEntity;
	if (poBrush)  mDel []poBrush;
  //## end CMapScene::~CMapScene%.body
}



//## Other Operations (implementation)
void CMapScene::AddEntity (CMapEntity* _poMapEntity)
{
  //## begin CMapScene::AddEntity%1014246304.body preserve=yes
  	CMapEntity* *poNewEnts;

	// Allocate space for old + new instructions
	poNewEnts = mNew CMapEntity *[iNumEntities+1];		

	// Copy old data
	if (poEntity) 
		memcpy(poNewEnts,poEntity,iNumEntities*sizeof(CMapEntity *));

	// Add new instruction
	poNewEnts[iNumEntities] = _poMapEntity;
	
	// delete old data
	if (poEntity) mDel []poEntity;

	// Update object		
	poEntity = poNewEnts;

	iNumEntities++;
  //## end CMapScene::AddEntity%1014246304.body
}

void CMapScene::AddBrush (CMapBrush *_poBrush)
{
  //## begin CMapScene::AddBrush%1014246305.body preserve=yes
  	CMapBrush* *poNewBrush;

	// Allocate space for old + new instructions
	poNewBrush = mNew CMapBrush *[iNumBrushes+1];		

	// Copy old data
	if (poBrush) 
		memcpy(poNewBrush,poBrush,iNumBrushes*sizeof(CMapBrush *));

	// Add new instruction
	poNewBrush[iNumBrushes] = _poBrush;
	
	// delete old data
	if (poBrush) mDel []poBrush;

	// Update object		
	poBrush = poNewBrush;

	iNumBrushes++;
  //## end CMapScene::AddBrush%1014246305.body
}

// Additional Declarations
  //## begin CMapScene%3C7423860247.declarations preserve=yes
  //## end CMapScene%3C7423860247.declarations

//## begin module%3C7423860247.epilog preserve=yes
//## end module%3C7423860247.epilog
