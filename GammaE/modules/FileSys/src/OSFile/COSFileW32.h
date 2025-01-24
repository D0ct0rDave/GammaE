//	  %X% %Q% %Z% %W%



#ifndef COSFileW32_h
#define COSFileW32_h 1


#include <stdio.h>

// COSFile
#include "OSFile\COSFile.h"




class COSFileW32 : public COSFile  {
    
  public:
          COSFileW32();

          ~COSFileW32();


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
    // Data Members for Class Attributes

                  FILE *fd;
      
                  char szFilename[256];
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class COSFileW32 



#endif
