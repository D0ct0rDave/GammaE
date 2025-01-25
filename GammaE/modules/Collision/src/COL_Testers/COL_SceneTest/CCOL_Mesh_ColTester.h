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
#include "Collision\COL_TriList\CCOL_TriList.h"
// CCOL_DT_ColTester
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_ColTester.h"
// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"

class CCOL_Mesh_ColTester
{
    public:
        CCOL_Mesh_ColTester();

        ~CCOL_Mesh_ColTester();

        static int iTestCollision(CMesh* _pMesh, CGBoundingVolume* _BVol, CCOL_TriList& _TriList);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_Mesh_ColTester

#endif
