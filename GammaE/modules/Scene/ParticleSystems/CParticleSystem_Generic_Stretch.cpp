//## begin module%3B754D4401D5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B754D4401D5.cm

//## begin module%3B754D4401D5.cp preserve=no
//## end module%3B754D4401D5.cp

//## Module: CParticleSystem_Generic_Stretch%3B754D4401D5; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem_Generic_Stretch.cpp

//## begin module%3B754D4401D5.additionalIncludes preserve=no
//## end module%3B754D4401D5.additionalIncludes

//## begin module%3B754D4401D5.includes preserve=yes
//## end module%3B754D4401D5.includes

// CParticleSystem_Generic_Stretch
#include "Scene\ParticleSystems\CParticleSystem_Generic_Stretch.h"
//## begin module%3B754D4401D5.additionalDeclarations preserve=yes
//## end module%3B754D4401D5.additionalDeclarations


// Class CParticleSystem_Generic_Stretch 


CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch()
  //## begin CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch%.hasinit preserve=no
      : pParts(NULL)
  //## end CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch%.hasinit
  //## begin CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch%.initialization preserve=yes
  //## end CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch%.initialization
{
  //## begin CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch%.body preserve=yes
  //## end CParticleSystem_Generic_Stretch::CParticleSystem_Generic_Stretch%.body
}


CParticleSystem_Generic_Stretch::~CParticleSystem_Generic_Stretch()
{
  //## begin CParticleSystem_Generic_Stretch::~CParticleSystem_Generic_Stretch%.body preserve=yes
  //## end CParticleSystem_Generic_Stretch::~CParticleSystem_Generic_Stretch%.body
}



//## Other Operations (implementation)
void CParticleSystem_Generic_Stretch::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
  //## begin CParticleSystem_Generic_Stretch::InitPS%997641958.body preserve=yes
  	iParticleBytes = sizeof(TParticle_Stretch);
	CParticleSystem::InitPS(_iMaxParticles,_bZOrder,_bDisableZBuffer);
	pParts = (TParticle_Stretch*)Particle;
  //## end CParticleSystem_Generic_Stretch::InitPS%997641958.body
}

void CParticleSystem_Generic_Stretch::InitParticle (int iPart)
{
  //## begin CParticleSystem_Generic_Stretch::InitParticle%997543944.body preserve=yes
	TParticle_Stretch *P = &pParts[iPart];

	P->Pos.V3	(0,0,0);
	P->OldPos.V3(0,0,0);

	P->OldSpeed.V3   (fRandom(),fRandom(),fRandom());
 	P->OldSpeed.Sub  (0.5f,0.5f,0.5f);
	P->OldSpeed.Scale(fPInitialSpeedFact);
	P->OldSpeed.Add  (PSSpeed);

	P->Speed.Assign  (P->OldSpeed);	
		
	P->fSize   = fPInitialSizeFact  *fRandom();
	P->fEnergy = fPInitialEnergyFact*fRandom();

	P->Color.Assign(RGBAInitialValue);
  //## end CParticleSystem_Generic_Stretch::InitParticle%997543944.body
}

void CParticleSystem_Generic_Stretch::UpdateParticle (int iPart)
{
  //## begin CParticleSystem_Generic_Stretch::UpdateParticle%997543945.body preserve=yes
	static CVect3 Gravity(0,0,-9.8f);
	static CVect3 Aux;

	TParticle_Stretch *P = &pParts[iPart];
	P->fEnergy -= fPEnergyFact;	

	// x = x0 + vt
	Aux.Assign(P->OldSpeed);
	Aux.Scale(fDelta);
	
	P->OldPos.Assign(P->Pos);
	P->Pos.Add(Aux);

	// v = v0 + at
	Aux.Assign(Gravity);
	Aux.Scale (fDelta);

	P->OldSpeed.Assign(P->Speed);
	P->Speed.Add(Aux);
	
	// Setup alpha
	P->Color.Sub(RGBAFact);
  //## end CParticleSystem_Generic_Stretch::UpdateParticle%997543945.body
}

void CParticleSystem_Generic_Stretch::UpdatePS (CMatrix4x4* _ViewMatrix)
{
  //## begin CParticleSystem_Generic_Stretch::UpdatePS%997641956.body preserve=yes
  	if (fPSEnergy<=0) return;

	CVect3				NewPos;
	CVect3				OldPos;
	TParticle_Stretch	*P   = pParts;
	CVect3				*pVX = poMesh->VXs;
	CVect4				*pVC = poMesh->VCs;
	int					cPart;	

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

		OldPos.Assign( P->OldPos );
		_ViewMatrix->TransformPoint(OldPos);
		
		pVX[0].V3(-P->fSize,-P->fSize,0); pVX[0].Add(NewPos);
		pVX[1].V3(-P->fSize, P->fSize,0); pVX[1].Add(NewPos);
		pVX[2].V3( P->fSize, P->fSize,0); pVX[2].Add(OldPos);
		pVX[3].V3( P->fSize,-P->fSize,0); pVX[3].Add(OldPos);

		pVC[0].Assign(P->Color);
		pVC[1].Assign(P->Color);
		pVC[2].Assign(P->Color);
		pVC[3].Assign(P->Color);

		pVX += 4;
		pVC += 4;
		P++;
	}

  //## end CParticleSystem_Generic_Stretch::UpdatePS%997641956.body
}

// Additional Declarations
  //## begin CParticleSystem_Generic_Stretch%3B754D4401D5.declarations preserve=yes
  //## end CParticleSystem_Generic_Stretch%3B754D4401D5.declarations

//## begin module%3B754D4401D5.epilog preserve=yes
//## end module%3B754D4401D5.epilog
