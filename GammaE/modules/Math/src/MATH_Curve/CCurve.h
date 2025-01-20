//-----------------------------------------------------------------------------
#ifndef CCurve_h
#define CCurve_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "MATH_Vector/CVect3.h"
//-----------------------------------------------------------------------------
// Implements a catmull-rom curve for variable number of points
//-----------------------------------------------------------------------------
class C4PCurve;
class CCurve
{
	public:
			/// Constructor without initialization
            CCurve(){};

			/// Constructor with initialization
            CCurve(CVect3* _oPoints,uint _uiNumPoints)
            {
				Init(_oPoints,_uiNumPoints); 
			};

			/// Initializes the curve with the given array of points. Expects at least 4 points
			virtual void Init(CVect3* _oPoints,uint _uiNumPoints)
			{
				m_poPoints		= _oPoints;
				m_uiNumPoints	= _uiNumPoints;
			}

			/// Returns the interpolated point for the given factor (0..1)
			const CVect3& oPos(float _fFact) const;

			/// Returns the interpolated tangent vector for the given factor (0..1)
			const CVect3& oDir(float _fFact) const;

			/// Returns the interpolated up vector for the given factor (0..1)
			const CVect3& oUp(float _fFact) const;
			
			/// Returns the array of points of the curve
			CVect3* poControlPoints() { return(m_poPoints); };
			
			/// Returns the number of control points of the curve
			uint uiNumControlPoints() { return(m_uiNumPoints); };

	protected:
			float fGet4PCurve(float _fFact,C4PCurve* _poCurve) const;

			// Data Members for Class Attributes
			CVect3*				m_poPoints;
			uint				m_uiNumPoints;
};
//-----------------------------------------------------------------------------
class CCurveDynamic : public CCurve
{
	public:
			/// Initializes the curve with the given array of points. Expects at least 4 points
			virtual void Init(CVect3* _oPoints,uint _uiNumPoints)
			{
				m_oPntList.Clear();

				for (uint i=0;i<_uiNumPoints;i++)
					m_oPntList.uiAdd( _oPoints[i] );

				m_poPoints		= m_oPntList.poBuff();
				m_uiNumPoints	= _uiNumPoints;
			}

			/// To add independent points one by one
			void AddPoint(const CVect3& _oPoint)
			{
				m_oPntList.uiAdd(_oPoint);

				m_poPoints		= m_oPntList.poBuff();
				m_uiNumPoints	= m_oPntList.uiNumElems();				
			}			

	public:
			// Data Members for Class Attributes
			CGDynArray<CVect3> m_oPntList;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
