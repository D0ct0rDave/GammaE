//## begin module%3C742BB2030E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C742BB2030E.cm

//## begin module%3C742BB2030E.cp preserve=no
//## end module%3C742BB2030E.cp

//## Module: CMapTriSceneGen%3C742BB2030E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\CMapTriSceneGen.cpp

//## begin module%3C742BB2030E.additionalIncludes preserve=no
//## end module%3C742BB2030E.additionalIncludes

//## begin module%3C742BB2030E.includes preserve=yes
#include "memory/gammae_mem.h"

#define	_PLANE_DIST_EPSILON_	0.05f
#define	_PLANE_NORMAL_EPSILON_	0.0001f
//## end module%3C742BB2030E.includes

// CMapTriSceneGen
#include "Tools\GEMapCompiler\MapData\CMapTriSceneGen.h"
//## begin module%3C742BB2030E.additionalDeclarations preserve=yes

typedef struct{
	CVect3	oPoint;
	float	fAngle;
	int		iIdx;
}TCoplanarPoint;

int SortCoplanarPoints( const void *a, const void *b)
{
	TCoplanarPoint *pPA = (TCoplanarPoint*)a;
	TCoplanarPoint *pPB = (TCoplanarPoint*)b;
	
	if (pPA->fAngle == pPB->fAngle) return(0);
	if (pPA->fAngle < pPB->fAngle) return(-1);
	return(1);
}

void TextureAxisFromPlane(CPlane &_roPlane,CVect3 &_roXAxis,CVect3 &_roYAxis)
{
	// Get the best axis 
	// From TextureAxisFromPlane in textures.c from QBSP tool of 
	// Quake2 ID Software Inc.
	CVect3 oBaseAxis[18];

	oBaseAxis[ 0].V3( 0, 0, 1);
	oBaseAxis[ 1].V3( 1, 0, 0);
	oBaseAxis[ 2].V3( 0,-1, 0);		// floor
	oBaseAxis[ 3].V3( 0, 0,-1);
	oBaseAxis[ 4].V3( 1, 0, 0);
	oBaseAxis[ 5].V3( 0,-1, 0);		// ceiling
	oBaseAxis[ 6].V3( 1, 0, 0);
	oBaseAxis[ 7].V3( 0, 1, 0);
	oBaseAxis[ 8].V3( 0, 0,-1);		// west wall
	oBaseAxis[ 9].V3(-1, 0, 0);
	oBaseAxis[10].V3( 0, 1, 0);
	oBaseAxis[11].V3( 0, 0,-1);		// east wall
	oBaseAxis[12].V3( 0, 1, 0);
	oBaseAxis[13].V3( 1, 0, 0);
	oBaseAxis[14].V3( 0, 0,-1);		// south wall
	oBaseAxis[15].V3( 0,-1, 0);
	oBaseAxis[16].V3( 1, 0, 0);
	oBaseAxis[17].V3( 0, 0,-1);		// north wall

	int		iBestAxis;
	float	fDot,fBest;
	int		cI;
	
	fBest     = 0;
	iBestAxis = 0;
	
	for (cI=0;cI<6;cI++)
	{
		fDot = _roPlane.Normal().DotProd(oBaseAxis[cI*3]);

		if (fDot > fBest)
		{
			fBest     = fDot;
			iBestAxis = cI;
		}
	}

	_roXAxis.Assign(oBaseAxis[iBestAxis*3+1]);
	_roYAxis.Assign(oBaseAxis[iBestAxis*3+2]);
}

