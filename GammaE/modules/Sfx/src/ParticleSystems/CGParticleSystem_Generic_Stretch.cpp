




// CGParticleSystem_Generic_Stretch
#include "ParticleSystems\CGParticleSystem_Generic_Stretch.h"


// Class CGParticleSystem_Generic_Stretch 


CGParticleSystem_Generic_Stretch::CGParticleSystem_Generic_Stretch()
        : pParts(NULL)
      {
}


CGParticleSystem_Generic_Stretch::~CGParticleSystem_Generic_Stretch()
{
}



void CGParticleSystem_Generic_Stretch::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
    	iParticleBytes = sizeof(TParticle_Stretch);
	CGParticleSystem::InitPS(_iMaxParticles,_bZOrder,_bDisableZBuffer);
	pParts = (TParticle_Stretch*)Particle;
}

void CGParticleSystem_Generic_Stretch::InitParticle (int iPart)
{
  	TParticle_Stretch *P = &pParts[iPart];

	P->Pos.V3	(0,0,0);
	P->OldPos.V3(0,0,0);

	P->OldSpeed.V3   (MATH_Common::fRand(),MATH_Common::fRand(),MATH_Common::fRand());
 	P->OldSpeed.Sub  (0.5f,0.5f,0.5f);
	P->OldSpeed.Scale(fPInitialSpeedFact);
	P->OldSpeed.Add  (PSSpeed);

	P->Speed.Assign  (P->OldSpeed);	
		
	P->fSize   = fPInitialSizeFact  *MATH_Common::fRand();
	P->fEnergy = fPInitialEnergyFact*MATH_Common::fRand();

	P->Color.Assign(RGBAInitialValue);
}

void CGParticleSystem_Generic_Stretch::UpdateParticle (int iPart)
{
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
}

void CGParticleSystem_Generic_Stretch::UpdatePS (CMatrix4x4* _ViewMatrix)
{
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
}

// Additional Declarations
    
