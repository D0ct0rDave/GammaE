//---------------------------------------------------------------------------
#ifdef USE_PRECOMPILED_HEADERS
    #include "DED_PrecompiledHeaders.h"
    #pragma hdrstop
#endif

#include <vcl.h>
//---------------------------------------------------------------------------
#include "CDummyRedistributor.h"
//---------------------------------------------------------------------------
#include "TerrainGeneration.h"
//---------------------------------------------------------------------------
float _fRand()
{
    return ((float)rand() / (float)RAND_MAX);
}

float CDummyRedistributor::fRand(int _iFunction,float _fX,float _fY)
{
    switch (_iFunction)
    {
        case 0: return ( _fRand() );
        case 1: return (PerlinNoise2(_fX,_fY)+0.5f);
    }
}

int CDummyRedistributor::Redistribute(TCircuit *_poCircuit,float _fRatio,CDummyList *_poDList)
{
    assert (_poCircuit && "NULL Circuit");
    assert (_poDList && "NULL Dummy Instance List");

    float           fCurX;
    float           fCurY;
    float           fValue;
    CDummyInstance  oDum;

    float fCircXSize = _fRatio * _poCircuit->GetCircuitXRes();
    float fCircYSize = _fRatio * _poCircuit->GetCircuitYRes();

    int  iDum;

    _poDList->DInsts.clear();
    for (iDum=0;iDum<_poDList->iIters;iDum++)
    {
        fCurX = _fRand()*fCircXSize;
        fCurY = _fRand()*fCircYSize;

        fValue = fRand(_poDList->iAlgType,_poDList->fScale*fCurX/fCircXSize,_poDList->fScale*fCurY/fCircYSize);

        if (fValue <= _poDList->fProb)
        {
            oDum.oPos.V3(fCurX,fCurY,_poCircuit->GetHeight(fCurX/_fRatio,fCurY/_fRatio));

            // Add instance to list
            _poDList->DInsts.push_back(oDum);
        }
    }
    /*
    _poDList->DInsts.clear();
    fCurY = _poDList->fDist;
    float fMaxProb = -20000.0f;
    while (fCurY + _poDList->fDist < fCircYSize)
    {
        fCurX  = _poDList->fDist;
        while (fCurX + _poDList->fDist < fCircXSize)
        {
            fValue = fRand(_poDList->iAlgType,fCurX/fCircXSize,fCurY/fCircYSize);

            if (fValue <= _poDList->fProb)
            {
                oDum.oPos.V3(fCurX,fCurY, _poCircuit->GetHeight(fCurX,fCurY));
                oDum.bHidden = false;

                // Add instance to list
                _poDList->DInsts.push_back(oDum);
            }

            if (fValue > fMaxProb)
                fMaxProb = fValue;

            fCurX += _poDList->fDist;
        }

        fCurY += _poDList->fDist;
    }
    */
    return (_poDList->DInsts.size() );
}
//---------------------------------------------------------------------------
