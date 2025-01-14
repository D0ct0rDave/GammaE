//## begin module%3B7DA09D0386.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7DA09D0386.cm

//## begin module%3B7DA09D0386.cp preserve=no
//## end module%3B7DA09D0386.cp

//## Module: CGPhysicEntity%3B7DA09D0386; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\CGPhysicEntity.h

#ifndef CGPhysicEntity_h
#define CGPhysicEntity_h 1

//## begin module%3B7DA09D0386.additionalIncludes preserve=no
//## end module%3B7DA09D0386.additionalIncludes

//## begin module%3B7DA09D0386.includes preserve=yes
#include "Math/GammaE_Math.h"
extern CVect3 GRAVITY;
//## end module%3B7DA09D0386.includes

// CGPhysic_ResponseType
#include "Game\Entities\CGPhysic_ResponseType.h"
// CGameEntity
#include "Game\Entities\CGameEntity.h"
// GammaE_Collision
#include "Collision\GammaE_Collision.h"
//## begin module%3B7DA09D0386.additionalDeclarations preserve=yes
#define MAX_FORCES 10
//## end module%3B7DA09D0386.additionalDeclarations


//## begin CGPhysicEntity%3B7DA09D0386.preface preserve=yes
//## end CGPhysicEntity%3B7DA09D0386.preface

//## Class: CGPhysicEntity%3B7DA09D0386
//## Category: Game::Entities%3B5DE99E0136
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C168B3002D2;GammaE_Collision { -> }

class CGPhysicEntity : public CGameEntity  //## Inherits: <unnamed>%3B7DA1360079
{
  //## begin CGPhysicEntity%3B7DA09D0386.initialDeclarations preserve=yes
  //## end CGPhysicEntity%3B7DA09D0386.initialDeclarations

  public:
    //## Constructors (generated)
      CGPhysicEntity();

    //## Destructor (generated)
      ~CGPhysicEntity();


    //## Other Operations (specified)
      //## Operation: bCheckCollisions%1008108906
      virtual bool bCheckCollisions ();

      //## Operation: ComputeCollisionResponse%1008204519
      virtual void ComputeCollisionResponse ();

      //## Operation: AddForce%1021497760
      void AddForce (CVect3& _roForce);

      //## Operation: oFinalForce%1021497761
      CVect3 oFinalForce ();

      //## Operation: ClearForces%1021497762
      void ClearForces ();

      //## Operation: ApplyForces%1021497763
      void ApplyForces (float _fDelta);

      //## Operation: ProcessCmds%1021497764
      virtual void ProcessCmds (float _fDelta);

      //## Operation: roColObj%1021578575
      CCOL_Collider& roColObj ();

    // Data Members for Associations

      //## Association: Game::Entities::<unnamed>%3C17FA800248
      //## Role: CGPhysicEntity::ResponseType%3C17FA8003BA
      //## begin CGPhysicEntity::ResponseType%3C17FA8003BA.role preserve=no  public: CGPhysic_ResponseType { -> VHAN}
      CGPhysic_ResponseType ResponseType;
      //## end CGPhysicEntity::ResponseType%3C17FA8003BA.role

    // Additional Public Declarations
      //## begin CGPhysicEntity%3B7DA09D0386.public preserve=yes
      //## end CGPhysicEntity%3B7DA09D0386.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iColTris%3C1685460307
      //## begin CGPhysicEntity::iColTris%3C1685460307.attr preserve=no  protected: int {UA} 
      int iColTris;
      //## end CGPhysicEntity::iColTris%3C1685460307.attr

      //## Attribute: fMass%3C17FAC702A4
      //## begin CGPhysicEntity::fMass%3C17FAC702A4.attr preserve=no  protected: float {UA} 
      float fMass;
      //## end CGPhysicEntity::fMass%3C17FAC702A4.attr

