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

#ifndef CGSceneReflector_h
#define CGSceneReflector_h 1

// GammaE_Math
#include "GammaE_Math.h"
// CGSceneNode
#include "GammaE_Scene.h"

class CGSceneReflector : public CGSceneGroup
{
    public:
        CGSceneReflector();

        virtual ~CGSceneReflector();

        virtual void Render();

        void SetupReflectionMatrix(CMatrix4x4 &_oMat);

        // Data Members for Class Attributes

        CGMesh* Mirror;

        // Data Members for Associations

        CPlane Plane;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CGSceneReflector

#endif
