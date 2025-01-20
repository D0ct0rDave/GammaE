//## begin module%3B754D4401D5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B754D4401D5.cm

//## begin module%3B754D4401D5.cp preserve=no
//## end module%3B754D4401D5.cp

//## Module: CParticleSystem_Generic_Stretch%3B754D4401D5; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem_Generic_Stretch.h

#ifndef CParticleSystem_Generic_Stretch_h
#define CParticleSystem_Generic_Stretch_h 1

//## begin module%3B754D4401D5.additionalIncludes preserve=no
//## end module%3B754D4401D5.additionalIncludes

//## begin module%3B754D4401D5.includes preserve=yes
//## end module%3B754D4401D5.includes

// CParticleSystem_Generic
#include "Scene\ParticleSystems\CParticleSystem_Generic.h"
//## begin module%3B754D4401D5.additionalDeclarations preserve=yes

typedef struct{
	
	CVect3 Pos;
	CVect3 OldPos;

	CVect3 Speed;	
	CVect3 OldSpeed;
	
	CVect4 Color;

	float  fSize;
	float  fEnergy;

}TParticle_Stretch;

//## end module%3B754D4401D5.additionalDeclarations


//## begin CParticleSystem_Generic_Stretch%3B754D4401D5.preface preserve=yes
//## end CParticleSystem_Generic_Stretch%3B754D4401D5.preface

//## Class: CParticleSystem_Generic_Stretch%3B754D4401D5
//## Category: Scene::ParticleSystems%3AABF9E8005A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CParticleSystem_Generic_Stretch : public CParticleSystem_Generic  //## Inherits: <unnamed>%3B754FA400AC
{
  //## begin CParticleSystem_Generic_Stretch%3B754D4401D5.initialDeclarations preserve=yes
  //## end CParticleSystem_Generic_Stretch%3B754D4401D5.initialDeclarations

  public:
    //## Constructors (generated)
      CParticleSystem_Generic_Stretch();

    //## Destructor (generated)
      virtual ~CParticleSystem_Generic_Stretch();


    //## Other Operations (specified)
      //## Operation: InitPS%997641958
      virtual void InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer);

      //## Operation: InitParticle%997543944
      virtual void InitParticle (int iPart);

      //## Operation: UpdateParticle%997543945
      virtual void UpdateParticle (int iPart);

      //## Operation: UpdatePS%997641956
      virtual void UpdatePS (CMatrix4x4* _ViewMatrix);

    // Additional Public Declarations
      //## begin CParticleSystem_Generic_Stretch%3B754D4401D5.public preserve=yes
      //## end CParticleSystem_Generic_Stretch%3B754D4401D5.public

  protected:
    // Additional Protected Declarations
      //## begin CParticleSystem_Generic_Stretch%3B754D4401D5.protected preserve=yes
      //## end CParticleSystem_Generic_Stretch%3B754D4401D5.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: pParts%3B76CF4F0091
      //## begin CParticleSystem_Generic_Stretch::pParts%3B76CF4F0091.attr preserve=no  private: TParticle_Stretch * {UA} NULL
      TParticle_Stretch *pParts;
      //## end CParticleSystem_Generic_Stretch::pParts%3B76CF4F0091.attr

    // Additional Private Declarations
      //## begin CParticleSystem_Generic_Stretch%3B754D4401D5.private preserve=yes
      //## end CParticleSystem_Generic_Stretch%3B754D4401D5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CParticleSystem_Generic_Stretch%3B754D4401D5.implementation preserve=yes
      //## end CParticleSystem_Generic_Stretch%3B754D4401D5.implementation

};

//## begin CParticleSystem_Generic_Stretch%3B754D4401D5.postscript preserve=yes
//## end CParticleSystem_Generic_Stretch%3B754D4401D5.postscript

// Class CParticleSystem_Generic_Stretch 

//## begin module%3B754D4401D5.epilog preserve=yes
//## end module%3B754D4401D5.epilog


#endif
