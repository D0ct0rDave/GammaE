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
#ifndef CCOL_MeshTester_h
#define CCOL_MeshTester_h 1
// -----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "COL_TriList\CCOL_TriList.h"
// -----------------------------------------------------------------------------
class CCOL_MeshTester
{
    public:
        virtual int iTestCollision(CGBaseMesh* _poMesh, int _iMat, CGGraphBV* _poBVol, CCOL_TriList& _oTriList);
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------