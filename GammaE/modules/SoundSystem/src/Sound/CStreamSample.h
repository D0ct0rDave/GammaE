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
// -----------------------------------------------------------------------------

#ifndef CStreamSample_h
#define CStreamSample_h 1

#include "Sound\CFileSample.h"

class CStreamSample : public CFileSample
{
    public:

        CStreamSample();

        ~CStreamSample();

        // -----------------------------------------------------------------------------

        // -----------------------------------------------------------------------------

    protected:
        // -----------------------------------------------------------------------------

        void* pFile;

    private:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

#endif