void ComputeUV(float *_pfU,float *_pfV,CVect3 &_roVX,CMapBrushSide &_roBSide)
{	
	float	fUOfs;
	float	fVOfs;
	float	fCRot;
	float	fSRot;
	CVect3	oXAxis;
	CVect3	oYAxis;
	CVect3	oV3Origin(0.0f,0.0f,0.0f);

	// Get texture axis
	TextureAxisFromPlane(_roBSide.oPlane,oXAxis,oYAxis);

	// Compute U and V Offsets	
	fUOfs = oV3Origin.DotProd(oXAxis);
	fVOfs = oV3Origin.DotProd(oYAxis);	

	// Compute angle based on brushside info
	if (_roBSide.fAngle == 0)
		{	fSRot = 0.0f;	fCRot =  1.0f;	}
	else if (_roBSide.fAngle == 90)
		{	fSRot = 1.0f;	fCRot =  0.0f;	}
	else if (_roBSide.fAngle == 180)
		{	fSRot = 0.0f;	fCRot = -1.0f;	}
	else if (_roBSide.fAngle == 270)
		{	fSRot =-1.0f;	fCRot =  0.0f;	}
	else
	{
		float fAngle = _roBSide.fAngle*_PI_OVER_180_;
		fCRot = (float)cos(fAngle);
		fSRot = (float)sin(fAngle);
	}

	// Rotate axis
	int iSv,iTv;

	if (oXAxis.X())
		iSv = 0;
	else if (oXAxis.Y())
		iSv = 1;
	else
		iSv = 2;
				
	if (oYAxis.X())
		iTv = 0;
	else if (oYAxis.Y())
		iTv = 1;
	else
		iTv = 2;

	float fNewS,fNewT;
	
	fNewS = fCRot * oXAxis.v[iSv] - fSRot*oXAxis.v[iTv];
	fNewT = fSRot * oXAxis.v[iSv] + fCRot*oXAxis.v[iTv];
	oXAxis.v[iSv] = fNewS;
	oXAxis.v[iTv] = fNewT;

	fNewS = fCRot * oYAxis.v[iSv] - fSRot*oYAxis.v[iTv];
	fNewT = fSRot * oYAxis.v[iSv] + fCRot*oYAxis.v[iTv];
	oYAxis.v[iSv] = fNewS;
	oYAxis.v[iTv] = fNewT;

	oXAxis.Scale(1.0f / _roBSide.fUScale);
	oYAxis.Scale(1.0f / _roBSide.fVScale);

	*_pfU =(_roVX.X()*oXAxis.X() + 
			_roVX.Y()*oXAxis.Y() + 
			_roVX.Z()*oXAxis.Z() + fUOfs + _roBSide.fUOfs) / (float)_roBSide.iTexW;

	*_pfV =(_roVX.X()*oYAxis.X() + 
			_roVX.Y()*oYAxis.Y() + 
			_roVX.Z()*oYAxis.Z() + fVOfs + _roBSide.fVOfs) / (float)_roBSide.iTexH;
}

void RetrieveTexInfo(char *_szFilename,int *_piTX,int *_piTY)
{
	TMipMapObj *poMMObj = TMipMapWarehouse::LoadMipMap(_szFilename,0,MMCM_BilinearFiltering);

	if (! poMMObj)
	{
		*_piTX = 1;
		*_piTY = 1;
	}
	else
	{
		if (poMMObj->MipMap.TX != 0) *_piTX = poMMObj->MipMap.TX; else *_piTX =1;
		if (poMMObj->MipMap.TY != 0) *_piTY = poMMObj->MipMap.TY; else *_piTY =1;
	}	
}
//## end module%3C742BB2030E.additionalDeclarations


// Class CMapTriSceneGen 

//## begin CMapTriSceneGen::szTexturePath%3CB2144B033D.attr preserve=no  private: static char[256] {UA} 
char CMapTriSceneGen::szTexturePath[256];
//## end CMapTriSceneGen::szTexturePath%3CB2144B033D.attr

//## begin CMapTriSceneGen::poMatTable%3C76E1A0019B.role preserve=no  public: static SCNUt_MaterialTable { -> RHAN}
SCNUt_MaterialTable *CMapTriSceneGen::poMatTable;
//## end CMapTriSceneGen::poMatTable%3C76E1A0019B.role

CMapTriSceneGen::CMapTriSceneGen()
  //## begin CMapTriSceneGen::CMapTriSceneGen%.hasinit preserve=no
  //## end CMapTriSceneGen::CMapTriSceneGen%.hasinit
  //## begin CMapTriSceneGen::CMapTriSceneGen%.initialization preserve=yes
  //## end CMapTriSceneGen::CMapTriSceneGen%.initialization
{
  //## begin CMapTriSceneGen::CMapTriSceneGen%.body preserve=yes
	szTexturePath[0] = 0;
  //## end CMapTriSceneGen::CMapTriSceneGen%.body
}


CMapTriSceneGen::~CMapTriSceneGen()
{
  //## begin CMapTriSceneGen::~CMapTriSceneGen%.body preserve=yes
  //## end CMapTriSceneGen::~CMapTriSceneGen%.body
}



//## Other Operations (implementation)
SCNUt_TriScene* CMapTriSceneGen::poGenerateScene (CMapScene& _roMapScene)
{
  //## begin CMapTriSceneGen::poGenerateScene%1014246308.body preserve=yes
	int							cB;
	SCNUt_TriScene				*poBScn;
	SCNUt_TriSceneAccumulator	*poTScn = mNew SCNUt_TriSceneAccumulator;
	poTScn->Init(0,32768);		// Realloc by 32768 tris
	
	if (poMatTable) mDel poMatTable;
	poMatTable = mNew SCNUt_MaterialTable;
	poMatTable->Init(_roMapScene.iNumBrushes * 16);

	for (cB=0;cB<_roMapScene.iNumBrushes;cB++)
	{
		poBScn = poDecomposeBrush(*_roMapScene.poBrush[cB]);
		if (poBScn) poTScn->AddTriScene(poBScn);
		
		mDel poBScn;
	}

//	mDel poMatTable;
	return(poTScn);
  //## end CMapTriSceneGen::poGenerateScene%1014246308.body
}

