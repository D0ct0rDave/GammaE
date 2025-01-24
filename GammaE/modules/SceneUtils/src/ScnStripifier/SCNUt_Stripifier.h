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

#ifndef SCNUt_Stripifier_h
#define SCNUt_Stripifier_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_AdjTriListBuilder
#include "ScnStripifier\SCNUt_AdjTriListBuilder.h"
// SCNUt_EdgeBuilder
#include "ScnStripifier\SCNUt_EdgeBuilder.h"
// SCNUt_MeshGenerator
#include "ScnMeshGen\SCNUt_MeshGenerator.h"

class SCNUt_Stripifier
{
    public:
        SCNUt_Stripifier();

        ~SCNUt_Stripifier();

        CGMesh* poStripifyMesh(CGMesh* _poMesh);

        CGMesh* poStripifyTriScene(SCNUt_TriScene* _poTS);

        int iGetNonCommonVertex(CGMesh* _SrCGMesh, int _iSrcTri, int _iDstTri);

        // Additional Public Declarations

    protected:

        CGMesh* poStripify(CGMesh* _poMesh, SCNUt_AdjTriList* _poATL);

        int iSelectStartingTri(SCNUt_AdjTriList* _poATL);

        int iSelectBestNeigh(SCNUt_AdjTriList* _poATL, int _iSrcTri);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_Stripifier

#endif
