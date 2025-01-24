//-----------------------------------------------------------------------------
#ifndef C4PCurve_h
#define C4PCurve_h 1
//-----------------------------------------------------------------------------
#include "MATH_Vector/CVect3.h"
//-----------------------------------------------------------------------------
// Implements a 4 point catmull-rom curve
//-----------------------------------------------------------------------------
class C4PCurve
{   
	public:
			/// Constructor without initialization
            C4PCurve(){};

			/// Constructor with initialization
            C4PCurve(const CVect3& _oP0,const CVect3& _oP1,const CVect3& _oP2,const CVect3& _oP3){ Init(_oP0,_oP1,_oP2,_oP3); };

			/// Constructor with initialization
            C4PCurve(CVect3* _oPoints){ Init(_oPoints[0],_oPoints[1],_oPoints[2],_oPoints[3]); };

			/// Initializes the curve with the given array of points. Expects 4 points
			void Init(CVect3* _oPoints)
			{
				Init(_oPoints[0],_oPoints[1],_oPoints[2],_oPoints[3]);
			}

			/// Initializes the curve with the given 4 points
			void Init(const CVect3& _oP0,const CVect3& _oP1,const CVect3& _oP2,const CVect3& _oP3)
			{
				m_oP[0] = _oP0;
				m_oP[1] = _oP1;
				m_oP[2] = _oP2;
				m_oP[3] = _oP3;
			}

			/// Returns the interpolated point for the given factor (0..1)
			const CVect3& oPos(float _fFact) const;

			/// Returns the interpolated tangent vector for the given factor (0..1)
			const CVect3& oDir(float _fFact) const;

			/// Returns the interpolated up vector for the given factor (0..1)
			const CVect3& oUp(float _fFact) const;

	public:
			// Data Members for Class Attributes
			CVect3 m_oP[4];
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
