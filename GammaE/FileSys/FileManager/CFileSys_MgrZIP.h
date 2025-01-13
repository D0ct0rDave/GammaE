//## begin module%3C7E14BE02FF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E14BE02FF.cm

//## begin module%3C7E14BE02FF.cp preserve=no
//## end module%3C7E14BE02FF.cp

//## Module: CFileSys_MgrZIP%3C7E14BE02FF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_MgrZIP.h

#ifndef CFileSys_MgrZIP_h
#define CFileSys_MgrZIP_h 1

//## begin module%3C7E14BE02FF.additionalIncludes preserve=no
//## end module%3C7E14BE02FF.additionalIncludes

//## begin module%3C7E14BE02FF.includes preserve=yes
//## end module%3C7E14BE02FF.includes

// CFileSys_Manager
#include "FileSys\FileManager\CFileSys_Manager.h"
//## begin module%3C7E14BE02FF.additionalDeclarations preserve=yes
//## end module%3C7E14BE02FF.additionalDeclarations


//## begin CFileSys_MgrZIP%3C7E14BE02FF.preface preserve=yes
//## end CFileSys_MgrZIP%3C7E14BE02FF.preface

//## Class: CFileSys_MgrZIP%3C7E14BE02FF
//## Category: FileSys::FileManager%3C7E13D00112
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CFileSys_MgrZIP : public CFileSys_Manager  //## Inherits: <unnamed>%3C7E14C701FE
{
  //## begin CFileSys_MgrZIP%3C7E14BE02FF.initialDeclarations preserve=yes
  //## end CFileSys_MgrZIP%3C7E14BE02FF.initialDeclarations

  public:
    //## Constructors (generated)
      CFileSys_MgrZIP();

    //## Destructor (generated)
      ~CFileSys_MgrZIP();


    //## Other Operations (specified)
      //## Operation: iOpenFile%1014892624
      virtual int iOpenFile (char *_szFilename, char* _szMode);

      //## Operation: CloseFile%1014892625
      virtual void CloseFile (int _iHandler);

      //## Operation: iReadFile%1014892626
      virtual int iReadFile (int _iHandler, void* _pData, int _iSize);

      //## Operation: iWriteFile%1014892627
      virtual int iWriteFile (int _iHandler, void* _pData, int _iSize);

      //## Operation: iSeekFile%1014892628
      virtual int iSeekFile (int _iHandler, int _iOffset, eFile_SeekMode _eMode);

      //## Operation: iLengthFile%1014892629
      virtual int iLengthFile (int _iHandler);

      //## Operation: iPosFile%1014912977
      virtual int iPosFile (int _iHandler);

    // Additional Public Declarations
      //## begin CFileSys_MgrZIP%3C7E14BE02FF.public preserve=yes
      //## end CFileSys_MgrZIP%3C7E14BE02FF.public

  protected:
    // Additional Protected Declarations
      //## begin CFileSys_MgrZIP%3C7E14BE02FF.protected preserve=yes
      //## end CFileSys_MgrZIP%3C7E14BE02FF.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poOSFile%3C7E15A1039C
      //## begin CFileSys_MgrZIP::poOSFile%3C7E15A1039C.attr preserve=no  private: COSFile * {UA} 
      COSFile *poOSFile;
      //## end CFileSys_MgrZIP::poOSFile%3C7E15A1039C.attr

    // Additional Private Declarations
      //## begin CFileSys_MgrZIP%3C7E14BE02FF.private preserve=yes
      //## end CFileSys_MgrZIP%3C7E14BE02FF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFileSys_MgrZIP%3C7E14BE02FF.implementation preserve=yes
      //## end CFileSys_MgrZIP%3C7E14BE02FF.implementation

};

//## begin CFileSys_MgrZIP%3C7E14BE02FF.postscript preserve=yes
//## end CFileSys_MgrZIP%3C7E14BE02FF.postscript

// Class CFileSys_MgrZIP 

//## begin module%3C7E14BE02FF.epilog preserve=yes
//## end module%3C7E14BE02FF.epilog


#endif
