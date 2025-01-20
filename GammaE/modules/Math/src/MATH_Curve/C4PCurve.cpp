#include "C4PCurve.h"
//-----------------------------------------------------------------------------
/*
http://www.mvps.org/directx/articles/catmull/

Returns the value for this formula
	q(t) = 0.5 *(    	(2 * P1) +
  				(-P0 + P2) * t +
				(2*P0 - 5*P1 + 4*P2 - P3) * t2 +
				(-P0 + 3*P1- 3*P2 + P3) * t3)
				
	for values between 0..1 the formula gives points in the segment P1 - P2
*/
//-----------------------------------------------------------------------------
const CVect3& C4PCurve::oPos(float _fFact) const
{
	float fT = _fFact;
	float fT2 = _fFact*_fFact;
	float fT3 = fT2*_fFact;

	static CVect3 oQ;

	oQ.x =0.5f*    ((2.0f*m_oP[1].x) +
					(-m_oP[0].x + m_oP[2].x)*fT + 
					(2.0f*m_oP[0].x -  5.0f*m_oP[1].x + 4.0f*m_oP[2].x - m_oP[3].x)*fT2 + 
					(-m_oP[0].x +  3.0f*m_oP[1].x - 3.0f*m_oP[2].x + m_oP[3].x)*fT3);

	oQ.y =0.5f*    ((2.0f*m_oP[1].y) +
					(-m_oP[0].y + m_oP[2].y)*fT + 
					(2.0f*m_oP[0].y -  5.0f*m_oP[1].y + 4.0f*m_oP[2].y - m_oP[3].y)*fT2 + 
					(-m_oP[0].y +  3.0f*m_oP[1].y - 3.0f*m_oP[2].y + m_oP[3].y)*fT3);

	oQ.z =0.5f*    ((2.0f*m_oP[1].z) +
					(-m_oP[0].z + m_oP[2].z)*fT + 
					(2.0f*m_oP[0].z -  5.0f*m_oP[1].z + 4.0f*m_oP[2].z - m_oP[3].z)*fT2 + 
					(-m_oP[0].z +  3.0f*m_oP[1].z - 3.0f*m_oP[2].z + m_oP[3].z)*fT3);

	/*
		// Implementando operadores en CVect3
		oQ = 0.5f * ((2.0f*m_oP[1]) + 
					 (-m_oP[0] + m_oP[2])*fT + 
					 (2.0f*m_oP[0] - 5.0f*m_oP[1] + 4.0f*m_oP[2] - m_oP[3])*fT2 + 
					 (-m_oP[0] + 3.0f*m_oP[1] - 3.0f*m_oP[2] + m_oP[3])*fT3 );
	*/

	return(oQ);
}
//-----------------------------------------------------------------------------
/*
Returns the value for this formula
	q(t) = 0.5*((-P0 + P2) +
				(2*P0 - 5*P1 + 4*P2 - P3) * 2 * t +
				(-P0 + 3*P1- 3*P2 + P3) * 3 * t2)

	for values between 0..1 the formula gives points in the segment P1 - P2
*/
//-----------------------------------------------------------------------------
const CVect3& C4PCurve::oDir(float _fFact) const
{
	float fT = _fFact;
	float fT2 = _fFact*_fFact;

	static CVect3 oQ;

	oQ.x =0.5f*    ((-m_oP[0].x + m_oP[2].x) + 
					(2.0f*m_oP[0].x -  5.0f*m_oP[1].x + 4.0f*m_oP[2].x - m_oP[3].x)*2*fT + 
					(-m_oP[0].x +  3.0f*m_oP[1].x - 3.0f*m_oP[2].x + m_oP[3].x)*3*fT2);

	oQ.y =0.5f*    ((-m_oP[0].y + m_oP[2].y) + 
					(2.0f*m_oP[0].y -  5.0f*m_oP[1].y + 4.0f*m_oP[2].y - m_oP[3].y)*2*fT + 
					(-m_oP[0].y +  3.0f*m_oP[1].y - 3.0f*m_oP[2].y + m_oP[3].y)*3*fT2);

	oQ.z =0.5f*    ((-m_oP[0].z + m_oP[2].z) + 
					(2.0f*m_oP[0].z -  5.0f*m_oP[1].z + 4.0f*m_oP[2].z - m_oP[3].z)*2*fT + 
					(-m_oP[0].z +  3.0f*m_oP[1].z - 3.0f*m_oP[2].z + m_oP[3].z)*3*fT2);

	return(oQ);
}
//-----------------------------------------------------------------------------
/*
Returns the value for this formula
	q(t) = 0.5 *(2*P0 - 5*P1 + 4*P2 - P3)* 2 +
				(-P0 + 3*P1- 3*P2 + P3)* 6 * t)
				
	for values between 0..1 the formula gives points in the segment P1 - P2
*/
//-----------------------------------------------------------------------------
const CVect3& C4PCurve::oUp(float _fFact) const
{
	CVect3 oD;
	oD.Orthogonal(oDir(_fFact));
	return(oD);

/*
	float fT = _fFact;

	static CVect3 oQ;

	oQ.x =0.5f*    ((2.0f*m_oP[0].x -  5.0f*m_oP[1].x + 4.0f*m_oP[2].x - m_oP[3].x)*2 + 
					(-m_oP[0].x +  3.0f*m_oP[1].x - 3.0f*m_oP[2].x + m_oP[3].x)*6*fT);

	oQ.y =0.5f*    ((2.0f*m_oP[0].y -  5.0f*m_oP[1].y + 4.0f*m_oP[2].y - m_oP[3].y)*2 + 
					(-m_oP[0].y +  3.0f*m_oP[1].y - 3.0f*m_oP[2].y + m_oP[3].y)*6*fT);

	oQ.z =0.5f*    ((2.0f*m_oP[0].z -  5.0f*m_oP[1].z + 4.0f*m_oP[2].z - m_oP[3].z)*2 + 
					(-m_oP[0].z +  3.0f*m_oP[1].z - 3.0f*m_oP[2].z + m_oP[3].z)*6*fT);

	CVect3 oD = oDir(_fFact);

	float fVDotV = oD.fDotProd(oD);
	float fVDotA = oD.fDotProd(oQ);
	// (oQ*fVDotV) - (oD*fVDotA);

    oQ.Scale(fVDotV);
    oD.Scale(fVDotA);
    oQ.Sub(oD);

	return(oQ);
*/
}
//-----------------------------------------------------------------------------
