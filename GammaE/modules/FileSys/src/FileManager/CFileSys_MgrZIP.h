//	  %X% %Q% %Z% %W%



#ifndef CFileSys_MgrZIP_h
#define CFileSys_MgrZIP_h 1



// CFileSys_Manager
#include "FileManager\CFileSys_Manager.h"




class CFileSys_MgrZIP : public CFileSys_Manager  {
    
  public:
          CFileSys_MgrZIP();

          ~CFileSys_MgrZIP();


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
    // Data Members for Class Attributes

                  COSFile *poOSFile;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CFileSys_MgrZIP 



#endif
