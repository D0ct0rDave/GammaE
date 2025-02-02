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

#ifndef CLMSector_RGB24_h
#define CLMSector_RGB24_h 1

// CLMSector
#include "Sector\CLMSector.h"

class CLMSector_RGB24 : public CLMSector
{
    public:
        CLMSector_RGB24();

        virtual ~CLMSector_RGB24();

        virtual CSectElem & GetValue(int _X, int _Y);

        virtual void SetValue(int _X, int _Y, CSectElem &_Value);

        virtual CSector* CreateClass();

        virtual unsigned long ElemArraySize(int _iResolution);

        // Gets the raw data of a given LOD
        virtual void GetLODData(int _iLOD, void* _pData);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CLMSector_RGB24

#endif
