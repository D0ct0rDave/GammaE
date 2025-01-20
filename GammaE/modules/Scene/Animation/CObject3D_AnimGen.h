//## begin module%3B9DFF3A0340.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9DFF3A0340.cm

//## begin module%3B9DFF3A0340.cp preserve=no
//## end module%3B9DFF3A0340.cp

//## Module: CObject3D_AnimGen%3B9DFF3A0340; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimGen.h

#ifndef CObject3D_AnimGen_h
#define CObject3D_AnimGen_h 1

//## begin module%3B9DFF3A0340.additionalIncludes preserve=no
//## end module%3B9DFF3A0340.additionalIncludes

//## begin module%3B9DFF3A0340.includes preserve=yes
//## end module%3B9DFF3A0340.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3B9DFF3A0340.additionalDeclarations preserve=yes
//## end module%3B9DFF3A0340.additionalDeclarations


//## begin CObject3D_AnimGen%3B9DFF3A0340.preface preserve=yes
//## end CObject3D_AnimGen%3B9DFF3A0340.preface

//## Class: CObject3D_AnimGen%3B9DFF3A0340
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_AnimGen : public CObject3D  //## Inherits: <unnamed>%3BA2984B0047
{
  //## begin CObject3D_AnimGen%3B9DFF3A0340.initialDeclarations preserve=yes
  //## end CObject3D_AnimGen%3B9DFF3A0340.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimGen();

    //## Destructor (generated)
      ~CObject3D_AnimGen();


    //## Other Operations (specified)
      //## Operation: SetAnimState%1000205749
      virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor) = 0;

      //## Operation: poGetStateBVol%1000479977
      virtual CGraphBV * poGetStateBVol (int _iState) = 0;

      //## Operation: iGetNumStates%1000933010
      int iGetNumStates ();

      //## Operation: iGetLastFrame%1018897759
      int iGetLastFrame ();

    // Additional Public Declarations
      //## begin CObject3D_AnimGen%3B9DFF3A0340.public preserve=yes
      //## end CObject3D_AnimGen%3B9DFF3A0340.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iNumStates%3BA90E2700C3
      //## begin CObject3D_AnimGen::iNumStates%3BA90E2700C3.attr preserve=no  protected: int {UA} 0
      int iNumStates;
      //## end CObject3D_AnimGen::iNumStates%3BA90E2700C3.attr

      //## Attribute: iLastFrame%3CBB3C2D02F8
      //## begin CObject3D_AnimGen::iLastFrame%3CBB3C2D02F8.attr preserve=no  protected: int {UA} -1
      int iLastFrame;
      //## end CObject3D_AnimGen::iLastFrame%3CBB3C2D02F8.attr

    // Additional Protected Declarations
      //## begin CObject3D_AnimGen%3B9DFF3A0340.protected preserve=yes
      //## end CObject3D_AnimGen%3B9DFF3A0340.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_AnimGen%3B9DFF3A0340.private preserve=yes
      //## end CObject3D_AnimGen%3B9DFF3A0340.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimGen%3B9DFF3A0340.implementation preserve=yes
      //## end CObject3D_AnimGen%3B9DFF3A0340.implementation

};

//## begin CObject3D_AnimGen%3B9DFF3A0340.postscript preserve=yes
//## end CObject3D_AnimGen%3B9DFF3A0340.postscript

// Class CObject3D_AnimGen 


//## Other Operations (inline)
inline int CObject3D_AnimGen::iGetNumStates ()
{
  //## begin CObject3D_AnimGen::iGetNumStates%1000933010.body preserve=yes
	return(iNumStates);
  //## end CObject3D_AnimGen::iGetNumStates%1000933010.body
}

inline int CObject3D_AnimGen::iGetLastFrame ()
{
  //## begin CObject3D_AnimGen::iGetLastFrame%1018897759.body preserve=yes
  //## end CObject3D_AnimGen::iGetLastFrame%1018897759.body
}

//## begin module%3B9DFF3A0340.epilog preserve=yes
//## end module%3B9DFF3A0340.epilog


#endif
