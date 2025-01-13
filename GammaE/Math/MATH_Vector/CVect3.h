//## begin module%3A9AD9AC01F4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD9AC01F4.cm

//## begin module%3A9AD9AC01F4.cp preserve=no
//## end module%3A9AD9AC01F4.cp

//## Module: CVect3%3A9AD9AC01F4; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Vector\CVect3.h

#ifndef CVect3_h
#define CVect3_h 1

//## begin module%3A9AD9AC01F4.additionalIncludes preserve=no
//## end module%3A9AD9AC01F4.additionalIncludes

//## begin module%3A9AD9AC01F4.includes preserve=yes
#include <math.h>
#ifndef cosf
#define cosf cos
#endif

#ifndef sinf
#define sinf sin
#endif

#define _X_	0
#define _Y_	1
#define _Z_	2

//## end module%3A9AD9AC01F4.includes

// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3A9AD9AC01F4.additionalDeclarations preserve=yes
//## end module%3A9AD9AC01F4.additionalDeclarations


//## begin CVect3%3A9AD9AC01F4.preface preserve=yes
//## end CVect3%3A9AD9AC01F4.preface

//## Class: CVect3%3A9AD9AC01F4
//## Category: Math::MATH_Vector%3C275D080385
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CB5CCBE0346;MATH_Common { -> }

class CVect3 
{
  //## begin CVect3%3A9AD9AC01F4.initialDeclarations preserve=yes
  //## end CVect3%3A9AD9AC01F4.initialDeclarations

  public:
    //## Constructors (generated)
      CVect3();

    //## Constructors (specified)
      //## Operation: CVect3%1018547492
      CVect3 (float _fX, float _fY, float _fZ);


    //## Other Operations (specified)
      //## Operation: V3%1018547493
      void V3 (float _fX, float _fY, float _fZ);

      //## Operation: Point%1018547494
      void Point (float _fAzimut, float _fElevation);

      //## Operation: Assign%1018547495
      void Assign (CVect3& _roV);

      //## Operation: CrossProd%1018547496
      void CrossProd (CVect3& _roV1, CVect3& _roV2);

      //## Operation: Normal%1018547497
      void Normal (CVect3& _roA, CVect3& _roB, CVect3& _roC);

      //## Operation: Orthogonal%1018547498
      void Orthogonal (CVect3& _roV);

      //## Operation: LineEq%1018547499
      void LineEq (CVect3& _roPos, CVect3& _roDir, float _fU);

      //## Operation: X%1018547500
      float X ();

      //## Operation: Y%1018547501
      float Y ();

      //## Operation: Z%1018547502
      float Z ();

      //## Operation: SetX%1018547503
      void SetX (float _fX);

      //## Operation: SetY%1018547504
      void SetY (float _fY);

      //## Operation: SetZ%1018547505
      void SetZ (float _fZ);

      //## Operation: Add%1018547506
      void Add (CVect3& _roV);

      //## Operation: Sub%1018547507
      void Sub (CVect3& _roV);

      //## Operation: Mult%1018547508
      void Mult (CVect3& _roV);

      //## Operation: Scale%1018547509
      void Scale (float _fFactor);

      //## Operation: Add%1018547510
      void Add (float _fX, float _fY, float _fZ);

      //## Operation: Sub%1018547511
      void Sub (float _fX, float _fY, float _fZ);

      //## Operation: Mult%1018547512
      void Mult (float _fX, float _fY, float _fZ);

      //## Operation: DotProd%1018547513
      float DotProd (CVect3& _roV);

      //## Operation: Module%1018547514
      float Module ();

      //## Operation: SqModule%1018547515
      float SqModule ();

      //## Operation: Normalize%1018547516
      void Normalize ();

      //## Operation: Interpolate%1018547517
      void Interpolate (CVect3& _roA, CVect3& _roB, float _fFact);

      //## Operation: Distance%1018547518
      float Distance (CVect3& _roPnt);

      //## Operation: SqDistance%1018547519
      float SqDistance (CVect3& _roPnt);

      //## Operation: Inside%1018547520
      bool Inside (CVect3& _roMax, CVect3& _roMin);

      //## Operation: Equal%1018547521
      bool Equal (CVect3& _roV);

      //## Operation: iGetGreaterAxis%1018547522
      int iGetGreaterAxis ();

    // Data Members for Class Attributes

      //## Attribute: v%3CB5CCB402F2
      //## begin CVect3::v%3CB5CCB402F2.attr preserve=no  public: float[3] {UA} 
      float v[3];
      //## end CVect3::v%3CB5CCB402F2.attr

