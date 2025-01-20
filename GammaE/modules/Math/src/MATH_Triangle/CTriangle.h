//-----------------------------------------------------------------------------
#ifndef CTriangle_h
#define CTriangle_h 1
//-----------------------------------------------------------------------------
#include "..\MATH_Vector\CVect3.h"

class CTriangle 
{
  public:

      void Init (CVect3* _pVXs);

      
      void Init (CVect3* _pVXs, CVect3& _Normal);

      
      void ComputeSegs ();

      
      void ComputeAxis ();

      
      void ComputeAll ();

    //-----------------------------------------------------------------------------

      
      
      CVect3 Normal;
      

      
      
      CVect3 *VXs;
      

      
      
      CVect3 s0;
      

      
      
      CVect3 s1;
      

      
      
      CVect3 s2;
      

      
      
      CVect3 e1;
      

      
      
      CVect3 e2;
      

    //-----------------------------------------------------------------------------
      
      

  protected:
    //-----------------------------------------------------------------------------

      
      
      bool bSelfData;
      

    //-----------------------------------------------------------------------------
      
      

  private:
    //-----------------------------------------------------------------------------
      
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------



inline void CTriangle::Init (CVect3* _pVXs)
{
  
	VXs = _pVXs;
	Normal.Normal(VXs[0],VXs[1],VXs[2]);
  
}

inline void CTriangle::Init (CVect3* _pVXs, CVect3& _Normal)
{
  
	VXs = _pVXs;
	Normal.Assign(_Normal);
  
}

inline void CTriangle::ComputeSegs ()
{
    s0.Assign(VXs[0]);	s0.Sub(VXs[2]);
	s1.Assign(VXs[1]);	s1.Sub(VXs[0]);
	s2.Assign(VXs[2]);	s2.Sub(VXs[1]); 
}

inline void CTriangle::ComputeAxis ()
{
  
	e1.Assign(VXs[1]);	e1.Sub(VXs[0]);	
	e2.Assign(VXs[2]);	e2.Sub(VXs[0]);
  
}

inline void CTriangle::ComputeAll ()
{
  
    ComputeSegs ();
    ComputeAxis ();
  
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
