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

#ifndef SCNUt_Scn2TriScnBuilder_h
#define SCNUt_Scn2TriScnBuilder_h 1

// CGSceneNode
#include "CGSceneNode.h"
// CGSceneTransf
#include "CGSceneTransf.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"

class SCNUt_Scn2TriScnBuilder
{
    public:
        SCNUt_Scn2TriScnBuilder();

        ~SCNUt_Scn2TriScnBuilder();

        SCNUt_TriScene* poBuild(CGSceneNode* _poScene, SCNUt_MaterialTable& _oMTable);

        SCNUt_TriScene* poBuildRec(CGSceneNode* _poScene, CGMatrix4x4* _poMStack, int _iMPos, SCNUt_MaterialTable& _poMTab);

        SCNUt_TriScene* poBuildMesh(const CGMesh& _oMesh, int _iMat, const CGMatrix4x4& _oMat);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_Scn2TriScnBuilder

#endif