    // Additional Public Declarations
      //## begin CVect3%3A9AD9AC01F4.public preserve=yes
      //## end CVect3%3A9AD9AC01F4.public

  protected:
    // Additional Protected Declarations
      //## begin CVect3%3A9AD9AC01F4.protected preserve=yes
      //## end CVect3%3A9AD9AC01F4.protected

  private:
    // Additional Private Declarations
      //## begin CVect3%3A9AD9AC01F4.private preserve=yes
      //## end CVect3%3A9AD9AC01F4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CVect3%3A9AD9AC01F4.implementation preserve=yes
      //## end CVect3%3A9AD9AC01F4.implementation

};

//## begin CVect3%3A9AD9AC01F4.postscript preserve=yes
//## end CVect3%3A9AD9AC01F4.postscript

// Class CVect3 

inline CVect3::CVect3()
  //## begin CVect3::CVect3%.hasinit preserve=no
  //## end CVect3::CVect3%.hasinit
  //## begin CVect3::CVect3%.initialization preserve=yes
  //## end CVect3::CVect3%.initialization
{
  //## begin CVect3::CVect3%.body preserve=yes
  //## end CVect3::CVect3%.body
}

inline CVect3::CVect3 (float _fX, float _fY, float _fZ)
  //## begin CVect3::CVect3%1018547492.hasinit preserve=no
  //## end CVect3::CVect3%1018547492.hasinit
  //## begin CVect3::CVect3%1018547492.initialization preserve=yes
  //## end CVect3::CVect3%1018547492.initialization
{
  //## begin CVect3::CVect3%1018547492.body preserve=yes
	v[0] = _fX;
	v[1] = _fY;
	v[2] = _fZ;
  //## end CVect3::CVect3%1018547492.body
}



//## Other Operations (inline)
inline void CVect3::V3 (float _fX, float _fY, float _fZ)
{
  //## begin CVect3::V3%1018547493.body preserve=yes
	v[0] = _fX;
	v[1] = _fY;
	v[2] = _fZ;
  //## end CVect3::V3%1018547493.body
}

inline void CVect3::Point (float _fAzimut, float _fElevation)
{
  //## begin CVect3::Point%1018547494.body preserve=yes
    static float c;
	c = (float)cosf(_fElevation);

    v[0] = c * (float)cosf(_fAzimut);
    v[1] = c * (float)sinf(_fAzimut);
    v[2] =     (float)sinf(_fElevation);
  //## end CVect3::Point%1018547494.body
}

inline void CVect3::Assign (CVect3& _roV)
{
  //## begin CVect3::Assign%1018547495.body preserve=yes
	v[0] = _roV.v[0];
	v[1] = _roV.v[1];
	v[2] = _roV.v[2];
  //## end CVect3::Assign%1018547495.body
}

inline void CVect3::CrossProd (CVect3& _roV1, CVect3& _roV2)
{
  //## begin CVect3::CrossProd%1018547496.body preserve=yes
	v[0] = _roV1.Y()*_roV2.Z() - _roV1.Z()*_roV2.Y();
	v[1] = _roV1.Z()*_roV2.X() - _roV1.X()*_roV2.Z();
	v[2] = _roV1.X()*_roV2.Y() - _roV1.Y()*_roV2.X();
  //## end CVect3::CrossProd%1018547496.body
}

inline void CVect3::Normal (CVect3& _roA, CVect3& _roB, CVect3& _roC)
{
  //## begin CVect3::Normal%1018547497.body preserve=yes
  	static CVect3 ba,ca;

    ba.Assign(_roB);	ba.Sub(_roA);
    ca.Assign(_roC);	ca.Sub(_roA);

    CrossProd(ba,ca);
  //## end CVect3::Normal%1018547497.body
}

inline void CVect3::Orthogonal (CVect3& _roV)
{
  //## begin CVect3::Orthogonal%1018547498.body preserve=yes
	float fX = MATH_Common::fAbs(_roV.v[0]);
	float fY = MATH_Common::fAbs(_roV.v[1]);
	float fZ = MATH_Common::fAbs(_roV.v[2]);

	// Regla: intercambiar las 2 coordenadas con valores más altos
	// la coordenada que tenga menor valor se invierte ( multiplica por -1)
	// la coordenada con valor más bajo se deja a 0

	if (fX > fY)
	{
		if (fY > fZ)
		{
			// fX > fY && fY > fZ
			v[0] = -_roV.v[1];
			v[1] =  _roV.v[0];
			v[2] =  0.0f;
		}
		else
		{			
			if (fX > fZ)
			{
				// fX > fY && fX > fZ && fZ > fY
				v[0] = -_roV.v[2];
				v[1] =  0.0f;
				v[2] =  _roV.v[0];
			}
			else			
			{
				// fX > fY && fZ < fX fY < fZ
				v[0] =  _roV.v[2];
				v[1] =  0.0f;
				v[2] = -_roV.v[0];
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
				v[0] =  _roV.v[1];
				v[1] = -_roV.v[0];
				v[2] =  0.0f;
			}
			else
			{
				// fY > fX && fY > fZ && fZ > fX
				v[0] = 0.0f;
				v[1] = -_roV.v[2];
				v[2] =  _roV.v[1];
			}			
		}
		else
		{
			// fZ > fY && fY > fX
			v[0] = 0.0f;
			v[1] =  _roV.v[2];
			v[2] = -_roV.v[1];			
		}
	}

  //## end CVect3::Orthogonal%1018547498.body
}

