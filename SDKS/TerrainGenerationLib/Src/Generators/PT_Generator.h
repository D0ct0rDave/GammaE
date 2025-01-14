//---------------------------------------------------------------------------
#ifndef PT_Generator_h
#define PT_Generator_h 1
//---------------------------------------------------------------------------
#include "HeightField/PT_HeightField.h"
//---------------------------------------------------------------------------
class PT_Generator 
{
  public:
      virtual ~PT_Generator();
      virtual void Generate (PT_HeightField *HF) = 0;

  protected:
    // Data Members for Class Attributes
      float OfsX;
      float OfsY;
      float Scale;
      float Angle;

  public:
      const float GetOfsX () const{return OfsX;}
      const float GetOfsY () const{return OfsY;}
      const float GetScale() const{return Scale;}
      const float GetAngle() const{return Angle;}

      const void SetOfsX (float _OfsX) {OfsX = _OfsX;}
      const void SetOfsY (float _OfsY) {OfsY = _OfsY;}
      const void SetScale(float _Scale) {Scale = _Scale;}
      const void SetAngle(float _Angle) {Angle = _Angle;}
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
