//## begin module%3B9DFE320391.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9DFE320391.cm

//## begin module%3B9DFE320391.cp preserve=no
//## end module%3B9DFE320391.cp

//## Module: CObject3D_AnimCfg%3B9DFE320391; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\Animation\CObject3D_AnimCfg.h

#ifndef CObject3D_AnimCfg_h
#define CObject3D_AnimCfg_h 1

//## begin module%3B9DFE320391.additionalIncludes preserve=no
//## end module%3B9DFE320391.additionalIncludes

//## begin module%3B9DFE320391.includes preserve=yes
//## end module%3B9DFE320391.includes

// CObject3D_AnimCfgGen
#include "Scene\Animation\CObject3D_AnimCfgGen.h"
// TFrameAnimation
#include "Scene\Animation\TFrameAnimation.h"
// CObject3D_AnimGen
#include "Scene\Animation\CObject3D_AnimGen.h"
//## begin module%3B9DFE320391.additionalDeclarations preserve=yes
//## end module%3B9DFE320391.additionalDeclarations


//## begin CObject3D_AnimCfg%3B9DFE320391.preface preserve=yes
//## end CObject3D_AnimCfg%3B9DFE320391.preface

//## Class: CObject3D_AnimCfg%3B9DFE320391
//## Category: Scene::Animation%3BA297A00326
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CObject3D_AnimCfg : public CObject3D_AnimCfgGen  //## Inherits: <unnamed>%3BA51CA10358
{
  //## begin CObject3D_AnimCfg%3B9DFE320391.initialDeclarations preserve=yes
  //## end CObject3D_AnimCfg%3B9DFE320391.initialDeclarations

  public:
    //## Constructors (generated)
      CObject3D_AnimCfg();

    //## Destructor (generated)
      virtual ~CObject3D_AnimCfg();


    //## Other Operations (specified)
      //## Operation: CreateFrameAnims%1000205750
      void CreateFrameAnims (int _iNumFrameAnims);

      //## Operation: SetupFrameAnim%1000205751
      void SetupFrameAnim (int _iFrameAnim, int _iInitialFrame, int _iFinalFrame, float _fFrameAnimTime, bool _bLoop);

      //## Operation: SetFrameAnim%1000205752
      virtual void SetFrameAnim (int iFrameAnim);

      //## Operation: poGetBoundVol%1000205753
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1000205754
      virtual void ComputeBoundVol ();

      //## Operation: Render%1000205755
      virtual void Render ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Scene::<unnamed>%3B9E058B015B
      //## Role: CObject3D_AnimCfg::FrameAnim%3B9E058B02EC
      TFrameAnimation * GetFrameAnim ();

      //## Association: Scene::<unnamed>%3B9E01FB024A
      //## Role: CObject3D_AnimCfg::AnimObj%3B9E01FB036C
      CObject3D_AnimGen * GetAnimObj ();
      void SetAnimObj (CObject3D_AnimGen * value);

    // Data Members for Class Attributes

      //## Attribute: iNumFrameAnims%3B9DFE600012
      //## begin CObject3D_AnimCfg::iNumFrameAnims%3B9DFE600012.attr preserve=no  public: int {UA} 0
      int iNumFrameAnims;
      //## end CObject3D_AnimCfg::iNumFrameAnims%3B9DFE600012.attr

      //## Attribute: iCurrentFrameAnim%3B9E1F60016E
      //## begin CObject3D_AnimCfg::iCurrentFrameAnim%3B9E1F60016E.attr preserve=no  public: int {UA} 0
      int iCurrentFrameAnim;
      //## end CObject3D_AnimCfg::iCurrentFrameAnim%3B9E1F60016E.attr

      //## Attribute: fCurrentTime%3B9E1F750182
      //## begin CObject3D_AnimCfg::fCurrentTime%3B9E1F750182.attr preserve=no  public: float {UA} 0
      float fCurrentTime;
      //## end CObject3D_AnimCfg::fCurrentTime%3B9E1F750182.attr

      //## Attribute: iLastFrame%3CBB3DB00290
      //## begin CObject3D_AnimCfg::iLastFrame%3CBB3DB00290.attr preserve=no  public: int {UA} -1
      int iLastFrame;
      //## end CObject3D_AnimCfg::iLastFrame%3CBB3DB00290.attr

    // Data Members for Associations

      //## Association: Scene::<unnamed>%3B9E058B015B
      //## begin CObject3D_AnimCfg::FrameAnim%3B9E058B02EC.role preserve=no  public: TFrameAnimation { -> RHAN}
      TFrameAnimation *FrameAnim;
      //## end CObject3D_AnimCfg::FrameAnim%3B9E058B02EC.role

      //## Association: Scene::<unnamed>%3B9E01FB024A
      //## begin CObject3D_AnimCfg::AnimObj%3B9E01FB036C.role preserve=no  public: CObject3D_AnimGen { -> RHAN}
      CObject3D_AnimGen *AnimObj;
      //## end CObject3D_AnimCfg::AnimObj%3B9E01FB036C.role

    // Additional Public Declarations
      //## begin CObject3D_AnimCfg%3B9DFE320391.public preserve=yes
      //## end CObject3D_AnimCfg%3B9DFE320391.public

  protected:
    // Additional Protected Declarations
      //## begin CObject3D_AnimCfg%3B9DFE320391.protected preserve=yes
      //## end CObject3D_AnimCfg%3B9DFE320391.protected

  private:
    // Additional Private Declarations
      //## begin CObject3D_AnimCfg%3B9DFE320391.private preserve=yes
      //## end CObject3D_AnimCfg%3B9DFE320391.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CObject3D_AnimCfg%3B9DFE320391.implementation preserve=yes
      //## end CObject3D_AnimCfg%3B9DFE320391.implementation

};

//## begin CObject3D_AnimCfg%3B9DFE320391.postscript preserve=yes
//## end CObject3D_AnimCfg%3B9DFE320391.postscript

// Class CObject3D_AnimCfg 

//## Get and Set Operations for Associations (inline)

inline TFrameAnimation * CObject3D_AnimCfg::GetFrameAnim ()
{
  //## begin CObject3D_AnimCfg::GetFrameAnim%3B9E058B02EC.get preserve=no
  return FrameAnim;
  //## end CObject3D_AnimCfg::GetFrameAnim%3B9E058B02EC.get
}

inline CObject3D_AnimGen * CObject3D_AnimCfg::GetAnimObj ()
{
  //## begin CObject3D_AnimCfg::GetAnimObj%3B9E01FB036C.get preserve=no
  return AnimObj;
  //## end CObject3D_AnimCfg::GetAnimObj%3B9E01FB036C.get
}

inline void CObject3D_AnimCfg::SetAnimObj (CObject3D_AnimGen * value)
{
  //## begin CObject3D_AnimCfg::SetAnimObj%3B9E01FB036C.set preserve=no
  AnimObj = value;
  //## end CObject3D_AnimCfg::SetAnimObj%3B9E01FB036C.set
}

//## begin module%3B9DFE320391.epilog preserve=yes
//## end module%3B9DFE320391.epilog


#endif
