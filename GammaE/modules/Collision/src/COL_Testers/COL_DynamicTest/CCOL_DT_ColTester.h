// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

#ifndef CCOL_DT_ColTester_h
#define CCOL_DT_ColTester_h 1

// GammaE_E3D
#include "GammaE_E3D.h"


class CCOL_DT_ColTester
{
    public:

        static float fTestCollision(CGGraphBV* SrcObj, CGGraphBV* DstObj);

        static float fTestPlane(CGGraphBV* _SrcObj, const CGPlane& Plane);

        static float fTestTriangle(CGGraphBV* _SrcObj, const CGTriangle& _Tri);
};

// Class CCOL_DT_ColTester

#endif
