//## begin module%3B70757D03CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B70757D03CA.cm

//## begin module%3B70757D03CA.cp preserve=no
//## end module%3B70757D03CA.cp

//## Module: CGraphBV_Manager%3B70757D03CA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Manager.h

#ifndef CGraphBV_Manager_h
#define CGraphBV_Manager_h 1

//## begin module%3B70757D03CA.additionalIncludes preserve=no
//## end module%3B70757D03CA.additionalIncludes

//## begin module%3B70757D03CA.includes preserve=yes
//## end module%3B70757D03CA.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
// eGraphBV_TypeID
#include "E3D\BoundingVolume\GraphBoundVol\eGraphBV_TypeID.h"
//## begin module%3B70757D03CA.additionalDeclarations preserve=yes
//## end module%3B70757D03CA.additionalDeclarations


//## begin CGraphBV_Manager%3B70757D03CA.preface preserve=yes
//## end CGraphBV_Manager%3B70757D03CA.preface

//## Class: CGraphBV_Manager%3B70757D03CA
//## Category: E3D::BoundingVolume::GraphBoundVol%3B7060820104
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B70758F00DC;CGraphBV_Cylinder { -> }
//## Uses: <unnamed>%3B7075CD03B6;CGraphBV_Sphere { -> }
//## Uses: <unnamed>%3B7075E60186;CGraphBV_Box { -> }
//## Uses: <unnamed>%3C4D99D303CE;CGraphBV_Point { -> }
//## Uses: <unnamed>%3C5092550399;eGraphBV_TypeID { -> }
//## Uses: <unnamed>%3C5095A0003E;CGraphBV { -> }

class CGraphBV_Manager 
{
  //## begin CGraphBV_Manager%3B70757D03CA.initialDeclarations preserve=yes
  //## end CGraphBV_Manager%3B70757D03CA.initialDeclarations

  public:
    //## Constructors (generated)
      CGraphBV_Manager();

    //## Destructor (generated)
      ~CGraphBV_Manager();


    //## Other Operations (specified)
      //## Operation: poCreate%997221311
      static CGraphBV * poCreate ();

      //## Operation: SetBVMode%997221312
      static void SetBVMode (eGraphBV_TypeID _eMode);

      //## Operation: eGetBVMode%1011911194
      static eGraphBV_TypeID eGetBVMode ();

    // Additional Public Declarations
      //## begin CGraphBV_Manager%3B70757D03CA.public preserve=yes
      //## end CGraphBV_Manager%3B70757D03CA.public

  protected:
    // Additional Protected Declarations
      //## begin CGraphBV_Manager%3B70757D03CA.protected preserve=yes
      //## end CGraphBV_Manager%3B70757D03CA.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: eCreationMode%3B7075AD0398
      //## begin CGraphBV_Manager::eCreationMode%3B7075AD0398.attr preserve=no  private: static eGraphBV_TypeID {UA} eGraphBV_Sphere
      static eGraphBV_TypeID eCreationMode;
      //## end CGraphBV_Manager::eCreationMode%3B7075AD0398.attr

    // Additional Private Declarations
      //## begin CGraphBV_Manager%3B70757D03CA.private preserve=yes
      //## end CGraphBV_Manager%3B70757D03CA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CGraphBV_Manager%3B70757D03CA.implementation preserve=yes
      //## end CGraphBV_Manager%3B70757D03CA.implementation

};

//## begin CGraphBV_Manager%3B70757D03CA.postscript preserve=yes
//## end CGraphBV_Manager%3B70757D03CA.postscript

// Class CGraphBV_Manager 


//## Other Operations (inline)
inline void CGraphBV_Manager::SetBVMode (eGraphBV_TypeID _eMode)
{
  //## begin CGraphBV_Manager::SetBVMode%997221312.body preserve=yes
	eCreationMode = _eMode;
  //## end CGraphBV_Manager::SetBVMode%997221312.body
}

inline eGraphBV_TypeID CGraphBV_Manager::eGetBVMode ()
{
  //## begin CGraphBV_Manager::eGetBVMode%1011911194.body preserve=yes
	return (eCreationMode);
  //## end CGraphBV_Manager::eGetBVMode%1011911194.body
}

//## begin module%3B70757D03CA.epilog preserve=yes
//## end module%3B70757D03CA.epilog


#endif
