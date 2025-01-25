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

// CGBVSphere
#include "BoundingVolume\GraphBoundVol\CGBVSphere.h"
// CGraphBV_Point
#include "BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
// CGraphBV_Manager
#include "BoundingVolume\GraphBoundVol\CGraphBV_Manager.h"
// CGraphBV_Cylinder
#include "BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
// CGBVAABB
#include "BoundingVolume\GraphBoundVol\CGBVAABB.h"

// Class CGraphBV_Manager

eGraphBV_TypeID CGraphBV_Manager::eCreationMode = eGraphBV_Sphere;

CGraphBV_Manager::CGraphBV_Manager()
{
}

CGraphBV_Manager::~CGraphBV_Manager()
{
}

CGBoundingVolume* CGraphBV_Manager::poCreate ()
{
    switch ( eCreationMode )
    {
        case eGraphBV_Sphere:   return(mNew CGBVSphere);

        case eGraphBV_Box:      return(mNew CGBVAABB);

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
