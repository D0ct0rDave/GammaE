//## begin module%3B62DC8C03CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B62DC8C03CA.cm

//## begin module%3B62DC8C03CA.cp preserve=no
//## end module%3B62DC8C03CA.cp

//## Module: CGameHUD%3B62DC8C03CA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\GameHUD\CGameHUD.h

#ifndef CGameHUD_h
#define CGameHUD_h 1

//## begin module%3B62DC8C03CA.additionalIncludes preserve=no
//## end module%3B62DC8C03CA.additionalIncludes

//## begin module%3B62DC8C03CA.includes preserve=yes
//## end module%3B62DC8C03CA.includes

// CConsole
#include "SceneObjects\Console\CConsole.h"
// CGameEntity
#include "Game\Entities\CGameEntity.h"
// eGameHUDState
#include "Game\Entities\GameHUD\eGameHUDState.h"
//## begin module%3B62DC8C03CA.additionalDeclarations preserve=yes
//## end module%3B62DC8C03CA.additionalDeclarations


//## begin CGameHUD%3B62DC8C03CA.preface preserve=yes
//## end CGameHUD%3B62DC8C03CA.preface

//## Class: CGameHUD%3B62DC8C03CA
//## Category: Game::Entities::GameHUD%3B62DC840122
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BDC9EFB02C0;eGameHUDState { -> }

class CGameHUD : public CGameEntity  //## Inherits: <unnamed>%3B62DC9B0320
{
  //## begin CGameHUD%3B62DC8C03CA.initialDeclarations preserve=yes
  //## end CGameHUD%3B62DC8C03CA.initialDeclarations

  public:
    //## Constructors (generated)
      CGameHUD();

    //## Destructor (generated)
      ~CGameHUD();


    //## Other Operations (specified)
      //## Operation: Think%996334235
      virtual void Think (float fDelta);

      //## Operation: SetCamera%1004042075
      void SetCamera (CE3D_Camera *_Cam);

      //## Operation: Toggle%1004309120
      void Toggle ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Game::Entities::GameHUD::<unnamed>%3B62DCEC00A0
      //## Role: CGameHUD::Console%3B62DCEC0367
      CConsole * GetConsole ();
      void SetConsole (CConsole * value);

    // Data Members for Associations

      //## Association: Game::Entities::GameHUD::<unnamed>%3B62DCEC00A0
      //## begin CGameHUD::Console%3B62DCEC0367.role preserve=no  public: CConsole { -> RHAN}
      CConsole *Console;
      //## end CGameHUD::Console%3B62DCEC0367.role

    // Additional Public Declarations
      //## begin CGameHUD%3B62DC8C03CA.public preserve=yes
      //## end CGameHUD%3B62DC8C03CA.public

  protected:
    // Additional Protected Declarations
      //## begin CGameHUD%3B62DC8C03CA.protected preserve=yes
      //## end CGameHUD%3B62DC8C03CA.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Cam%3BD88B8E0252
      //## begin CGameHUD::Cam%3BD88B8E0252.attr preserve=no  private: CE3D_Camera * {UA} NULL
      CE3D_Camera *Cam;
      //## end CGameHUD::Cam%3BD88B8E0252.attr

      //## Attribute: eState%3BDC9EBE01AA
      //## begin CGameHUD::eState%3BDC9EBE01AA.attr preserve=no  private: eGameHUDState {UA} 
      eGameHUDState eState;
      //## end CGameHUD::eState%3BDC9EBE01AA.attr

      //## Attribute: fSize%3BDC9FBF034E
      //## begin CGameHUD::fSize%3BDC9FBF034E.attr preserve=no  private: float {UA} 0.0f
      float fSize;
      //## end CGameHUD::fSize%3BDC9FBF034E.attr

      //## Attribute: fSecs%3BDC9FD1006F
      //## begin CGameHUD::fSecs%3BDC9FD1006F.attr preserve=no  private: float {UA} 1.0f
      float fSecs;
      //## end CGameHUD::fSecs%3BDC9FD1006F.attr

    // Additional Private Declarations
      //## begin CGameHUD%3B62DC8C03CA.private preserve=yes
      //## end CGameHUD%3B62DC8C03CA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameHUD%3B62DC8C03CA.implementation preserve=yes
      //## end CGameHUD%3B62DC8C03CA.implementation

};

//## begin CGameHUD%3B62DC8C03CA.postscript preserve=yes
//## end CGameHUD%3B62DC8C03CA.postscript

// Class CGameHUD 

//## Get and Set Operations for Associations (inline)

inline CConsole * CGameHUD::GetConsole ()
{
  //## begin CGameHUD::GetConsole%3B62DCEC0367.get preserve=no
  return Console;
  //## end CGameHUD::GetConsole%3B62DCEC0367.get
}

inline void CGameHUD::SetConsole (CConsole * value)
{
  //## begin CGameHUD::SetConsole%3B62DCEC0367.set preserve=no
  Console = value;
  //## end CGameHUD::SetConsole%3B62DCEC0367.set
}

//## begin module%3B62DC8C03CA.epilog preserve=yes
//## end module%3B62DC8C03CA.epilog


#endif
