//## begin module%3C294DBE032E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C294DBE032E.cm

//## begin module%3C294DBE032E.cp preserve=no
//## end module%3C294DBE032E.cp

//## Module: CCOL_MT_TerrainMesh%3C294DBE032E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_TerrainMesh.cpp

//## begin module%3C294DBE032E.additionalIncludes preserve=no
//## end module%3C294DBE032E.additionalIncludes

//## begin module%3C294DBE032E.includes preserve=yes
//## end module%3C294DBE032E.includes

// CCOL_ColState
#include "Collision\CollisionSystem\CCOL_ColState.h"
// CCOL_MT_TerrainMesh
#include "Collision\COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_TerrainMesh.h"
//## begin module%3C294DBE032E.additionalDeclarations preserve=yes
//## end module%3C294DBE032E.additionalDeclarations


// Class CCOL_MT_TerrainMesh 







CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh()
  //## begin CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh%.hasinit preserve=no
      : HF(NULL), iSectorRes(0), fRatio(0), iTWidth(0), iTHeight(0), fInvRatio(0)
  //## end CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh%.hasinit
  //## begin CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh%.initialization preserve=yes
  //## end CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh%.initialization
{
  //## begin CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh%.body preserve=yes
  //## end CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh%.body
}


CCOL_MT_TerrainMesh::~CCOL_MT_TerrainMesh()
{
  //## begin CCOL_MT_TerrainMesh::~CCOL_MT_TerrainMesh%.body preserve=yes
  //## end CCOL_MT_TerrainMesh::~CCOL_MT_TerrainMesh%.body
}



