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
// %X% %Q% %Z% %W%

// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_MT_TerrainMesh
#include "COL_Testers\COL_SceneTest\COL_MeshTest\CCOL_MT_TerrainMesh.h"

// Class CCOL_MT_TerrainMesh

CCOL_MT_TerrainMesh::CCOL_MT_TerrainMesh()
    : HF(NULL), iSectorRes(0), fRatio(0), iTWidth(0), iTHeight(0), fInvRatio(0)
{
}

int CCOL_MT_TerrainMesh::iTestCollision(CGMesh* _poMesh, int _iMat, CGGraphBV* _poBVol, CCOL_TriList& _oTriList)
{
    // Convertir coordinadas SrcIPos, SrcFPos a coordenadas de terreno
    // Trazar el recorrido del objeto sobre el terreno, pixel a pixel.

    // Para cada coordenada (bresenhan line) obtener el par de tri�ngulos apropiado
    // y testear colision del objeto con ese par de tri�ngulos.

    // si hay colision, a�adir a la lista (y retornar ?)
    // si no hay colision, continuar trazando hasta llegar al l�mite.

    // (limite de sector si puede ser).
    CGTriangle Tri;
    CGVect3 VXs[2048];
    CGVect3 Normal;
    CGVect3 Pos;
    int iNumTris;

    int iIX,iIY,iFX,iFY,iXRange,iYRange,iSteps,iS;
    float fXStep,fYStep,fZStep,fActX,fActY,fActZ;
    float fHeight,fHalfZObj;
    float fColTime;

    iIX = CCOL_ColState::SrcIPos.x * fRatio;
    iIY = CCOL_ColState::SrcIPos.y * fRatio;
    iFX = CCOL_ColState::SrcFPos.x * fRatio;
    iFY = CCOL_ColState::SrcFPos.y * fRatio;

    iXRange = iFX - iIX;
    iYRange = iFY - iIY;

    if ( Math::fAbs(iXRange) == Math::fAbs(iYRange) )
    {
        iSteps = Math::fAbs(iXRange);
        fXStep = Math::fSign(iXRange);
        fYStep = Math::fSign(iYRange);
    }
    else
    {
        if ( Math::fAbs(iXRange) > Math::fAbs(iYRange) )
        {
            iSteps = Math::fAbs(iXRange);
            fXStep = Math::fSign(iXRange);
            fYStep = (float)iYRange / (float)iSteps;
        }
        else
        {
            iSteps = Math::fAbs(iYRange);
            fXStep = (float)iXRange / (float)iSteps;
            fYStep = Math::fSign(iYRange);
        }
    }

    if ( !iSteps )
        fZStep = 0.0f;
    else
        fZStep = (CCOL_ColState::SrcFPos.z - CCOL_ColState::SrcIPos.z) / (float)iSteps;

    // Loop throught all the traversed triangles
    fActX = iIX;
    fActY = iIY;
    fActZ = CCOL_ColState::SrcIPos.z;

    fHalfZObj = _poBVol->GetExtents().z;

    iNumTris = 0;

    for ( iS = 0; iS <= iSteps; iS++ )
    {
        if ( Math::bInRange(fActX,0,iTWidth ) &&
            Math::bInRange(fActY,0,iTHeight) )
        {
            // Get the triangles associated with the pixel
            GetTriangle(fActX,fActY,VXs);

            // Get position of collision
            Pos.Interpolate( CCOL_ColState::SrcIPos,
                            CCOL_ColState::SrcFPos,
                            (float)iS / (iSteps + 1) );

            // Test for collision with the first tri
            Tri.Init(VXs);
            Tri.ComputeAll();

            fColTime = CCOL_DT_ColTester::fTestTriangle(_poBVol,Tri);
            if ( fColTime >= 0.0f )
            {
                _oTriList.iAddTri(Tri.VXs,Tri.Normal,-1,fColTime);
                iNumTris++;
            }

            // Test for collision with the second tri
            Tri.Init(VXs + 3);
            Tri.ComputeAll();

            fColTime = CCOL_DT_ColTester::fTestTriangle(_poBVol,Tri);
            if ( fColTime >= 0.0f )
            {
                _oTriList.iAddTri(Tri.VXs,Tri.Normal,-1,fColTime);
                iNumTris++;
            }
        }

        fActX += fXStep;
        fActY += fYStep;
        fActZ += fZStep;
    }
    return (iNumTris);
    /*
       CGVect3		VXs[2048];
       CGVect3		Normal;
       CGTriangle	Tri;
       int			iNumTris,iTri;
       int			iSelTris;

       int		iIX,iIY,iFX,iFY,iXRange,iYRange,iSteps,iS,iRatio,iLevel;

       float	fXStep,fYStep,fActX,fActY;

       iIX = CCOL_ColState::SrcIPos.x*fRatio;
       iIY = CCOL_ColState::SrcIPos.y*fRatio;
       iFX = CCOL_ColState::SrcFPos.x*fRatio;
       iFY = CCOL_ColState::SrcFPos.y*fRatio;

       iXRange = iFX - iIX;
       iYRange = iFY - iIY;

       if (Math::fAbs(iXRange) == Math::fAbs(iYRange))
       {
        iSteps = 1;
        fXStep = Math::fSign(iXRange);
        fYStep = Math::fSign(iYRange);
       }
       else
       {
        if (Math::fAbs(iXRange) > Math::fAbs(iYRange))
        {
            iSteps = Math::fAbs(iXRange);
            fXStep = Math::fSign(iXRange);
            fYStep = (float)iYRange/(float)iSteps;
        }
        else
        {
            iSteps = Math::fAbs(iYRange);
            fXStep = (float)iXRange/(float)iSteps;
            fYStep = Math::fSign(iYRange);
        }
       }

       fZStep = (CCOL_ColState::SrcFPos.z - CCOL_ColState::SrcIPos.z) / (float)iSteps;

       // Loop throught all the traversed triangles
       fActX	 = iIX;
       fActY	 = iIY;

       iRatio   = _BVol->GetMaxExtent()*fRatio + 1.0f;
       for (iS=0;iS<=iSteps;iS++)
       {
        if (Math::bInRange(fActX,iRatio,iTWidth -iRatio) &&
            Math::bInRange(fActY,iRatio,iTHeight-iRatio))
        {
            // Get the triangles associated with the pixel

            /*
            for (iLevel=-iRatio;iLevel<=iRatio;iLevel++)
            {
                GetTriangle(fActX+iLevel,fActY+iLevel,VXs);

                Tri.Init(VXs);		Tri.ComputeAll();
                if (CCOL_DT_ColTester::iTestTriangle(_BVol,Tri))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
                    iNumTris++;
                    // return(1);
                }

                Tri.Init(VXs+3);		Tri.ComputeAll();
                if (CCOL_DT_ColTester::iTestTriangle(_BVol,Tri))
                {
                    _TriList.iAddTri(Tri.VXs,Tri.Normal);
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
            _TriList.iAddTri(Tri.VXs,Tri.Normal);
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
}

int CCOL_MT_TerrainMesh::iGetTriangles (int _iX, int _iY, int _iRad, CGVect3* _pVXs)
{
    int iIX,iFX;
    int iIY,iFY;
    int cI,cJ;

    iIX = _iX - _iRad;
    iFX = _iX + _iRad;
    iIY = _iY - _iRad;
    iFY = _iY + _iRad;

    for ( cJ = iIY; cJ <= iFY; cJ++ )
        for ( cI = iIX; cI <= iFX; cI++ )
        {
            GetTriangle(cI,cJ,_pVXs);
            _pVXs += 6;
        }

    return( 2 * (2 * _iRad + 1) * (2 * _iRad + 1) );
}

void CCOL_MT_TerrainMesh::GetTriangle (int _iX, int _iY, CGVect3* _pa6VXs)
{
    float fH[4];
    float fIX,fFX;
    float fIY,fFY;

    fH[0] = GetHeight(_iX,_iY  );
    fH[1] = GetHeight(_iX + 1,_iY  );
    fH[2] = GetHeight(_iX,_iY + 1);
    fH[3] = GetHeight(_iX + 1,_iY + 1);

    fIX = _iX * fInvRatio;
    fFX = fIX + fInvRatio;

    fIY = _iY * fInvRatio;
    fFY = fIY + fInvRatio;

    _pa6VXs[0].Set(fIX,fIY,fH[0]);
    _pa6VXs[1].Set(fIX,fFY,fH[2]);
    _pa6VXs[2].Set(fFX,fFY,fH[3]);

    _pa6VXs[3].Set(fIX,fIY,fH[0]);
    _pa6VXs[4].Set(fFX,fFY,fH[3]);
    _pa6VXs[5].Set(fFX,fIY,fH[1]);
}

float CCOL_MT_TerrainMesh::GetHeight (int iX, int iY)
{
    int iXSect = iX / iSectorRes;
    int iYSect = iY / iSectorRes;

    iX -= iXSect * iSectorRes;
    iY -= iYSect * iSectorRes;

    float* pfa = (float*) ( (CHFSector*)HF->GetSector(iXSect,iYSect) )->GetValue(iX,iY).Get();

    return(*pfa);
}

void CCOL_MT_TerrainMesh::Init (CHeightField* _pHF, int _iSectorRes, float _fSectorSize)
{
    HF = _pHF;

    iSectorRes = _iSectorRes;

    fRatio = (float)iSectorRes / _fSectorSize;
    fInvRatio = 1.0f / fRatio;

    iTWidth = HF->iGetSecsPerRow() * _iSectorRes - 2;
    iTHeight = HF->iGetSecsPerCol() * _iSectorRes - 2;
}

// Additional Declarations
