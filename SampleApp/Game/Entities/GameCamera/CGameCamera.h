//## begin module%3B62D27300F0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B62D27300F0.cm

//## begin module%3B62D27300F0.cp preserve=no
//## end module%3B62D27300F0.cp

//## Module: CGameCamera%3B62D27300F0; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\GameCamera\CGameCamera.h

#ifndef CGameCamera_h
#define CGameCamera_h 1

//## begin module%3B62D27300F0.additionalIncludes preserve=no
//## end module%3B62D27300F0.additionalIncludes

//## begin module%3B62D27300F0.includes preserve=yes
//## end module%3B62D27300F0.includes

// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
//## begin module%3B62D27300F0.additionalDeclarations preserve=yes
//## end module%3B62D27300F0.additionalDeclarations


//## begin CGameCamera%3B62D27300F0.preface preserve=yes
//## end CGameCamera%3B62D27300F0.preface

//## Class: CGameCamera%3B62D27300F0
//## Category: Game::Entities::GameCamera%3B62D25B01CC
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CGameCamera : public CGPhysicEntity  //## Inherits: <unnamed>%3C1D29E9021B
{
  //## begin CGameCamera%3B62D27300F0.initialDeclarations preserve=yes
  //## end CGameCamera%3B62D27300F0.initialDeclarations

  public:
    //## Constructors (generated)
      CGameCamera();

    //## Destructor (generated)
      ~CGameCamera();


    //## Other Operations (specified)
      //## Operation: Think%996332271
      virtual void Think (float fDelta);

      //## Operation: CorrectCamHeight%997742738
      float CorrectCamHeight (CVect3 &Src, CVect3 &Dst);

      //## Operation: SetCamera%1004042074
      void SetCamera (CE3D_Camera *_Cam);

    // Data Members for Class Attributes

      //## Attribute: Dir%3B62D3910276
      //## begin CGameCamera::Dir%3B62D3910276.attr preserve=no  public: CVect3 {UA} 
      CVect3 Dir;
      //## end CGameCamera::Dir%3B62D3910276.attr

      //## Attribute: Up%3B62D397029E
      //## begin CGameCamera::Up%3B62D397029E.attr preserve=no  public: CVect3 {UA} 
      CVect3 Up;
      //## end CGameCamera::Up%3B62D397029E.attr

      //## Attribute: Side%3B62D39B0046
      //## begin CGameCamera::Side%3B62D39B0046.attr preserve=no  public: CVect3 {UA} 
      CVect3 Side;
      //## end CGameCamera::Side%3B62D39B0046.attr

    // Additional Public Declarations
      //## begin CGameCamera%3B62D27300F0.public preserve=yes
      //## end CGameCamera%3B62D27300F0.public

  protected:
    // Additional Protected Declarations
      //## begin CGameCamera%3B62D27300F0.protected preserve=yes
      //## end CGameCamera%3B62D27300F0.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Cam%3BD88AEF02FD
      //## begin CGameCamera::Cam%3BD88AEF02FD.attr preserve=no  private: CE3D_Camera * {UA} 
      CE3D_Camera *Cam;
      //## end CGameCamera::Cam%3BD88AEF02FD.attr

    // Additional Private Declarations
      //## begin CGameCamera%3B62D27300F0.private preserve=yes
      //## end CGameCamera%3B62D27300F0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGameCamera%3B62D27300F0.implementation preserve=yes
      //## end CGameCamera%3B62D27300F0.implementation

};

//## begin CGameCamera%3B62D27300F0.postscript preserve=yes
//## end CGameCamera%3B62D27300F0.postscript

// Class CGameCamera 

//## begin module%3B62D27300F0.epilog preserve=yes
//## end module%3B62D27300F0.epilog


#endif
