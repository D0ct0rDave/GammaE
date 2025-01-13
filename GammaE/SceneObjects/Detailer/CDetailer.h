//## begin module%3C43544A0378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C43544A0378.cm

//## begin module%3C43544A0378.cp preserve=no
//## end module%3C43544A0378.cp

//## Module: CDetailer%3C43544A0378; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\Detailer\CDetailer.h

#ifndef CDetailer_h
#define CDetailer_h 1

//## begin module%3C43544A0378.additionalIncludes preserve=no
//## end module%3C43544A0378.additionalIncludes

//## begin module%3C43544A0378.includes preserve=yes
//## end module%3C43544A0378.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3C43544A0378.additionalDeclarations preserve=yes
//## end module%3C43544A0378.additionalDeclarations


//## begin CDetailer%3C43544A0378.preface preserve=yes
//## end CDetailer%3C43544A0378.preface

//## Class: CDetailer%3C43544A0378
//## Category: SceneObjects::Detailer%3C4354430092
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CDetailer : public CObject3D_Leaf  //## Inherits: <unnamed>%3C4354FC0388
{
  //## begin CDetailer%3C43544A0378.initialDeclarations preserve=yes
  //## end CDetailer%3C43544A0378.initialDeclarations

  public:
    //## Constructors (generated)
      CDetailer();

    //## Destructor (generated)
      ~CDetailer();


    //## Other Operations (specified)
      //## Operation: Init%1011045648
      void Init (int _iMaxTris);

      //## Operation: SetCamPos%1011045650
      void SetCamPos (CVect3& _roCamPos);

      //## Operation: SetVertexTris%1011045651
      void SetVertexTris (CVect3* _poVXs, int _iNumTris);

      //## Operation: CreateTextureContents%1011045654
      void CreateTextureContents (MipMap *_pMipMap);

      //## Operation: CreateTexture%1011045653
      TTextureObj * CreateTexture ();

      //## Operation: poCreateMaterial%1011045652
      CE3D_Shader * poCreateMaterial ();

      //## Operation: Render%1011045658
      virtual void Render ();

    // Additional Public Declarations
      //## begin CDetailer%3C43544A0378.public preserve=yes
      //## end CDetailer%3C43544A0378.public

  protected:
    // Additional Protected Declarations
      //## begin CDetailer%3C43544A0378.protected preserve=yes
      //## end CDetailer%3C43544A0378.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oCamPos%3C43552C00D4
      //## begin CDetailer::oCamPos%3C43552C00D4.attr preserve=no  private: CVect3 {UA} 
      CVect3 oCamPos;
      //## end CDetailer::oCamPos%3C43552C00D4.attr

    // Additional Private Declarations
      //## begin CDetailer%3C43544A0378.private preserve=yes
      //## end CDetailer%3C43544A0378.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CDetailer%3C43544A0378.implementation preserve=yes
      //## end CDetailer%3C43544A0378.implementation

};

//## begin CDetailer%3C43544A0378.postscript preserve=yes
//## end CDetailer%3C43544A0378.postscript

// Class CDetailer 

//## begin module%3C43544A0378.epilog preserve=yes
//## end module%3C43544A0378.epilog


#endif
