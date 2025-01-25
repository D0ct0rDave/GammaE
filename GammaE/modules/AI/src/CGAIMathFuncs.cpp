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
#include "CGAIMathFuncs.h"
#include "GammaE_Math.h"
#include <math.h>
// ----------------------------------------------------------------------------
// ////////////////////////////////////////////////////////////////////
// Construction/Destruction
// ////////////////////////////////////////////////////////////////////
long CGAIMathFuncs::Angle2D(long x1, long y1, long x2, long y2)
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

    rc2 = Math::fArcTan(rc);  // atan(rc);

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
long CGAIMathFuncs::AbsAngleDiff(long a1, long a2)
{
    long d1 = 0;
    long d2 = 0;

    a1 = Math::fAbs((float)(a1 % 360));
    a2 = Math::fAbs((float)(a2 % 360));

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
long CGAIMathFuncs::Distance2D(long x1, long y1, long x2, long y2)
{
    long ld = 0;

    ld = ( (x2 - x1) * (x2 - x1) ) + ( (y2 - y1) * (y2 - y1) );
    ld = (long)Math::fSqrt( (float)ld );

    return(ld);
}
// ----------------------------------------------------------------------------
long CGAIMathFuncs::AngleAdd(long Angle, long lAdd)
{
    long NewAngle = 0;

    NewAngle = Angle + lAdd;
    if ( NewAngle > 360 ) NewAngle = NewAngle - 360;

    return(NewAngle);
}
// ----------------------------------------------------------------------------
long CGAIMathFuncs::AngleDec(long Angle, long lAdd)
{
    long NewAngle = 0;

    NewAngle = Angle - lAdd;
    if ( NewAngle < 0 ) NewAngle = NewAngle + 360;

    return(NewAngle);
}
// ----------------------------------------------------------------------------
long CGAIMathFuncs::GetRotatedX(long x, long y, long Angle)
{
    long rc = 0;

    double a = 0.0;

    double drc = 0.0;

    a = Angle;

    a = a * _PI_OVER_180_;

    drc = (double) x * Math::fCos(a) - (double) y * Math::fSin(a);

    rc = (long) drc;

    return(rc);
}
// ----------------------------------------------------------------------------
long CGAIMathFuncs::GetRotatedY(long x, long y, long Angle)
{
    long rc = 0;

    double a = 0.0;

    double drc = 0.0;

    a = Angle;

    a = a * _PI_OVER_180_;

    drc = (double) x * Math::fSin(a) + (double) y * Math::fCos(a);

    rc = (long) drc;

    return(-rc);
}
// ----------------------------------------------------------------------------
