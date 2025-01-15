//## begin module%3C7426A10223.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7426A10223.cm

//## begin module%3C7426A10223.cp preserve=no
//## end module%3C7426A10223.cp

//## Module: CMapEntity%3C7426A10223; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEntity.h

#ifndef CMapEntity_h
#define CMapEntity_h 1

//## begin module%3C7426A10223.additionalIncludes preserve=no
//## end module%3C7426A10223.additionalIncludes

//## begin module%3C7426A10223.includes preserve=yes
//## end module%3C7426A10223.includes

// CMapEntityClass
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntityClass.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C7426A10223.additionalDeclarations preserve=yes
//## end module%3C7426A10223.additionalDeclarations


//## begin CMapEntity%3C7426A10223.preface preserve=yes
//## end CMapEntity%3C7426A10223.preface

//## Class: CMapEntity%3C7426A10223
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CDAFCF10158;GammaE_Math { -> }

class CMapEntity 
{
  //## begin CMapEntity%3C7426A10223.initialDeclarations preserve=yes
  //## end CMapEntity%3C7426A10223.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEntity();

    //## Destructor (generated)
      ~CMapEntity();

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::MapEntity::<unnamed>%3C7429B502A8
      //## Role: CMapEntity::eClass%3C7429B60173
      //## begin CMapEntity::eClass%3C7429B60173.role preserve=no  public: CMapEntityClass { -> VHAN}
      CMapEntityClass eClass;
      //## end CMapEntity::eClass%3C7429B60173.role

    // Additional Public Declarations
      //## begin CMapEntity%3C7426A10223.public preserve=yes
      //## end CMapEntity%3C7426A10223.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEntity%3C7426A10223.protected preserve=yes
      //## end CMapEntity%3C7426A10223.protected

  private:
    // Additional Private Declarations
      //## begin CMapEntity%3C7426A10223.private preserve=yes
      //## end CMapEntity%3C7426A10223.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEntity%3C7426A10223.implementation preserve=yes
      //## end CMapEntity%3C7426A10223.implementation

};

//## begin CMapEntity%3C7426A10223.postscript preserve=yes
//## end CMapEntity%3C7426A10223.postscript

// Class CMapEntity 

//## begin module%3C7426A10223.epilog preserve=yes
//## end module%3C7426A10223.epilog


#endif
