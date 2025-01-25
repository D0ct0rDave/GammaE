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

#ifndef CSkyBox_h
#define CSkyBox_h 1

// CGSceneTransf
#include "GammaE_Scene.h"

class CSkyBox : public CGSceneTransf
{
    public:
        CSkyBox();

        virtual ~CSkyBox();

        void InitSkyBox(float fSize, CGVect3& Center, float fRoll, CE3D_Shader* * Materials);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        CGMesh* MeshSides[6];

        CGSceneLeaf* ObjSides[6];

        CE3D_Shader* MatsSides[6];

        CGSceneGroup* poNode;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CSkyBox

#endif
