//	  %X% %Q% %Z% %W%

#ifndef CLoaderMD2_h
#define CLoaderMD2_h 1

#include "GammaE_SceneUtils.h"
#include "MD2Types.h"

// CObject3D
#include "CObject3D.h"
// CObject3D_Node
#include "CObject3D_Node.h"
// C3DLoader
#include "3D_Loaders\C3DLoader.h"
// CObject3D_AnimCfgMgr
#include "Animation\CObject3D_AnimCfgMgr.h"
// CObject3D_AnimMesh
#include "Animation\CObject3D_AnimMesh.h"
// CObject3D_AnimCfg
#include "Animation\CObject3D_AnimCfg.h"

class CLoaderMD2 : public C3DLoader
{

public: CLoaderMD2();

    ~CLoaderMD2();

    virtual CObject3D *pLoad (char *Filename);

    int GetNumSkins ();

    char *GetSkin (int iSkin);

    int GetNumFrames ();

    CObject3D_AnimCfgGen *pLoadQ2Player (char *Filename);

     // Additional Public Declarations
protected:
    int ReadFile (char *Filename);

    void SetupFrame (int iFrame);

    void ParseHeader ();

    CObject3D *ParseChunks ();

    SCNUt_TriScene *ParseModel ();

    CE3D_Shader *ParseMaterial ();

    unsigned short *GetVertexConversionTable (CMesh &Mesh);

    void ParseFrameSet (CObject3D_AnimMesh &AnimMesh, CMesh &Mesh);

     // Additional Protected Declarations
private:
    // Data Members for Class Attributes

    char *Stream;

    int StreamSize;

    model_t *MD2Header;

    frame_t *Frame;

    triangle_t *Triangles;

    triangleVertex_t *Vertexs;

    textureCoordinate_t *TexCoords;

     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CLoaderMD2

#endif // ifndef CLoaderMD2_h
