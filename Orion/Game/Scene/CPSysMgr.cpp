// -----------------------------------------------------------------------------
#include "CPSysMgr.h"
CE3D_Shader		*CPSysMgr::oShTab[MAX_PSSHADERS];					// The materials
TPSysType		CPSysMgr::oPSTT [MAX_PSYS_TYPES];					// PSys Type Table
TPSysInstance	*CPSysMgr::oPSys[MAX_PSYS_TYPES];					// The PSys
TParticle		CPSysMgr::oPars	[MAX_PARTICLES];					// The particles

CMesh			CPSysMgr::oMesh;									// The PSys mesh
CMatrix4x4		CPSysMgr::oPrjMat;
CMatrix4x4		CPSysMgr::oCamMat;
CMatrix4x4		CPSysMgr::oCPMat;
static	float	lmfDelta;
// -----------------------------------------------------------------------------
CPSysMgr::CPSysMgr()
{
}
// -----------------------------------------------------------------------------
CPSysMgr::~CPSysMgr()
{
}

// -----------------------------------------------------------------------------
void PPGravity(TParticle *poPart)
{
	poPart->oOldPos.Assign(poPart->oPos);
	poPart->oPos.LineEq(poPart->oPos,poPart->oSpeed,lmfDelta);
	poPart->oSpeed.SetZ(poPart->oSpeed.Z()+
                        CPSysMgr::oPSTT[ poPart->pParent->iType ].fGravity*lmfDelta);
}
// -----------------------------------------------------------------------------
void PPNoGravity(TParticle *poPart)
{
	poPart->oOldPos.Assign(poPart->oPos);
	poPart->oPos.LineEq(poPart->oPos,poPart->oSpeed,lmfDelta);	
}
// -----------------------------------------------------------------------------
void CPSysMgr::Init()
{
	int iPart;
	int iTotalMax,iMax;
	int i;
	int iPSys;
	// ------------------------------
	// Shader Type Table
	// ------------------------------
	oShTab[0] = CE3D_ShaderWH::poCreateShader("SmokeAlpha");
	oShTab[1] = CE3D_ShaderWH::poCreateShader("SmokeAdd");
	oShTab[2] = CE3D_ShaderWH::poCreateShader("Drip");    

    // Load PSys table
    CFile oFile;
    if (oFile.iOpen("base/data.ptt","rb"))
    {
        oFile.iRead(oPSTT,sizeof(TPSysType)*MAX_PSYS_TYPES);
        oFile.Close();
        
        // Convert process to runtime function
        for (int cI=0;cI<MAX_PSYS_TYPES;cI++)
        {
            switch ((int)CPSysMgr::oPSTT[cI].Process)
            {
                case 0:CPSysMgr::oPSTT[cI].Process =PPNoGravity;break;
                case 1:CPSysMgr::oPSTT[cI].Process =PPGravity;  break;

                default:CPSysMgr::oPSTT[cI].Process =PPNoGravity;break;
            }
            if (CPSysMgr::oPSTT[cI].fILTime == 0.0f)
                CPSysMgr::oPSTT[cI].fILTime = 1.0f;

            if (CPSysMgr::oPSTT[cI].fFreq == 0.0f)
               CPSysMgr::oPSTT[cI].fFreq = 1.0f;

            if (CPSysMgr::oPSTT[cI].fPeriod == 0.0f)
                CPSysMgr::oPSTT[cI].fPeriod = 1.0f / CPSysMgr::oPSTT[cI].fFreq;
        }
    }

	// ------------------------------
	// Create and setup the mesh
	// ------------------------------
	// 10*100 = Maximo de los sistemas de particulas
	iTotalMax = 0;

	for (i=0;i<MAX_PSYS_TYPES;i++)
	{
		oPSTT[i].iMaxPSys = 10;

		iMax = oPSTT[i].iMaxPSys*MAX_FREQ*MAX_LTIME;
		if (iTotalMax < iMax) iTotalMax = iMax;
	}

	oMesh.Init(	MAX_TYPEPART*4,
				MAX_TYPEPART,
				E3D_MESH_NIQUADS,
				MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS );

	for (iPart=0;iPart<MAX_TYPEPART;iPart++)
	{
		oMesh.UVs[iPart*4+0].V2(0.0f,0.0f);
		oMesh.UVs[iPart*4+1].V2(1.0f,0.0f);
		oMesh.UVs[iPart*4+2].V2(1.0f,1.0f);
        oMesh.UVs[iPart*4+3].V2(0.0f,1.0f);

		oMesh.VCs[iPart*4+0].V4(1.0f,1.0f,1.0f,0.5f);
		oMesh.VCs[iPart*4+1].V4(1.0f,1.0f,1.0f,0.5f);
		oMesh.VCs[iPart*4+2].V4(1.0f,1.0f,1.0f,0.5f);
		oMesh.VCs[iPart*4+3].V4(1.0f,1.0f,1.0f,0.5f);
	}

	// ------------------------------
	// Init PSys table
	// ------------------------------
	for (iPSys=0;iPSys<MAX_PSYS_TYPES;iPSys++)
		oPSys[iPSys] = mNew TPSysInstance[ oPSTT[iPSys].iMaxPSys ];		

	// ------------------------------
	// Init Particle table
	// ------------------------------
	for (iPart=0;iPart<MAX_PARTICLES;iPart++)
	{
		oPars[iPart].pParent = NULL;
		oPars[iPart].fLTime  = 0.0f;
	}

	Reset();
}
// -----------------------------------------------------------------------------
void CPSysMgr::Reset()
{
	int cI,cJ;
	for (cJ=0;cJ<MAX_PSYS_TYPES;cJ++)
		for (cI=0;cI<oPSTT[cJ].iMaxPSys;cI++)
			oPSys[cJ][cI].pParent = NULL;
}
// -----------------------------------------------------------------------------
// Add particle system instances 
// -----------------------------------------------------------------------------
void CPSysMgr::AddPSys(int _iType,void *_pParent,int _iChildNum,CVect3 &_roWorldPos,CVect3 &_roWorldDir)
{
	for (int cI=0;cI<oPSTT[_iType].iMaxPSys;cI++)
	{
		if ((oPSys[_iType][cI].pParent  == _pParent) &&
			(oPSys[_iType][cI].iChildNum== _iChildNum))
		{
			// update position and dir
			oPSys[_iType][cI].oPos.Assign(_roWorldPos);
			oPSys[_iType][cI].oDir.Assign(_roWorldDir);
			oPSys[_iType][cI].fTime     += lmfDelta;
			oPSys[_iType][cI].iStamp	= 1;
			
			// Control particle system generation frequency
			if (oPSys[_iType][cI].fTime > oPSTT[ oPSys[_iType][cI].iType ].fPeriod)
			{
				int iNumParts = oPSys[_iType][cI].fTime / oPSTT[ oPSys[_iType][cI].iType ].fPeriod;
				CreateParticles(&oPSys[_iType][cI],iNumParts);

				oPSys[_iType][cI].fTime = 0;
			}
			return;
		}
   else if (oPSys[_iType][cI].pParent == NULL)
		{
			// add			
			oPSys[_iType][cI].pParent	= _pParent;
			oPSys[_iType][cI].iChildNum	= _iChildNum;
			oPSys[_iType][cI].iType		= _iType;			
			oPSys[_iType][cI].oPos.Assign(_roWorldPos);
			oPSys[_iType][cI].oDir.Assign(_roWorldDir);
			oPSys[_iType][cI].fTime		= 0.0f;
			oPSys[_iType][cI].iStamp	= 1;

			CreateParticles(&oPSys[_iType][cI],1);
			return;
		}
	}
	
	// No ha sido posible ni encontrar el PSys, ni crear uno nuevo.
}
// -----------------------------------------------------------------------------
// Creating particles
// -----------------------------------------------------------------------------
float fSignRand()
{
	return ( 2.0f*MATH_Common::fRand() - 1.0f );
}

