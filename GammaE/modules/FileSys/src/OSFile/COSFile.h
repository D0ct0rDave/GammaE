//	  %X% %Q% %Z% %W%



#ifndef COSFile_h
#define COSFile_h 1



// eOSF_SeekMode
#include "OSFile\eOSF_SeekMode.h"





class COSFile 
{
    
  public:
          COSFile();

          ~COSFile();


                virtual int iOpenOSF (char *_szFilename, char* _szMode);

            virtual void CloseOSF ();

            virtual int iReadOSF (void* _pData, int _iSize);

            virtual int iWriteOSF (void* _pData, int _iSize);

            virtual int iSeekOSF (int _iOffset, eOSF_SeekMode _eMode);

            virtual int iLengthOSF ();

            virtual int iPosOSF ();

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class COSFile 



#endif
