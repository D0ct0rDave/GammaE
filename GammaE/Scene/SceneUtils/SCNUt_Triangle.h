//## begin module%3AC229CB01AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC229CB01AE.cm

//## begin module%3AC229CB01AE.cp preserve=no
//## end module%3AC229CB01AE.cp

//## Module: SCNUt_Triangle%3AC229CB01AE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SCNUt_Triangle.h

#ifndef SCNUt_Triangle_h
#define SCNUt_Triangle_h 1

//## begin module%3AC229CB01AE.additionalIncludes preserve=no
//## end module%3AC229CB01AE.additionalIncludes

//## begin module%3AC229CB01AE.includes preserve=yes
//## end module%3AC229CB01AE.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
// SCNUt_ePolyState
#include "Scene\SceneUtils\SCNUt_ePolyState.h"
//## begin module%3AC229CB01AE.additionalDeclarations preserve=yes
//## end module%3AC229CB01AE.additionalDeclarations


//## Class: SCNUt_Triangle%3AC229CB01AE
//## Category: Scene::SceneUtils%3AC22916003C
//## Persistence: Persistent
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BDDF55C0361;GammaE_Math { -> }
//## Uses: <unnamed>%3BE8699C0172;SCNUt_ePolyState { -> }

class SCNUt_Triangle 
{
  public:
    //## Constructors (generated)
      SCNUt_Triangle();

    //## Destructor (generated)
      ~SCNUt_Triangle();

    // Data Members for Class Attributes

      //## Attribute: VXs%3AC229DC026C
      //	// XYZ coordinates
      //## begin SCNUt_Triangle::VXs%3AC229DC026C.attr preserve=no  public: CVect3[3] {UA} 
      CVect3 VXs[3];
      //## end SCNUt_Triangle::VXs%3AC229DC026C.attr

      //## Attribute: UVs%3AC229EC00A0
      //	// UV coordinates
      //## begin SCNUt_Triangle::UVs%3AC229EC00A0.attr preserve=no  public: CVect2[3] {UA} 
      CVect2 UVs[3];
      //## end SCNUt_Triangle::UVs%3AC229EC00A0.attr

      //## Attribute: VCs%3AC22A070384
      //	// VertexColor of the vertex (if any)
      //## begin SCNUt_Triangle::VCs%3AC22A070384.attr preserve=no  public: CVect4[3] {UA} 
      CVect4 VCs[3];
      //## end SCNUt_Triangle::VCs%3AC22A070384.attr

      //## Attribute: VNs%3AC229FA0370
      //	// Vertex normals (if any)
      //## begin SCNUt_Triangle::VNs%3AC229FA0370.attr preserve=no  public: CVect3[3] {UA} 
      CVect3 VNs[3];
      //## end SCNUt_Triangle::VNs%3AC229FA0370.attr

      //## Attribute: Material%3AC22A1901D6
      //## begin SCNUt_Triangle::Material%3AC22A1901D6.attr preserve=no  public: int {UA} 
      int Material;
      //## end SCNUt_Triangle::Material%3AC22A1901D6.attr

      //## Attribute: Side%3BE8698901E3
      //## begin SCNUt_Triangle::Side%3BE8698901E3.attr preserve=no  public: SCNUt_ePolyState {UA} 
      SCNUt_ePolyState Side;
      //## end SCNUt_Triangle::Side%3BE8698901E3.attr

      //## Attribute: VertexSide%3BE8698F00B5
      //## begin SCNUt_Triangle::VertexSide%3BE8698F00B5.attr preserve=no  public: SCNUt_ePolyState[3] {UA} 
      SCNUt_ePolyState VertexSide[3];
      //## end SCNUt_Triangle::VertexSide%3BE8698F00B5.attr

      //## Attribute: DProds%3BE86995023A
      //## begin SCNUt_Triangle::DProds%3BE86995023A.attr preserve=no  public: float[3] {UA} 
      float DProds[3];
      //## end SCNUt_Triangle::DProds%3BE86995023A.attr

      //## Attribute: iFlags%3C0046B10258
      //## begin SCNUt_Triangle::iFlags%3C0046B10258.attr preserve=no  public: unsigned int {UA} 0
      unsigned int iFlags;
      //## end SCNUt_Triangle::iFlags%3C0046B10258.attr

  protected:
  private:
  private: //## implementation
};

// Class SCNUt_Triangle 

//## begin module%3AC229CB01AE.epilog preserve=yes
//## end module%3AC229CB01AE.epilog


#endif
