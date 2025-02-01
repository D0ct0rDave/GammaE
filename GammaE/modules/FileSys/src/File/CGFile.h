// ----------------------------------------------------------------------------
/*! \class CGFile
 *  \brief Platform independent class to read write files.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGFileH
#define CGFileH
// ----------------------------------------------------------------------------
#include "FileManager\CGFileSysManager.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGFile
{
    public:
        CGFile();

        // / Opens a given file with the given mode.
        virtual bool bOpen(const CGString& _sFilename, const EFileOpenMode _eOpenMode);

        // / Closes the file.
        virtual void Close();

        // / Reads a stream of data to the given buffer.
        virtual uint uiReadData(pointer _pData, uint _uiSize) const;

        // / Writes a stream of data using the given buffer.
        virtual uint uiWrite(pointer _pData, uint _uiSize) const;

        // / Reads a float.
        float fRead() const;

        // / Writes a float.
        void Write(float _fValue) const;

        // / Reads an integer.
        int iRead() const;

        // / Writes an integer.
        void Write(int _iValue) const;

        // / Reads an unsigned integer.
        uint uiReadData() const;

        // / Writes an unsigned integer.
        void Write(uint _uiValue) const;

        // / Reads a short.
        short sRead() const;

        // / Writes a short.
        void Write(short _sValue) const;

        // / Reads an unsigned short.
        unsigned short usRead() const;

        // / Writes an unsigned short.
        void Write(unsigned short _usValue) const;

        // / Reads a char.
        char cRead() const;

        // / Writes a char.
        void Write(char _cValue) const;

        // / Reads an unsigned short.
        unsigned char ucRead() const;

        // / Writes an unsigned char.
        void Write(unsigned char _ucValue) const;

        // / Reads an array of integers.
        void ReadArray(const int* _piBuff, uint _uiNumElems) const;

        // / Writes an array of integers.
        void WriteArray(const int* _piBuff, uint _uiNumElems) const;

        // / Reads an array of shorts.
        void ReadArray(const short* _psBuff, uint _uiNumElems) const;

        // / Writes an array of shorts.
        void WriteArray(const short* _psBuff, uint _uiNumElems) const;

        // / Reads an array of chars.
        void ReadArray(const char* _pcBuff, uint _uiNumElems) const;

        // / Writes an array of chars.
        void WriteArray(const char* _pcBuff, uint _uiNumElems) const;

        // / Reads an array of floats.
        void ReadArray(const float* _pfBuff, uint _uiNumElems) const;

        // / Writes an array of floats.
        void WriteArray(const float* _pfBuff, uint _uiNumElems) const;

        // / Moves the file pointer to a given position.
        int iSeek(int _iOffset, EFileSeekMode _eSeekMode) const;

        // / Skips a number of bytes from the current file position.
        void Skip(uint _uiBytes) const;

        // / Retrieves the current file position.
        uint uiPos() const;

        // / Retrieves the file length.
        uint uiLength() const;

        // / Writes a formated text to the file.
        void WriteText(char* fmt,...) const;

    protected:

        handler m_hHandler;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
