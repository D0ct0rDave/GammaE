//-----------------------------------------------------------------------------
#ifndef CVect4_h
#define CVect4_h 1
//-----------------------------------------------------------------------------
class CVect4 
{   
  public:
            CVect4();

            CVect4 (float _fV0, float _fV1, float _fV2, float _fV3);

            void V4 (float _fV0, float _fV1, float _fV2, float _fV3);

            void Assign(const CVect4& _oV);

            void Add (const CVect4& _oV);

            void Add (float _fX, float _fY, float _fZ, float _fW);

            void Sub (const CVect4& _oV);

            void Sub (float _fX, float _fY, float _fZ, float _fW);

            void Interpolate(const CVect4& _oA,const CVect4& _oB, float _fFact);

            void LineEq (const CVect4& _oPos,const CVect4& _oDir, float _fU);

			// Additional Public Declarations
      		void Scale (float _fFactor);

			float& v(int _iIdx)
			{
				return( *((float*)&x + _iIdx) );
			}

			const float* V()
			{
				return( &x);
			};

			// Data Members for Class Attributes
			float x;
			float y;
			float z;
			float w;

};

// Class CVect4 
inline CVect4::CVect4()
{
}

inline CVect4::CVect4 (float _fV0, float _fV1, float _fV2, float _fV3)
{
  	x = _fV0;
	y = _fV1;
	z = _fV2;
	w = _fV3;
}

inline void CVect4::V4 (float _fV0, float _fV1, float _fV2, float _fV3)
{
  	x = _fV0;
	y = _fV1;
	z = _fV2;
	w = _fV3;
}

inline void CVect4::Assign (const CVect4& _oV)
{
  	x = _oV.x;
	y = _oV.y;
	z = _oV.z;
	w = _oV.w;
}

inline void CVect4::Add (const CVect4& _oV)
{
  	x += _oV.x;
	y += _oV.y;
	z += _oV.z;
	w += _oV.w;
}

inline void CVect4::Add (float _fX, float _fY, float _fZ, float _fW)
{
    x += _fX;
	y += _fY;
	z += _fZ;
	w += _fW;
}

inline void CVect4::Sub (const CVect4& _oV)
{
  	x -= _oV.x;
	y -= _oV.y;
	z -= _oV.z;
	w -= _oV.w;
}

inline void CVect4::Sub (float _fX, float _fY, float _fZ, float _fW)
{
  	x -= _fX;
	y -= _fY;
	z -= _fZ;
	w -= _fW;
}

inline void CVect4::Interpolate (const CVect4& _oA,const CVect4& _oB, float _fFact)
{
    /*
	// x = a*(1-f) + b*f   =>   x = a -a*f + b*f    =>	x = a + (b-a)*f

	float *va = a.v;
	float *vb = b.v;
	float *vc = v;

	*vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
	*vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
	*vc  = *va+(*vb - *va)*Factor;
*/
	x = _oA.x + (_oB.x - _oA.x)*_fFact;
	y = _oA.y + (_oB.y - _oA.y)*_fFact;
	z = _oA.z + (_oB.z - _oA.z)*_fFact;
	w = _oA.w + (_oB.w - _oA.w)*_fFact;
}

inline void CVect4::LineEq (const CVect4& _oPos,const CVect4& _oDir, float _fU)
{
  	x = _oPos.x + _oDir.x*_fU;
	y = _oPos.y + _oDir.y*_fU;
	z = _oPos.z + _oDir.z*_fU;
	w = _oPos.w + _oDir.w*_fU;
}

inline void CVect4::Scale (float _fFactor)
{
  	x *= _fFactor;
	y *= _fFactor;
	z *= _fFactor;
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
