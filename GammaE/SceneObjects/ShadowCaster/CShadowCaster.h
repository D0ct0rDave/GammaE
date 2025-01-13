//## begin module%3CBB24A1003D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CBB24A1003D.cm

//## begin module%3CBB24A1003D.cp preserve=no
//## end module%3CBB24A1003D.cp

//## Module: CShadowCaster%3CBB24A1003D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\ShadowCaster\CShadowCaster.h

#ifndef CShadowCaster_h
#define CShadowCaster_h 1

//## begin module%3CBB24A1003D.additionalIncludes preserve=no
//## end module%3CBB24A1003D.additionalIncludes

//## begin module%3CBB24A1003D.includes preserve=yes
//## end module%3CBB24A1003D.includes

// CTexProjector
#include "SceneObjects\TexProjector\CTexProjector.h"
// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3CBB24A1003D.additionalDeclarations preserve=yes
//## end module%3CBB24A1003D.additionalDeclarations


//## begin CShadowCaster%3CBB24A1003D.preface preserve=yes
//## end CShadowCaster%3CBB24A1003D.preface

//## Class: CShadowCaster%3CBB24A1003D
//## Category: SceneObjects::ShadowCaster%3CBB2499012C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CShadowCaster : public CObject3D  //## Inherits: <unnamed>%3CBB2554036F
{
  //## begin CShadowCaster%3CBB24A1003D.initialDeclarations preserve=yes
  //## end CShadowCaster%3CBB24A1003D.initialDeclarations

  public:
    //## Constructors (generated)
      CShadowCaster();

    //## Destructor (generated)
      ~CShadowCaster();


    //## Other Operations (specified)
      //## Operation: Init%1018910300
      void Init (int _iRes);

      //## Operation: Setup%1018897755
      void Setup (CVect3& _roLightPos, CObject3D* _poBlockerObj, CMesh** _poRecObjs, int _iNumRecObjs);

      //## Operation: poGetBoundVol%1018897758
      virtual CGraphBV* poGetBoundVol ();

      //## Operation: ComputeBoundVol%1018897757
      virtual void ComputeBoundVol ();

      //## Operation: ComputeLightCamera%1018910298
      void ComputeLightCamera ();

      //## Operation: ComputeLightViewport%1018910301
      void ComputeLightViewport (CE3D_Viewport& _roVpt);

      //## Operation: ComputeLightProjection%1018910302
      void ComputeLightProjection ();

      //## Operation: ComputeTextureProjection%1018988852
      void ComputeTextureProjection ();

      //## Operation: UploadShadowMap%1018910299
      void UploadShadowMap ();

      //## Operation: RenderShadowMap%1018910297
      void RenderShadowMap ();

      //## Operation: Render%1018897756
      virtual void Render ();

    // Data Members for Class Attributes

      //## Attribute: oCamMat%3CBCB47C026C
      //## begin CShadowCaster::oCamMat%3CBCB47C026C.attr preserve=no  public: CMatrix4x4 {UA} 
      CMatrix4x4 oCamMat;
      //## end CShadowCaster::oCamMat%3CBCB47C026C.attr

    // Data Members for Associations

      //## Association: SceneObjects::ShadowCaster::<unnamed>%3CBB24C8024C
      //## Role: CShadowCaster::oTexProj%3CBB24C90045
      //## begin CShadowCaster::oTexProj%3CBB24C90045.role preserve=no  public: CTexProjector { -> VHAN}
      CTexProjector oTexProj;
      //## end CShadowCaster::oTexProj%3CBB24C90045.role

      //## Association: SceneObjects::ShadowCaster::<unnamed>%3CBB24FA033E
      //## Role: CShadowCaster::poShader%3CBB24FB00AA
      //## begin CShadowCaster::poShader%3CBB24FB00AA.role preserve=no  public: CE3D_Shader { -> RHAN}
      CE3D_Shader *poShader;
      //## end CShadowCaster::poShader%3CBB24FB00AA.role

    // Additional Public Declarations
      //## begin CShadowCaster%3CBB24A1003D.public preserve=yes
      //## end CShadowCaster%3CBB24A1003D.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: poBlockerObj%3CBB29830008
      //## begin CShadowCaster::poBlockerObj%3CBB29830008.attr preserve=no  protected: CObject3D* {UA} NULL
      CObject3D* poBlockerObj;
      //## end CShadowCaster::poBlockerObj%3CBB29830008.attr

      //## Attribute: oLPos%3CBB298C0340
      //## begin CShadowCaster::oLPos%3CBB298C0340.attr preserve=no  protected: CVect3 {UA} 
      CVect3 oLPos;
      //## end CShadowCaster::oLPos%3CBB298C0340.attr

      //## Attribute: poRecObjs%3CBB299003A0
      //## begin CShadowCaster::poRecObjs%3CBB299003A0.attr preserve=no  protected: CMesh* * {UA} NULL
      CMesh* *poRecObjs;
      //## end CShadowCaster::poRecObjs%3CBB299003A0.attr

      //## Attribute: iNumRecObjs%3CBCB01C0058
      //## begin CShadowCaster::iNumRecObjs%3CBCB01C0058.attr preserve=no  protected: int {UA} 0
      int iNumRecObjs;
      //## end CShadowCaster::iNumRecObjs%3CBCB01C0058.attr

      //## Attribute: iRes%3CBB594B023D
      //## begin CShadowCaster::iRes%3CBB594B023D.attr preserve=no  protected: int {UA} 
      int iRes;
      //## end CShadowCaster::iRes%3CBB594B023D.attr

      //## Attribute: poTexObj%3CBB5AA50046
      //## begin CShadowCaster::poTexObj%3CBB5AA50046.attr preserve=no  protected: TTextureObj * {UA} NULL
      TTextureObj *poTexObj;
      //## end CShadowCaster::poTexObj%3CBB5AA50046.attr

      //## Attribute: oPrjMat%3CBCB47500DB
      //## begin CShadowCaster::oPrjMat%3CBCB47500DB.attr preserve=no  protected: CMatrix4x4 {UA} 
      CMatrix4x4 oPrjMat;
      //## end CShadowCaster::oPrjMat%3CBCB47500DB.attr

      //## Attribute: oPrjTexMat%3CBCB55301B6
      //## begin CShadowCaster::oPrjTexMat%3CBCB55301B6.attr preserve=no  protected: CMatrix4x4 {UA} 
      CMatrix4x4 oPrjTexMat;
      //## end CShadowCaster::oPrjTexMat%3CBCB55301B6.attr

      //## Attribute: pucAuxTexData%3CBDECDB0108
      //## begin CShadowCaster::pucAuxTexData%3CBDECDB0108.attr preserve=no  protected: unsigned char * {UA} NULL
      unsigned char *pucAuxTexData;
      //## end CShadowCaster::pucAuxTexData%3CBDECDB0108.attr

    // Additional Protected Declarations
      //## begin CShadowCaster%3CBB24A1003D.protected preserve=yes
      //## end CShadowCaster%3CBB24A1003D.protected

  private:
    // Additional Private Declarations
      //## begin CShadowCaster%3CBB24A1003D.private preserve=yes
      //## end CShadowCaster%3CBB24A1003D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CShadowCaster%3CBB24A1003D.implementation preserve=yes
      //## end CShadowCaster%3CBB24A1003D.implementation

};

//## begin CShadowCaster%3CBB24A1003D.postscript preserve=yes
//## end CShadowCaster%3CBB24A1003D.postscript

// Class CShadowCaster 

//## begin module%3CBB24A1003D.epilog preserve=yes
//## end module%3CBB24A1003D.epilog


#endif
