//## begin module%3A9AD44A035C.cm preserve=no
//## end module%3A9AD44A035C.cm

//## begin module%3A9AD44A035C.cp preserve=no
//## end module%3A9AD44A035C.cp

//## Module: CE3D_Viewport%3A9AD44A035C; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Viewing\Viewport\CE3D_Viewport.cpp

//## begin module%3A9AD44A035C.additionalIncludes preserve=no
//## end module%3A9AD44A035C.additionalIncludes

//## begin module%3A9AD44A035C.includes preserve=yes
//## end module%3A9AD44A035C.includes

// CE3D_Viewport
#include "E3D\Viewing\Viewport\CE3D_Viewport.h"
//## begin module%3A9AD44A035C.additionalDeclarations preserve=yes
//## end module%3A9AD44A035C.additionalDeclarations


// Class CE3D_Viewport 






CE3D_Viewport::CE3D_Viewport()
  //## begin CE3D_Viewport::CE3D_Viewport%.hasinit preserve=no
      : ScrCX(0), ScrCY(0), ScrTX(0), ScrTY(0)
  //## end CE3D_Viewport::CE3D_Viewport%.hasinit
  //## begin CE3D_Viewport::CE3D_Viewport%.initialization preserve=yes
  //## end CE3D_Viewport::CE3D_Viewport%.initialization
{
  //## begin CE3D_Viewport::CE3D_Viewport%.body preserve=yes
  //## end CE3D_Viewport::CE3D_Viewport%.body
}


CE3D_Viewport::~CE3D_Viewport()
{
  //## begin CE3D_Viewport::~CE3D_Viewport%.body preserve=yes
  //## end CE3D_Viewport::~CE3D_Viewport%.body
}



//## Other Operations (implementation)
void CE3D_Viewport::SetViewport (float cX, float cY, float TX, float TY)
{
  //## begin CE3D_Viewport::SetViewport%983219137.body preserve=yes
	ScrCX	= cX;
	ScrCY	= cY;
	ScrTX	= TX;
	ScrTY	= TY;
  //## end CE3D_Viewport::SetViewport%983219137.body
}

// Additional Declarations
  //## begin CE3D_Viewport%3A9AD44A035C.declarations preserve=yes
  //## end CE3D_Viewport%3A9AD44A035C.declarations

//## begin module%3A9AD44A035C.epilog preserve=yes
//## end module%3A9AD44A035C.epilog
