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
// SCNUt_PlanarMapper
#include "ScnPlanarMapper\SCNUt_PlanarMapper.h"

// Class SCNUt_PlanarMapper

SCNUt_PlanarMapper::SCNUt_PlanarMapper()
{
}

SCNUt_PlanarMapper::~SCNUt_PlanarMapper()
{
}

void SCNUt_PlanarMapper::PlanarMap (SCNUt_TriScene& _oTriScn)
{
    // Normalize the scene
    SCNUt_TriScene oTriScene;

    // Make a copy of the triangle scene
    oTriScene = _oTriScn;

    // Compute object dimensions
    SCNUt_ComputeBoundingBox oBBoxCmp;
    CGBVAABB* poBBox;

    poBBox = oBBoxCmp.poComputeBoundingBox(&oTriScene);

    // Get object dimensions
    CGVect3 oDims;
    oDims.Assign(poBBox->m_oMaxs);
    oDims.Sub   (poBBox->m_oMins);

    // Modify texcoords
    float fU,fV,fVOfs;

    for ( int iTri = 0; iTri < _oTriScn.NumTris; iTri++ )
    {
        // Mirar la componente Z de la normal del triángulo
        CGVect3 oNormal;
        oNormal.Normal( _oTriScn.Tris[iTri].VXs[0],
                        _oTriScn.Tris[iTri].VXs[1],
                        _oTriScn.Tris[iTri].VXs[2]);

        if ( oNormal.z < 0.0f ) fVOfs = 0.5f;
        else fVOfs = 0;

        for ( int iVX = 0; iVX < 3; iVX++ )
        {
            fU = (_oTriScn.Tris[iTri].VXs[iVX].x - poBBox->m_oMins.x) / oDims.x;
            fV = (_oTriScn.Tris[iTri].VXs[iVX].y - poBBox->m_oMins.y) / oDims.y;

            _oTriScn.Tris[iTri].UVs[iVX].V2(fU,0.5f * fV + fVOfs);
        }
    }
}

// Additional Declarations
