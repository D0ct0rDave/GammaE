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

#ifndef CGraphBV_h
#define CGraphBV_h 1

// eGraphBV_TypeID
#include "BoundingVolume\GraphBoundVol\eGraphBV_TypeID.h"
// CE3D_Frustum
#include "Viewing\Frustum\CE3D_Frustum.h"

class CGBoundingVolume
{
    public:
        CGBoundingVolume();

        ~CGBoundingVolume();

        virtual void Transform(CGMatrix4x4& M);

        virtual void Compute(CGVect3* VXs, int iNumVXs);

        virtual float GetRange(int iAxis);

        virtual CGVect3 & GetCenter();

        virtual int TestFrustum(CE3D_Frustum& _Frustum);

        virtual void Init(CGVect3 Max, CGVect3 Min);

        virtual void Copy(CGBoundingVolume* Src);

        eGraphBV_TypeID eGetTypeID();

        virtual int TestInside(CGVect3& _Pos);

        virtual CGVect3 & GetExtents();

        virtual CGVect3 & oGetMax();

        virtual CGVect3 & oGetMin();

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        eGraphBV_TypeID eTypeID;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGBoundingVolume

inline eGraphBV_TypeID CGBoundingVolume::eGetTypeID ()
{
    return (eTypeID);
}

#endif
