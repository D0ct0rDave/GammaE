// -----------------------------------------------------------------------------
#include "CFlareMgr.h"

TFlareType		CFlareMgr::oFTT[MAX_FLARE_TYPES];					// Flare Type Table
TFlareElem		CFlareMgr::oFlare[MAX_FLARE_COLS][FLARES_PER_COL];	// The flares
CMesh			CFlareMgr::oMesh;									// The flare mesh
CMatrix4x4		CFlareMgr::oPrjMat;
CMatrix4x4		CFlareMgr::oCamMat;
CMatrix4x4		CFlareMgr::oCPMat;
static	float	lmfDelta;
// -----------------------------------------------------------------------------
const float	CHST_SPEED			= 2.0f;
const float FLARE_ZOMBIETIME	= 10.0f;
// -----------------------------------------------------------------------------
inline float fBlinkFunc(TBlinkFunc _eFunc,float _fVal)
{
	switch (_eFunc)
	{
		case TBF_none:		return(1.0f);
		case TBF_step:		if (_fVal<0.5f) return(1.0f);	else return(0.0f);
		case TBF_pulse:		if (_fVal<0.75f) return(0.0f);	else return(1.0f);
		case TBF_invpulse:	if (_fVal<0.75f) return(1.0f);	else return(0.0f);
		case TBF_flicker:	return( 0.25f + 0.75f*MATH_Common::fRand() );
	}
}

