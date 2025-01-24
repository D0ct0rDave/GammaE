//	  %X% %Q% %Z% %W%



#ifndef CFileSys_Manager_h
#define CFileSys_Manager_h 1


#include "GammaE_Misc.h"
// COSFile
#include "OSFile\COSFile.h"
// eFile_SeekMode
#include "FileManager\eFile_SeekMode.h"





class CFileSys_Manager 
{
    
  public:
          CFileSys_Manager();

          ~CFileSys_Manager();


                virtual handler iOpenFile (char *_szFilename, char* _szMode);

            virtual void CloseFile (handler _iHandler);

            virtual int iReadFile (handler _iHandler, void* _pData, int _iSize);

            virtual int iWriteFile (handler _iHandler, void* _pData, int _iSize);

            virtual int iSeekFile (handler _iHandler, int _iOffset, eFile_SeekMode _eMode);

            virtual int iLengthFile (handler _iHandler);

            virtual int iPosFile (handler _iHandler);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CFileSys_Manager 



#endif