void GetRandomUnitVector(CVect3 &_roRes)
{
	// <WARNING> Este código tiene copyright.
	// Mirar en FLIP CODE
	int type;

	float	x1,y1,z1,d;
	float	x2,y2,z2;

	// calculate approximate unit vector pointed in arbitrary direction
	x2 = 2.0f*MATH_Common::fRand() - 1.0f;
	y2 = 2.0f*MATH_Common::fRand() - 1.0f;
	z2 = 2.0f*MATH_Common::fRand() - 1.0f;

	x1 = MATH_Common::fAbs(x2);
	y1 = MATH_Common::fAbs(y2);
	z1 = MATH_Common::fAbs(z2);

	if (x1 > y1)
	{
		if (x1>z1)
		{
			// x1 > y1    x1 > z1 
			if (y1>z1)
			{
				d = x1 + (.34375f*y1) + (.25f *z1);
			}
			else
			{
				d = x1 + (.34375f*z1) + (.25f *y1);
			}
		}
		else
		{
			// z1 > x1 > y1
			d = z1 + (.34375f*x1) + (.25f *y1);
		}
	}
	else
	{
		if (y1>z1)
		{
			// y1 > x1	y1 > z1
			if (x1>z1)
			{
				d = y1 + (.34375f*x1) + (.25f *z1);
			}
			else
			{
				d = y1 + (.34375f*z1) + (.25f *x1);
			}
		}
		else 
		{
			// z1 > y1 > x1
			d = z1 + (.34375f*y1) + (.25f *x1);
		}
	}

	float fInvD = 1.0f / d;
	x2 *= fInvD;
	y2 *= fInvD;
	z2 *= fInvD;

	_roRes.V3(x2,y2,z2);
}

