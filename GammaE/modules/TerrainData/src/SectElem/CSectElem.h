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

#ifndef CSectElem_h
#define CSectElem_h 1

#include <math.h>
#include "gammae_math.h"

class CSectElem
{
    public:
        CSectElem();

        ~CSectElem();

        virtual unsigned long ByteSize() = 0;

        virtual CSectElem & Sum(CSectElem &a, CSectElem &b);

        virtual CSectElem & Mult(CSectElem &a, CSectElem &b);

        virtual CSectElem & LinInterpolate(CSectElem &a, CSectElem &b, float fFactor);

        virtual CSectElem & CosInterpolate(CSectElem &a, CSectElem &b, float fFactor);

        virtual void* Get() = 0;

        virtual void Set(void* _Value) = 0;

        virtual CSectElem* CreateClass() = 0;

        virtual CSectElem & Clear();

        virtual CSectElem & Add(CSectElem &a);

        virtual CSectElem & Mult(CSectElem &a);

        virtual CSectElem & Scale(float a);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSectElem

#endif
