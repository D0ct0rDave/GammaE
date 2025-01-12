//## begin module%3C50874F011A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C50874F011A.cm

//## begin module%3C50874F011A.cp preserve=no
//## end module%3C50874F011A.cp

//## Module: CCompiledMesh%3C50874F011A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\CompiledMesh\CCompiledMesh.h

#ifndef CCompiledMesh_h
#define CCompiledMesh_h 1

//## begin module%3C50874F011A.additionalIncludes preserve=no
//## end module%3C50874F011A.additionalIncludes

//## begin module%3C50874F011A.includes preserve=yes
//## end module%3C50874F011A.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
// CMesh
#include "E3D\Mesh\CMesh.h"
//## begin module%3C50874F011A.additionalDeclarations preserve=yes
//## end module%3C50874F011A.additionalDeclarations


//## begin CCompiledMesh%3C50874F011A.preface preserve=yes
//## end CCompiledMesh%3C50874F011A.preface

//## Class: CCompiledMesh%3C50874F011A
//## Category: E3D::CompiledMesh%3C5087130178
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C5087BA0363;CGraphBV { -> }
//## Uses: <unnamed>%3C5096490290;CMesh { -> }

class CCompiledMesh 
{
  //## begin CCompiledMesh%3C50874F011A.initialDeclarations preserve=yes
  //## end CCompiledMesh%3C50874F011A.initialDeclarations

  public:
    //## Constructors (generated)
      CCompiledMesh();

    //## Destructor (generated)
      ~CCompiledMesh();


    //## Other Operations (specified)
      //## Operation: poGetBV%1011911192
      CGraphBV * poGetBV ();

      //## Operation: poCopyBV%1011911193
      void poCopyBV (CGraphBV *_poBV);

    // Data Members for Class Attributes

      //## Attribute: iID%3C50878401AD
      //## begin CCompiledMesh::iID%3C50878401AD.attr preserve=no  public: int {UA} -1
      int iID;
      //## end CCompiledMesh::iID%3C50878401AD.attr

      //## Attribute: usNumVerts%3C508BCF02CF
      //## begin CCompiledMesh::usNumVerts%3C508BCF02CF.attr preserve=no  public: unsigned short {UA} 0
      unsigned short usNumVerts;
      //## end CCompiledMesh::usNumVerts%3C508BCF02CF.attr

      //## Attribute: usNumPrims%3C508BDB01D2
      //## begin CCompiledMesh::usNumPrims%3C508BDB01D2.attr preserve=no  public: unsigned short {UA} 0
      unsigned short usNumPrims;
      //## end CCompiledMesh::usNumPrims%3C508BDB01D2.attr

      //## Attribute: eMeshType%3C508BEF0004
      //## begin CCompiledMesh::eMeshType%3C508BEF0004.attr preserve=no  public: EMeshType {UA} E3D_MESH_NONE
      EMeshType eMeshType;
      //## end CCompiledMesh::eMeshType%3C508BEF0004.attr

    // Additional Public Declarations
      //## begin CCompiledMesh%3C50874F011A.public preserve=yes
      //## end CCompiledMesh%3C50874F011A.public

  protected:
    // Additional Protected Declarations
      //## begin CCompiledMesh%3C50874F011A.protected preserve=yes
      //## end CCompiledMesh%3C50874F011A.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poBV%3C50884E012B
      //## begin CCompiledMesh::poBV%3C50884E012B.attr preserve=no  private: CGraphBV * {UA} NULL
      CGraphBV *poBV;
      //## end CCompiledMesh::poBV%3C50884E012B.attr

    // Additional Private Declarations
      //## begin CCompiledMesh%3C50874F011A.private preserve=yes
      //## end CCompiledMesh%3C50874F011A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCompiledMesh%3C50874F011A.implementation preserve=yes
      //## end CCompiledMesh%3C50874F011A.implementation

};

//## begin CCompiledMesh%3C50874F011A.postscript preserve=yes
//## end CCompiledMesh%3C50874F011A.postscript

// Class CCompiledMesh 


//## Other Operations (inline)
inline CGraphBV * CCompiledMesh::poGetBV ()
{
  //## begin CCompiledMesh::poGetBV%1011911192.body preserve=yes
	return ( poBV);
  //## end CCompiledMesh::poGetBV%1011911192.body
}

//## begin module%3C50874F011A.epilog preserve=yes
//## end module%3C50874F011A.epilog


#endif
