// CObject3D_CompiledLeaf
#include "CObject3D_CompiledLeaf.h"

// Class CObject3D_CompiledLeaf

CObject3D_CompiledLeaf::CObject3D_CompiledLeaf()
    : poCMesh(NULL), poShader(NULL)
{
}

CObject3D_CompiledLeaf::~CObject3D_CompiledLeaf()
{
}

void CObject3D_CompiledLeaf::Render ()
{

     // If NULL material process is still valid
    CGRenderer::I()->RenderCompiledMesh( poGetCMesh(),poGetShader() );

}

void CObject3D_CompiledLeaf::SetCMesh (CCompiledMesh *_poCMesh)
{
    poCMesh = _poCMesh;
}

CCompiledMesh *CObject3D_CompiledLeaf::poGetCMesh ()
{
    return( poCMesh );
}

CGraphBV *CObject3D_CompiledLeaf::poGetBoundVol ()
{
    return( poGetCMesh()->poGetBV() );
}

void CObject3D_CompiledLeaf::ComputeBoundVol ()
{
}

void CObject3D_CompiledLeaf::SetShader (CE3D_Shader *_poShader)
{
    poShader = _poShader;
}

CE3D_Shader *CObject3D_CompiledLeaf::poGetShader ()
{
    return ( poShader );
}

// Additional Declarations
