//## begin module%3B54BA61015E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B54BA61015E.cm

//## begin module%3B54BA61015E.cp preserve=no
//## end module%3B54BA61015E.cp

//## Module: CLODSelector_Array%3B54BA61015E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Terrain\TerrainMath\CLODSelector_Array.h

#ifndef CLODSelector_Array_h
#define CLODSelector_Array_h 1

//## begin module%3B54BA61015E.additionalIncludes preserve=no
//## end module%3B54BA61015E.additionalIncludes

//## begin module%3B54BA61015E.includes preserve=yes
//## end module%3B54BA61015E.includes

// CLODSelector
#include "Terrain\TerrainMath\CLODSelector.h"
//## begin module%3B54BA61015E.additionalDeclarations preserve=yes
//## end module%3B54BA61015E.additionalDeclarations


//## begin CLODSelector_Array%3B54BA61015E.preface preserve=yes
//## end CLODSelector_Array%3B54BA61015E.preface

//## Class: CLODSelector_Array%3B54BA61015E
//## Category: Terrain::TerrainMath%3B54BA370226
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLODSelector_Array : public CLODSelector  //## Inherits: <unnamed>%3B54BB130212
{
  //## begin CLODSelector_Array%3B54BA61015E.initialDeclarations preserve=yes
  //## end CLODSelector_Array%3B54BA61015E.initialDeclarations

  public:
    //## Constructors (generated)
      CLODSelector_Array();

    //## Destructor (generated)
      ~CLODSelector_Array();


    //## Other Operations (specified)
      //## Operation: GetLOD%995406157
      virtual float GetLOD (float fDist);

      //## Operation: AddLOD%995406159
      void AddLOD (float fLODDist);

      //## Operation: Init%995406160
      void Init (int _MaxLODs);

    // Additional Public Declarations
      //## begin CLODSelector_Array%3B54BA61015E.public preserve=yes
      //## end CLODSelector_Array%3B54BA61015E.public

  protected:
    // Additional Protected Declarations
      //## begin CLODSelector_Array%3B54BA61015E.protected preserve=yes
      //## end CLODSelector_Array%3B54BA61015E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: LODArray%3B54BA84030C
      //## begin CLODSelector_Array::LODArray%3B54BA84030C.attr preserve=no  private: float * {UA} 0
      float *LODArray;
      //## end CLODSelector_Array::LODArray%3B54BA84030C.attr

      //## Attribute: iMaxLODs%3B54BA9E0104
      //## begin CLODSelector_Array::iMaxLODs%3B54BA9E0104.attr preserve=no  private: int {UA} 0
      int iMaxLODs;
      //## end CLODSelector_Array::iMaxLODs%3B54BA9E0104.attr

      //## Attribute: iNumLODs%3B54BE230172
      //## begin CLODSelector_Array::iNumLODs%3B54BE230172.attr preserve=no  private: int {UA} 0
      int iNumLODs;
      //## end CLODSelector_Array::iNumLODs%3B54BE230172.attr

    // Additional Private Declarations
      //## begin CLODSelector_Array%3B54BA61015E.private preserve=yes
      //## end CLODSelector_Array%3B54BA61015E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLODSelector_Array%3B54BA61015E.implementation preserve=yes
      //## end CLODSelector_Array%3B54BA61015E.implementation

};

//## begin CLODSelector_Array%3B54BA61015E.postscript preserve=yes
//## end CLODSelector_Array%3B54BA61015E.postscript

// Class CLODSelector_Array 

//## begin module%3B54BA61015E.epilog preserve=yes
//## end module%3B54BA61015E.epilog


#endif
