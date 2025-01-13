//## begin module%3CC5D588008C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CC5D588008C.cm

//## begin module%3CC5D588008C.cp preserve=no
//## end module%3CC5D588008C.cp

//## Module: CSegment%3CC5D588008C; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Segment\CSegment.cpp

//## begin module%3CC5D588008C.additionalIncludes preserve=no
//## end module%3CC5D588008C.additionalIncludes

//## begin module%3CC5D588008C.includes preserve=yes
//## end module%3CC5D588008C.includes

// CSegment
#include "Math\MATH_Segment\CSegment.h"
//## begin module%3CC5D588008C.additionalDeclarations preserve=yes
//## end module%3CC5D588008C.additionalDeclarations


// Class CSegment 



CSegment::CSegment()
  //## begin CSegment::CSegment%.hasinit preserve=no
  //## end CSegment::CSegment%.hasinit
  //## begin CSegment::CSegment%.initialization preserve=yes
  //## end CSegment::CSegment%.initialization
{
  //## begin CSegment::CSegment%.body preserve=yes
  //## end CSegment::CSegment%.body
}



//## Other Operations (implementation)
CVect3 CSegment::ProjectPoint (CVect3& _roPoint)
{
  //## begin CSegment::ProjectPoint%1019598322.body preserve=yes
	float fLambda;
	CVect3 c,qp,cp;
	
	cp.Assign(_roPoint);
	cp.Sub(oIni);

	qp.Assign(oEnd);
	qp.Sub(oIni);

	fLambda = cp.DotProd(qp) / qp.SqModule();
	
	if (fLambda < 0.0f) 
		fLambda = 0.0f;
	else
	{
		if (fLambda > 1.0f)
			fLambda = 1.0f;
	}	
	
	c.Interpolate(oIni,oEnd,fLambda);
	
	return(c);
  //## end CSegment::ProjectPoint%1019598322.body
}

// Additional Declarations
  //## begin CSegment%3CC5D588008C.declarations preserve=yes
  //## end CSegment%3CC5D588008C.declarations

//## begin module%3CC5D588008C.epilog preserve=yes
//## end module%3CC5D588008C.epilog