SCNUt_TriScene * CMapTriSceneGen::poDecomposeBrush (CMapBrush& _roBrush)
{
  //## begin CMapTriSceneGen::poDecomposeBrush%1014330409.body preserve=yes
	int		iM,jM,kM;
	int		cI,cJ,cK;	
	float	fD1,fD2,fD3;	
	int		iNumPoints;
	CVect3	*poPoints;
	CVect3	*poAuxPoints;
	CVect3  oPoint;
	CPlane  *poPlane1,*poPlane2,*poPlane3;

	if (_roBrush.iNumBSides<4) return(NULL);

	iM = _roBrush.iNumBSides-2;
	jM = _roBrush.iNumBSides-1;
	kM = _roBrush.iNumBSides;

	iNumPoints=0;

	// Compute brush points
	for(cI=0;cI<iM;cI++)
	{
		poPlane1 = &_roBrush.poBSides[cI].oPlane;

		for(cJ=cI+1;cJ<jM;cJ++)
		{
			poPlane2 = &_roBrush.poBSides[cJ].oPlane;			

			for(cK=cJ+1;cK<kM;cK++)
			{
				poPlane3 = &_roBrush.poBSides[cK].oPlane;

				if (! MATH_Utils::iTest3PlaneIntersection(*poPlane1,*poPlane2,*poPlane3,oPoint))
					continue;

				if (! bPointInBrush(oPoint,_roBrush))
					continue;

				if (bPointAlreadyInList (oPoint,poPoints,iNumPoints))
					continue;

				// --------------------------------------------------------
				poAuxPoints = mNew CVect3[iNumPoints+1];
				if (iNumPoints>0)
				{
					memcpy(poAuxPoints,poPoints,iNumPoints*sizeof(CVect3));
					mDel []poPoints;
				}

				poPoints = poAuxPoints;
				poPoints[iNumPoints].Assign(oPoint);
				iNumPoints++;
				// --------------------------------------------------------
			}
		}
	}

	// Manage materials 
	char		szStrBuff[256];
	CE3D_Shader *poShader;
	for (cI=0;cI<_roBrush.iNumBSides;cI++)
	{		
		if (*szTexturePath)
			sprintf(szStrBuff,"%s\\%s",szTexturePath,_roBrush.poBSides[cI].szTex);
		else
			sprintf(szStrBuff,"%s",_roBrush.poBSides[cI].szTex);

		RetrieveTexInfo(szStrBuff,&_roBrush.poBSides[cI].iTexW,&_roBrush.poBSides[cI].iTexH);

		poShader = CE3D_ShaderWH::poCreateShader(szStrBuff);
		_roBrush.poBSides[cI].iTex = poMatTable->iAddShader(poShader);
	}

	return( poBrush2Tris(poPoints,iNumPoints,_roBrush) );
  //## end CMapTriSceneGen::poDecomposeBrush%1014330409.body
}

bool CMapTriSceneGen::bPointInBrush (CVect3& _roPoint, CMapBrush& _roBrush)
{
  //## begin CMapTriSceneGen::bPointInBrush%1014762715.body preserve=yes

	/*
	// Property A: 2 planes could only intersect if the angle between their normals
	// is in (-90,90) else we can produce non-convex polyedra.
	fD1 = poPlane1->Normal().DotProd(poPlane2->Normal());
	if (fD1 < -_EPSILON2_) continue;
	*/

	// Some planes generate points but they are not valid since they could
	// make non-convex solids. In order to prevent this, we shall test if the 
	// generated point, is inside the given brush

	int iSide;
	for (iSide=0;iSide<_roBrush.iNumBSides;iSide++)
	{
		float fDist = _roBrush.poBSides[iSide].oPlane.GetDistanceToPoint(_roPoint);
		if (fDist > _PLANE_DIST_EPSILON_)
		// if (MATH_Utils::iTestPointPlane(_roPoint,_roBrush.poBSides[iSide].oPlane)>0)		
			return(false);
	}

	return(true);
  //## end CMapTriSceneGen::bPointInBrush%1014762715.body
}

