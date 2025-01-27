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

#ifndef CCOL_Mesh_ColTester_h
#define CCOL_Mesh_ColTester_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// CCOL_TriList
#include "COL_TriList\CCOL_TriList.h"
// CCOL_DT_ColTester
#include "COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"

class CCOL_Mesh_ColTester
{
    public:
        static int iTestCollision(CGMesh* _pMesh, CGGraphBV* _BVol, CCOL_TriList& _TriList);
};

// Class CCOL_Mesh_ColTester

#endif