inline void CVect3::LineEq (CVect3& _roPos, CVect3& _roDir, float _fU)
{
  //## begin CVect3::LineEq%1018547499.body preserve=yes
  	v[0] = _roPos.v[0] + _fU*_roDir.v[0];
	v[1] = _roPos.v[1] + _fU*_roDir.v[1];
	v[2] = _roPos.v[2] + _fU*_roDir.v[2];
  //## end CVect3::LineEq%1018547499.body
}

inline float CVect3::X ()
{
  //## begin CVect3::X%1018547500.body preserve=yes
	return(v[0]);
  //## end CVect3::X%1018547500.body
}

inline float CVect3::Y ()
{
  //## begin CVect3::Y%1018547501.body preserve=yes
	return(v[1]);	
  //## end CVect3::Y%1018547501.body
}

inline float CVect3::Z ()
{
  //## begin CVect3::Z%1018547502.body preserve=yes
	return(v[2]);
  //## end CVect3::Z%1018547502.body
}

inline void CVect3::SetX (float _fX)
{
  //## begin CVect3::SetX%1018547503.body preserve=yes
	v[0] = _fX;
  //## end CVect3::SetX%1018547503.body
}

inline void CVect3::SetY (float _fY)
{
  //## begin CVect3::SetY%1018547504.body preserve=yes
	v[1] = _fY;
  //## end CVect3::SetY%1018547504.body
}

inline void CVect3::SetZ (float _fZ)
{
  //## begin CVect3::SetZ%1018547505.body preserve=yes
	v[2] = _fZ;
  //## end CVect3::SetZ%1018547505.body
}

inline void CVect3::Add (CVect3& _roV)
{
  //## begin CVect3::Add%1018547506.body preserve=yes
	v[0] += _roV.v[0];
	v[1] += _roV.v[1];
	v[2] += _roV.v[2];
  //## end CVect3::Add%1018547506.body
}

inline void CVect3::Sub (CVect3& _roV)
{
  //## begin CVect3::Sub%1018547507.body preserve=yes
	v[0] -= _roV.v[0];
	v[1] -= _roV.v[1];
	v[2] -= _roV.v[2];
  //## end CVect3::Sub%1018547507.body
}

inline void CVect3::Mult (CVect3& _roV)
{
  //## begin CVect3::Mult%1018547508.body preserve=yes
	v[0] *= _roV.v[0];
	v[1] *= _roV.v[1];
	v[2] *= _roV.v[2];
  //## end CVect3::Mult%1018547508.body
}

inline void CVect3::Scale (float _fFactor)
{
  //## begin CVect3::Scale%1018547509.body preserve=yes
  	v[0] *= _fFactor;
	v[1] *= _fFactor;
	v[2] *= _fFactor;
  //## end CVect3::Scale%1018547509.body
}

inline void CVect3::Add (float _fX, float _fY, float _fZ)
{
  //## begin CVect3::Add%1018547510.body preserve=yes
	v[0] += _fX;
	v[1] += _fY;
	v[2] += _fZ;
  //## end CVect3::Add%1018547510.body
}

inline void CVect3::Sub (float _fX, float _fY, float _fZ)
{
  //## begin CVect3::Sub%1018547511.body preserve=yes
	v[0] -= _fX;
	v[1] -= _fY;
	v[2] -= _fZ;
  //## end CVect3::Sub%1018547511.body
}

inline void CVect3::Mult (float _fX, float _fY, float _fZ)
{
  //## begin CVect3::Mult%1018547512.body preserve=yes
	v[0] *= _fX;
	v[1] *= _fY;
	v[2] *= _fZ;
  //## end CVect3::Mult%1018547512.body
}

inline float CVect3::DotProd (CVect3& _roV)
{
  //## begin CVect3::DotProd%1018547513.body preserve=yes
	return (v[0]*_roV.v[0] + v[1]*_roV.v[1] + v[2]*_roV.v[2]);
  //## end CVect3::DotProd%1018547513.body
}

