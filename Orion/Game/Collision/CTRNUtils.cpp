#include "CTRNUtils.h"
#include "Game/GameGlobals/GameGlobals.h"
/********************************************************************

********************************************************************/
float	fRatio;
float	fStepX,fStepY,fStepZ;
float	fCircTX,fCircTY;
float	fMinH,fMaxH;
CVect3  oAct;
/********************************************************************

********************************************************************/
inline int iClampMax(int _iValue,int _iMax)
{
	if (_iValue<0) 
		return(0);
	else if (_iValue>_iMax) 
		return(_iMax);
	else
		return(_iValue);
}

inline bool bInRange(float _fMin,float _fMax,float _fValue)
{
	return((_fValue>=_fMin) && (_fValue<=_fMax));
}

/*
inline bool bInRange(int _iMin,int _iMax,int _iValue)
{
	return((_iValue>=_iMin) && (_iValue<=_iMax));
}
*/
/********************************************************************

********************************************************************/

void CTRNUtils::Init()
{
	fRatio = (float)goTL.iSectorRes / goTL.fSectorSize;

	fCircTX = goTL.HF->iGetSecsPerRow() * goTL.iSectorRes;
	fCircTY = goTL.HF->iGetSecsPerCol() * goTL.iSectorRes;
    fMinH   = goTL.HF->GetMinHeight();
    fMaxH   = goTL.HF->GetMinHeight();

	float fRho = goTL.EnvPars.fLightRhoAngle;
	float fPhi = goTL.EnvPars.fLightPhiAngle;

	/* ----------------------------------------------
           /|
          / |StepY
         /  |                | StepY
        /¬__|         /¬_____|
        StepX            StepX
    ---------------------------------------------- */
    fStepX =      cos(fRho)*cos(fPhi);
    fStepY = -1 * cos(fRho)*sin(fPhi);
    fStepZ =      sin(fRho);

	#define fAbs MATH_Common::fAbs
	#define fSgn MATH_Common::fSign

	if (fAbs(fStepX) > fAbs(fStepY))
    {
        fStepY = fSgn(fStepY) * (fAbs(fStepY) / fAbs(fStepX));
        fStepZ = fSgn(fStepZ) * (fAbs(fStepZ) / fAbs(fStepX));
        fStepX = fSgn(fStepX);
    }
    else
    {
        fStepX = fSgn(fStepX) * (fAbs(fStepX) / fAbs(fStepY));
        fStepZ = fSgn(fStepZ) * (fAbs(fStepZ) / fAbs(fStepY));
        fStepY = fSgn(fStepY);
    }

    if (fRho <=0) fStepZ = 0.0f;
}
//--------------------------------------------------------------------
float CTRNUtils::fGetHeight(CVect3 &_roPos)
{
	float fRatio = (float)goTL.iSectorRes / goTL.fSectorSize;
	return ( *( (float *)goTL.HF->GetValueF(_roPos.X()*fRatio,_roPos.Y()*fRatio).Get() ));
}
//--------------------------------------------------------------------
float CTRNUtils::fGetHeight(float _fX,float _fY)
{
	float fRatio = (float)goTL.iSectorRes / goTL.fSectorSize;
	return ( *( (float *)goTL.HF->GetValueF(_fX*fRatio,_fY*fRatio).Get() ));
}
//--------------------------------------------------------------------
int CTRNUtils::iGetSector(CVect3 &_roPos,int &_riXSect,int &_riYSect)
{
	_riXSect = iClampMax(_roPos.X() / goTL.fSectorSize,goTL.HF->iGetSecsPerRow()-1);
	_riYSect = iClampMax(_roPos.Y() / goTL.fSectorSize,goTL.HF->iGetSecsPerCol()-1);

	return( _riYSect*goTL.HF->iGetSecsPerRow() + _riXSect );
}
//--------------------------------------------------------------------
int CTRNUtils::iGetSector(float _fX,float _fY,int &_riXSect,int &_riYSect)
{
	_riXSect = iClampMax(_fX / goTL.fSectorSize,goTL.HF->iGetSecsPerRow()-1);
	_riYSect = iClampMax(_fY / goTL.fSectorSize,goTL.HF->iGetSecsPerCol()-1);

	return( _riYSect*goTL.HF->iGetSecsPerRow() + _riXSect );
}
//--------------------------------------------------------------------
bool CTRNUtils::bSunArrivesToPoint(CVect3 &_roPos)
{
	#define fGetHeight(x,y) *((float *)goTL.HF->GetValueF(x,y).Get())

	float cx,cy,cz;	
    float fActX,fActY,fActZ,fZValue;
    bool  bLightCollisions;
	    
	cx = _roPos.X() * fRatio;
	cy = _roPos.Y() * fRatio;
	cz = fGetHeight(cx,cy);

    bLightCollisions = false;

	fActX   = cx + fStepX;
    fActY   = cy + fStepY;
    fActZ   = cz + fStepZ;

    while ((! bLightCollisions) &&
           (bInRange(0.0f,fCircTX, fActX)) &&
           (bInRange(0.0f,fCircTY, fActY)) &&
           (bInRange(fMinH,fMaxH,  fActZ)))
    {
        fZValue = fGetHeight(fActX,fActY);
        bLightCollisions = (fZValue >= fActZ);

        fActX += fStepX;
        fActY += fStepY;
        fActZ += fStepZ;
    }
	
	oAct.V3(fActX,fActY,fActZ);
    return(! bLightCollisions);
}

bool CTRNUtils::bIntersect(CVect3 &_roPos,CVect3 &_roPoint)
{
	// Invert ray direction
	fStepX *= -1.0f;
	fStepY *= -1.0f;
	fStepZ *= -1.0f;

	bool bRes = bSunArrivesToPoint(_roPos);
	
	if (bRes)
		_roPoint.Assign(oAct);

	// Restore
	fStepX *= -1.0f;
	fStepY *= -1.0f;
	fStepZ *= -1.0f;
	
	return(bRes);
}
//--------------------------------------------------------------------