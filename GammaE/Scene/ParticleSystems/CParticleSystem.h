//## begin module%3B72F78101D1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B72F78101D1.cm

//## begin module%3B72F78101D1.cp preserve=no
//## end module%3B72F78101D1.cp

//## Module: CParticleSystem%3B72F78101D1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem.h

#ifndef CParticleSystem_h
#define CParticleSystem_h 1

//## begin module%3B72F78101D1.additionalIncludes preserve=no
//## end module%3B72F78101D1.additionalIncludes

//## begin module%3B72F78101D1.includes preserve=yes
#include <stdlib.h>
//## end module%3B72F78101D1.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3B72F78101D1.additionalDeclarations preserve=yes
inline float fRandom()
{
	return ((float)rand() / (float)RAND_MAX);
}
//## end module%3B72F78101D1.additionalDeclarations


//## begin CParticleSystem%3B72F78101D1.preface preserve=yes
//## end CParticleSystem%3B72F78101D1.preface

//## Class: CParticleSystem%3B72F78101D1
//## Category: Scene::ParticleSystems%3AABF9E8005A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CParticleSystem : public CObject3D_Leaf  //## Inherits: <unnamed>%3B72F7930340
{
  //## begin CParticleSystem%3B72F78101D1.initialDeclarations preserve=yes
  //## end CParticleSystem%3B72F78101D1.initialDeclarations

  public:
    //## Constructors (generated)
      CParticleSystem();

    //## Destructor (generated)
      virtual ~CParticleSystem();


    //## Other Operations (specified)
      //## Operation: InitPS%997390914
      virtual void InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer);

      //## Operation: SetPSParams%998089259
      void SetPSParams (bool _bPSRegen, float _fPSEnergy, float _fPSEnergyFact);

      //## Operation: Think%997390915
      virtual void Think (float _fDelta);

      //## Operation: InitParticle%997390916
      virtual void InitParticle (int iPart) = 0;

      //## Operation: Render%997390917
      virtual void Render ();

      //## Operation: UpdatePS%997390918
      virtual void UpdatePS (CMatrix4x4* _ViewMatrix) = 0;

      //## Operation: UpdateParticle%997390919
      virtual void UpdateParticle (int iPart) = 0;

      //## Operation: OrderPS%998089257
      void OrderPS ();

    // Data Members for Class Attributes

      //## Attribute: PSSpeed%3B74706500E6
      //## begin CParticleSystem::PSSpeed%3B74706500E6.attr preserve=no  public: CVect3 {UA} 
      CVect3 PSSpeed;
      //## end CParticleSystem::PSSpeed%3B74706500E6.attr

    // Additional Public Declarations
      //## begin CParticleSystem%3B72F78101D1.public preserve=yes
      //## end CParticleSystem%3B72F78101D1.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iMaxParticles%3B72F7AC02E2
      //## begin CParticleSystem::iMaxParticles%3B72F7AC02E2.attr preserve=no  protected: int {UA} 0
      int iMaxParticles;
      //## end CParticleSystem::iMaxParticles%3B72F7AC02E2.attr

      //## Attribute: Particle%3B72FA3003D8
      //## begin CParticleSystem::Particle%3B72FA3003D8.attr preserve=no  protected: void * {UA} NULL
      void *Particle;
      //## end CParticleSystem::Particle%3B72FA3003D8.attr

      //## Attribute: fDelta%3B72FAB0031E
      //## begin CParticleSystem::fDelta%3B72FAB0031E.attr preserve=no  protected: float {UA} 0
      float fDelta;
      //## end CParticleSystem::fDelta%3B72FAB0031E.attr

      //## Attribute: bPSRegen%3B72FBB800B0
      //## begin CParticleSystem::bPSRegen%3B72FBB800B0.attr preserve=no  protected: bool {UA} false
      bool bPSRegen;
      //## end CParticleSystem::bPSRegen%3B72FBB800B0.attr

      //## Attribute: fPSInitialEnergy%3B72FBBC03E1
      //## begin CParticleSystem::fPSInitialEnergy%3B72FBBC03E1.attr preserve=no  protected: float {UA} 0
      float fPSInitialEnergy;
      //## end CParticleSystem::fPSInitialEnergy%3B72FBBC03E1.attr

      //## Attribute: fPSEnergyFact%3B74668402D4
      //## begin CParticleSystem::fPSEnergyFact%3B74668402D4.attr preserve=no  protected: float {UA} 0
      float fPSEnergyFact;
      //## end CParticleSystem::fPSEnergyFact%3B74668402D4.attr

      //## Attribute: fPSEnergy%3B74670E03AF
      //## begin CParticleSystem::fPSEnergy%3B74670E03AF.attr preserve=no  protected: float {UA} 
      float fPSEnergy;
      //## end CParticleSystem::fPSEnergy%3B74670E03AF.attr

      //## Attribute: iParticleBytes%3B76CD860207
      //## begin CParticleSystem::iParticleBytes%3B76CD860207.attr preserve=no  protected: int {UA} 0
      int iParticleBytes;
      //## end CParticleSystem::iParticleBytes%3B76CD860207.attr

      //## Attribute: bZOrder%3B7DA4CA03DD
      //## begin CParticleSystem::bZOrder%3B7DA4CA03DD.attr preserve=no  protected: bool {UA} false
      bool bZOrder;
      //## end CParticleSystem::bZOrder%3B7DA4CA03DD.attr

    // Additional Protected Declarations
      //## begin CParticleSystem%3B72F78101D1.protected preserve=yes
      //## end CParticleSystem%3B72F78101D1.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: bDisableZBuffer%3B7DBBFF037C
      //## begin CParticleSystem::bDisableZBuffer%3B7DBBFF037C.attr preserve=no  private: bool {UA} false
      bool bDisableZBuffer;
      //## end CParticleSystem::bDisableZBuffer%3B7DBBFF037C.attr

    // Additional Private Declarations
      //## begin CParticleSystem%3B72F78101D1.private preserve=yes
      //## end CParticleSystem%3B72F78101D1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CParticleSystem%3B72F78101D1.implementation preserve=yes
      //## end CParticleSystem%3B72F78101D1.implementation

};

//## begin CParticleSystem%3B72F78101D1.postscript preserve=yes
//## end CParticleSystem%3B72F78101D1.postscript

// Class CParticleSystem 

//## begin module%3B72F78101D1.epilog preserve=yes
//## end module%3B72F78101D1.epilog


#endif