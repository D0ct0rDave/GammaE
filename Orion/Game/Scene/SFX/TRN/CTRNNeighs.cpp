#include "CTRNNeighs.h"
#include "Game/GameGlobals/GameGlobals.h"

CMesh CTRNNeighs::goNGMesh;

#define		uiMaxRes	100
#define		_ZOFS_		0.1f

inline unsigned int uiStripSize(unsigned int _uiXRes,unsigned int _uiYRes)
{
	return ( (2*_uiXRes+2)*(_uiYRes-1) );
}
/******************************************************************************

******************************************************************************/
inline int iClamp(int _iMin,int _iMax,int _iValue)
{
	if (_iValue<_iMin) return(_iMin);
	if (_iValue>_iMax) return(_iMax);
	return(_iValue);
}

/******************************************************************************

******************************************************************************/
CMesh *CTRNNeighs::GetNeighs(CVect3 &_roPos,float _fRadius)
{
	if (goNGMesh.usNumPrims == 0)
	{
		// Create mesh
		unsigned int uiNumVXs = uiStripSize(100,100);
		goNGMesh.Init(uiNumVXs,uiNumVXs -2,E3D_MESH_NITRISTRIP,MESH_FIELD_VERTEXS);
	}

	float	fH[10000];		// 100*4   = 400 meters
							// 100*2   = 200 meters
							// 100*1   = 100 meters
							// 100*0.5 = 50  meters
	float	*pfH = fH;
	int     iSteps		= _fRadius*goTL.fIScale;		// total meters / meters per pixel
	int		cI,cJ;
	int		iXIni,iYIni,iXEnd,iYEnd;
	float	fXIni,fYIni,fXEnd,fYEnd;	
	
	// Clamp
	iXIni = iClamp(0,goTL.iCircXRes-1,_roPos.X()*goTL.fIScale - iSteps);
	iYIni = iClamp(0,goTL.iCircYRes-1,_roPos.Y()*goTL.fIScale - iSteps);
	iXEnd = iClamp(0,goTL.iCircXRes-1,_roPos.X()*goTL.fIScale + iSteps);
	iYEnd = iClamp(0,goTL.iCircYRes-1,_roPos.Y()*goTL.fIScale + iSteps);

	// Fill Height array
	for (cJ=iYIni;cJ<=iYEnd;cJ++)
		for (cI=iXIni;cI<=iXEnd;cI++)
			   *pfH++ = *((float*)(goTL.HF->GetValue(cI,cJ).Get())) + _ZOFS_;

	BuildMesh(fH,
   			  iXEnd-iXIni+1,
			  iYEnd-iYIni+1,
			  iXIni*goTL.fXYScale,
	  		  iYIni*goTL.fXYScale);

	return( &goNGMesh );
}
/******************************************************************************

******************************************************************************/
void CTRNNeighs::BuildMesh(float *_pfHF,unsigned int _uiTX,unsigned int _uiTY,float _fOfsX,float _fOfsY)
{
	int		cI,cJ;
	float	fX,fY1,fY2;

	CVect3	*poVX = goNGMesh.VXs;
	float   fStep = goTL.EnvPars.fXYScale;
	float	*pfH1 = _pfHF;
	float	*pfH2 = _pfHF + _uiTX;
	
	fY1 = _fOfsY;
	fY2 = _fOfsY + fStep;
	_uiTY--;	// 1 iteration less since, we use 2 rows per horizontal loop

	for (cJ=0;cJ<_uiTY;cJ++)
	{
		fX = _fOfsX;

		poVX->V3(fX,fY1,*pfH1);				poVX++;		// Next

		for (cI=0;cI<_uiTX;cI++)
		{
			poVX->V3(fX,fY1,*pfH1);			poVX++;		// Next
			poVX->V3(fX,fY2,*pfH2);			poVX++;		// Next

			fX += fStep;			
			pfH1++;
			pfH2++;
		}

		poVX->V3(fX-fStep,fY2,pfH2[-1]);	poVX++;		// Next

		fY1 += fStep;
		fY2 += fStep;
	}

	goNGMesh.usNumVerts = uiStripSize(_uiTX,_uiTY);
	goNGMesh.usNumPrims = goNGMesh.usNumVerts-2;
}
/******************************************************************************

******************************************************************************/
