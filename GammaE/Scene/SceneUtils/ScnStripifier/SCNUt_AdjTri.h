//## begin module%3C321C5F038F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C321C5F038F.cm

//## begin module%3C321C5F038F.cp preserve=no
//## end module%3C321C5F038F.cp

//## Module: SCNUt_AdjTri%3C321C5F038F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_AdjTri.h

#ifndef SCNUt_AdjTri_h
#define SCNUt_AdjTri_h 1

//## begin module%3C321C5F038F.additionalIncludes preserve=no
//## end module%3C321C5F038F.additionalIncludes

//## begin module%3C321C5F038F.includes preserve=yes
//## end module%3C321C5F038F.includes

//## begin module%3C321C5F038F.additionalDeclarations preserve=yes
//## end module%3C321C5F038F.additionalDeclarations


//## begin SCNUt_AdjTri%3C321C5F038F.preface preserve=yes
//## end SCNUt_AdjTri%3C321C5F038F.preface

//## Class: SCNUt_AdjTri%3C321C5F038F
//## Category: Scene::SceneUtils::ScnStripifier%3C308123036F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class SCNUt_AdjTri 
{
  //## begin SCNUt_AdjTri%3C321C5F038F.initialDeclarations preserve=yes
  //## end SCNUt_AdjTri%3C321C5F038F.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_AdjTri();

    //## Destructor (generated)
      ~SCNUt_AdjTri();


    //## Other Operations (specified)
      //## Operation: AddNeigh%1009917117
      void AddNeigh (int _iIdx);

    // Data Members for Class Attributes

      //## Attribute: iNumNeighs%3C321C680017
      //## begin SCNUt_AdjTri::iNumNeighs%3C321C680017.attr preserve=no  public: int {UA} 0
      int iNumNeighs;
      //## end SCNUt_AdjTri::iNumNeighs%3C321C680017.attr

      //## Attribute: Neigh%3C321C73013F
      //## begin SCNUt_AdjTri::Neigh%3C321C73013F.attr preserve=no  public: int * {UA} NULL
      int *Neigh;
      //## end SCNUt_AdjTri::Neigh%3C321C73013F.attr

      //## Attribute: Visited%3C321CF70153
      //## begin SCNUt_AdjTri::Visited%3C321CF70153.attr preserve=no  public: bool {UA} false
      bool Visited;
      //## end SCNUt_AdjTri::Visited%3C321CF70153.attr

    // Additional Public Declarations
      //## begin SCNUt_AdjTri%3C321C5F038F.public preserve=yes
      //## end SCNUt_AdjTri%3C321C5F038F.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_AdjTri%3C321C5F038F.protected preserve=yes
      //## end SCNUt_AdjTri%3C321C5F038F.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_AdjTri%3C321C5F038F.private preserve=yes
      //## end SCNUt_AdjTri%3C321C5F038F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_AdjTri%3C321C5F038F.implementation preserve=yes
      //## end SCNUt_AdjTri%3C321C5F038F.implementation

};

//## begin SCNUt_AdjTri%3C321C5F038F.postscript preserve=yes
//## end SCNUt_AdjTri%3C321C5F038F.postscript

// Class SCNUt_AdjTri 

//## begin module%3C321C5F038F.epilog preserve=yes
//## end module%3C321C5F038F.epilog


#endif
