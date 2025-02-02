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
#ifndef CCOL_Mesh_h
#define CCOL_Mesh_h 1
// -----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CCOL_Mesh
{
    public:
        CCOL_Mesh();
        void Set(CGBaseMesh* _poMesh, int _iMat, float _fFrameFact);

        CGBaseMesh* m_poMesh;
        float fFrameFact;
        int iMat;
};
// -----------------------------------------------------------------------------
inline void CCOL_Mesh::Set(CGBaseMesh* _poMesh, int _iMat, float _fFrameFact)
{
    m_poMesh = _poMesh;
    fFrameFact = _fFrameFact;
    iMat = _iMat;
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------