inline unsigned int uiGetIndex(void *_pKey, unsigned int _iChild)
{
	return (unsigned int) ( ((unsigned long long)_pKey + _iChild) % MAX_FLARE_COLS );
}
// -----------------------------------------------------------------------------
CFlareMgr::CFlareMgr()
{
}
// -----------------------------------------------------------------------------
CFlareMgr::~CFlareMgr()
{
}
// -----------------------------------------------------------------------------
void CFlareMgr::Init()
{
	// ------------------------------
	// Flare Type Table
	// ------------------------------
	
	// Flare type 0
	oFTT[0].bDirectional	= true;
	oFTT[0].eBlinkFunc		= TBF_none;
	oFTT[0].fFreq			= 0.0f;	
	oFTT[0].oColor.r		= 1.0f;
	oFTT[0].oColor.g		= 1.0f;
	oFTT[0].oColor.b		= 0.5f;
	oFTT[0].oColor.a		= 0.0f;
 	oFTT[0].poShader		= CE3D_ShaderWH::poCreateShader("fl00");
	
	// Flare type 1
	oFTT[1].bDirectional	= true;
	oFTT[1].eBlinkFunc		= TBF_pulse;
	oFTT[1].fFreq			= 0.25f;	
	oFTT[1].oColor.r		= 1.0f;
	oFTT[1].oColor.g		= 0.25f;
	oFTT[1].oColor.b		= 0.0f;
	oFTT[1].oColor.a		= 0.0f;
 	oFTT[1].poShader		= CE3D_ShaderWH::poCreateShader("fl01");

	// Flare type 2
	oFTT[2].bDirectional	= true;
	oFTT[2].eBlinkFunc		= TBF_step;
	oFTT[2].fFreq			= 0.5f;	
	oFTT[2].oColor.r		= 0.2f;
	oFTT[2].oColor.g		= 1.0f;
	oFTT[2].oColor.b		= 0.0f;
	oFTT[2].oColor.a		= 0.0f;
 	oFTT[2].poShader		= CE3D_ShaderWH::poCreateShader("fl02");

	// Flare type 3
	oFTT[3].bDirectional	= true;
	oFTT[3].eBlinkFunc		= TBF_invpulse;
	oFTT[3].fFreq			= 1.0f;	
	oFTT[3].oColor.r		= 0.0f;
	oFTT[3].oColor.g		= 0.2f;
	oFTT[3].oColor.b		= 1.0f;
	oFTT[3].oColor.a		= 0.0f;
 	oFTT[3].poShader		= CE3D_ShaderWH::poCreateShader("fl02");

	// Flare type 4
	oFTT[4].bDirectional	= false;
	oFTT[4].eBlinkFunc		= TBF_none;
	oFTT[4].fFreq			= 0.0f;	
	oFTT[4].oColor.r		= 1.0f;
	oFTT[4].oColor.g		= 0.0f;
	oFTT[4].oColor.b		= 0.0f;
	oFTT[4].oColor.a		= 0.0f;
 	oFTT[4].poShader		= CE3D_ShaderWH::poCreateShader("fl02");
		
	// Flare type 5
	oFTT[5].bDirectional	= false;
	oFTT[5].eBlinkFunc		= TBF_none;
	oFTT[5].fFreq			= 0.0f;	
	oFTT[5].oColor.r		= 0.0f;
	oFTT[5].oColor.g		= 1.0f;
	oFTT[5].oColor.b		= 0.0f;
	oFTT[5].oColor.a		= 0.0f;
 	oFTT[5].poShader		= CE3D_ShaderWH::poCreateShader("fl02");

	// Flare type 6
	oFTT[6].bDirectional	= false;
	oFTT[6].eBlinkFunc		= TBF_none;
	oFTT[6].fFreq			= 0.0f;	
	oFTT[6].oColor.r		= 0.0f;
	oFTT[6].oColor.g		= 1.0f;
	oFTT[6].oColor.b		= 0.5f;
	oFTT[6].oColor.a		= 0.0f;
 	oFTT[6].poShader		= CE3D_ShaderWH::poCreateShader("fl03");

	// Flare type 10
	oFTT[10].bDirectional	= false;
	oFTT[10].eBlinkFunc		= TBF_none;
	oFTT[10].fFreq			= 0.0f;	
	oFTT[10].oColor.r		= 0.8f;
	oFTT[10].oColor.g		= 0.8f;
	oFTT[10].oColor.b		= 1.0f;
	oFTT[10].oColor.a		= 0.0f;
 	oFTT[10].poShader		= CE3D_ShaderWH::poCreateShader("fl00");

	// Flare type 11
	oFTT[11].bDirectional	= false;
	oFTT[11].eBlinkFunc		= TBF_pulse;
	oFTT[11].fFreq			= 0.25f;	
	oFTT[11].oColor.r		= 1.0f;
	oFTT[11].oColor.g		= 1.0f;
	oFTT[11].oColor.b		= 1.0f;
	oFTT[11].oColor.a		= 0.0f;
 	oFTT[11].poShader		= CE3D_ShaderWH::poCreateShader("fl01");

	// Flare type 12
	oFTT[12].bDirectional	= false;
	oFTT[12].eBlinkFunc		= TBF_flicker;
	oFTT[12].fFreq			= 0.25f;	
	oFTT[12].oColor.r		= 1.0f;
	oFTT[12].oColor.g		= 1.0f;
	oFTT[12].oColor.b		= 1.0f;
	oFTT[12].oColor.a		= 0.0f;
 	oFTT[12].poShader		= CE3D_ShaderWH::poCreateShader("fl01");

	// ------------------------------
	// Create mesh
	// ------------------------------	
	oMesh.Init(	MAX_FLARE_COLS*FLARES_PER_COL*4,
				MAX_FLARE_COLS*FLARES_PER_COL,
				E3D_MESH_NIQUADS,
				MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS );

	for (int iFlare=0;iFlare<MAX_FLARE_COLS*FLARES_PER_COL;iFlare++)
	{
		oMesh.UVs[iFlare*4+0].V2(0.0f,1.0f);
		oMesh.UVs[iFlare*4+1].V2(0.0f,0.0f);
		oMesh.UVs[iFlare*4+2].V2(1.0f,0.0f);
		oMesh.UVs[iFlare*4+3].V2(1.0f,1.0f);

		oMesh.VCs[iFlare*4+0].V4(1.0f,1.0f,1.0f,0.5f);
		oMesh.VCs[iFlare*4+1].V4(1.0f,1.0f,1.0f,0.5f);
		oMesh.VCs[iFlare*4+2].V4(1.0f,1.0f,1.0f,0.5f);
		oMesh.VCs[iFlare*4+3].V4(1.0f,1.0f,1.0f,0.5f);
	}

	// ------------------------------
	// Init flare table
	// ------------------------------
	Reset();
}
// -----------------------------------------------------------------------------
void CFlareMgr::Reset()
{
	int cI,cJ;
	for (cJ=0;cJ<MAX_FLARE_COLS;cJ++)
		for (cI=0;cI<FLARES_PER_COL;cI++)
		{
			oFlare[cJ][cI].pParent = NULL;	
			oFlare[cJ][cI].iStamp  = 0;
			oFlare[cJ][cI].eState  = TFS_Off;
		}
}
// -----------------------------------------------------------------------------
void CFlareMgr::AddFlare(int _iType,void *_pParent,int _iChildNum,CVect3 &_roWorldPos,CVect3 &_roWorldDir,float _fSize)
{
	unsigned int uiIdx = uiGetIndex(_pParent,_iChildNum);
	int cI;	

	for (cI=0;cI<FLARES_PER_COL;cI++)
	{
		if ((oFlare[uiIdx][cI].pParent  == _pParent) &&
			(oFlare[uiIdx][cI].iChildNum== _iChildNum))
		{
			// update fields
			oFlare[uiIdx][cI].oPos.Assign(_roWorldPos);
			oFlare[uiIdx][cI].oDir.Assign(_roWorldDir);
			oFlare[uiIdx][cI].iType		= _iType;
			oFlare[uiIdx][cI].fSize		= _fSize;
			oFlare[uiIdx][cI].iStamp     = 1;
			return;
		}
   else if (oFlare[uiIdx][cI].pParent == NULL)
		{
			// add new flare
			oFlare[uiIdx][cI].pParent	= _pParent;
			oFlare[uiIdx][cI].iChildNum	= _iChildNum;
			oFlare[uiIdx][cI].iType		= _iType;
			oFlare[uiIdx][cI].fTime		= 0.0f;
			oFlare[uiIdx][cI].fSize		= _fSize;
			oFlare[uiIdx][cI].fFactor	= 0.0f;
			oFlare[uiIdx][cI].eState		= TFS_Off;
			oFlare[uiIdx][cI].oPos.Assign(_roWorldPos);
			oFlare[uiIdx][cI].oDir.Assign(_roWorldDir);

			oFlare[uiIdx][cI].iStamp     = 1;
			return;
		}
	}

	// No ha sido posible ni encontrar el flare, ni crear uno nuevo.
}
// -----------------------------------------------------------------------------
bool CFlareMgr::bFlareVisible(TFlareElem &_roElem)
{
	return(true);

	CVect3 oPrjPos;
	oPrjPos.Assign(_roElem.oPos);

	oCPMat.TransformPoint(oPrjPos);

	float fInvZ = 1.0f / oPrjPos.Z();
	_roElem.oPrjPos.V2(oPrjPos.X()*fInvZ,oPrjPos.Y()*fInvZ);
	
	if ((_roElem.oPrjPos.X()<-1.0f) || (_roElem.oPrjPos.X()>1.0f) ||
		(_roElem.oPrjPos.Y()<-1.0f) || (_roElem.oPrjPos.X()>1.0f) ||
		(oPrjPos.Z() > 0.0f))
		 return(false);

	return(true);
}

