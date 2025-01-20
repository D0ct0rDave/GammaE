//## begin module%3B90D6180001.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B90D6180001.cm

//## begin module%3B90D6180001.cp preserve=no
//## end module%3B90D6180001.cp

//## Module: C3DSaver%3B90D6180001; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Savers\C3DSaver.h

#ifndef C3DSaver_h
#define C3DSaver_h 1

//## begin module%3B90D6180001.additionalIncludes preserve=no
//## end module%3B90D6180001.additionalIncludes

//## begin module%3B90D6180001.includes preserve=yes
//## end module%3B90D6180001.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3B90D6180001.additionalDeclarations preserve=yes
//## end module%3B90D6180001.additionalDeclarations


//## begin C3DSaver%3B90D6180001.preface preserve=yes
//## end C3DSaver%3B90D6180001.preface

//## Class: C3DSaver%3B90D6180001
//## Category: Scene::3D_Savers%3B90D396001B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1BF3F2038C;GammaE_E3D { -> }
//## Uses: <unnamed>%3CB8503E0381;CObject3D { -> }

class C3DSaver 
{
  //## begin C3DSaver%3B90D6180001.initialDeclarations preserve=yes
  //## end C3DSaver%3B90D6180001.initialDeclarations

  public:
    //## Constructors (generated)
      C3DSaver();

    //## Destructor (generated)
      ~C3DSaver();


    //## Other Operations (specified)
      //## Operation: iSave%999339046
      virtual int iSave (char *_Filename, CObject3D* _pObj) = 0;

    // Additional Public Declarations
      //## begin C3DSaver%3B90D6180001.public preserve=yes
      //## end C3DSaver%3B90D6180001.public

  protected:
    // Additional Protected Declarations
      //## begin C3DSaver%3B90D6180001.protected preserve=yes
      //## end C3DSaver%3B90D6180001.protected

  private:
    // Additional Private Declarations
      //## begin C3DSaver%3B90D6180001.private preserve=yes
      //## end C3DSaver%3B90D6180001.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin C3DSaver%3B90D6180001.implementation preserve=yes
      //## end C3DSaver%3B90D6180001.implementation

};

//## begin C3DSaver%3B90D6180001.postscript preserve=yes
//## end C3DSaver%3B90D6180001.postscript

// Class C3DSaver 

//## begin module%3B90D6180001.epilog preserve=yes
//## end module%3B90D6180001.epilog


#endif
