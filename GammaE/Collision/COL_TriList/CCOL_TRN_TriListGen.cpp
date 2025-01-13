///## begin module%3B5DED78033E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B5DED78033E.cm

//## begin module%3B5DED78033E.cp preserve=no
//## end module%3B5DED78033E.cp

//## Module: CCOL_TRN_TriListGen%3B5DED78033E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_TriList\CCOL_TRN_TriListGen.cpp

//## begin module%3B5DED78033E.additionalIncludes preserve=no
//## end module%3B5DED78033E.additionalIncludes

//## begin module%3B5DED78033E.includes preserve=yes
//## end module%3B5DED78033E.includes

// CCOL_TRN_TriListGen
#include "Collision\COL_TriList\CCOL_TRN_TriListGen.h"
//## begin module%3B5DED78033E.additionalDeclarations preserve=yes


inline void TEST_Triangle(CVect3 *_poVXs,int _iMat,int &_riTris,CCOL_TriList& _roTriList,CVect3 &_roPos,float _fSqrRadius)
{
	_roTriList.iAddTri(_poVXs,_poVXs[0],_iMat,0.0f);
	_riTris ++;
	return;
	
	/*
	CTriangle	oTri;	
	CVect3		oNorm;
	float		fSqrDist;

	oTri.Init(_poVXs);
	oTri.Normal.Normalize();
	oTri.ComputeAll();

	fSqrDist = MATH_Utils::fTriPointSqDistance(oTri,_roPos);
	if ( fSqrDist < _fSqrRadius )
	{
		_roTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,0.0f);
		_riTris ++;
	}
	*/
}

//## end module%3B5DED78033E.additionalDeclarations


// Class CCOL_TRN_TriListGen 

//## begin CCOL_TRN_TriListGen::fSectorSize%3B5DEE170190.attr preserve=no  private: static float {UA} 
float CCOL_TRN_TriListGen::fSectorSize;
//## end CCOL_TRN_TriListGen::fSectorSize%3B5DEE170190.attr

//## begin CCOL_TRN_TriListGen::HFs%3B5DEE1F008C.attr preserve=no  private: static CHFSector* * {UA} NULL
CHFSector* *CCOL_TRN_TriListGen::HFs = NULL;
//## end CCOL_TRN_TriListGen::HFs%3B5DEE1F008C.attr

//## begin CCOL_TRN_TriListGen::iSecsPerRow%3B5DEE8701F4.attr preserve=no  private: static int {UA} 0
int CCOL_TRN_TriListGen::iSecsPerRow = 0;
//## end CCOL_TRN_TriListGen::iSecsPerRow%3B5DEE8701F4.attr

//## begin CCOL_TRN_TriListGen::iSecsPerCol%3B5DEE8D0334.attr preserve=no  private: static int {UA} 0
int CCOL_TRN_TriListGen::iSecsPerCol = 0;
//## end CCOL_TRN_TriListGen::iSecsPerCol%3B5DEE8D0334.attr

//## begin CCOL_TRN_TriListGen::iSectorRes%3B5DF2670046.attr preserve=no  private: static int {UA} 0
int CCOL_TRN_TriListGen::iSectorRes = 0;
//## end CCOL_TRN_TriListGen::iSectorRes%3B5DF2670046.attr

//## begin CCOL_TRN_TriListGen::fRatio%3B5DF2C20320.attr preserve=no  private: static float {UA} 0
float CCOL_TRN_TriListGen::fRatio = 0;
//## end CCOL_TRN_TriListGen::fRatio%3B5DF2C20320.attr

//## begin CCOL_TRN_TriListGen::iTWidth%3C0C1061030F.attr preserve=no  private: static int {UA} 0
int CCOL_TRN_TriListGen::iTWidth = 0;
//## end CCOL_TRN_TriListGen::iTWidth%3C0C1061030F.attr

//## begin CCOL_TRN_TriListGen::iTHeight%3C0C106C02C5.attr preserve=no  private: static int {UA} 0
int CCOL_TRN_TriListGen::iTHeight = 0;
//## end CCOL_TRN_TriListGen::iTHeight%3C0C106C02C5.attr

//## begin CCOL_TRN_TriListGen::fInvRatio%3C0D6F1C00A7.attr preserve=no  private: static float {UA} 0
float CCOL_TRN_TriListGen::fInvRatio = 0;
//## end CCOL_TRN_TriListGen::fInvRatio%3C0D6F1C00A7.attr

