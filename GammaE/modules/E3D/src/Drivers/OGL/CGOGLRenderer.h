// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGOGLRendererH
#define CGOGLRendererH
// ----------------------------------------------------------------------------
// CGRenderer
#include "CGE3DRenderer.h"
// CGShaderRenderer_OGL
#include "Drivers\OGL\OGLShaderRender\CGOGLShaderRenderer.h"
// ----------------------------------------------------------------------------
class CGOGLRenderer : public CGE3DRenderer
{
    public:
        CGOGLRenderer();
        ~CGOGLRenderer();

        CGOGLShaderRenderer oShaderRenderer;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
