//## begin module%3B6F1B0E0226.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B6F1B0E0226.cm

//## begin module%3B6F1B0E0226.cp preserve=no
//## end module%3B6F1B0E0226.cp

//## Module: CCOL_Stack%3B6F1B0E0226; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\Collider\CCOL_Stack.cpp

//## begin module%3B6F1B0E0226.additionalIncludes preserve=no
//## end module%3B6F1B0E0226.additionalIncludes

//## begin module%3B6F1B0E0226.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3B6F1B0E0226.includes

// CCOL_Stack
#include "Collision\Collider\CCOL_Stack.h"
//## begin module%3B6F1B0E0226.additionalDeclarations preserve=yes
//## end module%3B6F1B0E0226.additionalDeclarations


// Class CCOL_Stack 





CCOL_Stack::CCOL_Stack()
  //## begin CCOL_Stack::CCOL_Stack%.hasinit preserve=no
      : iNumCollisions(0), iMaxCollisions(0), Collided(NULL)
  //## end CCOL_Stack::CCOL_Stack%.hasinit
  //## begin CCOL_Stack::CCOL_Stack%.initialization preserve=yes
  //## end CCOL_Stack::CCOL_Stack%.initialization
{
  //## begin CCOL_Stack::CCOL_Stack%.body preserve=yes
  //## end CCOL_Stack::CCOL_Stack%.body
}


CCOL_Stack::~CCOL_Stack()
{
  //## begin CCOL_Stack::~CCOL_Stack%.body preserve=yes
	if (Collided) 	
		mDel []Collided;
  //## end CCOL_Stack::~CCOL_Stack%.body
}



//## Other Operations (implementation)
void CCOL_Stack::Init (int _iMaxColisions)
{
  //## begin CCOL_Stack::Init%999639509.body preserve=yes
	iMaxCollisions = _iMaxColisions;
	iNumCollisions = 0;
	Collided       = mNew CCOL_StackCollisionElem[_iMaxColisions];
  //## end CCOL_Stack::Init%999639509.body
}

void CCOL_Stack::Reset ()
{
  //## begin CCOL_Stack::Reset%999639510.body preserve=yes
	iNumCollisions = 0;
  //## end CCOL_Stack::Reset%999639510.body
}

void CCOL_Stack::AddCollision (void *_poCObj, float _fFrameFact)
{
  //## begin CCOL_Stack::AddCollision%999639511.body preserve=yes
	if (iNumCollisions==iMaxCollisions) return;

	Collided[iNumCollisions].poCObj     = _poCObj;
	Collided[iNumCollisions].fFrameFact = _fFrameFact;	

	iNumCollisions++;
  //## end CCOL_Stack::AddCollision%999639511.body
}

// Additional Declarations
  //## begin CCOL_Stack%3B6F1B0E0226.declarations preserve=yes
  //## end CCOL_Stack%3B6F1B0E0226.declarations

//## begin module%3B6F1B0E0226.epilog preserve=yes
//## end module%3B6F1B0E0226.epilog
