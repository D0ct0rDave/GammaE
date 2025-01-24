// ----------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "CObject3D_Leaf.h"
// ----------------------------------------------------------------------
// Class CObject3D_Leaf
// ----------------------------------------------------------------------
CObject3D_Leaf::CObject3D_Leaf() : poMesh(NULL), poShader(NULL)
{
    TypeID   = e3DObj_Leaf;
}
// ----------------------------------------------------------------------
CObject3D_Leaf::~CObject3D_Leaf()
{
    Clear();
}
// ----------------------------------------------------------------------
void CObject3D_Leaf::Clear ()
{
   mDel poMesh;

    poMesh = NULL;
}
// ----------------------------------------------------------------------
CGraphBV *CObject3D_Leaf::poGetBoundVol ()
{
    return( poMesh->BVol );
}
// ----------------------------------------------------------------------
void CObject3D_Leaf::ComputeBoundVol ()
{
   poMesh->ComputeBoundVol();
}
// ----------------------------------------------------------------------
void CObject3D_Leaf::SetMesh (CMesh *_poMesh)
{
    poMesh = _poMesh;
}
// ----------------------------------------------------------------------
CMesh *CObject3D_Leaf::poGetMesh ()
{
    return( poMesh );
}
// ----------------------------------------------------------------------
void CObject3D_Leaf::Render ()
{
   CGRenderer::I()->RenderMesh( poGetMesh(),poGetShader() );
}
// ----------------------------------------------------------------------
