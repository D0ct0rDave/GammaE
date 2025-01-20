//	  %X% %Q% %Z% %W%



#ifndef CFileUtils_h
#define CFileUtils_h 1



// CFile
#include "File\CFile.h"

//-----------------------------------------------------------------------------
#ifndef     MAKE_RIFF_ID
#define     MAKE_RIFF_ID(a,b,c,d)  ((a) | (b << 8) | (c <<16) | (d << 24))
#endif
//-----------------------------------------------------------------------------






class CFileUtils 
{
    
  public:
          CFileUtils();

          ~CFileUtils();


                static void BeginRIFFBlock (unsigned int _uiID, CFile& _oFile);

            static void EndRIFFBlock (CFile& _oFile);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  static unsigned int  uiBlockLenPos[256];
      
                  static int uiBLIdx;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CFileUtils 



#endif
