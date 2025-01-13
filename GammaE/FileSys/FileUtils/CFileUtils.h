//## begin module%3C7EA4E00311.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7EA4E00311.cm

//## begin module%3C7EA4E00311.cp preserve=no
//## end module%3C7EA4E00311.cp

//## Module: CFileUtils%3C7EA4E00311; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileUtils\CFileUtils.h

#ifndef CFileUtils_h
#define CFileUtils_h 1

//## begin module%3C7EA4E00311.additionalIncludes preserve=no
//## end module%3C7EA4E00311.additionalIncludes

//## begin module%3C7EA4E00311.includes preserve=yes
//## end module%3C7EA4E00311.includes

// CFile
#include "FileSys\File\CFile.h"
//## begin module%3C7EA4E00311.additionalDeclarations preserve=yes

//------------------------------------------------------------------------------
#ifndef     MAKE_RIFF_ID
#define     MAKE_RIFF_ID(a,b,c,d)  ((a) | (b << 8) | (c <<16) | (d << 24))
#endif
//------------------------------------------------------------------------------

//## end module%3C7EA4E00311.additionalDeclarations


//## begin CFileUtils%3C7EA4E00311.preface preserve=yes
//## end CFileUtils%3C7EA4E00311.preface

//## Class: CFileUtils%3C7EA4E00311
//## Category: FileSys::FileUtils%3C7EA4D401F1
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7EA5790180;CFile { -> }

class CFileUtils 
{
  //## begin CFileUtils%3C7EA4E00311.initialDeclarations preserve=yes
  //## end CFileUtils%3C7EA4E00311.initialDeclarations

  public:
    //## Constructors (generated)
      CFileUtils();

    //## Destructor (generated)
      ~CFileUtils();


    //## Other Operations (specified)
      //## Operation: BeginRIFFBlock%1014932975
      static void BeginRIFFBlock (unsigned int _uiID, CFile& _roFile);

      //## Operation: EndRIFFBlock%1014932976
      static void EndRIFFBlock (CFile& _roFile);

    // Additional Public Declarations
      //## begin CFileUtils%3C7EA4E00311.public preserve=yes
      //## end CFileUtils%3C7EA4E00311.public

  protected:
    // Additional Protected Declarations
      //## begin CFileUtils%3C7EA4E00311.protected preserve=yes
      //## end CFileUtils%3C7EA4E00311.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: uiBlockLenPos%3C7EA63601AA
      //## begin CFileUtils::uiBlockLenPos%3C7EA63601AA.attr preserve=no  private: static unsigned int [256] {UA} 
      static unsigned int  uiBlockLenPos[256];
      //## end CFileUtils::uiBlockLenPos%3C7EA63601AA.attr

      //## Attribute: uiBLIdx%3C7EA6EF03A5
      //## begin CFileUtils::uiBLIdx%3C7EA6EF03A5.attr preserve=no  private: static int {UA} -1
      static int uiBLIdx;
      //## end CFileUtils::uiBLIdx%3C7EA6EF03A5.attr

    // Additional Private Declarations
      //## begin CFileUtils%3C7EA4E00311.private preserve=yes
      //## end CFileUtils%3C7EA4E00311.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFileUtils%3C7EA4E00311.implementation preserve=yes
      //## end CFileUtils%3C7EA4E00311.implementation

};

//## begin CFileUtils%3C7EA4E00311.postscript preserve=yes
//## end CFileUtils%3C7EA4E00311.postscript

// Class CFileUtils 

//## begin module%3C7EA4E00311.epilog preserve=yes
//## end module%3C7EA4E00311.epilog


#endif
