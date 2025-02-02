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

#ifndef CSR_Bass_Emiter_h
#define CSR_Bass_Emiter_h 1

#include <bass.h>

class CSR_Bass_Emiter
{
    public:
        CSR_Bass_Emiter();

        ~CSR_Bass_Emiter();

        // Data Members for Class Attributes

        CSoundEmiter* pEmiter;

        HCHANNEL iCurCh;

        int iCurSmpLayer;

        bool bUnlock;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CSR_Bass_Emiter

#endif
