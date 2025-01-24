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
#include "GammaE_Mem.h"

// CGraphBV_Sphere
#include "BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h"
// CGraphBV_Point
#include "BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
// CGraphBV_Manager
#include "BoundingVolume\GraphBoundVol\CGraphBV_Manager.h"
// CGraphBV_Cylinder
#include "BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
// CGraphBV_Box
#include "BoundingVolume\GraphBoundVol\CGraphBV_Box.h"

// Class CGraphBV_Manager

eGraphBV_TypeID CGraphBV_Manager::eCreationMode = eGraphBV_Sphere;

CGraphBV_Manager::CGraphBV_Manager()
{
}

CGraphBV_Manager::~CGraphBV_Manager()
{
}

CGraphBV* CGraphBV_Manager::poCreate ()
{
    switch ( eCreationMode )
    {
        case eGraphBV_Sphere:   return(mNew CGraphBV_Sphere);

        case eGraphBV_Box:      return(mNew CGraphBV_Box);

        case eGraphBV_Cylinder: return(mNew CGraphBV_Cylinder);

        case eGraphBV_Point:    return(mNew CGraphBV_Point);
    }

    return (NULL);
}

// Additional Declarations

// -----------------------------------------------------------------------------
// epilog: singleton initializer through static instantiation
// -----------------------------------------------------------------------------
static CGraphBV_Manager oInstance;
