//## begin module%3BA2966A028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA2966A028A.cm

//## begin module%3BA2966A028A.cp preserve=no
//## end module%3BA2966A028A.cp

//## Module: CObject3D_AnimCfgMgr%3BA2966A028A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimCfgMgr.h

#ifndef CObject3D_AnimCfgMgr_h
#define CObject3D_AnimCfgMgr_h 1

//## begin module%3BA2966A028A.additionalIncludes preserve=no
//## end module%3BA2966A028A.additionalIncludes

//## begin module%3BA2966A028A.includes preserve=yes
//## end module%3BA2966A028A.includes

// CObject3D_AnimCfgGen
#include "Scene\Animation\CObject3D_AnimCfgGen.h"
// CObject3D_AnimCfg
#include "Scene\Animation\CObject3D_AnimCfg.h"
//## begin module%3BA2966A028A.additionalDeclarations preserve=yes
//## end module%3BA2966A028A.additionalDeclarations


//## begin CObject3D_AnimCfgMgr%3BA2966A028A.preface preserve=yes
//## end CObject3D_AnimCfgMgr%3BA2966A028A.preface

//## Class: CObject3D_AnimCfgMgr%3BA2966A028A
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA2973202F6;CObject3D_AnimCfg { -> }

class CObject3D_AnimCfgMgr : public CObject3D_AnimCfgGen  //## Inherits: <unnamed>%3BA51C9F0201
{
  //## begin CObject3D_AnimCfgMgr%3BA2966A028A.initialDeclarations preserve=yes
  //## end CObject3D_AnimCfgMgr%3BA2966A028A.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimCfgMgr();

    //## Destructor (generated)
      virtual ~CObject3D_AnimCfgMgr();


    //## Other Operations (specified)
      //## Operation: Init%1000511359
      void Init (int _iMaxAnimObjs);

      //## Operation: SetFrameAnim%1000511360
      virtual void SetFrameAnim (int _iFrameAnim);

      //## Operation: poGetBoundVol%1000511361
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1000511362
      virtual void ComputeBoundVol ();

      //## Operation: Render%1000511363
      virtual void Render ();

      //## Operation: AddAnimObj%1000511364
      int AddAnimObj (CObject3D_AnimCfg *_pAnimObj);

    // Data Members for Class Attributes

      //## Attribute: iNumAnimObjs%3BA296DE018D
      //## begin CObject3D_AnimCfgMgr::iNumAnimObjs%3BA296DE018D.attr preserve=no  public: int {UA} 0
      int iNumAnimObjs;
      //## end CObject3D_AnimCfgMgr::iNumAnimObjs%3BA296DE018D.attr

      //## Attribute: iMaxAnimObjs%3BA29A7D0320
      //## begin CObject3D_AnimCfgMgr::iMaxAnimObjs%3BA29A7D0320.attr preserve=no  public: int {UA} 0
      int iMaxAnimObjs;
      //## end CObject3D_AnimCfgMgr::iMaxAnimObjs%3BA29A7D0320.attr

      //## Attribute: pAnimObjs%3BA296E702DA
      //## begin CObject3D_AnimCfgMgr::pAnimObjs%3BA296E702DA.attr preserve=no  public: CObject3D_AnimCfg* * {UA} NULL
      CObject3D_AnimCfg* *pAnimObjs;
      //## end CObject3D_AnimCfgMgr::pAnimObjs%3BA296E702DA.attr

      //## Attribute: iCurrentFrame%3BA29ACF0093
      //## begin CObject3D_AnimCfgMgr::iCurrentFrame%3BA29ACF0093.attr preserve=no  public: int {UA} 0
      int iCurrentFrame;
      //## end CObject3D_AnimCfgMgr::iCurrentFrame%3BA29ACF0093.attr

    // Additional Public Declarations
      //## begin CObject3D_AnimCfgMgr%3BA2966A028A.public preserve=yes
      //## end CObject3D_AnimCfgMgr%3BA2966A028A.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_AnimCfgMgr%3BA2966A028A.protected preserve=yes
      //## end CObject3D_AnimCfgMgr%3BA2966A028A.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_AnimCfgMgr%3BA2966A028A.private preserve=yes
      //## end CObject3D_AnimCfgMgr%3BA2966A028A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimCfgMgr%3BA2966A028A.implementation preserve=yes
      //## end CObject3D_AnimCfgMgr%3BA2966A028A.implementation

};

//## begin CObject3D_AnimCfgMgr%3BA2966A028A.postscript preserve=yes
//## end CObject3D_AnimCfgMgr%3BA2966A028A.postscript

// Class CObject3D_AnimCfgMgr 

//## begin module%3BA2966A028A.epilog preserve=yes
//## end module%3BA2966A028A.epilog


#endif
