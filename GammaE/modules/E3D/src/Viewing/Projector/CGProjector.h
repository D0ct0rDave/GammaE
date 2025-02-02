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
#ifndef CGProjectorH
#define CGProjectorH
// ----------------------------------------------------------------------------
#include "E3D_Enums.h"
// ----------------------------------------------------------------------------
class CGProjector
{
    public:
        CGProjector();

        float fFOV;

        float fNear;

        float fFar;

        E3D_ProjectorType ePrjType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
