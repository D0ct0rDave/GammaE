




// CBoundingSphere
#include "BoundingVolume\CBoundingSphere.h"


// Class CBoundingSphere 




CBoundingSphere::CBoundingSphere()
        {
}


CBoundingSphere::~CBoundingSphere()
{
}



void CBoundingSphere::Init (CVect3 _Center, float _fRadius)
{
  	Center.Assign(_Center);
	Radius = _fRadius;
}

void CBoundingSphere::Init (CVect3& Max, CVect3& Min)
{
  
	// Get radius
	Center.Assign(Max);
	Center.Sub(Min);
	Radius = Center.fModule() * 0.5;

	// Get center pos
	Center.Interpolate(Max,Min,0.5f);

}

// Additional Declarations
    
