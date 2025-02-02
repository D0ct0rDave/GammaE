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

#ifndef CSectorLoaderManager_h
#define CSectorLoaderManager_h 1

// CSector
#include "Sector\CSector.h"

class CSectorLoaderManager
{
    public:
        CSectorLoaderManager();

        ~CSectorLoaderManager();

        virtual CSector* poCreateClass(FILE* _FD);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSectorLoaderManager

#endif
