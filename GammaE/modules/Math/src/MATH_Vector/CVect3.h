//-----------------------------------------------------------------------------
#ifndef CVect3_h
#define CVect3_h 1
//-----------------------------------------------------------------------------
#include <math.h>
#include "GammaE_Misc.h"
#ifndef cosf
#define cosf cos
#endif

#ifndef sinf
#define sinf sin
#endif
//-----------------------------------------------------------------------------
// MATH_Common
#include "..\MATH_Other\MATH_Common.h"
//-----------------------------------------------------------------------------
class CVect3 
{
  public:
			CVect3();
			
			CVect3 (float _fX, float _fY, float _fZ);

            void V3(float _fX, float _fY, float _fZ);

            void Point(float _fAzimut, float _fElevation);

            void Assign(const CVect3& _oV);

            void CrossProd(const CVect3& _oV1,const CVect3& _oV2);

            void Normal(const CVect3& _oA, const CVect3& _oB, const CVect3& _oC);

            void Orthogonal(const CVect3& _oV);

            void LineEq(const CVect3& _oPos, const CVect3& _oDir, float _fU);

            void Add(const CVect3& _oV);

            void Sub(const CVect3& _oV);

            void Mult(const CVect3& _oV);

            void Scale(float _fFactor);

            void Add(float _fX, float _fY, float _fZ);

            void Sub(float _fX, float _fY, float _fZ);

            void Mult(float _fX, float _fY, float _fZ);

            float fDotProd(const CVect3& _oV) const;

            void Interpolate(const CVect3& _oA,const CVect3& _oB, float _fFact);

            void Normalize();

            float fModule() const;

            float fSqModule() const;

            float fDistance(const CVect3& _oPnt) const;

            float fSqDistance(const CVect3& _oPnt) const;

            bool bInside(const CVect3& _oMax, const CVect3& _oMin) const;

            bool bEqual(const CVect3& _oV) const;

            int iGetGreaterAxis() const;

            static const CVect3& oZero() { extern CVect3 gsoZero;	return(gsoZero); };
            static const CVect3& oX()    { extern CVect3 gsoX;		return(gsoX); };
            static const CVect3& oY()    { extern CVect3 gsoY;		return(gsoY); };
            static const CVect3& oZ()    { extern CVect3 gsoZ;		return(gsoZ); };

			float& v(uint _uiIdx)
			{
				return( *((float*)&x + _uiIdx) );
			}

			const float* V()
			{
				return( &x);
			};
			// float& operator[](const unsigned int index) const;

