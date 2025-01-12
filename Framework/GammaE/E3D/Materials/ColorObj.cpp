//---------------------------------------------------------------------------
#include "ColorObj.h"
//---------------------------------------------------------------------------
TColorObj::TColorObj()
{
    ResColor.r = 0;
    ResColor.g = 0;
    ResColor.b = 0;
    ResColor.a = 0;
}

TColorObj::~TColorObj()
{

}

void TColorObj::Think()
{

}

void TColorObj::SetColor(float r,float g,float b,float a)
{
    ResColor.r = r;
    ResColor.g = g;
    ResColor.b = b;
    ResColor.a = a;
}

TFColor TColorObj::Color()
{
    return(ResColor);
}
//---------------------------------------------------------------------------

