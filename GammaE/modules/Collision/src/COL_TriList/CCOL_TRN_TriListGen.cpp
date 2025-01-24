// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------

// CCOL_TRN_TriListGen
#include "COL_TriList\CCOL_TRN_TriListGen.h"

inline void TEST_Triangle(CVect3* _poVXs,int _iMat,int &_iTris,CCOL_TriList& _oTriList,CVect3 &_oPos,float _fSqrRadius)
{
    _oTriList.iAddTri(_poVXs,_poVXs[0],_iMat,0.0f);
    _iTris++;
    return;

    /*
       CTriangle	oTri;
       CVect3		oNorm;
       float		fSqrDist;

       oTri.Init(_poVXs);
       oTri.Normal.Normalize();
       oTri.ComputeAll();

       fSqrDist = MATH_Utils::fTriPointSqDistance(oTri,_oPos);
       if ( fSqrDist < _fSqrRadius )
       {
        _oTriList.iAddTri(oTri.VXs,oTri.Normal,_iMat,0.0f);
        _iTris ++;
       }
     */
}

// Class CCOL_TRN_TriListGen

float CCOL_TRN_TriListGen::fSectorSize;

CHFSector* * CCOL_TRN_TriListGen::HFs = NULL;

int CCOL_TRN_TriListGen::iSecsPerRow = 0;

int CCOL_TRN_TriListGen::iSecsPerCol = 0;

int CCOL_TRN_TriListGen::iSectorRes = 0;

float CCOL_TRN_TriListGen::fRatio = 0;

int CCOL_TRN_TriListGen::iTWidth = 0;

int CCOL_TRN_TriListGen::iTHeight = 0;

float CCOL_TRN_TriListGen::fInvRatio = 0;

CCOL_TRN_TriListGen::CCOL_TRN_TriListGen()
{
}

CCOL_TRN_TriListGen::~CCOL_TRN_TriListGen()
{
}

float CCOL_TRN_TriListGen::GetHeight (float fX, float fY)
{
    int iX = fX * fRatio;
    int iY = fY * fRatio;

    if ( iX <= 0 ) iX = 0;
    if ( iX >= iSectorRes * iSecsPerRow - 1 ) iX = iSectorRes * iSecsPerRow - 2;

    if ( iY <= 0 ) iY = 0;
    if ( iY >= iSectorRes * iSecsPerCol - 1 ) iY = iSectorRes * iSecsPerCol - 2;

    float fU,fV;

    fU = fX - (int)fX;
    fV = fY - (int)fY;

    float fA = GetHeight(iX,iY  );
    float fB = GetHeight(iX + 1,iY  );
    float fC = GetHeight(iX,iY + 1);
    float fD = GetHeight(iX + 1,iY + 1);
    float fRes1 = fA + (fB - fA) * fU;
    float fRes2 = fC + (fD - fC) * fU;

    return (fRes1 + (fRes2 - fRes1) * fV);
}

float CCOL_TRN_TriListGen::GetHeight (int iX, int iY)
{
    int iXSect = iX / iSectorRes;
    int iYSect = iY / iSectorRes;

    iX %= iSectorRes;
    iY %= iSectorRes;

    // CHeight a = (CHeight)HFs[iYSect*iSecsPerRow+iXSect].GetValue(iX,iY);
    CSectElem &a = HFs[iYSect * iSecsPerRow + iXSect]->GetValue(iX,iY);
    float* pfa = (float*)a.Get();

    return(*pfa);
}

void CCOL_TRN_TriListGen::Init (int _iSecsPerRow, int _iSecsPerCol, int _iSectorRes, float _fSectorSize)
{
    iSecsPerRow = _iSecsPerRow;
    iSecsPerCol = _iSecsPerCol;
    iSectorRes = _iSectorRes;
    fSectorSize = _fSectorSize;
    fRatio = (float)iSectorRes / fSectorSize;
    fInvRatio = 1.0f / fRatio;
    iTWidth = _iSecsPerRow * _iSectorRes - 2;
    iTHeight = _iSecsPerCol * _iSectorRes - 2;

    HFs = mNew CHFSector *[iSecsPerRow * iSecsPerCol];
}

void CCOL_TRN_TriListGen::SetSector (int iSect, CHFSector* HFSect)
{
    assert (HFs && "Object not initialized");
    HFs[iSect] = HFSect;
}

