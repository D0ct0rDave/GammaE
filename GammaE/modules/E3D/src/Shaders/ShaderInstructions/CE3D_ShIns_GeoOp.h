//## begin module%3C603E0E0216.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603E0E0216.cm

//## begin module%3C603E0E0216.cp preserve=no
//## end module%3C603E0E0216.cp

//## Module: CE3D_ShIns_GeoOp%3C603E0E0216; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_GeoOp.h

#ifndef CE3D_ShIns_GeoOp_h
#define CE3D_ShIns_GeoOp_h 1

//## begin module%3C603E0E0216.additionalIncludes preserve=no
//## end module%3C603E0E0216.additionalIncludes

//## begin module%3C603E0E0216.includes preserve=yes
//## end module%3C603E0E0216.includes

// eShInsGeoOp_TypeID
#include "E3D\Shaders\ShaderInstructions\eShInsGeoOp_TypeID.h"
// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C603E0E0216.additionalDeclarations preserve=yes
//## end module%3C603E0E0216.additionalDeclarations


//## begin CE3D_ShIns_GeoOp%3C603E0E0216.preface preserve=yes
//## end CE3D_ShIns_GeoOp%3C603E0E0216.preface

//## Class: CE3D_ShIns_GeoOp%3C603E0E0216
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C603E4C00CB;GammaE_Math { -> }

class CE3D_ShIns_GeoOp : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C603FD202E9
{
  //## begin CE3D_ShIns_GeoOp%3C603E0E0216.initialDeclarations preserve=yes
  //## end CE3D_ShIns_GeoOp%3C603E0E0216.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_GeoOp();

    //## Destructor (generated)
      ~CE3D_ShIns_GeoOp();

    //## Get and Set Operations for Associations (generated)

      //## Association: E3D::Materials::<unnamed>%3C603F330196
      //## Role: CE3D_ShIns_GeoOp::eGOpType%3C603F330291
      eShInsGeoOp_TypeID GeteGOpType ();
      void SeteGOpType (eShInsGeoOp_TypeID value);

    // Data Members for Class Attributes

      //## Attribute: poEval%3C6041880112
      //## begin CE3D_ShIns_GeoOp::poEval%3C6041880112.attr preserve=no  public: CEvaluator * {UA} NULL
      CEvaluator *poEval;
      //## end CE3D_ShIns_GeoOp::poEval%3C6041880112.attr

    // Data Members for Associations

      //## Association: E3D::Materials::<unnamed>%3C603F330196
      //## begin CE3D_ShIns_GeoOp::eGOpType%3C603F330291.role preserve=no  public: eShInsGeoOp_TypeID { -> VHAN}
      eShInsGeoOp_TypeID eGOpType;
      //## end CE3D_ShIns_GeoOp::eGOpType%3C603F330291.role

    // Additional Public Declarations
      //## begin CE3D_ShIns_GeoOp%3C603E0E0216.public preserve=yes
      //## end CE3D_ShIns_GeoOp%3C603E0E0216.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_GeoOp%3C603E0E0216.protected preserve=yes
      //## end CE3D_ShIns_GeoOp%3C603E0E0216.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_GeoOp%3C603E0E0216.private preserve=yes
      //## end CE3D_ShIns_GeoOp%3C603E0E0216.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_GeoOp%3C603E0E0216.implementation preserve=yes
      //## end CE3D_ShIns_GeoOp%3C603E0E0216.implementation

};

//## begin CE3D_ShIns_GeoOp%3C603E0E0216.postscript preserve=yes
//## end CE3D_ShIns_GeoOp%3C603E0E0216.postscript

// Class CE3D_ShIns_GeoOp 

//## Get and Set Operations for Associations (inline)

inline eShInsGeoOp_TypeID CE3D_ShIns_GeoOp::GeteGOpType ()
{
  //## begin CE3D_ShIns_GeoOp::GeteGOpType%3C603F330291.get preserve=no
  return eGOpType;
  //## end CE3D_ShIns_GeoOp::GeteGOpType%3C603F330291.get
}

inline void CE3D_ShIns_GeoOp::SeteGOpType (eShInsGeoOp_TypeID value)
{
  //## begin CE3D_ShIns_GeoOp::SeteGOpType%3C603F330291.set preserve=no
  eGOpType = value;
  //## end CE3D_ShIns_GeoOp::SeteGOpType%3C603F330291.set
}

//## begin module%3C603E0E0216.epilog preserve=yes
//## end module%3C603E0E0216.epilog


#endif
