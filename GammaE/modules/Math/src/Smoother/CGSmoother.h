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
#ifndef CGSmootherH
#define CGSmootherH
// ----------------------------------------------------------------------------
class CGSmoother
{
    public:
        CGSmoother(float _fSmoothFact = 1.0f) : m_fAccum(0.0f)
        {
            Init(_fSmoothFact);
        }

        // / Inializes the smoother object using the initial smooth factor
        void Init(float _fSmoothFact);

        // / Retrieves the a smooth value given the raw input value
        float fValue(float _fInputVal);

    protected:
        float m_fSmoothFact;

        float m_fAccum;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
