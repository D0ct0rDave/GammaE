//## begin module%3B9E18660043.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9E18660043.cm

//## begin module%3B9E18660043.cp preserve=no
//## end module%3B9E18660043.cp

//## Module: CObject3D_AnimTransf%3B9E18660043; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimTransf.h

#ifndef CObject3D_AnimTransf_h
#define CObject3D_AnimTransf_h 1

//## begin module%3B9E18660043.additionalIncludes preserve=no
//## end module%3B9E18660043.additionalIncludes

//## begin module%3B9E18660043.includes preserve=yes
//## end module%3B9E18660043.includes

// CObject3D_AnimGen
#include "Scene\Animation\CObject3D_AnimGen.h"
//## begin module%3B9E18660043.additionalDeclarations preserve=yes
//## end module%3B9E18660043.additionalDeclarations


//## begin CObject3D_AnimTransf%3B9E18660043.preface preserve=yes
//## end CObject3D_AnimTransf%3B9E18660043.preface

//## Class: CObject3D_AnimTransf%3B9E18660043
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_AnimTransf : public CObject3D_AnimGen  //## Inherits: <unnamed>%3B9E19660132
{
  //## begin CObject3D_AnimTransf%3B9E18660043.initialDeclarations preserve=yes
  //## end CObject3D_AnimTransf%3B9E18660043.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimTransf();

    //## Destructor (generated)
      virtual ~CObject3D_AnimTransf();


    //## Other Operations (specified)
      //## Operation: CreateStates%1000332374
      void CreateStates (int _iNumStates);

      //## Operation: poGetBoundVol%1000205759
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1000205760
      virtual void ComputeBoundVol ();

      //## Operation: Render%1000205761
      virtual void Render ();

      //## Operation: SetAnimState%1000245732
      virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor);

      //## Operation: poGetStateBVol%1000479978
      virtual CGraphBV * poGetStateBVol (int _iState);

    // Data Members for Class Attributes

      //## Attribute: pTransStates%3B9EA1200109
      //## begin CObject3D_AnimTransf::pTransStates%3B9EA1200109.attr preserve=no  public: CMatrix4x4 * {UA} NULL
      CMatrix4x4 *pTransStates;
      //## end CObject3D_AnimTransf::pTransStates%3B9EA1200109.attr

    // Additional Public Declarations
      //## begin CObject3D_AnimTransf%3B9E18660043.public preserve=yes
      //## end CObject3D_AnimTransf%3B9E18660043.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_AnimTransf%3B9E18660043.protected preserve=yes
      //## end CObject3D_AnimTransf%3B9E18660043.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Trans%3B9EA1A60134
      //## begin CObject3D_AnimTransf::Trans%3B9EA1A60134.attr preserve=no  private: CMatrix4x4 {UA} 
      CMatrix4x4 Trans;
      //## end CObject3D_AnimTransf::Trans%3B9EA1A60134.attr

    // Additional Private Declarations
      //## begin CObject3D_AnimTransf%3B9E18660043.private preserve=yes
      //## end CObject3D_AnimTransf%3B9E18660043.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimTransf%3B9E18660043.implementation preserve=yes
      //## end CObject3D_AnimTransf%3B9E18660043.implementation

};

//## begin CObject3D_AnimTransf%3B9E18660043.postscript preserve=yes
//## end CObject3D_AnimTransf%3B9E18660043.postscript

// Class CObject3D_AnimTransf 

//## begin module%3B9E18660043.epilog preserve=yes
//## end module%3B9E18660043.epilog


#endif
