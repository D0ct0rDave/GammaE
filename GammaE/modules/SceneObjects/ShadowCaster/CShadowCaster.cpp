//## begin module%3CBB24A1003D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CBB24A1003D.cm

//## begin module%3CBB24A1003D.cp preserve=no
//## end module%3CBB24A1003D.cp

//## Module: CShadowCaster%3CBB24A1003D; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\ShadowCaster\CShadowCaster.cpp

//## begin module%3CBB24A1003D.additionalIncludes preserve=no
//## end module%3CBB24A1003D.additionalIncludes

//## begin module%3CBB24A1003D.includes preserve=yes
#include "tex.h"
//## end module%3CBB24A1003D.includes

// CShadowCaster
#include "SceneObjects\ShadowCaster\CShadowCaster.h"
//## begin module%3CBB24A1003D.additionalDeclarations preserve=yes

#define _SMOOTH_SHADOW2_

//## end module%3CBB24A1003D.additionalDeclarations


// Class CShadowCaster 













CShadowCaster::CShadowCaster()
  //## begin CShadowCaster::CShadowCaster%.hasinit preserve=no
      : poBlockerObj(NULL), poRecObjs(NULL), iNumRecObjs(0), poTexObj(NULL), pucAuxTexData(NULL)
  //## end CShadowCaster::CShadowCaster%.hasinit
  //## begin CShadowCaster::CShadowCaster%.initialization preserve=yes
  //## end CShadowCaster::CShadowCaster%.initialization
{
  //## begin CShadowCaster::CShadowCaster%.body preserve=yes
  //## end CShadowCaster::CShadowCaster%.body
}


CShadowCaster::~CShadowCaster()
{
  //## begin CShadowCaster::~CShadowCaster%.body preserve=yes
  //## end CShadowCaster::~CShadowCaster%.body
}



//## Other Operations (implementation)
void CShadowCaster::Init (int _iRes)
{
  //## begin CShadowCaster::Init%1018910300.body preserve=yes
	iRes = _iRes;

	// Create texture
	MipMap* oMipMap;
	
	#ifdef _SMOOTH_SHADOW_
	AllocateMipMap(&oMipMap,iRes>>1,iRes>>1,TEX_PF_PALETTE,1);	
	for (int i=0;i<256;i++)
	{
		oMipMap.Palette->data[i].r = i;
		oMipMap.Palette->data[i].g = i;
		oMipMap.Palette->data[i].b = i;
	}
	pucAuxTexData = mNew unsigned char[iRes*iRes*4];

	#else
	oMipMap = poCreateMipMap(iRes, iRes, 4);
	#endif

	// Create shader from texture
	CE3D_ShaderUtils::SetupTilingFlags(0,0);
	poShader = CE3D_ShaderUtils::poGenerateShaderFromMipMap(oMipMap,"::ShadowMap::");


	// Get a reference to texture object
	poTexObj = ((CE3D_ShIns_Texture *)poShader->pGetInstruction(0))->pTex;


	// Add blending op before texture operation
	CE3D_ShIns_BlendOp *poBop = mNew CE3D_ShIns_BlendOp;
	poBop->SeteBOpType(eSIBOp_Mult);
	poShader->PushInstruction(poBop);


	// Add matrix texture operation 
	CE3D_ShIns_TexOp *poTop = mNew CE3D_ShIns_TexOp;
	poTop->SeteTOpType(eSITexOp_Matrix);
	poTop->poMat = &oPrjTexMat;
	poShader->PushInstruction(poTop);

	// Deallocate texture
	DestroyMipMap(oMipMap);	

  //## end CShadowCaster::Init%1018910300.body
}

void CShadowCaster::Setup (CVect3& _roLightPos, CObject3D* _poBlockerObj, CMesh** _poRecObjs, int _iNumRecObjs)
{
  //## begin CShadowCaster::Setup%1018897755.body preserve=yes
	oLPos.Assign(_roLightPos);
	poBlockerObj = _poBlockerObj;
	
	poRecObjs	 = _poRecObjs;
	iNumRecObjs  = _iNumRecObjs;

	RenderShadowMap();

	ComputeTextureProjection();
  //## end CShadowCaster::Setup%1018897755.body
}

CGraphBV* CShadowCaster::poGetBoundVol ()
{
  //## begin CShadowCaster::poGetBoundVol%1018897758.body preserve=yes
	return (NULL);
  //## end CShadowCaster::poGetBoundVol%1018897758.body
}

void CShadowCaster::ComputeBoundVol ()
{
  //## begin CShadowCaster::ComputeBoundVol%1018897757.body preserve=yes
  //## end CShadowCaster::ComputeBoundVol%1018897757.body
}

