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
#ifndef CGTriangleH
#define CGTriangleH
// ----------------------------------------------------------------------------
#include "..\Vector\CGVect3.h"
// ----------------------------------------------------------------------------
class CGTriangle
{
    public:

        void Init(CGVect3* _pVXs);

        void Init(CGVect3* _pVXs, CGVect3& _Normal);

        void ComputeSegs();

        void ComputeAxis();

        void ComputeAll();

        // ----------------------------------------------------------------------------

        CGVect3 Normal;

        CGVect3* VXs;

        CGVect3 s0;

        CGVect3 s1;

        CGVect3 s2;

        CGVect3 e1;

        CGVect3 e2;

        // ----------------------------------------------------------------------------

    protected:
        // ----------------------------------------------------------------------------

        bool bSelfData;

        // ----------------------------------------------------------------------------

    private:
        // ----------------------------------------------------------------------------

    private:
        // ----------------------------------------------------------------------------
};

// ----------------------------------------------------------------------------

inline void CGTriangle::Init (CGVect3* _pVXs)
{
    VXs = _pVXs;
    Normal.Normal(VXs[0],VXs[1],VXs[2]);
}

inline void CGTriangle::Init (CGVect3* _pVXs, CGVect3& _Normal)
{
    VXs = _pVXs;
    Normal.Assign(_Normal);
}

inline void CGTriangle::ComputeSegs ()
{
    s0.Assign(VXs[0]);
    s0.Sub(VXs[2]);
    s1.Assign(VXs[1]);
    s1.Sub(VXs[0]);
    s2.Assign(VXs[2]);
    s2.Sub(VXs[1]);
}

inline void CGTriangle::ComputeAxis ()
{
    e1.Assign(VXs[1]);
    e1.Sub(VXs[0]);
    e2.Assign(VXs[2]);
    e2.Sub(VXs[0]);
}

inline void CGTriangle::ComputeAll ()
{
    ComputeSegs ();
    ComputeAxis ();
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
