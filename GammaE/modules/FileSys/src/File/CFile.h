//	  %X% %Q% %Z% %W%
#ifndef CFile_h
#define CFile_h 1

// CFileSys_Manager
#include "FileManager\CFileSys_Manager.h"
#include "GammaE_Misc.h"

class CFile 
{   
  public:
          CFile();

          ~CFile();

            virtual bool bOpen (const char *_szFilename, char* _szMode);

            virtual void Close ();
            virtual int iRead (void* _pData, int _iSize);

            virtual int iWrite (void* _pData, int _iSize);

            float fRead ();

            void Write (float _fValue);

            void Write (int _iValue);

            int iRead ();

            void Write (short _sValue);

            short sRead ();

            void Write (char _cValue);

            char cRead ();

            void ReadIntArray (int *_piBuff, int _iNumElems);

            void WriteIntArray (int *_piBuff, int _iNumElems);

            void ReadShortArray (short *_psBuff, int _iNumElems);

            void WriteShortArray (short *_psBuff, int _iNumElems);

            void ReadCharArray (char *_pcBuff, int _iNumElems);

            void WriteCharArray (char *_pcBuff, int _iNumElems);

            void ReadFloatArray (float *_pfBuff, int _iNumElems);

            void WriteFloatArray (float *_pfBuff, int _iNumElems);

            virtual uint uiSeek (int _iOffset, eFile_SeekMode _eMode);
      
			virtual void Skip(unsigned int _uiBytes);

            virtual uint uiLength ();

            virtual uint uiPos ();

    // Additional Public Declarations
            virtual void WriteText(char*fmt,...);
      
  protected:
    // Data Members for Class Attributes

                  int iHandler;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};

// Class CFile 

#endif
