



#include "GammaE_Mem.h"

// CHFSector_FN
#include "Sector\HeightField\CHFSector_FN.h"
  CHeight H;


// Class CHFSector_FN 

CHFSector_FN::CHFSector_FN()
        {
  	ulID = MAKE_RIFF_ID('H','S','F','N');
}


CHFSector_FN::~CHFSector_FN()
{
}



CSectElem & CHFSector_FN::GetValue (int _X, int _Y)
{
  	H.Set(&((float *)pData)[_Y*Resolution+_X]);
	return H;
}

void CHFSector_FN::SetValue (int _X, int _Y, CSectElem &_Value)
{
  	CHFSector::SetValue(_X,_Y,_Value);
	((float *)pData)[_Y*Resolution+_X] = *(float *)(_Value.Get());
}

CSector * CHFSector_FN::CreateClass ()
{
  	return (mNew CHFSector_FN());
}

unsigned long CHFSector_FN::ElemArraySize (int _iResolution)
{
    	return( _iResolution*_iResolution*4 );
}

void CHFSector_FN::GetLODData (int _iLOD, void *_pData)
{
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
}

CSectElem & CHFSector_FN::GetValueF (float _fX, float _fY)
{
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
}

// Additional Declarations
    
