//## begin module%3BD353840026.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD353840026.cm

//## begin module%3BD353840026.cp preserve=no
//## end module%3BD353840026.cp

//## Module: CLookupArray%3BD353840026; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\TAD\CLookupArray.h

#ifndef CLookupArray_h
#define CLookupArray_h 1

//## begin module%3BD353840026.additionalIncludes preserve=no
//## end module%3BD353840026.additionalIncludes

//## begin module%3BD353840026.includes preserve=yes
//## end module%3BD353840026.includes

// CLookupEntry
#include "Misc\TAD\CLookupEntry.h"
//## begin module%3BD353840026.additionalDeclarations preserve=yes
//## end module%3BD353840026.additionalDeclarations


//## begin CLookupArray%3BD353840026.preface preserve=yes
//## end CLookupArray%3BD353840026.preface

//## Class: CLookupArray%3BD353840026
//## Category: Misc::TAD%3BD2D0650185
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLookupArray 
{
  //## begin CLookupArray%3BD353840026.initialDeclarations preserve=yes
  //## end CLookupArray%3BD353840026.initialDeclarations

  public:
    //## Constructors (generated)
      CLookupArray();

    //## Destructor (generated)
      ~CLookupArray();


    //## Other Operations (specified)
      //## Operation: Init%1003698093
      void Init (int _iMaxElems);

      //## Operation: AddVar%1003698094
      int AddVar (char* _szString, void *_pValue);

      //## Operation: pGetVar%1003698095
      void * pGetVar (char* _szString);

    // Data Members for Class Attributes

      //## Attribute: iNumElems%3BD35399038D
      //## begin CLookupArray::iNumElems%3BD35399038D.attr preserve=no  public: int {UA} 0
      int iNumElems;
      //## end CLookupArray::iNumElems%3BD35399038D.attr

      //## Attribute: iMaxElems%3BD354400275
      //## begin CLookupArray::iMaxElems%3BD354400275.attr preserve=no  public: int {UA} 0
      int iMaxElems;
      //## end CLookupArray::iMaxElems%3BD354400275.attr

    // Additional Public Declarations
      //## begin CLookupArray%3BD353840026.public preserve=yes
      //## end CLookupArray%3BD353840026.public

  protected:
    // Data Members for Associations

      //## Association: Misc::TAD::<unnamed>%3BD353A50196
      //## Role: CLookupArray::Elems%3BD353A6006B
      //## begin CLookupArray::Elems%3BD353A6006B.role preserve=no  protected: CLookupEntry { -> RHAN}
      CLookupEntry *Elems;
      //## end CLookupArray::Elems%3BD353A6006B.role

    // Additional Protected Declarations
      //## begin CLookupArray%3BD353840026.protected preserve=yes
      //## end CLookupArray%3BD353840026.protected

  private:
    // Additional Private Declarations
      //## begin CLookupArray%3BD353840026.private preserve=yes
      //## end CLookupArray%3BD353840026.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLookupArray%3BD353840026.implementation preserve=yes
      //## end CLookupArray%3BD353840026.implementation

};

//## begin CLookupArray%3BD353840026.postscript preserve=yes
//## end CLookupArray%3BD353840026.postscript

// Class CLookupArray 

//## begin module%3BD353840026.epilog preserve=yes
//## end module%3BD353840026.epilog


#endif
