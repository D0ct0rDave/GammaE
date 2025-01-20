//## begin module%3B76DE5D02B0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DE5D02B0.cm

//## begin module%3B76DE5D02B0.cp preserve=no
//## end module%3B76DE5D02B0.cp

//## Module: CSample%3B76DE5D02B0; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSample.h

#ifndef CSample_h
#define CSample_h 1

//## begin module%3B76DE5D02B0.additionalIncludes preserve=no
//## end module%3B76DE5D02B0.additionalIncludes

//## begin module%3B76DE5D02B0.includes preserve=yes
//## end module%3B76DE5D02B0.includes

//## begin module%3B76DE5D02B0.additionalDeclarations preserve=yes
//## end module%3B76DE5D02B0.additionalDeclarations


//## begin CSample%3B76DE5D02B0.preface preserve=yes
//## end CSample%3B76DE5D02B0.preface

//## Class: CSample%3B76DE5D02B0
//## Category: SoundSystem::Sound%3B76DE2401DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSample 
{
  //## begin CSample%3B76DE5D02B0.initialDeclarations preserve=yes
  //## end CSample%3B76DE5D02B0.initialDeclarations

  public:
    //## Constructors (generated)
      CSample();

    //## Destructor (generated)
      ~CSample();


    //## Other Operations (specified)
      //## Operation: Init%1002050842
      void Init (int _iChannels, int _iBits, int _iSRate, float _fTime);

      //## Operation: Init%1015160466
      void Init (int _iChannels, int _iBits, int _iSRate, int _iSamples);

    // Data Members for Class Attributes

      //## Attribute: pData%3B76DE77039D
      //## begin CSample::pData%3B76DE77039D.attr preserve=no  public: void * {UA} NULL
      void *pData;
      //## end CSample::pData%3B76DE77039D.attr

      //## Attribute: iChannels%3BBA0BEC020C
      //## begin CSample::iChannels%3BBA0BEC020C.attr preserve=no  public: int {UA} 0
      int iChannels;
      //## end CSample::iChannels%3BBA0BEC020C.attr

      //## Attribute: iBits%3BBA0BF10187
      //## begin CSample::iBits%3BBA0BF10187.attr preserve=no  public: int {UA} 0
      int iBits;
      //## end CSample::iBits%3BBA0BF10187.attr

      //## Attribute: iSRate%3BBA0BF403E4
      //## begin CSample::iSRate%3BBA0BF403E4.attr preserve=no  public: int {UA} 0
      int iSRate;
      //## end CSample::iSRate%3BBA0BF403E4.attr

      //## Attribute: iSamples%3BBA0C0A03E5
      //## begin CSample::iSamples%3BBA0C0A03E5.attr preserve=no  public: int {UA} 0
      int iSamples;
      //## end CSample::iSamples%3BBA0C0A03E5.attr

      //## Attribute: iHandle%3BB77FB9039B
      //## begin CSample::iHandle%3BB77FB9039B.attr preserve=no  public: int {UA} -1
      int iHandle;
      //## end CSample::iHandle%3BB77FB9039B.attr

    // Additional Public Declarations
      //## begin CSample%3B76DE5D02B0.public preserve=yes
      //## end CSample%3B76DE5D02B0.public

  protected:
    // Additional Protected Declarations
      //## begin CSample%3B76DE5D02B0.protected preserve=yes
      //## end CSample%3B76DE5D02B0.protected

  private:
    // Additional Private Declarations
      //## begin CSample%3B76DE5D02B0.private preserve=yes
      //## end CSample%3B76DE5D02B0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSample%3B76DE5D02B0.implementation preserve=yes
      //## end CSample%3B76DE5D02B0.implementation

};

//## begin CSample%3B76DE5D02B0.postscript preserve=yes
//## end CSample%3B76DE5D02B0.postscript

// Class CSample 

//## begin module%3B76DE5D02B0.epilog preserve=yes
//## end module%3B76DE5D02B0.epilog


#endif