void CPSysMgr::CreateParticle(TParticle &_roPart,TPSysInstance *_poParent)
{
	CVect3		oRandDir;
	TPSysType	*poPType = &oPSTT[ _poParent->iType ];

	GetRandomUnitVector(oRandDir);

	_roPart.oPos.V3(_poParent->oPos.X() + fSignRand()* poPType->oExtPos.X(),
					_poParent->oPos.Y() + fSignRand()* poPType->oExtPos.Y(),
					_poParent->oPos.Z() + fSignRand()* poPType->oExtPos.Z());
	
	_roPart.oSpeed.V3(_poParent->oDir.X() * poPType->fSpeed +  oRandDir.X() * poPType->fRSpeed,
					  _poParent->oDir.Y() * poPType->fSpeed +  oRandDir.Y() * poPType->fRSpeed,
					  _poParent->oDir.Z() * poPType->fSpeed +  oRandDir.Z() * poPType->fRSpeed);

	_roPart.oColor  = poPType->oIColor;
	_roPart.fAngle  = poPType->fIAngle*MATH_Common::fRand();    // Initial rotation
	_roPart.fDAngle = poPType->fDAngle*fSignRand();             // Angular velocity

	_roPart.fSize   = poPType->fISize  + poPType->fRSize *MATH_Common::fRand();

	_roPart.fLTime  = poPType->fILTime + poPType->fRLTime*MATH_Common::fRand();
	
	_roPart.fColor  = 0.0f;
	_roPart.fDColor = 1.0f / _roPart.fLTime;

	_roPart.pParent = _poParent;
}

void CPSysMgr::CreateParticles(TPSysInstance *_poParent,int _iNumParts)
{
	int			iPart;

	for (iPart=0;((iPart<MAX_PARTICLES) && (_iNumParts>0));iPart++)
	{
		if (oPars[iPart].fLTime<=0.0f)
		{
			CreateParticle( oPars[iPart],_poParent);
			_iNumParts --;									// 1 less particle
		}
	}
}

// -----------------------------------------------------------------------------
// Updating particles
// -----------------------------------------------------------------------------
void CPSysMgr::UpdateParticle(TParticle &_roPart)
{
	TPSysType	*poPType;
	float		fFact;

	poPType = &oPSTT[ _roPart.pParent->iType ];
	poPType->Process( &_roPart );

	// Size
	_roPart.fSize  += poPType->fDSize;

	// Angle
	_roPart.fAngle += _roPart.fDAngle;
	if (_roPart.fAngle  > _2PI_) _roPart.fAngle -= _2PI_;
else if (_roPart.fAngle < 0    ) _roPart.fAngle += _2PI_;

	// Color
	_roPart.fColor += (_roPart.fDColor*lmfDelta);
	fFact = _roPart.fColor;
	_roPart.oColor.r = poPType->oIColor.r + (poPType->oFColor.r - poPType->oIColor.r)*fFact;
	_roPart.oColor.g = poPType->oIColor.g + (poPType->oFColor.g - poPType->oIColor.g)*fFact;
	_roPart.oColor.b = poPType->oIColor.b + (poPType->oFColor.b - poPType->oIColor.b)*fFact;
	_roPart.oColor.a = poPType->oIColor.a + (poPType->oFColor.a - poPType->oIColor.a)*fFact;

	_roPart.fLTime -= lmfDelta;

    if (_roPart.fLTime <= 0.0f)
    {
        _roPart.fLTime = 0.0f;
        _roPart.pParent= NULL;
    }
}

void CPSysMgr::Update()
{
	int iType,iInst,iPart;

	// Update particle system instances
	for (iType=0;iType<MAX_PSYS_TYPES;iType++)
	{
		for (iInst=0;iInst<oPSTT[iType].iMaxPSys;iInst++)
		{
			if (oPSys[iType][iInst].iStamp)
				oPSys[iType][iInst].iStamp = 0;
			else
				// Orphan Particle system
				oPSys[iType][iInst].pParent = NULL;
		}
	}
	
	// Update particles
	for (iPart=0;iPart<MAX_PARTICLES;iPart++)
	{		
		if (oPars[iPart].fLTime > 0.0f)
			UpdateParticle(oPars[iPart]);
	}
}

