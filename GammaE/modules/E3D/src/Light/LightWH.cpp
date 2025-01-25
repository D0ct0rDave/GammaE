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
#include "LightWH.h"
#include "memory/gammae_mem.h"
// -----------------------------------------------------------------------------
CLightWareHouse::CLightWareHouse()
{
    unsigned int cLight;

    for ( cLight = 0; cLight < E3D_MAX_LIGHTS; cLight++ )
        LightTable[cLight] = 0;
}
// -----------------------------------------------------------------------------
CLightWareHouse::~CLightWareHouse()
{
    Invalidate();
}
// -----------------------------------------------------------------------------
void CLightWareHouse::AddLight(CLight* Light)
{
    unsigned int uiLight = FindFreeLightEntry();

    if ( uiLight < E3D_MAX_LIGHTS )
        LightTable[uiLight] = Light;
}
// -----------------------------------------------------------------------------
void CLightWareHouse::RemoveLight(CLight* Light)
{
    unsigned int uiLight = FindLight(Light);

    if ( uiLight < E3D_MAX_LIGHTS )
    {
        mDel (LightTable[uiLight]);
        LightTable[uiLight] = 0;
    }
}
// -----------------------------------------------------------------------------
void CLightWareHouse::Invalidate()
{
    unsigned int cLight;

    for ( cLight = 0; cLight < E3D_MAX_LIGHTS; cLight++ )
    {
        mDel (LightTable[cLight]);
        LightTable[cLight] = 0;
    }
}
// -----------------------------------------------------------------------------
unsigned int CLightWareHouse::FindLight(CLight* Light)
{
    unsigned int cLight;

    for ( cLight = 0; cLight < E3D_MAX_LIGHTS; cLight++ )
        if ( LightTable[cLight] == Light ) return(cLight);
    return (E3D_MAX_LIGHTS);
}
// -----------------------------------------------------------------------------
unsigned int CLightWareHouse::FindFreeLightEntry()
{
    unsigned int cLight;

    for ( cLight = 0; cLight < E3D_MAX_LIGHTS; cLight++ )
        if ( !LightTable[cLight] ) return(cLight);

    return (E3D_MAX_LIGHTS);
}
// -----------------------------------------------------------------------------
CLight* CLightWareHouse::GetLight(unsigned int LightID)
{
    unsigned int cLight;

    if ( LightID < E3D_MAX_LIGHTS )
        return(LightTable[cLight]);
    else
        return (0);
}
// -----------------------------------------------------------------------------
TFColor CLightWareHouse::ComputeLighting(CGVect3 &Vertex,CGVect3 &Normal)
{
    unsigned int cLight,nLights;
    TFColor Col,ColR;

    ColR.r = ColR.b = ColR.g = 0;
    nLights = 0;
    for ( cLight = 0; cLight < E3D_MAX_LIGHTS; cLight++ )
    {
        if ( LightTable[cLight] )
        {
            Col = LightTable[cLight]->ComputeColor(Vertex,Normal);

            ColR.r += Col.r;
            ColR.b += Col.b;
            ColR.g += Col.g;

            nLights++;
        }
    }

    if ( ColR.r > 1 ) ColR.r = 1;
    if ( ColR.g > 1 ) ColR.g = 1;
    if ( ColR.b > 1 ) ColR.b = 1;

    return (ColR);
}
// -----------------------------------------------------------------------------
