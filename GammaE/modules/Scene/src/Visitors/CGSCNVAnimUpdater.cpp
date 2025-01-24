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
#include "CGSCNVAnimUpdater.h"

#include "CGSceneBSPNode.h"
#include "CGSceneCamera.h"
#include "CGSceneCompiledLeaf.h"
#include "CGSceneInstance.h"
#include "CGSceneLeaf.h"
#include "CGSceneMux.h"
#include "CGSceneNode.h"
#include "CGSceneScreenRect.h"
#include "CGSceneSwitch.h"
#include "CGSceneTransf.h"
#include "CGSceneScreenRect.h"

#include "Animation/CGSceneAnimObject.h"
#include "Animation/CGSceneAnimCfg.h"
#include "Animation/CGSceneAnimMesh.h"
#include "Animation/CGSceneAnimInstance.h"
#include "Animation/CGSceneAnimNode.h"
#include "Animation/CGSceneAnimTransf.h"

// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::SetAnimState(CGSceneAnimInstance* _poInst,uint _uiIFrame,uint _uiEFrame,float _fFact)
{
    m_uiIFrame = _uiIFrame;
    m_uiEFrame = _uiEFrame;
    m_fFact = _fFact;

    _poInst->poGetAnimatedObject()->Accept(this);
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimObject* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimMesh* _poNode)
{
// assert (_poNode->pMeshStates && "NULL Mesh state array");
// assert (pBVolStates && "NULL Bounding Volume State array");
// assert (Leaf        && "NULL Leaf Mesh");
    if ( _poNode->uiGetNumKeyFrames() == 1 )
    {
        memcpy( _poNode->poGetMesh()->m_poVX,_poNode->poGetVertexs(),_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );
        memcpy( _poNode->poGetMesh()->m_poVN,_poNode->poGetNormals(),_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );
    }
    else
    {
        if ( m_uiIFrame >= _poNode->uiGetNumKeyFrames() ) m_uiIFrame = _poNode->uiGetNumKeyFrames() - 1;
        if ( m_uiEFrame >= _poNode->uiGetNumKeyFrames() ) m_uiEFrame = _poNode->uiGetNumKeyFrames() - 1;
        if ( m_fFact == 1.0f ) m_uiIFrame = m_uiEFrame;                     // Optimization

        if ( (m_uiIFrame != m_uiEFrame) && (m_fFact > 0.0f) )
        {
            int cVert;
            CGVect3* pSrcVX = _poNode->poGetVertexs() + _poNode->uiGetNumFrameVXs() * m_uiIFrame;
            CGVect3* pDstVX = _poNode->poGetVertexs() + _poNode->uiGetNumFrameVXs() * m_uiEFrame;
            CGVect3* pMeshVX = _poNode->poGetMesh()->m_poVX;

            for ( uint cVert = 0; cVert < _poNode->uiGetNumFrameVXs(); cVert++ )
            {
                pMeshVX->Interpolate(*pSrcVX,*pDstVX,m_fFact);

                pSrcVX++;
                pDstVX++;
                pMeshVX++;
            }

            /*
               // No se nota tanto la diferecia
               CGVect3			*pSrcVN  = pNMeshStates + iNumStateVXs*_iSrc;
               CGVect3			*pDstVN  = pNMeshStates + iNumStateVXs*_iDst;
               CGVect3			*pMeshVN = Leaf->poGetMesh()->VNs;
               for (cVert=0;cVert<iNumStateVXs;cVert++)
               {

                pMeshVN->Interpolate(*pSrcVN,*pDstVN,_fFactor);

                pSrcVN ++;
                pDstVN ++;
                pMeshVN++;
               }
             */
            memcpy( _poNode->poGetMesh()->m_poVN,_poNode->poGetNormals() + _poNode->uiGetNumFrameVXs() * m_uiIFrame,_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );

            CGVect3 oSMax,oSMin,oDMax,oDMin,oMax,oMin;
            CGVect3 oSCen = _poNode->poGetKeyFrameBVol(m_uiIFrame)->GetCenter();
            CGVect3 oDCen = _poNode->poGetKeyFrameBVol(m_uiEFrame)->GetCenter();
            CGVect3 oSExt = _poNode->poGetKeyFrameBVol(m_uiIFrame)->GetExtents();
            CGVect3 oDExt = _poNode->poGetKeyFrameBVol(m_uiEFrame)->GetExtents();
            oSMax.Assign(oSCen);
            oSMax.Add(oSExt);
            oSMin.Assign(oSCen);
            oSMin.Sub(oSExt);
            oDMax.Assign(oDCen);
            oDMax.Add(oDExt);
            oDMin.Assign(oDCen);
            oDMin.Sub(oDExt);

            oMax.Interpolate(oSMax,oDMax,m_fFact);
            oMin.Interpolate(oSMin,oDMin,m_fFact);

            _poNode->poGetMesh()->poGetBoundVol()->Init(oMax,oMin);
        }
        else
        {
            // Src copy:
            _poNode->poGetMesh()->poGetBoundVol()->Copy( _poNode->poGetKeyFrameBVol(m_uiIFrame) );

            // Copy of the vertexs
            memcpy( _poNode->poGetMesh()->m_poVX,_poNode->poGetVertexs() + _poNode->uiGetNumFrameVXs() * m_uiIFrame,_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );

            // Copy of the normals
            memcpy( _poNode->poGetMesh()->m_poVN,_poNode->poGetNormals() + _poNode->uiGetNumFrameVXs() * m_uiIFrame,_poNode->uiGetNumFrameVXs() * sizeof(CGVect3) );
        }
    }
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimNode* _poNode)
{
}
// ----------------------------------------------------------------------------
void CGSCNVAnimUpdater::Visit(CGSceneAnimTransf* _poNode)
{
}
// ----------------------------------------------------------------------------
