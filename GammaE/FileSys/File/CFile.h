//## begin module%3C7E0C860264.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7E0C860264.cm

//## begin module%3C7E0C860264.cp preserve=no
//## end module%3C7E0C860264.cp

//## Module: CFile%3C7E0C860264; Pseudo Package specification
//## Source file: i:\Projects\GammaE\FileSys\File\CFile.h

#ifndef CFile_h
#define CFile_h 1

//## begin module%3C7E0C860264.additionalIncludes preserve=no
//## end module%3C7E0C860264.additionalIncludes

//## begin module%3C7E0C860264.includes preserve=yes
//## end module%3C7E0C860264.includes

// CFileSys_Manager
#include "FileSys\FileManager\CFileSys_Manager.h"
//## begin module%3C7E0C860264.additionalDeclarations preserve=yes
//## end module%3C7E0C860264.additionalDeclarations


//## begin CFile%3C7E0C860264.preface preserve=yes
//## end CFile%3C7E0C860264.preface

//## Class: CFile%3C7E0C860264
//## Category: FileSys::File%3C7E13CC006C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7E0C9803AA;CFileSys_Manager { -> }

class CFile 
{
  //## begin CFile%3C7E0C860264.initialDeclarations preserve=yes
  //## end CFile%3C7E0C860264.initialDeclarations

  public:
    //## Constructors (generated)
      CFile();

    //## Destructor (generated)
      ~CFile();


    //## Other Operations (specified)
      //## Operation: iOpen%1014892612
      virtual int iOpen (char *_szFilename, char* _szMode);

      //## Operation: Close%1014892613
      virtual void Close ();

      //## Operation: iRead%1014892614
      virtual int iRead (void* _pData, int _iSize);

      //## Operation: iWrite%1014892615
      virtual int iWrite (void* _pData, int _iSize);

      //## Operation: fRead%1017566936
      float fRead ();

      //## Operation: Write%1017566937
      void Write (float _fValue);

      //## Operation: Write%1017566924
      void Write (int _iValue);

      //## Operation: iRead%1017566925
      int iRead ();

      //## Operation: Write%1017566926
      void Write (short _sValue);

      //## Operation: sRead%1017566927
      short sRead ();

      //## Operation: Write%1017566928
      void Write (char _cValue);

      //## Operation: cRead%1017566929
      char cRead ();

      //## Operation: ReadIntArray%1017566930
      void ReadIntArray (int *_piBuff, int _iNumElems);

      //## Operation: WriteIntArray%1017566931
      void WriteIntArray (int *_piBuff, int _iNumElems);

      //## Operation: ReadShortArray%1017566932
      void ReadShortArray (short *_psBuff, int _iNumElems);

      //## Operation: WriteShortArray%1017566933
      void WriteShortArray (short *_psBuff, int _iNumElems);

      //## Operation: ReadCharArray%1017566934
      void ReadCharArray (char *_pcBuff, int _iNumElems);

      //## Operation: WriteCharArray%1017566935
      void WriteCharArray (char *_pcBuff, int _iNumElems);

      //## Operation: ReadFloatArray%1017566938
      void ReadFloatArray (float *_pfBuff, int _iNumElems);

      //## Operation: WriteFloatArray%1017566939
      void WriteFloatArray (float *_pfBuff, int _iNumElems);

      //## Operation: iSeek%1014892616
      virtual int iSeek (int _iOffset, eFile_SeekMode _eMode);

      //## Operation: iLength%1014892617
      virtual int iLength ();

      //## Operation: iPos%1014912983
      virtual int iPos ();

    // Additional Public Declarations
      //## begin CFile%3C7E0C860264.public preserve=yes
      //## end CFile%3C7E0C860264.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iHandler%3C7E0E010255
      //## begin CFile::iHandler%3C7E0E010255.attr preserve=no  protected: int {UA} 
      using HANDLER = void*;
      HANDLER iHandler;
      //## end CFile::iHandler%3C7E0E010255.attr

    // Additional Protected Declarations
      //## begin CFile%3C7E0C860264.protected preserve=yes
      //## end CFile%3C7E0C860264.protected

  private:
    // Additional Private Declarations
      //## begin CFile%3C7E0C860264.private preserve=yes
      //## end CFile%3C7E0C860264.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CFile%3C7E0C860264.implementation preserve=yes
      //## end CFile%3C7E0C860264.implementation

};

//## begin CFile%3C7E0C860264.postscript preserve=yes
//## end CFile%3C7E0C860264.postscript

// Class CFile 

//## begin module%3C7E0C860264.epilog preserve=yes
//## end module%3C7E0C860264.epilog


#endif
