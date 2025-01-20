//## begin module%3A9AB8AF032A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AB8AF032A.cm

//## begin module%3A9AB8AF032A.cp preserve=no
//## end module%3A9AB8AF032A.cp

//## Module: CE3D_OGL_Renderer%3A9AB8AF032A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Drivers\OGL\CE3D_OGL_Renderer.h

#ifndef CE3D_OGL_Renderer_h
#define CE3D_OGL_Renderer_h 1

//## begin module%3A9AB8AF032A.additionalIncludes preserve=no
//## end module%3A9AB8AF032A.additionalIncludes

//## begin module%3A9AB8AF032A.includes preserve=yes
//## end module%3A9AB8AF032A.includes

// CE3D_Renderer
#include "E3D\CE3D_Renderer.h"
// CE3D_ShaderRenderer_OGL
#include "E3D\Drivers\OGL\ShaderRenderOGL\CE3D_ShaderRenderer_OGL.h"
//## begin module%3A9AB8AF032A.additionalDeclarations preserve=yes
//## end module%3A9AB8AF032A.additionalDeclarations


//## begin CE3D_OGL_Renderer%3A9AB8AF032A.preface preserve=yes
//## end CE3D_OGL_Renderer%3A9AB8AF032A.preface

//## Class: CE3D_OGL_Renderer%3A9AB8AF032A
//## Category: E3D::Drivers::OGL%3A9EBF2A00BE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3A9FCE8A02EE; { -> }

class CE3D_OGL_Renderer : public CE3D_Renderer  //## Inherits: <unnamed>%3A9AB8BB02DA
{
  //## begin CE3D_OGL_Renderer%3A9AB8AF032A.initialDeclarations preserve=yes
  //## end CE3D_OGL_Renderer%3A9AB8AF032A.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_OGL_Renderer();

    //## Destructor (generated)
      ~CE3D_OGL_Renderer();

    // Data Members for Associations

      //## Association: E3D::Drivers::OGL::<unnamed>%3C6ACFCA0170
      //## Role: CE3D_OGL_Renderer::oShaderRenderer%3C6ACFCA02C5
      //## begin CE3D_OGL_Renderer::oShaderRenderer%3C6ACFCA02C5.role preserve=no  public: CE3D_ShaderRenderer_OGL { -> VHAN}
      CE3D_ShaderRenderer_OGL oShaderRenderer;
      //## end CE3D_OGL_Renderer::oShaderRenderer%3C6ACFCA02C5.role

    // Additional Public Declarations
      //## begin CE3D_OGL_Renderer%3A9AB8AF032A.public preserve=yes
      //## end CE3D_OGL_Renderer%3A9AB8AF032A.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_OGL_Renderer%3A9AB8AF032A.protected preserve=yes
      //## end CE3D_OGL_Renderer%3A9AB8AF032A.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_OGL_Renderer%3A9AB8AF032A.private preserve=yes
      //## end CE3D_OGL_Renderer%3A9AB8AF032A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_OGL_Renderer%3A9AB8AF032A.implementation preserve=yes
      //## end CE3D_OGL_Renderer%3A9AB8AF032A.implementation

};

//## begin CE3D_OGL_Renderer%3A9AB8AF032A.postscript preserve=yes
//## end CE3D_OGL_Renderer%3A9AB8AF032A.postscript

// Class CE3D_OGL_Renderer 

//## begin module%3A9AB8AF032A.epilog preserve=yes
//## end module%3A9AB8AF032A.epilog


#endif
