//## begin module%3C435D4603E3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C435D4603E3.cm

//## begin module%3C435D4603E3.cp preserve=no
//## end module%3C435D4603E3.cp

//## Module: CGame_DetailCamera%3C435D4603E3; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\GameCamera\CGame_DetailCamera.h

#ifndef CGame_DetailCamera_h
#define CGame_DetailCamera_h 1

//## begin module%3C435D4603E3.additionalIncludes preserve=no
//## end module%3C435D4603E3.additionalIncludes

//## begin module%3C435D4603E3.includes preserve=yes
//## end module%3C435D4603E3.includes

// CDetailer
#include "SceneObjects\Detailer\CDetailer.h"
// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
//## begin module%3C435D4603E3.additionalDeclarations preserve=yes
//## end module%3C435D4603E3.additionalDeclarations


//## begin CGame_DetailCamera%3C435D4603E3.preface preserve=yes
//## end CGame_DetailCamera%3C435D4603E3.preface

//## Class: CGame_DetailCamera%3C435D4603E3
//## Category: Game::Entities::GameCamera%3B62D25B01CC
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGame_DetailCamera : public CGPhysicEntity  //## Inherits: <unnamed>%3C435E0F03B0
{
  //## begin CGame_DetailCamera%3C435D4603E3.initialDeclarations preserve=yes
  //## end CGame_DetailCamera%3C435D4603E3.initialDeclarations

  public:
    //## Constructors (generated)
      CGame_DetailCamera();

    //## Destructor (generated)
      ~CGame_DetailCamera();


    //## Other Operations (specified)
      //## Operation: SetCamera%1011045655
      void SetCamera (CE3D_Camera *_Cam);

      //## Operation: Think%1011045656
      virtual void Think (float fDelta);

      //## Operation: SetDetailer%1011045657
      void SetDetailer (CDetailer *_poDetailer);

    // Data Members for Associations

      //## Association: Game::Entities::GameSFX::<unnamed>%3C435E1E018B
      //## Role: CGame_DetailCamera::poDetailer%3C435E1E03E5
      //## begin CGame_DetailCamera::poDetailer%3C435E1E03E5.role preserve=no  public: CDetailer { -> RHAN}
      CDetailer *poDetailer;
      //## end CGame_DetailCamera::poDetailer%3C435E1E03E5.role

    // Additional Public Declarations
      //## begin CGame_DetailCamera%3C435D4603E3.public preserve=yes
      //## end CGame_DetailCamera%3C435D4603E3.public

  protected:
    // Additional Protected Declarations
      //## begin CGame_DetailCamera%3C435D4603E3.protected preserve=yes
      //## end CGame_DetailCamera%3C435D4603E3.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Cam%3C435FFF0024
      //## begin CGame_DetailCamera::Cam%3C435FFF0024.attr preserve=no  private: CE3D_Camera * {UA} 
      CE3D_Camera *Cam;
      //## end CGame_DetailCamera::Cam%3C435FFF0024.attr

    // Additional Private Declarations
      //## begin CGame_DetailCamera%3C435D4603E3.private preserve=yes
      //## end CGame_DetailCamera%3C435D4603E3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGame_DetailCamera%3C435D4603E3.implementation preserve=yes
      //## end CGame_DetailCamera%3C435D4603E3.implementation

};

//## begin CGame_DetailCamera%3C435D4603E3.postscript preserve=yes
//## end CGame_DetailCamera%3C435D4603E3.postscript

// Class CGame_DetailCamera 

//## begin module%3C435D4603E3.epilog preserve=yes
//## end module%3C435D4603E3.epilog


#endif
