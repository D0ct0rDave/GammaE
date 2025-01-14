//## begin module%3CA0F4370168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CA0F4370168.cm

//## begin module%3CA0F4370168.cp preserve=no
//## end module%3CA0F4370168.cp

//## Module: CQLEMapScn%3CA0F4370168; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\QLEMap\CQLEMapScn.h

#ifndef CQLEMapScn_h
#define CQLEMapScn_h 1

//## begin module%3CA0F4370168.additionalIncludes preserve=no
//## end module%3CA0F4370168.additionalIncludes

//## begin module%3CA0F4370168.includes preserve=yes
//## end module%3CA0F4370168.includes

// CQLEObject
#include "Tools\GEMapCompiler\QLEMap\CQLEObject.h"
// CMapScene
#include "Tools\GEMapCompiler\MapData\CMapScene.h"
//## begin module%3CA0F4370168.additionalDeclarations preserve=yes
//## end module%3CA0F4370168.additionalDeclarations


//## begin CQLEMapScn%3CA0F4370168.preface preserve=yes
//## end CQLEMapScn%3CA0F4370168.preface

//## Class: CQLEMapScn%3CA0F4370168
//## Category: Tools::GEMapCompiler::QLEMap%3CA0F45D0394
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CQLEMapScn : public CMapScene  //## Inherits: <unnamed>%3CA0F43F03A5
{
  //## begin CQLEMapScn%3CA0F4370168.initialDeclarations preserve=yes
  //## end CQLEMapScn%3CA0F4370168.initialDeclarations

  public:
    //## Constructors (generated)
      CQLEMapScn();

    //## Destructor (generated)
      ~CQLEMapScn();


    //## Other Operations (specified)
      //## Operation: AddObject%1017256160
      void AddObject (CQLEObject* _poObj);

    // Data Members for Class Attributes

      //## Attribute: iNumObjs%3CA0F44200D8
      //## begin CQLEMapScn::iNumObjs%3CA0F44200D8.attr preserve=no  public: int {UA} 0
      int iNumObjs;
      //## end CQLEMapScn::iNumObjs%3CA0F44200D8.attr

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::QLEMap::<unnamed>%3CA0F56A0015
      //## Role: CQLEMapScn::poQLEObj%3CA0F56A02AB
      //## begin CQLEMapScn::poQLEObj%3CA0F56A02AB.role preserve=no  public: CQLEObject { -> RHAN}
      CQLEObject* *poQLEObj;
      //## end CQLEMapScn::poQLEObj%3CA0F56A02AB.role

    // Additional Public Declarations
      //## begin CQLEMapScn%3CA0F4370168.public preserve=yes
      //## end CQLEMapScn%3CA0F4370168.public

  protected:
    // Additional Protected Declarations
      //## begin CQLEMapScn%3CA0F4370168.protected preserve=yes
      //## end CQLEMapScn%3CA0F4370168.protected

  private:
    // Additional Private Declarations
      //## begin CQLEMapScn%3CA0F4370168.private preserve=yes
      //## end CQLEMapScn%3CA0F4370168.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CQLEMapScn%3CA0F4370168.implementation preserve=yes
      //## end CQLEMapScn%3CA0F4370168.implementation

};

//## begin CQLEMapScn%3CA0F4370168.postscript preserve=yes
//## end CQLEMapScn%3CA0F4370168.postscript

// Class CQLEMapScn 

//## begin module%3CA0F4370168.epilog preserve=yes
//## end module%3CA0F4370168.epilog


#endif
