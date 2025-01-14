//---------------------------------------------------------------------------
#include <math.h>
#include "Vect2.h"
//---------------------------------------------------------------------------
#ifndef     PI
#define     PI      3.1415926535897932384626433832795
#endif
//---------------------------------------------------------------------------
TVect2 V2_Rotate(TVect2 &V,float Angle)
{
	TVect2 r;
    float sn = sin(Angle);
    float cs = cos(Angle);

    r.v[0] =  V.v[0]*cs + V.v[1]*sn;
    r.v[1] = -V.v[0]*sn + V.v[1]*cs;

    return(r);
}
/*
//---------------------------------------------------------------------------
void V2_Proyecta2D(TVect3 *VSrc,TVect2 *VDst,unsigned int NumElems,float FOV,float zD,float zF)
{
    unsigned int cElem;
    float hV = zD*tan((PI*FOV/180.0f)/2);			// hV = zD * tan (FOV/2)   si FOV = 90 tan(FOV/2) = 1

    for (cElem=0;cElem<NumElems;cElem++)
        if ((VSrc[cElem].v[2] >= zD) && (VSrc[cElem].v[2] <= zF) )
        {
	        VDst[cElem].v[0] = (zD*VSrc[cElem].v[0])/(hV*VSrc[cElem].v[2]);
            VDst[cElem].v[1] = (zD*VSrc[cElem].v[1])/(hV*VSrc[cElem].v[2]);
        }
        else
        {
            VDst[cElem].v[0] = 0;
            VDst[cElem].v[1] = 0;
            VDst[cElem].v[2] = 0;
        }
}
*/
//---------------------------------------------------------------------------
void V2_Viewport2Screen(TVect2 *VSrc,TVect2 *VDst,unsigned int NumElems,unsigned int SrcWidth,unsigned int SrcHeight)
{
    unsigned int cElem;

    for (cElem=0;cElem<NumElems;cElem++)
    {
        VDst[cElem].v[0] = SrcWidth/2  + ((SrcWidth /2) * VSrc[cElem].v[0]);
        VDst[cElem].v[1] = SrcHeight/2 - ((SrcHeight/2) * VSrc[cElem].v[1]);
    }
}
//---------------------------------------------------------------------------
void V2_Sum(TVect2 &VSrc,TVect2 &Diff)
{
    VSrc.v[0] += Diff.v[0];
    VSrc.v[1] += Diff.v[1];
}
//---------------------------------------------------------------------------
void V2_Diff(TVect2 &VSrc,TVect2 &Diff)
{
    VSrc.v[0] -= Diff.v[0];
    VSrc.v[1] -= Diff.v[1];
}
//---------------------------------------------------------------------------
float V2_DotProd(TVect2 &V1,TVect2 &V2)
{
    return(V1.v[0]*V2.v[0] + V1.v[1]*V2.v[1]);
}
//---------------------------------------------------------------------------
float V2_CrossProd(TVect2 &V1,TVect2 &V2)
{
    return(V1.v[0]*V2.v[1] - V1.v[1]*V2.v[0]);
}
//---------------------------------------------------------------------------
float V2_Module(TVect2 &V)
{
    return( sqrt(V.v[0]*V.v[0] + V.v[1]*V.v[1]) );
}
//---------------------------------------------------------------------------
void V2_Normalize(TVect2 &V)
{
	float Modulo = V2_Module(V);

    if (!Modulo) return;

    V.v[0] /= Modulo;
    V.v[1] /= Modulo;
}
//---------------------------------------------------------------------------
