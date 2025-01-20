//## begin module%3A9AD9B7032A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD9B7032A.cm

//## begin module%3A9AD9B7032A.cp preserve=no
//## end module%3A9AD9B7032A.cp

//## Module: CVect4%3A9AD9B7032A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Vector\CVect4.h

#ifndef CVect4_h
#define CVect4_h 1

//## begin module%3A9AD9B7032A.additionalIncludes preserve=no
//## end module%3A9AD9B7032A.additionalIncludes

//## begin module%3A9AD9B7032A.includes preserve=yes
//## end module%3A9AD9B7032A.includes

//## begin module%3A9AD9B7032A.additionalDeclarations preserve=yes
//## end module%3A9AD9B7032A.additionalDeclarations


//## begin CVect4%3A9AD9B7032A.preface preserve=yes
//## end CVect4%3A9AD9B7032A.preface

//## Class: CVect4%3A9AD9B7032A
//## Category: Math::MATH_Vector%3C275D080385
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2C97260038;MATH_Common { -> }

class CVect4 
{
  //## begin CVect4%3A9AD9B7032A.initialDeclarations preserve=yes
  //## end CVect4%3A9AD9B7032A.initialDeclarations

  public:
    //## Constructors (generated)
      CVect4();

    //## Constructors (specified)
      //## Operation: CVect4%1020067942
      CVect4 (float _fV0, float _fV1, float _fV2, float _fV3);


    //## Other Operations (specified)
      //## Operation: V4%1009552659
      void V4 (float _fV0, float _fV1, float _fV2, float _fV3);

      //## Operation: Assign%1009552660
      void Assign (CVect4& _roV);

      //## Operation: Add%1009552661
      void Add (CVect4& _roV);

      //## Operation: Add%1009552662
      void Add (float _fX, float _fY, float _fZ, float _fW);

      //## Operation: Sub%1009552663
      void Sub (CVect4& _roV);

      //## Operation: Sub%1009552664
      void Sub (float _fX, float _fY, float _fZ, float _fW);

      //## Operation: Interpolate%1009552665
      void Interpolate (CVect4& _roA, CVect4& _roB, float _fFact);

      //## Operation: X%1009552666
      float X ();

      //## Operation: Y%1009552667
      float Y ();

      //## Operation: Z%1009552668
      float Z ();

      //## Operation: W%1009552669
      float W ();

    // Data Members for Class Attributes

      //## Attribute: v%3C2C90EC025D
      //## begin CVect4::v%3C2C90EC025D.attr preserve=no  public: float[4] {UA} 
      float v[4];
      //## end CVect4::v%3C2C90EC025D.attr

    // Additional Public Declarations
      //## begin CVect4%3A9AD9B7032A.public preserve=yes
      //## end CVect4%3A9AD9B7032A.public

  protected:
    // Additional Protected Declarations
      //## begin CVect4%3A9AD9B7032A.protected preserve=yes
      //## end CVect4%3A9AD9B7032A.protected

  private:
    // Additional Private Declarations
      //## begin CVect4%3A9AD9B7032A.private preserve=yes
      //## end CVect4%3A9AD9B7032A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CVect4%3A9AD9B7032A.implementation preserve=yes
      //## end CVect4%3A9AD9B7032A.implementation

};

//## begin CVect4%3A9AD9B7032A.postscript preserve=yes
//## end CVect4%3A9AD9B7032A.postscript

// Class CVect4 

inline CVect4::CVect4 (float _fV0, float _fV1, float _fV2, float _fV3)
  //## begin CVect4::CVect4%1020067942.hasinit preserve=no
  //## end CVect4::CVect4%1020067942.hasinit
  //## begin CVect4::CVect4%1020067942.initialization preserve=yes
  //## end CVect4::CVect4%1020067942.initialization
{
  //## begin CVect4::CVect4%1020067942.body preserve=yes
	v[0] = _fV0;
	v[1] = _fV1;
	v[2] = _fV2;
	v[3] = _fV3;
  //## end CVect4::CVect4%1020067942.body
}



//## Other Operations (inline)
inline void CVect4::V4 (float _fV0, float _fV1, float _fV2, float _fV3)
{
  //## begin CVect4::V4%1009552659.body preserve=yes
  	v[0] = _fV0;
	v[1] = _fV1;
	v[2] = _fV2;
	v[3] = _fV3;
  //## end CVect4::V4%1009552659.body
}

inline void CVect4::Assign (CVect4& _roV)
{
  //## begin CVect4::Assign%1009552660.body preserve=yes
	v[0] = _roV.v[0];
	v[1] = _roV.v[1];
	v[2] = _roV.v[2];
	v[3] = _roV.v[3];
  //## end CVect4::Assign%1009552660.body
}

inline void CVect4::Add (CVect4& _roV)
{
  //## begin CVect4::Add%1009552661.body preserve=yes
	v[0] += _roV.v[0];
	v[1] += _roV.v[1];
	v[2] += _roV.v[2];
	v[3] += _roV.v[3];
  //## end CVect4::Add%1009552661.body
}

inline void CVect4::Add (float _fX, float _fY, float _fZ, float _fW)
{
  //## begin CVect4::Add%1009552662.body preserve=yes
    v[0] += _fX;
	v[1] += _fY;
	v[2] += _fZ;
	v[3] += _fW;
  //## end CVect4::Add%1009552662.body
}

inline void CVect4::Sub (CVect4& _roV)
{
  //## begin CVect4::Sub%1009552663.body preserve=yes
	v[0] -= _roV.v[0];
	v[1] -= _roV.v[1];
	v[2] -= _roV.v[2];
	v[3] -= _roV.v[3];
  //## end CVect4::Sub%1009552663.body
}

inline void CVect4::Sub (float _fX, float _fY, float _fZ, float _fW)
{
  //## begin CVect4::Sub%1009552664.body preserve=yes
	v[0] -= _fX;
	v[1] -= _fY;
	v[2] -= _fZ;
	v[3] -= _fW;
  //## end CVect4::Sub%1009552664.body
}

inline void CVect4::Interpolate (CVect4& _roA, CVect4& _roB, float _fFact)
{
  //## begin CVect4::Interpolate%1009552665.body preserve=yes
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
	v[3] = _roA.v[3] + (_roB.v[3] - _roA.v[3])*_fFact;
  //## end CVect4::Interpolate%1009552665.body
}

inline float CVect4::X ()
{
  //## begin CVect4::X%1009552666.body preserve=yes
	return(v[0]);
  //## end CVect4::X%1009552666.body
}

inline float CVect4::Y ()
{
  //## begin CVect4::Y%1009552667.body preserve=yes
	return(v[1]);
  //## end CVect4::Y%1009552667.body
}

inline float CVect4::Z ()
{
  //## begin CVect4::Z%1009552668.body preserve=yes
	return(v[2]);
  //## end CVect4::Z%1009552668.body
}

inline float CVect4::W ()
{
  //## begin CVect4::W%1009552669.body preserve=yes
	return(v[3]);
  //## end CVect4::W%1009552669.body
}

//## begin module%3A9AD9B7032A.epilog preserve=yes
//## end module%3A9AD9B7032A.epilog


#endif
