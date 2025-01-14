//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CGameScene%3B65CB11028A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\CGameScene.h

#ifndef CGameScene_h
#define CGameScene_h 1

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
//## end module%3B65CB11028A.includes

// CParticleSystemMgr
#include "Game\CParticleSystemMgr.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Camera
#include "Scene\CObject3D_Camera.h"
// CBackgroundMgr
#include "Game\CBackgroundMgr.h"
//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
//## end module%3B65CB11028A.additionalDeclarations


//## begin CGameScene%3B65CB11028A.preface preserve=yes
//## end CGameScene%3B65CB11028A.preface

//## Class: CGameScene%3B65CB11028A
//## Category: Game%3B5DE98D0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B770BC40318;CParticleSystemMgr { -> }
//## Uses: <unnamed>%3B770BC702B8;CBackgroundMgr { -> }

class CGameScene : public CObject3D_Camera  //## Inherits: <unnamed>%3B65CB820384
{
  //## begin CGameScene%3B65CB11028A.initialDeclarations preserve=yes
  //## end CGameScene%3B65CB11028A.initialDeclarations

  public:
    //## Constructors (generated)
      CGameScene();

    //## Destructor (generated)
      ~CGameScene();


    //## Other Operations (specified)
      //## Operation: InitScene%997655858
      void InitScene (int iMaxObjs);

    //## Get and Set Operations for Associations (generated)

      //## Association: Game::<unnamed>%3B770DB002ED
      //## Role: CGameScene::Scene%3B770DB602A7
      CObject3D_Node * GetScene ();
      void SetScene (CObject3D_Node * value);

    // Additional Public Declarations
      //## begin CGameScene%3B65CB11028A.public preserve=yes
      //## end CGameScene%3B65CB11028A.public

  protected:
    // Additional Protected Declarations
      //## begin CGameScene%3B65CB11028A.protected preserve=yes
      //## end CGameScene%3B65CB11028A.protected

  private:
    // Additional Private Declarations
      //## begin CGameScene%3B65CB11028A.private preserve=yes
      //## end CGameScene%3B65CB11028A.private

  private: //## implementation
    // Data Members for Associations

      //## Association: Game::<unnamed>%3B770DB002ED
      //## begin CGameScene::Scene%3B770DB602A7.role preserve=no  public: CObject3D_Node { -> RHN}
      CObject3D_Node *Scene;
      //## end CGameScene::Scene%3B770DB602A7.role

    // Additional Implementation Declarations
      //## begin CGameScene%3B65CB11028A.implementation preserve=yes
      //## end CGameScene%3B65CB11028A.implementation

};

//## begin CGameScene%3B65CB11028A.postscript preserve=yes
//## end CGameScene%3B65CB11028A.postscript

// Class CGameScene 

//## Get and Set Operations for Associations (inline)

inline CObject3D_Node * CGameScene::GetScene ()
{
  //## begin CGameScene::GetScene%3B770DB602A7.get preserve=no
  return Scene;
  //## end CGameScene::GetScene%3B770DB602A7.get
}

inline void CGameScene::SetScene (CObject3D_Node * value)
{
  //## begin CGameScene::SetScene%3B770DB602A7.set preserve=no
  Scene = value;
  //## end CGameScene::SetScene%3B770DB602A7.set
}

//## begin module%3B65CB11028A.epilog preserve=yes
extern CGameScene GameScene;
//## end module%3B65CB11028A.epilog


#endif
