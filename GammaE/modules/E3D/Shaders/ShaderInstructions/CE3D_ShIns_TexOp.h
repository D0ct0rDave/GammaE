//## begin module%3C603FDC0094.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603FDC0094.cm

//## begin module%3C603FDC0094.cp preserve=no
//## end module%3C603FDC0094.cp

//## Module: CE3D_ShIns_TexOp%3C603FDC0094; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_TexOp.h

#ifndef CE3D_ShIns_TexOp_h
#define CE3D_ShIns_TexOp_h 1

//## begin module%3C603FDC0094.additionalIncludes preserve=no
//## end module%3C603FDC0094.additionalIncludes

//## begin module%3C603FDC0094.includes preserve=yes
//## end module%3C603FDC0094.includes

// eShInsTexOp_TypeID
#include "E3D\Shaders\ShaderInstructions\eShInsTexOp_TypeID.h"
// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C603FDC0094.additionalDeclarations preserve=yes
//## end module%3C603FDC0094.additionalDeclarations


//## begin CE3D_ShIns_TexOp%3C603FDC0094.preface preserve=yes
//## end CE3D_ShIns_TexOp%3C603FDC0094.preface

//## Class: CE3D_ShIns_TexOp%3C603FDC0094
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6040B403B6;GammaE_Math { -> }

class CE3D_ShIns_TexOp : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C6040B2001A
{
  //## begin CE3D_ShIns_TexOp%3C603FDC0094.initialDeclarations preserve=yes
  //## end CE3D_ShIns_TexOp%3C603FDC0094.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_TexOp();

    //## Destructor (generated)
      ~CE3D_ShIns_TexOp();

    //## Get and Set Operations for Associations (generated)

      //## Association: E3D::Materials::<unnamed>%3C603FFB026F
      //## Role: CE3D_ShIns_TexOp::eTOpType%3C603FFC0023
      eShInsTexOp_TypeID GeteTOpType ();
      void SeteTOpType (eShInsTexOp_TypeID value);

    // Data Members for Class Attributes

      //## Attribute: poEval%3C6041960068
      //## begin CE3D_ShIns_TexOp::poEval%3C6041960068.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *poEval;
      //## end CE3D_ShIns_TexOp::poEval%3C6041960068.attr

      //## Attribute: poMat%3CBF08F001B3
      //## begin CE3D_ShIns_TexOp::poMat%3CBF08F001B3.attr preserve=no  public: CMatrix4x4 * {UA} NULL
      CMatrix4x4 *poMat;
      //## end CE3D_ShIns_TexOp::poMat%3CBF08F001B3.attr

    // Data Members for Associations

      //## Association: E3D::Materials::<unnamed>%3C603FFB026F
      //## begin CE3D_ShIns_TexOp::eTOpType%3C603FFC0023.role preserve=no  public: eShInsTexOp_TypeID { -> VHAN}
      eShInsTexOp_TypeID eTOpType;
      //## end CE3D_ShIns_TexOp::eTOpType%3C603FFC0023.role

    // Additional Public Declarations
      //## begin CE3D_ShIns_TexOp%3C603FDC0094.public preserve=yes
      //## end CE3D_ShIns_TexOp%3C603FDC0094.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_TexOp%3C603FDC0094.protected preserve=yes
      //## end CE3D_ShIns_TexOp%3C603FDC0094.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_TexOp%3C603FDC0094.private preserve=yes
      //## end CE3D_ShIns_TexOp%3C603FDC0094.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_TexOp%3C603FDC0094.implementation preserve=yes
      //## end CE3D_ShIns_TexOp%3C603FDC0094.implementation

};

//## begin CE3D_ShIns_TexOp%3C603FDC0094.postscript preserve=yes
//## end CE3D_ShIns_TexOp%3C603FDC0094.postscript

// Class CE3D_ShIns_TexOp 

//## Get and Set Operations for Associations (inline)

inline eShInsTexOp_TypeID CE3D_ShIns_TexOp::GeteTOpType ()
{
  //## begin CE3D_ShIns_TexOp::GeteTOpType%3C603FFC0023.get preserve=no
  return eTOpType;
  //## end CE3D_ShIns_TexOp::GeteTOpType%3C603FFC0023.get
}

inline void CE3D_ShIns_TexOp::SeteTOpType (eShInsTexOp_TypeID value)
{
  //## begin CE3D_ShIns_TexOp::SeteTOpType%3C603FFC0023.set preserve=no
  eTOpType = value;
  //## end CE3D_ShIns_TexOp::SeteTOpType%3C603FFC0023.set
}

//## begin module%3C603FDC0094.epilog preserve=yes
//## end module%3C603FDC0094.epilog


#endif
