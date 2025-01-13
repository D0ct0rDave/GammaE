//## begin module%3B72F78101D1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B72F78101D1.cm

//## begin module%3B72F78101D1.cp preserve=no
//## end module%3B72F78101D1.cp

//## Module: CParticleSystem%3B72F78101D1; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem.cpp

//## begin module%3B72F78101D1.additionalIncludes preserve=no
//## end module%3B72F78101D1.additionalIncludes

//## begin module%3B72F78101D1.includes preserve=yes
#include <stdlib.h>
#include <string.h>
// #include <iostream.h>

#include "Memory/GammaE_Mem.h"
//## end module%3B72F78101D1.includes

// CParticleSystem
#include "Scene\ParticleSystems\CParticleSystem.h"
//## begin module%3B72F78101D1.additionalDeclarations preserve=yes

CVect3 *pCurrentVXs = NULL;

int SortVXs( const void *a, const void *b)
{
	static CVect3 *pVXa,*pVXb;		

	pVXa = (CVect3 *)pCurrentVXs + *((unsigned short *)a);
	pVXb = (CVect3 *)pCurrentVXs + *((unsigned short *)b);

   	 if (pVXa->Z() < pVXb->Z()) return(-1);
else if (pVXa->Z() > pVXb->Z()) return( 1);
else							return( 0);   

}

//## end module%3B72F78101D1.additionalDeclarations


// Class CParticleSystem 













CParticleSystem::CParticleSystem()
  //## begin CParticleSystem::CParticleSystem%.hasinit preserve=no
      : iMaxParticles(0), Particle(NULL), fDelta(0), bPSRegen(false), fPSInitialEnergy(0), fPSEnergyFact(0), iParticleBytes(0), bZOrder(false), bDisableZBuffer(false)
  //## end CParticleSystem::CParticleSystem%.hasinit
  //## begin CParticleSystem::CParticleSystem%.initialization preserve=yes
  //## end CParticleSystem::CParticleSystem%.initialization
{
  //## begin CParticleSystem::CParticleSystem%.body preserve=yes
	bFrustumTest = 0;	
  //## end CParticleSystem::CParticleSystem%.body
}


CParticleSystem::~CParticleSystem()
{
  //## begin CParticleSystem::~CParticleSystem%.body preserve=yes
  //## end CParticleSystem::~CParticleSystem%.body
}



//## Other Operations (implementation)
void CParticleSystem::InitPS (int _iMaxParticles, bool _bZOrder, bool _bDisableZBuffer)
{
  //## begin CParticleSystem::InitPS%997390914.body preserve=yes
	int cPart;
	
	if (Particle) free(Particle);
	if (poMesh)	  mDel(poMesh);
	
	iMaxParticles = _iMaxParticles;
	Particle      = malloc(iParticleBytes*iMaxParticles);
	memset(Particle,0,iParticleBytes*iMaxParticles);
	
	// -----------------------------------------------------
	// InitMesh
	// -----------------------------------------------------	
	poMesh = new CMesh();
	poMesh->Init(iMaxParticles*4,iMaxParticles,E3D_MESH_QUADS,
				MESH_FIELD_VERTEXS  |
				MESH_FIELD_UVCOORDS | 
				MESH_FIELD_COLORS   | 
				MESH_FIELD_INDEXES);

	for (cPart=0;cPart<iMaxParticles;cPart++)
	{
		poMesh->Idxs[cPart*4+0] = cPart*4 + 1;
		poMesh->Idxs[cPart*4+1] = cPart*4 + 0;
		poMesh->Idxs[cPart*4+2] = cPart*4 + 3;
		poMesh->Idxs[cPart*4+3] = cPart*4 + 2;

		poMesh->UVs[cPart*4+0].V2(0.0f,0.0f);
		poMesh->UVs[cPart*4+1].V2(0.0f,1.0f);
		poMesh->UVs[cPart*4+2].V2(1.0f,1.0f);
		poMesh->UVs[cPart*4+3].V2(1.0f,0.0f);

		poMesh->VXs[cPart*4+0].V3(0.0f,0.0f,10000.0f);
		poMesh->VXs[cPart*4+1].V3(0.0f,0.0f,10000.0f);
		poMesh->VXs[cPart*4+2].V3(0.0f,0.0f,10000.0f);
		poMesh->VXs[cPart*4+3].V3(0.0f,0.0f,10000.0f);
	}

	// -----------------------------------------------------
	BVol = poMesh->GetBoundVol();
	bZOrder			= _bZOrder;
	bDisableZBuffer	= _bDisableZBuffer;
  //## end CParticleSystem::InitPS%997390914.body
}

void CParticleSystem::SetPSParams (bool _bPSRegen, float _fPSEnergy, float _fPSEnergyFact)
{
  //## begin CParticleSystem::SetPSParams%998089259.body preserve=yes
	bPSRegen		= _bPSRegen;
	fPSInitialEnergy= _fPSEnergy;
	fPSEnergy		= _fPSEnergy;
	fPSEnergyFact	= _fPSEnergyFact;
  //## end CParticleSystem::SetPSParams%998089259.body
}

void CParticleSystem::Think (float _fDelta)
{
  //## begin CParticleSystem::Think%997390915.body preserve=yes
	if (fPSEnergy<=0) return;
	
	fPSEnergy -= fPSEnergyFact;
	
	if (fPSEnergy<=0)
	{
		if (bPSRegen) fPSEnergy = fPSInitialEnergy;
	}

	fDelta     = _fDelta;
  //## end CParticleSystem::Think%997390915.body
}

void CParticleSystem::Render ()
{
  //## begin CParticleSystem::Render%997390917.body preserve=yes
  	CMatrix4x4	CurrentViewMat;
	bool		bEnableZBuffer = false;

	if (bDisableZBuffer)
		gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Current);

			Think( gpoE3DRenderer->REStats.DTime );	

			gpoE3DRenderer->GetCurrentMatrix(&CurrentViewMat);
		
				UpdatePS(&CurrentViewMat);
				if (bZOrder) OrderPS ();
				gpoE3DRenderer->ClearCameraMatrix();
				CObject3D_Leaf::Render();
	
			gpoE3DRenderer->SetCurrentMatrix(&CurrentViewMat);
	
	
	if (bEnableZBuffer)
		gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Current);		
  //## end CParticleSystem::Render%997390917.body
}

void CParticleSystem::OrderPS ()
{
  //## begin CParticleSystem::OrderPS%998089257.body preserve=yes
    pCurrentVXs = poMesh->VXs;
	qsort(poMesh->Idxs,iMaxParticles,4*sizeof(unsigned short),SortVXs);
  //## end CParticleSystem::OrderPS%998089257.body
}

// Additional Declarations
  //## begin CParticleSystem%3B72F78101D1.declarations preserve=yes
  //## end CParticleSystem%3B72F78101D1.declarations

//## begin module%3B72F78101D1.epilog preserve=yes
//## end module%3B72F78101D1.epilog
