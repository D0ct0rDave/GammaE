//	  %X% %Q% %Z% %W%



#ifndef CFileSys_MgrMultiPAK_h
#define CFileSys_MgrMultiPAK_h 1



// CFileSys_Manager
#include "FileManager\CFileSys_Manager.h"
// CFileSys_MgrPAK
#include "FileManager\CFileSys_MgrPAK.h"




class CFileSys_MgrMultiPAK : public CFileSys_Manager  {
    
  public:
          CFileSys_MgrMultiPAK();

          ~CFileSys_MgrMultiPAK();


                virtual int iOpenFile (char *_szFilename, char* _szMode);

            virtual void CloseFile (int _iHandler);

            virtual int iReadFile (int _iHandler, void* _pData, int _iSize);

            virtual int iWriteFile (int _iHandler, void* _pData, int _iSize);

            virtual int iSeekFile (int _iHandler, int _iOffset, eFile_SeekMode _eMode);

            virtual int iLengthFile (int _iHandler);

            virtual int iPosFile (int _iHandler);

    
                  CFileSys_MgrPAK * GetpoPAK ();
      void SetpoPAK (CFileSys_MgrPAK * value);

    // Data Members for Associations

                  CFileSys_MgrPAK *poPAK;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CFileSys_MgrMultiPAK 


inline CFileSys_MgrPAK * CFileSys_MgrMultiPAK::GetpoPAK ()
{
    return poPAK;
}

inline void CFileSys_MgrMultiPAK::SetpoPAK (CFileSys_MgrPAK * value)
{
    poPAK = value;
}



#endif
