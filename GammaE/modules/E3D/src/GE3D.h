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
#ifndef GE3D_h
#define GE3D_H
// ----------------------------------------------------------------------------Rendering drivers
// ----------------------------------------------------------------------------
#include "CGRenderer.h"

// OpenGL
#ifdef _OGL_
    #include "Drivers/OGL/CGOGLRenderer.h"

// Windows
    #ifdef WIN32
        #include "Drivers/OGL/CGOGLWinRenderer.h"
    #endif

// Borland C++ Builder
    #ifdef __BORLANDC__
        #include "Drivers/OGL/CGOGLWinRenderer.h"
    #endif
#endif
// ----------------------------------------------------------------------------Other
// ----------------------------------------------------------------------------
#include "RenderVars/CGRenderVars.h"

#include "Viewing/Viewport/CGViewport.h"
#include "Viewing/Camera/CGCamera.h"
#include "Viewing/Projector/CGProjector.h"

// ----------------------------------------------------------------------------Geometry
// ----------------------------------------------------------------------------
#include "Mesh/CGBaseMesh.h"
#include "Mesh/CGMesh.h"
#include "Mesh/CGMeshBox.h"
#include "Mesh/CGMeshSphere.h"
#include "Mesh/CGMeshRect.h"
#include "Mesh/CGMeshCross.h"
#include "Mesh/CGCompiledMesh.h"
#include "Mesh/MeshUtils/NormalGen.h"
#include "Mesh/MeshUtils/TexCoordGen.h"
#include "Mesh/MeshUtils/TransformMesh.h"
#include "Mesh/MeshUtils/ComputeBV.h"

// ----------------------------------------------------------------------------Materials
// ----------------------------------------------------------------------------
#include "Shaders/CGShaderExtDB.h"
#include "Shaders/ShaderInstructions/CGShaderInstructions.h"
#include "Shaders/ShaderDefinitions/CGShaderDefWH.h"
#include "Shaders/ShaderDefinitions/CGShaderDefFileWH.h"
#include "Shaders/ShaderWarehouse/CGShaderWH.h"
#include "Shaders/ShaderParser/CGShaderParser.h"
#include "Shaders/ShaderUtils/CGShaderUtils.h"
#include "Materials/CGMipMapWH.h"
#include "Materials/CGTexObjWH.h"
#include "Materials/CGProgramWH.h"
#include "Light/CGLight.h"

#include "CGRenderer.h"
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
