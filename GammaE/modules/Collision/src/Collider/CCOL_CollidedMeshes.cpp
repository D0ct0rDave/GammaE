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
#include "Collider\CCOL_CollidedMeshes.h"
#include <assert.h>
// -----------------------------------------------------------------------------
void CCOL_CollidedMeshes::Reset()
{
    m_poMeshes.Clear();
}
// -----------------------------------------------------------------------------
void CCOL_CollidedMeshes::AddMesh(CGBaseMesh* _pMesh)
{
    m_poMeshes.uiAdd(_pMesh);
}
// -----------------------------------------------------------------------------
int CCOL_CollidedMeshes::iGetNumMeshes()
{
    return(m_poMeshes.uiNumElems());
}
// -----------------------------------------------------------------------------
CGBaseMesh* CCOL_CollidedMeshes::pGetMesh(uint _uiMesh)
{
    assert ((_uiMesh < m_poMeshes.uiNumElems()) && "Mesh index out of bounds" );
    return (m_poMeshes[_uiMesh]);
}
// -----------------------------------------------------------------------------
