//## begin module%3C6040C302C7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C6040C302C7.cm

//## begin module%3C6040C302C7.cp preserve=no
//## end module%3C6040C302C7.cp

//## Module: CE3D_ShIns_BlendOp%3C6040C302C7; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_BlendOp.h

#ifndef CE3D_ShIns_BlendOp_h
#define CE3D_ShIns_BlendOp_h 1

//## begin module%3C6040C302C7.additionalIncludes preserve=no
//## end module%3C6040C302C7.additionalIncludes

//## begin module%3C6040C302C7.includes preserve=yes
//## end module%3C6040C302C7.includes

// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
// eShInsBlendOp_TypeID
#include "E3D\Shaders\ShaderInstructions\eShInsBlendOp_TypeID.h"
//## begin module%3C6040C302C7.additionalDeclarations preserve=yes
//## end module%3C6040C302C7.additionalDeclarations


//## begin CE3D_ShIns_BlendOp%3C6040C302C7.preface preserve=yes
//## end CE3D_ShIns_BlendOp%3C6040C302C7.preface

//## Class: CE3D_ShIns_BlendOp%3C6040C302C7
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShIns_BlendOp : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C60417C0219
{
  //## begin CE3D_ShIns_BlendOp%3C6040C302C7.initialDeclarations preserve=yes
  //## end CE3D_ShIns_BlendOp%3C6040C302C7.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_BlendOp();

    //## Destructor (generated)
      ~CE3D_ShIns_BlendOp();

    //## Get and Set Operations for Associations (generated)

      //## Association: E3D::Materials::<unnamed>%3C60413B03D8
      //## Role: CE3D_ShIns_BlendOp::eBOpType%3C60413C01BD
      eShInsBlendOp_TypeID GeteBOpType ();
      void SeteBOpType (eShInsBlendOp_TypeID value);

    // Data Members for Associations

      //## Association: E3D::Materials::<unnamed>%3C60413B03D8
      //## begin CE3D_ShIns_BlendOp::eBOpType%3C60413C01BD.role preserve=no  public: eShInsBlendOp_TypeID { -> VHAN}
      eShInsBlendOp_TypeID eBOpType;
      //## end CE3D_ShIns_BlendOp::eBOpType%3C60413C01BD.role

    // Additional Public Declarations
      //## begin CE3D_ShIns_BlendOp%3C6040C302C7.public preserve=yes
      //## end CE3D_ShIns_BlendOp%3C6040C302C7.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_BlendOp%3C6040C302C7.protected preserve=yes
      //## end CE3D_ShIns_BlendOp%3C6040C302C7.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_BlendOp%3C6040C302C7.private preserve=yes
      //## end CE3D_ShIns_BlendOp%3C6040C302C7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_BlendOp%3C6040C302C7.implementation preserve=yes
      //## end CE3D_ShIns_BlendOp%3C6040C302C7.implementation

};

//## begin CE3D_ShIns_BlendOp%3C6040C302C7.postscript preserve=yes
//## end CE3D_ShIns_BlendOp%3C6040C302C7.postscript

// Class CE3D_ShIns_BlendOp 

//## Get and Set Operations for Associations (inline)

inline eShInsBlendOp_TypeID CE3D_ShIns_BlendOp::GeteBOpType ()
{
  //## begin CE3D_ShIns_BlendOp::GeteBOpType%3C60413C01BD.get preserve=no
  return eBOpType;
  //## end CE3D_ShIns_BlendOp::GeteBOpType%3C60413C01BD.get
}

inline void CE3D_ShIns_BlendOp::SeteBOpType (eShInsBlendOp_TypeID value)
{
  //## begin CE3D_ShIns_BlendOp::SeteBOpType%3C60413C01BD.set preserve=no
  eBOpType = value;
  //## end CE3D_ShIns_BlendOp::SeteBOpType%3C60413C01BD.set
}

//## begin module%3C6040C302C7.epilog preserve=yes
//## end module%3C6040C302C7.epilog


#endif
