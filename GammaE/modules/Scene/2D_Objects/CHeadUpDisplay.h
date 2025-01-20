//## begin module%3ACA2D230154.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ACA2D230154.cm

//## begin module%3ACA2D230154.cp preserve=no
//## end module%3ACA2D230154.cp

//## Module: CHeadUpDisplay%3ACA2D230154; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\2D_Objects\CHeadUpDisplay.h

#ifndef CHeadUpDisplay_h
#define CHeadUpDisplay_h 1

//## begin module%3ACA2D230154.additionalIncludes preserve=no
//## end module%3ACA2D230154.additionalIncludes

//## begin module%3ACA2D230154.includes preserve=yes
//## end module%3ACA2D230154.includes

// THUDObjPosEntry
#include "Scene\2D_Objects\THUDObjPosEntry.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3ACA2D230154.additionalDeclarations preserve=yes
//## end module%3ACA2D230154.additionalDeclarations


//## begin CHeadUpDisplay%3ACA2D230154.preface preserve=yes
//## end CHeadUpDisplay%3ACA2D230154.preface

//## Class: CHeadUpDisplay%3ACA2D230154
//## Category: Scene::2D_Objects%3ACA2CA302BC
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3ACA46280172;THUDObjPosEntry { -> }

class CHeadUpDisplay : public CObject3D_Node  //## Inherits: <unnamed>%3ACA2D410186
{
  //## begin CHeadUpDisplay%3ACA2D230154.initialDeclarations preserve=yes
  //## end CHeadUpDisplay%3ACA2D230154.initialDeclarations

  public:
    //## Constructors (generated)
      CHeadUpDisplay();

    //## Destructor (generated)
      virtual ~CHeadUpDisplay();


    //## Other Operations (specified)
      //## Operation: AddObject%986334606
      void AddObject (CObject3D *Obj, float x, float y, float tx, float ty);

      //## Operation: Invalidate%986334607
      void Invalidate ();

      //## Operation: Render%986334608
      virtual void Render ();

      //## Operation: Init%986334609
      void Init (int _NumSubObjects);

      //## Operation: iCulled%1006904818
      virtual int iCulled ();

    // Additional Public Declarations
      //## begin CHeadUpDisplay%3ACA2D230154.public preserve=yes
      //## end CHeadUpDisplay%3ACA2D230154.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: ObjPos%3ACA465D0104
      //## begin CHeadUpDisplay::ObjPos%3ACA465D0104.attr preserve=no  protected: THUDObjPosEntry * {UA} NULL
      THUDObjPosEntry *ObjPos;
      //## end CHeadUpDisplay::ObjPos%3ACA465D0104.attr

    // Additional Protected Declarations
      //## begin CHeadUpDisplay%3ACA2D230154.protected preserve=yes
      //## end CHeadUpDisplay%3ACA2D230154.protected

  private:
    // Additional Private Declarations
      //## begin CHeadUpDisplay%3ACA2D230154.private preserve=yes
      //## end CHeadUpDisplay%3ACA2D230154.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHeadUpDisplay%3ACA2D230154.implementation preserve=yes
      //## end CHeadUpDisplay%3ACA2D230154.implementation

};

//## begin CHeadUpDisplay%3ACA2D230154.postscript preserve=yes
//## end CHeadUpDisplay%3ACA2D230154.postscript

// Class CHeadUpDisplay 

//## begin module%3ACA2D230154.epilog preserve=yes
//## end module%3ACA2D230154.epilog


#endif
