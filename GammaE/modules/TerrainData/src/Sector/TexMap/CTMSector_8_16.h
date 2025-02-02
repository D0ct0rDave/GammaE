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

#ifndef CTMSector_8_16_h
#define CTMSector_8_16_h 1

// CTMSector
#include "Sector\CTMSector.h"

class CTMSector_8_16 : public CTMSector
{
    public:
        CTMSector_8_16();

        ~CTMSector_8_16();

        virtual CSector* CreateClass();

        virtual unsigned long ElemArraySize(int _iResolution);

        virtual CSectElem & GetValue(int _X, int _Y);

        virtual void SetValue(int _X, int _Y, CSectElem &_Value);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTMSector_8_16

#endif
