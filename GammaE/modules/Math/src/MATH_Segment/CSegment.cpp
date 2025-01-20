














//-----------------------------------------------------------------------------
#include "MATH_Segment\CSegment.h"




//-----------------------------------------------------------------------------





CVect3 CSegment::ProjectPoint (CVect3& _oPoint)
{
  
	float fLambda;
	CVect3 c,qp,cp;
	
	cp.Assign(_oPoint);
	cp.Sub(oIni);

	qp.Assign(oEnd);
	qp.Sub(oIni);

	fLambda = cp.fDotProd(qp) / qp.fSqModule();
	
	if (fLambda < 0.0f) 
		fLambda = 0.0f;
	else
	{
		if (fLambda > 1.0f)
			fLambda = 1.0f;
	}	
	
	c.Interpolate(oIni,oEnd,fLambda);
	
	return(c);
  
}

//-----------------------------------------------------------------------------
  
  