void CShadowCaster::ComputeLightCamera ()
{
  //## begin CShadowCaster::ComputeLightCamera%1018910298.body preserve=yes
	CE3D_Camera oCam;
	
	oCam.Dir.Assign(poBlockerObj->poGetBoundVol()->GetCenter());
	oCam.Dir.Sub   (oLPos);
	oCam.Dir.Normalize();

	// _roCam.Side = Orthogonal();
	oCam.Side.Orthogonal(oCam.Dir);
	oCam.Side.Normalize ();

	oCam.Up.CrossProd(oCam.Dir,oCam.Side);
	oCam.Pos.Assign	 (oLPos);

	/*
	// Compute camera viewing matrix
	CVect3 oDir,oSide,oUp;

	oDir.Assign(poBlockerObj->poGetBoundVol()->GetCenter());
	oDir.Sub   (oLPos);
	oDir.Normalize();
	
	// Side = Orthogonal();
	oSide.Orthogonal(oDir);
	oSide.Normalize ();

	oUp.CrossProd(oDir,oSide);

	oCamMat.SetColVector(0,oSide.X(),oSide.Y(),oSide.Z(),0.0f);
	oCamMat.SetColVector(1,oDir .X(),oDir .Y(),oDir .Z(),0.0f);
	oCamMat.SetColVector(2,oUp  .X(),oUp  .Y(),oUp  .Z(),0.0f);
	oCamMat.SetColVector(3,oLPos.X(),oLPos.Y(),oLPos.Z(),1.0f);

	_roCam.Dir.Assign	(oDir);
	_roCam.Side.Assign	(oSide);
	_roCam.Up.Assign	(oUp);
	_roCam.Pos.Assign   (oLPos);
	*/
	
	// <OPTIMIZABLE> Via own camera computation.
	gpoE3DRenderer->SetCamera(&oCam);
	gpoE3DRenderer->GetCameraMatrix(&oCamMat);

  //## end CShadowCaster::ComputeLightCamera%1018910298.body
}

void CShadowCaster::ComputeLightViewport (CE3D_Viewport& _roVpt)
{
  //## begin CShadowCaster::ComputeLightViewport%1018910301.body preserve=yes
	float fTX = (float)iRes / (float)gpoE3DRenderer->iGetScrTX();
	float fTY = (float)iRes / (float)gpoE3DRenderer->iGetScrTY();

	_roVpt.SetViewport(0.0f,0.0f,fTX,fTY);
  //## end CShadowCaster::ComputeLightViewport%1018910301.body
}

void CShadowCaster::ComputeLightProjection ()
{
  //## begin CShadowCaster::ComputeLightProjection%1018910302.body preserve=yes

	CGraphBV_Box oBox;
	CVect3 *poPnt = oBox.Vol.Points;
	oBox.Copy(	poBlockerObj->poGetBoundVol() );

	// Transform bounding volume points	
	float fXAbs,fYAbs;
	float fXMax,fYMax;

	fXMax =-1e6f;	fYMax =-1e6f;
	for (int iPnt=0;iPnt<8;iPnt++)
	{
		oCamMat.TransformPoint(poPnt[iPnt]);	
		
		fXAbs = MATH_Common::fAbs(poPnt[iPnt].X() / poPnt[iPnt].Z());
		fYAbs = MATH_Common::fAbs(poPnt[iPnt].Y() / poPnt[iPnt].Z());

		if (fXMax < fXAbs) fXMax = fXAbs;
		if (fYMax < fYAbs) fYMax = fYAbs;
	}

	const float fLFar  = 1000.0f;
	const float fLNear =    0.1f;	
	float       A = 1.0f - 2.0f/(float)iRes;
	const float B = (fLFar+fLNear)/(fLNear-fLFar);
	const float C = 2*(fLFar*fLNear)/(fLNear-fLFar);

	oPrjMat.LoadIdentity();
	oPrjMat.Set(0,0,A/fXMax);
	oPrjMat.Set(1,1,A/fYMax);
	oPrjMat.Set(2,2,B);
	oPrjMat.Set(2,3,C);	// Este es el orden correcto !
	oPrjMat.Set(3,2,-1);// Este es el orden correcto !
	oPrjMat.Set(3,3,0);
  //## end CShadowCaster::ComputeLightProjection%1018910302.body
}

