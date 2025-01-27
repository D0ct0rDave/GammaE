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

#ifndef CCOL_ST_ColTester_h
#define CCOL_ST_ColTester_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// CCOL_ST_Point
#include "COL_Testers\COL_StaticTest\CCOL_ST_Point.h"
// CCOL_ST_Sphere
#include "COL_Testers\COL_StaticTest\CCOL_ST_Sphere.h"
// CCOL_ST_Box
#include "COL_Testers\COL_StaticTest\CCOL_ST_Box.h"

class CCOL_ST_ColTester
{
    public:
        static int iTestCollision(CGGraphBV* _poSrcBV, CGGraphBV* _poDstBV);
        static int iTestPlane(CGGraphBV* _poBV, const CGPlane& _oPlane);

};

// Class CCOL_ST_ColTester

#endif
