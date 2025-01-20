//## begin module%3AA40E33028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AA40E33028A.cm

//## begin module%3AA40E33028A.cp preserve=no
//## end module%3AA40E33028A.cp

//## Module: CE3D_RenderVars%3AA40E33028A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\RenderVars\CE3D_RenderVars.h

#ifndef CE3D_RenderVars_h
#define CE3D_RenderVars_h 1

//## begin module%3AA40E33028A.additionalIncludes preserve=no
//## end module%3AA40E33028A.additionalIncludes

//## begin module%3AA40E33028A.includes preserve=yes
//## end module%3AA40E33028A.includes

// GammaE_Misc
#include "Misc\GammaE_Misc.h"
//## begin module%3AA40E33028A.additionalDeclarations preserve=yes
//## end module%3AA40E33028A.additionalDeclarations


//## begin CE3D_RenderVars%3AA40E33028A.preface preserve=yes
//## end CE3D_RenderVars%3AA40E33028A.preface

//## Class: CE3D_RenderVars%3AA40E33028A
//## Category: E3D::RenderVars%3AA40E2A0320
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6E68D2021B;GammaE_Misc { -> }

class CE3D_RenderVars 
{
  //## begin CE3D_RenderVars%3AA40E33028A.initialDeclarations preserve=yes
  //## end CE3D_RenderVars%3AA40E33028A.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_RenderVars();

    //## Destructor (generated)
      ~CE3D_RenderVars();


    //## Other Operations (specified)
      //## Operation: AddRenderVar%995233492
      static void AddRenderVar (char *_szVariable, void *_pValue);

      //## Operation: pGetRenderVar%995233493
      static void * pGetRenderVar (char *_szVariable);

    // Additional Public Declarations
      //## begin CE3D_RenderVars%3AA40E33028A.public preserve=yes
      //## end CE3D_RenderVars%3AA40E33028A.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_RenderVars%3AA40E33028A.protected preserve=yes
      //## end CE3D_RenderVars%3AA40E33028A.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oVarTable%3C6E68B9012E
      //## begin CE3D_RenderVars::oVarTable%3C6E68B9012E.attr preserve=no  private: static CHashTable {UA} 
      static CHashTable oVarTable;
      //## end CE3D_RenderVars::oVarTable%3C6E68B9012E.attr

    // Additional Private Declarations
      //## begin CE3D_RenderVars%3AA40E33028A.private preserve=yes
      //## end CE3D_RenderVars%3AA40E33028A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_RenderVars%3AA40E33028A.implementation preserve=yes
      //## end CE3D_RenderVars%3AA40E33028A.implementation

};

//## begin CE3D_RenderVars%3AA40E33028A.postscript preserve=yes
//## end CE3D_RenderVars%3AA40E33028A.postscript

// Class CE3D_RenderVars 

//## begin module%3AA40E33028A.epilog preserve=yes
//## end module%3AA40E33028A.epilog


#endif
