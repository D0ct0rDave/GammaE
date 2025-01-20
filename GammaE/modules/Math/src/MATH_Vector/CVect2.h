//## begin module%3A9AD9B10118.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AD9B10118.cm

//## begin module%3A9AD9B10118.cp preserve=no
//## end module%3A9AD9B10118.cp

//## Module: CVect2%3A9AD9B10118; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Vector\CVect2.h

#ifndef CVect2_h
#define CVect2_h 1

//## begin module%3A9AD9B10118.additionalIncludes preserve=no
//## end module%3A9AD9B10118.additionalIncludes

//## begin module%3A9AD9B10118.includes preserve=yes
//## end module%3A9AD9B10118.includes

//## begin module%3A9AD9B10118.additionalDeclarations preserve=yes
//## end module%3A9AD9B10118.additionalDeclarations


//## begin CVect2%3A9AD9B10118.preface preserve=yes
//## end CVect2%3A9AD9B10118.preface

//## Class: CVect2%3A9AD9B10118
//## Category: Math::MATH_Vector%3C275D080385
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2C97290001;MATH_Common { -> }

class CVect2 
{
  //## begin CVect2%3A9AD9B10118.initialDeclarations preserve=yes
  //## end CVect2%3A9AD9B10118.initialDeclarations

  public:
    //## Constructors (generated)
      CVect2();

    //## Constructors (specified)
      //## Operation: CVect2%1020067941
      CVect2 (float _fV0, float _fV1);


    //## Other Operations (specified)
      //## Operation: V2%1009552670
      void V2 (float _fV0, float _fV1);

      //## Operation: Assign%1009552693
      void Assign (CVect2& _roV);

      //## Operation: SetU%1009552671
      void SetU (float _fU);

      //## Operation: SetV%1009552672
      void SetV (float _fV);

      //## Operation: U%1009552673
      float U ();

      //## Operation: V%1009552674
      float V ();

      //## Operation: X%1009552675
      float X ();

      //## Operation: Y%1009552676
      float Y ();

      //## Operation: Add%1009552677
      void Add (CVect2& _roV);

      //## Operation: Add%1009552678
      void Add (float _fX, float _fY);

      //## Operation: Sub%1009552679
      void Sub (CVect2& _roV);

      //## Operation: Sub%1009552680
      void Sub (float _fX, float _fY);

      //## Operation: Mult%1009552681
      void Mult (CVect2& _roV);

      //## Operation: Mult%1009552682
      void Mult (float _fX, float _fY);

      //## Operation: Scale%1009552683
      void Scale (float _fScale);

      //## Operation: DotProd%1009552684
      float DotProd (CVect2& _roV);

      //## Operation: Module%1009552685
      float Module ();

      //## Operation: SqModule%1009552686
      float SqModule ();

      //## Operation: Normalize%1009552687
      void Normalize ();

      //## Operation: Interpolate%1009552688
      void Interpolate (CVect2& _roA, CVect2& _roB, float _fFact);

      //## Operation: Distance%1009552689
      float Distance (CVect2& _roV);

      //## Operation: SqDistance%1009552690
      float SqDistance (CVect2& _roV);

      //## Operation: Inside%1009552691
      bool Inside (CVect2& _roMax, CVect2& _roMin);

      //## Operation: Equal%1009552692
      bool Equal (CVect2& _roV);

    // Data Members for Class Attributes

      //## Attribute: v%3C2C93B70229
      //## begin CVect2::v%3C2C93B70229.attr preserve=no  public: float[2] {UA} 
      float v[2];
      //## end CVect2::v%3C2C93B70229.attr

    // Additional Public Declarations
      //## begin CVect2%3A9AD9B10118.public preserve=yes
      //## end CVect2%3A9AD9B10118.public

  protected:
    // Additional Protected Declarations
      //## begin CVect2%3A9AD9B10118.protected preserve=yes
      //## end CVect2%3A9AD9B10118.protected

  private:
    // Additional Private Declarations
      //## begin CVect2%3A9AD9B10118.private preserve=yes
      //## end CVect2%3A9AD9B10118.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CVect2%3A9AD9B10118.implementation preserve=yes
      //## end CVect2%3A9AD9B10118.implementation

};

//## begin CVect2%3A9AD9B10118.postscript preserve=yes
//## end CVect2%3A9AD9B10118.postscript

// Class CVect2 

inline CVect2::CVect2 (float _fV0, float _fV1)
  //## begin CVect2::CVect2%1020067941.hasinit preserve=no
  //## end CVect2::CVect2%1020067941.hasinit
  //## begin CVect2::CVect2%1020067941.initialization preserve=yes
  //## end CVect2::CVect2%1020067941.initialization
{
  //## begin CVect2::CVect2%1020067941.body preserve=yes
	v[0] = _fV0;
	v[1] = _fV1;
  //## end CVect2::CVect2%1020067941.body
}



