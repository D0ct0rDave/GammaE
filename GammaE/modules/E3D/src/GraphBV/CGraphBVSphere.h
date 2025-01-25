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
// %X% %Q% %Z% %W%

#ifndef CGBVSphere_h
#define CGBVSphere_h 1

// CGBoundingVolume
#include "BoundingVolume\GraphBoundVol\CGBoundingVolume.h"
// CBoundingSphere
#include "BoundingVolume\CBoundingSphere.h"

class CGBVSphere : public CGBoundingVolume
{
    public:
        CGBVSphere();

        ~CGBVSphere();

        virtual void Transform(CGMatrix4x4& M);

        virtual void Compute(CGVect3* VXs, int iNumVXs);

        virtual float GetRange(int iAxis);

        virtual CGVect3 & GetCenter();

        virtual int TestFrustum(CE3D_Frustum& _Frustum);

        virtual void Init(CGVect3 Max, CGVect3 Min);

        CBoundingSphere* pGetSphere();

        virtual int TestInside(CGVect3& _Pos);

        virtual void Copy(CGBoundingVolume* Src);

        // Data Members for Associations

        CBoundingSphere Vol;

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        CGVect3 oExtents;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGBVSphere

#endif
