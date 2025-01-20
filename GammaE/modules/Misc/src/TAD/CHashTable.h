//## begin module%3BD351ED02AC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD351ED02AC.cm

//## begin module%3BD351ED02AC.cp preserve=no
//## end module%3BD351ED02AC.cp

//## Module: CHashTable%3BD351ED02AC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\TAD\CHashTable.h

#ifndef CHashTable_h
#define CHashTable_h 1

//## begin module%3BD351ED02AC.additionalIncludes preserve=no
//## end module%3BD351ED02AC.additionalIncludes

//## begin module%3BD351ED02AC.includes preserve=yes
//## end module%3BD351ED02AC.includes

// CLookupArray
#include "Misc\TAD\CLookupArray.h"
//## begin module%3BD351ED02AC.additionalDeclarations preserve=yes
//## end module%3BD351ED02AC.additionalDeclarations


//## begin CHashTable%3BD351ED02AC.preface preserve=yes
//## end CHashTable%3BD351ED02AC.preface

//## Class: CHashTable%3BD351ED02AC
//## Category: Misc::TAD%3BD2D0650185
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHashTable 
{
  //## begin CHashTable%3BD351ED02AC.initialDeclarations preserve=yes
  //## end CHashTable%3BD351ED02AC.initialDeclarations

  public:
    //## Constructors (generated)
      CHashTable();

    //## Destructor (generated)
      ~CHashTable();


    //## Other Operations (specified)
      //## Operation: Init%1003698088
      void Init (int _iRows, int _iCols);

      //## Operation: AddVar%1003698089
      void AddVar (char *_szString, void *_pValue);

      //## Operation: pGetVar%1003698090
      void * pGetVar (char *_szString);

    // Additional Public Declarations
      //## begin CHashTable%3BD351ED02AC.public preserve=yes
      //## end CHashTable%3BD351ED02AC.public

  protected:
    // Data Members for Associations

      //## Association: Misc::TAD::<unnamed>%3BD354570083
      //## Role: CHashTable::Elems%3BD354570143
      //## begin CHashTable::Elems%3BD354570143.role preserve=no  protected: CLookupArray { -> RHAN}
      CLookupArray *Elems;
      //## end CHashTable::Elems%3BD354570143.role

    // Additional Protected Declarations
      //## begin CHashTable%3BD351ED02AC.protected preserve=yes
      //## end CHashTable%3BD351ED02AC.protected

  private:

    //## Other Operations (specified)
      //## Operation: iGetIndex%1003698092
      int iGetIndex (char *_szString);

    // Data Members for Class Attributes

      //## Attribute: iNumCols%3BD357920119
      //## begin CHashTable::iNumCols%3BD357920119.attr preserve=no  private: int {UA} 0
      int iNumCols;
      //## end CHashTable::iNumCols%3BD357920119.attr

    // Additional Private Declarations
      //## begin CHashTable%3BD351ED02AC.private preserve=yes
      //## end CHashTable%3BD351ED02AC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHashTable%3BD351ED02AC.implementation preserve=yes
      //## end CHashTable%3BD351ED02AC.implementation

};

//## begin CHashTable%3BD351ED02AC.postscript preserve=yes
//## end CHashTable%3BD351ED02AC.postscript

// Class CHashTable 

//## begin module%3BD351ED02AC.epilog preserve=yes
//## end module%3BD351ED02AC.epilog


#endif
