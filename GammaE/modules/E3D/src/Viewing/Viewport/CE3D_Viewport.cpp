




// CE3D_Viewport
#include "Viewing\Viewport\CE3D_Viewport.h"


// Class CE3D_Viewport 






CE3D_Viewport::CE3D_Viewport()
        : ScrCX(0), ScrCY(0), ScrTX(0), ScrTY(0)
      {
}


CE3D_Viewport::~CE3D_Viewport()
{
}



void CE3D_Viewport::SetViewport (float cX, float cY, float TX, float TY)
{
  	ScrCX	= cX;
	ScrCY	= cY;
	ScrTX	= TX;
	ScrTY	= TY;
}

// Additional Declarations
    
