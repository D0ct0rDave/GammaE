// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CLoaderMD2H
#define CLoaderMD2H
// ----------------------------------------------------------------------------
#include "GammaE_SceneUtils.h"
#include "MD2Types.h"
// ----------------------------------------------------------------------------
#include "CGSceneNode.h"
// CGSceneNode
#include "CGSceneNode.h"
// C3DLoader
#include "3D_Loaders\C3DLoader.h"
// CGSceneAnimMesh
#include "Animation\CGSceneAnimMesh.h"
// CGSceneAnimCfg
#include "Animation\CGSceneAnimActionSet.h"
// ----------------------------------------------------------------------------
class CLoaderMD2 : public C3DLoader
{
    public:
        CLoaderMD2();

        ~CLoaderMD2();

        virtual CGSceneNode* poLoad(const CGString& _sFilename);

        int GetNumSkins();

        char* GetSkin(int iSkin);

        int GetNumFrames();

        CGSceneAnimActionSet* pLoadQ2Player(const CGString& _sFilename);

    protected:

        int ReadFile(const CGString& _sFilename);

        void SetupFrame(int iFrame);

        void ParseHeader();

        CGSceneNode* ParseChunks();

        SCNUt_TriScene* ParseModel();

        CGShader* ParseMaterial();

        unsigned short* GetVertexConversionTable(CGMesh &Mesh);

        void ParseFrameSet(CGSceneAnimMesh &AnimMesh, CGMesh &Mesh);

    private:

        pointer Stream;

        int StreamSize;

        model_t* MD2Header;

        frame_t* Frame;

        triangle_t* Triangles;

        triangleVertex_t* Vertexs;

        textureCoordinate_t* TexCoords;

    private:
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
