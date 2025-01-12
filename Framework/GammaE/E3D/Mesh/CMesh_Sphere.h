//## begin module%3CCD399302BD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CCD399302BD.cm

//## begin module%3CCD399302BD.cp preserve=no
//## end module%3CCD399302BD.cp

//## Module: CMesh_Sphere%3CCD399302BD; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Mesh\CMesh_Sphere.h

#ifndef CMesh_Sphere_h
#define CMesh_Sphere_h 1

//## begin module%3CCD399302BD.additionalIncludes preserve=no
//## end module%3CCD399302BD.additionalIncludes

//## begin module%3CCD399302BD.includes preserve=yes
//## end module%3CCD399302BD.includes

// CMesh
#include "E3D\Mesh\CMesh.h"
//## begin module%3CCD399302BD.additionalDeclarations preserve=yes
//## end module%3CCD399302BD.additionalDeclarations


//## begin CMesh_Sphere%3CCD399302BD.preface preserve=yes
//## end CMesh_Sphere%3CCD399302BD.preface

//## Class: CMesh_Sphere%3CCD399302BD
//## Category: E3D::Mesh%3A9EC33D0334
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMesh_Sphere : public CMesh  //## Inherits: <unnamed>%3CCD39A002B1
{
  //## begin CMesh_Sphere%3CCD399302BD.initialDeclarations preserve=yes
  //## end CMesh_Sphere%3CCD399302BD.initialDeclarations

  public:
    //## Constructors (generated)
      CMesh_Sphere();

    //## Constructors (specified)
      //## Operation: CMesh_Sphere%1020082679
      CMesh_Sphere (int _iNumSlices, float _fRadius);

    //## Destructor (generated)
      ~CMesh_Sphere();

    // Additional Public Declarations
      //## begin CMesh_Sphere%3CCD399302BD.public preserve=yes
      //## end CMesh_Sphere%3CCD399302BD.public

  protected:

    //## Other Operations (specified)
      //## Operation: Init%1020082680
      void Init (int _iNumSlices, float _fRadius);

    // Additional Protected Declarations
      //## begin CMesh_Sphere%3CCD399302BD.protected preserve=yes
      //## end CMesh_Sphere%3CCD399302BD.protected

  private:
    // Additional Private Declarations
      //## begin CMesh_Sphere%3CCD399302BD.private preserve=yes
      //## end CMesh_Sphere%3CCD399302BD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMesh_Sphere%3CCD399302BD.implementation preserve=yes
      //## end CMesh_Sphere%3CCD399302BD.implementation

};

//## begin CMesh_Sphere%3CCD399302BD.postscript preserve=yes
//## end CMesh_Sphere%3CCD399302BD.postscript

// Class CMesh_Sphere 

//## begin module%3CCD399302BD.epilog preserve=yes
//## end module%3CCD399302BD.epilog


#endif
