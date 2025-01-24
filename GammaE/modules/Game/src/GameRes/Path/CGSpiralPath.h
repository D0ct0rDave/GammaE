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
#ifndef CGSpiralPathH
#define CGSpiralPathH
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "CGPath.h"
// -----------------------------------------------------------------------------

typedef struct TSpiralPathParams
{
    CVect3 m_oInitialPos;
    CVect3 m_oSpeed;

    CVect3 m_oInitialRadius;
    CVect3 m_oRadiusSpeed;

    CVect3 m_oInitialPhase;
    CVect3 m_oAngularSpeed;

    float m_fPathTime;

    // TSpiralPathParams*		m_poNext;
    // TSpiralPathParams*		m_poPrev;
} TSpiralPathParams;

// -----------------------------------------------------------------------------
class CGSpiralPath : public CGPath
{
    public:

        // / Initializes the path with the given parameters
        void Init(const TSpiralPathParams& _oPars)
        {
            m_oPars = _oPars;
        }

        // / Retrieves the position of the path for a given factor between  (0..1)
        virtual const CVect3& oPos(float _fFact);

        // / Retrieves the total path time
        virtual float fTime()
        {
            return(m_oPars.m_fPathTime);
        }

    protected:

        // / Stores the path parameters
        TSpiralPathParams m_oPars;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