//## Other Operations (implementation)
int CCOL_MT_TerrainMesh::iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _roTriList)
{
  //## begin CCOL_MT_TerrainMesh::iTestCollision%1009321164.body preserve=yes

	// Convertir coordinadas SrcIPos, SrcFPos a coordenadas de terreno
	// Trazar el recorrido del objeto sobre el terreno, pixel a pixel.
	
	// Para cada coordenada (bresenhan line) obtener el par de triángulos apropiado
	// y testear colision del objeto con ese par de triángulos.
	
	// si hay colision, añadir a la lista (y retornar ?)
	// si no hay colision, continuar trazando hasta llegar al límite. 

	// (limite de sector si puede ser).
	CTriangle	Tri;
	CVect3		VXs[2048];
	CVect3		Normal;	
	CVect3		Pos;
	int			iNumTris;

	int			iIX,iIY,iFX,iFY,iXRange,iYRange,iSteps,iS;
	float		fXStep,fYStep,fZStep,fActX,fActY,fActZ;
	float		fHeight,fHalfZObj;	
	float		fColTime;
		
	iIX = CCOL_ColState::SrcIPos.X()*fRatio;
	iIY = CCOL_ColState::SrcIPos.Y()*fRatio;
	iFX = CCOL_ColState::SrcFPos.X()*fRatio;
	iFY = CCOL_ColState::SrcFPos.Y()*fRatio;

	iXRange = iFX - iIX;
	iYRange = iFY - iIY;

	if (MATH_Common::fAbs(iXRange) == MATH_Common::fAbs(iYRange))
	{
		iSteps = MATH_Common::fAbs(iXRange);
		fXStep = MATH_Common::fSign(iXRange);
		fYStep = MATH_Common::fSign(iYRange);
	}
	else
	{
		if (MATH_Common::fAbs(iXRange) > MATH_Common::fAbs(iYRange))
		{
			iSteps = MATH_Common::fAbs(iXRange);
			fXStep = MATH_Common::fSign(iXRange);
			fYStep = (float)iYRange/(float)iSteps;
		}
		else
		{
			iSteps = MATH_Common::fAbs(iYRange);
			fXStep = (float)iXRange/(float)iSteps;
			fYStep = MATH_Common::fSign(iYRange);
		}
	}
	
	if (! iSteps)
		fZStep = 0.0f;
	else
		fZStep = (CCOL_ColState::SrcFPos.Z() - CCOL_ColState::SrcIPos.Z()) / (float)iSteps;

	// Loop throught all the traversed triangles
	fActX	 = iIX;
	fActY	 = iIY;
	fActZ    = CCOL_ColState::SrcIPos.Z();

	fHalfZObj= _poBVol->GetExtents().Z();
   
    iNumTris = 0;

	for (iS=0;iS<=iSteps;iS++)
	{
		if (MATH_Common::bInRange(fActX,0,iTWidth ) &&
			MATH_Common::bInRange(fActY,0,iTHeight))
		{
			// Get the triangles associated with the pixel			
			GetTriangle(fActX,fActY,VXs);


			// Get position of collision
			Pos.Interpolate( CCOL_ColState::SrcIPos,
							 CCOL_ColState::SrcFPos,
							 (float)iS/(iSteps+1) );

			// Test for collision with the first tri
			Tri.Init(VXs);
			Tri.ComputeAll();

			
			fColTime = CCOL_DT_ColTester::fTestTriangle(_poBVol,Tri);
			if (fColTime >= 0.0f)
			{
				_roTriList.iAddTri(Tri.VXs,Tri.Normal,-1,fColTime);
				iNumTris ++;
			}
			
			// Test for collision with the second tri
			Tri.Init(VXs+3);
			Tri.ComputeAll();

			fColTime = CCOL_DT_ColTester::fTestTriangle(_poBVol,Tri);
			if (fColTime >= 0.0f)
			{
				_roTriList.iAddTri(Tri.VXs,Tri.Normal,-1,fColTime);
				iNumTris ++;
			}
		}

		fActX += fXStep;
		fActY += fYStep;
		fActZ += fZStep;
	}
	return (iNumTris);
	/*
	CVect3		VXs[2048];
	CVect3		Normal;
	CTriangle	Tri;
	int			iNumTris,iTri;
	int			iSelTris;

	int		iIX,iIY,iFX,iFY,iXRange,iYRange,iSteps,iS,iRatio,iLevel;
	
	float	fXStep,fYStep,fActX,fActY;
		
	iIX = CCOL_ColState::SrcIPos.X()*fRatio;
	iIY = CCOL_ColState::SrcIPos.Y()*fRatio;
	iFX = CCOL_ColState::SrcFPos.X()*fRatio;
	iFY = CCOL_ColState::SrcFPos.Y()*fRatio;	

	iXRange = iFX - iIX;
	iYRange = iFY - iIY;	

	if (MATH_Common::fAbs(iXRange) == MATH_Common::fAbs(iYRange))
	{
		iSteps = 1;
		fXStep = MATH_Common::fSign(iXRange);
		fYStep = MATH_Common::fSign(iYRange);
	}
	else
	{
		if (MATH_Common::fAbs(iXRange) > MATH_Common::fAbs(iYRange))
		{
			iSteps = MATH_Common::fAbs(iXRange);
			fXStep = MATH_Common::fSign(iXRange);
			fYStep = (float)iYRange/(float)iSteps;
		}
		else
		{
			iSteps = MATH_Common::fAbs(iYRange);
			fXStep = (float)iXRange/(float)iSteps;
			fYStep = MATH_Common::fSign(iYRange);
		}
	}

	fZStep = (CCOL_ColState::SrcFPos.Z() - CCOL_ColState::SrcIPos.Z()) / (float)iSteps;

	// Loop throught all the traversed triangles
	fActX	 = iIX;
	fActY	 = iIY;
	
	iRatio   = _BVol->GetMaxExtent()*fRatio + 1.0f;
	for (iS=0;iS<=iSteps;iS++)
	{
		if (MATH_Common::bInRange(fActX,iRatio,iTWidth -iRatio) &&
			MATH_Common::bInRange(fActY,iRatio,iTHeight-iRatio))
		{
			// Get the triangles associated with the pixel

			/*
			for (iLevel=-iRatio;iLevel<=iRatio;iLevel++)
			{
				GetTriangle(fActX+iLevel,fActY+iLevel,VXs);

				Tri.Init(VXs);		Tri.ComputeAll();
				if (CCOL_DT_ColTester::iTestTriangle(_BVol,Tri))
				{
					_rTriList.iAddTri(Tri.VXs,Tri.Normal);
					iNumTris++;
					// return(1);
				}

				Tri.Init(VXs+3);		Tri.ComputeAll();
				if (CCOL_DT_ColTester::iTestTriangle(_BVol,Tri))
				{
					_rTriList.iAddTri(Tri.VXs,Tri.Normal);
					iNumTris++;
					// return(1);
				}
			}*/
				// Test the selected triangles
				/*
				iSelTris  = iGetTriangles(fActX,fActY,iRatio,VXs);

				for (iTri=0;iTri<iSelTris;iTri++)
				{					
					Tri.Init(VXs + iTri*3);		Tri.ComputeAll();
					if (CCOL_DT_ColTester::iTestTriangle(_BVol,Tri))
					{
						_rTriList.iAddTri(Tri.VXs,Tri.Normal);
						iNumTris++;
						// return(1);
					}
				}

			
		}

		fActX += fXStep;
		fActY += fYStep;
	}
	return(iNumTris);
*/
  //## end CCOL_MT_TerrainMesh::iTestCollision%1009321164.body
}

