//## begin module%3C7E12060290.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E12060290.cm

//## begin module%3C7E12060290.cp preserve=no
//## end module%3C7E12060290.cp

//## Module: COSFile%3C7E12060290; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\OSFile\COSFile.h

#ifndef COSFile_h
#define COSFile_h 1

//## begin module%3C7E12060290.additionalIncludes preserve=no
//## end module%3C7E12060290.additionalIncludes

//## begin module%3C7E12060290.includes preserve=yes
//## end module%3C7E12060290.includes

// eOSF_SeekMode
#include "FileSys\OSFile\eOSF_SeekMode.h"
//## begin module%3C7E12060290.additionalDeclarations preserve=yes
//## end module%3C7E12060290.additionalDeclarations


//## begin COSFile%3C7E12060290.preface preserve=yes
//## end COSFile%3C7E12060290.preface

//## Class: COSFile%3C7E12060290
//## Category: FileSys::OSFile%3C7E120001FB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7E12F6019B;eOSF_SeekMode { -> }

class COSFile 
{
  //## begin COSFile%3C7E12060290.initialDeclarations preserve=yes
  //## end COSFile%3C7E12060290.initialDeclarations

  public:
    //## Constructors (generated)
      COSFile();

    //## Destructor (generated)
      ~COSFile();


    //## Other Operations (specified)
      //## Operation: iOpenOSF%1014892588
      virtual int iOpenOSF (char *_szFilename, char* _szMode);

      //## Operation: CloseOSF%1014892589
      virtual void CloseOSF ();

      //## Operation: iReadOSF%1014892590
      virtual int iReadOSF (void* _pData, int _iSize);

      //## Operation: iWriteOSF%1014892591
      virtual int iWriteOSF (void* _pData, int _iSize);

      //## Operation: iSeekOSF%1014892592
      virtual int iSeekOSF (int _iOffset, eOSF_SeekMode _eMode);

      //## Operation: iLengthOSF%1014892593
      virtual int iLengthOSF ();

      //## Operation: iPosOSF%1014912982
      virtual int iPosOSF ();

    // Additional Public Declarations
      //## begin COSFile%3C7E12060290.public preserve=yes
      //## end COSFile%3C7E12060290.public

  protected:
    // Additional Protected Declarations
      //## begin COSFile%3C7E12060290.protected preserve=yes
      //## end COSFile%3C7E12060290.protected

  private:
    // Additional Private Declarations
      //## begin COSFile%3C7E12060290.private preserve=yes
      //## end COSFile%3C7E12060290.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin COSFile%3C7E12060290.implementation preserve=yes
      //## end COSFile%3C7E12060290.implementation

};

//## begin COSFile%3C7E12060290.postscript preserve=yes
//## end COSFile%3C7E12060290.postscript

// Class COSFile 

//## begin module%3C7E12060290.epilog preserve=yes
//## end module%3C7E12060290.epilog


#endif
