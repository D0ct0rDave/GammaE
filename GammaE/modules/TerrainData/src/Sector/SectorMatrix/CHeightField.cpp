#include "GammaE_Mem.h"

// CHeightField
#include "Sector\SectorMatrix\CHeightField.h"
inline int iClamp(int _iValue,int _iMax,int _iMin)
{
    if ( _iValue < _iMin ) return(_iMin);
    else if ( _iValue > _iMax ) return(_iMax);
    else return(_iValue);
}

inline int iClampMax(int _iValue,int _iMax)
{
    if ( _iValue < 0 )
        return(0);
    else if ( _iValue > _iMax )
        return(_iMax);
    else
        return(_iValue);
}

// Class CHeightField

CHeightField::CHeightField()
    : bRecomputeMaxMins(false)
{
    ulID = MAKE_RIFF_ID('H','F','L','D');
    pData = (void*)&HFData;
    poSectManager = mNew CSLM_HFieldSect();
}

CHeightField::~CHeightField()
{
    pData = NULL;
    mDel poSectManager;
}

CSector* CHeightField::CreateClass ()
{
    return ( mNew CHeightField() );
}

void CHeightField::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
    int cSect;

    CSectorMatrix::Init(_SecsPerRow,_SecsPerCol,_SectorRes,_SectorType,_b21);

    // Create sector
    switch ( _SectorType )
    {
        case 0: for ( cSect = 0; cSect < SecsPerCol * SecsPerRow; cSect++ )
        {
            SectArray[cSect] = mNew CHFSector_FN();
            SectArray[cSect]->Init(_SectorRes,_b21);
        }
        break;
    }

    // Create each sector object
}

unsigned long CHeightField::DataSize ()
{
    return( sizeof(THeightFieldData) );
}

float CHeightField::GetMaxHeight ()
{
    if ( bRecomputeMaxMins ) RecomputeMaxMins();
    return (HFData.fMaxHeight);
}

float CHeightField::GetMinHeight ()
{
    if ( bRecomputeMaxMins ) RecomputeMaxMins();

    return (HFData.fMinHeight);
}

void CHeightField::SetValue (int _X, int _Y, CSectElem &_Value)
{
    bRecomputeMaxMins = true;
    CSectorMatrix::SetValue(_X,_Y,_Value);
}

void CHeightField::SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value)
{
    bRecomputeMaxMins = true;
    CSectorMatrix::SetValueFromSect(_iSect,_X,_Y,_Value);
}

void CHeightField::RecomputeMaxMins ()
{
    unsigned int cSect;
    float fCurrentMax,fCurrentMin;

    HFData.fMaxHeight = -1.0E09f;
    HFData.fMinHeight = 1.0E09f;

    for ( cSect = 0; cSect < SecsPerRow * SecsPerCol; cSect++ )
    {
        fCurrentMax = ( (CHFSector*)SectArray[cSect] )->GetMaxHeight();
        fCurrentMin = ( (CHFSector*)SectArray[cSect] )->GetMinHeight();

        if ( fCurrentMax > HFData.fMaxHeight ) HFData.fMaxHeight = fCurrentMax;
        if ( fCurrentMin < HFData.fMinHeight ) HFData.fMinHeight = fCurrentMin;
    }

    bRecomputeMaxMins = false;
}

CSector* CHeightField::GenerateLOD (int _iLOD)
{
    CHeightField* HF = (CHeightField*)CSectorMatrix::GenerateLOD(_iLOD);
    HF->RecomputeMaxMins();

    return (HF);
}

CSectElem & CHeightField::GetValueF (float _fX, float _fY)
{
    if ( VGenMethod == eGM_Nearest ) return ( GetValue( (int)_fX,(int)_fY ) );
    float f1overLast = 1.0f / iLast;
    int iSectX = iClampMax(_fX * f1overLast,SecsPerRow - 1);
    int iSectY = iClampMax(_fY * f1overLast,SecsPerCol - 1);

    _fX -= iSectX * iLast;
    _fY -= iSectY * iLast;

    return ( GetSector(iSectX,iSectY)->GetValueF(_fX,_fY) );
}

// Additional Declarations
