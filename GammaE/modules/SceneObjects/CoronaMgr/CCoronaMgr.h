//## begin module%3C72C95203E5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C72C95203E5.cm

//## begin module%3C72C95203E5.cp preserve=no
//## end module%3C72C95203E5.cp

//## Module: CCoronaMgr%3C72C95203E5; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\CoronaMgr\CCoronaMgr.h

#ifndef CCoronaMgr_h
#define CCoronaMgr_h 1

//## begin module%3C72C95203E5.additionalIncludes preserve=no
//## end module%3C72C95203E5.additionalIncludes

//## begin module%3C72C95203E5.includes preserve=yes
//## end module%3C72C95203E5.includes

// CCorona
#include "SceneObjects\CoronaMgr\CCorona.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3C72C95203E5.additionalDeclarations preserve=yes
//## end module%3C72C95203E5.additionalDeclarations


//## begin CCoronaMgr%3C72C95203E5.preface preserve=yes
//## end CCoronaMgr%3C72C95203E5.preface

//## Class: CCoronaMgr%3C72C95203E5
//## Category: SceneObjects::CoronaMgr%3C72C8690318
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCoronaMgr : public CObject3D_Leaf  //## Inherits: <unnamed>%3C72CBD60323
{
  //## begin CCoronaMgr%3C72C95203E5.initialDeclarations preserve=yes
  //## end CCoronaMgr%3C72C95203E5.initialDeclarations

  public:
    //## Constructors (generated)
      CCoronaMgr();

    //## Destructor (generated)
      ~CCoronaMgr();


    //## Other Operations (specified)
      //## Operation: Init%1014157000
      void Init (int _iMaxCoronas);

      //## Operation: AddCorona%1014157001
      void AddCorona (TFColor _roColor, CE3D_Shader *_poMat, CVect3& _roPos, float _fXYSize);

      //## Operation: SetMaxCoronaDist%1014157318
      void SetMaxCoronaDist (float _fMaxCoronaDist);

      //## Operation: bVisible%1014157319
      bool bVisible (CCorona& _roCorona);

      //## Operation: MarkVisibles%1014157320
      void MarkVisibles ();

      //## Operation: Render%1014157002
      virtual void Render ();

    //## Get and Set Operations for Associations (generated)

      //## Association: SceneObjects::CoronaMgr::<unnamed>%3C72CE2502AA
      //## Role: CCoronaMgr::poCoronas%3C72CE270005
      CCorona * GetpoCoronas ();
      void SetpoCoronas (CCorona * value);

    // Data Members for Associations

      //## Association: SceneObjects::CoronaMgr::<unnamed>%3C72CE2502AA
      //## begin CCoronaMgr::poCoronas%3C72CE270005.role preserve=no  public: CCorona { -> RHAN}
      CCorona *poCoronas;
      //## end CCoronaMgr::poCoronas%3C72CE270005.role

    // Additional Public Declarations
      //## begin CCoronaMgr%3C72C95203E5.public preserve=yes
      //## end CCoronaMgr%3C72C95203E5.public

  protected:
    // Additional Protected Declarations
      //## begin CCoronaMgr%3C72C95203E5.protected preserve=yes
      //## end CCoronaMgr%3C72C95203E5.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iMaxCoronas%3C72CB8C038A
      //## begin CCoronaMgr::iMaxCoronas%3C72CB8C038A.attr preserve=no  private: int {UA} 0
      int iMaxCoronas;
      //## end CCoronaMgr::iMaxCoronas%3C72CB8C038A.attr

      //## Attribute: iNumCoronas%3C72CB910139
      //## begin CCoronaMgr::iNumCoronas%3C72CB910139.attr preserve=no  private: int {UA} 0
      int iNumCoronas;
      //## end CCoronaMgr::iNumCoronas%3C72CB910139.attr

      //## Attribute: fMaxCoronaDist%3C72CC1002FE
      //## begin CCoronaMgr::fMaxCoronaDist%3C72CC1002FE.attr preserve=no  private: float {UA} 0.0f
      float fMaxCoronaDist;
      //## end CCoronaMgr::fMaxCoronaDist%3C72CC1002FE.attr

      //## Attribute: bVisibles%3C72D2CC02A3
      //## begin CCoronaMgr::bVisibles%3C72D2CC02A3.attr preserve=no  private: bool * {UA} NULL
      bool *bVisibles;
      //## end CCoronaMgr::bVisibles%3C72D2CC02A3.attr

    // Additional Private Declarations
      //## begin CCoronaMgr%3C72C95203E5.private preserve=yes
      //## end CCoronaMgr%3C72C95203E5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCoronaMgr%3C72C95203E5.implementation preserve=yes
      //## end CCoronaMgr%3C72C95203E5.implementation

};

//## begin CCoronaMgr%3C72C95203E5.postscript preserve=yes
//## end CCoronaMgr%3C72C95203E5.postscript

// Class CCoronaMgr 

//## Get and Set Operations for Associations (inline)

inline CCorona * CCoronaMgr::GetpoCoronas ()
{
  //## begin CCoronaMgr::GetpoCoronas%3C72CE270005.get preserve=no
  return poCoronas;
  //## end CCoronaMgr::GetpoCoronas%3C72CE270005.get
}

inline void CCoronaMgr::SetpoCoronas (CCorona * value)
{
  //## begin CCoronaMgr::SetpoCoronas%3C72CE270005.set preserve=no
  poCoronas = value;
  //## end CCoronaMgr::SetpoCoronas%3C72CE270005.set
}

//## begin module%3C72C95203E5.epilog preserve=yes
//## end module%3C72C95203E5.epilog


#endif
