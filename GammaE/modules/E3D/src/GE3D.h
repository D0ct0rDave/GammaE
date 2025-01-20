//-----------------------------------------------------------------------------
#ifndef GE3D_h
#define GE3D_h 1
//-----------------------------------------------------------------------------
// Rendering drivers
//-----------------------------------------------------------------------------
#include "CE3D_Renderer.h"

// OpenGL
#ifdef _OGL_
	#include "Drivers/OGL/CE3D_OGL_Renderer.h"
	
	// Windows
	#ifdef WIN32
		#include "Drivers/OGL/CE3D_OGL_Win_Renderer.h"
	#endif

	// Borland C++ Builder
	#ifdef __BORLANDC__
		#include "Drivers/OGL/CE3D_OGL_Win_Renderer.h"
	#endif
#endif
//-----------------------------------------------------------------------------
// Other
//-----------------------------------------------------------------------------
#include "RenderVars/CE3D_RenderVars.h"

#include "Viewing/Viewport/CE3D_Viewport.h"
#include "Viewing/Camera/CE3D_Camera.h"
#include "Viewing/Frustum/CE3D_Frustum.h"
#include "Viewing/Projector/CE3D_Projector.h"

#include "BoundingVolume/CBoundingVolume.h"
#include "BoundingVolume/GraphBoundVol/CGraphBV_Manager.h"
#include "BoundingVolume/GraphBoundVol/GraphBVUtils/CGraphBV_FileIO.h"
//-----------------------------------------------------------------------------
// Geometry
//-----------------------------------------------------------------------------
#include "Mesh/CMesh.h"
#include "Mesh/CMesh_Box.h"
#include "Mesh/CMesh_Sphere.h"
#include "Mesh/CMesh_Rect.h"
#include "Mesh/MeshUtils/NormalGen.h"
#include "Mesh/MeshUtils/TexCoordGen.h"
#include "Mesh/MeshUtils/TransformMesh.h"
#include "CompiledMesh/CCompiledMesh.h"
//-----------------------------------------------------------------------------
// Materials
//-----------------------------------------------------------------------------
#include "Shaders/CE3D_ShaderExtDB.h"
#include "Shaders/ShaderInstructions/CE3D_ShaderInsts.h"
#include "Shaders/ShaderDefinitions/CE3D_ShaderDefWH.h"
#include "Shaders/ShaderDefinitions/CE3D_ShaderDefFileWH.h"
#include "Shaders/ShaderWarehouse/CE3D_ShaderWH.h"
#include "Shaders/ShaderParser/CE3D_ShaderParser.h"
#include "Shaders/ShaderUtils/CE3D_ShaderUtils.h"
#include "Materials/MipMapWH.h"
#include "Materials/TexObjWH.h"
#include "Materials/CGProgramWH.h"

#include "CGRenderer.h"
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