CCOL_TRN_TriListGen::CCOL_TRN_TriListGen()
  //## begin CCOL_TRN_TriListGen::CCOL_TRN_TriListGen%.hasinit preserve=no
  //## end CCOL_TRN_TriListGen::CCOL_TRN_TriListGen%.hasinit
  //## begin CCOL_TRN_TriListGen::CCOL_TRN_TriListGen%.initialization preserve=yes
  //## end CCOL_TRN_TriListGen::CCOL_TRN_TriListGen%.initialization
{
  //## begin CCOL_TRN_TriListGen::CCOL_TRN_TriListGen%.body preserve=yes
  //## end CCOL_TRN_TriListGen::CCOL_TRN_TriListGen%.body
}


CCOL_TRN_TriListGen::~CCOL_TRN_TriListGen()
{
  //## begin CCOL_TRN_TriListGen::~CCOL_TRN_TriListGen%.body preserve=yes
  //## end CCOL_TRN_TriListGen::~CCOL_TRN_TriListGen%.body
}



//## Other Operations (implementation)
float CCOL_TRN_TriListGen::GetHeight (float fX, float fY)
{
  //## begin CCOL_TRN_TriListGen::GetHeight%996008335.body preserve=yes
	int iX  = fX * fRatio;
	int iY  = fY * fRatio;

	if (iX<=0) iX = 0;
	if (iX >= iSectorRes*iSecsPerRow-1) iX = iSectorRes*iSecsPerRow-2;

	if (iY<=0) iY = 0;
	if (iY >= iSectorRes*iSecsPerCol-1) iY = iSectorRes*iSecsPerCol-2;

	float	fU,fV;

	fU = fX - (int)fX;
	fV = fY - (int)fY;
	
	float fA    = GetHeight(iX  ,iY  );
	float fB    = GetHeight(iX+1,iY  );
	float fC    = GetHeight(iX  ,iY+1);
	float fD    = GetHeight(iX+1,iY+1);
	float fRes1 = fA + (fB-fA)*fU;
	float fRes2 = fC + (fD-fC)*fU;
	
	return ( fRes1 + (fRes2-fRes1)*fV );
	
  //## end CCOL_TRN_TriListGen::GetHeight%996008335.body
}

float CCOL_TRN_TriListGen::GetHeight (int iX, int iY)
{
  //## begin CCOL_TRN_TriListGen::GetHeight%996008338.body preserve=yes
	int		iXSect = iX / iSectorRes;
	int		iYSect = iY / iSectorRes;
	
	iX %= iSectorRes;
	iY %= iSectorRes;

	// CHeight a = (CHeight)HFs[iYSect*iSecsPerRow+iXSect].GetValue(iX,iY);
	CSectElem &a = HFs[iYSect*iSecsPerRow+iXSect]->GetValue(iX,iY);
	float	*pfa = (float *)a.Get();
	
	return(*pfa);
  //## end CCOL_TRN_TriListGen::GetHeight%996008338.body
}

void CCOL_TRN_TriListGen::Init (int _iSecsPerRow, int _iSecsPerCol, int _iSectorRes, float _fSectorSize)
{
  //## begin CCOL_TRN_TriListGen::Init%996008336.body preserve=yes
	iSecsPerRow = _iSecsPerRow;
	iSecsPerCol = _iSecsPerCol;
	iSectorRes  = _iSectorRes;
	fSectorSize = _fSectorSize;
	fRatio      = (float)iSectorRes/fSectorSize;
	fInvRatio   = 1.0f / fRatio;
	iTWidth		= _iSecsPerRow*_iSectorRes-2;
	iTHeight	= _iSecsPerCol*_iSectorRes-2;

	HFs = mNew CHFSector *[iSecsPerRow*iSecsPerCol];
  //## end CCOL_TRN_TriListGen::Init%996008336.body
}

void CCOL_TRN_TriListGen::SetSector (int iSect, CHFSector *HFSect)
{
  //## begin CCOL_TRN_TriListGen::SetSector%996008337.body preserve=yes
	assert (HFs && "Object not initialized");
	HFs[iSect] = HFSect;
  //## end CCOL_TRN_TriListGen::SetSector%996008337.body
}

