// -----------------------------------------------------------------------------
#ifndef CE3D_OGL_Renderer_h
#define CE3D_OGL_Renderer_h 1
// -----------------------------------------------------------------------------
// CE3D_Renderer
#include "CE3D_Renderer.h"
// CE3D_ShaderRenderer_OGL
#include "Drivers\OGL\ShaderRenderOGL\CE3D_ShaderRenderer_OGL.h"
// -----------------------------------------------------------------------------
class CE3D_OGL_Renderer : public CE3D_Renderer
{
  public:
          CE3D_OGL_Renderer();

          ~CE3D_OGL_Renderer();

          CE3D_ShaderRenderer_OGL oShaderRenderer;           
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
