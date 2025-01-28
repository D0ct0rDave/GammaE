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

// SCNUt_TransformTriScene
#include "TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_VisibilityTester
#include "ScnVisibilityTester\SCNUt_VisibilityTester.h"

// Class SCNUt_VisibilityTester

SCNUt_VisibilityTester::SCNUt_VisibilityTester()
{
}

SCNUt_VisibilityTester::~SCNUt_VisibilityTester()
{
}

bool SCNUt_VisibilityTester::bIsVisible (SCNUt_TriScene* _poTScn, CGVect3& _oIni, CGVect3& _oEnd)
{
    CGRay oRay;

    oRay.InitFromPoints(_oIni,_oEnd);
    oRay.Dir.Normalize();

    return( bRayToPos(oRay,_oEnd,_poTScn) );
}

bool SCNUt_VisibilityTester::bRayToPos (CGRay& _oRay, CGVect3& _oPos, SCNUt_TriScene* _poTScn)
{
    if ( !_poTScn ) return(false);
    if ( !_poTScn->NumTris ) return(false);
    if ( !_poTScn->Tris ) return(false);

    // For all those triangles, compute intersection point,
    int iTri;
    CGTriangle oTri;
    CGVect3 oPoint;
    float fMaxDist;
    float fCurDist;

    fMaxDist = _oRay.Origin.fDistance(_oPos);

    for ( iTri = 0; iTri < _poTScn->NumTris; iTri++ )
    {
        oTri.Init(_poTScn->Tris[iTri].VXs);
        oTri.ComputeAll();
        oTri.Normal.Normalize();

        if ( Math::iTestSegTriIntersection(_oRay,oTri,oPoint) )
        {
            fCurDist = _oRay.Origin.fDistance(oPoint);
            if ( fCurDist + 1e-1f < fMaxDist )
                return(false);
        }
    }

    return(true);
}

// Additional Declarations
