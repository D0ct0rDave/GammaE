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
#ifndef CG4PCurveH
#define CG4PCurveH
// ----------------------------------------------------------------------------
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
// Implements a 4 point catmull-rom curve
// ----------------------------------------------------------------------------
class CG4PCurve
{
    public:
        // / Constructor without initialization
        CG4PCurve()
        {
        }

        // / Constructor with initialization
        CG4PCurve(const CGVect3& _oP0,const CGVect3& _oP1,const CGVect3& _oP2,const CGVect3& _oP3)
        {
            Init(_oP0,_oP1,_oP2,_oP3);
        }

        // / Constructor with initialization
        CG4PCurve(CGVect3* _oPoints)
        {
            Init(_oPoints[0],_oPoints[1],_oPoints[2],_oPoints[3]);
        }

        // / Initializes the curve with the given array of points. Expects 4 points
        void Init(CGVect3* _oPoints)
        {
            Init(_oPoints[0],_oPoints[1],_oPoints[2],_oPoints[3]);
        }

        // / Initializes the curve with the given 4 points
        void Init(const CGVect3& _oP0,const CGVect3& _oP1,const CGVect3& _oP2,const CGVect3& _oP3)
        {
            m_oP[0] = _oP0;
            m_oP[1] = _oP1;
            m_oP[2] = _oP2;
            m_oP[3] = _oP3;
        }

        // / Returns the interpolated point for the given factor (0..1)
        const CGVect3& oPos(float _fFact) const;

        // / Returns the interpolated tangent vector for the given factor (0..1)
        const CGVect3& oDir(float _fFact) const;

        // / Returns the interpolated up vector for the given factor (0..1)
        const CGVect3& oUp(float _fFact) const;

    public:

        CGVect3 m_oP[4];
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
