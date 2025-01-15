//## begin module%3C7429E5010C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7429E5010C.cm

//## begin module%3C7429E5010C.cp preserve=no
//## end module%3C7429E5010C.cp

//## Module: CMapEnt_Platform%3C7429E5010C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Platform.h

#ifndef CMapEnt_Platform_h
#define CMapEnt_Platform_h 1

//## begin module%3C7429E5010C.additionalIncludes preserve=no
//## end module%3C7429E5010C.additionalIncludes

//## begin module%3C7429E5010C.includes preserve=yes
//## end module%3C7429E5010C.includes

// CMapBrush
#include "Tools\GEMapCompiler\MapData\MapBrush\CMapBrush.h"
// CMapEnt_Target
#include "Tools\GEMapCompiler\MapData\MapEntity\CMapEnt_Target.h"
// GammaE_Scene
#include "Scene\GammaE_Scene.h"
//## begin module%3C7429E5010C.additionalDeclarations preserve=yes
#include "Misc/GammaE_Misc.h"
//## end module%3C7429E5010C.additionalDeclarations


//## begin CMapEnt_Platform%3C7429E5010C.preface preserve=yes
//## end CMapEnt_Platform%3C7429E5010C.preface

//## Class: CMapEnt_Platform%3C7429E5010C
//## Category: Tools::GEMapCompiler::MapData::MapEntity%3C7428F80364
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CDD33AF01F9;GammaE_Scene { -> }

class CMapEnt_Platform : public CMapEnt_Target  //## Inherits: <unnamed>%3CDCDFF60152
{
  //## begin CMapEnt_Platform%3C7429E5010C.initialDeclarations preserve=yes
  //## end CMapEnt_Platform%3C7429E5010C.initialDeclarations

  public:
    //## Constructors (generated)
      CMapEnt_Platform();

    //## Destructor (generated)
      ~CMapEnt_Platform();

    // Data Members for Class Attributes

      //## Attribute: fSpeed%3CDAFB15035D
      //## begin CMapEnt_Platform::fSpeed%3CDAFB15035D.attr preserve=no  public: float {UA} 
      float fSpeed;
      //## end CMapEnt_Platform::fSpeed%3CDAFB15035D.attr

      //## Attribute: fEndAc%3CDAFB200128
      //## begin CMapEnt_Platform::fEndAc%3CDAFB200128.attr preserve=no  public: float {UA} 
      float fEndAc;
      //## end CMapEnt_Platform::fEndAc%3CDAFB200128.attr

      //## Attribute: fStartDec%3CDAFB2601C7
      //## begin CMapEnt_Platform::fStartDec%3CDAFB2601C7.attr preserve=no  public: float {UA} 
      float fStartDec;
      //## end CMapEnt_Platform::fStartDec%3CDAFB2601C7.attr

      //## Attribute: oDstPos%3CDD281A0368
      //## begin CMapEnt_Platform::oDstPos%3CDD281A0368.attr preserve=no  public: CVect3 {UA} 
      CVect3 oDstPos;
      //## end CMapEnt_Platform::oDstPos%3CDD281A0368.attr

      //## Attribute: oSrcPos%3CE0307902D7
      //## begin CMapEnt_Platform::oSrcPos%3CE0307902D7.attr preserve=no  public: CVect3 {UA} 
      CVect3 oSrcPos;
      //## end CMapEnt_Platform::oSrcPos%3CE0307902D7.attr

      //## Attribute: poScn%3CDD33720101
      //## begin CMapEnt_Platform::poScn%3CDD33720101.attr preserve=no  public: CObject3D* {UA} 
      CObject3D* poScn;
      //## end CMapEnt_Platform::poScn%3CDD33720101.attr

      //## Attribute: oPos%3CE0256100AD
      //## begin CMapEnt_Platform::oPos%3CE0256100AD.attr preserve=no  public: CVect3 {UA} 
      CVect3 oPos;
      //## end CMapEnt_Platform::oPos%3CE0256100AD.attr

    // Data Members for Associations

      //## Association: Tools::GEMapCompiler::MapData::MapEntity::<unnamed>%3C742A4302DE
      //## Role: CMapEnt_Platform::aoBrush%3C742A440069
      //## begin CMapEnt_Platform::aoBrush%3C742A440069.role preserve=no  public: CMapBrush { -> RHAN}
      CDynArray <CMapBrush *> aoBrush;
      //## end CMapEnt_Platform::aoBrush%3C742A440069.role

    // Additional Public Declarations
      //## begin CMapEnt_Platform%3C7429E5010C.public preserve=yes
      //## end CMapEnt_Platform%3C7429E5010C.public

  protected:
    // Additional Protected Declarations
      //## begin CMapEnt_Platform%3C7429E5010C.protected preserve=yes
      //## end CMapEnt_Platform%3C7429E5010C.protected

  private:
    // Additional Private Declarations
      //## begin CMapEnt_Platform%3C7429E5010C.private preserve=yes
      //## end CMapEnt_Platform%3C7429E5010C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMapEnt_Platform%3C7429E5010C.implementation preserve=yes
      //## end CMapEnt_Platform%3C7429E5010C.implementation

};

//## begin CMapEnt_Platform%3C7429E5010C.postscript preserve=yes
//## end CMapEnt_Platform%3C7429E5010C.postscript

// Class CMapEnt_Platform 

//## begin module%3C7429E5010C.epilog preserve=yes
//## end module%3C7429E5010C.epilog


#endif
