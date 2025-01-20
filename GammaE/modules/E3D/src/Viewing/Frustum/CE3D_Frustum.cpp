



#include <math.h>

// CE3D_Frustum
#include "Viewing\Frustum\CE3D_Frustum.h"


// Class CE3D_Frustum 





void CE3D_Frustum::Compute (CE3D_Projector *_Projector, float _fRatio)
{
  	#define		FOVM	0.5f

  	CVect3	Origin,Normal;
	
    float	CosVFov = cosf(_Projector->fFOV*FOVM*_PI_OVER_180_);
	float	SinVFov = sinf(_Projector->fFOV*FOVM*_PI_OVER_180_);
	
	// OpenGL blue book -> XFov is YFov * AspectRatio -> see gluPerspective
	float	CosHFov = cosf(_fRatio*_Projector->fFOV*FOVM*_PI_OVER_180_);
	float	SinHFov = sinf(_fRatio*_Projector->fFOV*FOVM*_PI_OVER_180_);

    /*
    			+z
    			 |
    			 |
                 |
                 |
    +x  ---------+------------ x-
                /|\
             --/-+-\-- Near plane
              /  |  \
 Left Plane  /   |   \  Right Plane
            /    |    \
    	   /	 |     \
        --/------+------\-- Far plane
          		 |
                 |
                -z
    */

    // Near plane
    Origin.V3(0,0,-_Projector->fNear);
    Normal.V3(0,0, 1);
    Plane[0].GeneratePlaneFromFields(Origin,Normal);

    // Far plane
    Origin.V3(0,0,-_Projector->fFar);
    Normal.V3(0,0,-1);
    Plane[1].GeneratePlaneFromFields(Origin,Normal);

    Origin.V3(0,0,0);

    // Right plane
    Normal.V3( CosHFov,0,SinHFov);	
	Plane[2].GeneratePlaneFromFields(Origin,Normal);

    // Left plane
    Normal.V3(-CosHFov,0,SinHFov);
    Plane[3].GeneratePlaneFromFields(Origin,Normal);

    // Upper plane
    Normal.V3(0, CosVFov,SinVFov);
    Plane[4].GeneratePlaneFromFields(Origin,Normal);

    // Lower plane
	Normal.V3(0, -CosVFov,SinVFov);
	Plane[5].GeneratePlaneFromFields(Origin,Normal);

}

CPlane & CE3D_Frustum::GetPlane (int iPlane)
{
  	return Plane[iPlane];
}

int CE3D_Frustum::TestBBox (CVect3& Maxs, CVect3 &Mins)
{
  	
	// The plane normals point to outside, then, if a distance point is >0
	// the point is outside the plane (in front of the plane, 
	// in oposition to the back face of the plane)

	unsigned int	cPlane;

	// WARNING: In release near plane doens't work properly
    for (cPlane=0;cPlane<6;cPlane++)
        if ( MATH_Utils::iTestBoxPlane(Maxs,Mins,Plane[cPlane]) == 1) 
			return(0);

    return(1);
}

int CE3D_Frustum::TestSphere (float Radius, CVect3 &Center)
{
  
	// The plane normals point to outside, then, if a distance point is >0
	// the point is outside the plane (in front of the plane, 
	// in oposition to the back face of the plane)

	int cPlane;

	// WARNING: In release near plane doens't work properly
    for (cPlane=0;cPlane<6;cPlane++)
        if ( MATH_Utils::iTestSpherePlane(Center,Radius,Plane[cPlane]) == 1) 
			return(0);

    return(1);

}

int CE3D_Frustum::TestPoint (CVect3& _oPoint)
{
  
  	// The plane normals point to outside, then, if a distance point is >0
	// the point is outside the plane (in front of the plane, 
	// in oposition to the back face of the plane)

	int cPlane;

	// WARNING: In release near plane doens't work properly
    for (cPlane=0;cPlane<6;cPlane++)
        if ( MATH_Utils::iTestPointPlane(_oPoint,Plane[cPlane]) == 1) 
			return(0);

    return(1);

}

void CE3D_Frustum::Transform (CMatrix4x4 &_Transf)
{
  	
	// Near Plane
	Plane[0].Transform(_Transf);
	// Far Plane
	Plane[1].Transform(_Transf);
	// Right Plane
	Plane[2].Transform(_Transf);
	// Left Plane
	Plane[3].Transform(_Transf);
	// Top Plane
	Plane[4].Transform(_Transf);
	// Bottom Plane
	Plane[5].Transform(_Transf);

}

void CE3D_Frustum::Copy (CE3D_Frustum &_pFrust)
{
  	Plane[0] = _pFrust.GetPlane(0);
	Plane[1] = _pFrust.GetPlane(1);
	Plane[2] = _pFrust.GetPlane(2);
	Plane[3] = _pFrust.GetPlane(3);
	Plane[4] = _pFrust.GetPlane(4);
	Plane[5] = _pFrust.GetPlane(5);
}

// Additional Declarations
    
