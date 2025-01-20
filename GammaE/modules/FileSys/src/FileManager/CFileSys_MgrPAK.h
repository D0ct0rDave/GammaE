//## begin module%3C7E0E6A0378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E0E6A0378.cm

//## begin module%3C7E0E6A0378.cp preserve=no
//## end module%3C7E0E6A0378.cp

//## Module: CFileSys_MgrPAK%3C7E0E6A0378; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_MgrPAK.h

#ifndef CFileSys_MgrPAK_h
#define CFileSys_MgrPAK_h 1

//## begin module%3C7E0E6A0378.additionalIncludes preserve=no
//## end module%3C7E0E6A0378.additionalIncludes

//## begin module%3C7E0E6A0378.includes preserve=yes
//## end module%3C7E0E6A0378.includes

// CFileSys_Manager
#include "FileSys\FileManager\CFileSys_Manager.h"
//## begin module%3C7E0E6A0378.additionalDeclarations preserve=yes
//## end module%3C7E0E6A0378.additionalDeclarations


//## begin CFileSys_MgrPAK%3C7E0E6A0378.preface preserve=yes
//## end CFileSys_MgrPAK%3C7E0E6A0378.preface

//## Class: CFileSys_MgrPAK%3C7E0E6A0378
//## Category: FileSys::FileManager%3C7E13D00112
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CFileSys_MgrPAK : public CFileSys_Manager  //## Inherits: <unnamed>%3C7E0E7B0015
{
  //## begin CFileSys_MgrPAK%3C7E0E6A0378.initialDeclarations preserve=yes
  //## end CFileSys_MgrPAK%3C7E0E6A0378.initialDeclarations

  public:
    //## Constructors (generated)
      CFileSys_MgrPAK();

    //## Destructor (generated)
      ~CFileSys_MgrPAK();


    //## Other Operations (specified)
      //## Operation: iOpenFile%1014892606
      virtual FileHandler iOpenFile (char *_szFilename, char* _szMode);

      //## Operation: CloseFile%1014892607
      virtual void CloseFile (FileHandler _iHandler);

      //## Operation: iReadFile%1014892608
      virtual int iReadFile (FileHandler _iHandler, void* _pData, int _iSize);

      //## Operation: iWriteFile%1014892609
      virtual int iWriteFile (FileHandler _iHandler, void* _pData, int _iSize);

      //## Operation: iSeekFile%1014892610
      virtual int iSeekFile (FileHandler _iHandler, int _iOffset, eFile_SeekMode _eMode);

      //## Operation: iLengthFile%1014892611
      virtual int iLengthFile (FileHandler _iHandler);

      //## Operation: iPosFile%1014912980
      virtual int iPosFile (FileHandler _iHandler);

    // Additional Public Declarations
      //## begin CFileSys_MgrPAK%3C7E0E6A0378.public preserve=yes
      //## end CFileSys_MgrPAK%3C7E0E6A0378.public

  protected:
    // Additional Protected Declarations
      //## begin CFileSys_MgrPAK%3C7E0E6A0378.protected preserve=yes
      //## end CFileSys_MgrPAK%3C7E0E6A0378.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: poOSFile%3C7E147903B4
      //## begin CFileSys_MgrPAK::poOSFile%3C7E147903B4.attr preserve=no  private: COSFile * {UA} 
      COSFile *poOSFile;
      //## end CFileSys_MgrPAK::poOSFile%3C7E147903B4.attr

    // Additional Private Declarations
      //## begin CFileSys_MgrPAK%3C7E0E6A0378.private preserve=yes
      //## end CFileSys_MgrPAK%3C7E0E6A0378.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFileSys_MgrPAK%3C7E0E6A0378.implementation preserve=yes
      //## end CFileSys_MgrPAK%3C7E0E6A0378.implementation

};

//## begin CFileSys_MgrPAK%3C7E0E6A0378.postscript preserve=yes
//## end CFileSys_MgrPAK%3C7E0E6A0378.postscript

// Class CFileSys_MgrPAK 

//## begin module%3C7E0E6A0378.epilog preserve=yes
//## end module%3C7E0E6A0378.epilog


#endif