int CCOL_TRN_TriListGen::GetTriList (CCOL_TriList& _roTriList, CVect3& _roPos, float _fRadius)
{
  //## begin CCOL_TRN_TriListGen::GetTriList%1008463030.body preserve=yes
	if (! _roTriList.iFreeTris()) return(0);

	int iSteps = fRatio*_fRadius;		
	float fSqRadius = _SQ_(_fRadius);

	int iX     = _roPos.X()*fRatio - iSteps;
	int iY     = _roPos.Y()*fRatio - iSteps;
	int fX	   = _roPos.X()*fRatio + iSteps;
	int fY	   = _roPos.Y()*fRatio + iSteps;
	
	// Out of terrain bounds?
	if (iX<0)		 return(0);
	if (iY<0)		 return(0);
	if (fX>iTWidth ) return(0);
	if (fY>iTHeight) return(0);
	
	CTriangle	Tri;
	int			cI,cJ;
	int			iNumTris;	
	float		fXIni,fYIni;
	float		fXEnd,fYEnd;
	float		fH[4];
	CVect3		VXs[3];
	CVect3		VN;
	
	// Clamp
	if (iX<0)		 iX=0;
	if (iY<0)		 iY=0;
	if (fX>iTWidth ) iY=iTWidth;
	if (fY>iTHeight) iY=iTHeight;
	

	if (! iSteps)
	{
		// Only 2 triangles ?
		if (_roTriList.iFreeTris() < 2) return(0);
		
		iNumTris = 0;

		fYIni = iY*fInvRatio;
		fYEnd = fYIni + fInvRatio;

		fXIni = iX*fInvRatio;
		fXEnd = fXIni + fInvRatio;		

		fH[0] = GetHeight(iX  ,iY  );
		fH[1] = GetHeight(iX+1,iY  );
		fH[2] = GetHeight(iX  ,iY+1);
		fH[3] = GetHeight(iX+1,iY+1);
	
		// First tri
		VXs[0].V3(fXIni,fYIni,fH[0]);
		VXs[1].V3(fXEnd,fYIni,fH[1]);
		VXs[2].V3(fXIni,fYEnd,fH[2]);
		TEST_Triangle(VXs,-1,iNumTris,_roTriList,_roPos,fSqRadius);		

		// Second tri
		VXs[0].V3(fXEnd,fYIni,fH[1]);
		VXs[1].V3(fXEnd,fYEnd,fH[3]);
		VXs[2].V3(fXIni,fYEnd,fH[2]);		
		TEST_Triangle(VXs,-1,iNumTris,_roTriList,_roPos,fSqRadius);

		return(iNumTris);
	}	
	else
	{	
		// Control vertex buffer capacity
		if (_roTriList.iFreeTris() < (fY-iY)*(fX-iX) ) return(0);

		// Generate triangle list	
		iNumTris = 0;
		fYIni    = iY*fInvRatio;
		fYEnd    = fYIni + fInvRatio;

		for (cJ=iY;cJ<fY;cJ++)
		{
			fXIni = iX*fInvRatio;
			fXEnd = fXIni + fInvRatio;		

			for (cI=iX;cI<fX;cI++)
			{
				fH[0] = GetHeight(cI  ,cJ  );
				fH[1] = GetHeight(cI+1,cJ  );
				fH[2] = GetHeight(cI  ,cJ+1);
				fH[3] = GetHeight(cI+1,cJ+1);
				
				// First tri
				VXs[0].V3(fXIni,fYIni,fH[0]);
				VXs[1].V3(fXEnd,fYIni,fH[1]);
				VXs[2].V3(fXIni,fYEnd,fH[2]);
				TEST_Triangle(VXs,-1,iNumTris,_roTriList,_roPos,fSqRadius);

							
				// Second tri
				VXs[0].V3(fXEnd,fYIni,fH[1]);
				VXs[1].V3(fXEnd,fYEnd,fH[3]);
				VXs[2].V3(fXIni,fYEnd,fH[2]);	
				
				TEST_Triangle(VXs,-1,iNumTris,_roTriList,_roPos,fSqRadius);

				// Next coordinates
				fXIni	+= fInvRatio;
				fXEnd	+= fInvRatio;
			}

			fYIni += fInvRatio;
			fYEnd += fInvRatio;
		}

		return(iNumTris);
	}
  //## end CCOL_TRN_TriListGen::GetTriList%1008463030.body
}

int CCOL_TRN_TriListGen::GetTrisFromMesh (CCOL_TriList& _roTriList, CMesh* _poMesh, int _iMat, CVect3& _roPos, float _fRadius)
{
  //## begin CCOL_TRN_TriListGen::GetTrisFromMesh%1008711904.body preserve=yes
	return( GetTriList(_roTriList,_roPos,_fRadius) );
  //## end CCOL_TRN_TriListGen::GetTrisFromMesh%1008711904.body
}

// Additional Declarations
  //## begin CCOL_TRN_TriListGen%3B5DED78033E.declarations preserve=yes
  //## end CCOL_TRN_TriListGen%3B5DED78033E.declarations

//## begin module%3B5DED78033E.epilog preserve=yes
//## end module%3B5DED78033E.epilog
