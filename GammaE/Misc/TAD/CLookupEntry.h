//## begin module%3BD352610028.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD352610028.cm

//## begin module%3BD352610028.cp preserve=no
//## end module%3BD352610028.cp

//## Module: CLookupEntry%3BD352610028; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Misc\TAD\CLookupEntry.h

#ifndef CLookupEntry_h
#define CLookupEntry_h 1

//## begin module%3BD352610028.additionalIncludes preserve=no
//## end module%3BD352610028.additionalIncludes

//## begin module%3BD352610028.includes preserve=yes
//## end module%3BD352610028.includes

//## begin module%3BD352610028.additionalDeclarations preserve=yes
//## end module%3BD352610028.additionalDeclarations


//## begin CLookupEntry%3BD352610028.preface preserve=yes
//## end CLookupEntry%3BD352610028.preface

//## Class: CLookupEntry%3BD352610028
//## Category: Misc::TAD%3BD2D0650185
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLookupEntry 
{
  //## begin CLookupEntry%3BD352610028.initialDeclarations preserve=yes
  //## end CLookupEntry%3BD352610028.initialDeclarations

  public:
    //## Constructors (generated)
      CLookupEntry();

    //## Destructor (generated)
      ~CLookupEntry();


    //## Other Operations (specified)
      //## Operation: Init%1003698096
      void Init (char *_szString, void *_pValue);

    // Data Members for Class Attributes

      //## Attribute: szString%3BD3526C0055
      //## begin CLookupEntry::szString%3BD3526C0055.attr preserve=no  public: char* {UA} NULL
      char* szString;
      //## end CLookupEntry::szString%3BD3526C0055.attr

      //## Attribute: pValue%3BD352790130
      //## begin CLookupEntry::pValue%3BD352790130.attr preserve=no  public: void * {UA} NULL
      void *pValue;
      //## end CLookupEntry::pValue%3BD352790130.attr

    // Additional Public Declarations
      //## begin CLookupEntry%3BD352610028.public preserve=yes
      //## end CLookupEntry%3BD352610028.public

  protected:
    // Additional Protected Declarations
      //## begin CLookupEntry%3BD352610028.protected preserve=yes
      //## end CLookupEntry%3BD352610028.protected

  private:
    // Additional Private Declarations
      //## begin CLookupEntry%3BD352610028.private preserve=yes
      //## end CLookupEntry%3BD352610028.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLookupEntry%3BD352610028.implementation preserve=yes
      //## end CLookupEntry%3BD352610028.implementation

};

//## begin CLookupEntry%3BD352610028.postscript preserve=yes
//## end CLookupEntry%3BD352610028.postscript

// Class CLookupEntry 

//## begin module%3BD352610028.epilog preserve=yes
//## end module%3BD352610028.epilog


#endif
