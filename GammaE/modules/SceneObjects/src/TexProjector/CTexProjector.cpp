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

// CTexProjector
#include "TexProjector\CTexProjector.h"

// arreglar
// int iMaxUVs = 0;

// Class CTexProjector

CTexProjector::CTexProjector()
{
}

CTexProjector::~CTexProjector()
{
    // Unlink projector mesh
    oAuxMesh.m_poBV = NULL;
    oAuxMesh.m_eMeshType = E3D_MESH_NONE;
    oAuxMesh.m_pusIdx = NULL;
    oAuxMesh.m_poVX = NULL;
    oAuxMesh.m_uiNumIdxs = NULL;
    oAuxMesh.m_uiNumPrims = NULL;
    oAuxMesh.m_usNumVXs = NULL;
    oAuxMesh.m_poUV = NULL;
    oAuxMesh.m_poUV = NULL;
    oAuxMesh.m_poVC = NULL;
    oAuxMesh.m_poVN = NULL;
    oAuxMesh.m_poTN = NULL;

    SetMesh(NULL);
}

void CTexProjector::Setup (CGMesh* _oSrCGMesh, CE3D_Shader* _poShader, CMatrix4x4& _oPrjMatrix)
{
    // Copy source data
    oAuxMesh.m_poBV = _oSrCGMesh->m_poBV;
    oAuxMesh.m_eMeshType = _oSrCGMesh->m_eMeshType;
    oAuxMesh.m_pusIdx = _oSrCGMesh->m_pusIdx;
    oAuxMesh.m_poVX = _oSrCGMesh->m_poVX;
    oAuxMesh.m_uiNumIdxs = _oSrCGMesh->m_uiNumIdxs;
    oAuxMesh.m_uiNumPrims = _oSrCGMesh->m_uiNumPrims;
    oAuxMesh.m_usNumVXs = _oSrCGMesh->m_usNumVXs;
    oAuxMesh.m_poUV = (CVect2*)_oSrCGMesh->m_poVX;
    oAuxMesh.m_poUV = NULL;
    oAuxMesh.m_poVC = NULL;                             // _oSrCGMesh->VCs;
    oAuxMesh.m_poVN = NULL;
    oAuxMesh.m_poTN = NULL;

    // UVs
    /*
       if (_oSrCGMesh->usNumVerts > iMaxUVs)
       {
        if (iMaxUVs)
            mDel []oAuxMesh.UVs;

        oAuxMesh.UVs = mNew CVect2[_oSrCGMesh->usNumVerts];
        iMaxUVs = _oSrCGMesh->usNumVerts;
       }

       // Project coordinates
       CVect3	oUV;
       int		iV;
       for (iV=0;iV<_oSrCGMesh->usNumVerts;iV++)
       {
        // oUV.V4(oAuxMesh.VXs[iV].x,oAuxMesh.VXs[iV].y,oAuxMesh.VXs[iV].z,1.0f);
        oUV.Assign(oAuxMesh.VXs[iV]);
        _oPrjMatrix.TransformVector(oUV);

        // oAuxMesh.UVs[iV].V2(0.5f + 0.5f*oUV.x/oUV.z,0.5f + 0.5f*oUV.y/oUV.z);
        oAuxMesh.UVs[iV].V2(oUV.x/oUV.z,oUV.y/oUV.z);
       }
     */
    SetShader(_poShader);
    SetMesh  (&oAuxMesh);
}

void CTexProjector::Setup (CGMesh* _oSrCGMesh, CE3D_Shader* _poShader, CVect3& _oPos, CVect3& _oDir, float _fXSize, float _fYSize)
{
    // Compute projection matrix
    CMatrix4x4 oPrjMat;

    // ...
    // ...
    // ...

    Setup(_oSrCGMesh,_poShader,oPrjMat);
}

// Additional Declarations
