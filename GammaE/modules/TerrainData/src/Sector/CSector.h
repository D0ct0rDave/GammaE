// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

#ifndef CSector_h
#define CSector_h 1

#include <stdlib.h>
#include <stdio.h>
#include "GammaE_FileSys.h"

// CSectElem
#include "SectElem\CSectElem.h"
typedef enum
{
    eGM_Nearest,
    eGM_Linear,
    eGM_CosLinear,

    eGM_NumGenMethods
}EGenerationMethod;

class CSector
{
    public:
        CSector();

        virtual ~CSector();

        const CSector & operator=(const CSector &right);

        // Initializes data according the given characteristics.
        virtual void Init(int _iRes, bool _b21);

        // Erases and invalidates the data stored into the current
        // class
        virtual void Invalidate();

        // Gets the file identifier of the current class
        virtual unsigned long GetID();

        // The size of the entire object in disk.
        virtual unsigned long ByteSize();

        // Gets the value of a specific element inside the data
        virtual CSectElem & GetValue(int _X, int _Y) = 0;

        // Sets the value of a specific element inside the data
        virtual void SetValue(int _X, int _Y, CSectElem &_Value) = 0;

        virtual CSectElem & GetValueF(float _fX, float _fY);

        // Generates a new object with  data corresponding to a
        // given LOD
        virtual CSector* GenerateLOD(int _iLOD);

        // Gets the raw data of a given LOD
        virtual void GetLODData(int _iLOD, void* _pData);

        // Loads an object from the given file
        virtual int iLoad(char* _Filename);

        // Loads and initializes object data, from disk.
        virtual int iLoadWithHandler(FILE* _FD);

        // Save the entire object inside the given file
        virtual int iSave(char* _Filename);

        // Save the object contents into a file, associated to the
        // current file descriptor
        virtual int iSaveWithHandler(FILE* _FD);

        // The size of the data from this object
        virtual unsigned long DataSize();

        // Creates a new object of the same class as the current
        // object
        virtual CSector* CreateClass() = 0;

        // The equivalent size for an object of the given
        // characteristics.
        virtual unsigned long ElemArraySize(int _iResolution);

        EGenerationMethod GetVGenMethod();
        void SetVGenMethod(EGenerationMethod value);

        int GetResolution();

        // Data Members for Class Attributes

        EGenerationMethod VGenMethod;

        int Resolution;

        // Additional Public Declarations

    protected:

        bool Getb21();

        // Data Members for Class Attributes

        unsigned long ulID;

        void* pData;

        unsigned char ucMajVer;

        unsigned char ucMinVer;

        bool b21;

        int iLast;

        // Additional Protected Declarations

    private:

        CSectElem & GetValueLOD(int _X, int _Y, int _iLOD);

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSector

inline unsigned long CSector::GetID ()
{
    return(ulID);
}

inline EGenerationMethod CSector::GetVGenMethod ()
{
    return(VGenMethod);
}

inline void CSector::SetVGenMethod (EGenerationMethod value)
{
    VGenMethod = value;
}

inline int CSector::GetResolution ()
{
    return(Resolution);
}

inline bool CSector::Getb21 ()
{
    return(b21);
}

#endif
