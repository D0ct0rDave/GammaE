//## begin module%3B754F8F0098.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B754F8F0098.cm

//## begin module%3B754F8F0098.cp preserve=no
//## end module%3B754F8F0098.cp

//## Module: cParticleSystem_Generic_Quad%3B754F8F0098; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\cParticleSystem_Generic_Quad.cpp

//## begin module%3B754F8F0098.additionalIncludes preserve=no
//## end module%3B754F8F0098.additionalIncludes

//## begin module%3B754F8F0098.includes preserve=yes
//## end module%3B754F8F0098.includes

// cParticleSystem_Generic_Quad
#include "Scene\ParticleSystems\cParticleSystem_Generic_Quad.h"
//## begin module%3B754F8F0098.additionalDeclarations preserve=yes
//## end module%3B754F8F0098.additionalDeclarations


// Class cParticleSystem_Generic_Quad 


cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad()
  //## begin cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad%.hasinit preserve=no
      : pParts(NULL)
  //## end cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad%.hasinit
  //## begin cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad%.initialization preserve=yes
  //## end cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad%.initialization
{
  //## begin cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad%.body preserve=yes
	iParticleBytes = sizeof(TParticle_Quad);
  //## end cParticleSystem_Generic_Quad::cParticleSystem_Generic_Quad%.body
}


cParticleSystem_Generic_Quad::~cParticleSystem_Generic_Quad()
{
  //## begin cParticleSystem_Generic_Quad::~cParticleSystem_Generic_Quad%.body preserve=yes
  //## end cParticleSystem_Generic_Quad::~cParticleSystem_Generic_Quad%.body
}



//## Other Operations (implementation)
void cParticleSystem_Generic_Quad::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
  //## begin cParticleSystem_Generic_Quad::InitPS%997641957.body preserve=yes
  	iParticleBytes = sizeof(TParticle_Quad);
	
	CParticleSystem::InitPS(_iMaxParticles,_bZOrder,_bDisableZBuffer);
	
	pParts = (TParticle_Quad *)Particle;
  //## end cParticleSystem_Generic_Quad::InitPS%997641957.body
}

void cParticleSystem_Generic_Quad::InitParticle (int iPart)
{
  //## begin cParticleSystem_Generic_Quad::InitParticle%997543942.body preserve=yes
	TParticle_Quad *P = &pParts[iPart];

	P->Pos.V3	(0,0,0);

	P->OldSpeed.V3   (fRandom(),fRandom(),fRandom());
 	P->OldSpeed.Sub  (0.5f,0.5f,0.5f);
	P->OldSpeed.Scale(fPInitialSpeedFact);
	P->OldSpeed.Add  (PSSpeed);

	P->Speed.Assign  (P->OldSpeed);	
		
	P->fSize   = fPInitialSizeFact  *fRandom();
	P->fEnergy = fPInitialEnergyFact*fRandom();

	P->Color.Assign(RGBAInitialValue);
  //## end cParticleSystem_Generic_Quad::InitParticle%997543942.body
}

void cParticleSystem_Generic_Quad::UpdateParticle (int iPart)
{
  //## begin cParticleSystem_Generic_Quad::UpdateParticle%997543943.body preserve=yes
	static CVect3 Gravity(0,0,-9.8f);
	static CVect3 Aux;

	TParticle_Quad *P = &pParts[iPart];
	P->fEnergy -= fPEnergyFact;	

	// x = x0 + vt
	Aux.Assign(P->OldSpeed);
	Aux.Scale(fDelta);
	
	P->Pos.Add(Aux);

	// v = v0 + at
	Aux.Assign(Gravity);
	Aux.Scale (fDelta);

	P->OldSpeed.Assign(P->Speed);
	P->Speed.Add(Aux);
	
	// Setup alpha
	P->Color.Sub(RGBAFact);
  //## end cParticleSystem_Generic_Quad::UpdateParticle%997543943.body
}

void cParticleSystem_Generic_Quad::UpdatePS (CMatrix4x4* _ViewMatrix)
{
  //## begin cParticleSystem_Generic_Quad::UpdatePS%997641955.body preserve=yes
  	if (fPSEnergy<=0) return;

	/*	
	if (bZOrder)
	{
		UpdatePSZOrder(_ViewMatrix);
		return;
	}
	*/

	CVect3			NewPos;
	TParticle_Quad	*P   = pParts;
	CVect3			*pVX = poMesh->VXs;
	CVect4			*pVC = poMesh->VCs;
	int				cPart;	

	for (cPart=0;cPart<iMaxParticles;cPart++)
	{		
		if (P->fEnergy <= 0)
		{
			if ((bPSRegen) && (fPSEnergy>=0))
				InitParticle(cPart);
		}
		UpdateParticle (cPart);

		NewPos.Assign( P->Pos );		
		_ViewMatrix->TransformPoint(NewPos);
	
		pVX[0].V3(-P->fSize,-P->fSize,0); pVX[0].Add(NewPos);
		pVX[1].V3(-P->fSize, P->fSize,0); pVX[1].Add(NewPos);
		pVX[2].V3( P->fSize, P->fSize,0); pVX[2].Add(NewPos);
		pVX[3].V3( P->fSize,-P->fSize,0); pVX[3].Add(NewPos);

		pVC[0].Assign(P->Color);
		pVC[1].Assign(P->Color);
		pVC[2].Assign(P->Color);
		pVC[3].Assign(P->Color);

		pVX += 4;
		pVC += 4;
		P++;
	}
  //## end cParticleSystem_Generic_Quad::UpdatePS%997641955.body
}

// Additional Declarations
  //## begin cParticleSystem_Generic_Quad%3B754F8F0098.declarations preserve=yes
  //## end cParticleSystem_Generic_Quad%3B754F8F0098.declarations

//## begin module%3B754F8F0098.epilog preserve=yes
//## end module%3B754F8F0098.epilog
