//## begin module%3C72CDE90113.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C72CDE90113.cm

//## begin module%3C72CDE90113.cp preserve=no
//## end module%3C72CDE90113.cp

//## Module: CCorona%3C72CDE90113; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\CoronaMgr\CCorona.h

#ifndef CCorona_h
#define CCorona_h 1

//## begin module%3C72CDE90113.additionalIncludes preserve=no
//## end module%3C72CDE90113.additionalIncludes

//## begin module%3C72CDE90113.includes preserve=yes
//## end module%3C72CDE90113.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3C72CDE90113.additionalDeclarations preserve=yes
//## end module%3C72CDE90113.additionalDeclarations


//## begin CCorona%3C72CDE90113.preface preserve=yes
//## end CCorona%3C72CDE90113.preface

//## Class: CCorona%3C72CDE90113
//## Category: SceneObjects::CoronaMgr%3C72C8690318
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C72D5D701F9;GammaE_E3D { -> }

class CCorona 
{
  //## begin CCorona%3C72CDE90113.initialDeclarations preserve=yes
  //## end CCorona%3C72CDE90113.initialDeclarations

  public:
    //## Constructors (generated)
      CCorona();

    //## Destructor (generated)
      ~CCorona();

    // Data Members for Class Attributes

      //## Attribute: oColor%3C72CDF503C4
      //## begin CCorona::oColor%3C72CDF503C4.attr preserve=no  public: TFColor {UA} 
      TFColor oColor;
      //## end CCorona::oColor%3C72CDF503C4.attr

      //## Attribute: poMat%3C72CE0003E7
      //## begin CCorona::poMat%3C72CE0003E7.attr preserve=no  public: CE3D_Shader* {UA} 
      CE3D_Shader* poMat;
      //## end CCorona::poMat%3C72CE0003E7.attr

      //## Attribute: oPos%3C72CE060288
      //## begin CCorona::oPos%3C72CE060288.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CCorona::oPos%3C72CE060288.attr

      //## Attribute: fXYSize%3C72CE0E035B
      //## begin CCorona::fXYSize%3C72CE0E035B.attr preserve=no  public: float {UA} 
      float fXYSize;
      //## end CCorona::fXYSize%3C72CE0E035B.attr

    // Additional Public Declarations
      //## begin CCorona%3C72CDE90113.public preserve=yes
      //## end CCorona%3C72CDE90113.public

  protected:
    // Additional Protected Declarations
      //## begin CCorona%3C72CDE90113.protected preserve=yes
      //## end CCorona%3C72CDE90113.protected

  private:
    // Additional Private Declarations
      //## begin CCorona%3C72CDE90113.private preserve=yes
      //## end CCorona%3C72CDE90113.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCorona%3C72CDE90113.implementation preserve=yes
      //## end CCorona%3C72CDE90113.implementation

};

//## begin CCorona%3C72CDE90113.postscript preserve=yes
//## end CCorona%3C72CDE90113.postscript

// Class CCorona 

//## begin module%3C72CDE90113.epilog preserve=yes
//## end module%3C72CDE90113.epilog


#endif
