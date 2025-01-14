//---------------------------------------------------------------------------
#include "MatrixOps.h"
#include <string.h>
//---------------------------------------------------------------------------
void FindMaxMinMatrixValues(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS,float *Max,float *Min)
{
    unsigned int cI,cJ;
    *Max = -10000000;
    *Min =  10000000;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
        {
        	if (Matrix[cJ*uiCOLS+cI]>*Max) *Max = Matrix[cJ*uiCOLS+cI];
	        if (Matrix[cJ*uiCOLS+cI]<*Min) *Min = Matrix[cJ*uiCOLS+cI];
        }
}
//---------------------------------------------------------------------------
void RescaleMatrix(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS)
{
    float Max,Min;
    unsigned int cI,cJ;

	// Encontrar máximo y minimo
    FindMaxMinMatrixValues(Matrix,uiROWS,uiCOLS,&Max,&Min);
    if ((Max == Min) || ((Max==1) && (Min==0)) )return;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
            Matrix[cJ*uiCOLS+cI] = (Matrix[cJ*uiCOLS+cI]-Min)/(Max-Min);
}
//---------------------------------------------------------------------------
void ClampMatrix(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS)
{
    float Max,Min;
    unsigned int cI,cJ;

	// Encontrar máximo y minimo
    FindMaxMinMatrixValues(Matrix,uiROWS,uiCOLS,&Max,&Min);
    if ((Max == Min) || ((Max==1) && (Min==0)) )return;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
        {
        	if ( Matrix[cJ*uiCOLS+cI] > 1.0)	Matrix[cJ*uiCOLS+cI] = 1.0;
            if ( Matrix[cJ*uiCOLS+cI] < 0  ) 	Matrix[cJ*uiCOLS+cI] = 0.0;
        }
}
//---------------------------------------------------------------------------
void CopyMatrixs(float *SrcMatrix,float *DstMatrix,unsigned int uiROWS,unsigned int uiCOLS)
{
	memcpy(DstMatrix,SrcMatrix,uiROWS*uiCOLS*sizeof(float));
}
//---------------------------------------------------------------------------
void SumMatrixs(float *SrcMatrix,float *DstMatrix,unsigned int uiROWS,unsigned int uiCOLS)
{
    unsigned int cI,cJ;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
        {
        	DstMatrix[cJ*uiCOLS+cI] += SrcMatrix[cJ*uiCOLS+cI];
            if (DstMatrix[cJ*uiCOLS+cI] > 1) DstMatrix[cJ*uiCOLS+cI] = 1.0f;
       else if (DstMatrix[cJ*uiCOLS+cI] < 0) DstMatrix[cJ*uiCOLS+cI] = 0.0f;
        }
}
//---------------------------------------------------------------------------
void MultiplyMatrixs(float *SrcMatrix,float *DstMatrix,unsigned int uiROWS,unsigned int uiCOLS)
{
    unsigned int cI,cJ;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
        	DstMatrix[cJ*uiCOLS+cI] *= SrcMatrix[cJ*uiCOLS+cI];
}
//---------------------------------------------------------------------------
void InvertMatrix(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS)
{
    unsigned int cI,cJ;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
        	Matrix[cJ*uiCOLS+cI] = 1.0f - Matrix[cJ*uiCOLS+cI];
}
//---------------------------------------------------------------------------
void InterpolateMatrixs(float *SrcMatrix,float *DstMatrix,float *FacMatrix,unsigned int uiROWS,unsigned int uiCOLS)
{
    unsigned int cI,cJ;
    float a,b,f;

    for (cJ=0;cJ<uiROWS;cJ++)
	    for (cI=0;cI<uiCOLS;cI++)
        {
        	a = SrcMatrix[cJ*uiCOLS+cI];
            b = DstMatrix[cJ*uiCOLS+cI];
            f = FacMatrix[cJ*uiCOLS+cI];

        	DstMatrix[cJ*uiCOLS+cI] = a*f + (1-f)*b;
        }
}
//---------------------------------------------------------------------------
float GetMatrixBilinearValue(float *Matrix,unsigned int uiROWS,unsigned int uiCOLS,float cX,float cY)
{
    int cI,cJ;
    float a,b,c,d,r1,r2,r;
    float u,v;

    cI = cX;
    cJ = cY;

    if ((int)cI >= uiCOLS-1) cI = uiCOLS-2; else if (cI<0) cI=0;
    if ((int)cJ >= uiROWS-1) cJ = uiROWS-2; else if (cJ<0) cJ=0;

    u  = cX - (int)cX;
    v  = cY - (int)cY;

    a = Matrix[cJ    *uiCOLS+ cI   ];
    b = Matrix[cJ    *uiCOLS+(cI+1)];
    c = Matrix[(cJ+1)*uiCOLS+ cI   ];
    d = Matrix[(cJ+1)*uiCOLS+(cI+1)];

    r1 =  a*(1.0f-u) +  b*u;
    r2 =  c*(1.0f-u) +  d*u;
    r  = r1*(1.0f-v) + r2*v;
    
    return(r);
}
//---------------------------------------------------------------------------