//## Other Operations (inline)
inline void CVect2::V2 (float _fV0, float _fV1)
{
  //## begin CVect2::V2%1009552670.body preserve=yes
	v[0] = _fV0;
	v[1] = _fV1;
  //## end CVect2::V2%1009552670.body
}

inline void CVect2::Assign (CVect2& _roV)
{
  //## begin CVect2::Assign%1009552693.body preserve=yes
	v[0] = _roV.v[0];
	v[1] = _roV.v[1];
  //## end CVect2::Assign%1009552693.body
}

inline void CVect2::SetU (float _fU)
{
  //## begin CVect2::SetU%1009552671.body preserve=yes
	v[0] = _fU;	
  //## end CVect2::SetU%1009552671.body
}

inline void CVect2::SetV (float _fV)
{
  //## begin CVect2::SetV%1009552672.body preserve=yes
	v[1] = _fV;
  //## end CVect2::SetV%1009552672.body
}

inline float CVect2::U ()
{
  //## begin CVect2::U%1009552673.body preserve=yes
	return(v[0]);
  //## end CVect2::U%1009552673.body
}

inline float CVect2::V ()
{
  //## begin CVect2::V%1009552674.body preserve=yes
	return(v[1]);
  //## end CVect2::V%1009552674.body
}

inline float CVect2::X ()
{
  //## begin CVect2::X%1009552675.body preserve=yes
	return(v[0]);
  //## end CVect2::X%1009552675.body
}

inline float CVect2::Y ()
{
  //## begin CVect2::Y%1009552676.body preserve=yes
	return(v[1]);
  //## end CVect2::Y%1009552676.body
}

inline void CVect2::Add (CVect2& _roV)
{
  //## begin CVect2::Add%1009552677.body preserve=yes
	v[0] += _roV.v[0];
	v[1] += _roV.v[1];
  //## end CVect2::Add%1009552677.body
}

inline void CVect2::Add (float _fX, float _fY)
{
  //## begin CVect2::Add%1009552678.body preserve=yes
	v[0] += _fX;
	v[1] += _fY;
  //## end CVect2::Add%1009552678.body
}

inline void CVect2::Sub (CVect2& _roV)
{
  //## begin CVect2::Sub%1009552679.body preserve=yes
	v[0] -= _roV.v[0];
	v[1] -= _roV.v[1];
  //## end CVect2::Sub%1009552679.body
}

inline void CVect2::Sub (float _fX, float _fY)
{
  //## begin CVect2::Sub%1009552680.body preserve=yes
	v[0] -= _fX;
	v[1] -= _fY;
  //## end CVect2::Sub%1009552680.body
}

inline void CVect2::Mult (CVect2& _roV)
{
  //## begin CVect2::Mult%1009552681.body preserve=yes
  	v[0] *= _roV.v[0];
	v[1] *= _roV.v[1];
  //## end CVect2::Mult%1009552681.body
}

inline void CVect2::Mult (float _fX, float _fY)
{
  //## begin CVect2::Mult%1009552682.body preserve=yes
  	v[0] *= _fX;
	v[1] *= _fY;
  //## end CVect2::Mult%1009552682.body
}

inline void CVect2::Scale (float _fScale)
{
  //## begin CVect2::Scale%1009552683.body preserve=yes
	v[0] *= _fScale;
	v[1] *= _fScale;
  //## end CVect2::Scale%1009552683.body
}

inline float CVect2::DotProd (CVect2& _roV)
{
  //## begin CVect2::DotProd%1009552684.body preserve=yes
	return (v[0]*_roV.v[0] + v[1]*_roV.v[1]);
  //## end CVect2::DotProd%1009552684.body
}

inline void CVect2::Interpolate (CVect2& _roA, CVect2& _roB, float _fFact)
{
  //## begin CVect2::Interpolate%1009552688.body preserve=yes
  /*
	float *va = a.v;
	float *vb = b.v;
	float *vc = v;
	*vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
	*vc  = *va+(*vb - *va)*Factor;
*/
	v[0] = _roA.v[0] + (_roB.v[0] - _roA.v[0])*_fFact;
	v[1] = _roA.v[1] + (_roB.v[1] - _roA.v[1])*_fFact;	
  //## end CVect2::Interpolate%1009552688.body
}

//## begin module%3A9AD9B10118.epilog preserve=yes
//## end module%3A9AD9B10118.epilog


#endif
