//## begin module%3C2BCE35036E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BCE35036E.cm

//## begin module%3C2BCE35036E.cp preserve=no
//## end module%3C2BCE35036E.cp

//## Module: SCNUt_TriSceneAccumulator%3C2BCE35036E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_TriSceneAccumulator.cpp

//## begin module%3C2BCE35036E.additionalIncludes preserve=no
//## end module%3C2BCE35036E.additionalIncludes

//## begin module%3C2BCE35036E.includes preserve=yes
//## end module%3C2BCE35036E.includes

// SCNUt_TriSceneAccumulator
#include "Scene\SceneUtils\SCNUt_TriSceneAccumulator.h"
//## begin module%3C2BCE35036E.additionalDeclarations preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3C2BCE35036E.additionalDeclarations


// Class SCNUt_TriSceneAccumulator 



SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator()
  //## begin SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator%.hasinit preserve=no
      : iMaxTris(0), iRealloc(100)
  //## end SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator%.hasinit
  //## begin SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator%.initialization preserve=yes
  //## end SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator%.initialization
{
  //## begin SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator%.body preserve=yes
  //## end SCNUt_TriSceneAccumulator::SCNUt_TriSceneAccumulator%.body
}


SCNUt_TriSceneAccumulator::~SCNUt_TriSceneAccumulator()
{
  //## begin SCNUt_TriSceneAccumulator::~SCNUt_TriSceneAccumulator%.body preserve=yes
  //## end SCNUt_TriSceneAccumulator::~SCNUt_TriSceneAccumulator%.body
}



//## Other Operations (implementation)
void SCNUt_TriSceneAccumulator::AddTriScene (SCNUt_TriScene* _poScn)
{
  //## begin SCNUt_TriSceneAccumulator::AddTriScene%1009496919.body preserve=yes
	if (NumTris + _poScn->NumTris > iMaxTris)
	{
		SCNUt_Triangle *pTris;

		// Allocate space for old + new triangles
		iMaxTris = NumTris + _poScn->NumTris + iRealloc;
		pTris = mNew SCNUt_Triangle[NumTris + _poScn->NumTris + iRealloc];		
		
		// Copy old data
		memcpy(pTris,Tris,NumTris*sizeof(SCNUt_Triangle));

		// Copy new data
		memcpy(pTris+NumTris,_poScn->Tris,_poScn->NumTris*sizeof(SCNUt_Triangle));
		
		// delete old data
		mDel []Tris;

		// Update object
		NumTris += _poScn->NumTris;
		Tris     = pTris;
	}
	else
	{	
		memcpy(Tris+NumTris,_poScn->Tris,_poScn->NumTris*sizeof(SCNUt_Triangle));
		NumTris += _poScn->NumTris;
	}
  //## end SCNUt_TriSceneAccumulator::AddTriScene%1009496919.body
}

void SCNUt_TriSceneAccumulator::Init (int _iNumTris)
{
  //## begin SCNUt_TriSceneAccumulator::Init%1012510459.body preserve=yes
	Init(_iNumTris,iRealloc);
  //## end SCNUt_TriSceneAccumulator::Init%1012510459.body
}

void SCNUt_TriSceneAccumulator::Init (int _iNumTris, int _iRealloc)
{
  //## begin SCNUt_TriSceneAccumulator::Init%1012510460.body preserve=yes
	iRealloc = _iRealloc;
	SCNUt_TriScene::Init(_iNumTris);
	iMaxTris = _iNumTris;
  //## end SCNUt_TriSceneAccumulator::Init%1012510460.body
}

// Additional Declarations
  //## begin SCNUt_TriSceneAccumulator%3C2BCE35036E.declarations preserve=yes
  //## end SCNUt_TriSceneAccumulator%3C2BCE35036E.declarations

//## begin module%3C2BCE35036E.epilog preserve=yes
//## end module%3C2BCE35036E.epilog