void CFlareMgr::UpdateFlare(TFlareElem &_roElem)
{
	bool bVisible = bFlareVisible(_roElem);

	// Update flare state
	switch (_roElem.eState)
	{
		case TFS_Off:	
		{
			if (bVisible)
			{
				_roElem.eState  = TFS_Showing;
				_roElem.fFactor = 0.0f;
			}
		}
		break;

		case TFS_Showing:
		{
			if (bVisible)
			{
				_roElem.fFactor += CHST_SPEED*lmfDelta;
				
				if (_roElem.fFactor >= 1.0f)
				{
					_roElem.fFactor = 1.0f;
					_roElem.eState  = TFS_On;
				}
			}
			else
				_roElem.eState  = TFS_Hidding;				
		}
		break;

		case TFS_On:
		{
			if (! bVisible)
			{
				_roElem.eState  = TFS_Hidding;
				_roElem.fFactor = 1.0f;
			}
		}
		break;

		case TFS_Hidding:
		{
			if (! bVisible)
			{
				_roElem.fFactor -= CHST_SPEED*lmfDelta;

				if (_roElem.fFactor <= 0.0f)
				{
					_roElem.fFactor = 0.0f;
					_roElem.eState  = TFS_Off;
				}
			}
			else
				_roElem.eState  = TFS_Showing;
		}
		break;
	}

	// Update flare time
	_roElem.fTime += gpoE3DRenderer->REStats.DTime;		
}

