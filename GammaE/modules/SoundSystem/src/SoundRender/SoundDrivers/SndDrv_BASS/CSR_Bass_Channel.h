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

#ifndef CSR_Bass_Channel_h
#define CSR_Bass_Channel_h 1

class CSR_Bass_Channel
{
    public:
        CSR_Bass_Channel();

        ~CSR_Bass_Channel();

        // Data Members for Class Attributes

        int iChannel;

        BASS_3DVECTOR Vel;

        BASS_3DVECTOR Pos;

        int iDir;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CSR_Bass_Channel

#endif
