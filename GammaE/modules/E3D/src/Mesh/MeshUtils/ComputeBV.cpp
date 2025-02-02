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
#include "ComputeBV.h"
#include "GraphBV/CGGraphBVAABB.h"
#include "GraphBV/CGGraphBVSphere.h"
#include "Mesh/CGMesh.h"
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
CGGraphBV* poComputeBV(const CGMesh &Mesh)
{
    CGGraphBVAABB* poAABB = poComputeBVAABB(Mesh);
    CGGraphBVSphere* poSphere = poComputeBVSphere(Mesh);

    float fAABBVol = poAABB->oGetBV().fGetVolume();
    float fSphereVol = poSphere->oGetBV().fGetVolume();

    if ( fSphereVol < fAABBVol )
    {
        mDel poAABB;
        return(poSphere);
    }
    else
    {
        mDel poSphere;
        return(poAABB);
    }
}
// ----------------------------------------------------------------------------
CGGraphBVAABB* poComputeBVAABB(const CGMesh &Mesh)
{
    CGVect3 oMins,oMaxs;

    oMins.Set( _INFINITE_, _INFINITE_, _INFINITE_);
    oMaxs.Set(-_INFINITE_,-_INFINITE_,-_INFINITE_);

    for ( uint cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
    {
        if ( Mesh.m_poVX[cV].x > oMaxs.x ) oMaxs.x = Mesh.m_poVX[cV].x;
        if ( Mesh.m_poVX[cV].x < oMins.x ) oMins.x = Mesh.m_poVX[cV].x;
        if ( Mesh.m_poVX[cV].y > oMaxs.y ) oMaxs.y = Mesh.m_poVX[cV].y;
        if ( Mesh.m_poVX[cV].y < oMins.y ) oMins.y = Mesh.m_poVX[cV].y;
        if ( Mesh.m_poVX[cV].z > oMaxs.z ) oMaxs.z = Mesh.m_poVX[cV].z;
        if ( Mesh.m_poVX[cV].z < oMins.z ) oMins.z = Mesh.m_poVX[cV].z;
    }

    CGGraphBVAABB* poAABB = mNew CGGraphBVAABB;
    poAABB->Init(oMaxs, oMins);

    return(poAABB);
}
// ----------------------------------------------------------------------------
CGGraphBVSphere* poComputeBVSphere(const CGMesh &Mesh)
{
    // Compute center as the average of the input points
    CGVect3 oCenter(0.0f,0.0f,0.0f);

    for ( uint cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
        oCenter.Add(Mesh.m_poVX[cV]);

    oCenter.Scale( 1.0f / (float)Mesh.uiGetNumVXs() );

    // Compute sphere radius
    float fSqRad;
    float fRadius = 0.0f;
    for ( uint cV = 0; cV < Mesh.uiGetNumVXs(); cV++ )
    {
        fSqRad = oCenter.fSqDistance( Mesh.m_poVX[cV] );

        if ( fSqRad > fRadius )
            fRadius = fSqRad;
    }

    fRadius = Math::fSqrt(fRadius);

    CGGraphBVSphere* poSphere = mNew CGGraphBVSphere;
    poSphere->Init(oCenter, fRadius);

    return(poSphere);
    /*
       // Another way for the same result
       // Initialize bounding volume
       Vol.Init(oCenter,fRadius);
       CGVect3 oMins,oMaxs;

       oMins.Set( _INFINITE_, _INFINITE_, _INFINITE_);
       oMaxs.Set(-_INFINITE_,-_INFINITE_,-_INFINITE_);

       for (uint cV=0;cV<Mesh.uiGetNumVXs();cV++)
       {
        if ( Mesh.m_poVX[cV].x > oMaxs.x ) oMaxs.x =  Mesh.m_poVX[cV].x ;
        if ( Mesh.m_poVX[cV].x < oMins.x ) oMins.x =  Mesh.m_poVX[cV].x ;
        if ( Mesh.m_poVX[cV].y > oMaxs.y ) oMaxs.y =  Mesh.m_poVX[cV].y ;
        if ( Mesh.m_poVX[cV].y < oMins.y ) oMins.y =  Mesh.m_poVX[cV].y ;
        if ( Mesh.m_poVX[cV].z > oMaxs.z ) oMaxs.z =  Mesh.m_poVX[cV].z ;
        if ( Mesh.m_poVX[cV].z < oMins.z ) oMins.z =  Mesh.m_poVX[cV].z ;
       }

       CGVect3 oCenter = oMaxs;
       oCenter.Add(oMins);
       oCenter.Scale(0.5f);

       // Retrieve max distance to the center
       float fRadius = -_INFINITE_;
       for (uint cV=0;cV<Mesh.uiGetNumVXs();cV++)
       {
        float fDist = oCenter.fDistance(Mesh.m_poVX[cV]);
        if (fDist > fRadius) fRadius = fDist;
       }

       CGBVSphere* poSphere = mNew CGBVSphere;
       poSphere->Init(oCenter,fRadius);

       return(poSphere);
     */
}
// ----------------------------------------------------------------------------
}; // namespace MeshUtils
// ----------------------------------------------------------------------------