void CShadowCaster::ComputeTextureProjection ()
{
  //## begin CShadowCaster::ComputeTextureProjection%1018988852.body preserve=yes
	CMatrix4x4 oAuxMat;
	
	
	oAuxMat = oPrjMat;
	
	/*
	oAuxMat.Set(0,0,oAuxMat.Get(0,0)*0.5f);
	oAuxMat.Set(1,1,oAuxMat.Get(1,1)*0.5f);
	oAuxMat.Set(0,2,-0.5f);
	oAuxMat.Set(1,2,-0.5f);
	*/

	CMatrix4x4 oScaleMat;
	oScaleMat.LoadIdentity();
	oScaleMat.Scale3f(0.5f,0.5f,1.0f);

	CMatrix4x4 oTransMat;
	oTransMat.LoadIdentity();
	oTransMat.Translate3f(0.5f,0.5f,0.0f);
		

	oAuxMat = oPrjMat;
	oAuxMat.MultiplyBy(oScaleMat);

	oPrjTexMat = oCamMat;
	oPrjTexMat.MultiplyBy(oPrjMat);
	oPrjTexMat.MultiplyBy(oScaleMat);
	oPrjTexMat.MultiplyBy(oTransMat);

	oPrjTexMat = oTransMat;
	oPrjTexMat.MultiplyBy(oScaleMat);
	oPrjTexMat.MultiplyBy(oPrjMat);
	oPrjTexMat.MultiplyBy(oCamMat);

	// oPrjTexMat.Multiply(oAuxMat,oCamMat);	
  //## end CShadowCaster::ComputeTextureProjection%1018988852.body
}

void CShadowCaster::UploadShadowMap ()
{
  //## begin CShadowCaster::UploadShadowMap%1018910299.body preserve=yes

	// Retrieve texture from frame buffer
	gpoE3DRenderer->ReadBuffer(0,0,iRes,iRes,eE3D_RB_Back,poTexObj->MipMapObj->mipMap->lods[0]->data);
	
	#ifdef _SMOOTH_SHADOW2_
	int cI,cJ;
	unsigned char *pucPixelA = poTexObj->MipMapObj->mipMap->lods[0]->data;
	unsigned char *pucPixelB;
	unsigned short usValue;
	for (cJ=0;cJ<iRes;cJ++)
	{
		pucPixelB = pucPixelA + 4;
		for (cI=1;cI<iRes;cI++)
		{
			if (*pucPixelB != *pucPixelA)
			{
				usValue = (pucPixelB[0] + pucPixelA[0]) >> 1;
				
				pucPixelA[0] = usValue;
				pucPixelA[1] = usValue;
				pucPixelA[2] = usValue;
				pucPixelA[3] = usValue;
			}

			pucPixelA += 4;
			pucPixelB += 4;
		}

		pucPixelA = pucPixelB;
	}
	#endif

	// Force update
	poTexObj->MipMapObj->Update = true;	
  //## end CShadowCaster::UploadShadowMap%1018910299.body
}

void CShadowCaster::RenderShadowMap ()
{
  //## begin CShadowCaster::RenderShadowMap%1018910297.body preserve=yes
	
	CE3D_Viewport	oVpt;
	CE3D_Viewport	*poOldVpt;	
	CMatrix4x4		oOldPrjMat;
	CMatrix4x4		oOldCamMat;

	// Save current state	
	gpoE3DRenderer->GetProjectorMatrix(&oOldPrjMat);
	gpoE3DRenderer->GetCameraMatrix   (&oOldCamMat);
	poOldVpt = gpoE3DRenderer->GetViewport();	
	
	// Set current point of view
	ComputeLightViewport	(oVpt);
	gpoE3DRenderer->SetViewport(&oVpt);
	
	ComputeLightCamera();	
	ComputeLightProjection();

	gpoE3DRenderer->SetCameraMatrix(&oCamMat);	
	gpoE3DRenderer->SetProjectorMatrix(&oPrjMat);

	// Rendering

		// El objeto es visible completamente porque el frustum de la luz
		// es adaptativo
		gpoE3DRenderer->DisableFrustumCulling();
		gpoE3DRenderer->EnableFlatRendering();
		gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);
			
			// Clear buffer
			gpoE3DRenderer->ClearBuffer(eE3D_RB_Back);

			// Render blocking object
			poBlockerObj->Render();
			
			// Get ShadowMap texture
			UploadShadowMap ();

		gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);
		gpoE3DRenderer->DisableFlatRendering();	

	// Restore state
	gpoE3DRenderer->SetViewport	 (poOldVpt);
	gpoE3DRenderer->SetProjectorMatrix(&oOldPrjMat);
	gpoE3DRenderer->SetCameraMatrix   (&oOldCamMat);	
  //## end CShadowCaster::RenderShadowMap%1018910297.body
}

void CShadowCaster::Render ()
{
  //## begin CShadowCaster::Render%1018897756.body preserve=yes
	for (int iObj=0;iObj<iNumRecObjs;iObj++)
	{
		oTexProj.Setup(poRecObjs[iObj],poShader,oPrjTexMat);
		oTexProj.Render();
	}
  //## end CShadowCaster::Render%1018897756.body
}

// Additional Declarations
  //## begin CShadowCaster%3CBB24A1003D.declarations preserve=yes
  //## end CShadowCaster%3CBB24A1003D.declarations

//## begin module%3CBB24A1003D.epilog preserve=yes
//## end module%3CBB24A1003D.epilog
