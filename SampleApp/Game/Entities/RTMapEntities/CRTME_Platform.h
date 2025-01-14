//## begin module%3CDE418D0044.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDE418D0044.cm

//## begin module%3CDE418D0044.cp preserve=no
//## end module%3CDE418D0044.cp

//## Module: CRTME_Platform%3CDE418D0044; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Platform.h

#ifndef CRTME_Platform_h
#define CRTME_Platform_h 1

//## begin module%3CDE418D0044.additionalIncludes preserve=no
//## end module%3CDE418D0044.additionalIncludes

//## begin module%3CDE418D0044.includes preserve=yes
//## end module%3CDE418D0044.includes

// CGPhysicEntity
#include "Game\Entities\CGPhysicEntity.h"
// CRTME_Target
#include "Game\Entities\RTMapEntities\CRTME_Target.h"
// GammaE_Collision
#include "Collision\GammaE_Collision.h"
//## begin module%3CDE418D0044.additionalDeclarations preserve=yes
//## end module%3CDE418D0044.additionalDeclarations


//## begin CRTME_Platform%3CDE418D0044.preface preserve=yes
//## end CRTME_Platform%3CDE418D0044.preface

//## Class: CRTME_Platform%3CDE418D0044
//## Category: Game::Entities::RTMapEntities%3CDE40EE01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CE2EABD01FC;GammaE_Collision { -> }

class CRTME_Platform : public CRTME_Target  //## Inherits: <unnamed>%3CDE41D203D3
{
  //## begin CRTME_Platform%3CDE418D0044.initialDeclarations preserve=yes
  //## end CRTME_Platform%3CDE418D0044.initialDeclarations

  public:
    //## Constructors (generated)
      CRTME_Platform();

    //## Destructor (generated)
      ~CRTME_Platform();


    //## Other Operations (specified)
      //## Operation: Init%1021237870
      void Init (CMapEnt_Platform* _poPlatInfo);

      //## Operation: iDragEntity%1021565344
      int iDragEntity (CGPhysicEntity* _poEnt);

      //## Operation: Think%1021199184
      virtual void Think (float _fDelta);

      //## Operation: ProcessCmds%1021565349
      virtual void ProcessCmds (float _fDelta);

      //## Operation: Interact%1021578576
      virtual void Interact (float _fDelta);

    // Data Members for Class Attributes

      //## Attribute: poGrObj%3CDEF4AA0180
      //## begin CRTME_Platform::poGrObj%3CDEF4AA0180.attr preserve=no  public: CObject3D_Transf* {UA} NULL
      CObject3D_Transf* poGrObj;
      //## end CRTME_Platform::poGrObj%3CDEF4AA0180.attr

      //## Attribute: fFact%3CDEF54701AE
      //## begin CRTME_Platform::fFact%3CDEF54701AE.attr preserve=no  public: float {UA} 0.0f
      float fFact;
      //## end CRTME_Platform::fFact%3CDEF54701AE.attr

      //## Attribute: poPlatInfo%3CDEF7A4024E
      //## begin CRTME_Platform::poPlatInfo%3CDEF7A4024E.attr preserve=no  public: CMapEnt_Platform* {UA} NULL
      CMapEnt_Platform* poPlatInfo;
      //## end CRTME_Platform::poPlatInfo%3CDEF7A4024E.attr

      //## Attribute: fCurSpd%3CDEFE2501A8
      //## begin CRTME_Platform::fCurSpd%3CDEFE2501A8.attr preserve=no  public: float {UA} 0.0f
      float fCurSpd;
      //## end CRTME_Platform::fCurSpd%3CDEFE2501A8.attr

      //## Attribute: fCurAcc%3CDEFFD401C6
      //## begin CRTME_Platform::fCurAcc%3CDEFFD401C6.attr preserve=no  public: float {UA} 0.0f
      float fCurAcc;
      //## end CRTME_Platform::fCurAcc%3CDEFFD401C6.attr

      //## Attribute: oCurPos%3CDEFF5602C9
      //## begin CRTME_Platform::oCurPos%3CDEFF5602C9.attr preserve=no  public: CVect3 {UA} 
      CVect3 oCurPos;
      //## end CRTME_Platform::oCurPos%3CDEFF5602C9.attr

      //## Attribute: oSpdDir%3CE00F4002AF
      //## begin CRTME_Platform::oSpdDir%3CE00F4002AF.attr preserve=no  public: CVect3 {UA} 
      CVect3 oSpdDir;
      //## end CRTME_Platform::oSpdDir%3CE00F4002AF.attr

      //## Attribute: iState%3CE0183C03BB
      //## begin CRTME_Platform::iState%3CE0183C03BB.attr preserve=no  public: int {UA} 0
      int iState;
      //## end CRTME_Platform::iState%3CE0183C03BB.attr

      //## Attribute: fDecel%3CE02FF0032A
      //## begin CRTME_Platform::fDecel%3CE02FF0032A.attr preserve=no  public: float {UA} 
      float fDecel;
      //## end CRTME_Platform::fDecel%3CE02FF0032A.attr

      //## Attribute: fAccel%3CE0303B01E8
      //## begin CRTME_Platform::fAccel%3CE0303B01E8.attr preserve=no  public: float {UA} 
      float fAccel;
      //## end CRTME_Platform::fAccel%3CE0303B01E8.attr

      //## Attribute: fCurFact%3CE0440B006E
      //## begin CRTME_Platform::fCurFact%3CE0440B006E.attr preserve=no  public: float {UA} 0.0f
      float fCurFact;
      //## end CRTME_Platform::fCurFact%3CE0440B006E.attr

      //## Attribute: poColObj%3CE2EAA70326
      //## begin CRTME_Platform::poColObj%3CE2EAA70326.attr preserve=no  public: CCOL_Collider * {UA} NULL
      CCOL_Collider *poColObj;
      //## end CRTME_Platform::poColObj%3CE2EAA70326.attr

      //## Attribute: bChDir%3CE3E37E0243
      //## begin CRTME_Platform::bChDir%3CE3E37E0243.attr preserve=no  public: bool {UA} false
      bool bChDir;
      //## end CRTME_Platform::bChDir%3CE3E37E0243.attr

    // Data Members for Associations

      //## Association: Game::Entities::RTMapEntities::<unnamed>%3CE3DDF001BC
      //## Role: CRTME_Platform::aoDragged%3CE3DDF00253
      //## begin CRTME_Platform::aoDragged%3CE3DDF00253.role preserve=no  public: CGPhysicEntity { -> UHAN}
      CStArray <CGPhysicEntity*> aoDragged;
      //## end CRTME_Platform::aoDragged%3CE3DDF00253.role

    // Additional Public Declarations
      //## begin CRTME_Platform%3CDE418D0044.public preserve=yes
      //## end CRTME_Platform%3CDE418D0044.public

  protected:
    // Additional Protected Declarations
      //## begin CRTME_Platform%3CDE418D0044.protected preserve=yes
      //## end CRTME_Platform%3CDE418D0044.protected

  private:
    // Additional Private Declarations
      //## begin CRTME_Platform%3CDE418D0044.private preserve=yes
      //## end CRTME_Platform%3CDE418D0044.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CRTME_Platform%3CDE418D0044.implementation preserve=yes
      //## end CRTME_Platform%3CDE418D0044.implementation

};

//## begin CRTME_Platform%3CDE418D0044.postscript preserve=yes
//## end CRTME_Platform%3CDE418D0044.postscript

// Class CRTME_Platform 

//## begin module%3CDE418D0044.epilog preserve=yes
//## end module%3CDE418D0044.epilog


#endif
