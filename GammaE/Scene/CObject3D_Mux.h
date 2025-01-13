//## begin module%3BD972AC0089.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD972AC0089.cm

//## begin module%3BD972AC0089.cp preserve=no
//## end module%3BD972AC0089.cp

//## Module: CObject3D_Mux%3BD972AC0089; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Mux.h

#ifndef CObject3D_Mux_h
#define CObject3D_Mux_h 1

//## begin module%3BD972AC0089.additionalIncludes preserve=no
//## end module%3BD972AC0089.additionalIncludes

//## begin module%3BD972AC0089.includes preserve=yes
//## end module%3BD972AC0089.includes

// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3BD972AC0089.additionalDeclarations preserve=yes
//## end module%3BD972AC0089.additionalDeclarations


//## begin CObject3D_Mux%3BD972AC0089.preface preserve=yes
//## end CObject3D_Mux%3BD972AC0089.preface

//## Class: CObject3D_Mux%3BD972AC0089
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_Mux : public CObject3D_Node  //## Inherits: <unnamed>%3BD972C30281
{
  //## begin CObject3D_Mux%3BD972AC0089.initialDeclarations preserve=yes
  //## end CObject3D_Mux%3BD972AC0089.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_Mux();

    //## Destructor (generated)
      virtual ~CObject3D_Mux();


    //## Other Operations (specified)
      //## Operation: Init%1004106494
      virtual void Init (int _MaxSubObjects);

      //## Operation: Render%1004106495
      virtual void Render ();

      //## Operation: SelectAll%1004106496
      void SelectAll ();

      //## Operation: SelectNone%1004106497
      void SelectNone ();

      //## Operation: Select%1004106498
      void Select (int _iIdx);

      //## Operation: Unselect%1004106499
      void Unselect (int _iIdx);

      //## Operation: bIsSelected%1004106500
      bool bIsSelected (int _iIdx);

    // Additional Public Declarations
      //## begin CObject3D_Mux%3BD972AC0089.public preserve=yes
      //## end CObject3D_Mux%3BD972AC0089.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: Selected%3BD972B901BE
      //## begin CObject3D_Mux::Selected%3BD972B901BE.attr preserve=no  protected: char * {UA} NULL
      char *Selected;
      //## end CObject3D_Mux::Selected%3BD972B901BE.attr

    // Additional Protected Declarations
      //## begin CObject3D_Mux%3BD972AC0089.protected preserve=yes
      //## end CObject3D_Mux%3BD972AC0089.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_Mux%3BD972AC0089.private preserve=yes
      //## end CObject3D_Mux%3BD972AC0089.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_Mux%3BD972AC0089.implementation preserve=yes
      //## end CObject3D_Mux%3BD972AC0089.implementation

};

//## begin CObject3D_Mux%3BD972AC0089.postscript preserve=yes
//## end CObject3D_Mux%3BD972AC0089.postscript

// Class CObject3D_Mux 

//## begin module%3BD972AC0089.epilog preserve=yes
//## end module%3BD972AC0089.epilog


#endif
