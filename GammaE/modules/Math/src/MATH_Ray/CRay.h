//-----------------------------------------------------------------------------
#ifndef CRay_h
#define CRay_h 1
//-----------------------------------------------------------------------------
#include "..\MATH_Vector\CVect3.h"
//-----------------------------------------------------------------------------
#include "..\MATH_Other\MATH_Common.h"
class CRay 
{
  public:
      
      void InitFromFields (CVect3& _Origin, CVect3& _Dir);

      
      void InitFromPoints (CVect3& _Origin, CVect3& _End);

      
      CVect3 ProjectPoint (CVect3& _Point);

      
      float GetDistanceToPoint (CVect3& _Point);

      
      float GetSqDistanceToPoint (CVect3& _Point);

      
      CVect3 GetPerpendicular (CVect3& _Point);

    //-----------------------------------------------------------------------------

      
      
      CVect3 Origin;
      

      
      
      CVect3 Dir;
      

    //-----------------------------------------------------------------------------
      
      

  protected:
    //-----------------------------------------------------------------------------
      
      

  private:
    //-----------------------------------------------------------------------------
      
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------



inline void CRay::InitFromFields (CVect3& _Origin, CVect3& _Dir)
{
  
  	Origin.Assign(_Origin);
	Dir.Assign(_Dir);
  
}

inline void CRay::InitFromPoints (CVect3& _Origin, CVect3& _End)
{
  
  	Origin.Assign(_Origin);	
	
	Dir.Assign(_End);
	Dir.Sub   (_Origin);
  
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
