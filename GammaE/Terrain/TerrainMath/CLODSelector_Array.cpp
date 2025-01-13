//## begin module%3B54BA61015E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B54BA61015E.cm

//## begin module%3B54BA61015E.cp preserve=no
//## end module%3B54BA61015E.cp

//## Module: CLODSelector_Array%3B54BA61015E; Pseudo Package body
//## Source file: i:\Projects\GammaE\Terrain\TerrainMath\CLODSelector_Array.cpp

//## begin module%3B54BA61015E.additionalIncludes preserve=no
//## end module%3B54BA61015E.additionalIncludes

//## begin module%3B54BA61015E.includes preserve=yes
//## end module%3B54BA61015E.includes

// CLODSelector_Array
#include "Terrain\TerrainMath\CLODSelector_Array.h"
//## begin module%3B54BA61015E.additionalDeclarations preserve=yes
//## end module%3B54BA61015E.additionalDeclarations


// Class CLODSelector_Array 




CLODSelector_Array::CLODSelector_Array()
  //## begin CLODSelector_Array::CLODSelector_Array%.hasinit preserve=no
      : LODArray(0), iMaxLODs(0), iNumLODs(0)
  //## end CLODSelector_Array::CLODSelector_Array%.hasinit
  //## begin CLODSelector_Array::CLODSelector_Array%.initialization preserve=yes
  //## end CLODSelector_Array::CLODSelector_Array%.initialization
{
  //## begin CLODSelector_Array::CLODSelector_Array%.body preserve=yes
  //## end CLODSelector_Array::CLODSelector_Array%.body
}


CLODSelector_Array::~CLODSelector_Array()
{
  //## begin CLODSelector_Array::~CLODSelector_Array%.body preserve=yes
	if (LODArray) delete []LODArray;
  //## end CLODSelector_Array::~CLODSelector_Array%.body
}



//## Other Operations (implementation)
float CLODSelector_Array::GetLOD (float fDist)
{
  //## begin CLODSelector_Array::GetLOD%995406157.body preserve=yes
	int	  cLOD;	
	float fLastLODDst = 0;

	for (cLOD=0;cLOD<iNumLODs;cLOD++)
	{
		if (fDist <= LODArray[cLOD]) 
		{
			return((float)cLOD + ((fDist - fLastLODDst) / (LODArray[cLOD] - fLastLODDst)) );
		}

		fLastLODDst = LODArray[cLOD];
	}

	return(-1.0f*cLOD);
  //## end CLODSelector_Array::GetLOD%995406157.body
}

void CLODSelector_Array::AddLOD (float fLODDist)
{
  //## begin CLODSelector_Array::AddLOD%995406159.body preserve=yes
	LODArray[iNumLODs++] = fLODDist;
  //## end CLODSelector_Array::AddLOD%995406159.body
}

void CLODSelector_Array::Init (int _MaxLODs)
{
  //## begin CLODSelector_Array::Init%995406160.body preserve=yes
	iMaxLODs = _MaxLODs;
	iNumLODs = 0;
	LODArray = new float[iMaxLODs];
  //## end CLODSelector_Array::Init%995406160.body
}

// Additional Declarations
  //## begin CLODSelector_Array%3B54BA61015E.declarations preserve=yes
  //## end CLODSelector_Array%3B54BA61015E.declarations

//## begin module%3B54BA61015E.epilog preserve=yes
//## end module%3B54BA61015E.epilog
