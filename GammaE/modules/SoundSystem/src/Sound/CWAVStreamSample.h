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

#ifndef CWAVStreamSample_h
#define CWAVStreamSample_h 1

#include "SoundSystem/GammaE_Sound.h"

class CWAVStreamSample : public CSample
{
    public:

        CWAVStreamSample();

        ~CWAVStreamSample();

        void Init(char* _szFilename);

        // -----------------------------------------------------------------------------

        // -----------------------------------------------------------------------------

        virtual int iGetData(int _iOfs,void* _pBuffer,int _iSize);

    protected:
        // -----------------------------------------------------------------------------

        CFile oFile;

    private:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

#endif
