//-----------------------------------------------------------------------------
#ifndef LightWHH
#define LightWHH
//-----------------------------------------------------------------------------
#include "E3D/Light/Light.h"
#define 	E3D_MAX_LIGHTS	8
//-----------------------------------------------------------------------------
class CLightWareHouse
{
    public:	 CLightWareHouse();
    		~CLightWareHouse();

             void AddLight(CLight *Light);
             void RemoveLight(CLight *Light);
             void Invalidate();
			 CLight *GetLight(unsigned int LightID);
             TFColor ComputeLighting(CVect3 &Vertex,CVect3 &Normal);
    private:
    		unsigned int FindFreeLightEntry();
            unsigned int FindLight(CLight *Light);

    		CLight *LightTable[E3D_MAX_LIGHTS];
};
//-----------------------------------------------------------------------------
#endif
