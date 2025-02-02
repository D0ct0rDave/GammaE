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

#ifndef CDetailer_h
#define CDetailer_h 1

// CGSceneLeaf
#include "GammaE_Scene.h"

class CDetailer : public CGSceneLeaf
{
    public:
        CDetailer();

        virtual ~CDetailer();

        void Init(int _iMaxTris);

        void SetCamPos(CGVect3& _oCamPos);

        virtual void SetVertexTris(CGVect3* _poVXs, int _iNumTris);

        void CreateTextureContents(CGMipMap* _pMipMap);

        CGShader* poCreateMaterial();

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes
        CGMesh* m_poMesh;
        CGUnmanagedMesh* m_poDetailMesh;
        CGVect3 oCamPos;
        CGMipMap* poTex;
};

// Class CDetailer

#endif
