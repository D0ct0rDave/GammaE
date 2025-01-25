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
#include "TexCoordGen.h"
// ----------------------------------------------------------------------------
namespace MeshUtils {
// ----------------------------------------------------------------------------
void ComputeUVOrthoMapping(CGMesh &Mesh)
{
    /*
       // DMC REFACT
       uint CGVect;
       CGGraphBV* BVol;
       CGVect3 Center;
       float UOffset;

       if ( !Mesh.m_pusIdx ) return;

       // We need the Min and Max mesh points
       BVol = Mesh.poGetBoundVol();

       // Get the center point
       Center = BVol->GetCenter();

       // Compute UV coordinates
       for ( CGVect = 0; CGVect < Mesh.m_uiNumVXs; CGVect++ )
       {
        if ( Mesh.m_poVX[CGVect].z - Center.z < 0 ) UOffset = 0.5; else UOffset = 0;

        Mesh.m_poUV[CGVect].x = UOffset + ( ( 0.5f + ( Mesh.m_poVX[CGVect].x - Center.x ) / BVol->GetRange(0) ) / 2.0f );
        Mesh.m_poUV[CGVect].y = ( 0.5f + ( Mesh.m_poVX[CGVect].y - Center.y ) / BVol->GetRange(1) );
       }
     */
}
// ----------------------------------------------------------------------------
}; // MeshUtils
// ----------------------------------------------------------------------------
