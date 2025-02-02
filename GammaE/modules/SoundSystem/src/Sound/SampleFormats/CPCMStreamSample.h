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

#ifndef CPCMStreamSample_h
#define CPCMStreamSample_h 1

#include "Sound\CStreamSample.h"

class CPCMStreamSample : public CStreamSample
{
    public:

        CPCMStreamSample();

        ~CPCMStreamSample();

        virtual void Init(char* _szFilename);
        virtual void Finish();

        // -----------------------------------------------------------------------------

        // -----------------------------------------------------------------------------

        virtual int iGetData(int _iOfs,void* _pBuffer,int _iSize);

    protected:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

#endif
