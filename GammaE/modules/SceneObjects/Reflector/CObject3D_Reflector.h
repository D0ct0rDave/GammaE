//## begin module%3BDB5AB6017E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BDB5AB6017E.cm

//## begin module%3BDB5AB6017E.cp preserve=no
//## end module%3BDB5AB6017E.cp

//## Module: CObject3D_Reflector%3BDB5AB6017E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\Reflector\CObject3D_Reflector.h

#ifndef CObject3D_Reflector_h
#define CObject3D_Reflector_h 1

//## begin module%3BDB5AB6017E.additionalIncludes preserve=no
//## end module%3BDB5AB6017E.additionalIncludes

//## begin module%3BDB5AB6017E.includes preserve=yes
//## end module%3BDB5AB6017E.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
// CPlane
#include "Math\MATH_Plane\CPlane.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
//## begin module%3BDB5AB6017E.additionalDeclarations preserve=yes
//## end module%3BDB5AB6017E.additionalDeclarations


//## begin CObject3D_Reflector%3BDB5AB6017E.preface preserve=yes
//## end CObject3D_Reflector%3BDB5AB6017E.preface

//## Class: CObject3D_Reflector%3BDB5AB6017E
//## Category: SceneObjects::Reflector%3BDB5A9801E9
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C276504033E;GammaE_Math { -> }

class CObject3D_Reflector : public CObject3D_Node  //## Inherits: <unnamed>%3BDB5AEE02E7
{
  //## begin CObject3D_Reflector%3BDB5AB6017E.initialDeclarations preserve=yes
  //## end CObject3D_Reflector%3BDB5AB6017E.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_Reflector();

    //## Destructor (generated)
      virtual ~CObject3D_Reflector();


    //## Other Operations (specified)
      //## Operation: Render%1004231435
      virtual void Render ();

      //## Operation: SetupReflectionMatrix%1004231436
      void SetupReflectionMatrix (CMatrix4x4 &_roMat);

    //## Get and Set Operations for Associations (generated)

      //## Association: SceneObjects::Reflector::<unnamed>%3BDB5AD20175
      //## Role: CObject3D_Reflector::Plane%3BDB5AD20298
      CPlane& GetPlane ();
      void SetPlane (const CPlane& value);

    // Data Members for Class Attributes

      //## Attribute: Mirror%3BDB61DD016D
      //## begin CObject3D_Reflector::Mirror%3BDB61DD016D.attr preserve=no  public: CMesh * {UA} NULL
      CMesh *Mirror;
      //## end CObject3D_Reflector::Mirror%3BDB61DD016D.attr

    // Data Members for Associations

      //## Association: SceneObjects::Reflector::<unnamed>%3BDB5AD20175
      //## begin CObject3D_Reflector::Plane%3BDB5AD20298.role preserve=no  public: CPlane { -> VHAN}
      CPlane Plane;
      //## end CObject3D_Reflector::Plane%3BDB5AD20298.role

    // Additional Public Declarations
      //## begin CObject3D_Reflector%3BDB5AB6017E.public preserve=yes
      //## end CObject3D_Reflector%3BDB5AB6017E.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_Reflector%3BDB5AB6017E.protected preserve=yes
      //## end CObject3D_Reflector%3BDB5AB6017E.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_Reflector%3BDB5AB6017E.private preserve=yes
      //## end CObject3D_Reflector%3BDB5AB6017E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_Reflector%3BDB5AB6017E.implementation preserve=yes
      //## end CObject3D_Reflector%3BDB5AB6017E.implementation

};

//## begin CObject3D_Reflector%3BDB5AB6017E.postscript preserve=yes
//## end CObject3D_Reflector%3BDB5AB6017E.postscript

// Class CObject3D_Reflector 

//## Get and Set Operations for Associations (inline)

inline CPlane& CObject3D_Reflector::GetPlane ()
{
  //## begin CObject3D_Reflector::GetPlane%3BDB5AD20298.get preserve=no
  return Plane;
  //## end CObject3D_Reflector::GetPlane%3BDB5AD20298.get
}

inline void CObject3D_Reflector::SetPlane (const CPlane& value)
{
  //## begin CObject3D_Reflector::SetPlane%3BDB5AD20298.set preserve=no
  Plane = value;
  //## end CObject3D_Reflector::SetPlane%3BDB5AD20298.set
}

//## begin module%3BDB5AB6017E.epilog preserve=yes
//## end module%3BDB5AB6017E.epilog


#endif