inline float CVect3::Module ()
{
  //## begin CVect3::Module%1018547514.body preserve=yes
	return( MATH_Common::fSqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]) );
  //## end CVect3::Module%1018547514.body
}

inline float CVect3::SqModule ()
{
  //## begin CVect3::SqModule%1018547515.body preserve=yes
	return (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
  //## end CVect3::SqModule%1018547515.body
}

inline void CVect3::Normalize ()
{
  //## begin CVect3::Normalize%1018547516.body preserve=yes
	static float m;
	
	m = Module();
	if (m==1) return;

	if (m)
    {
    	m = 1.0f/m;

    	v[0]*=m;
    	v[1]*=m;
    	v[2]*=m;
    }
    else
    {
        // v[0] = MMath_Sgn(v[0])*MMATH_INFINITE;
        v[0] = MATH_Common::fSign(v[0])*1000;
        v[1] = v[0];
        v[2] = v[0];
    }
  //## end CVect3::Normalize%1018547516.body
}

inline void CVect3::Interpolate (CVect3& _roA, CVect3& _roB, float _fFact)
{
  //## begin CVect3::Interpolate%1018547517.body preserve=yes
/*
	// x = a*(1-f) + b*f   =>   x = a -a*f + b*f    =>	x = a + (b-a)*f

	float *va = a.v;
	float *vb = b.v;
	float *vc = v;

	*vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
	*vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
	*vc  = *va+(*vb - *va)*Factor;
*/
	v[0] = _roA.v[0] + (_roB.v[0] - _roA.v[0])*_fFact;
	v[1] = _roA.v[1] + (_roB.v[1] - _roA.v[1])*_fFact;
	v[2] = _roA.v[2] + (_roB.v[2] - _roA.v[2])*_fFact;
  //## end CVect3::Interpolate%1018547517.body
}

inline float CVect3::Distance (CVect3& _roPnt)
{
  //## begin CVect3::Distance%1018547518.body preserve=yes
	return (MATH_Common::fSqrt(SqDistance(_roPnt)) );
  //## end CVect3::Distance%1018547518.body
}

inline float CVect3::SqDistance (CVect3& _roPnt)
{
  //## begin CVect3::SqDistance%1018547519.body preserve=yes
	static CVect3 VAux;

    VAux.V3(v[0],v[1],v[2]);
    VAux.Sub (_roPnt);
	return ( VAux.SqModule() );
  //## end CVect3::SqDistance%1018547519.body
}

inline bool CVect3::Inside (CVect3& _roMax, CVect3& _roMin)
{
  //## begin CVect3::Inside%1018547520.body preserve=yes
/*
	//---------------------------------------------------------------------------
	inline float _FFabs(float a)
	{	
		*((unsigned int *)&a) &= 0x7fffffff;	
		return(a);
	}

	return ( (
			  (_FFabs(Max.v[0] - v[0]) + _FFabs(v[0] - Min.v[0]) + 
			   _FFabs(Max.v[1] - v[1]) + _FFabs(v[1] - Min.v[1]) +
			   _FFabs(Max.v[2] - v[2]) + _FFabs(v[2] - Min.v[2])) -
			 
			 (_FFabs(Max.v[0] - Min.v[0]) +
			  _FFabs(Max.v[1] - Min.v[1]) +
			  _FFabs(Max.v[2] - Min.v[2]))
			  )

			  == 0.0f
			);
*/
	return(
    	  (v[0] >= _roMin.v[0]) && (v[1] >= _roMin.v[1]) && (v[2] >= _roMin.v[2]) &&
          (v[0] <= _roMax.v[0]) && (v[1] <= _roMax.v[1]) && (v[2] <= _roMax.v[2])
          );

  //## end CVect3::Inside%1018547520.body
}

inline bool CVect3::Equal (CVect3& _roV)
{
  //## begin CVect3::Equal%1018547521.body preserve=yes
	return( (v[0] == _roV.v[0]) && (v[1] == _roV.v[1]) && (v[2] == _roV.v[2]) );
  //## end CVect3::Equal%1018547521.body
}

inline int CVect3::iGetGreaterAxis ()
{
  //## begin CVect3::iGetGreaterAxis%1018547522.body preserve=yes
	float fX = MATH_Common::fAbs(v[0]);
	float fY = MATH_Common::fAbs(v[1]);
	float fZ = MATH_Common::fAbs(v[2]);

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
  //## end CVect3::iGetGreaterAxis%1018547522.body
}

//## begin module%3A9AD9AC01F4.epilog preserve=yes
//## end module%3A9AD9AC01F4.epilog


#endif
