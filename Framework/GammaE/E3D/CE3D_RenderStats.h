//## begin module%3BD71C550305.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD71C550305.cm

//## begin module%3BD71C550305.cp preserve=no
//## end module%3BD71C550305.cp

//## Module: CE3D_RenderStats%3BD71C550305; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\CE3D_RenderStats.h

#ifndef CE3D_RenderStats_h
#define CE3D_RenderStats_h 1

//## begin module%3BD71C550305.additionalIncludes preserve=no
//## end module%3BD71C550305.additionalIncludes

//## begin module%3BD71C550305.includes preserve=yes
//## end module%3BD71C550305.includes

//## begin module%3BD71C550305.additionalDeclarations preserve=yes
//## end module%3BD71C550305.additionalDeclarations


//## begin CE3D_RenderStats%3BD71C550305.preface preserve=yes
//## end CE3D_RenderStats%3BD71C550305.preface

//## Class: CE3D_RenderStats%3BD71C550305
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_RenderStats 
{
  //## begin CE3D_RenderStats%3BD71C550305.initialDeclarations preserve=yes
  //## end CE3D_RenderStats%3BD71C550305.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_RenderStats();

    //## Destructor (generated)
      ~CE3D_RenderStats();

    // Data Members for Class Attributes

      //## Attribute: NumTestedObjs%3BD71C6B031B
      //## begin CE3D_RenderStats::NumTestedObjs%3BD71C6B031B.attr preserve=no  public: int {UA} 0
      int NumTestedObjs;
      //## end CE3D_RenderStats::NumTestedObjs%3BD71C6B031B.attr

      //## Attribute: NumRenderedGObjs%3BD71C70030E
      //## begin CE3D_RenderStats::NumRenderedGObjs%3BD71C70030E.attr preserve=no  public: int {UA} 0
      int NumRenderedGObjs;
      //## end CE3D_RenderStats::NumRenderedGObjs%3BD71C70030E.attr

      //## Attribute: NumCulledObjs%3BD71C790311
      //## begin CE3D_RenderStats::NumCulledObjs%3BD71C790311.attr preserve=no  public: int {UA} 0
      int NumCulledObjs;
      //## end CE3D_RenderStats::NumCulledObjs%3BD71C790311.attr

      //## Attribute: NumRenderedTris%3BD71C7E0386
      //## begin CE3D_RenderStats::NumRenderedTris%3BD71C7E0386.attr preserve=no  public: int {UA} 0
      int NumRenderedTris;
      //## end CE3D_RenderStats::NumRenderedTris%3BD71C7E0386.attr

      //## Attribute: NumRenderedVerts%3BD71C8400F0
      //## begin CE3D_RenderStats::NumRenderedVerts%3BD71C8400F0.attr preserve=no  public: int {UA} 0
      int NumRenderedVerts;
      //## end CE3D_RenderStats::NumRenderedVerts%3BD71C8400F0.attr

      //## Attribute: cDTime%3BD71C89016F
      //## begin CE3D_RenderStats::cDTime%3BD71C89016F.attr preserve=no  public: int {UA} 0
      int cDTime;
      //## end CE3D_RenderStats::cDTime%3BD71C89016F.attr

      //## Attribute: DTimes%3BD71C8E0325
      //## begin CE3D_RenderStats::DTimes%3BD71C8E0325.attr preserve=no  public: float[4] {UA} 
      float DTimes[4];
      //## end CE3D_RenderStats::DTimes%3BD71C8E0325.attr

      //## Attribute: DTime%3BD71C9900AA
      //## begin CE3D_RenderStats::DTime%3BD71C9900AA.attr preserve=no  public: float {UA} 
      float DTime;
      //## end CE3D_RenderStats::DTime%3BD71C9900AA.attr

      //## Attribute: FPS%3BD71C9E0039
      //## begin CE3D_RenderStats::FPS%3BD71C9E0039.attr preserve=no  public: float {UA} 
      float FPS;
      //## end CE3D_RenderStats::FPS%3BD71C9E0039.attr

      //## Attribute: iCurrentFrame%3BD74559010E
      //## begin CE3D_RenderStats::iCurrentFrame%3BD74559010E.attr preserve=no  public: int {UA} 0
      int iCurrentFrame;
      //## end CE3D_RenderStats::iCurrentFrame%3BD74559010E.attr

      //## Attribute: fTotalTime%3BD746960042
      //## begin CE3D_RenderStats::fTotalTime%3BD746960042.attr preserve=no  public: float {UA} 0.0f
      float fTotalTime;
      //## end CE3D_RenderStats::fTotalTime%3BD746960042.attr

    // Additional Public Declarations
      //## begin CE3D_RenderStats%3BD71C550305.public preserve=yes
      //## end CE3D_RenderStats%3BD71C550305.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_RenderStats%3BD71C550305.protected preserve=yes
      //## end CE3D_RenderStats%3BD71C550305.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_RenderStats%3BD71C550305.private preserve=yes
      //## end CE3D_RenderStats%3BD71C550305.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_RenderStats%3BD71C550305.implementation preserve=yes
      //## end CE3D_RenderStats%3BD71C550305.implementation

};

//## begin CE3D_RenderStats%3BD71C550305.postscript preserve=yes
//## end CE3D_RenderStats%3BD71C550305.postscript

// Class CE3D_RenderStats 

//## begin module%3BD71C550305.epilog preserve=yes
//## end module%3BD71C550305.epilog


#endif
