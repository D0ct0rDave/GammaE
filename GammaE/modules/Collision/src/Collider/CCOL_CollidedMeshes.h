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
#ifndef CCOL_CollidedMeshes_h
#define CCOL_CollidedMeshes_h 1
// -----------------------------------------------------------------------------
#include "GammaE_E3D.h"
// -----------------------------------------------------------------------------
class CCOL_CollidedMeshes
{
    public:
        CCOL_CollidedMeshes();

        ~CCOL_CollidedMeshes();

        void Reset();

        void AddMesh(CGBaseMesh* _pMesh);

        int iGetNumMeshes();

        CGBaseMesh* pGetMesh(uint _uiMesh);

    protected:

        CGDynArray<CGBaseMesh*> m_poMeshes;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------