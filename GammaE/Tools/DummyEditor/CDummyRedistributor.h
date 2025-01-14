//---------------------------------------------------------------------------
#ifndef CDummyRedistributorH
#define CDummyRedistributorH
//---------------------------------------------------------------------------
#include "TerrPrj.h"
#include "CDummyList.h"
//---------------------------------------------------------------------------
class CDummyRedistributor
{
    public:
            int Redistribute(TCircuit *_poCircuit,float _fRatio,CDummyList *_poDList);
            float fRand(int _iFunction,float _fX,float _fY);
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
 