//## begin module%3B62D89300C8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B62D89300C8.cm

//## begin module%3B62D89300C8.cp preserve=no
//## end module%3B62D89300C8.cp

//## Module: CGameListEntity%3B62D89300C8; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGameListEntity.h

#ifndef CGameListEntity_h
#define CGameListEntity_h 1

//## begin module%3B62D89300C8.additionalIncludes preserve=no
//## end module%3B62D89300C8.additionalIncludes

//## begin module%3B62D89300C8.includes preserve=yes
//## end module%3B62D89300C8.includes

// CGameEntity
#include "Game\Entities\CGameEntity.h"
//## begin module%3B62D89300C8.additionalDeclarations preserve=yes
//## end module%3B62D89300C8.additionalDeclarations


//## begin CGameListEntity%3B62D89300C8.preface preserve=yes
//## end CGameListEntity%3B62D89300C8.preface

//## Class: CGameListEntity%3B62D89300C8
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGameListEntity : public CGameEntity  //## Inherits: <unnamed>%3B62D8A701A4
{
  //## begin CGameListEntity%3B62D89300C8.initialDeclarations preserve=yes
  //## end CGameListEntity%3B62D89300C8.initialDeclarations

  public:
    //## Constructors (generated)
      CGameListEntity();

    //## Destructor (generated)
      ~CGameListEntity();


    //## Other Operations (specified)
      //## Operation: Think%996332272
      virtual void Think (float _fDelta);

      //## Operation: Init%996332273
      void Init (int _iMaxEntities);

      //## Operation: iAddEntity%996522676
      int iAddEntity (CGameEntity* _pEntity);

      //## Operation: SetEntity%996332274
      void SetEntity (int _iEntNum, CGameEntity *_pEntity);

      //## Operation: poGetEntity%996522677
      CGameEntity * poGetEntity (int _iEntNum);

      //## Operation: Reset%1021237867
      void Reset ();

      //## Operation: ProcessCmds%1021565345
      virtual void ProcessCmds (float _fDelta);

      //## Operation: Interact%1021565347
      virtual void Interact (float _fDelta);

    // Additional Public Declarations
      //## begin CGameListEntity%3B62D89300C8.public preserve=yes
      //## end CGameListEntity%3B62D89300C8.public

  protected:
    // Additional Protected Declarations
      //## begin CGameListEntity%3B62D89300C8.protected preserve=yes
      //## end CGameListEntity%3B62D89300C8.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poEntities%3B62D8D900B4
      //## begin CGameListEntity::poEntities%3B62D8D900B4.attr preserve=no  private: CGameEntity* * {UA} NULL
      CGameEntity* *poEntities;
      //## end CGameListEntity::poEntities%3B62D8D900B4.attr

      //## Attribute: iMaxEntities%3B62D8E30230
      //## begin CGameListEntity::iMaxEntities%3B62D8E30230.attr preserve=no  private: int {UA} 0
      int iMaxEntities;
      //## end CGameListEntity::iMaxEntities%3B62D8E30230.attr

      //## Attribute: iNumEntities%3CDEDE5803AB
      //## begin CGameListEntity::iNumEntities%3CDEDE5803AB.attr preserve=no  private: int {UA} 0
      int iNumEntities;
      //## end CGameListEntity::iNumEntities%3CDEDE5803AB.attr

    // Additional Private Declarations
      //## begin CGameListEntity%3B62D89300C8.private preserve=yes
      //## end CGameListEntity%3B62D89300C8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameListEntity%3B62D89300C8.implementation preserve=yes
      //## end CGameListEntity%3B62D89300C8.implementation

};

//## begin CGameListEntity%3B62D89300C8.postscript preserve=yes
//## end CGameListEntity%3B62D89300C8.postscript

// Class CGameListEntity 

//## begin module%3B62D89300C8.epilog preserve=yes
//## end module%3B62D89300C8.epilog


#endif