bool CMapTriSceneGen::bPointAlreadyInList (CVect3& _roPnt, CVect3* _poVXs, int _iNumPnts)
{
  //## begin CMapTriSceneGen::bPointAlreadyInList%1014767412.body preserve=yes

	int iPoint;
	for (iPoint=0;iPoint<_iNumPnts;iPoint++)
	{
		if (_roPnt.Equal(_poVXs[iPoint]))
			return(true);
	}

	return(false);
  //## end CMapTriSceneGen::bPointAlreadyInList%1014767412.body
}

SCNUt_TriScene * CMapTriSceneGen::poBrush2Tris (CVect3* _poPoints, int _iNumPoints, CMapBrush& _roBrush)
{
  //## begin CMapTriSceneGen::poBrush2Tris%1014330410.body preserve=yes
	int		cPlane;
	SCNUt_TriSceneAccumulator	*poTSA = mNew SCNUt_TriSceneAccumulator;
	SCNUt_TriScene				*poTScn;

	// For each plane
	for (cPlane=0;cPlane<_roBrush.iNumBSides;cPlane++)
	{		
		// Generate the list of points belonging this plane
		poTScn = poBrushSide2Tris(_poPoints,_iNumPoints,_roBrush.poBSides[cPlane]);
		if (poTScn)
		{
			poTSA->AddTriScene(poTScn);
			mDel poTScn;
		}
	}

	return(poTSA);
  //## end CMapTriSceneGen::poBrush2Tris%1014330410.body
}

SCNUt_TriScene * CMapTriSceneGen::poBrushSide2Tris (CVect3* _poPoints, int _iNumPoints, CMapBrushSide& _roBSide)
{
  //## begin CMapTriSceneGen::poBrushSide2Tris%1014393896.body preserve=yes
	if (! _iNumPoints) return(NULL);

	int				cPoint;
	int				iTPoints;
	CVect3			*poTPoint = mNew CVect3        [_iNumPoints];
	TCoplanarPoint  *poCopPnt = mNew TCoplanarPoint[_iNumPoints];
	CVect3			oCenter;
	CVect3			oV1;
	CVect3			oV2;
	CVect3			oV3;
	float			fAngle1;
	float			fAngle2;
	SCNUt_TriScene *poTScn;
	float			fDist;

	// Retrieve points belonging the plane
	iTPoints = 0;
	for (cPoint=0;cPoint<_iNumPoints;cPoint++)
	{
		fDist = _roBSide.oPlane.GetDistanceToPoint(_poPoints[cPoint]);
		if ( MATH_Common::fAbs(fDist) <= _PLANE_DIST_EPSILON_ )
		{
			poTPoint[iTPoints].Assign(_poPoints[cPoint]);
			iTPoints++;
		}
	}

	if (! iTPoints)
	{
		mDel []poTPoint;
		mDel []poCopPnt;
		return(NULL);
	}

	// Compute centroid of polygon
	oCenter.V3(0.0f,0.0f,0.0f);
	for (cPoint=0;cPoint<iTPoints;cPoint++)
		oCenter.Add(poTPoint[cPoint]);

	oCenter.Scale(1.0f / (float)iTPoints);

	// Compute angles from the first to the rest of the points (for vertex ordering)
	oV1.Assign(poTPoint[0]);
	oV1.Sub   (oCenter);
	oV1.Normalize();
	
	oV2.CrossProd(oV1,_roBSide.oPlane.Normal());
	
	poCopPnt[0].oPoint.Assign(poTPoint[0]);
	poCopPnt[0].fAngle = 0.0f;
	poCopPnt[0].iIdx   = 0;

	for (cPoint=1;cPoint<iTPoints;cPoint++)
	{
		oV3.Assign(poTPoint[cPoint]);
		oV3.Sub   (oCenter);
		oV3.Normalize();

		fAngle1 = oV3.DotProd(oV1);	// Maniobra super astuta, operar con los 2
		fAngle2 = oV3.DotProd(oV2);	// ángulos para saber que cuadrante estamos
									// from Q2toQ3T / file Q2toQ3T.cpp / line 7023

		if (fAngle2 <= 0.0f)
			fAngle1 = 2.0f + (fAngle1+1.0f);
		else
			fAngle1 = (1.0f - fAngle1);
/*
		// avoid -1.#IND0 when acos(1.0)

		if (fAngle2 <= 0.0f)
			fAngle1 = _2PI_ - acos(fAngle1);
		else
			fAngle1 = acos(fAngle1);
*/
		poCopPnt[cPoint].oPoint.Assign(poTPoint[cPoint]);
		poCopPnt[cPoint].fAngle = fAngle1;
		poCopPnt[cPoint].iIdx   = cPoint;
	}

	// Sort points by angle
	qsort(poCopPnt,iTPoints,sizeof(TCoplanarPoint),SortCoplanarPoints);

	// generate an ordered point list
	for (cPoint=0;cPoint<iTPoints;cPoint++)
		poTPoint[cPoint].Assign( poCopPnt[cPoint].oPoint );

	// here we have the polygon vertexs so, generate triangles with them
	poTScn = poPoly2Tris(poTPoint,iTPoints,_roBSide,_roBSide.iTex);

	mDel []poTPoint;
	mDel []poCopPnt;

	return(poTScn);
  //## end CMapTriSceneGen::poBrushSide2Tris%1014393896.body
}

