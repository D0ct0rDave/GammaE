// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "Ray\CGRay.h"
#include "Matrix\CGMatrix4x4.h"
// ----------------------------------------------------------------------------
CGVect3 CGRay::ProjectPoint (CGVect3& _Point)
{
    CGVect3 PO;
    PO.Assign(_Point);
    PO.Sub(Origin);
    float fSqDirMod = Dir.fSqModule();
    float fT = PO.fDotProd(Dir) / fSqDirMod;  // this is the magnitude of the XO vector divided
                                              // by |Dir| :  PO.Dir
                                              // --------
                                              // |Dir||Dir|

    CGVect3 XO;
    XO.Assign(Dir);
    XO.Scale(fT);                           // The direction vector normalized and multiplied by the
                                            // magnitude! Dir * PO.Dir            PO.Dir
                                            // ---  ------   => fT = ----------
                                            // |Dir| |Dir|			|Dir||Dir|
    XO.Add(Origin);
    return(XO);
}
// ----------------------------------------------------------------------------
float CGRay::GetDistanceToPoint (CGVect3& _Point)
{
    return ( Math::fSqrt( GetSqDistanceToPoint(_Point) ) );
}
// ----------------------------------------------------------------------------
float CGRay::GetSqDistanceToPoint (CGVect3& _Point)
{
    CGVect3 PX = GetPerpendicular(_Point);

    // Squared distance: No sqrt in this implementation
    return ( PX.fSqModule() );
}
// ----------------------------------------------------------------------------
CGVect3 CGRay::GetPerpendicular (CGVect3& _Point)
{
    // ---------------
    // Concepts comming from Michael Abrash:
    // PO.Dir = cos (PO^Dir)*|PO||Dir|
    // distance from origin to point projected (X) from _Point to Ray
    // line = cos (PO^Dir) * |PO| = PO.Dir / |Dir|
    //
    // Magic Software Inc:
    // We can think that the distance from the point to the line is the magnitude
    // of the vector comming from Origin to Point minus the vector comming from
    // Origin to Projected point (X):
    // PO - XO = PX
    //
    // /P     \
    //	
	//          /  |      |
    // /    |	  > This module is the distance from the point to the line
    // /      |      |
    // O________X___  /
    //
    // ---------------

    CGVect3 PO;
    PO.Assign(_Point);
    PO.Sub(Origin);
    float fT = PO.fDotProd(Dir) / Dir.fSqModule(); // this is the magnitude of the XO vector divided
    // by |Dir| :  PO.Dir
    // --------
    // |Dir||Dir|

    CGVect3 XO;
    XO.Assign(Dir);
    XO.Scale(fT);                           // The direction vector normalized and multiplied by the
                                            // magnitude! Dir * PO.Dir            PO.Dir
                                            // ---  ------   => fT = ----------
                                            // |Dir| |Dir|			|Dir||Dir|
    PO.Sub(XO);

    return(PO);
}
// ----------------------------------------------------------------------------
