// MathFunctions.h: interface for the CMathFunctions class.
//
//////////////////////////////////////////////////////////////////////
#ifndef CAI_MathFuncsH
#define CAI_MathFuncsH

class CAI_MathFuncs
{
public:
	long GetRotatedY(long x, long y, long Angle);
	long GetRotatedX(long x, long y, long Angle);
	long AngleDec(long Angle, long lAdd);
	long AngleAdd(long Angle, long lAdd);
	long Distance2D(long x1, long y1, long x2, long y2);
	long AbsAngleDiff(long a1, long a2);
	long Angle2D(long x1, long y1, long x2, long y2);
	CAI_MathFuncs();
	virtual ~CAI_MathFuncs();

};

#endif