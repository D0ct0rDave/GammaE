//## begin module%3BB3A26503DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB3A26503DE.cm

//## begin module%3BB3A26503DE.cp preserve=no
//## end module%3BB3A26503DE.cp

//## Module: CLensFlare_Elem%3BB3A26503DE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\LensFlare\CLensFlare_Elem.h

#ifndef CLensFlare_Elem_h
#define CLensFlare_Elem_h 1

//## begin module%3BB3A26503DE.additionalIncludes preserve=no
//## end module%3BB3A26503DE.additionalIncludes

//## begin module%3BB3A26503DE.includes preserve=yes
//## end module%3BB3A26503DE.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3BB3A26503DE.additionalDeclarations preserve=yes
//## end module%3BB3A26503DE.additionalDeclarations


//## begin CLensFlare_Elem%3BB3A26503DE.preface preserve=yes
//## end CLensFlare_Elem%3BB3A26503DE.preface

//## Class: CLensFlare_Elem%3BB3A26503DE
//## Category: SceneObjects::LensFlare%3BB24FB703B6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1BF3D4019E;GammaE_E3D { -> }

class CLensFlare_Elem 
{
  //## begin CLensFlare_Elem%3BB3A26503DE.initialDeclarations preserve=yes
  //## end CLensFlare_Elem%3BB3A26503DE.initialDeclarations

  public:
    //## Constructors (generated)
      CLensFlare_Elem();

    //## Destructor (generated)
      ~CLensFlare_Elem();

    // Data Members for Class Attributes

      //## Attribute: fSize%3BB3A26C0059
      //## begin CLensFlare_Elem::fSize%3BB3A26C0059.attr preserve=no  public: float {UA} 0.0f
      float fSize;
      //## end CLensFlare_Elem::fSize%3BB3A26C0059.attr

      //## Attribute: fDist%3BB3A2D202B8
      //## begin CLensFlare_Elem::fDist%3BB3A2D202B8.attr preserve=no  public: float {UA} 0.0f
      float fDist;
      //## end CLensFlare_Elem::fDist%3BB3A2D202B8.attr

      //## Attribute: Color%3BB3A273012B
      //## begin CLensFlare_Elem::Color%3BB3A273012B.attr preserve=no  public: CVect4 {UA} 
      CVect4 Color;
      //## end CLensFlare_Elem::Color%3BB3A273012B.attr

      //## Attribute: pMaterial%3BB3AA310320
      //## begin CLensFlare_Elem::pMaterial%3BB3AA310320.attr preserve=no  public: CE3D_Shader * {UA} NULL
      CE3D_Shader *pMaterial;
      //## end CLensFlare_Elem::pMaterial%3BB3AA310320.attr

    // Additional Public Declarations
      //## begin CLensFlare_Elem%3BB3A26503DE.public preserve=yes
      //## end CLensFlare_Elem%3BB3A26503DE.public

  protected:
    // Additional Protected Declarations
      //## begin CLensFlare_Elem%3BB3A26503DE.protected preserve=yes
      //## end CLensFlare_Elem%3BB3A26503DE.protected

  private:
    // Additional Private Declarations
      //## begin CLensFlare_Elem%3BB3A26503DE.private preserve=yes
      //## end CLensFlare_Elem%3BB3A26503DE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLensFlare_Elem%3BB3A26503DE.implementation preserve=yes
      //## end CLensFlare_Elem%3BB3A26503DE.implementation

};

//## begin CLensFlare_Elem%3BB3A26503DE.postscript preserve=yes
//## end CLensFlare_Elem%3BB3A26503DE.postscript

// Class CLensFlare_Elem 

//## begin module%3BB3A26503DE.epilog preserve=yes
//## end module%3BB3A26503DE.epilog


#endif
