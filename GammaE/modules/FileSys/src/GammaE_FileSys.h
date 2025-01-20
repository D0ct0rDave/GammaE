//## begin module%3C7E13B20340.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E13B20340.cm

//## begin module%3C7E13B20340.cp preserve=no
//## end module%3C7E13B20340.cp

//## Module: GammaE_FileSys%3C7E13B20340; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\GammaE_FileSys.h

#ifndef GammaE_FileSys_h
#define GammaE_FileSys_h 1

//## begin module%3C7E13B20340.additionalIncludes preserve=no
//## end module%3C7E13B20340.additionalIncludes

//## begin module%3C7E13B20340.includes preserve=yes
#include "FileUtils/CFileUtils.h"

#include "FileSys/File/CFile.h"
#include "FileSys/File/FILEMgr.h"

#include "FileSys/FileManager/CFileSys_Manager.h"
#include "FileSys/FileManager/CFileSys_MgrPAK.h"
#include "FileSys/FileManager/CFileSys_MgrMultiPAK.h"
#include "FileSys/FileManager/CFileSys_MgrZIP.h"
#include "FileSys/FileManager/CFileSys_MgrMultiZIP.h"
#include "FileSys/FileManager/CFileSys_MgrMultiZIP.h"

#include "FileSys/FileManager/OSFile.h"
//## end module%3C7E13B20340.includes

//## begin module%3C7E13B20340.additionalDeclarations preserve=yes
//## end module%3C7E13B20340.additionalDeclarations


//## Class: GammaE_FileSys%3C7E13B20340
//## Category: FileSys%3C7E0C6003A9
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class GammaE_FileSys 
{
  public:
    //## Constructors (generated)
      GammaE_FileSys();

    //## Destructor (generated)
      ~GammaE_FileSys();

  protected:
  private:
  private: //## implementation
};

// Class GammaE_FileSys 

//## begin module%3C7E13B20340.epilog preserve=yes
//## end module%3C7E13B20340.epilog


#endif
