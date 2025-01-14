//## begin module%3CDE422E0353.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDE422E0353.cm

//## begin module%3CDE422E0353.cp preserve=no
//## end module%3CDE422E0353.cp

//## Module: CRTME_Trigger%3CDE422E0353; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Trigger.h

#ifndef CRTME_Trigger_h
#define CRTME_Trigger_h 1

//## begin module%3CDE422E0353.additionalIncludes preserve=no
//## end module%3CDE422E0353.additionalIncludes

//## begin module%3CDE422E0353.includes preserve=yes
//## end module%3CDE422E0353.includes

// CCOL_Collider
#include "Collision\Collider\CCOL_Collider.h"
// CRTME_Target
#include "Game\Entities\RTMapEntities\CRTME_Target.h"
// CMapEnt_Trigger
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Trigger.h"
//## begin module%3CDE422E0353.additionalDeclarations preserve=yes
//## end module%3CDE422E0353.additionalDeclarations


//## begin CRTME_Trigger%3CDE422E0353.preface preserve=yes
//## end CRTME_Trigger%3CDE422E0353.preface

//## Class: CRTME_Trigger%3CDE422E0353
//## Category: Game::Entities::RTMapEntities%3CDE40EE01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CRTME_Trigger : public CRTME_Target  //## Inherits: <unnamed>%3CDE425602A6
{
  //## begin CRTME_Trigger%3CDE422E0353.initialDeclarations preserve=yes
  //## end CRTME_Trigger%3CDE422E0353.initialDeclarations

  public:
    //## Constructors (generated)
      CRTME_Trigger();

    //## Destructor (generated)
      ~CRTME_Trigger();


    //## Other Operations (specified)
      //## Operation: Think%1021199188
      virtual void Think (float _fDelta);

      //## Operation: Init%1021237871
      void Init (CMapEnt_Trigger* _poTrigInfo);

    // Data Members for Class Attributes

      //## Attribute: poTrigInfo%3CDEF7C0021D
      //## begin CRTME_Trigger::poTrigInfo%3CDEF7C0021D.attr preserve=no  public: CMapEnt_Trigger* {UA} NULL
      CMapEnt_Trigger* poTrigInfo;
      //## end CRTME_Trigger::poTrigInfo%3CDEF7C0021D.attr

    // Data Members for Associations

      //## Association: Game::Entities::RTMapEntities::<unnamed>%3CDE429F036A
      //## Role: CRTME_Trigger::Target%3CDE42A000C2
      //## begin CRTME_Trigger::Target%3CDE42A000C2.role preserve=no  public: CRTME_Target { -> RHAN}
      CRTME_Target *Target;
      //## end CRTME_Trigger::Target%3CDE42A000C2.role

      //## Association: Game::Entities::RTMapEntities::<unnamed>%3CDE42B802D9
      //## Role: CRTME_Trigger::SecTarget%3CDE42B90065
      //## begin CRTME_Trigger::SecTarget%3CDE42B90065.role preserve=no  public: CRTME_Target { -> RHAN}
      CRTME_Target *SecTarget;
      //## end CRTME_Trigger::SecTarget%3CDE42B90065.role

      //## Association: Game::Entities::RTMapEntities::<unnamed>%3CDE431201E8
      //## Role: CRTME_Trigger::TrigInfo%3CDE431202BB
      //## begin CRTME_Trigger::TrigInfo%3CDE431202BB.role preserve=no  public: CMapEnt_Trigger { -> RHAN}
      CMapEnt_Trigger *TrigInfo;
      //## end CRTME_Trigger::TrigInfo%3CDE431202BB.role

    // Additional Public Declarations
      //## begin CRTME_Trigger%3CDE422E0353.public preserve=yes
      //## end CRTME_Trigger%3CDE422E0353.public

  protected:
    // Data Members for Associations

      //## Association: Game::Entities::RTMapEntities::<unnamed>%3CDE47380069
      //## Role: CRTME_Trigger::oColObj%3CDE47380223
      //## begin CRTME_Trigger::oColObj%3CDE47380223.role preserve=no  protected: CCOL_Collider { -> VHAN}
      CCOL_Collider oColObj;
      //## end CRTME_Trigger::oColObj%3CDE47380223.role

    // Additional Protected Declarations
      //## begin CRTME_Trigger%3CDE422E0353.protected preserve=yes
      //## end CRTME_Trigger%3CDE422E0353.protected

  private:
    // Additional Private Declarations
      //## begin CRTME_Trigger%3CDE422E0353.private preserve=yes
      //## end CRTME_Trigger%3CDE422E0353.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CRTME_Trigger%3CDE422E0353.implementation preserve=yes
      //## end CRTME_Trigger%3CDE422E0353.implementation

};

//## begin CRTME_Trigger%3CDE422E0353.postscript preserve=yes
//## end CRTME_Trigger%3CDE422E0353.postscript

// Class CRTME_Trigger 

//## begin module%3CDE422E0353.epilog preserve=yes
//## end module%3CDE422E0353.epilog


#endif
