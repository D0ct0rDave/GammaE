//## begin module%3AA256E702BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AA256E702BF.cm

//## begin module%3AA256E702BF.cp preserve=no
//## end module%3AA256E702BF.cp

//## Module: CObject3D_Leaf%3AA256E702BF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Leaf.h

#ifndef CObject3D_Leaf_h
#define CObject3D_Leaf_h 1

//## begin module%3AA256E702BF.additionalIncludes preserve=no
//## end module%3AA256E702BF.additionalIncludes

//## begin module%3AA256E702BF.includes preserve=yes
//## end module%3AA256E702BF.includes

// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3AA256E702BF.additionalDeclarations preserve=yes
//## end module%3AA256E702BF.additionalDeclarations


//## begin CObject3D_Leaf%3AA256E702BF.preface preserve=yes
//## end CObject3D_Leaf%3AA256E702BF.preface

//## Class: CObject3D_Leaf%3AA256E702BF
//## Category: Scene%3AA2567D00C8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AA256E702C0; { -> }

class CObject3D_Leaf : public CObject3D  //## Inherits: <unnamed>%3AA256E702BE
{
  //## begin CObject3D_Leaf%3AA256E702BF.initialDeclarations preserve=yes
  //## end CObject3D_Leaf%3AA256E702BF.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_Leaf();

    //## Destructor (generated)
      virtual ~CObject3D_Leaf();


    //## Other Operations (specified)
      //## Operation: Clear%986154963
      virtual void Clear ();

      //## Operation: poGetBoundVol%983822073
      virtual CGraphBV * poGetBoundVol ();

      //## Operation: ComputeBoundVol%983822074
      virtual void ComputeBoundVol ();

      //## Operation: SetMesh%983822080
      void SetMesh (CMesh *_poMesh);

      //## Operation: poGetMesh%983717868
      virtual CMesh * poGetMesh ();

      //## Operation: SetShader%984437269
      virtual void SetShader (CE3D_Shader *_poShader);

      //## Operation: poGetShader%984437270
      virtual CE3D_Shader* poGetShader ();

      //## Operation: Render%983822077
      virtual void Render ();

    // Data Members for Class Attributes

      //## Attribute: poMesh%3AA256E702C5
      //## begin CObject3D_Leaf::poMesh%3AA256E702C5.attr preserve=no  public: CMesh * {UA} NULL
      CMesh *poMesh;
      //## end CObject3D_Leaf::poMesh%3AA256E702C5.attr

    // Additional Public Declarations
      //## begin CObject3D_Leaf%3AA256E702BF.public preserve=yes
      //## end CObject3D_Leaf%3AA256E702BF.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: poShader%3AA418F6017C
      //## begin CObject3D_Leaf::poShader%3AA418F6017C.attr preserve=no  protected: CE3D_Shader * {UA} NULL
      CE3D_Shader *poShader;
      //## end CObject3D_Leaf::poShader%3AA418F6017C.attr

    // Additional Protected Declarations
      //## begin CObject3D_Leaf%3AA256E702BF.protected preserve=yes
      //## end CObject3D_Leaf%3AA256E702BF.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_Leaf%3AA256E702BF.private preserve=yes
      //## end CObject3D_Leaf%3AA256E702BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_Leaf%3AA256E702BF.implementation preserve=yes
      //## end CObject3D_Leaf%3AA256E702BF.implementation

};

//## begin CObject3D_Leaf%3AA256E702BF.postscript preserve=yes
//## end CObject3D_Leaf%3AA256E702BF.postscript

// Class CObject3D_Leaf 


//## Other Operations (inline)
inline void CObject3D_Leaf::SetShader (CE3D_Shader *_poShader)
{
  //## begin CObject3D_Leaf::SetShader%984437269.body preserve=yes
	poShader = _poShader;
  //## end CObject3D_Leaf::SetShader%984437269.body
}

inline CE3D_Shader* CObject3D_Leaf::poGetShader ()
{
  //## begin CObject3D_Leaf::poGetShader%984437270.body preserve=yes
	return(poShader);
  //## end CObject3D_Leaf::poGetShader%984437270.body
}

//## begin module%3AA256E702BF.epilog preserve=yes
//## end module%3AA256E702BF.epilog


#endif
