//## begin module%3B76DF1100F6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DF1100F6.cm

//## begin module%3B76DF1100F6.cp preserve=no
//## end module%3B76DF1100F6.cp

//## Module: CSampleWH%3B76DF1100F6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSampleWH.h

#ifndef CSampleWH_h
#define CSampleWH_h 1

//## begin module%3B76DF1100F6.additionalIncludes preserve=no
//## end module%3B76DF1100F6.additionalIncludes

//## begin module%3B76DF1100F6.includes preserve=yes
//## end module%3B76DF1100F6.includes

// CSample
#include "SoundSystem\Sound\CSample.h"
//## begin module%3B76DF1100F6.additionalDeclarations preserve=yes
//## end module%3B76DF1100F6.additionalDeclarations


//## begin CSampleWH%3B76DF1100F6.preface preserve=yes
//## end CSampleWH%3B76DF1100F6.preface

//## Class: CSampleWH%3B76DF1100F6
//## Category: SoundSystem::Sound%3B76DE2401DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BB65502025F;CSample { -> }

class CSampleWH 
{
  //## begin CSampleWH%3B76DF1100F6.initialDeclarations preserve=yes
  //## end CSampleWH%3B76DF1100F6.initialDeclarations

  public:
    //## Constructors (generated)
      CSampleWH();

    //## Destructor (generated)
      ~CSampleWH();


    //## Other Operations (specified)
      //## Operation: Init%1001802581
      static void Init (int _iMaxSamples);

      //## Operation: Invalidate%1001802582
      static void Invalidate ();

      //## Operation: iAddSample%1001802583
      static int iAddSample (CSample *_poSample);

      //## Operation: poGetSample%1001802584
      static CSample * poGetSample (int _iIdx);

      //## Operation: iLoadSample%1001881740
      static int iLoadSample (char *_szFilename);

      //## Operation: SetForcedParams%1014979368
      static void SetForcedParams (int _iForcedSRate, int _iForcedBits);

    // Additional Public Declarations
      //## begin CSampleWH%3B76DF1100F6.public preserve=yes
      //## end CSampleWH%3B76DF1100F6.public

  protected:
    // Additional Protected Declarations
      //## begin CSampleWH%3B76DF1100F6.protected preserve=yes
      //## end CSampleWH%3B76DF1100F6.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iNumSamples%3BB645B60236
      //## begin CSampleWH::iNumSamples%3BB645B60236.attr preserve=no  private: static int {UA} 0
      static int iNumSamples;
      //## end CSampleWH::iNumSamples%3BB645B60236.attr

      //## Attribute: iMaxSamples%3BB645BB00DE
      //## begin CSampleWH::iMaxSamples%3BB645BB00DE.attr preserve=no  private: static int {UA} 0
      static int iMaxSamples;
      //## end CSampleWH::iMaxSamples%3BB645BB00DE.attr

      //## Attribute: poSample%3BB654A503D7
      //## begin CSampleWH::poSample%3BB654A503D7.attr preserve=no  private: static CSample* * {UA} NULL
      static CSample* *poSample;
      //## end CSampleWH::poSample%3BB654A503D7.attr

      //## Attribute: iForcedSRate%3C7F7F07032E
      //## begin CSampleWH::iForcedSRate%3C7F7F07032E.attr preserve=no  private: static int {UA} 22050
      static int iForcedSRate;
      //## end CSampleWH::iForcedSRate%3C7F7F07032E.attr

      //## Attribute: iForcedBits%3C7F7F100038
      //## begin CSampleWH::iForcedBits%3C7F7F100038.attr preserve=no  private: static int {UA} 16
      static int iForcedBits;
      //## end CSampleWH::iForcedBits%3C7F7F100038.attr

    // Additional Private Declarations
      //## begin CSampleWH%3B76DF1100F6.private preserve=yes
      //## end CSampleWH%3B76DF1100F6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSampleWH%3B76DF1100F6.implementation preserve=yes
      //## end CSampleWH%3B76DF1100F6.implementation

};

//## begin CSampleWH%3B76DF1100F6.postscript preserve=yes
//## end CSampleWH%3B76DF1100F6.postscript

// Class CSampleWH 

//## begin module%3B76DF1100F6.epilog preserve=yes
//## end module%3B76DF1100F6.epilog


#endif