int CCOL_TRN_TriListGen::GetTriList (CCOL_TriList& _oTriList, CVect3& _oPos, float _fRadius)
{
    if ( !_oTriList.iFreeTris() ) return(0);

    int iSteps = fRatio * _fRadius;
    float fSqRadius = _SQ_(_fRadius);

    int iX = _oPos.x * fRatio - iSteps;
    int iY = _oPos.y * fRatio - iSteps;
    int fX = _oPos.x * fRatio + iSteps;
    int fY = _oPos.y * fRatio + iSteps;

    // Out of terrain bounds?
    if ( iX < 0 ) return(0);
    if ( iY < 0 ) return(0);
    if ( fX > iTWidth ) return(0);
    if ( fY > iTHeight ) return(0);

    CTriangle Tri;
    int cI,cJ;
    int iNumTris;
    float fXIni,fYIni;
    float fXEnd,fYEnd;
    float fH[4];
    CVect3 VXs[3];
    CVect3 VN;

    // Clamp
    if ( iX < 0 ) iX = 0;
    if ( iY < 0 ) iY = 0;
    if ( fX > iTWidth ) iY = iTWidth;
    if ( fY > iTHeight ) iY = iTHeight;

    if ( !iSteps )
    {
        // Only 2 triangles ?
        if ( _oTriList.iFreeTris() < 2 ) return(0);

        iNumTris = 0;

        fYIni = iY * fInvRatio;
        fYEnd = fYIni + fInvRatio;

        fXIni = iX * fInvRatio;
        fXEnd = fXIni + fInvRatio;

        fH[0] = GetHeight(iX,iY  );
        fH[1] = GetHeight(iX + 1,iY  );
        fH[2] = GetHeight(iX,iY + 1);
        fH[3] = GetHeight(iX + 1,iY + 1);

        // First tri
        VXs[0].V3(fXIni,fYIni,fH[0]);
        VXs[1].V3(fXEnd,fYIni,fH[1]);
        VXs[2].V3(fXIni,fYEnd,fH[2]);
        TEST_Triangle(VXs,-1,iNumTris,_oTriList,_oPos,fSqRadius);

        // Second tri
        VXs[0].V3(fXEnd,fYIni,fH[1]);
        VXs[1].V3(fXEnd,fYEnd,fH[3]);
        VXs[2].V3(fXIni,fYEnd,fH[2]);
        TEST_Triangle(VXs,-1,iNumTris,_oTriList,_oPos,fSqRadius);

        return(iNumTris);
    }
    else
    {
        // Control vertex buffer capacity
        if ( _oTriList.iFreeTris() < (fY - iY) * (fX - iX) ) return(0);

        // Generate triangle list
        iNumTris = 0;
        fYIni = iY * fInvRatio;
        fYEnd = fYIni + fInvRatio;

        for ( cJ = iY; cJ < fY; cJ++ )
        {
            fXIni = iX * fInvRatio;
            fXEnd = fXIni + fInvRatio;

            for ( cI = iX; cI < fX; cI++ )
            {
                fH[0] = GetHeight(cI,cJ  );
                fH[1] = GetHeight(cI + 1,cJ  );
                fH[2] = GetHeight(cI,cJ + 1);
                fH[3] = GetHeight(cI + 1,cJ + 1);

                // First tri
                VXs[0].V3(fXIni,fYIni,fH[0]);
                VXs[1].V3(fXEnd,fYIni,fH[1]);
                VXs[2].V3(fXIni,fYEnd,fH[2]);
                TEST_Triangle(VXs,-1,iNumTris,_oTriList,_oPos,fSqRadius);

                // Second tri
                VXs[0].V3(fXEnd,fYIni,fH[1]);
                VXs[1].V3(fXEnd,fYEnd,fH[3]);
                VXs[2].V3(fXIni,fYEnd,fH[2]);

                TEST_Triangle(VXs,-1,iNumTris,_oTriList,_oPos,fSqRadius);

                // Next coordinates
                fXIni += fInvRatio;
                fXEnd += fInvRatio;
            }

            fYIni += fInvRatio;
            fYEnd += fInvRatio;
        }

        return(iNumTris);
    }
}

int CCOL_TRN_TriListGen::GetTrisFromMesh (CCOL_TriList& _oTriList, CGMesh* _poMesh, int _iMat, CVect3& _oPos, float _fRadius)
{
    return( GetTriList(_oTriList,_oPos,_fRadius) );
}

// Additional Declarations
