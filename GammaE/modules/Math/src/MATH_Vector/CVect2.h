//-----------------------------------------------------------------------------
#ifndef CVect2_h
#define CVect2_h 1
//-----------------------------------------------------------------------------
class CVect2 
{
  public:
   
      CVect2();

      CVect2 (float _fV0, float _fV1);

      void V2 (float _fV0, float _fV1);

      void Assign (const CVect2& _oV);
      
      void Add (const CVect2& _oV);
      
      void Add (float _fX, float _fY);

      void Sub (const CVect2& _oV);

      void Sub (float _fX, float _fY);

      void Mult (const CVect2& _oV);

      void Mult (float _fX, float _fY);

      void Scale (float _fScale);

      float DotProd (const CVect2& _oV);

      float Module ();

      float SqModule ();

      void Normalize ();

      void Interpolate (const CVect2& _oA,const  CVect2& _oB, float _fFact);

      float Distance (const CVect2& _oV);

      float SqDistance (const CVect2& _oV);

      bool Inside (const CVect2& _oMax,const  CVect2& _oMin);

      bool bEqual (const CVect2& _oV);

	  void LineEq (const CVect2& _oPos,const CVect2& _oDir, float _fU);
	  
		float& v(int _iIdx)
		{
			return( *((float*)&x + _iIdx) );
		}
		
		const float* V()
		{
			return( &x);
		};

	float x;
	float y;
};
//-----------------------------------------------------------------------------
inline CVect2::CVect2()
{
}

inline CVect2::CVect2 (float _fV0, float _fV1)
{
	x = _fV0;
	y = _fV1;
}

inline void CVect2::V2 (float _fV0, float _fV1)
{
  
	x = _fV0;
	y = _fV1;
  
}

inline void CVect2::Assign (const CVect2& _oV)
{
  
	x = _oV.x;
	y = _oV.y;
  
}

inline void CVect2::Add (const CVect2& _oV)
{
	x += _oV.x;
	y += _oV.y;
}

inline void CVect2::Add (float _fX, float _fY)
{
  
	x += _fX;
	y += _fY;
  
}

inline void CVect2::Sub (const CVect2& _oV)
{
  
	x -= _oV.x;
	y -= _oV.y;
  
}

inline void CVect2::Sub (float _fX, float _fY)
{
  
	x -= _fX;
	y -= _fY;
  
}

inline void CVect2::Mult (const CVect2& _oV)
{
  
  	x *= _oV.x;
	y *= _oV.y;
  
}

inline void CVect2::Mult (float _fX, float _fY)
{
  
  	x *= _fX;
	y *= _fY;
  
}

inline void CVect2::Scale (float _fScale)
{
  
	x *= _fScale;
	y *= _fScale;
  
}

inline float CVect2::DotProd (const CVect2& _oV)
{
  
	return (x*_oV.x + y*_oV.y);
  
}

inline void CVect2::Interpolate (const CVect2& _oA,const CVect2& _oB, float _fFact)
{
  
  /*
	float *va = a.v;
	float *vb = b.v;
	float *vc = v;
	*vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
	*vc  = *va+(*vb - *va)*Factor;
*/
	x = _oA.x + (_oB.x - _oA.x)*_fFact;
	y = _oA.y + (_oB.y - _oA.y)*_fFact;	
  
}


inline void CVect2::LineEq (const CVect2& _oPos,const CVect2& _oDir, float _fU)
{
	x = _oPos.x + _oDir.x*_fU;
	y = _oPos.y + _oDir.y*_fU;
}

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
