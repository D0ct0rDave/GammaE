#include "CCurve.h"
#include "C4PCurve.h"
//-----------------------------------------------------------------------------
float CCurve::fGet4PCurve(float _fFact,C4PCurve* _poCurve) const
{
	// Number of possible 4p curve segments in this curve
	uint uiSegs      = m_uiNumPoints - 3;

	// Distribute the values uniformly each segment is fSegSize percentage of curve
	float fSegSize = 1.0f / (float)uiSegs;

	// Retrieve the segment to get the interpolated data
	uint uiSeg  = (uint)(_fFact / fSegSize);

	// Compute the factor for this segment
	float fFact = ((_fFact/fSegSize) - (float)uiSeg);

	/*
	if (uiSeg == 0)
	{
		// fFact = -4/3 + fFact*4.3f;
		fFact = (4.0f / 3.0f)* fFact - (1.0f/3.0f);
	}
	else 	
	if (uiSeg == uiSegs-1)
	{
		fFact = 1.5f * fFact;
	}
	*/
	
	// Setup the curve to get the point
	_poCurve->Init( m_poPoints + uiSeg );
	
	return(fFact);
}
//-----------------------------------------------------------------------------
// Assume segments are equally spaced
//-----------------------------------------------------------------------------
const CVect3& CCurve::oPos(float _fFact) const
{
	if (m_uiNumPoints<4) return( CVect3::oZero() );

	// early rejection tests
	if (_fFact <= 0.0f) return( m_poPoints[1] );
	if (_fFact >= 1.0f) return( m_poPoints[m_uiNumPoints-2] );

	C4PCurve oCurve;
	float fFact = fGet4PCurve(_fFact,&oCurve);

	// Returns the value
	return( oCurve.oPos(fFact) );
}
//-----------------------------------------------------------------------------
const CVect3& CCurve::oDir(float _fFact) const
{
	if (m_uiNumPoints<4) return( CVect3::oZ() );

	// early rejection tests
	if (_fFact <= 0.0f) return( CVect3::oZ() );
	if (_fFact >= 1.0f) return( CVect3::oZ() );

	C4PCurve oCurve;
	float fFact = fGet4PCurve(_fFact,&oCurve);

	// Returns the value
	return( oCurve.oDir(fFact) );
}
//-----------------------------------------------------------------------------
/// Returns the interpolated up vector for the given factor (0..1)
const CVect3& CCurve::oUp(float _fFact) const
{
	if (m_uiNumPoints<4) return( CVect3::oY() );

	// early rejection tests
	if (_fFact < 0.0f) return( CVect3::oY() );
	if (_fFact > 1.0f) return( CVect3::oY() );


	C4PCurve oCurve;
	float fFact = fGet4PCurve(_fFact,&oCurve);

	// Returns the value
	return( oCurve.oUp(fFact) );
}
//-----------------------------------------------------------------------------
