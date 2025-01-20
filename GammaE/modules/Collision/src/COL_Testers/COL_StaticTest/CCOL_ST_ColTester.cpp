//## begin module%3B7AF1BC01C2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7AF1BC01C2.cm

//## begin module%3B7AF1BC01C2.cp preserve=no
//## end module%3B7AF1BC01C2.cp

//## Module: CCOL_ST_ColTester%3B7AF1BC01C2; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_StaticTest\CCOL_ST_ColTester.cpp

//## begin module%3B7AF1BC01C2.additionalIncludes preserve=no
//## end module%3B7AF1BC01C2.additionalIncludes

//## begin module%3B7AF1BC01C2.includes preserve=yes
//## end module%3B7AF1BC01C2.includes

// CCOL_ST_ColTester
#include "Collision\COL_Testers\COL_StaticTest\CCOL_ST_ColTester.h"
//## begin module%3B7AF1BC01C2.additionalDeclarations preserve=yes
//## end module%3B7AF1BC01C2.additionalDeclarations


// Class CCOL_ST_ColTester 

CCOL_ST_ColTester::CCOL_ST_ColTester()
  //## begin CCOL_ST_ColTester::CCOL_ST_ColTester%.hasinit preserve=no
  //## end CCOL_ST_ColTester::CCOL_ST_ColTester%.hasinit
  //## begin CCOL_ST_ColTester::CCOL_ST_ColTester%.initialization preserve=yes
  //## end CCOL_ST_ColTester::CCOL_ST_ColTester%.initialization
{
  //## begin CCOL_ST_ColTester::CCOL_ST_ColTester%.body preserve=yes
  //## end CCOL_ST_ColTester::CCOL_ST_ColTester%.body
}


CCOL_ST_ColTester::~CCOL_ST_ColTester()
{
  //## begin CCOL_ST_ColTester::~CCOL_ST_ColTester%.body preserve=yes
  //## end CCOL_ST_ColTester::~CCOL_ST_ColTester%.body
}



//## Other Operations (implementation)
int CCOL_ST_ColTester::iTestCollision (CGraphBV *SrcObj, CGraphBV *DstObj)
{
  //## begin CCOL_ST_ColTester::iTestCollision%997912317.body preserve=yes
	CBoundingSphere *SS,*DS;
	CBoundingBox	*SB,*DB;
	CVect3			*SP,*DP;
	int				iFlags=0;

	// Get source Bounding Volume
	switch ( SrcObj->eGetTypeID() )
	{
		case eGraphBV_Sphere:	SS = ((CGraphBV_Sphere*)SrcObj)->pGetSphere();
								iFlags += 0;
								break;
		case eGraphBV_Box:		SB = ((CGraphBV_Box*)SrcObj)->pGetBox();
								iFlags += 1;
								break;
		case eGraphBV_Point:	SP = ((CGraphBV_Point*)SrcObj)->pGetPoint();
								iFlags += 2;
								break;

	}
	
	// Get destination Bounding Volume
	switch ( DstObj->eGetTypeID() )
	{
		case eGraphBV_Sphere:	DS = ((CGraphBV_Sphere*)DstObj)->pGetSphere();
								iFlags += 3*0;
								break;
		case eGraphBV_Box:		DB = ((CGraphBV_Box*)DstObj)->pGetBox();
								iFlags += 3*1;
								break;
		case eGraphBV_Point:	DP = ((CGraphBV_Point*)DstObj)->pGetPoint();
								iFlags += 3*2;
								break;
	}

	switch (iFlags)
	{  
		case 0:	// Sphere-Sphere test				
				return ( CCOL_ST_Sphere::iTestSphere(SS->Center,SS->Radius,DS->Center,DS->Radius) );
				break;

		case 1:	// Box-Sphere test
				return ( CCOL_ST_Box::iTestSphere(SB->Maxs,SB->Mins,DS->Center,DS->Radius) );
				break;

		case 2: // Point-Sphere test				
				return ( CCOL_ST_Point::iTestSphere(*SP,DS->Center,DS->Radius) );
				break;

		case 3:	// Sphere-Box test
				return ( CCOL_ST_Sphere::iTestBox(SS->Center,SS->Radius,DB->Maxs,DB->Mins) );
				break;

		case 4:	// Box-Box test
				return ( CCOL_ST_Box::iTestSphere(SB->Maxs,SB->Mins,DS->Center,DS->Radius) );
				break;

		case 5: // Point-Box test
				return ( CCOL_ST_Point::iTestBox(*SP,DB->Maxs,DB->Mins) );
				break;

		case 6: // Sphere-Point
				return ( CCOL_ST_Sphere::iTestPoint(SS->Center,SS->Radius,*DP) );
				break;

		case 7: // Box-Point
				return ( CCOL_ST_Box::iTestPoint(SB->Maxs,SB->Mins,*DP) );
				break;

		case 8: // Point-Point
				return ( CCOL_ST_Point::iTestPoint(*SP,*DP) );
				break;
	}

	return (0);
  //## end CCOL_ST_ColTester::iTestCollision%997912317.body
}

int CCOL_ST_ColTester::iTestPlane (CGraphBV *_SrcObj, CPlane& Plane)
{
  //## begin CCOL_ST_ColTester::iTestPlane%1007160414.body preserve=yes
	CBoundingSphere *SS;
	CBoundingBox	*SB;
	CVect3			*SP;

	switch ( _SrcObj->eGetTypeID() )
	{
		case eGraphBV_Sphere:	SS = ((CGraphBV_Sphere*)_SrcObj)->pGetSphere();
								return ( MATH_Utils::iTestSpherePlane(SS->Center,SS->Radius,Plane) );
								break;
		case eGraphBV_Box:		SB = ((CGraphBV_Box*)_SrcObj)->pGetBox();
								return ( MATH_Utils::iTestBoxPlane(SB->Maxs,SB->Maxs,Plane) );
								break;
		case eGraphBV_Point:	SP = ((CGraphBV_Point*)_SrcObj)->pGetPoint();
								return ( MATH_Utils::iTestPointPlane(*SP,Plane) );
								break;
	}

	return (0);
  //## end CCOL_ST_ColTester::iTestPlane%1007160414.body
}

// Additional Declarations
  //## begin CCOL_ST_ColTester%3B7AF1BC01C2.declarations preserve=yes
  //## end CCOL_ST_ColTester%3B7AF1BC01C2.declarations

//## begin module%3B7AF1BC01C2.epilog preserve=yes
//## end module%3B7AF1BC01C2.epilog
