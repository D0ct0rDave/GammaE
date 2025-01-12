//## begin module%3BD358A00059.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD358A00059.cm

//## begin module%3BD358A00059.cp preserve=no
//## end module%3BD358A00059.cp

//## Module: CE3D_ShaderExtDB%3BD358A00059; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\CE3D_ShaderExtDB.h

#ifndef CE3D_ShaderExtDB_h
#define CE3D_ShaderExtDB_h 1

//## begin module%3BD358A00059.additionalIncludes preserve=no
//## end module%3BD358A00059.additionalIncludes

//## begin module%3BD358A00059.includes preserve=yes
#include "Misc/GammaE_Misc.h"
//## end module%3BD358A00059.includes

// GammaE_Misc
#include "Misc\GammaE_Misc.h"
//## begin module%3BD358A00059.additionalDeclarations preserve=yes
//## end module%3BD358A00059.additionalDeclarations


//## begin CE3D_ShaderExtDB%3BD358A00059.preface preserve=yes
//## end CE3D_ShaderExtDB%3BD358A00059.preface

//## Class: CE3D_ShaderExtDB%3BD358A00059
//## Category: E3D::Shaders%3BD3587E014A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6E6F510348;GammaE_Misc { -> }

class CE3D_ShaderExtDB 
{
  //## begin CE3D_ShaderExtDB%3BD358A00059.initialDeclarations preserve=yes
  //## end CE3D_ShaderExtDB%3BD358A00059.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderExtDB();

    //## Destructor (generated)
      ~CE3D_ShaderExtDB();


    //## Other Operations (specified)
      //## Operation: AddExtension%1003698097
      static void AddExtension (char *_szExtensionName, void *_pExtensionFunc);

      //## Operation: pGetExtension%1003698098
      static void * pGetExtension (char *_szExtensionName);

    // Additional Public Declarations
      //## begin CE3D_ShaderExtDB%3BD358A00059.public preserve=yes
      //## end CE3D_ShaderExtDB%3BD358A00059.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShaderExtDB%3BD358A00059.protected preserve=yes
      //## end CE3D_ShaderExtDB%3BD358A00059.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oExtDB%3BD3590702F6
      //## begin CE3D_ShaderExtDB::oExtDB%3BD3590702F6.attr preserve=no  private: static CHashTable {UA} 
      static CHashTable oExtDB;
      //## end CE3D_ShaderExtDB::oExtDB%3BD3590702F6.attr

    // Additional Private Declarations
      //## begin CE3D_ShaderExtDB%3BD358A00059.private preserve=yes
      //## end CE3D_ShaderExtDB%3BD358A00059.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderExtDB%3BD358A00059.implementation preserve=yes
      //## end CE3D_ShaderExtDB%3BD358A00059.implementation

};

//## begin CE3D_ShaderExtDB%3BD358A00059.postscript preserve=yes
//## end CE3D_ShaderExtDB%3BD358A00059.postscript

// Class CE3D_ShaderExtDB 

//## begin module%3BD358A00059.epilog preserve=yes
//## end module%3BD358A00059.epilog


#endif
