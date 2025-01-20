//## begin module%3C1BF3280328.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1BF3280328.cm

//## begin module%3C1BF3280328.cp preserve=no
//## end module%3C1BF3280328.cp

//## Module: GammaE_E3D%3C1BF3280328; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\GammaE_E3D.h

#ifndef GammaE_E3D_h
#define GammaE_E3D_h 1

//## begin module%3C1BF3280328.additionalIncludes preserve=no
//## end module%3C1BF3280328.additionalIncludes

//## begin module%3C1BF3280328.includes preserve=yes
//---------------------------------------------------------------------------
// Rendering drivers
//---------------------------------------------------------------------------
#include "E3D/CE3D_Renderer.h"

// OpenGL
#ifdef _OGL_
	#include "E3D/Drivers/OGL/CE3D_OGL_Renderer.h"
	
	// Windows
	#ifdef WIN32
		#include "E3D/Drivers/OGL/CE3D_OGL_Win_Renderer.h"
	#endif

	// Borland C++ Builder
	#ifdef _BORLANDC_
		#include "E3D/Drivers/OGL/CE3D_OGL_Win_Renderer.h"
	#endif
#endif

//---------------------------------------------------------------------------
// Other
//---------------------------------------------------------------------------
#include "E3D/RenderVars/CE3D_RenderVars.h"

#include "E3D/Viewing/Viewport/CE3D_Viewport.h"
#include "E3D/Viewing/Camera/CE3D_Camera.h"
#include "E3D/Viewing/Frustum/CE3D_Frustum.h"
#include "E3D/Viewing/Projector/CE3D_Projector.h"

#include "E3D/BoundingVolume/CBoundingVolume.h"
#include "E3D/BoundingVolume/GraphBoundVol/CGraphBV_Manager.h"
#include "E3D/BoundingVolume/GraphBoundVol/GraphBVUtils/CGraphBV_FileIO.h"
#include "Color.h"
//---------------------------------------------------------------------------
// Geometry
//---------------------------------------------------------------------------
#include "E3D/Mesh/CMesh.h"
#include "E3D/Mesh/CMesh_Box.h"
#include "E3D/Mesh/CMesh_Sphere.h"
#include "E3D/Mesh/CMesh_Rect.h"
#include "E3D/Mesh/MeshUtils/NormalGen.h"
#include "E3D/Mesh/MeshUtils/TexCoordGen.h"
#include "E3D/Mesh/MeshUtils/TransformMesh.h"
#include "E3D/CompiledMesh/CCompiledMesh.h"
//---------------------------------------------------------------------------
// Materials
//---------------------------------------------------------------------------
#include "E3D/Shaders/CE3D_ShaderExtDB.h"
#include "E3D/Shaders/ShaderInstructions/CE3D_ShaderInsts.h"
#include "E3D/Shaders/ShaderDefWarehouse/CE3D_ShaderDefWH.h"
#include "E3D/Shaders/ShaderWarehouse/CE3D_ShaderWH.h"
#include "E3D/Shaders/ShaderParser/CE3D_ShaderParser.h"
#include "E3D/Shaders/ShaderUtils/CE3D_ShaderUtils.h"
#include "E3D/Materials/MipMapWH.h"
#include "E3D/Materials/TexObjWH.h"
//---------------------------------------------------------------------------
extern	CE3D_Renderer *gpoE3DRenderer;
//---------------------------------------------------------------------------

//## end module%3C1BF3280328.includes

//## begin module%3C1BF3280328.additionalDeclarations preserve=yes
//## end module%3C1BF3280328.additionalDeclarations


//## Class: GammaE_E3D%3C1BF3280328
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class GammaE_E3D 
{
  public:
  protected:
  private:
  private: //## implementation
};

// Class GammaE_E3D 

//## begin module%3C1BF3280328.epilog preserve=yes
//## end module%3C1BF3280328.epilog


#endif
