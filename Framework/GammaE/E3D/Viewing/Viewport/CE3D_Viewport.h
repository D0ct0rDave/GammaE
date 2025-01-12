//## begin module%3A9AD44A035C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD44A035C.cm

//## begin module%3A9AD44A035C.cp preserve=no
//## end module%3A9AD44A035C.cp

//## Module: CE3D_Viewport%3A9AD44A035C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Viewing\Viewport\CE3D_Viewport.h

#ifndef CE3D_Viewport_h
#define CE3D_Viewport_h 1

//## begin module%3A9AD44A035C.additionalIncludes preserve=no
//## end module%3A9AD44A035C.additionalIncludes

//## begin module%3A9AD44A035C.includes preserve=yes
//## end module%3A9AD44A035C.includes

//## begin module%3A9AD44A035C.additionalDeclarations preserve=yes
//## end module%3A9AD44A035C.additionalDeclarations


//## begin CE3D_Viewport%3A9AD44A035C.preface preserve=yes
//## end CE3D_Viewport%3A9AD44A035C.preface

//## Class: CE3D_Viewport%3A9AD44A035C
//## Category: E3D::Viewing::Viewport%3A9AD4440398
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_Viewport 
{
  //## begin CE3D_Viewport%3A9AD44A035C.initialDeclarations preserve=yes
  //## end CE3D_Viewport%3A9AD44A035C.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_Viewport();

    //## Destructor (generated)
      ~CE3D_Viewport();


    //## Other Operations (specified)
      //## Operation: SetViewport%983219137
      void SetViewport (float cX, float cY, float TX, float TY);

    // Data Members for Class Attributes

      //## Attribute: ScrCX%3A9AD4570032
      //## begin CE3D_Viewport::ScrCX%3A9AD4570032.attr preserve=no  public: float {UA} 0
      float ScrCX;
      //## end CE3D_Viewport::ScrCX%3A9AD4570032.attr

      //## Attribute: ScrCY%3A9AD45C0366
      //## begin CE3D_Viewport::ScrCY%3A9AD45C0366.attr preserve=no  public: float {UA} 0
      float ScrCY;
      //## end CE3D_Viewport::ScrCY%3A9AD45C0366.attr

      //## Attribute: ScrTX%3A9AD462005A
      //## begin CE3D_Viewport::ScrTX%3A9AD462005A.attr preserve=no  public: float {UA} 0
      float ScrTX;
      //## end CE3D_Viewport::ScrTX%3A9AD462005A.attr

      //## Attribute: ScrTY%3A9AD46700FA
      //## begin CE3D_Viewport::ScrTY%3A9AD46700FA.attr preserve=no  public: float {UA} 0
      float ScrTY;
      //## end CE3D_Viewport::ScrTY%3A9AD46700FA.attr

    // Additional Public Declarations
      //## begin CE3D_Viewport%3A9AD44A035C.public preserve=yes
      //## end CE3D_Viewport%3A9AD44A035C.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_Viewport%3A9AD44A035C.protected preserve=yes
      //## end CE3D_Viewport%3A9AD44A035C.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_Viewport%3A9AD44A035C.private preserve=yes
      //## end CE3D_Viewport%3A9AD44A035C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_Viewport%3A9AD44A035C.implementation preserve=yes
      //## end CE3D_Viewport%3A9AD44A035C.implementation

};

//## begin CE3D_Viewport%3A9AD44A035C.postscript preserve=yes
//## end CE3D_Viewport%3A9AD44A035C.postscript

// Class CE3D_Viewport 

//## begin module%3A9AD44A035C.epilog preserve=yes
//## end module%3A9AD44A035C.epilog


#endif
