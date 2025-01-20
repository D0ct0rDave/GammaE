//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CHTMLParser%3B65CB11028A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\CHTMLParser.h

#ifndef CHTMLParser_H
#define CHTMLParser_H 1

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
//## end module%3B65CB11028A.includes

//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
//## end module%3B65CB11028A.additionalDeclarations


//## begin CHTMLParser%3B65CB11028A.preface preserve=yes
//## end CHTMLParser%3B65CB11028A.preface

//## Class: CHTMLParser%3B65CB11028A
//## Category: Game%3B5DE98D0118
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B770BC40318;CParticleSystemMgr { -> }
//## Uses: <unnamed>%3B770BC702B8;CBackgroundMgr { -> }
#include "GammaE.h"
// ----------------------------------------------------------------------------
class CHTMLParser  //## Inherits: <unnamed>%3B65CB820384
{
  //## begin CHTMLParser%3B65CB11028A.initialDeclarations preserve=yes
  //## end CHTMLParser%3B65CB11028A.initialDeclarations

  public:
    //## Constructors (generated)
      CHTMLParser();

    //## Destructor (generated)
      ~CHTMLParser();


    //## Other Operations (specified)
      //## Operation: InitScene%997655858
		static CObject3D* poInit(char* _szFilename,char* _szRootDir);

    // Additional Public Declarations
      //## begin CHTMLParser%3B65CB11028A.public preserve=yes
      //## end CHTMLParser%3B65CB11028A.public

  protected:
    // Additional Protected Declarations
      //## begin CHTMLParser%3B65CB11028A.protected preserve=yes
      //## end CHTMLParser%3B65CB11028A.protected

  private:
    // Additional Private Declarations
      //## begin CHTMLParser%3B65CB11028A.private preserve=yes
      //## end CHTMLParser%3B65CB11028A.private

  private: //## implementation
    // Data Members for Associations

};

//## begin CHTMLParser%3B65CB11028A.postscript preserve=yes
//## end CHTMLParser%3B65CB11028A.postscript

// Class CHTMLParser 
#endif
