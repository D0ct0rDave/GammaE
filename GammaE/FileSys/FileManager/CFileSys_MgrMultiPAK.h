//## begin module%3C7E144D00EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E144D00EA.cm

//## begin module%3C7E144D00EA.cp preserve=no
//## end module%3C7E144D00EA.cp

//## Module: CFileSys_MgrMultiPAK%3C7E144D00EA; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\FileManager\CFileSys_MgrMultiPAK.h

#ifndef CFileSys_MgrMultiPAK_h
#define CFileSys_MgrMultiPAK_h 1

//## begin module%3C7E144D00EA.additionalIncludes preserve=no
//## end module%3C7E144D00EA.additionalIncludes

//## begin module%3C7E144D00EA.includes preserve=yes
//## end module%3C7E144D00EA.includes

// CFileSys_Manager
#include "FileSys\FileManager\CFileSys_Manager.h"
// CFileSys_MgrPAK
#include "FileSys\FileManager\CFileSys_MgrPAK.h"
//## begin module%3C7E144D00EA.additionalDeclarations preserve=yes
//## end module%3C7E144D00EA.additionalDeclarations


//## begin CFileSys_MgrMultiPAK%3C7E144D00EA.preface preserve=yes
//## end CFileSys_MgrMultiPAK%3C7E144D00EA.preface

//## Class: CFileSys_MgrMultiPAK%3C7E144D00EA
//## Category: FileSys::FileManager%3C7E13D00112
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CFileSys_MgrMultiPAK : public CFileSys_Manager  //## Inherits: <unnamed>%3C7E15720196
{
  //## begin CFileSys_MgrMultiPAK%3C7E144D00EA.initialDeclarations preserve=yes
  //## end CFileSys_MgrMultiPAK%3C7E144D00EA.initialDeclarations

  public:
    //## Constructors (generated)
      CFileSys_MgrMultiPAK();

    //## Destructor (generated)
      ~CFileSys_MgrMultiPAK();


    //## Other Operations (specified)
      //## Operation: iOpenFile%1014892630
      virtual FileHandler iOpenFile (char *_szFilename, char* _szMode);

      //## Operation: CloseFile%1014892631
      virtual void CloseFile (FileHandler _iHandler);

      //## Operation: iReadFile%1014892632
      virtual int iReadFile (FileHandler _iHandler, void* _pData, int _iSize);

      //## Operation: iWriteFile%1014892633
      virtual int iWriteFile (FileHandler _iHandler, void* _pData, int _iSize);

      //## Operation: iSeekFile%1014892634
      virtual int iSeekFile (FileHandler _iHandler, int _iOffset, eFile_SeekMode _eMode);

      //## Operation: iLengthFile%1014892635
      virtual int iLengthFile (FileHandler _iHandler);

      //## Operation: iPosFile%1014912978
      virtual int iPosFile (FileHandler _iHandler);

    //## Get and Set Operations for Associations (generated)

      //## Association: FileSys::FileManager::<unnamed>%3C7E145A000C
      //## Role: CFileSys_MgrMultiPAK::poPAK%3C7E145A00C2
      CFileSys_MgrPAK * GetpoPAK ();
      void SetpoPAK (CFileSys_MgrPAK * value);

    // Data Members for Associations

      //## Association: FileSys::FileManager::<unnamed>%3C7E145A000C
      //## begin CFileSys_MgrMultiPAK::poPAK%3C7E145A00C2.role preserve=no  public: CFileSys_MgrPAK { -> RHAN}
      CFileSys_MgrPAK *poPAK;
      //## end CFileSys_MgrMultiPAK::poPAK%3C7E145A00C2.role

    // Additional Public Declarations
      //## begin CFileSys_MgrMultiPAK%3C7E144D00EA.public preserve=yes
      //## end CFileSys_MgrMultiPAK%3C7E144D00EA.public

  protected:
    // Additional Protected Declarations
      //## begin CFileSys_MgrMultiPAK%3C7E144D00EA.protected preserve=yes
      //## end CFileSys_MgrMultiPAK%3C7E144D00EA.protected

  private:
    // Additional Private Declarations
      //## begin CFileSys_MgrMultiPAK%3C7E144D00EA.private preserve=yes
      //## end CFileSys_MgrMultiPAK%3C7E144D00EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFileSys_MgrMultiPAK%3C7E144D00EA.implementation preserve=yes
      //## end CFileSys_MgrMultiPAK%3C7E144D00EA.implementation

};

//## begin CFileSys_MgrMultiPAK%3C7E144D00EA.postscript preserve=yes
//## end CFileSys_MgrMultiPAK%3C7E144D00EA.postscript

// Class CFileSys_MgrMultiPAK 

//## Get and Set Operations for Associations (inline)

inline CFileSys_MgrPAK * CFileSys_MgrMultiPAK::GetpoPAK ()
{
  //## begin CFileSys_MgrMultiPAK::GetpoPAK%3C7E145A00C2.get preserve=no
  return poPAK;
  //## end CFileSys_MgrMultiPAK::GetpoPAK%3C7E145A00C2.get
}

inline void CFileSys_MgrMultiPAK::SetpoPAK (CFileSys_MgrPAK * value)
{
  //## begin CFileSys_MgrMultiPAK::SetpoPAK%3C7E145A00C2.set preserve=no
  poPAK = value;
  //## end CFileSys_MgrMultiPAK::SetpoPAK%3C7E145A00C2.set
}

//## begin module%3C7E144D00EA.epilog preserve=yes
//## end module%3C7E144D00EA.epilog


#endif
