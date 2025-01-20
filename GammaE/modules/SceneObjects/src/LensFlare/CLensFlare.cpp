//## begin module%3BB24FC100F3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB24FC100F3.cm

//## begin module%3BB24FC100F3.cp preserve=no
//## end module%3BB24FC100F3.cp

//## Module: CLensFlare%3BB24FC100F3; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\LensFlare\CLensFlare.cpp

//## begin module%3BB24FC100F3.additionalIncludes preserve=no
//## end module%3BB24FC100F3.additionalIncludes

//## begin module%3BB24FC100F3.includes preserve=yes
//## end module%3BB24FC100F3.includes

// CLensFlare
#include "SceneObjects\LensFlare\CLensFlare.h"
//## begin module%3BB24FC100F3.additionalDeclarations preserve=yes
#define _1_OVER_SQRT_2 0.70710678118654752440084436210485
//## end module%3BB24FC100F3.additionalDeclarations


// Class CLensFlare 





CLensFlare::CLensFlare()
  //## begin CLensFlare::CLensFlare%.hasinit preserve=no
      : FlareElems(NULL), iNumElems(0), MeshArray(NULL)
  //## end CLensFlare::CLensFlare%.hasinit
  //## begin CLensFlare::CLensFlare%.initialization preserve=yes
  //## end CLensFlare::CLensFlare%.initialization
{
  //## begin CLensFlare::CLensFlare%.body preserve=yes
  //## end CLensFlare::CLensFlare%.body
}


CLensFlare::~CLensFlare()
{
  //## begin CLensFlare::~CLensFlare%.body preserve=yes
	if (FlareElems)	delete []FlareElems;	
  //## end CLensFlare::~CLensFlare%.body
}



//## Other Operations (implementation)
void CLensFlare::InitLensFlare (int _iNumElems, CVect3 _SunPos)
{
  //## begin CLensFlare::InitLensFlare%1001541675.body preserve=yes
	
	// Setup lens flare properties
	SunPos.Assign(_SunPos);
	iNumElems   = _iNumElems;

	// -----------------------------------------------------
	// Create the flare elem array
	// -----------------------------------------------------
	FlareElems = new CLensFlare_Elem[iNumElems];

	// -----------------------------------------------------
	// Create the flare elem array
	// -----------------------------------------------------
	MeshArray  = new CMesh_Rect[iNumElems];	
  //## end CLensFlare::InitLensFlare%1001541675.body
}

void CLensFlare::SetupFlareElem (int _iElem, float _fSize, float _fDist, CVect4 _Color, CE3D_Shader *_pMat)
{
  //## begin CLensFlare::SetupFlareElem%1001625477.body preserve=yes
	assert (FlareElems		     && "NULL Lens flare elem array");
	assert ((_iElem < iNumElems) && "Flare elem out of bounds");

	FlareElems[_iElem].fSize	= _fSize;
	FlareElems[_iElem].fDist	= _fDist;
	FlareElems[_iElem].Color.Assign(_Color);
	FlareElems[_iElem].pMaterial= _pMat;
  //## end CLensFlare::SetupFlareElem%1001625477.body
}

