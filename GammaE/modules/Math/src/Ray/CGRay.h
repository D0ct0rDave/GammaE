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
#ifndef CGRayH
#define CGRayH
// ----------------------------------------------------------------------------
#include "..\Vector\CGVect3.h"
#include "..\Other\GMathCommon.h"
// ----------------------------------------------------------------------------
class CGRay
{
    public:

        void InitFromFields(CGVect3& _Origin, CGVect3& _Dir);

        void InitFromPoints(CGVect3& _Origin, CGVect3& _End);

        CGVect3 ProjectPoint(CGVect3& _Point);

        float GetDistanceToPoint(CGVect3& _Point);

        float GetSqDistanceToPoint(CGVect3& _Point);

        CGVect3 GetPerpendicular(CGVect3& _Point);

        CGVect3 Origin;

        CGVect3 Dir;
};
// ----------------------------------------------------------------------------
inline void CGRay::InitFromFields (CGVect3& _Origin, CGVect3& _Dir)
{
    Origin.Assign(_Origin);
    Dir.Assign(_Dir);
}
// ----------------------------------------------------------------------------
inline void CGRay::InitFromPoints (CGVect3& _Origin, CGVect3& _End)
{
    Origin.Assign(_Origin);

    Dir.Assign(_End);
    Dir.Sub   (_Origin);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
