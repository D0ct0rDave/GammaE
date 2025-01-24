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

#ifndef SCNUt_Mesh2TriScene_h
#define SCNUt_Mesh2TriScene_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"

class SCNUt_Mesh2TriScene
{
    public:
        SCNUt_Mesh2TriScene();

        ~SCNUt_Mesh2TriScene();

        SCNUt_TriScene* Generate(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedTriFanMesh(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedQuadStripMesh(CGMesh& _oMesh, int _iMat);

        // Additional Public Declarations

    protected:

        SCNUt_TriScene* Generate_FromIndexedTriMesh(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedQuadMesh(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedTriStripMesh(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromNonIndexedTriMesh(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromNonIndexedQuadMesh(CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromNonIndexedTriStripMesh(CGMesh& _oMesh, int _iMat);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_Mesh2TriScene

#endif
