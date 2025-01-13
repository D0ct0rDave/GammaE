//## begin module%3C7E13120227.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E13120227.cm

//## begin module%3C7E13120227.cp preserve=no
//## end module%3C7E13120227.cp

//## Module: COSFileW32%3C7E13120227; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\OSFile\COSFileW32.h

#ifndef COSFileW32_h
#define COSFileW32_h 1

//## begin module%3C7E13120227.additionalIncludes preserve=no
//## end module%3C7E13120227.additionalIncludes

//## begin module%3C7E13120227.includes preserve=yes
#include <stdio.h>
//## end module%3C7E13120227.includes

// COSFile
#include "FileSys\OSFile\COSFile.h"
//## begin module%3C7E13120227.additionalDeclarations preserve=yes
//## end module%3C7E13120227.additionalDeclarations


//## begin COSFileW32%3C7E13120227.preface preserve=yes
//## end COSFileW32%3C7E13120227.preface

//## Class: COSFileW32%3C7E13120227
//## Category: FileSys::OSFile%3C7E120001FB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class COSFileW32 : public COSFile  //## Inherits: <unnamed>%3C7E132100CB
{
  //## begin COSFileW32%3C7E13120227.initialDeclarations preserve=yes
  //## end COSFileW32%3C7E13120227.initialDeclarations

  public:
    //## Constructors (generated)
      COSFileW32();

    //## Destructor (generated)
      ~COSFileW32();


    //## Other Operations (specified)
      //## Operation: iOpenOSF%1014892594
      virtual int iOpenOSF (char *_szFilename, char* _szMode);

      //## Operation: CloseOSF%1014892595
      virtual void CloseOSF ();

      //## Operation: iReadOSF%1014892596
      virtual int iReadOSF (void* _pData, int _iSize);

      //## Operation: iWriteOSF%1014892597
      virtual int iWriteOSF (void* _pData, int _iSize);

      //## Operation: iSeekOSF%1014892598
      virtual int iSeekOSF (int _iOffset, eOSF_SeekMode _eMode);

      //## Operation: iLengthOSF%1014892599
      virtual int iLengthOSF ();

      //## Operation: iPosOSF%1014912981
      virtual int iPosOSF ();

    // Additional Public Declarations
      //## begin COSFileW32%3C7E13120227.public preserve=yes
      //## end COSFileW32%3C7E13120227.public

  protected:
    // Additional Protected Declarations
      //## begin COSFileW32%3C7E13120227.protected preserve=yes
      //## end COSFileW32%3C7E13120227.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: fd%3C7E13660110
      //## begin COSFileW32::fd%3C7E13660110.attr preserve=no  private: FILE * {UA} 
      FILE *fd;
      //## end COSFileW32::fd%3C7E13660110.attr

      //## Attribute: szFilename%3C7E1AFF0333
      //## begin COSFileW32::szFilename%3C7E1AFF0333.attr preserve=no  private: char[256] {UA} 
      char szFilename[256];
      //## end COSFileW32::szFilename%3C7E1AFF0333.attr

    // Additional Private Declarations
      //## begin COSFileW32%3C7E13120227.private preserve=yes
      //## end COSFileW32%3C7E13120227.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin COSFileW32%3C7E13120227.implementation preserve=yes
      //## end COSFileW32%3C7E13120227.implementation

};

//## begin COSFileW32%3C7E13120227.postscript preserve=yes
//## end COSFileW32%3C7E13120227.postscript

// Class COSFileW32 

//## begin module%3C7E13120227.epilog preserve=yes
//## end module%3C7E13120227.epilog


#endif
