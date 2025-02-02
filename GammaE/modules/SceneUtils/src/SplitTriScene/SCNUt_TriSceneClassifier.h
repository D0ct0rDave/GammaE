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
// %X% %Q% %Z% %W%

#ifndef SCNUt_TriSceneClassifier_h
#define SCNUt_TriSceneClassifier_h 1

// SCNUt_TriScene
#include "SCNUt_TriScene.h"

class SCNUt_TriSceneClassifier
{
    public:
        SCNUt_TriSceneClassifier();

        ~SCNUt_TriSceneClassifier();

        void ClassifyScene(SCNUt_TriScene& _poScene, CGPlane& _oPlane);

        // Data Members for Class Attributes

        int iFrontTris;

        int iBackTris;

        // Additional Public Declarations

    protected:

        SCNUt_ePolyState ClassifyTriangle(SCNUt_Triangle& SrcTri, CGPlane &Plane);

        void ClassifyTriangleVertexs(SCNUt_Triangle* SrcTri, CGPlane &Plane);

        SCNUt_ePolyState ClassifyVertex(SCNUt_Triangle* SrcTri, int iVertex);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_TriSceneClassifier

#endif
