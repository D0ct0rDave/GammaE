//	  %X% %Q% %Z% %W%



#ifndef CFileSys_Manager_h
#define CFileSys_Manager_h 1



// COSFile
#include "OSFile\COSFile.h"
// eFile_SeekMode
#include "FileManager\eFile_SeekMode.h"





class CFileSys_Manager 
{
    
  public:
          CFileSys_Manager();

          ~CFileSys_Manager();


                virtual int iOpenFile (char *_szFilename, char* _szMode);

            virtual void CloseFile (int _iHandler);

            virtual int iReadFile (int _iHandler, void* _pData, int _iSize);

            virtual int iWriteFile (int _iHandler, void* _pData, int _iSize);

            virtual int iSeekFile (int _iHandler, int _iOffset, eFile_SeekMode _eMode);

            virtual int iLengthFile (int _iHandler);

            virtual int iPosFile (int _iHandler);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CFileSys_Manager 



#endif
