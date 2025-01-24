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
#ifndef CGPSGGenericQuadOrbit_h
#define CGPSGGenericQuadOrbit_h 1
// -----------------------------------------------------------------------------
#include "CGParticle.h"
#include "CGPSGGenericQuad.h"
// -----------------------------------------------------------------------------
class CGPSGGenericQuadOrbit : public CGPSGGenericQuad
{
    public:
        virtual void InitParticle(CGPSGGenericQuadParticle* _poPart);
        void SetOrbitFactor(float _fOrbitFactor)
        {
            m_fOrbitFactor = _fOrbitFactor;
        }

    protected:
        float m_fOrbitFactor;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
