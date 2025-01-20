//## begin module%3AF878DE0320.cm preserve=no
//## end module%3AF878DE0320.cm

//## begin module%3AF878DE0320.cp preserve=no
//## end module%3AF878DE0320.cp

//## Module: CHFSector_FN%3AF878DE0320; Pseudo Package body
//## Source file: i:\Projects\GammaE\TerrainData\Sector\HeightField\CHFSector_FN.cpp

//## begin module%3AF878DE0320.additionalIncludes preserve=no
//## end module%3AF878DE0320.additionalIncludes

//## begin module%3AF878DE0320.includes preserve=yes
//## end module%3AF878DE0320.includes

// CHFSector_FN
#include "TerrainData\Sector\HeightField\CHFSector_FN.h"
//## begin module%3AF878DE0320.additionalDeclarations preserve=yes
  CHeight H;
//## end module%3AF878DE0320.additionalDeclarations


// Class CHFSector_FN 

CHFSector_FN::CHFSector_FN()
  //## begin CHFSector_FN::CHFSector_FN%.hasinit preserve=no
  //## end CHFSector_FN::CHFSector_FN%.hasinit
  //## begin CHFSector_FN::CHFSector_FN%.initialization preserve=yes
  //## end CHFSector_FN::CHFSector_FN%.initialization
{
  //## begin CHFSector_FN::CHFSector_FN%.body preserve=yes
	ulID = MAKE_RIFF_ID('H','S','F','N');
  //## end CHFSector_FN::CHFSector_FN%.body
}


CHFSector_FN::~CHFSector_FN()
{
  //## begin CHFSector_FN::~CHFSector_FN%.body preserve=yes
  //## end CHFSector_FN::~CHFSector_FN%.body
}



//## Other Operations (implementation)
CSectElem & CHFSector_FN::GetValue (int _X, int _Y)
{
  //## begin CHFSector_FN::GetValue%989359135.body preserve=yes
	H.Set(&((float *)pData)[_Y*Resolution+_X]);
	return H;
  //## end CHFSector_FN::GetValue%989359135.body
}

void CHFSector_FN::SetValue (int _X, int _Y, CSectElem &_Value)
{
  //## begin CHFSector_FN::SetValue%989359136.body preserve=yes
	CHFSector::SetValue(_X,_Y,_Value);
	((float *)pData)[_Y*Resolution+_X] = *(float *)(_Value.Get());
  //## end CHFSector_FN::SetValue%989359136.body
}

CSector * CHFSector_FN::CreateClass ()
{
  //## begin CHFSector_FN::CreateClass%989359138.body preserve=yes
	return (new CHFSector_FN());
  //## end CHFSector_FN::CreateClass%989359138.body
}

unsigned long CHFSector_FN::ElemArraySize (int _iResolution)
{
  //## begin CHFSector_FN::ElemArraySize%989667593.body preserve=yes
  	return( _iResolution*_iResolution*4 );
  //## end CHFSector_FN::ElemArraySize%989667593.body
}

void CHFSector_FN::GetLODData (int _iLOD, void *_pData)
{
  //## begin CHFSector_FN::GetLODData%995233497.body preserve=yes
	int iNewResolution = ((Resolution & 0xfffffffe) >> _iLOD);
	if (b21) iNewResolution++;

	int iStep = 1 << _iLOD;
	int cI,cJ,cX,cY;
	float *	pDst;
	float * pSrc;
	
	pDst = (float *)_pData;
	pSrc = (float *) pData;
	cY = 0;
	for (cJ=0;cJ<iNewResolution;cJ++)
	{
		cX = 0;
		for (cI=0;cI<iNewResolution;cI++)
		{		
			*pDst = pSrc[cY*Resolution+cX];
					
			pDst ++;
			cX   += iStep;
		}
		cY += iStep;
	}
  //## end CHFSector_FN::GetLODData%995233497.body
}

CSectElem & CHFSector_FN::GetValueF (float _fX, float _fY)
{
  //## begin CHFSector_FN::GetValueF%1026770434.body preserve=yes
	#define Height(_X,_Y) ((float *)pData)[_Y*Resolution+_X]

	if (VGenMethod == eGM_Nearest) return ( GetValue((int)_fX,(int)_fY) );

  	int 	iX1,iY1,iX2,iY2;	
    float	fX,fY;				// fractional parts

    iX1 = (int)_fX;
    iY1 = (int)_fY;

    if (iX1 < iLast) iX2 = iX1+1; else iX2 = iX1;
    if (iY1 < iLast) iY2 = iY1+1; else iY2 = iY1;

    fX = _fX - iX1;
    fY = _fY - iY1;

	float a,b,c,d,r1,r2,r;

	a = Height(iX1,iY1);
	b = Height(iX2,iY1);
	c = Height(iX1,iY2);
	d = Height(iX2,iY2);

	switch (VGenMethod)
    {
		case eGM_Linear:	r1 = a + (b-a)*fX;
				        	r2 = c + (d-c)*fX;
							r = r1 + (r2-r1)*fY;

							H.Set( &r );
							return ( H );
							break;

		case eGM_CosLinear: /*
							GVL_r1->CosInterpolate(*GVL_a,*GVL_b,fX);
				        	GVL_r2->CosInterpolate(*GVL_c,*GVL_d,fX);

							return ( GVL_a->CosInterpolate(*GVL_r1,*GVL_r2,fY) );
							*/
							break;
    }

	return H;
  //## end CHFSector_FN::GetValueF%1026770434.body
}

// Additional Declarations
  //## begin CHFSector_FN%3AF878DE0320.declarations preserve=yes
  //## end CHFSector_FN%3AF878DE0320.declarations

//## begin module%3AF878DE0320.epilog preserve=yes
//## end module%3AF878DE0320.epilog
