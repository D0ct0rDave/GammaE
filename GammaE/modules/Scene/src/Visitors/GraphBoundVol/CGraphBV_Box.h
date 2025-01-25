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

#ifndef CGraphBV_Box_h
#define CGraphBV_Box_h 1

// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingBox
#include "BoundingVolume\CBoundingBox.h"

class CGraphBV_Box : public CGraphBV
{
    public:
        CGraphBV_Box();

        ~CGraphBV_Box();

        virtual void Transform(CMatrix4x4& M);

        virtual void Compute(CGVect3* VXs, int iNumVXs);

        virtual float GetRange(int iAxis);

        virtual CGVect3 & GetCenter();

        virtual int TestFrustum(CE3D_Frustum& _Frustum);

        virtual void Init(CGVect3 Max, CGVect3 Min);

        CBoundingBox* pGetBox();

        virtual int TestInside(CGVect3& _Pos);

        virtual CGVect3 & GetExtents();

        CGVect3 & GetAxis(int _iAxis);

        virtual CGVect3 & oGetMax();

        virtual CGVect3 & oGetMin();

        // Data Members for Associations

        CBoundingBox Vol;

        // Additional Public Declarations

    protected:

        void ComputeAll();

        // Data Members for Class Attributes

        CGVect3 oExtents;

        CGVect3 oCenter;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGraphBV_Box

#endif
