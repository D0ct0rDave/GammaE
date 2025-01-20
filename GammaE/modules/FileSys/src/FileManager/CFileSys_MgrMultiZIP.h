//	  %X% %Q% %Z% %W%



#ifndef CFileSys_MgrMultiZIP_h
#define CFileSys_MgrMultiZIP_h 1



// CFileSys_MgrZIP
#include "FileManager\CFileSys_MgrZIP.h"
// CFileSys_Manager
#include "FileManager\CFileSys_Manager.h"




class CFileSys_MgrMultiZIP : public CFileSys_Manager  {
    
  public:
          CFileSys_MgrMultiZIP();

          ~CFileSys_MgrMultiZIP();


                virtual int iOpenFile (char *_szFilename, char* _szMode);

            virtual void CloseFile (int _iHandler);

            virtual int iReadFile (int _iHandler, void* _pData, int _iSize);

            virtual int iWriteFile (int _iHandler, void* _pData, int _iSize);

            virtual int iSeekFile (int _iHandler, int _iOffset, eFile_SeekMode _eMode);

            virtual int iLengthFile (int _iHandler);

            virtual int iPosFile (int _iHandler);

    
                  CFileSys_MgrZIP * GetpoZIP ();
      void SetpoZIP (CFileSys_MgrZIP * value);

    // Data Members for Associations

                  CFileSys_MgrZIP *poZIP;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CFileSys_MgrMultiZIP 


inline CFileSys_MgrZIP * CFileSys_MgrMultiZIP::GetpoZIP ()
{
    return poZIP;
}

inline void CFileSys_MgrMultiZIP::SetpoZIP (CFileSys_MgrZIP * value)
{
    poZIP = value;
}



#endif
