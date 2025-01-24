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
#ifndef CGCurveH
#define CGCurveH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
// Implements a catmull-rom curve for variable number of points
// ----------------------------------------------------------------------------
class CG4PCurve;
class CGCurve
{
    public:
        // / Constructor without initialization
        CGCurve() :
            m_poPoints(NULL)
        {
        }

        // / Constructor with initialization
        CGCurve(CGVect3* _oPoints,uint _uiNumPoints)
        {
            Init(_oPoints,_uiNumPoints);
        }

        // / Initializes the curve with the given array of points. Expects at least 4 points
        virtual void Init(CGVect3* _oPoints,uint _uiNumPoints)
        {
            m_poPoints = _oPoints;
            m_uiNumPoints = _uiNumPoints;
        }

        // / Returns the interpolated point for the given factor (0..1)
        const CGVect3& oPos(float _fFact) const;

        // / Returns the interpolated tangent vector for the given factor (0..1)
        const CGVect3& oDir(float _fFact) const;

        // / Returns the interpolated up vector for the given factor (0..1)
        const CGVect3& oUp(float _fFact) const;

        // / Returns the array of points of the curve
        CGVect3* poControlPoints()
        {
            return(m_poPoints);
        }

        // / Returns the number of control points of the curve
        uint uiNumControlPoints()
        {
            return(m_uiNumPoints);
        }

    protected:
        float fGet4PCurve(float _fFact,CG4PCurve* _poCurve) const;

        CGVect3* m_poPoints;
        uint m_uiNumPoints;
};
// ----------------------------------------------------------------------------
class CGCurveDynamic : public CGCurve
{
    public:
        // / Initializes the curve with the given array of points. Expects at least 4 points
        virtual void Init(CGVect3* _oPoints,uint _uiNumPoints)
        {
            m_oPntList.Clear();

            for ( uint i = 0; i < _uiNumPoints; i++ )
                m_oPntList.uiAdd( _oPoints[i] );

            m_poPoints = m_oPntList.poBuff();
            m_uiNumPoints = _uiNumPoints;
        }

        // / To add independent points one by one
        void AddPoint(const CGVect3& _oPoint)
        {
            m_oPntList.uiAdd(_oPoint);

            m_poPoints = m_oPntList.poBuff();
            m_uiNumPoints = m_oPntList.uiNumElems();
        }

    public:

        CGDynArray <CGVect3> m_oPntList;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
