// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGChronoH
#define CGChronoH
// ----------------------------------------------------------------------------
class CGChrono
{
    public:

        CGChrono();

        ~CGChrono();

        void Reset();

        void Start();

        void Stop();

        double dElapsedTime();

    protected:

        double m_dStartTime;

        double m_dChronoFrequency;

        double m_dElapsedTime;

        bool m_bActive;

    private:

        double m_dLastDelta;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