void CFlareMgr::Update()
{
	int cI,cJ;	
	for (cJ=0;cJ<MAX_FLARE_COLS;cJ++)
		for (cI=0;cI<FLARES_PER_COL;cI++)
		{
			if (oFlare[cJ][cI].iStamp)
			{
				UpdateFlare(oFlare[cJ][cI]);
				oFlare[cJ][cI].iStamp = 0;
			}
			else
			{
				// Orphan Flare 
				oFlare[cJ][cI].pParent = NULL;
			}
		}
}
// -----------------------------------------------------------------------------
void CFlareMgr::RenderFlare(TFlareElem &_roElem)
{
	// --------------------------------------------------------------------------
	// First of all determine if the flare is visible due to transparency factors
	// --------------------------------------------------------------------------

	// 1.- Blinking function	
	float fBlinkFact = fBlinkFunc(oFTT[_roElem.iType].eBlinkFunc,_roElem.fTime);
	_roElem.fTime += lmfDelta*oFTT[_roElem.iType].fFreq;
	if (_roElem.fTime>=1.0f) _roElem.fTime -= 1.0f;
	if (fBlinkFact == 0.0f) return;
	
	
	// 2.- Distance
	float fDistFact;
	CVect3 oRCamPos;
	oRCamPos.Assign (_roElem.oPos );
	oCamMat.TransformPoint( oRCamPos );					// Object pos in camera space (camera is at (0,0,0));
	
	const float fMAXFLAREDIST	= 1000.0f;
	const float fMAXSQFLAREDIST	= fMAXFLAREDIST*fMAXFLAREDIST;

	fDistFact = (oRCamPos.SqModule() / fMAXSQFLAREDIST);// Distance from point to camera position
	if (fDistFact > 1.0f) return;						// Flare not visible
	fDistFact = 1.0f - fDistFact;


	// 3 .- Camera angle
	float fAngFact;
	if (oFTT[_roElem.iType].bDirectional)
	{
		CVect3 oRCamDir;
		CVect3 oCamDir;
		oCamDir.V3(0.0f,0.0f,1.0f);
		oRCamDir.Assign (_roElem.oDir);
		oCamMat.TransformVector( oRCamDir );				// Object dir in camera space (camera points to (0,0,1));
		fAngFact = oCamDir.DotProd(oRCamDir);
		fAngFact *= 1.0f;									// Oposite flares are visible
	
		if (fAngFact < 0.0f) return;						// Flare not visible
	}
	else
		fAngFact = 1.0f;


	// 4.- Total factor
	const float fFACTTHRESHOLD = 1e-2f;
	float	fTotFact = fBlinkFact*fDistFact*fAngFact*_roElem.fFactor;
	if (fTotFact < fFACTTHRESHOLD) return;				// Flare not visible
	
	// Set vertex color
	CVect4	*poVC = oMesh.VCs + oMesh.usNumVerts;
	poVC[0].V4( oFTT[_roElem.iType].oColor.r*fTotFact,
				oFTT[_roElem.iType].oColor.g*fTotFact,
				oFTT[_roElem.iType].oColor.b*fTotFact,
				oFTT[_roElem.iType].oColor.a*fTotFact );

	poVC[1].Assign(poVC[0]);
	poVC[2].Assign(poVC[0]);
	poVC[3].Assign(poVC[0]);


	// Set geometry	
	CVect3	*poVX = oMesh.VXs + oMesh.usNumVerts;

	CVect3 oRCP;						// Relative to camera position
	oRCP.Assign(_roElem.oPos);
	oCamMat.TransformPoint(oRCP);

	poVX[0].V3(oRCP.X() - _roElem.fSize,oRCP.Y() + _roElem.fSize,oRCP.Z());
	poVX[1].V3(oRCP.X() - _roElem.fSize,oRCP.Y() - _roElem.fSize,oRCP.Z());
	poVX[2].V3(oRCP.X() + _roElem.fSize,oRCP.Y() - _roElem.fSize,oRCP.Z());
	poVX[3].V3(oRCP.X() + _roElem.fSize,oRCP.Y() + _roElem.fSize,oRCP.Z());

	oMesh.usNumVerts+=4;
	oMesh.usNumPrims++;
}
// -----------------------------------------------------------------------------
void CFlareMgr::Render()
{
	int			iType,cI,cJ;
	TFlareElem *poElem;

	lmfDelta = gpoE3DRenderer->REStats.DTime;
	// gpoE3DRenderer->GetCameraMatrix(&oCamMat);
	gpoE3DRenderer->GetCurrentMatrix  (&oCamMat);	
	gpoE3DRenderer->GetProjectorMatrix(&oPrjMat);	
	oCPMat.Multiply(oCamMat,oPrjMat);

	// Update the flares
	Update();

	// Render Mesh
	gpoE3DRenderer->ClearCameraMatrix();
	gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Current);
	gpoE3DRenderer->SetFogPars(eE3D_FM_None,0.0f,0.0f,0.0f,NULL);

	// Render the flares
	for (iType=0;iType<MAX_FLARE_TYPES;iType++)
	{
		oMesh.usNumPrims = 0;
		oMesh.usNumVerts = 0;

		for (cJ=0;cJ<MAX_FLARE_COLS;cJ++)
			for (cI=0;cI<FLARES_PER_COL;cI++)
			{
				poElem = &oFlare[cJ][cI];

				if ((poElem->iType == iType) && 
					(poElem->pParent) && 
					(poElem->eState != TFS_Off))
				{
					RenderFlare(*poElem);
				}
			}

		// Render the mesh
		if (oMesh.usNumPrims)
			gpoE3DRenderer->RenderMesh(&oMesh,oFTT[iType].poShader);
			// gpoE3DRenderer->RenderMesh(&oMesh,NULL);
	}

	gpoE3DRenderer->SetCurrentMatrix(&oCamMat);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Current);
	gpoE3DRenderer->SetFogPars(eE3D_FM_Last,0.0f,0.0f,0.0f,NULL);
}
// -----------------------------------------------------------------------------