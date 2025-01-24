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
// ////////////////////////////////////////////////////////////////////
#include "CGMathFuncs.h"
#include <math.h>
// #include <cmath>                    // for trigonometry functions
// ----------------------------------------------------------------------------
// ////////////////////////////////////////////////////////////////////
// Construction/Destruction
// ////////////////////////////////////////////////////////////////////
long CGMathFuncs::Angle2D(long x1, long y1, long x2, long y2)
{
    double rc = 0.0;
    double rc2 = 0.0;

    double fx1 = 0.0;
    double fy1 = 0.0;
    double fx2 = 0.0;
    double fy2 = 0.0;

    fx1 = x1;
    fy1 = y1;
    fx2 = x2;
    fy2 = y2;

    long lrc = 0;
    if ( x2 == x1 )
    {
        if ( y1 < y2 ) return(270);
        if ( y1 > y2 ) return(90);
        return(0);
    }

    rc = (fy2 - fy1) / (fx2 - fx1);

    rc2 = atan(rc);

    rc2 = rc2 * 180 / 3.141592654; // convert Rad to Degrees

    if ( x2 < x1 )
    {
        if ( y2 < y1 )
        {
            lrc = (long) (180 - rc2);
        }
        else
        {
            lrc = (long) (180 - rc2);
        }
    }
    else
    {
        if ( y1 > y2 )
        {
            lrc = (long) (0 - rc2);
        }
        else
        {
            lrc = (long) (360 - rc2);
        }
    }

    return(lrc);
}
// ----------------------------------------------------------------------------
long CGMathFuncs::AbsAngleDiff(long a1, long a2)
{
    long d1 = 0;
    long d2 = 0;

    a1 = abs(a1 % 360);
    a2 = abs(a2 % 360);

    if ( a2 > a1 )
    {
        d1 = a2 - a1;

        d2 = 360 - a2 + a1;
    }
    else
    {
        d1 = a1 - a2;

        d2 = 360 - a1 + a2;
    }

    if ( d1 > d2 )
    {
        return(d2);
    }
    else
    {
        return(d1);
    }
}
// ----------------------------------------------------------------------------
long CGMathFuncs::Distance2D(long x1, long y1, long x2, long y2)
{
    long ld = 0;

    ld = ( (x2 - x1) * (x2 - x1) ) + ( (y2 - y1) * (y2 - y1) );
    ld = (long) sqrt( (float)ld );

    return(ld);
}
// ----------------------------------------------------------------------------
long CGMathFuncs::AngleAdd(long Angle, long lAdd)
{
    long NewAngle = 0;

    NewAngle = Angle + lAdd;
    if ( NewAngle > 360 ) NewAngle = NewAngle - 360;

    return(NewAngle);
}
// ----------------------------------------------------------------------------
long CGMathFuncs::AngleDec(long Angle, long lAdd)
{
    long NewAngle = 0;

    NewAngle = Angle - lAdd;
    if ( NewAngle < 0 ) NewAngle = NewAngle + 360;

    return(NewAngle);
}
// ----------------------------------------------------------------------------
long CGMathFuncs::GetRotatedX(long x, long y, long Angle)
{
    long rc = 0;

    double a = 0.0;

    double drc = 0.0;

    a = Angle;

    a = a * 3.14159265358979 / 180;

    drc = (double) x * cos(a) - (double) y * sin(a);

    rc = (long) drc;

    return(rc);
}
// ----------------------------------------------------------------------------
long CGMathFuncs::GetRotatedY(long x, long y, long Angle)
{
    long rc = 0;

    double a = 0.0;

    double drc = 0.0;

    a = Angle;

    a = a * 3.14159265358979 / 180;

    drc = (double) x * sin(a) + (double) y * cos(a);

    rc = (long) drc;

    return(-rc);
}
// ----------------------------------------------------------------------------
