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

#ifndef CCOL_CSysEntry_h
#define CCOL_CSysEntry_h 1

// CCOL_Collider
#include "Collider\CCOL_Collider.h"

class CCOL_CSysEntry
{
    public:
        CCOL_CSysEntry();

        ~CCOL_CSysEntry();

        void Tested(int _iIdx);

        bool bTested(int _iIdx);

        void Init(int _iNumTests);

        void Reset();

        // Data Members for Associations

        CCOL_Collider* ColObj;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        bool* pbTested;

        int iNumTests;

        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_CSysEntry

#endif
