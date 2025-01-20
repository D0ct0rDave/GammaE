//## begin module%3BD7363100C9.cm preserve=no
//## end module%3BD7363100C9.cm

//## begin module%3BD7363100C9.cp preserve=no
//## end module%3BD7363100C9.cp

//## Module: CE3D_Frustum%3BD7363100C9; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Viewing\Frustum\CE3D_Frustum.cpp

//## begin module%3BD7363100C9.additionalIncludes preserve=no
//## end module%3BD7363100C9.additionalIncludes

//## begin module%3BD7363100C9.includes preserve=yes
#include <math.h>
//## end module%3BD7363100C9.includes

// CE3D_Frustum
#include "E3D\Viewing\Frustum\CE3D_Frustum.h"
//## begin module%3BD7363100C9.additionalDeclarations preserve=yes
//## end module%3BD7363100C9.additionalDeclarations


// Class CE3D_Frustum 




CE3D_Frustum::CE3D_Frustum()
  //## begin CE3D_Frustum::CE3D_Frustum%.hasinit preserve=no
  //## end CE3D_Frustum::CE3D_Frustum%.hasinit
  //## begin CE3D_Frustum::CE3D_Frustum%.initialization preserve=yes
  //## end CE3D_Frustum::CE3D_Frustum%.initialization
{
  //## begin CE3D_Frustum::CE3D_Frustum%.body preserve=yes
  //## end CE3D_Frustum::CE3D_Frustum%.body
}


CE3D_Frustum::~CE3D_Frustum()
{
  //## begin CE3D_Frustum::~CE3D_Frustum%.body preserve=yes
  //## end CE3D_Frustum::~CE3D_Frustum%.body
}



//## Other Operations (implementation)
void CE3D_Frustum::Compute (CE3D_Projector *_Projector, float _fRatio)
{
  //## begin CE3D_Frustum::Compute%1003953253.body preserve=yes
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

  //## end CE3D_Frustum::Compute%1003953253.body
}

CPlane & CE3D_Frustum::GetPlane (int iPlane)
{
  //## begin CE3D_Frustum::GetPlane%1003953255.body preserve=yes
	return Plane[iPlane];
  //## end CE3D_Frustum::GetPlane%1003953255.body
}

int CE3D_Frustum::TestBBox (CVect3& Maxs, CVect3 &Mins)
{
  //## begin CE3D_Frustum::TestBBox%1003953256.body preserve=yes
	
	// The plane normals point to outside, then, if a distance point is >0
	// the point is outside the plane (in front of the plane, 
	// in oposition to the back face of the plane)

	unsigned int	cPlane;

    for (cPlane=0;cPlane<6;cPlane++)
        if ( MATH_Utils::iTestBoxPlane(Maxs,Mins,Plane[cPlane]) == 1) 
			return(0);

    return(1);
  //## end CE3D_Frustum::TestBBox%1003953256.body
}

int CE3D_Frustum::TestSphere (float Radius, CVect3 &Center)
{
  //## begin CE3D_Frustum::TestSphere%1003953257.body preserve=yes

	// The plane normals point to outside, then, if a distance point is >0
	// the point is outside the plane (in front of the plane, 
	// in oposition to the back face of the plane)

	int cPlane;

    for (cPlane=0;cPlane<6;cPlane++)
        if ( MATH_Utils::iTestSpherePlane(Center,Radius,Plane[cPlane]) == 1) 
			return(0);

    return(1);

  //## end CE3D_Frustum::TestSphere%1003953257.body
}

int CE3D_Frustum::TestPoint (CVect3& _roPoint)
{
  //## begin CE3D_Frustum::TestPoint%1011722642.body preserve=yes

  	// The plane normals point to outside, then, if a distance point is >0
	// the point is outside the plane (in front of the plane, 
	// in oposition to the back face of the plane)

	int cPlane;

    for (cPlane=0;cPlane<6;cPlane++)
        if ( MATH_Utils::iTestPointPlane(_roPoint,Plane[cPlane]) == 1) 
			return(0);

    return(1);

  //## end CE3D_Frustum::TestPoint%1011722642.body
}

void CE3D_Frustum::Transform (CMatrix4x4 &_Transf)
{
  //## begin CE3D_Frustum::Transform%1006987065.body preserve=yes
	
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

  //## end CE3D_Frustum::Transform%1006987065.body
}

void CE3D_Frustum::Copy (CE3D_Frustum &_pFrust)
{
  //## begin CE3D_Frustum::Copy%1006987066.body preserve=yes
	Plane[0] = _pFrust.GetPlane(0);
	Plane[1] = _pFrust.GetPlane(1);
	Plane[2] = _pFrust.GetPlane(2);
	Plane[3] = _pFrust.GetPlane(3);
	Plane[4] = _pFrust.GetPlane(4);
	Plane[5] = _pFrust.GetPlane(5);
  //## end CE3D_Frustum::Copy%1006987066.body
}

// Additional Declarations
  //## begin CE3D_Frustum%3BD7363100C9.declarations preserve=yes
  //## end CE3D_Frustum%3BD7363100C9.declarations

//## begin module%3BD7363100C9.epilog preserve=yes
//## end module%3BD7363100C9.epilog
