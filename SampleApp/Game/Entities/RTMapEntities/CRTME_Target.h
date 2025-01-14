//## begin module%3CDE40FB0366.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDE40FB0366.cm

//## begin module%3CDE40FB0366.cp preserve=no
//## end module%3CDE40FB0366.cp

//## Module: CRTME_Target%3CDE40FB0366; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Target.h

#ifndef CRTME_Target_h
#define CRTME_Target_h 1

//## begin module%3CDE40FB0366.additionalIncludes preserve=no
//## end module%3CDE40FB0366.additionalIncludes

//## begin module%3CDE40FB0366.includes preserve=yes
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEntities.h"
//## end module%3CDE40FB0366.includes

// CGameEntity
#include "Game\Entities\CGameEntity.h"
//## begin module%3CDE40FB0366.additionalDeclarations preserve=yes
//## end module%3CDE40FB0366.additionalDeclarations


//## begin CRTME_Target%3CDE40FB0366.preface preserve=yes
//## end CRTME_Target%3CDE40FB0366.preface

//## Class: CRTME_Target%3CDE40FB0366
//## Category: Game::Entities::RTMapEntities%3CDE40EE01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CRTME_Target : public CGameEntity  //## Inherits: <unnamed>%3CDE41B40091
{
  //## begin CRTME_Target%3CDE40FB0366.initialDeclarations preserve=yes
  //## end CRTME_Target%3CDE40FB0366.initialDeclarations

  public:
    //## Constructors (generated)
      CRTME_Target();

    //## Destructor (generated)
      ~CRTME_Target();


    //## Other Operations (specified)
      //## Operation: Trigger%1021199185
      void Trigger ();

      //## Operation: bTriggered%1021199186
      bool bTriggered ();

      //## Operation: UnTrigger%1021199187
      void UnTrigger ();

    // Data Members for Class Attributes

      //## Attribute: poTargetInfo%3CDEF8F90050
      //## begin CRTME_Target::poTargetInfo%3CDEF8F90050.attr preserve=no  public: CMapEnt_Target* {UA} NULL
      CMapEnt_Target* poTargetInfo;
      //## end CRTME_Target::poTargetInfo%3CDEF8F90050.attr

    // Additional Public Declarations
      //## begin CRTME_Target%3CDE40FB0366.public preserve=yes
      //## end CRTME_Target%3CDE40FB0366.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: bIsTriggered%3CDE411501BE
      //## begin CRTME_Target::bIsTriggered%3CDE411501BE.attr preserve=no  protected: bool {UA} 
      bool bIsTriggered;
      //## end CRTME_Target::bIsTriggered%3CDE411501BE.attr

    // Additional Protected Declarations
      //## begin CRTME_Target%3CDE40FB0366.protected preserve=yes
      //## end CRTME_Target%3CDE40FB0366.protected

  private:
    // Additional Private Declarations
      //## begin CRTME_Target%3CDE40FB0366.private preserve=yes
      //## end CRTME_Target%3CDE40FB0366.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CRTME_Target%3CDE40FB0366.implementation preserve=yes
      //## end CRTME_Target%3CDE40FB0366.implementation

};

//## begin CRTME_Target%3CDE40FB0366.postscript preserve=yes
//## end CRTME_Target%3CDE40FB0366.postscript

// Class CRTME_Target 


//## Other Operations (inline)
inline void CRTME_Target::Trigger ()
{
  //## begin CRTME_Target::Trigger%1021199185.body preserve=yes
	bIsTriggered = true;
  //## end CRTME_Target::Trigger%1021199185.body
}

inline bool CRTME_Target::bTriggered ()
{
  //## begin CRTME_Target::bTriggered%1021199186.body preserve=yes
	return ((bIsTriggered) || (poTargetInfo->eTriggerMode ==eMapEnt_TM_Always));
  //## end CRTME_Target::bTriggered%1021199186.body
}

inline void CRTME_Target::UnTrigger ()
{
  //## begin CRTME_Target::UnTrigger%1021199187.body preserve=yes
	bIsTriggered = false;
  //## end CRTME_Target::UnTrigger%1021199187.body
}

//## begin module%3CDE40FB0366.epilog preserve=yes
//## end module%3CDE40FB0366.epilog


#endif
