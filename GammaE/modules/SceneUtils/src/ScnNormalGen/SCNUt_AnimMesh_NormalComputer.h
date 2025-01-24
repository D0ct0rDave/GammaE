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

#ifndef SCNUt_AnimMesh_NormalComputer_h
#define SCNUt_AnimMesh_NormalComputer_h 1

// CGSceneAnimMesh
#include "GammaE_Scene.h"

class SCNUt_AnimMesh_NormalComputer
{
    public:
        SCNUt_AnimMesh_NormalComputer();

        ~SCNUt_AnimMesh_NormalComputer();

        void Generate(CGSceneAnimMesh* _pObj);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_AnimMesh_NormalComputer

extern SCNUt_AnimMesh_NormalComputer glbAnimMesh_NormalGenerator;

#endif
