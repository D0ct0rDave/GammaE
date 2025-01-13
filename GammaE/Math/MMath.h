//---------------------------------------------------------------------------
#ifndef MMathH
#define MMathH
//---------------------------------------------------------------------------
// Defines
//---------------------------------------------------------------------------
#define     MMATH_INFINITE      10000000000
//---------------------------------------------------------------------------
// Basic functions
//---------------------------------------------------------------------------
float MMath_Step      (float a,float x);
float MMath_SmoothStep(float x,float a,float b);
float MMath_Pulse     (float x,float a,float b);

float MMath_Clamp(float x,float a,float b);
float MMath_Min  (float a,float b);
float MMath_Max  (float a,float b);
float MMath_Abs  (float x);
float MMath_Sgn  (float x);
float MMath_Mod  (float a,float b);
float MMath_Floor(float x);
float MMath_Ceil (float x);
float MMath_Lerp(float t,float x0,float x1);
//---------------------------------------------------------------------------
// Interpolation functions
//---------------------------------------------------------------------------
float MMath_Spline(float x,int NumKnots,float *Knot);
float MMath_Spline4Knots(float x,float *Knot);
//---------------------------------------------------------------------------
// Noise functions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------