void CLensFlare::UpdateLensFlare (CMatrix4x4& _ViewMatrix, CMatrix4x4& _ProjMatrix, float _fSunCamAngle)
{
  //## begin CLensFlare::UpdateLensFlare%1001541676.body preserve=yes
	int				cElem;
	
	CVect3			NewPos;	
	CVect3			*pVX;
	CVect4			*pVC;
	
	float			fAlpha;
	CVect3			SunScr;
	float			fSize;	
	float			fDist,fDistFact;
	
	CVect3			PrjSun;

	// ---------------------------
	// Get the projected sun point	
	// ---------------------------
	PrjSun.Assign(SunPos);
	_ViewMatrix.TransformPoint(PrjSun);
	_ProjMatrix.TransformPoint(PrjSun);

	PrjSun.SetX(PrjSun.X() / PrjSun.Z());
	PrjSun.SetY(PrjSun.Y() / PrjSun.Z());
	PrjSun.SetZ(0.0f);

	// ---------------------------
	// Get the projected line eq
	// ---------------------------
	
	// Get direction from projected sun position to the screen center
	SunScr.V3(-PrjSun.X(),-PrjSun.Y(),0.0f);
	SunScr.Normalize();

	fDistFact = PrjSun.Module() * _1_OVER_SQRT_2;

	// Size decreases in angle
	fSize = 0.15f*_fSunCamAngle;

	// Alpha decreases in squared proportion to Angle	
	fAlpha = _fSunCamAngle*_fSunCamAngle;
	fAlpha = (1.0f - fDistFact)*1.025f ;

	// Init lens flare elems
	float fInvRatio = 1.0f / gpoE3DRenderer->fGetAspectRatio();

	for (cElem=0;cElem<iNumElems;cElem++)
	{		
		pVX = MeshArray[cElem].VXs;
		pVC = MeshArray[cElem].VCs;
		
		fSize = FlareElems[cElem].fSize * _fSunCamAngle;
		fDist = FlareElems[cElem].fDist * fDistFact / _1_OVER_SQRT_2;

		NewPos.LineEq(PrjSun,SunScr, fDist );

		// Set screen coordinates (normalized)		
		pVX[3].V3(-fSize*fInvRatio,-fSize,0); pVX[3].Add(NewPos);
		pVX[2].V3(-fSize*fInvRatio, fSize,0); pVX[2].Add(NewPos);
		pVX[1].V3( fSize*fInvRatio, fSize,0); pVX[1].Add(NewPos);
		pVX[0].V3( fSize*fInvRatio,-fSize,0); pVX[0].Add(NewPos);
		

		// Set vertex color
		pVC[0].Assign(FlareElems[cElem].Color);
		pVC[1].Assign(FlareElems[cElem].Color);
		pVC[2].Assign(FlareElems[cElem].Color);
		pVC[3].Assign(FlareElems[cElem].Color);

		pVC[0].v[3] *= fAlpha;
		pVC[1].v[3] *= fAlpha;
		pVC[2].v[3] *= fAlpha;
		pVC[3].v[3] *= fAlpha;
	}
  //## end CLensFlare::UpdateLensFlare%1001541676.body
}

void CLensFlare::Render ()
{
  //## begin CLensFlare::Render%1001541674.body preserve=yes
	assert (FlareElems && "NULL Lens flare elem array");

	CE3D_Renderer *pRend = gpoE3DRenderer;
	CE3D_Camera	  *pCam  = gpoE3DRenderer->GetCamera();

	// ---------------------------
	// Compute SunCam vector
	// ---------------------------
	CVect3			CamDir,SunCam;
	float			fCamSunAngle;

	// Get the Sun Camera direction vector
	SunCam.Assign( pCam->Pos );
	SunCam.Sub(SunPos);
	SunCam.Normalize();
	
	// ---------------------------
	// Compute SunCam/CamDir angle 
	// ---------------------------

	// Get the angle between camera dir vector and sun-camera vector
	fCamSunAngle = -1.0f * pCam->Dir.DotProd(SunCam);	

	// ---------------------------
	// Enabling Flare test
	// ---------------------------

	// Skip if sun is behind the camera
	if (fCamSunAngle <0) return;

	// ---------------------------
	// Flare Rendering
	// ---------------------------
   	CMatrix4x4		CurrentViewMat;
	CMatrix4x4		CurrentProjMat;
	int				cElem;

	pRend->SetFogPars(eE3D_FM_None,0.0f,0.0f,0.0f,NULL);
	pRend->GetCameraMatrix	 (&CurrentViewMat);
	pRend->GetProjectorMatrix(&CurrentProjMat);
		
		UpdateLensFlare(CurrentViewMat,CurrentProjMat,fCamSunAngle);

		pRend->ClearProjectorMatrix();
		pRend->ClearCameraMatrix();		
	
		for (cElem=0;cElem<iNumElems;cElem++)
			pRend->RenderMesh(&MeshArray[cElem],FlareElems[cElem].pMaterial);

	pRend->SetCameraMatrix   (&CurrentViewMat);
	pRend->SetProjectorMatrix(&CurrentProjMat);
	pRend->SetFogPars(eE3D_FM_Last,0.0f,0.0f,0.0f,NULL);
	
  //## end CLensFlare::Render%1001541674.body
}

CGraphBV* CLensFlare::poGetBoundVol ()
{
  //## begin CLensFlare::poGetBoundVol%1001625479.body preserve=yes
	return (NULL);
  //## end CLensFlare::poGetBoundVol%1001625479.body
}

void CLensFlare::ComputeBoundVol ()
{
  //## begin CLensFlare::ComputeBoundVol%1001625480.body preserve=yes
  //## end CLensFlare::ComputeBoundVol%1001625480.body
}

// Additional Declarations
  //## begin CLensFlare%3BB24FC100F3.declarations preserve=yes
  //## end CLensFlare%3BB24FC100F3.declarations

//## begin module%3BB24FC100F3.epilog preserve=yes
//## end module%3BB24FC100F3.epilog
