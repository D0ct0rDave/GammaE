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
// ----------------------------------------------------------------------------
#ifndef SCNUt_MeshCompacter_h
#define SCNUt_MeshCompacter_h 1
// ----------------------------------------------------------------------------

// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// ----------------------------------------------------------------------------
typedef struct
{
    uint m_uiTri;
    uint m_uiVX;
}TVertexRef;

class CCompactMeshData
{
    public:

        CGMesh* m_poMesh;

        // Inverse table
        CGDynArray <TVertexRef> m_oInvTable;
};
// ----------------------------------------------------------------------------
// Toma una escena con n triángulos y 3*n vertices, y
// genera una malla de m <=3*n vertices.
class SCNUt_MeshCompacter
{
    public:

        SCNUt_MeshCompacter();
        ~SCNUt_MeshCompacter();

        CGMesh* poCompactMesh(const SCNUt_TriScene& _oScene);
        void CompactMesh(const SCNUt_TriScene& _oScene,CCompactMeshData* _poData);

    protected:

        uint uiInsertVertex(CGMesh* Mesh, CGVect3 &VX, CGVect2& UV, CGVect4 &VC, CGVect3 &VN);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
