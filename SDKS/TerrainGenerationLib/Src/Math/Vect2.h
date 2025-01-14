//---------------------------------------------------------------------------
#ifndef Vect2H
#define Vect2H
//---------------------------------------------------------------------------
//#include "Vectores.h"
//---------------------------------------------------------------------------
typedef struct{
    float v[2];
}TVect2;
//---------------------------------------------------------------------------
TVect2 V2_Rotate(TVect2 &V,float Angle);
void   V2_Sum (TVect2 &VSrc,TVect2 &Diff);
void   V2_Diff(TVect2 &VSrc,TVect2 &Diff);
float  V2_DotProd(TVect2 &V1,TVect2 &V2);
float  V2_CrossProd(TVect2 &V1,TVect2 &V2);
float  V2_Module(TVect2 &V);
void   V2_Normalize(TVect2 &V);

// void V2_Proyecta2D     (TVect3 *VSrc,TVect2 *VDst,unsigned int NumElems,float FOV,float Near,float Far);
// void V2_Viewport2Screen(TVect2 *VSrc,TVect2 *VDst,unsigned int NumElems,unsigned int ScrWidth,unsigned int ScrHeight);
//---------------------------------------------------------------------------
#endif
