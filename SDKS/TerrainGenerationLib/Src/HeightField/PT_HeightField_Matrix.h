//---------------------------------------------------------------------------
#ifndef PT_HeightField_Matrix_h
#define PT_HeightField_Matrix_h 1
//---------------------------------------------------------------------------
#include "HeightField/PT_HeightField.h"

class PT_HeightField_Matrix : PT_HeightField
{
  public:
      PT_HeightField_Matrix ();
      virtual ~PT_HeightField_Matrix();
      
      void  Init      (unsigned int TheTX, unsigned int TheTY);
      float GetHeight (unsigned int x, unsigned int y);
      void  SetHeight (unsigned int x, unsigned int y, float Height);

  protected:
    // Data Members for Class Attributes
      float *Data;
      float Min;
      float Max;


      
  public:
      const float * GetData () const{return Data;}
      const unsigned int GetTX () const{return TX;}
      const unsigned int GetTY () const{return TY;}

      inline float GetMax() {return Max;};
      inline float GetMin() {return Min;};
      inline float GetRange() {return(Max-Min);};
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
