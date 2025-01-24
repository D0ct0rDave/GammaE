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

#ifndef CTexProjector_h
#define CTexProjector_h 1

// CGSceneLeaf
#include "GammaE_Scene.h"

class CTexProjector : public CGSceneLeaf
{
    public:
        CTexProjector();

        virtual ~CTexProjector();

        void Setup(CGMesh* _oSrCGMesh, CE3D_Shader* _poShader, CMatrix4x4& _oPrjMatrix);

        void Setup(CGMesh* _oSrCGMesh, CE3D_Shader* _poShader, CVect3& _oPos, CVect3& _oDir, float _fXSize, float _fYSize);

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        CGMesh oAuxMesh;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTexProjector

#endif
