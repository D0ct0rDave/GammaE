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
#include <string.h>

// CGSceneAnimMesh
#include "Animation\CGSceneAnimMesh.h"

// --------------------------------------------------------------------------------
CGSceneAnimMesh::CGSceneAnimMesh() :
    m_poFrameVXs(NULL),
    m_poFrameVNs(NULL),
    m_poMesh(NULL)
{
    m_eTypeID = OBJ3D_AnimMesh;
}
// --------------------------------------------------------------------------------
CGSceneAnimMesh::~CGSceneAnimMesh()
{
    m_poFrameBVol.Clear();

    if ( m_poFrameVXs ) mDel [] m_poFrameVXs;
    if ( m_poFrameVNs ) mDel [] m_poFrameVNs;
}
// --------------------------------------------------------------------------------
#if 0
void CGSceneAnimMesh::SetAnimState (int _iSrc, int _iDst, float _fFactor)
{
    assert (pMeshStates && "NULL Mesh state array");
    assert (pBVolStates && "NULL Bounding Volume State array");
    assert (Leaf && "NULL Leaf Mesh");

    if ( iNumStates == 1 )
    {
        memcpy( Leaf->poGetMesh()->VXs,pMeshStates,iNumStateVXs * sizeof(CGVect3) );
        memcpy( Leaf->poGetMesh()->VNs,pNMeshStates,iNumStateVXs * sizeof(CGVect3) );

        BVol->Copy(pBVolStates[0]);
        Leaf->poGetMesh()->BVol->Copy(BVol);
    }
    else
    {
        if ( _iSrc >= iNumStates ) _iSrc = iNumStates - 1;
        if ( _iDst >= iNumStates ) _iDst = iNumStates - 1;
        if ( _fFactor == 1.0f ) _iSrc = _iDst;                     // Optimization

        if ( (_iSrc != _iDst) && (_fFactor > 0.0f) )
        {
            int cVert;
            CGVect3* pSrcVX = pMeshStates + iNumStateVXs * _iSrc;
            CGVect3* pDstVX = pMeshStates + iNumStateVXs * _iDst;
            CGVect3* pMeshVX = Leaf->poGetMesh()->VXs;
            for ( cVert = 0; cVert < iNumStateVXs; cVert++ )
            {
                pMeshVX->Interpolate(*pSrcVX,*pDstVX,_fFactor);

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
            memcpy( Leaf->poGetMesh()->VNs,pNMeshStates + iNumStateVXs * _iSrc,iNumStateVXs * sizeof(CGVect3) );

            CGVect3 oSMax,oSMin,oDMax,oDMin,oMax,oMin;
            CGVect3 oSCen = pBVolStates[_iSrc]->GetCenter();
            CGVect3 oDCen = pBVolStates[_iDst]->GetCenter();
            CGVect3 oSExt = pBVolStates[_iSrc]->GetExtents();
            CGVect3 oDExt = pBVolStates[_iDst]->GetExtents();
            oSMax.Assign(oSCen);
            oSMax.Add(oSExt);
            oSMin.Assign(oSCen);
            oSMin.Sub(oSExt);
            oDMax.Assign(oDCen);
            oDMax.Add(oDExt);
            oDMin.Assign(oDCen);
            oDMin.Sub(oDExt);

            oMax.Interpolate(oSMax,oDMax,_fFactor);
            oMin.Interpolate(oSMin,oDMin,_fFactor);

            BVol->Init(oMax,oMin);
            Leaf->poGetMesh()->BVol->Copy(BVol);
        }
        else
        {
            // Src copy:
            BVol->Copy(pBVolStates[_iSrc]);
            Leaf->poGetMesh()->BVol->Copy(BVol);

            // Copy of the vertexs
            memcpy( Leaf->poGetMesh()->VXs,pMeshStates + iNumStateVXs * _iSrc,iNumStateVXs * sizeof(CGVect3) );

            // Copy of the normals
            memcpy( Leaf->poGetMesh()->VNs,pNMeshStates + iNumStateVXs * _iSrc,iNumStateVXs * sizeof(CGVect3) );
        }
    }
}
#endif
// --------------------------------------------------------------------------------
