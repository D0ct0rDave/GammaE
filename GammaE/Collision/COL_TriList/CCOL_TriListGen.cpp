//## begin module%3C1BEC41027D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1BEC41027D.cm

//## begin module%3C1BEC41027D.cp preserve=no
//## end module%3C1BEC41027D.cp

//## Module: CCOL_TriListGen%3C1BEC41027D; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_TriListGen.cpp

//## begin module%3C1BEC41027D.additionalIncludes preserve=no
//## end module%3C1BEC41027D.additionalIncludes

//## begin module%3C1BEC41027D.includes preserve=yes
//## end module%3C1BEC41027D.includes

// CCOL_TriListGen
#include "Collision\COL_TriList\CCOL_TriListGen.h"
//## begin module%3C1BEC41027D.additionalDeclarations preserve=yes
//## end module%3C1BEC41027D.additionalDeclarations


// Class CCOL_TriListGen 

//## begin CCOL_TriListGen::poMeshes%3C1BED81016E.attr preserve=no  protected: static CMesh* * {UA} NULL
CMesh* *CCOL_TriListGen::poMeshes = NULL;
//## end CCOL_TriListGen::poMeshes%3C1BED81016E.attr

//## begin CCOL_TriListGen::piMats%3CCD03E702FB.attr preserve=no  protected: static int * {UA} NULL
int *CCOL_TriListGen::piMats = NULL;
//## end CCOL_TriListGen::piMats%3CCD03E702FB.attr

//## begin CCOL_TriListGen::iNumMeshes%3C1BED8D03D9.attr preserve=no  protected: static int {UA} 0
int CCOL_TriListGen::iNumMeshes = 0;
//## end CCOL_TriListGen::iNumMeshes%3C1BED8D03D9.attr


CCOL_TriListGen::CCOL_TriListGen()
  //## begin CCOL_TriListGen::CCOL_TriListGen%.hasinit preserve=no
  //## end CCOL_TriListGen::CCOL_TriListGen%.hasinit
  //## begin CCOL_TriListGen::CCOL_TriListGen%.initialization preserve=yes
  //## end CCOL_TriListGen::CCOL_TriListGen%.initialization
{
  //## begin CCOL_TriListGen::CCOL_TriListGen%.body preserve=yes
  //## end CCOL_TriListGen::CCOL_TriListGen%.body
}


CCOL_TriListGen::~CCOL_TriListGen()
{
  //## begin CCOL_TriListGen::~CCOL_TriListGen%.body preserve=yes
  //## end CCOL_TriListGen::~CCOL_TriListGen%.body
}



//## Other Operations (implementation)
int CCOL_TriListGen::GetTriList (CCOL_TriList& _roTriList, CVect3& _roPos, float _fRadius)
{
  //## begin CCOL_TriListGen::GetTriList%1008463028.body preserve=yes
	return(0);
  //## end CCOL_TriListGen::GetTriList%1008463028.body
}

void CCOL_TriListGen::SetMeshes (CMesh** _poMeshes, int* _piMats, int _iNumMeshes)
{
  //## begin CCOL_TriListGen::SetMeshes%1008463029.body preserve=yes
	poMeshes	= _poMeshes;
	piMats		= _piMats;
	iNumMeshes	= _iNumMeshes;	
  //## end CCOL_TriListGen::SetMeshes%1008463029.body
}

int CCOL_TriListGen::GetTrisFromMesh (CCOL_TriList& _roTriList, CMesh* _poMesh, int _iMat, CVect3& _roPos, float _fRadius)
{
  //## begin CCOL_TriListGen::GetTrisFromMesh%1008711902.body preserve=yes
	return(0);
  //## end CCOL_TriListGen::GetTrisFromMesh%1008711902.body
}

// Additional Declarations
  //## begin CCOL_TriListGen%3C1BEC41027D.declarations preserve=yes
  //## end CCOL_TriListGen%3C1BEC41027D.declarations

//## begin module%3C1BEC41027D.epilog preserve=yes
//## end module%3C1BEC41027D.epilog