			// Data Members for Class Attributes				
			float x;
			float y;
			float z;
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CVect3 

inline CVect3::CVect3()
{
}

inline CVect3::CVect3(float _fX, float _fY, float _fZ)
{
  	x = _fX;
	y = _fY;
	z = _fZ;
}

inline void CVect3::V3(float _fX, float _fY, float _fZ)
{
  	x = _fX;
	y = _fY;
	z = _fZ;
}

inline void CVect3::Point(float _fAzimut, float _fElevation)
{
	static float c;
	c = (float)cosf(_fElevation);

    x = c * (float)cosf(_fAzimut);
    y = c * (float)sinf(_fAzimut);
    z =     (float)sinf(_fElevation);
}

inline void CVect3::Assign(const CVect3& _oV)
{
  	x = _oV.x;
	y = _oV.y;
	z = _oV.z;
}

inline void CVect3::CrossProd(const CVect3& _oV1,const CVect3& _oV2)
{
  	x = _oV1.y*_oV2.z - _oV1.z*_oV2.y;
	y = _oV1.z*_oV2.x - _oV1.x*_oV2.z;
	z = _oV1.x*_oV2.y - _oV1.y*_oV2.x;
}

inline void CVect3::Normal(const CVect3& _oA, const CVect3& _oB, const CVect3& _oC)
{
  	CVect3 ba,ca;

    ba.Assign(_oB);	ba.Sub(_oA);
    ca.Assign(_oC);	ca.Sub(_oA);

    CrossProd(ba,ca);
}

inline void CVect3::Orthogonal(const CVect3& _oV)
{
  	float fX = MATH_Common::fAbs(_oV.x);
	float fY = MATH_Common::fAbs(_oV.y);
	float fZ = MATH_Common::fAbs(_oV.z);

	// Regla: intercambiar las 2 coordenadas con valores más altos
	// la coordenada que tenga menor valor se invierte ( multiplica por -1)
	// la coordenada con valor más bajo se deja a 0

	if (fX > fY)
	{
		if (fY > fZ)
		{
			// fX > fY && fY > fZ
			x = -_oV.y;
			y =  _oV.x;
			z =  0.0f;
		}
		else
		{			
			if (fX > fZ)
			{
				// fX > fY && fX > fZ && fZ > fY
				x = -_oV.z;
				y =  0.0f;
				z =  _oV.x;
			}
			else			
			{
				// fX > fY && fZ < fX fY < fZ
				x =  _oV.z;
				y =  0.0f;
				z = -_oV.x;
			}
		}
	}
	else
	{
		if (fY > fZ)
		{			
			if (fX > fZ)
			{
				// fY > fX && fY > fZ && fX > fZ
				x =  _oV.y;
				y = -_oV.x;
				z =  0.0f;
			}
			else
			{
				// fY > fX && fY > fZ && fZ > fX
				x = 0.0f;
				y = -_oV.z;
				z =  _oV.y;
			}			
		}
		else
		{
			// fZ > fY && fY > fX
			x = 0.0f;
			y =  _oV.z;
			z = -_oV.y;			
		}
	}

}

inline void CVect3::LineEq (const CVect3& _oPos,const CVect3& _oDir, float _fU)
{
   	x = _oPos.x + _fU*_oDir.x;
	y = _oPos.y + _fU*_oDir.y;
	z = _oPos.z + _fU*_oDir.z;
}

inline void CVect3::Add(const CVect3& _oV)
{
  	x += _oV.x;
	y += _oV.y;
	z += _oV.z;
}

inline void CVect3::Sub(const CVect3& _oV)
{
  	x -= _oV.x;
	y -= _oV.y;
	z -= _oV.z;
}

inline void CVect3::Mult(const CVect3& _oV)
{
  	x *= _oV.x;
	y *= _oV.y;
	z *= _oV.z;
}

inline void CVect3::Scale(float _fFactor)
{
    x *= _fFactor;
	y *= _fFactor;
	z *= _fFactor;
}

inline void CVect3::Add(float _fX, float _fY, float _fZ)
{
  	x += _fX;
	y += _fY;
	z += _fZ;
}

inline void CVect3::Sub(float _fX, float _fY, float _fZ)
{
  	x -= _fX;
	y -= _fY;
	z -= _fZ;
}

inline void CVect3::Mult(float _fX, float _fY, float _fZ)
{
  	x *= _fX;
	y *= _fY;
	z *= _fZ;
}

inline float CVect3::fDotProd(const CVect3& _oV) const
{
  	return (x*_oV.x + y*_oV.y + z*_oV.z);
}

inline float CVect3::fModule() const
{
  	return( MATH_Common::fSqrt(x*x + y*y + z*z) );
}

inline float CVect3::fSqModule() const
{
  	return (x*x + y*y + z*z);
}

inline void CVect3::Normalize()
{
  	static float m;
	
	m = fModule();
	if (m==1) return;

	if (m)
    {
    	m = 1.0f/m;

    	x*=m;
    	y*=m;
    	z*=m;
}
    else
    {
        // x = MMath_Sgn(x)*MMATH_INFINITE;
        x = MATH_Common::fSign(x)*1000;
        y = x;
        z = x;
}
}

inline void CVect3::Interpolate(const CVect3& _oA,const CVect3& _oB, float _fFact)
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
}

inline float CVect3::fDistance(const CVect3& _oPnt) const
{
  	return (MATH_Common::fSqrt(fSqDistance(_oPnt)) );
}

inline float CVect3::fSqDistance(const CVect3& _oPnt) const
{
  	static CVect3 VAux;

    VAux.V3(x,y,z);
    VAux.Sub (_oPnt);
	return ( VAux.fSqModule() );
}

inline bool CVect3::bInside (const CVect3& _oMax,const CVect3& _oMin) const
{
  /*
	//-----------------------------------------------------------------------------
	inline float _FFabs(float a)
	{	
		*((unsigned int *)&a) &= 0x7fffffff;	
		return(a);
	}

	return ( (
			  (_FFabs(Max.x - x) + _FFabs(x - Min.x) + 
			   _FFabs(Max.y - y) + _FFabs(y - Min.y) +
			   _FFabs(Max.z - z) + _FFabs(z - Min.z)) -
			 
			 (_FFabs(Max.x - Min.x) +
			  _FFabs(Max.y - Min.y) +
			  _FFabs(Max.z - Min.z))
			  )

			  == 0.0f
			);
*/
	return(
    	  (x >= _oMin.x) && (y >= _oMin.y) && (z >= _oMin.z) &&
          (x <= _oMax.x) && (y <= _oMax.y) && (z <= _oMax.z)
          );

}

inline bool CVect3::bEqual(const CVect3& _oV) const
{
  	return( (x == _oV.x) && (y == _oV.y) && (z == _oV.z) );
}

inline int CVect3::iGetGreaterAxis () const
{
  	float fX = MATH_Common::fAbs(x);
	float fY = MATH_Common::fAbs(y);
	float fZ = MATH_Common::fAbs(z);

	if (fX > fY)
	{
		if (fY > fZ)
			// fX > fY && fY > fZ
			return(0);
		else
		{			
			if (fX > fZ)
				// fX > fY && fX > fZ
				return(0);
			else
				// fX > fY && fZ > fX
				return(2);
		}
	}
	else
	{
		if (fY > fZ)
			// fY > fX && fY > fZ
			return(1);
		else
			// fZ > fY && fY > fZ
			return(2);
	}
}
//-----------------------------------------------------------------------------
/*
float& CVect3::operator[](const unsigned int index) const
{
	return( *((float*)&x + index) );
}
*/
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
