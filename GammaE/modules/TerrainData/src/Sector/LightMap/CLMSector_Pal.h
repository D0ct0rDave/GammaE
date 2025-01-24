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

#ifndef CLMSector_Pal_h
#define CLMSector_Pal_h 1

// CLMSector
#include "Sector\CLMSector.h"

class CLMSector_Pal : public CLMSector
{
    public:
        CLMSector_Pal();

        virtual ~CLMSector_Pal();

        virtual CSectElem & GetValue(int _X, int _Y);

        virtual void SetValue(int _X, int _Y, CSectElem &_Value);

        virtual unsigned long DataSize();

        virtual CSector* CreateClass();

        void set_Pal(char* _Pal);

        virtual unsigned long ElemArraySize(int _iResolution);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        char Pal[768];

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CLMSector_Pal

#endif
