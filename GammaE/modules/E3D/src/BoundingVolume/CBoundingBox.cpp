




// CBoundingBox
#include "BoundingVolume\CBoundingBox.h"


// Class CBoundingBox 





CBoundingBox::CBoundingBox()
        {
}


CBoundingBox::~CBoundingBox()
{
}



void CBoundingBox::Init (CVect3& Max, CVect3& Min)
{
    	Mins.Assign(Min);
    Maxs.Assign(Max);

    // Look up table
    Points[0].V3( Maxs.x,Maxs.y,Maxs.z );		// 000
    Points[1].V3( Maxs.x,Maxs.y,Mins.z );		// 001
    Points[2].V3( Maxs.x,Mins.y,Maxs.z );		// 010
    Points[3].V3( Maxs.x,Mins.y,Mins.z );		// 011
    Points[4].V3( Mins.x,Maxs.y,Maxs.z );		// 100
    Points[5].V3( Mins.x,Maxs.y,Mins.z );		// 101
    Points[6].V3( Mins.x,Mins.y,Maxs.z );		// 110
    Points[7].V3( Mins.x,Mins.y,Mins.z );		// 111
}

// Additional Declarations
    