// -----------------------------------------------------------------------------
// Rendering particles
// -----------------------------------------------------------------------------
inline void RT2DPoint(float _fCos,float _fSin,float _fX,float _fY,float _fXOfs,float _fYOfs,CVect3 &_roVX)
{
	_roVX.SetX( _fXOfs + ( _fX*_fCos + _fY*_fSin) );
	_roVX.SetY( _fYOfs + (-_fX*_fSin + _fY*_fCos) );
}

void CPSysMgr::AddParticle(TParticle &_roPart)
{
    // Maximum number of particles of this type reached
    if (oMesh.usNumPrims == MAX_TYPEPART) return;

	CVect3			oCamPos;
	CVect3			oVX[4];
	float			fSin,fCos;
	float			fSize = _roPart.fSize;

	oCamPos.Assign(_roPart.oPos);
	oCamMat.TransformPoint(oCamPos);

	fSin = sinf(_roPart.fAngle);
	fCos = cosf(_roPart.fAngle);

	RT2DPoint(fSin,fCos,-fSize, fSize,oCamPos.X(),oCamPos.Y(),oVX[0]);
	RT2DPoint(fSin,fCos,-fSize,-fSize,oCamPos.X(),oCamPos.Y(),oVX[1]);
	RT2DPoint(fSin,fCos, fSize,-fSize,oCamPos.X(),oCamPos.Y(),oVX[2]);
	RT2DPoint(fSin,fCos, fSize, fSize,oCamPos.X(),oCamPos.Y(),oVX[3]);

	oMesh.VXs[oMesh.usNumVerts+0].V3(oVX[0].X(),oVX[0].Y(),oCamPos.Z());
	oMesh.VXs[oMesh.usNumVerts+1].V3(oVX[1].X(),oVX[1].Y(),oCamPos.Z());
	oMesh.VXs[oMesh.usNumVerts+2].V3(oVX[2].X(),oVX[2].Y(),oCamPos.Z());
	oMesh.VXs[oMesh.usNumVerts+3].V3(oVX[3].X(),oVX[3].Y(),oCamPos.Z());

	oMesh.VCs[oMesh.usNumVerts+0].V4(_roPart.oColor.r,_roPart.oColor.g,_roPart.oColor.b,_roPart.oColor.a);
	oMesh.VCs[oMesh.usNumVerts+1].V4(_roPart.oColor.r,_roPart.oColor.g,_roPart.oColor.b,_roPart.oColor.a);
	oMesh.VCs[oMesh.usNumVerts+2].V4(_roPart.oColor.r,_roPart.oColor.g,_roPart.oColor.b,_roPart.oColor.a);
	oMesh.VCs[oMesh.usNumVerts+3].V4(_roPart.oColor.r,_roPart.oColor.g,_roPart.oColor.b,_roPart.oColor.a);

	oMesh.usNumVerts += 4;
	oMesh.usNumPrims ++;
}

void CPSysMgr::RenderPSys(TPSysInstance *_poElem)
{
	float		fAlpha;

	for (int iPart=0;iPart<MAX_PARTICLES;iPart++)
	{
		if (oPars[iPart].pParent == _poElem)
			AddParticle(oPars[iPart]);
	}
}
// -----------------------------------------------------------------------------
void CPSysMgr::Render()
{
	int				iType,cI,cJ;
	TPSysInstance	*poElem;

	lmfDelta = gpoE3DRenderer->REStats.DTime;
	// gpoE3DRenderer->GetCameraMatrix(&oCamMat);
	gpoE3DRenderer->GetCurrentMatrix  (&oCamMat);	
	gpoE3DRenderer->GetProjectorMatrix(&oPrjMat);	
	oCPMat.Multiply(oCamMat,oPrjMat);

	// Update the PSyss
	Update();

	// Render Mesh
	gpoE3DRenderer->ClearCameraMatrix();
	gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Current);
	gpoE3DRenderer->SetFogPars(eE3D_FM_None,0.0f,0.0f,0.0f,NULL);

	// Render the PSyss
	for (iType=0;iType<MAX_PSYS_TYPES;iType++)
	{
		oMesh.usNumPrims = 0;
		oMesh.usNumVerts = 0; 

		for (cI=0;cI<oPSTT[iType].iMaxPSys;cI++)
		{
			poElem = &oPSys[iType][cI];
			
			if (poElem->pParent != NULL)
				RenderPSys(poElem);
		}

		// Render the mesh
		if (oMesh.usNumPrims)
			gpoE3DRenderer->RenderMesh(&oMesh,oShTab[ oPSTT[iType].iTex ]);
	}

	gpoE3DRenderer->SetCurrentMatrix(&oCamMat);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Current);
	gpoE3DRenderer->SetFogPars(eE3D_FM_Last,0.0f,0.0f,0.0f,NULL);
}
// -----------------------------------------------------------------------------