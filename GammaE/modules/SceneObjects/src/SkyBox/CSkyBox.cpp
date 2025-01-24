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
// CSkyBox
#include "SkyBox\CSkyBox.h"

// Class CSkyBox

CSkyBox::CSkyBox()
    : poNode(NULL)
{
}

CSkyBox::~CSkyBox()
{
    /*
       for (int cSide=0;cSide<6;cSide++)
        Sides = mDel CGMesh_Rect;
     */
}

void CSkyBox::InitSkyBox (float fSize, CVect3& Center, float fRoll, CE3D_Shader* * Materials)
{
    poNode = mNew CGSceneGroup;

    // Store the 6 sides of the sky box
    for ( int cSide = 0; cSide < 6; cSide++ )
    {
        // Create objects
        ObjSides [cSide] = mNew CGSceneLeaf();
        MeshSides[cSide] = mNew CGMeshRect;
        MatsSides[cSide] = Materials[cSide];

        // bind material and mesh to object
        ObjSides[cSide]->SetShader(MatsSides[cSide]);
        ObjSides[cSide]->SetMesh  (MeshSides[cSide]);

        // bind leaf object to SkyBox
        poNode->iAddObject(ObjSides[cSide]);
    }

    // Front/back
    MeshSides[0]->m_poVX[0].V3( 1,-1,-1);
    MeshSides[0]->m_poVX[1].V3(-1,-1,-1);
    MeshSides[0]->m_poVX[2].V3(-1,-1, 1);
    MeshSides[0]->m_poVX[3].V3( 1,-1, 1);
    MeshSides[0]->m_poUV[0].V2(1,1);
    MeshSides[0]->m_poUV[1].V2(0,1);
    MeshSides[0]->m_poUV[2].V2(0,0);
    MeshSides[0]->m_poUV[3].V2(1,0);

    MeshSides[1]->m_poVX[0].V3( 1, 1, 1);
    MeshSides[1]->m_poVX[1].V3(-1, 1, 1);
    MeshSides[1]->m_poVX[2].V3(-1, 1,-1);
    MeshSides[1]->m_poVX[3].V3( 1, 1,-1);
    MeshSides[1]->m_poUV[0].V2(0,0);
    MeshSides[1]->m_poUV[1].V2(1,0);
    MeshSides[1]->m_poUV[2].V2(1,1);
    MeshSides[1]->m_poUV[3].V2(0,1);

    // Right/Left
    MeshSides[2]->m_poVX[0].V3(-1, 1,-1);
    MeshSides[2]->m_poVX[1].V3(-1, 1, 1);
    MeshSides[2]->m_poVX[2].V3(-1,-1, 1);
    MeshSides[2]->m_poVX[3].V3(-1,-1,-1);
    MeshSides[2]->m_poUV[0].V2(0,1);
    MeshSides[2]->m_poUV[1].V2(0,0);
    MeshSides[2]->m_poUV[2].V2(1,0);
    MeshSides[2]->m_poUV[3].V2(1,1);

    MeshSides[3]->m_poVX[0].V3( 1, 1, 1);
    MeshSides[3]->m_poVX[1].V3( 1, 1,-1);
    MeshSides[3]->m_poVX[2].V3( 1,-1,-1);
    MeshSides[3]->m_poVX[3].V3( 1,-1, 1);
    MeshSides[3]->m_poUV[0].V2(1,0);
    MeshSides[3]->m_poUV[1].V2(1,1);
    MeshSides[3]->m_poUV[2].V2(0,1);
    MeshSides[3]->m_poUV[3].V2(0,0);

    // Up/Down
    MeshSides[4]->m_poVX[0].V3(-1, 1, 1);
    MeshSides[4]->m_poVX[1].V3( 1, 1, 1);
    MeshSides[4]->m_poVX[2].V3( 1,-1, 1);
    MeshSides[4]->m_poVX[3].V3(-1,-1, 1);
    MeshSides[4]->m_poUV[0].V2(0,1);
    MeshSides[4]->m_poUV[1].V2(0,0);
    MeshSides[4]->m_poUV[2].V2(1,0);
    MeshSides[4]->m_poUV[3].V2(1,1);

    MeshSides[5]->m_poVX[0].V3( 1, 1,-1);
    MeshSides[5]->m_poVX[1].V3(-1, 1,-1);
    MeshSides[5]->m_poVX[2].V3(-1,-1,-1);
    MeshSides[5]->m_poVX[3].V3( 1,-1,-1);
    MeshSides[5]->m_poUV[0].V2(0,0);
    MeshSides[5]->m_poUV[1].V2(1,0);
    MeshSides[5]->m_poUV[2].V2(1,1);
    MeshSides[5]->m_poUV[3].V2(0,1);

    // Setup transformation
    CMatrix4x4 oMat;

    oMat.Scale(fSize,fSize,fSize);
    oMat.Rotate('z',fRoll);
    oMat.Translate(Center);

    SetTransf(oMat);

    // Setup sky box as object
    SetObject(poNode);
}

// Additional Declarations
