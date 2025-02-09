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
#include "TexProjector\CTexProjector.h"
// -----------------------------------------------------------------------------
CTexProjector::CTexProjector()
{
}
// -----------------------------------------------------------------------------
CTexProjector::~CTexProjector()
{
    /*
    // Unlink projector mesh
    oAuxMesh.m_poBV = NULL;
    oAuxMesh.m_eMeshType = E3D_MESH_NONE;
    oAuxMesh.m_pusIdx = NULL;
    oAuxMesh.m_poVX = NULL;
    oAuxMesh.m_uiNumIdxs = NULL;
    oAuxMesh.m_uiNumPrims = NULL;
    oAuxMesh.uiGetNumVXs() = NULL;
    oAuxMesh.m_poUV = NULL;
    oAuxMesh.m_poUV = NULL;
    oAuxMesh.m_poVC = NULL;
    oAuxMesh.m_poVN = NULL;
    oAuxMesh.m_poTN = NULL;

    SetMesh(NULL);
    */
}
// -----------------------------------------------------------------------------
void CTexProjector::Setup (CGMesh* _oSrcMesh, CGShader* _poShader, CGMatrix4x4& _oPrjMatrix)
{
    /*
    // Copy source data
    oAuxMesh.m_poBV = _oSrcMesh->m_poBV;
    oAuxMesh.m_eMeshType = _oSrcMesh->m_eMeshType;
    oAuxMesh.m_pusIdx = _oSrcMesh->m_pusIdx;
    oAuxMesh.m_poVX = _oSrcMesh->m_poVX;
    oAuxMesh.m_uiNumIdxs = _oSrcMesh->m_uiNumIdxs;
    oAuxMesh.m_uiNumPrims = _oSrcMesh.uiGetNumPrims();
    oAuxMesh.uiGetNumVXs() = _oSrcMesh->uiGetNumVXs();
    oAuxMesh.m_poUV = (CGVect2*)_oSrcMesh->m_poVX;
    oAuxMesh.m_poUV = NULL;
    oAuxMesh.m_poVC = NULL;                             // _oSrCGMesh->VCs;
    oAuxMesh.m_poVN = NULL;
    oAuxMesh.m_poTN = NULL;

    // UVs
       if (_oSrcMesh->usNumVerts > iMaxUVs)
       {
        if (iMaxUVs)
            mDel []oAuxMesh.UVs;

        oAuxMesh.UVs = mNew CGVect2[_oSrcMesh->usNumVerts];
        iMaxUVs = _oSrcMesh->usNumVerts;
       }

       // Project coordinates
       CGVect3	oUV;
       int		iV;
       for (iV=0;iV<_oSrcMesh->usNumVerts;iV++)
       {
        // oUV.V4(oAuxMesh.VXs[iV].x,oAuxMesh.VXs[iV].y,oAuxMesh.VXs[iV].z,1.0f);
        oUV.Assign(oAuxMesh.VXs[iV]);
        _oPrjMatrix.TransformVector(oUV);

        // oAuxMesh.UVs[iV].Set(0.5f + 0.5f*oUV.x/oUV.z,0.5f + 0.5f*oUV.y/oUV.z);
        oAuxMesh.UVs[iV].Set(oUV.x/oUV.z,oUV.y/oUV.z);
       }
     */
    SetShader(_poShader);
    SetMesh  (&oAuxMesh);
}
// -----------------------------------------------------------------------------
void CTexProjector::Setup (CGMesh* _oSrCGMesh, CGShader* _poShader, CGVect3& _oPos, CGVect3& _oDir, float _fXSize, float _fYSize)
{
    // Compute projection matrix
    CGMatrix4x4 oPrjMat;

    // ...
    // ...
    // ...

    Setup(_oSrCGMesh,_poShader,oPrjMat);
}
// -----------------------------------------------------------------------------
// Additional Declarations
