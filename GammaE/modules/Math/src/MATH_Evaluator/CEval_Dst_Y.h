//## begin module%3B7FD0D9034F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B7FD0D9034F.cm

//## begin module%3B7FD0D9034F.cp preserve=no
//## end module%3B7FD0D9034F.cp

//## Module: CEval_Dst_Y%3B7FD0D9034F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Evaluator\CEval_Dst_Y.h

#ifndef CEval_Dst_Y_h
#define CEval_Dst_Y_h 1

//## begin module%3B7FD0D9034F.additionalIncludes preserve=no
//## end module%3B7FD0D9034F.additionalIncludes

//## begin module%3B7FD0D9034F.includes preserve=yes
//## end module%3B7FD0D9034F.includes

// CEvaluator
#include "Math\MATH_Evaluator\CEvaluator.h"
//## begin module%3B7FD0D9034F.additionalDeclarations preserve=yes
//## end module%3B7FD0D9034F.additionalDeclarations


//## begin CEval_Dst_Y%3B7FD0D9034F.preface preserve=yes
//## end CEval_Dst_Y%3B7FD0D9034F.preface

//## Class: CEval_Dst_Y%3B7FD0D9034F
//## Category: Math::MATH_Evaluator%3B7FD0D4034D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CEval_Dst_Y : public CEvaluator  //## Inherits: <unnamed>%3B7FD0D9034E
{
  //## begin CEval_Dst_Y%3B7FD0D9034F.initialDeclarations preserve=yes
  //## end CEval_Dst_Y%3B7FD0D9034F.initialDeclarations

  public:
    //## Constructors (generated)
      CEval_Dst_Y();

    //## Destructor (generated)
      ~CEval_Dst_Y();


    //## Other Operations (specified)
      //## Operation: GetValue%998231894
      virtual float GetValue ();

      //## Operation: SetY%998231895
      void SetY (float Y);

    // Additional Public Declarations
      //## begin CEval_Dst_Y%3B7FD0D9034F.public preserve=yes
      //## end CEval_Dst_Y%3B7FD0D9034F.public

  protected:
    // Additional Protected Declarations
      //## begin CEval_Dst_Y%3B7FD0D9034F.protected preserve=yes
      //## end CEval_Dst_Y%3B7FD0D9034F.protected

  private:
    // Additional Private Declarations
      //## begin CEval_Dst_Y%3B7FD0D9034F.private preserve=yes
      //## end CEval_Dst_Y%3B7FD0D9034F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CEval_Dst_Y%3B7FD0D9034F.implementation preserve=yes
      //## end CEval_Dst_Y%3B7FD0D9034F.implementation

};

//## begin CEval_Dst_Y%3B7FD0D9034F.postscript preserve=yes
//## end CEval_Dst_Y%3B7FD0D9034F.postscript

// Class CEval_Dst_Y 

//## begin module%3B7FD0D9034F.epilog preserve=yes
//## end module%3B7FD0D9034F.epilog


#endif
