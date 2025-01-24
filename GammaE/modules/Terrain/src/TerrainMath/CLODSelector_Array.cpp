



#include "GammaE_Mem.h"

// CLODSelector_Array
#include "TerrainMath\CLODSelector_Array.h"


// Class CLODSelector_Array 




CLODSelector_Array::CLODSelector_Array()
        : LODArray(0), iMaxLODs(0), iNumLODs(0)
      {
}


CLODSelector_Array::~CLODSelector_Array()
{
  	if (LODArray) mDel []LODArray;
}



float CLODSelector_Array::GetLOD (float fDist)
{
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
}

void CLODSelector_Array::AddLOD (float fLODDist)
{
  	LODArray[iNumLODs++] = fLODDist;
}

void CLODSelector_Array::Init (int _MaxLODs)
{
  	iMaxLODs = _MaxLODs;
	iNumLODs = 0;
	LODArray = mNew float[iMaxLODs];
}

// Additional Declarations
    
