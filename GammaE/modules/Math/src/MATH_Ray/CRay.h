//## begin module%3B7FCEBC0085.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FCEBC0085.cm

//## begin module%3B7FCEBC0085.cp preserve=no
//## end module%3B7FCEBC0085.cp

//## Module: CRay%3B7FCEBC0085; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Ray\CRay.h

#ifndef CRay_h
#define CRay_h 1

//## begin module%3B7FCEBC0085.additionalIncludes preserve=no
//## end module%3B7FCEBC0085.additionalIncludes

//## begin module%3B7FCEBC0085.includes preserve=yes
//## end module%3B7FCEBC0085.includes

// CVect3
#include "Math\MATH_Vector\CVect3.h"
// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3B7FCEBC0085.additionalDeclarations preserve=yes
//## end module%3B7FCEBC0085.additionalDeclarations


//## begin CRay%3B7FCEBC0085.preface preserve=yes
//## end CRay%3B7FCEBC0085.preface

//## Class: CRay%3B7FCEBC0085
//## Category: Math::MATH_Ray%3C275D0200F1
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B7FD02F0101;CVect3 { -> }
//## Uses: <unnamed>%3C2763F201E6;MATH_Common { -> }

class CRay 
{
  //## begin CRay%3B7FCEBC0085.initialDeclarations preserve=yes
  //## end CRay%3B7FCEBC0085.initialDeclarations

  public:
    //## Constructors (generated)
      CRay();


    //## Other Operations (specified)
      //## Operation: InitFromFields%998231879
      void InitFromFields (CVect3& _Origin, CVect3& _Dir);

      //## Operation: InitFromPoints%998231880
      void InitFromPoints (CVect3& _Origin, CVect3& _End);

      //## Operation: ProjectPoint%1007685159
      CVect3 ProjectPoint (CVect3& _Point);

      //## Operation: GetDistanceToPoint%1007685160
      float GetDistanceToPoint (CVect3& _Point);

      //## Operation: GetSqDistanceToPoint%1008804496
      float GetSqDistanceToPoint (CVect3& _Point);

      //## Operation: GetPerpendicular%1008804497
      CVect3 GetPerpendicular (CVect3& _Point);

    // Data Members for Class Attributes

      //## Attribute: Origin%3B7FCEDA01A1
      //## begin CRay::Origin%3B7FCEDA01A1.attr preserve=no  public: CVect3 {UA} 
      CVect3 Origin;
      //## end CRay::Origin%3B7FCEDA01A1.attr

      //## Attribute: Dir%3B7FCEE803B4
      //## begin CRay::Dir%3B7FCEE803B4.attr preserve=no  public: CVect3 {UA} 
      CVect3 Dir;
      //## end CRay::Dir%3B7FCEE803B4.attr

    // Additional Public Declarations
      //## begin CRay%3B7FCEBC0085.public preserve=yes
      //## end CRay%3B7FCEBC0085.public

  protected:
    // Additional Protected Declarations
      //## begin CRay%3B7FCEBC0085.protected preserve=yes
      //## end CRay%3B7FCEBC0085.protected

  private:
    // Additional Private Declarations
      //## begin CRay%3B7FCEBC0085.private preserve=yes
      //## end CRay%3B7FCEBC0085.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CRay%3B7FCEBC0085.implementation preserve=yes
      //## end CRay%3B7FCEBC0085.implementation

};

//## begin CRay%3B7FCEBC0085.postscript preserve=yes
//## end CRay%3B7FCEBC0085.postscript

// Class CRay 


//## Other Operations (inline)
inline void CRay::InitFromFields (CVect3& _Origin, CVect3& _Dir)
{
  //## begin CRay::InitFromFields%998231879.body preserve=yes
  	Origin.Assign(_Origin);
	Dir.Assign(_Dir);
  //## end CRay::InitFromFields%998231879.body
}

inline void CRay::InitFromPoints (CVect3& _Origin, CVect3& _End)
{
  //## begin CRay::InitFromPoints%998231880.body preserve=yes
  	Origin.Assign(_Origin);	
	
	Dir.Assign(_End);
	Dir.Sub   (_Origin);
  //## end CRay::InitFromPoints%998231880.body
}

//## begin module%3B7FCEBC0085.epilog preserve=yes
//## end module%3B7FCEBC0085.epilog


#endif
