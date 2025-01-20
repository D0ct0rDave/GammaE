//## begin module%3C1E70900364.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1E70900364.cm

//## begin module%3C1E70900364.cp preserve=no
//## end module%3C1E70900364.cp

//## Module: CTriangle%3C1E70900364; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Triangle\CTriangle.h

#ifndef CTriangle_h
#define CTriangle_h 1

//## begin module%3C1E70900364.additionalIncludes preserve=no
//## end module%3C1E70900364.additionalIncludes

//## begin module%3C1E70900364.includes preserve=yes
//## end module%3C1E70900364.includes

// CVect3
#include "Math\MATH_Vector\CVect3.h"
//## begin module%3C1E70900364.additionalDeclarations preserve=yes
//## end module%3C1E70900364.additionalDeclarations


//## begin CTriangle%3C1E70900364.preface preserve=yes
//## end CTriangle%3C1E70900364.preface

//## Class: CTriangle%3C1E70900364
//## Category: Math::MATH_Triangle%3C275D160104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1E78DA0008;CVect3 { -> }

class CTriangle 
{
  //## begin CTriangle%3C1E70900364.initialDeclarations preserve=yes
  //## end CTriangle%3C1E70900364.initialDeclarations

  public:
    //## Constructors (generated)
      CTriangle();


    //## Other Operations (specified)
      //## Operation: Init%1008626802
      void Init (CVect3* _pVXs);

      //## Operation: Init%1008626803
      void Init (CVect3* _pVXs, CVect3& _Normal);

      //## Operation: ComputeSegs%1009213639
      void ComputeSegs ();

      //## Operation: ComputeAxis%1009321152
      void ComputeAxis ();

      //## Operation: ComputeAll%1009321153
      void ComputeAll ();

    // Data Members for Class Attributes

      //## Attribute: Normal%3C1E709A011A
      //## begin CTriangle::Normal%3C1E709A011A.attr preserve=no  public: CVect3 {UA} 
      CVect3 Normal;
      //## end CTriangle::Normal%3C1E709A011A.attr

      //## Attribute: VXs%3C1E70A302FD
      //## begin CTriangle::VXs%3C1E70A302FD.attr preserve=no  public: CVect3 * {UA} NULL
      CVect3 *VXs;
      //## end CTriangle::VXs%3C1E70A302FD.attr

      //## Attribute: s0%3C275D1B0147
      //## begin CTriangle::s0%3C275D1B0147.attr preserve=no  public: CVect3 {UA} 
      CVect3 s0;
      //## end CTriangle::s0%3C275D1B0147.attr

      //## Attribute: s1%3C275D2201AC
      //## begin CTriangle::s1%3C275D2201AC.attr preserve=no  public: CVect3 {UA} 
      CVect3 s1;
      //## end CTriangle::s1%3C275D2201AC.attr

      //## Attribute: s2%3C275D2500B6
      //## begin CTriangle::s2%3C275D2500B6.attr preserve=no  public: CVect3 {UA} 
      CVect3 s2;
      //## end CTriangle::s2%3C275D2500B6.attr

      //## Attribute: e1%3C2904AB0325
      //## begin CTriangle::e1%3C2904AB0325.attr preserve=no  public: CVect3 {UA} 
      CVect3 e1;
      //## end CTriangle::e1%3C2904AB0325.attr

      //## Attribute: e2%3C2904B0019B
      //## begin CTriangle::e2%3C2904B0019B.attr preserve=no  public: CVect3 {UA} 
      CVect3 e2;
      //## end CTriangle::e2%3C2904B0019B.attr

    // Additional Public Declarations
      //## begin CTriangle%3C1E70900364.public preserve=yes
      //## end CTriangle%3C1E70900364.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: bSelfData%3C1E71800297
      //## begin CTriangle::bSelfData%3C1E71800297.attr preserve=no  protected: bool {UA} 
      bool bSelfData;
      //## end CTriangle::bSelfData%3C1E71800297.attr

    // Additional Protected Declarations
      //## begin CTriangle%3C1E70900364.protected preserve=yes
      //## end CTriangle%3C1E70900364.protected

  private:
    // Additional Private Declarations
      //## begin CTriangle%3C1E70900364.private preserve=yes
      //## end CTriangle%3C1E70900364.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTriangle%3C1E70900364.implementation preserve=yes
      //## end CTriangle%3C1E70900364.implementation

};

//## begin CTriangle%3C1E70900364.postscript preserve=yes
//## end CTriangle%3C1E70900364.postscript

// Class CTriangle 


//## Other Operations (inline)
inline void CTriangle::Init (CVect3* _pVXs)
{
  //## begin CTriangle::Init%1008626802.body preserve=yes
	VXs = _pVXs;
	Normal.Normal(VXs[0],VXs[1],VXs[2]);
  //## end CTriangle::Init%1008626802.body
}

inline void CTriangle::Init (CVect3* _pVXs, CVect3& _Normal)
{
  //## begin CTriangle::Init%1008626803.body preserve=yes
	VXs = _pVXs;
	Normal.Assign(_Normal);
  //## end CTriangle::Init%1008626803.body
}

inline void CTriangle::ComputeSegs ()
{
  //## begin CTriangle::ComputeSegs%1009213639.body preserve=yes
    s0.Assign(VXs[0]);	s0.Sub(VXs[2]);
	s1.Assign(VXs[1]);	s1.Sub(VXs[0]);
	s2.Assign(VXs[2]);	s2.Sub(VXs[1]);
  //## end CTriangle::ComputeSegs%1009213639.body
}

inline void CTriangle::ComputeAxis ()
{
  //## begin CTriangle::ComputeAxis%1009321152.body preserve=yes
	e1.Assign(VXs[1]);	e1.Sub(VXs[0]);	
	e2.Assign(VXs[2]);	e2.Sub(VXs[0]);
  //## end CTriangle::ComputeAxis%1009321152.body
}

inline void CTriangle::ComputeAll ()
{
  //## begin CTriangle::ComputeAll%1009321153.body preserve=yes
    ComputeSegs ();
    ComputeAxis ();
  //## end CTriangle::ComputeAll%1009321153.body
}

//## begin module%3C1E70900364.epilog preserve=yes
//## end module%3C1E70900364.epilog


#endif