SCNUt_TriScene * CMapTriSceneGen::poPoly2Tris (CVect3* _poPoints, int _iNumPoints, CMapBrushSide& _roBSide, int _iMaterial)
{
  //## begin CMapTriSceneGen::poPoly2Tris%1014393897.body preserve=yes
	if (_iNumPoints < 3) return(NULL);
	
	SCNUt_TriScene *poTScn;
	int				iTri;
	CVect3			oTriNormal;
	CPlane			oPlane;
	
	// Create triangle scene object
	poTScn = mNew SCNUt_TriScene;
	poTScn->Init(_iNumPoints-2);
	for (iTri=0;iTri<_iNumPoints-2;iTri++)
	{
		// Setup vertexs
		poTScn->Tris[iTri].VXs[0].Assign( _poPoints[0] );
		poTScn->Tris[iTri].VXs[1].Assign( _poPoints[iTri+1] );
		poTScn->Tris[iTri].VXs[2].Assign( _poPoints[iTri+2] );

		// winding is different from Quake and GammaE
		SCNUt_TriUtils::ChangeWinding(poTScn->Tris[iTri]);

		// Generate triangle normals
		oPlane.GenerateFromPoints(poTScn->Tris[iTri].VXs[0],
								  poTScn->Tris[iTri].VXs[1],
								  poTScn->Tris[iTri].VXs[2]);

		poTScn->Tris[iTri].VNs[0].Assign(oPlane.Normal());
		poTScn->Tris[iTri].VNs[1].Assign(oPlane.Normal());
		poTScn->Tris[iTri].VNs[2].Assign(oPlane.Normal());

		// Setup colors
		poTScn->Tris[iTri].VCs[0].V4(1.0f,1.0f,1.0f,1.0f);
		poTScn->Tris[iTri].VCs[1].V4(1.0f,1.0f,1.0f,1.0f);
		poTScn->Tris[iTri].VCs[2].V4(1.0f,1.0f,1.0f,1.0f);

		ComputeTriUV(poTScn->Tris[iTri],_roBSide);

		// Setup material
		poTScn->Tris[iTri].Material = _iMaterial;

		// Control triangle winding
		// if (_roBSide.oPlane.Normal().DotProd(oPlane.Normal()) < _PLANE_NORMAL_EPSILON_)
			// Change winding
			// SCNUt_TriUtils::ChangeWinding(poTScn->Tris[iTri]);		

	}

	return(poTScn);
  //## end CMapTriSceneGen::poPoly2Tris%1014393897.body
}

void CMapTriSceneGen::ComputeTriUV (SCNUt_Triangle &_roTri, CMapBrushSide& _roBSide)
{
  //## begin CMapTriSceneGen::ComputeTriUV%1014668746.body preserve=yes
	ComputeUV(&_roTri.UVs[0].v[0],&_roTri.UVs[0].v[1],_roTri.VXs[0],_roBSide);
	ComputeUV(&_roTri.UVs[1].v[0],&_roTri.UVs[1].v[1],_roTri.VXs[1],_roBSide);
	ComputeUV(&_roTri.UVs[2].v[0],&_roTri.UVs[2].v[1],_roTri.VXs[2],_roBSide);
	
	SCNUt_TriUtils::MinimizeMappingOffset(_roTri);
  //## end CMapTriSceneGen::ComputeTriUV%1014668746.body
}

void CMapTriSceneGen::SetTexturePath (char *_szTexturePath)
{
  //## begin CMapTriSceneGen::SetTexturePath%1018303589.body preserve=yes
	strcpy(szTexturePath,_szTexturePath);
  //## end CMapTriSceneGen::SetTexturePath%1018303589.body
}

// Additional Declarations
  //## begin CMapTriSceneGen%3C742BB2030E.declarations preserve=yes
  //## end CMapTriSceneGen%3C742BB2030E.declarations

//## begin module%3C742BB2030E.epilog preserve=yes
//## end module%3C742BB2030E.epilog
