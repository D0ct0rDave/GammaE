//## begin module%3B9E7C9F013E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9E7C9F013E.cm

//## begin module%3B9E7C9F013E.cp preserve=no
//## end module%3B9E7C9F013E.cp

//## Module: CQuaternion%3B9E7C9F013E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Quaternion\CQuaternion.h

#ifndef CQuaternion_h
#define CQuaternion_h 1

//## begin module%3B9E7C9F013E.additionalIncludes preserve=no
//## end module%3B9E7C9F013E.additionalIncludes

//## begin module%3B9E7C9F013E.includes preserve=yes
//## end module%3B9E7C9F013E.includes

// CMatrix4x4
#include "Math\MATH_Matrix\CMatrix4x4.h"
// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3B9E7C9F013E.additionalDeclarations preserve=yes
//## end module%3B9E7C9F013E.additionalDeclarations


//## begin CQuaternion%3B9E7C9F013E.preface preserve=yes
//## end CQuaternion%3B9E7C9F013E.preface

//## Class: CQuaternion%3B9E7C9F013E
//## Category: Math::MATH_Quaternion%3C275DC303C0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C275E70036F;CMatrix4x4 { -> }
//## Uses: <unnamed>%3C275E820035;MATH_Common { -> }

class CQuaternion 
{
  //## begin CQuaternion%3B9E7C9F013E.initialDeclarations preserve=yes
  //## end CQuaternion%3B9E7C9F013E.initialDeclarations

  public:
    //## Constructors (generated)
      CQuaternion();


    //## Other Operations (specified)
      //## Operation: Slerp%1000239577
      void Slerp (CQuaternion& _Src, CQuaternion& _Dst, float _fFactor);

      //## Operation: ToMatrix%1000239578
      CMatrix4x4 & ToMatrix ();

      //## Operation: FromMatrix%1000239579
      void FromMatrix (CMatrix4x4 &_Matrix);

    // Additional Public Declarations
      //## begin CQuaternion%3B9E7C9F013E.public preserve=yes
      //## end CQuaternion%3B9E7C9F013E.public

  protected:
    // Additional Protected Declarations
      //## begin CQuaternion%3B9E7C9F013E.protected preserve=yes
      //## end CQuaternion%3B9E7C9F013E.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: quat%3B9E7CA502C3
      //## begin CQuaternion::quat%3B9E7CA502C3.attr preserve=no  private: float[4] {UA} 
      float quat[4];
      //## end CQuaternion::quat%3B9E7CA502C3.attr

    // Additional Private Declarations
      //## begin CQuaternion%3B9E7C9F013E.private preserve=yes
      //## end CQuaternion%3B9E7C9F013E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CQuaternion%3B9E7C9F013E.implementation preserve=yes
      //## end CQuaternion%3B9E7C9F013E.implementation

};

//## begin CQuaternion%3B9E7C9F013E.postscript preserve=yes
//## end CQuaternion%3B9E7C9F013E.postscript

// Class CQuaternion 

//## begin module%3B9E7C9F013E.epilog preserve=yes
//## end module%3B9E7C9F013E.epilog


#endif
