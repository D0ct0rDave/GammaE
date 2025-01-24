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

#ifndef CShadowCaster_h
#define CShadowCaster_h 1

// CTexProjector
#include "TexProjector\CTexProjector.h"
// CE3D_Shader
#include "GammaE_E3D.h"
// CGSceneNode
#include "GammaE_Scene.h"

class CShadowCaster : public CGSceneNode
{
    public:
        CShadowCaster();

        virtual ~CShadowCaster();

        void Init(int _iRes);

        void Setup(CVect3& _oLightPos, CGSceneNode* _poBlockerObj, CGMesh* * _poRecObjs, int _iNumRecObjs);

        virtual CGraphBV* poGetBV();

        virtual void ComputeBoundVol();

        void ComputeLightCamera();

        void ComputeLightViewport(CE3D_Viewport& _oVpt);

        void ComputeLightProjection();

        void ComputeTextureProjection();

        void UploadShadowMap();

        void RenderShadowMap();

        virtual void Render();

        // Data Members for Class Attributes

        CMatrix4x4 oCamMat;

        // Data Members for Associations

        CTexProjector oTexProj;

        CE3D_Shader* poShader;

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        CGSceneNode* poBlockerObj;

        CVect3 oLPos;

        CGMesh* * poRecObjs;

        int iNumRecObjs;

        int iRes;

        CGTextureObj* poTexObj;

        CMatrix4x4 oPrjMat;

        CMatrix4x4 oPrjTexMat;

        unsigned char* pucAuxTexData;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CShadowCaster

#endif
