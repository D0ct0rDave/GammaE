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

#ifndef CHeight_h
#define CHeight_h 1

// CSectElem
#include "SectElem\CSectElem.h"

class CHeight : public CSectElem
{
    public:
        CHeight();

        ~CHeight();

        virtual unsigned long ByteSize();

        virtual CSectElem & Sum(CSectElem &a, CSectElem &b);

        virtual CSectElem & Mult(CSectElem &a, CSectElem &b);

        virtual CSectElem & LinInterpolate(CSectElem &a, CSectElem &b, float fFactor);

        virtual CSectElem & CosInterpolate(CSectElem &a, CSectElem &b, float fFactor);

        virtual void* Get();

        virtual void Set(void* _Value);

        virtual CSectElem* CreateClass();

        virtual CSectElem & Clear();

        virtual CSectElem & Add(CSectElem &a);

        virtual CSectElem & Mult(CSectElem &a);

        virtual CSectElem & Scale(float a);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        float Value;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CHeight

inline void* CHeight::Get ()
{
    return( (void*)&Value );
}

inline void CHeight::Set (void* _Value)
{
    Value = *(float*)_Value;
}

#endif
