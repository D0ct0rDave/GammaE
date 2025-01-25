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
// -----------------------------------------------------------------------------
#include "TransfTriScn\SCNUt_TransformTriScene.h"
// -----------------------------------------------------------------------------
SCNUt_TransformTriScene::SCNUt_TransformTriScene()
{
}
// -----------------------------------------------------------------------------
void SCNUt_TransformTriScene::Transform(SCNUt_TriScene* _poTriScn,const CGMatrix4x4& _oMatrix)
{
    Transform(_poTriScn,_oMatrix,_oMatrix);
}
// -----------------------------------------------------------------------------
void SCNUt_TransformTriScene::Transform(SCNUt_TriScene* _poTriScn, const CGMatrix4x4& _oVertexMatrix, const CGMatrix4x4& _oNormalMatrix)
{
    for ( uint i = 0; i < _poTriScn->NumTris; i++ )
    {
        // Transform points
        _oVertexMatrix.TransformPoint(_poTriScn->Tris[i].VXs[0]);
        _oVertexMatrix.TransformPoint(_poTriScn->Tris[i].VXs[1]);
        _oVertexMatrix.TransformPoint(_poTriScn->Tris[i].VXs[2]);

        // Transform normals
        _oNormalMatrix.TransformVector(_poTriScn->Tris[i].VNs[0]);
        _oNormalMatrix.TransformVector(_poTriScn->Tris[i].VNs[1]);
        _oNormalMatrix.TransformVector(_poTriScn->Tris[i].VNs[2]);
    }
}
// -----------------------------------------------------------------------------
