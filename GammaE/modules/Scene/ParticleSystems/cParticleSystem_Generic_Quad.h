//## begin module%3B754F8F0098.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B754F8F0098.cm

//## begin module%3B754F8F0098.cp preserve=no
//## end module%3B754F8F0098.cp

//## Module: cParticleSystem_Generic_Quad%3B754F8F0098; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\cParticleSystem_Generic_Quad.h

#ifndef cParticleSystem_Generic_Quad_h
#define cParticleSystem_Generic_Quad_h 1

//## begin module%3B754F8F0098.additionalIncludes preserve=no
//## end module%3B754F8F0098.additionalIncludes

//## begin module%3B754F8F0098.includes preserve=yes
//## end module%3B754F8F0098.includes

// CParticleSystem_Generic
#include "Scene\ParticleSystems\CParticleSystem_Generic.h"
//## begin module%3B754F8F0098.additionalDeclarations preserve=yes

typedef struct{
	
	CVect3 Pos;
	
	CVect3 Speed;	
	CVect3 OldSpeed;
	
	CVect4 Color;

	float  fSize;
	float  fEnergy;

}TParticle_Quad;

//## end module%3B754F8F0098.additionalDeclarations


//## begin cParticleSystem_Generic_Quad%3B754F8F0098.preface preserve=yes
//## end cParticleSystem_Generic_Quad%3B754F8F0098.preface

//## Class: cParticleSystem_Generic_Quad%3B754F8F0098
//## Category: Scene::ParticleSystems%3AABF9E8005A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class cParticleSystem_Generic_Quad : public CParticleSystem_Generic  //## Inherits: <unnamed>%3B754FA601A0
{
  //## begin cParticleSystem_Generic_Quad%3B754F8F0098.initialDeclarations preserve=yes
  //## end cParticleSystem_Generic_Quad%3B754F8F0098.initialDeclarations

  public:
    //## Constructors (generated)
      cParticleSystem_Generic_Quad();

    //## Destructor (generated)
      virtual ~cParticleSystem_Generic_Quad();


    //## Other Operations (specified)
      //## Operation: InitPS%997641957
      virtual void InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer);

      //## Operation: InitParticle%997543942
      virtual void InitParticle (int iPart);

      //## Operation: UpdateParticle%997543943
      virtual void UpdateParticle (int iPart);

      //## Operation: UpdatePS%997641955
      virtual void UpdatePS (CMatrix4x4* _ViewMatrix);

    // Additional Public Declarations
      //## begin cParticleSystem_Generic_Quad%3B754F8F0098.public preserve=yes
      //## end cParticleSystem_Generic_Quad%3B754F8F0098.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: pParts%3B76CF02039E
      //## begin cParticleSystem_Generic_Quad::pParts%3B76CF02039E.attr preserve=no  protected: TParticle_Quad * {UA} NULL
      TParticle_Quad *pParts;
      //## end cParticleSystem_Generic_Quad::pParts%3B76CF02039E.attr

    // Additional Protected Declarations
      //## begin cParticleSystem_Generic_Quad%3B754F8F0098.protected preserve=yes
      //## end cParticleSystem_Generic_Quad%3B754F8F0098.protected

  private:
    // Additional Private Declarations
      //## begin cParticleSystem_Generic_Quad%3B754F8F0098.private preserve=yes
      //## end cParticleSystem_Generic_Quad%3B754F8F0098.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin cParticleSystem_Generic_Quad%3B754F8F0098.implementation preserve=yes
      //## end cParticleSystem_Generic_Quad%3B754F8F0098.implementation

};

//## begin cParticleSystem_Generic_Quad%3B754F8F0098.postscript preserve=yes
//## end cParticleSystem_Generic_Quad%3B754F8F0098.postscript

// Class cParticleSystem_Generic_Quad 

//## begin module%3B754F8F0098.epilog preserve=yes
//## end module%3B754F8F0098.epilog


#endif
