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
//
// ////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------------------
#ifndef CGMathFuncsH
#define CGMathFuncsH
// ----------------------------------------------------------------------------
class CGMathFuncs
{
    public:

        long GetRotatedY(long x, long y, long Angle);
        long GetRotatedX(long x, long y, long Angle);
        long AngleDec(long Angle, long lAdd);
        long AngleAdd(long Angle, long lAdd);
        long Distance2D(long x1, long y1, long x2, long y2);
        long AbsAngleDiff(long a1, long a2);
        long Angle2D(long x1, long y1, long x2, long y2);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
