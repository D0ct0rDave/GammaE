//---------------------------------------------------------------------------
#ifndef PT_HeightField_h
#define PT_HeightField_h 1
//---------------------------------------------------------------------------
class PT_HeightField 
{
  public:
  	  PT_HeightField();
      virtual ~PT_HeightField();
      virtual float GetHeight(unsigned int x, unsigned int y) = 0;
      virtual void  SetHeight(unsigned int x, unsigned int y, float Height) = 0;
      virtual float GetMax() = 0;
      virtual float GetMin() = 0;
      virtual float GetRange() = 0;

  public:
      const float GetHeightDisplacement() const{return HeightDisplacement;}
      const float GetHeightMultiplier() const{return HeightMultiplier;}
      const unsigned int GetTX() const{return TX;}
      const unsigned int GetTY() const{return TY;}

      inline void SetHeightDisplacement(float _HeightDisplacement)
      	{ HeightDisplacement = _HeightDisplacement;}

      inline void SetHeightMultiplier(float _HeightMultiplier)
      	{ HeightMultiplier = _HeightMultiplier;}

  protected:
      // Data Members for Class Attributes
      float HeightDisplacement;
      float HeightMultiplier;
      unsigned int TX;
      unsigned int TY;

  private:
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
