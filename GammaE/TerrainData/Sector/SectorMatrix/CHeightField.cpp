//## begin module%3AF9BE740014.cm preserve=no
//## end module%3AF9BE740014.cm

//## begin module%3AF9BE740014.cp preserve=no
//## end module%3AF9BE740014.cp

//## Module: CHeightField%3AF9BE740014; Pseudo Package body
//## Source file: i:\Projects\GammaE\TerrainData\Sector\SectorMatrix\CHeightField.cpp

//## begin module%3AF9BE740014.additionalIncludes preserve=no
//## end module%3AF9BE740014.additionalIncludes

//## begin module%3AF9BE740014.includes preserve=yes
//## end module%3AF9BE740014.includes

// CHeightField
#include "TerrainData\Sector\SectorMatrix\CHeightField.h"
//## begin module%3AF9BE740014.additionalDeclarations preserve=yes
inline int iClamp(int _iValue,int _iMax,int _iMin)
{
		 if (_iValue<_iMin) return(_iMin);
	else if (_iValue>_iMax) return(_iMax);
	else return(_iValue);
}

inline int iClampMax(int _iValue,int _iMax)
{
	if (_iValue<0) 
		return(0);
	else if (_iValue>_iMax) 
		return(_iMax);
	else
		return(_iValue);
}
//## end module%3AF9BE740014.additionalDeclarations


// Class CHeightField 



CHeightField::CHeightField()
  //## begin CHeightField::CHeightField%.hasinit preserve=no
      : bRecomputeMaxMins(false)
  //## end CHeightField::CHeightField%.hasinit
  //## begin CHeightField::CHeightField%.initialization preserve=yes
  //## end CHeightField::CHeightField%.initialization
{
  //## begin CHeightField::CHeightField%.body preserve=yes
   	ulID = MAKE_RIFF_ID('H','F','L','D');
	pData = (void *)&HFData;
	poSectManager = new  CSLM_HFieldSect();
  //## end CHeightField::CHeightField%.body
}


CHeightField::~CHeightField()
{
  //## begin CHeightField::~CHeightField%.body preserve=yes
  	pData = NULL;
	delete poSectManager;
  //## end CHeightField::~CHeightField%.body
}



//## Other Operations (implementation)
CSector * CHeightField::CreateClass ()
{
  //## begin CHeightField::CreateClass%989530853.body preserve=yes
	return ( new CHeightField() );
  //## end CHeightField::CreateClass%989530853.body
}

void CHeightField::Init (int _SecsPerRow, int _SecsPerCol, int _SectorRes, int _SectorType, bool _b21)
{
  //## begin CHeightField::Init%989530856.body preserve=yes
	int cSect;

	CSectorMatrix::Init(_SecsPerRow,_SecsPerCol,_SectorRes,_SectorType,_b21);

	// Create sector
	switch (_SectorType)
	{
		case 0:	for (cSect=0;cSect<SecsPerCol*SecsPerRow;cSect++)
				{
					SectArray[cSect] = new CHFSector_FN();
					SectArray[cSect]->Init(_SectorRes,_b21);
				}
				break;
	}

	// Create each sector object
  //## end CHeightField::Init%989530856.body
}

unsigned long CHeightField::DataSize ()
{
  //## begin CHeightField::DataSize%989530863.body preserve=yes
	return( sizeof(THeightFieldData) );
  //## end CHeightField::DataSize%989530863.body
}

float CHeightField::GetMaxHeight ()
{
  //## begin CHeightField::GetMaxHeight%990479649.body preserve=yes
	if (bRecomputeMaxMins) RecomputeMaxMins();
	return ( HFData.fMaxHeight );
  //## end CHeightField::GetMaxHeight%990479649.body
}

float CHeightField::GetMinHeight ()
{
  //## begin CHeightField::GetMinHeight%990479650.body preserve=yes
	if (bRecomputeMaxMins) RecomputeMaxMins();

	return ( HFData.fMinHeight );
  //## end CHeightField::GetMinHeight%990479650.body
}

void CHeightField::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CHeightField::SetValue%990479657.body preserve=yes
	bRecomputeMaxMins = true;
	CSectorMatrix::SetValue(_X,_Y,_Value);
  //## end CHeightField::SetValue%990479657.body
}

void CHeightField::SetValueFromSect (int _iSect, int _X, int _Y, CSectElem &_Value)
{
  //## begin CHeightField::SetValueFromSect%990479658.body preserve=yes
	bRecomputeMaxMins = true;
	CSectorMatrix::SetValueFromSect(_iSect,_X,_Y,_Value);
  //## end CHeightField::SetValueFromSect%990479658.body
}

void CHeightField::RecomputeMaxMins ()
{
  //## begin CHeightField::RecomputeMaxMins%990479659.body preserve=yes
	unsigned int cSect;
	float		 fCurrentMax,fCurrentMin;
	
	HFData.fMaxHeight = -1.0E09f;
	HFData.fMinHeight =  1.0E09f;

	for (cSect=0;cSect<SecsPerRow*SecsPerCol;cSect++)
	{
		fCurrentMax = ((CHFSector *)SectArray[cSect])->GetMaxHeight();
		fCurrentMin = ((CHFSector *)SectArray[cSect])->GetMinHeight();

		if (fCurrentMax > HFData.fMaxHeight) HFData.fMaxHeight = fCurrentMax;
		if (fCurrentMin < HFData.fMinHeight) HFData.fMinHeight = fCurrentMin;
	}

    bRecomputeMaxMins = false;
  //## end CHeightField::RecomputeMaxMins%990479659.body
}

CSector * CHeightField::GenerateLOD (int _iLOD)
{
  //## begin CHeightField::GenerateLOD%991345748.body preserve=yes
	CHeightField * HF = (CHeightField *)CSectorMatrix::GenerateLOD(_iLOD);
	HF->RecomputeMaxMins();

	return ( HF );
  //## end CHeightField::GenerateLOD%991345748.body
}

CSectElem & CHeightField::GetValueF (float _fX, float _fY)
{
  //## begin CHeightField::GetValueF%1026770435.body preserve=yes
	if (VGenMethod == eGM_Nearest) return ( GetValue((int)_fX,(int)_fY) );
	float f1overLast = 1.0f / iLast;
	int iSectX = iClampMax(_fX * f1overLast,SecsPerRow-1);
	int iSectY = iClampMax(_fY * f1overLast,SecsPerCol-1);

	_fX -= iSectX*iLast;
	_fY -= iSectY*iLast;
	
	return ( GetSector(iSectX,iSectY)->GetValueF(_fX,_fY));
  //## end CHeightField::GetValueF%1026770435.body
}

// Additional Declarations
  //## begin CHeightField%3AF9BE740014.declarations preserve=yes
  //## end CHeightField%3AF9BE740014.declarations

//## begin module%3AF9BE740014.epilog preserve=yes
//## end module%3AF9BE740014.epilog
