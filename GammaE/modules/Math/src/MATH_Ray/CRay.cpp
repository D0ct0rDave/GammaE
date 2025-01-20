




// CRay
#include "MATH_Ray\CRay.h"
#include "MATH_Matrix\CMatrix4x4.h"


// Class CRay 




CVect3 CRay::ProjectPoint (CVect3& _Point)
{
  	CVect3 PO;
	PO.Assign(_Point);	PO.Sub(Origin);
	float fSqDirMod = Dir.fSqModule();
	float fT = PO.fDotProd(Dir)/fSqDirMod;	// this is the magnitude of the XO vector divided
											// by |Dir| :  PO.Dir 
											//            --------
											//           |Dir||Dir|
	
	CVect3 XO;
	XO.Assign(Dir);	XO.Scale(fT);			// The direction vector normalized and multiplied by the
											// magnitude! Dir * PO.Dir            PO.Dir
											//			  ---  ------   => fT = ----------
											//           |Dir| |Dir|			|Dir||Dir|
	XO.Add(Origin);
	return(XO);
}

float CRay::GetDistanceToPoint (CVect3& _Point)
{
  	return ( MATH_Common::fSqrt(GetSqDistanceToPoint(_Point)) );
}

float CRay::GetSqDistanceToPoint (CVect3& _Point)
{
  	CVect3 PX = GetPerpendicular(_Point);
    
	// Squared distance: No sqrt in this implementation	
	return (PX.fSqModule());
}

CVect3 CRay::GetPerpendicular (CVect3& _Point)
{
  
	// ---------------
	//  Concepts comming from Michael Abrash: 
	//			PO.Dir = cos (PO^Dir)*|PO||Dir|
	//			distance from origin to point projected (X) from _Point to Ray 
	//			line = cos (PO^Dir) * |PO| = PO.Dir / |Dir|
    //
	//  Magic Software Inc:
	//  We can think that the distance from the point to the line is the magnitude
	//  of the vector comming from Origin to Point minus the vector comming from
	//  Origin to Projected point (X):
	//	PO - XO = PX
	// 
	//            /P     \
	//          /  |      |
	//        /    |	  > This module is the distance from the point to the line
	//      /      |      |
	//    O________X___  /
	//
	// ---------------

	CVect3 PO;
	PO.Assign(_Point);	PO.Sub(Origin);
	float fT = PO.fDotProd(Dir)/Dir.fSqModule();// this is the magnitude of the XO vector divided
											// by |Dir| :  PO.Dir 
											//            --------
											//           |Dir||Dir|
	
	CVect3 XO;
	XO.Assign(Dir);	XO.Scale(fT);			// The direction vector normalized and multiplied by the
											// magnitude! Dir * PO.Dir            PO.Dir
											//			  ---  ------   => fT = ----------
											//           |Dir| |Dir|			|Dir||Dir|
	PO.Sub(XO);

	return(PO);
}

// Additional Declarations
    
