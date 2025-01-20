//## begin module%3C7E14E8006B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E14E8006B.cm

//## begin module%3C7E14E8006B.cp preserve=no
//## end module%3C7E14E8006B.cp

//## Module: CFileSys_MgrMultiZIP%3C7E14E8006B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_MgrMultiZIP.h

#ifndef CFileSys_MgrMultiZIP_h
#define CFileSys_MgrMultiZIP_h 1

//## begin module%3C7E14E8006B.additionalIncludes preserve=no
//## end module%3C7E14E8006B.additionalIncludes

//## begin module%3C7E14E8006B.includes preserve=yes
//## end module%3C7E14E8006B.includes

// CFileSys_MgrZIP
#include "FileSys\FileManager\CFileSys_MgrZIP.h"
// CFileSys_Manager
#include "FileSys\FileManager\CFileSys_Manager.h"
//## begin module%3C7E14E8006B.additionalDeclarations preserve=yes
//## end module%3C7E14E8006B.additionalDeclarations


//## begin CFileSys_MgrMultiZIP%3C7E14E8006B.preface preserve=yes
//## end CFileSys_MgrMultiZIP%3C7E14E8006B.preface

//## Class: CFileSys_MgrMultiZIP%3C7E14E8006B
//## Category: FileSys::FileManager%3C7E13D00112
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CFileSys_MgrMultiZIP : public CFileSys_Manager  //## Inherits: <unnamed>%3C7E150F01A7
{
  //## begin CFileSys_MgrMultiZIP%3C7E14E8006B.initialDeclarations preserve=yes
  //## end CFileSys_MgrMultiZIP%3C7E14E8006B.initialDeclarations

  public:
    //## Constructors (generated)
      CFileSys_MgrMultiZIP();

    //## Destructor (generated)
      ~CFileSys_MgrMultiZIP();


    //## Other Operations (specified)
      //## Operation: iOpenFile%1014892618
      virtual FileHandler iOpenFile (char *_szFilename, char* _szMode);

      //## Operation: CloseFile%1014892619
      virtual void CloseFile (FileHandler _iHandler);

      //## Operation: iReadFile%1014892620
      virtual int iReadFile (FileHandler _iHandler, void* _pData, int _iSize);

      //## Operation: iWriteFile%1014892621
      virtual int iWriteFile (FileHandler _iHandler, void* _pData, int _iSize);

      //## Operation: iSeekFile%1014892622
      virtual int iSeekFile (FileHandler _iHandler, int _iOffset, eFile_SeekMode _eMode);

      //## Operation: iLengthFile%1014892623
      virtual int iLengthFile (FileHandler _iHandler);

      //## Operation: iPosFile%1014912976
      virtual int iPosFile (FileHandler _iHandler);

    //## Get and Set Operations for Associations (generated)

      //## Association: FileSys::FileManager::<unnamed>%3C7E14F70080
      //## Role: CFileSys_MgrMultiZIP::poZIP%3C7E14F70211
      CFileSys_MgrZIP * GetpoZIP ();
      void SetpoZIP (CFileSys_MgrZIP * value);

    // Data Members for Associations

      //## Association: FileSys::FileManager::<unnamed>%3C7E14F70080
      //## begin CFileSys_MgrMultiZIP::poZIP%3C7E14F70211.role preserve=no  public: CFileSys_MgrZIP { -> RHAN}
      CFileSys_MgrZIP *poZIP;
      //## end CFileSys_MgrMultiZIP::poZIP%3C7E14F70211.role

    // Additional Public Declarations
      //## begin CFileSys_MgrMultiZIP%3C7E14E8006B.public preserve=yes
      //## end CFileSys_MgrMultiZIP%3C7E14E8006B.public

  protected:
    // Additional Protected Declarations
      //## begin CFileSys_MgrMultiZIP%3C7E14E8006B.protected preserve=yes
      //## end CFileSys_MgrMultiZIP%3C7E14E8006B.protected

  private:
    // Additional Private Declarations
      //## begin CFileSys_MgrMultiZIP%3C7E14E8006B.private preserve=yes
      //## end CFileSys_MgrMultiZIP%3C7E14E8006B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFileSys_MgrMultiZIP%3C7E14E8006B.implementation preserve=yes
      //## end CFileSys_MgrMultiZIP%3C7E14E8006B.implementation

};

//## begin CFileSys_MgrMultiZIP%3C7E14E8006B.postscript preserve=yes
//## end CFileSys_MgrMultiZIP%3C7E14E8006B.postscript

// Class CFileSys_MgrMultiZIP 

//## Get and Set Operations for Associations (inline)

inline CFileSys_MgrZIP * CFileSys_MgrMultiZIP::GetpoZIP ()
{
  //## begin CFileSys_MgrMultiZIP::GetpoZIP%3C7E14F70211.get preserve=no
  return poZIP;
  //## end CFileSys_MgrMultiZIP::GetpoZIP%3C7E14F70211.get
}

inline void CFileSys_MgrMultiZIP::SetpoZIP (CFileSys_MgrZIP * value)
{
  //## begin CFileSys_MgrMultiZIP::SetpoZIP%3C7E14F70211.set preserve=no
  poZIP = value;
  //## end CFileSys_MgrMultiZIP::SetpoZIP%3C7E14F70211.set
}

//## begin module%3C7E14E8006B.epilog preserve=yes
//## end module%3C7E14E8006B.epilog


#endif
