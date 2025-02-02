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

        SCNUt_TriScene* Generate(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedTriFanMesh(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedQuadStripMesh(const CGMesh& _oMesh, int _iMat);

        // Additional Public Declarations

    protected:

        SCNUt_TriScene* Generate_FromIndexedTriMesh(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedQuadMesh(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromIndexedTriStripMesh(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromNonIndexedTriMesh(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromNonIndexedQuadMesh(const CGMesh& _oMesh, int _iMat);

        SCNUt_TriScene* Generate_FromNonIndexedTriStripMesh(const CGMesh& _oMesh, int _iMat);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_Mesh2TriScene

#endif
