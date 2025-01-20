//## begin module%3B74642B00BD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B74642B00BD.cm

//## begin module%3B74642B00BD.cp preserve=no
//## end module%3B74642B00BD.cp

//## Module: CChrono%3B74642B00BD; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\Timing\CChrono.h

#ifndef CChrono_h
#define CChrono_h 1

//## begin module%3B74642B00BD.additionalIncludes preserve=no
//## end module%3B74642B00BD.additionalIncludes

//## begin module%3B74642B00BD.includes preserve=yes
//## end module%3B74642B00BD.includes

//## begin module%3B74642B00BD.additionalDeclarations preserve=yes
//## end module%3B74642B00BD.additionalDeclarations


//## begin CChrono%3B74642B00BD.preface preserve=yes
//## end CChrono%3B74642B00BD.preface

//## Class: CChrono%3B74642B00BD
//## Category: Misc::Timing%3B74642101C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CChrono 
{
  //## begin CChrono%3B74642B00BD.initialDeclarations preserve=yes
  //## end CChrono%3B74642B00BD.initialDeclarations

  public:
    //## Constructors (generated)
      CChrono();

    //## Destructor (generated)
      ~CChrono();


    //## Other Operations (specified)
      //## Operation: Reset%997612244
      void Reset ();

      //## Operation: Start%997612245
      void Start ();

      //## Operation: Stop%997612246
      void Stop ();

      //## Operation: ElapsedTime%997612247
      double ElapsedTime ();

    // Additional Public Declarations
      //## begin CChrono%3B74642B00BD.public preserve=yes
      //## end CChrono%3B74642B00BD.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: dStartTime%3B765B940234
      //## begin CChrono::dStartTime%3B765B940234.attr preserve=no  protected: double {UA} 0
      double dStartTime;
      //## end CChrono::dStartTime%3B765B940234.attr

      //## Attribute: dChronoFrequency%3B765BAF021F
      //## begin CChrono::dChronoFrequency%3B765BAF021F.attr preserve=no  protected: double {UA} 1
      double dChronoFrequency;
      //## end CChrono::dChronoFrequency%3B765BAF021F.attr

      //## Attribute: dElapsedTime%3B765BD901CF
      //## begin CChrono::dElapsedTime%3B765BD901CF.attr preserve=no  protected: double {UA} 0
      double dElapsedTime;
      //## end CChrono::dElapsedTime%3B765BD901CF.attr

      //## Attribute: bActive%3B765D850315
      //## begin CChrono::bActive%3B765D850315.attr preserve=no  protected: bool {UA} false
      bool bActive;
      //## end CChrono::bActive%3B765D850315.attr

    // Additional Protected Declarations
      //## begin CChrono%3B74642B00BD.protected preserve=yes
      //## end CChrono%3B74642B00BD.protected

  private:
    // Additional Private Declarations
      //## begin CChrono%3B74642B00BD.private preserve=yes
      //## end CChrono%3B74642B00BD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CChrono%3B74642B00BD.implementation preserve=yes
      //## end CChrono%3B74642B00BD.implementation

};

//## begin CChrono%3B74642B00BD.postscript preserve=yes
//## end CChrono%3B74642B00BD.postscript

// Class CChrono 

//## begin module%3B74642B00BD.epilog preserve=yes
//## end module%3B74642B00BD.epilog


#endif
