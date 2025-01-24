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
#ifndef CGLightH
#define CGLightH
// ----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "Materials/CGColor.h"
// ----------------------------------------------------------------------------
typedef enum
{
    LT_None,
    LT_Point,
    LT_Directional,
    LT_Spot
}eLightType;

class CGLight
{
    public:
        CGLight();
        ~CGLight();

    public:
        CGColor m_oLitAmb;
        CGColor m_oLitDiff;
        CGColor m_oLitSpec;

        CGVect3 m_oPos;
        CGVect3 m_oDir;

        // For spot lights
        float m_fSpExp;
        float m_fSpCutOff;

        float m_fCAtt;                // Constant attenuation
        float m_fLAtt;                // Linera attenuation
        float m_fQAtt;                // Quadratic attenuation

        eLightType m_eType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
