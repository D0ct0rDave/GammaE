//## begin module%3C7E0C780187.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E0C780187.cm

//## begin module%3C7E0C780187.cp preserve=no
//## end module%3C7E0C780187.cp

//## Module: CFileSys_Manager%3C7E0C780187; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_Manager.h

#ifndef CFileSys_Manager_h
#define CFileSys_Manager_h 1

//## begin module%3C7E0C780187.additionalIncludes preserve=no
//## end module%3C7E0C780187.additionalIncludes

//## begin module%3C7E0C780187.includes preserve=yes
//## end module%3C7E0C780187.includes

// COSFile
#include "FileSys\OSFile\COSFile.h"
// eFile_SeekMode
#include "FileSys\FileManager\eFile_SeekMode.h"
//## begin module%3C7E0C780187.additionalDeclarations preserve=yes
//## end module%3C7E0C780187.additionalDeclarations


//## begin CFileSys_Manager%3C7E0C780187.preface preserve=yes
//## end CFileSys_Manager%3C7E0C780187.preface

//## Class: CFileSys_Manager%3C7E0C780187
//## Category: FileSys::FileManager%3C7E13D00112
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7E19250197;eFile_SeekMode { -> }
//## Uses: <unnamed>%3C7E1A650238;COSFile { -> }

class CFileSys_Manager 
{
  //## begin CFileSys_Manager%3C7E0C780187.initialDeclarations preserve=yes
  using HANDLER = void*;
  //## end CFileSys_Manager%3C7E0C780187.initialDeclarations

  public:
    //## Constructors (generated)
      CFileSys_Manager();

    //## Destructor (generated)
      ~CFileSys_Manager();


    //## Other Operations (specified)
      //## Operation: iOpenFile%1014892600
      virtual HANDLER iOpenFile (char *_szFilename, char* _szMode);

      //## Operation: CloseFile%1014892601
      virtual void CloseFile (HANDLER _iHandler);

      //## Operation: iReadFile%1014892602
      virtual int iReadFile (HANDLER _iHandler, void* _pData, int _iSize);

      //## Operation: iWriteFile%1014892603
      virtual int iWriteFile (HANDLER _iHandler, void* _pData, int _iSize);

      //## Operation: iSeekFile%1014892604
      virtual int iSeekFile (HANDLER _iHandler, int _iOffset, eFile_SeekMode _eMode);

      //## Operation: iLengthFile%1014892605
      virtual int iLengthFile (HANDLER _iHandler);

      //## Operation: iPosFile%1014912979
      virtual int iPosFile (HANDLER _iHandler);

    // Additional Public Declarations
      //## begin CFileSys_Manager%3C7E0C780187.public preserve=yes
      //## end CFileSys_Manager%3C7E0C780187.public

  protected:
    // Additional Protected Declarations
      //## begin CFileSys_Manager%3C7E0C780187.protected preserve=yes
      //## end CFileSys_Manager%3C7E0C780187.protected

  private:
    // Additional Private Declarations
      //## begin CFileSys_Manager%3C7E0C780187.private preserve=yes
      //## end CFileSys_Manager%3C7E0C780187.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFileSys_Manager%3C7E0C780187.implementation preserve=yes
      //## end CFileSys_Manager%3C7E0C780187.implementation

};

//## begin CFileSys_Manager%3C7E0C780187.postscript preserve=yes
//## end CFileSys_Manager%3C7E0C780187.postscript

// Class CFileSys_Manager 

//## begin module%3C7E0C780187.epilog preserve=yes
//## end module%3C7E0C780187.epilog


#endif
