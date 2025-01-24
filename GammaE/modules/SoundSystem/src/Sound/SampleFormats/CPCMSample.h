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

#ifndef CPCMSample_h
#define CPCMSample_h 1

#include "Sound\CFileSample.h"

class CPCMSample : public CFileSample
{
    public:

        CPCMSample();

        ~CPCMSample();

        virtual void Init(char* _szFilename);

        // -----------------------------------------------------------------------------

        // -----------------------------------------------------------------------------

        virtual int iGetData(int _iOfs,void* _pBuffer,int _iSize);
        virtual void* pGetInternalData()
        {
            return(pData);
        }

        void Init(int _iChannels, int _iBits, int _iSRate, float _fTime);
        void Init(int _iChannels, int _iBits, int _iSRate, int _iSamples);

    protected:
        // -----------------------------------------------------------------------------

        virtual void Finish();

        void* pData;

    private:
        // -----------------------------------------------------------------------------

    private:
        // -----------------------------------------------------------------------------
};

// -----------------------------------------------------------------------------

#endif