      //## Attribute: iZombieTime%3C17FE860126
      //## begin CGPhysicEntity::iZombieTime%3C17FE860126.attr preserve=no  protected: int {UA} 0
      int iZombieTime;
      //## end CGPhysicEntity::iZombieTime%3C17FE860126.attr

      //## Attribute: fRestitutionFact%3C1E90A6013F
      //## begin CGPhysicEntity::fRestitutionFact%3C1E90A6013F.attr preserve=no  protected: float {UA} 0.5f
      float fRestitutionFact;
      //## end CGPhysicEntity::fRestitutionFact%3C1E90A6013F.attr

      //## Attribute: iContacts%3C291059036A
      //## begin CGPhysicEntity::iContacts%3C291059036A.attr preserve=no  protected: int {UA} 0
      int iContacts;
      //## end CGPhysicEntity::iContacts%3C291059036A.attr

      //## Attribute: oColObj%3CC096720301
      //## begin CGPhysicEntity::oColObj%3CC096720301.attr preserve=no  protected: CCOL_Collider {UA} 
      CCOL_Collider oColObj;
      //## end CGPhysicEntity::oColObj%3CC096720301.attr

      //## Attribute: a5oForces%3CE2D27D01A5
      //## begin CGPhysicEntity::a5oForces%3CE2D27D01A5.attr preserve=no  protected: CVect3[MAX_FORCES] {UA} 
      CVect3 a5oForces[MAX_FORCES];
      //## end CGPhysicEntity::a5oForces%3CE2D27D01A5.attr

      //## Attribute: iNumForces%3CE2D28702E0
      //## begin CGPhysicEntity::iNumForces%3CE2D28702E0.attr preserve=no  protected: int {UA} 0
      int iNumForces;
      //## end CGPhysicEntity::iNumForces%3CE2D28702E0.attr

    // Additional Protected Declarations
      //## begin CGPhysicEntity%3B7DA09D0386.protected preserve=yes
      //## end CGPhysicEntity%3B7DA09D0386.protected

  private:
    // Additional Private Declarations
      //## begin CGPhysicEntity%3B7DA09D0386.private preserve=yes
      //## end CGPhysicEntity%3B7DA09D0386.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGPhysicEntity%3B7DA09D0386.implementation preserve=yes
      //## end CGPhysicEntity%3B7DA09D0386.implementation

};

//## begin CGPhysicEntity%3B7DA09D0386.postscript preserve=yes
//## end CGPhysicEntity%3B7DA09D0386.postscript

// Class CGPhysicEntity 


//## Other Operations (inline)
inline void CGPhysicEntity::AddForce (CVect3& _roForce)
{
  //## begin CGPhysicEntity::AddForce%1021497760.body preserve=yes
	if (iNumForces >= MAX_FORCES) return;
	a5oForces[iNumForces++].Assign(_roForce);
  //## end CGPhysicEntity::AddForce%1021497760.body
}

inline CVect3 CGPhysicEntity::oFinalForce ()
{
  //## begin CGPhysicEntity::oFinalForce%1021497761.body preserve=yes
	CVect3 oRes(0.0f,0.0f,0.0f);
	if (iNumForces>0)
	{
		oRes.Assign(a5oForces[0]);
		for (int i=1;i<iNumForces;i++)
			oRes.Add(a5oForces[i]);
	}
	
	return(oRes);
  //## end CGPhysicEntity::oFinalForce%1021497761.body
}

inline void CGPhysicEntity::ClearForces ()
{
  //## begin CGPhysicEntity::ClearForces%1021497762.body preserve=yes
	iNumForces=0;
  //## end CGPhysicEntity::ClearForces%1021497762.body
}

inline CCOL_Collider& CGPhysicEntity::roColObj ()
{
  //## begin CGPhysicEntity::roColObj%1021578575.body preserve=yes
	return(oColObj);
  //## end CGPhysicEntity::roColObj%1021578575.body
}

//## begin module%3B7DA09D0386.epilog preserve=yes
//## end module%3B7DA09D0386.epilog


#endif
