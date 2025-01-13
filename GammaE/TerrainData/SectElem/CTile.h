//## begin module%3AFE96C5000A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AFE96C5000A.cm

//## begin module%3AFE96C5000A.cp preserve=no
//## end module%3AFE96C5000A.cp

//## Module: CTile%3AFE96C5000A; Pseudo Package specification
//## Source file: E:\Projects\GammaE\TerrainData\SectElem\CTile.h

#ifndef CTile_h
#define CTile_h 1

//## begin module%3AFE96C5000A.additionalIncludes preserve=no
//## end module%3AFE96C5000A.additionalIncludes

//## begin module%3AFE96C5000A.includes preserve=yes
//## end module%3AFE96C5000A.includes

// CSectElem
#include "TerrainData\SectElem\CSectElem.h"
//## begin module%3AFE96C5000A.additionalDeclarations preserve=yes
//## end module%3AFE96C5000A.additionalDeclarations


//## begin CTile%3AFE96C5000A.preface preserve=yes
//## end CTile%3AFE96C5000A.preface

//## Class: CTile%3AFE96C5000A
//## Category: TerrainData::SectElem%3AF50839032A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTile : public CSectElem  //## Inherits: <unnamed>%3AFE97E90104
{
  //## begin CTile%3AFE96C5000A.initialDeclarations preserve=yes
  //## end CTile%3AFE96C5000A.initialDeclarations

  public:
    //## Constructors (generated)
      CTile();

    //## Destructor (generated)
      ~CTile();


    //## Other Operations (specified)
      //## Operation: ByteSize%989763979
      virtual unsigned long ByteSize ();

      //## Operation: Get%989763984
      virtual void * Get ();

      //## Operation: Set%989763985
      virtual void Set (void *_Value);

      //## Operation: CreateClass%991155102
      virtual CSectElem * CreateClass ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: TileIdx%3AFE96DE0370
      int GetTileIdx ();
      void SetTileIdx (int value);

      //## Attribute: TransitionType%3AFE97330352
      int GetTransitionType ();
      void SetTransitionType (int value);

      //## Attribute: TransTileIdx%3AFE9753021C
      int GetTransTileIdx ();
      void SetTransTileIdx (int value);

      //## Attribute: RotationType%3AFE974902F8
      int GetRotationType ();
      void SetRotationType (int value);

      //## Attribute: Invisible%3AFE97610334
      bool GetInvisible ();
      void SetInvisible (bool value);

      //## Attribute: OldTransition%3AFE97AF03D4
      int GetOldTransition ();
      void SetOldTransition (int value);

    // Data Members for Class Attributes

      //## begin CTile::TileIdx%3AFE96DE0370.attr preserve=no  public: int {U} 0
      int TileIdx;
      //## end CTile::TileIdx%3AFE96DE0370.attr

      //## begin CTile::TransitionType%3AFE97330352.attr preserve=no  public: int {UA} 0
      int TransitionType;
      //## end CTile::TransitionType%3AFE97330352.attr

      //## begin CTile::TransTileIdx%3AFE9753021C.attr preserve=no  public: int {UA} 0
      int TransTileIdx;
      //## end CTile::TransTileIdx%3AFE9753021C.attr

      //## begin CTile::RotationType%3AFE974902F8.attr preserve=no  public: int {UA} 0
      int RotationType;
      //## end CTile::RotationType%3AFE974902F8.attr

      //## begin CTile::Invisible%3AFE97610334.attr preserve=no  public: bool {UA} true
      bool Invisible;
      //## end CTile::Invisible%3AFE97610334.attr

      //## begin CTile::OldTransition%3AFE97AF03D4.attr preserve=no  public: int {UA} 0
      int OldTransition;
      //## end CTile::OldTransition%3AFE97AF03D4.attr

    // Additional Public Declarations
      //## begin CTile%3AFE96C5000A.public preserve=yes
      //## end CTile%3AFE96C5000A.public

  protected:
    // Additional Protected Declarations
      //## begin CTile%3AFE96C5000A.protected preserve=yes
      //## end CTile%3AFE96C5000A.protected

  private:
    // Additional Private Declarations
      //## begin CTile%3AFE96C5000A.private preserve=yes
      //## end CTile%3AFE96C5000A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTile%3AFE96C5000A.implementation preserve=yes
      //## end CTile%3AFE96C5000A.implementation

};

//## begin CTile%3AFE96C5000A.postscript preserve=yes
//## end CTile%3AFE96C5000A.postscript

// Class CTile 

//## Get and Set Operations for Class Attributes (inline)

inline int CTile::GetTransTileIdx ()
{
  //## begin CTile::GetTransTileIdx%3AFE9753021C.get preserve=no
  return TransTileIdx;
  //## end CTile::GetTransTileIdx%3AFE9753021C.get
}

//## begin module%3AFE96C5000A.epilog preserve=yes
//## end module%3AFE96C5000A.epilog


#endif
