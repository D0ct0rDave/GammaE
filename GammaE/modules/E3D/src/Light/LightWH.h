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
#ifndef LightWHH
#define LightWHH
// -----------------------------------------------------------------------------
#include "E3D/Light/Light.h"
#define     E3D_MAX_LIGHTS  8
// -----------------------------------------------------------------------------
class CLightWareHouse
{
    public:  CLightWareHouse();
        ~CLightWareHouse();

        void AddLight(CLight* Light);
        void RemoveLight(CLight* Light);
        void Invalidate();
        CLight* GetLight(unsigned int LightID);
        TFColor ComputeLighting(CGVect3 &Vertex,CGVect3 &Normal);
    private:
        unsigned int FindFreeLightEntry();
        unsigned int FindLight(CLight* Light);

        CLight* LightTable[E3D_MAX_LIGHTS];
};
// -----------------------------------------------------------------------------
#endif
