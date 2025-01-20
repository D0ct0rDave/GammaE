//## begin module%3C3244E9007E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3244E9007E.cm

//## begin module%3C3244E9007E.cp preserve=no
//## end module%3C3244E9007E.cp

//## Module: MESHUt_BuildNIMesh%3C3244E9007E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Mesh\MeshUtils\MESHUt_BuildNIMesh.h

#ifndef MESHUt_BuildNIMesh_h
#define MESHUt_BuildNIMesh_h 1

//## begin module%3C3244E9007E.additionalIncludes preserve=no
//## end module%3C3244E9007E.additionalIncludes

//## begin module%3C3244E9007E.includes preserve=yes
//## end module%3C3244E9007E.includes

// CMesh
#include "E3D\Mesh\CMesh.h"
//## begin module%3C3244E9007E.additionalDeclarations preserve=yes
//## end module%3C3244E9007E.additionalDeclarations


//## begin MESHUt_BuildNIMesh%3C3244E9007E.preface preserve=yes
//## end MESHUt_BuildNIMesh%3C3244E9007E.preface

//## Class: MESHUt_BuildNIMesh%3C3244E9007E
//## Category: E3D::Mesh::MeshUtils%3A9EC36B001E
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C32493C01FC;CMesh { -> }

class MESHUt_BuildNIMesh 
{
  //## begin MESHUt_BuildNIMesh%3C3244E9007E.initialDeclarations preserve=yes
  //## end MESHUt_BuildNIMesh%3C3244E9007E.initialDeclarations

  public:
    //## Constructors (generated)
      MESHUt_BuildNIMesh();

    //## Destructor (generated)
      ~MESHUt_BuildNIMesh();


    //## Other Operations (specified)
      //## Operation: poBuild%1009920813
      CMesh * poBuild (CMesh* _poMesh);

    // Additional Public Declarations
      //## begin MESHUt_BuildNIMesh%3C3244E9007E.public preserve=yes
      //## end MESHUt_BuildNIMesh%3C3244E9007E.public

  protected:
    // Additional Protected Declarations
      //## begin MESHUt_BuildNIMesh%3C3244E9007E.protected preserve=yes
      //## end MESHUt_BuildNIMesh%3C3244E9007E.protected

  private:
    // Additional Private Declarations
      //## begin MESHUt_BuildNIMesh%3C3244E9007E.private preserve=yes
      //## end MESHUt_BuildNIMesh%3C3244E9007E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin MESHUt_BuildNIMesh%3C3244E9007E.implementation preserve=yes
      //## end MESHUt_BuildNIMesh%3C3244E9007E.implementation

};

//## begin MESHUt_BuildNIMesh%3C3244E9007E.postscript preserve=yes
//## end MESHUt_BuildNIMesh%3C3244E9007E.postscript

// Class MESHUt_BuildNIMesh 

//## begin module%3C3244E9007E.epilog preserve=yes
//## end module%3C3244E9007E.epilog


#endif
