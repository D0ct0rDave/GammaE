//## begin module%3AC229AA038E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC229AA038E.cm

//## begin module%3AC229AA038E.cp preserve=no
//## end module%3AC229AA038E.cp

//## Module: SCNUt_TriScene%3AC229AA038E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_TriScene.cpp

//## begin module%3AC229AA038E.additionalIncludes preserve=no
//## end module%3AC229AA038E.additionalIncludes

//## begin module%3AC229AA038E.includes preserve=yes
//## end module%3AC229AA038E.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3AC229AA038E.additionalDeclarations preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3AC229AA038E.additionalDeclarations


// Class SCNUt_TriScene 



SCNUt_TriScene::SCNUt_TriScene()
  //## begin SCNUt_TriScene::SCNUt_TriScene%.hasinit preserve=no
      : Tris(0), NumTris(0)
  //## end SCNUt_TriScene::SCNUt_TriScene%.hasinit
  //## begin SCNUt_TriScene::SCNUt_TriScene%.initialization preserve=yes
  //## end SCNUt_TriScene::SCNUt_TriScene%.initialization
{
  //## begin SCNUt_TriScene::SCNUt_TriScene%.body preserve=yes
  //## end SCNUt_TriScene::SCNUt_TriScene%.body
}


SCNUt_TriScene::~SCNUt_TriScene()
{
  //## begin SCNUt_TriScene::~SCNUt_TriScene%.body preserve=yes
	mDel []Tris;
  //## end SCNUt_TriScene::~SCNUt_TriScene%.body
}


const SCNUt_TriScene & SCNUt_TriScene::operator=(const SCNUt_TriScene &right)
{
  //## begin SCNUt_TriScene::operator=%.body preserve=yes

	Init(right.NumTris);
	memcpy(Tris,right.Tris,NumTris*sizeof(SCNUt_Triangle));
	
	return(*this);
  //## end SCNUt_TriScene::operator=%.body
}



//## Other Operations (implementation)
void SCNUt_TriScene::Init (int _iNumTris)
{
  //## begin SCNUt_TriScene::Init%985803487.body preserve=yes
	if (! _iNumTris) return;
	if (Tris) mDel[]Tris;

	NumTris = _iNumTris;
	Tris    = mNew SCNUt_Triangle[NumTris];
  //## end SCNUt_TriScene::Init%985803487.body
}

// Additional Declarations
  //## begin SCNUt_TriScene%3AC229AA038E.declarations preserve=yes
  //## end SCNUt_TriScene%3AC229AA038E.declarations

//## begin module%3AC229AA038E.epilog preserve=yes
//## end module%3AC229AA038E.epilog
