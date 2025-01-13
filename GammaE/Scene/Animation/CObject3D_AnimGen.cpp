//## begin module%3B9DFF3A0340.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9DFF3A0340.cm

//## begin module%3B9DFF3A0340.cp preserve=no
//## end module%3B9DFF3A0340.cp

//## Module: CObject3D_AnimGen%3B9DFF3A0340; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimGen.cpp

//## begin module%3B9DFF3A0340.additionalIncludes preserve=no
//## end module%3B9DFF3A0340.additionalIncludes

//## begin module%3B9DFF3A0340.includes preserve=yes
//## end module%3B9DFF3A0340.includes

// CObject3D_AnimGen
#include "Scene\Animation\CObject3D_AnimGen.h"
//## begin module%3B9DFF3A0340.additionalDeclarations preserve=yes
//## end module%3B9DFF3A0340.additionalDeclarations


// Class CObject3D_AnimGen 




CObject3D_AnimGen::CObject3D_AnimGen()
  //## begin CObject3D_AnimGen::CObject3D_AnimGen%.hasinit preserve=no
      : iNumStates(0), iLastFrame(-1)
  //## end CObject3D_AnimGen::CObject3D_AnimGen%.hasinit
  //## begin CObject3D_AnimGen::CObject3D_AnimGen%.initialization preserve=yes
  //## end CObject3D_AnimGen::CObject3D_AnimGen%.initialization
{
  //## begin CObject3D_AnimGen::CObject3D_AnimGen%.body preserve=yes
	  TypeID = e3DObj_AnimGen;
  //## end CObject3D_AnimGen::CObject3D_AnimGen%.body
}


CObject3D_AnimGen::~CObject3D_AnimGen()
{
  //## begin CObject3D_AnimGen::~CObject3D_AnimGen%.body preserve=yes
  //## end CObject3D_AnimGen::~CObject3D_AnimGen%.body
}


// Additional Declarations
  //## begin CObject3D_AnimGen%3B9DFF3A0340.declarations preserve=yes
  //## end CObject3D_AnimGen%3B9DFF3A0340.declarations

//## begin module%3B9DFF3A0340.epilog preserve=yes
//## end module%3B9DFF3A0340.epilog
