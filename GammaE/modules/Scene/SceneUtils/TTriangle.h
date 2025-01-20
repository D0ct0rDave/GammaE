//## begin module%3AC229CB01AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC229CB01AE.cm

//## begin module%3AC229CB01AE.cp preserve=no
//## end module%3AC229CB01AE.cp

//## Module: TTriangle%3AC229CB01AE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\TTriangle.h

#ifndef TTriangle_h
#define TTriangle_h 1

//## begin module%3AC229CB01AE.additionalIncludes preserve=no
//## end module%3AC229CB01AE.additionalIncludes

//## begin module%3AC229CB01AE.includes preserve=yes
//## end module%3AC229CB01AE.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3AC229CB01AE.additionalDeclarations preserve=yes
enum ePolyState
{
	POLYSTATE_NONE		= 0,
	POLYSTATE_FRONT		= 1,			// Polygon frontside the plane
	POLYSTATE_BACK		= 2,			// Polygon backside the plane
	POLYSTATE_OVER		= 3,			// Polygon over the plane
	POLYSTATE_ONEOVER	= 4,			// 1 vertex over the plane  (tris)
	POLYSTATE_TWOOVER	= 5,			// 2 vertexs over the plane (tris)
	POLYSTATE_CROSS1	= 6,			// The polygon crosses the plane
	POLYSTATE_CROSS2	= 7,			// The polygon crosses the plane
};
//## end module%3AC229CB01AE.additionalDeclarations


//## Class: TTriangle%3AC229CB01AE
//## Category: Scene::SceneUtils%3AC22916003C
//## Persistence: Persistent
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AC22D9502A8;GammaE_Math { -> }

class TTriangle 
{
  public:
    //## Constructors (generated)
      TTriangle();

    //## Destructor (generated)
      ~TTriangle();

    // Data Members for Class Attributes

      //## Attribute: VXs%3AC229DC026C
      //	// XYZ coordinates
      //## begin TTriangle::VXs%3AC229DC026C.attr preserve=no  public: CVect3[3] {UA} 
      CVect3 VXs[3];
      //## end TTriangle::VXs%3AC229DC026C.attr

      //## Attribute: UVs%3AC229EC00A0
      //	// UV coordinates
      //## begin TTriangle::UVs%3AC229EC00A0.attr preserve=no  public: CVect2[3] {UA} 
      CVect2 UVs[3];
      //## end TTriangle::UVs%3AC229EC00A0.attr

      //## Attribute: VCs%3AC22A070384
      //	// VertexColor of the vertex (if any)
      //## begin TTriangle::VCs%3AC22A070384.attr preserve=no  public: CVect4[3] {UA} 
      CVect4 VCs[3];
      //## end TTriangle::VCs%3AC22A070384.attr

      //## Attribute: VNs%3AC229FA0370
      //	// Vertex normals (if any)
      //## begin TTriangle::VNs%3AC229FA0370.attr preserve=no  public: CVect3[3] {UA} 
      CVect3 VNs[3];
      //## end TTriangle::VNs%3AC229FA0370.attr

      //## Attribute: Material%3AC22A1901D6
      //## begin TTriangle::Material%3AC22A1901D6.attr preserve=no  public: int {UA} 
      int Material;
      //## end TTriangle::Material%3AC22A1901D6.attr

      //## Attribute: Side%3AC22A4C0154
      //	// Side of the triangle respect the plane
      //## begin TTriangle::Side%3AC22A4C0154.attr preserve=no  public: ePolyState {UA} 
      ePolyState Side;
      //## end TTriangle::Side%3AC22A4C0154.attr

      //## Attribute: VertexSide%3AC22A6C0244
      //	// Side of this vertex respect the plane
      //## begin TTriangle::VertexSide%3AC22A6C0244.attr preserve=no  public: ePolyState[3] {UA} 
      ePolyState VertexSide[3];
      //## end TTriangle::VertexSide%3AC22A6C0244.attr

      //## Attribute: DProds%3AC22A770190
      //	// Dot product of the vertex and the plane
      //## begin TTriangle::DProds%3AC22A770190.attr preserve=no  public: float[3] {UA} 
      float DProds[3];
      //## end TTriangle::DProds%3AC22A770190.attr

  protected:
  private:
  private: //## implementation
};

// Class TTriangle 

//## begin module%3AC229CB01AE.epilog preserve=yes
//## end module%3AC229CB01AE.epilog


#endif