int CCOL_MT_TerrainMesh::iGetTriangles (int _iX, int _iY, int _iRad, CVect3* _pVXs)
{
  //## begin CCOL_MT_TerrainMesh::iGetTriangles%1009321167.body preserve=yes
	int iIX,iFX;
	int iIY,iFY;
	int cI,cJ;
	
	iIX = _iX - _iRad;
	iFX = _iX + _iRad;
	iIY = _iY - _iRad;
	iFY = _iY + _iRad;

	for (cJ=iIY;cJ<=iFY;cJ++)
		for (cI=iIX;cI<=iFX;cI++)
		{
			GetTriangle(cI,cJ,_pVXs);
			_pVXs +=6;
		}

	return(2*(2*_iRad+1)*(2*_iRad+1));
  //## end CCOL_MT_TerrainMesh::iGetTriangles%1009321167.body
}

void CCOL_MT_TerrainMesh::GetTriangle (int _iX, int _iY, CVect3* _pa6VXs)
{
  //## begin CCOL_MT_TerrainMesh::GetTriangle%1009406733.body preserve=yes
  	float fH[4];
	float fIX,fFX;
	float fIY,fFY;

	fH[0] = GetHeight(_iX  ,_iY  );
	fH[1] = GetHeight(_iX+1,_iY  );
	fH[2] = GetHeight(_iX  ,_iY+1);
	fH[3] = GetHeight(_iX+1,_iY+1);

	fIX = _iX*fInvRatio;
	fFX = fIX + fInvRatio;
	
	fIY = _iY*fInvRatio;
	fFY = fIY + fInvRatio;

	_pa6VXs[0].V3(fIX,fIY,fH[0]);
	_pa6VXs[1].V3(fIX,fFY,fH[2]);
	_pa6VXs[2].V3(fFX,fFY,fH[3]);

	_pa6VXs[3].V3(fIX,fIY,fH[0]);
	_pa6VXs[4].V3(fFX,fFY,fH[3]);
	_pa6VXs[5].V3(fFX,fIY,fH[1]);
  //## end CCOL_MT_TerrainMesh::GetTriangle%1009406733.body
}

float CCOL_MT_TerrainMesh::GetHeight (int iX, int iY)
{
  //## begin CCOL_MT_TerrainMesh::GetHeight%1009321166.body preserve=yes
  	int		iXSect = iX / iSectorRes;
	int		iYSect = iY / iSectorRes;
	
	iX -= iXSect*iSectorRes;
	iY -= iYSect*iSectorRes;
	
	float *pfa = (float *) ((CHFSector*)HF->GetSector(iXSect,iYSect))->GetValue(iX,iY).Get();
	
	return(*pfa);
  //## end CCOL_MT_TerrainMesh::GetHeight%1009321166.body
}

void CCOL_MT_TerrainMesh::Init (CHeightField* _pHF, int _iSectorRes, float _fSectorSize)
{
  //## begin CCOL_MT_TerrainMesh::Init%1009321165.body preserve=yes
  	HF			= _pHF;

	iSectorRes  = _iSectorRes;	
	
	fRatio      = (float)iSectorRes/_fSectorSize;
	fInvRatio   = 1.0f / fRatio;

	iTWidth		= HF->iGetSecsPerRow()*_iSectorRes-2;
	iTHeight	= HF->iGetSecsPerCol()*_iSectorRes-2;
  //## end CCOL_MT_TerrainMesh::Init%1009321165.body
}

// Additional Declarations
  //## begin CCOL_MT_TerrainMesh%3C294DBE032E.declarations preserve=yes
  //## end CCOL_MT_TerrainMesh%3C294DBE032E.declarations

//## begin module%3C294DBE032E.epilog preserve=yes
//## end module%3C294DBE032E.epilog
