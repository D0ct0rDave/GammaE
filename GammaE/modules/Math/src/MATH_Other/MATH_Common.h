//## begin module%3C0C21B2015B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C0C21B2015B.cm

//## begin module%3C0C21B2015B.cp preserve=no
//## end module%3C0C21B2015B.cp

//## Module: MATH_Common%3C0C21B2015B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Other\MATH_Common.h

#ifndef MATH_Common_h
#define MATH_Common_h 1

//## begin module%3C0C21B2015B.additionalIncludes preserve=no
//## end module%3C0C21B2015B.additionalIncludes

//## begin module%3C0C21B2015B.includes preserve=yes
//## end module%3C0C21B2015B.includes

//## begin module%3C0C21B2015B.additionalDeclarations preserve=yes
#define _PI_		  3.1415926535897932384626433832795f
#define _2PI_		  6.283185307179586476925286766558f
#define _PI2_		  1.5707963267948966192313216916395f
#define _PI_OVER_180_ 0.0174532925199432957692369076848833f
#define _180_OVER_PI_ 57.2957795130823208767981548141052f

#define _SQ_(x) ((x)*(x))
#define _P2_(x) ((x)*(x))
#define _P3_(x) ((x)*(x)*(x))
#define _P4_(x) ((x)*(x)*(x)*(x))

#define _EPSILON_ 1e-5f
//## end module%3C0C21B2015B.additionalDeclarations


//## begin MATH_Common%3C0C21B2015B.preface preserve=yes
//## end MATH_Common%3C0C21B2015B.preface

//## Class: MATH_Common%3C0C21B2015B
//## Category: Math::MATH_Other%3C275D6F02F7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class MATH_Common 
{
  //## begin MATH_Common%3C0C21B2015B.initialDeclarations preserve=yes
  //## end MATH_Common%3C0C21B2015B.initialDeclarations

  public:
    //## Constructors (generated)
      MATH_Common();

    //## Destructor (generated)
      ~MATH_Common();


    //## Other Operations (specified)
      //## Operation: fRand%1007421153
      static float fRand ();

      //## Operation: fSqrt%1008711892
      static float fSqrt (float _fValue);

      //## Operation: fAbs%1009321159
      static float fAbs (float _fValue);

      //## Operation: fSign%1009406730
      static float fSign (float _fValue);

      //## Operation: bInRange%1009406731
      static bool bInRange (float _fValue, float _fMin, float _fMax);

      //## Operation: bEqualF%1021629965
      static bool bEqualF (float _fA, float _fB, float _fEpsilon);

    // Additional Public Declarations
      //## begin MATH_Common%3C0C21B2015B.public preserve=yes
      //## end MATH_Common%3C0C21B2015B.public

  protected:
    // Additional Protected Declarations
      //## begin MATH_Common%3C0C21B2015B.protected preserve=yes
      //## end MATH_Common%3C0C21B2015B.protected

  private:
    // Additional Private Declarations
      //## begin MATH_Common%3C0C21B2015B.private preserve=yes
      //## end MATH_Common%3C0C21B2015B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin MATH_Common%3C0C21B2015B.implementation preserve=yes
      //## end MATH_Common%3C0C21B2015B.implementation

};

//## begin MATH_Common%3C0C21B2015B.postscript preserve=yes
//## end MATH_Common%3C0C21B2015B.postscript

// Class MATH_Common 


//## Other Operations (inline)
inline float MATH_Common::fAbs (float _fValue)
{
  //## begin MATH_Common::fAbs%1009321159.body preserve=yes
	*((unsigned int*)&_fValue) &= 0x7fffffff;
	return(_fValue);
  //## end MATH_Common::fAbs%1009321159.body
}

inline float MATH_Common::fSign (float _fValue)
{
  //## begin MATH_Common::fSign%1009406730.body preserve=yes
	return ( (*((unsigned int*)&_fValue) >> 31)*-2.0f + 1.0f);  
  //## end MATH_Common::fSign%1009406730.body
}

inline bool MATH_Common::bInRange (float _fValue, float _fMin, float _fMax)
{
  //## begin MATH_Common::bInRange%1009406731.body preserve=yes
	return ((_fValue >= _fMin) && (_fValue<=_fMax));
  //## end MATH_Common::bInRange%1009406731.body
}

inline bool MATH_Common::bEqualF (float _fA, float _fB, float _fEpsilon)
{
  //## begin MATH_Common::bEqualF%1021629965.body preserve=yes
	return ( MATH_Common::fAbs(_fA - _fB) < _fEpsilon );
  //## end MATH_Common::bEqualF%1021629965.body
}

//## begin module%3C0C21B2015B.epilog preserve=yes
//## end module%3C0C21B2015B.epilog


#endif
