//## begin module%3B7FCEBC0085.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FCEBC0085.cm

//## begin module%3B7FCEBC0085.cp preserve=no
//## end module%3B7FCEBC0085.cp

//## Module: CRay%3B7FCEBC0085; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Ray\CRay.cpp

//## begin module%3B7FCEBC0085.additionalIncludes preserve=no
//## end module%3B7FCEBC0085.additionalIncludes

//## begin module%3B7FCEBC0085.includes preserve=yes
//## end module%3B7FCEBC0085.includes

// CRay
#include "Math\MATH_Ray\CRay.h"
//## begin module%3B7FCEBC0085.additionalDeclarations preserve=yes
//## end module%3B7FCEBC0085.additionalDeclarations


// Class CRay 



CRay::CRay()
  //## begin CRay::CRay%.hasinit preserve=no
  //## end CRay::CRay%.hasinit
  //## begin CRay::CRay%.initialization preserve=yes
  //## end CRay::CRay%.initialization
{
  //## begin CRay::CRay%.body preserve=yes
  //## end CRay::CRay%.body
}



//## Other Operations (implementation)
CVect3 CRay::ProjectPoint (CVect3& _Point)
{
  //## begin CRay::ProjectPoint%1007685159.body preserve=yes
	CVect3 PO;
	PO.Assign(_Point);	PO.Sub(Origin);
	float fSqDirMod = Dir.SqModule();
	float fT = PO.DotProd(Dir)/fSqDirMod;	// this is the magnitude of the XO vector divided
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
  //## end CRay::ProjectPoint%1007685159.body
}

float CRay::GetDistanceToPoint (CVect3& _Point)
{
  //## begin CRay::GetDistanceToPoint%1007685160.body preserve=yes
	return ( MATH_Common::fSqrt(GetSqDistanceToPoint(_Point)) );
  //## end CRay::GetDistanceToPoint%1007685160.body
}

float CRay::GetSqDistanceToPoint (CVect3& _Point)
{
  //## begin CRay::GetSqDistanceToPoint%1008804496.body preserve=yes
	CVect3 PX = GetPerpendicular(_Point);
    
	// Squared distance: No sqrt in this implementation	
	return (PX.SqModule());
  //## end CRay::GetSqDistanceToPoint%1008804496.body
}

CVect3 CRay::GetPerpendicular (CVect3& _Point)
{
  //## begin CRay::GetPerpendicular%1008804497.body preserve=yes

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
	float fT = PO.DotProd(Dir)/Dir.SqModule();// this is the magnitude of the XO vector divided
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
  //## end CRay::GetPerpendicular%1008804497.body
}

// Additional Declarations
  //## begin CRay%3B7FCEBC0085.declarations preserve=yes
  //## end CRay%3B7FCEBC0085.declarations

//## begin module%3B7FCEBC0085.epilog preserve=yes
//## end module%3B7FCEBC0085.epilog
