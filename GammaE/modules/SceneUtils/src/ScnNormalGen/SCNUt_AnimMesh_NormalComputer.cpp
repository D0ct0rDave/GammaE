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
// SCNUt_AnimMesh_NormalComputer
#include "ScnNormalGen\SCNUt_AnimMesh_NormalComputer.h"
SCNUt_AnimMesh_NormalComputer glbAnimMesh_NormalGenerator;

// Class SCNUt_AnimMesh_NormalComputer

SCNUt_AnimMesh_NormalComputer::SCNUt_AnimMesh_NormalComputer()
{
}

SCNUt_AnimMesh_NormalComputer::~SCNUt_AnimMesh_NormalComputer()
{
}

void SCNUt_AnimMesh_NormalComputer::Generate (CGSceneAnimMesh* _pObj)
{
    assert (_pObj && "NULL Animated Mesh Object");

    CGMesh* pLeafMesh = _pObj->poGetMesh();

    CGVect3* pOldVXs = pLeafMesh->m_poVX;
    CGVect3* pOldVNs = pLeafMesh->m_poVN;

    int iState;

    for ( iState = 0; iState < _pObj->uiGetNumKeyFrames(); iState++ )
    {
        pLeafMesh->m_poVX = _pObj->poGetVertexs() + _pObj->uiGetNumFrameVXs() * iState;
        pLeafMesh->m_poVN = _pObj->poGetNormals() + _pObj->uiGetNumFrameVXs() * iState;

        NormalGen_ComputeVertexsNormals(*pLeafMesh);
    }

    pLeafMesh->m_poVX = pOldVXs;
    pLeafMesh->m_poVN = pOldVNs;
}

// Additional Declarations
