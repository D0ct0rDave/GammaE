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
#ifndef SCNUt_TransformTriScene_h
#define SCNUt_TransformTriScene_h 1
// -----------------------------------------------------------------------------

#include "GammaE_E3D.h"
#include "GammaE_Math.h"
#include "SCNUt_TriScene.h"

// -----------------------------------------------------------------------------
class SCNUt_TransformTriScene
{
    public:
        SCNUt_TransformTriScene();

        // / Transforms the vertices and normals of the scene using the given matrix
        void Transform(SCNUt_TriScene* _poTriScn, const CGMatrix4x4& _oMatrix);

        // / Transforms the vertices and normals of the scene with specific matrices
        void Transform(SCNUt_TriScene* _poTriScn, const CGMatrix4x4& _oVertexMatrix, const CGMatrix4x4& _oNormalMatrix);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
