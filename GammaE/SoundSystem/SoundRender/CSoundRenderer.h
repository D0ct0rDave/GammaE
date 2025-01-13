//## begin module%3B76FFB6017F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76FFB6017F.cm

//## begin module%3B76FFB6017F.cp preserve=no
//## end module%3B76FFB6017F.cp

//## Module: CSoundRenderer%3B76FFB6017F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\CSoundRenderer.h

#ifndef CSoundRenderer_h
#define CSoundRenderer_h 1

//## begin module%3B76FFB6017F.additionalIncludes preserve=no
//## end module%3B76FFB6017F.additionalIncludes

//## begin module%3B76FFB6017F.includes preserve=yes
#include "Misc/GammaE_Misc.h"
//## end module%3B76FFB6017F.includes

// CSoundEmiter
#include "SoundSystem\SoundRender\CSoundEmiter.h"
// CSoundReceiver
#include "SoundSystem\SoundRender\CSoundReceiver.h"
//## begin module%3B76FFB6017F.additionalDeclarations preserve=yes
//## end module%3B76FFB6017F.additionalDeclarations


//## begin CSoundRenderer%3B76FFB6017F.preface preserve=yes
//## end CSoundRenderer%3B76FFB6017F.preface

//## Class: CSoundRenderer%3B76FFB6017F
//## Category: SoundSystem::SoundRender%3B76FFA20393
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7F8E7900E6;CSoundReceiver { -> }
//## Uses: <unnamed>%3D0A506E0369;CSoundEmiter { -> }

class CSoundRenderer 
{
  //## begin CSoundRenderer%3B76FFB6017F.initialDeclarations preserve=yes
  //## end CSoundRenderer%3B76FFB6017F.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundRenderer();

    //## Destructor (generated)
      ~CSoundRenderer();


    //## Other Operations (specified)
      //## Operation: Init%1001802590
      virtual int Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters) = 0;

      //## Operation: Render%1001802591
      virtual void Render (float _fDelta) = 0;

      //## Operation: poAddEmiter%1001802592
      virtual CSoundEmiter * poAddEmiter (CSound* _poSound, CVect3& _roPos, float _fVol);

      //## Operation: poAddOmniEmiter%1024078849
      CSoundEmiter * poAddOmniEmiter (CSound* _poSound, float _fVol);

      //## Operation: SetReceiver%1001802594
      void SetReceiver (CSoundReceiver* _poReceiver);

      //## Operation: poGetReceiver%1001802601
      CSoundReceiver * poGetReceiver ();

    // Additional Public Declarations
      //## begin CSoundRenderer%3B76FFB6017F.public preserve=yes
      //## end CSoundRenderer%3B76FFB6017F.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iMaxEmiters%3BB64E0C018A
      //## begin CSoundRenderer::iMaxEmiters%3BB64E0C018A.attr preserve=no  protected: int {UA} 0
      int iMaxEmiters;
      //## end CSoundRenderer::iMaxEmiters%3BB64E0C018A.attr

      //## Attribute: poReceiver%3BB6568C0107
      //## begin CSoundRenderer::poReceiver%3BB6568C0107.attr preserve=no  protected: CSoundReceiver * {UA} NULL
      CSoundReceiver *poReceiver;
      //## end CSoundRenderer::poReceiver%3BB6568C0107.attr

      //## Attribute: oEmiters%3D0A4DE600AA
      //## begin CSoundRenderer::oEmiters%3D0A4DE600AA.attr preserve=no  protected: CCircularArray <CSoundEmiter> {UA} 
      CCircularArray <CSoundEmiter> oEmiters;
      //## end CSoundRenderer::oEmiters%3D0A4DE600AA.attr

    // Additional Protected Declarations
      //## begin CSoundRenderer%3B76FFB6017F.protected preserve=yes
      //## end CSoundRenderer%3B76FFB6017F.protected

  private:
    // Additional Private Declarations
      //## begin CSoundRenderer%3B76FFB6017F.private preserve=yes
      //## end CSoundRenderer%3B76FFB6017F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundRenderer%3B76FFB6017F.implementation preserve=yes
      //## end CSoundRenderer%3B76FFB6017F.implementation

};

//## begin CSoundRenderer%3B76FFB6017F.postscript preserve=yes
//## end CSoundRenderer%3B76FFB6017F.postscript

// Class CSoundRenderer 

//## begin module%3B76FFB6017F.epilog preserve=yes
//## end module%3B76FFB6017F.epilog


#endif
