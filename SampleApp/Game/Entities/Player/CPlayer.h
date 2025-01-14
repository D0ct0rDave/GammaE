//## begin module%3B5DFD6B014A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5DFD6B014A.cm

//## begin module%3B5DFD6B014A.cp preserve=no
//## end module%3B5DFD6B014A.cp

//## Module: CPlayer%3B5DFD6B014A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\Player\CPlayer.h

#ifndef CPlayer_h
#define CPlayer_h 1

//## begin module%3B5DFD6B014A.additionalIncludes preserve=no
//## end module%3B5DFD6B014A.additionalIncludes

//## begin module%3B5DFD6B014A.includes preserve=yes
//## end module%3B5DFD6B014A.includes

// ePlayerState
#include "Game\Entities\Player\ePlayerState.h"
// ePlayerCommands
#include "Game\Entities\Player\ePlayerCommands.h"
// CGPGAnimatedEntity
#include "Game\Entities\CGPGAnimatedEntity.h"
// CGameListEntity
#include "Game\Entities\CGameListEntity.h"
// CGameScene
#include "Game\GameScene\CGameScene.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
//## begin module%3B5DFD6B014A.additionalDeclarations preserve=yes

#define CMF_FORWARD		0x0001
#define CMF_BACKWARD	0x0002
#define CMF_UP			0x0004
#define CMF_DOWN		0x0008
#define CMF_LEFT		0x0010
#define CMF_RIGHT		0x0020

//## end module%3B5DFD6B014A.additionalDeclarations


//## begin CPlayer%3B5DFD6B014A.preface preserve=yes
//## end CPlayer%3B5DFD6B014A.preface

//## Class: CPlayer%3B5DFD6B014A
//## Category: Game::Entities::Player%3B62D1730046
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B6088C20212;ePlayerState { -> }
//## Uses: <unnamed>%3B608A7A02F8;ePlayerCommands { -> }
//## Uses: <unnamed>%3B65C7C40046;CGameListEntity { -> }
//## Uses: <unnamed>%3B65CBD9019A;CGameScene { -> }
//## Uses: <unnamed>%3CC09AF302EB;GammaE_Scene { -> }

class CPlayer : public CGPGAnimatedEntity  //## Inherits: <unnamed>%3CD6F23900AD
{
  //## begin CPlayer%3B5DFD6B014A.initialDeclarations preserve=yes
  //## end CPlayer%3B5DFD6B014A.initialDeclarations

  public:
    //## Constructors (generated)
      CPlayer();

    //## Destructor (generated)
      ~CPlayer();


    //## Other Operations (specified)
      //## Operation: Init%1019254138
      void Init (CObject3D* _poModel, CObject3D* _poMesh);

      //## Operation: SetupFrameFromFlags%996856077
      void SetupFrameFromFlags ();

      //## Operation: Fire%1019293385
      void Fire ();

      //## Operation: Think%1020720917
      virtual void Think (float _fDelta);

      //## Operation: ControlCmds%1020720918
      virtual void ControlCmds (int _iCmd, bool _bEnabled, float _fValue);

      //## Operation: ProcessCmds%1021497765
      virtual void ProcessCmds (float _fDelta);

      //## Operation: ComputeCollisionResponse%1021497766
      virtual void ComputeCollisionResponse ();

      //## Operation: Interact%1021565346
      virtual void Interact (float _fDelta);

    // Additional Public Declarations
      //## begin CPlayer%3B5DFD6B014A.public preserve=yes
      //## end CPlayer%3B5DFD6B014A.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: ePrevState%3B5F49DC0384
      //## begin CPlayer::ePrevState%3B5F49DC0384.attr preserve=no  protected: ePlayerState {UA} PS_Idle
      ePlayerState ePrevState;
      //## end CPlayer::ePrevState%3B5F49DC0384.attr

      //## Attribute: eState%3CD6F6700358
      //## begin CPlayer::eState%3CD6F6700358.attr preserve=no  protected: ePlayerState {UA} PS_Idle
      ePlayerState eState;
      //## end CPlayer::eState%3CD6F6700358.attr

      //## Attribute: eLastCmd%3CD6F6680306
      //## begin CPlayer::eLastCmd%3CD6F6680306.attr preserve=no  protected: ePlayerCommands {UA} PC_None
      ePlayerCommands eLastCmd;
      //## end CPlayer::eLastCmd%3CD6F6680306.attr

      //## Attribute: iState%3B5F49E200E6
      //## begin CPlayer::iState%3B5F49E200E6.attr preserve=no  protected: int {UA} 0
      int iState;
      //## end CPlayer::iState%3B5F49E200E6.attr

      //## Attribute: iCFrame%3B618D600136
      //## begin CPlayer::iCFrame%3B618D600136.attr preserve=no  protected: int {UA} 0
      int iCFrame;
      //## end CPlayer::iCFrame%3B618D600136.attr

      //## Attribute: iMFlags%3B6487540316
      //## begin CPlayer::iMFlags%3B6487540316.attr preserve=no  protected: int {UA} 0
      int iMFlags;
      //## end CPlayer::iMFlags%3B6487540316.attr

      //## Attribute: fRoll%3B6721BE0230
      //## begin CPlayer::fRoll%3B6721BE0230.attr preserve=no  protected: float {UA} 0
      float fRoll;
      //## end CPlayer::fRoll%3B6721BE0230.attr

      //## Attribute: fYaw%3B6721C10212
      //## begin CPlayer::fYaw%3B6721C10212.attr preserve=no  protected: float {UA} 0
      float fYaw;
      //## end CPlayer::fYaw%3B6721C10212.attr

    // Additional Protected Declarations
      //## begin CPlayer%3B5DFD6B014A.protected preserve=yes
      //## end CPlayer%3B5DFD6B014A.protected

  private:
    // Additional Private Declarations
      //## begin CPlayer%3B5DFD6B014A.private preserve=yes
      //## end CPlayer%3B5DFD6B014A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPlayer%3B5DFD6B014A.implementation preserve=yes
      //## end CPlayer%3B5DFD6B014A.implementation

};

//## begin CPlayer%3B5DFD6B014A.postscript preserve=yes
//## end CPlayer%3B5DFD6B014A.postscript

// Class CPlayer 

//## begin module%3B5DFD6B014A.epilog preserve=yes
//## end module%3B5DFD6B014A.epilog


#endif
