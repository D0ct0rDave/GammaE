//---------------------------------------------------------------------------
#ifdef USE_PRECOMPILED_HEADERS
    #include "OCT_PrecompiledHeaders.h"
    #pragma hdrstop
#endif
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#define IC_MARK     0
#define IC_NODE     1
#define IC_LEAF     2
#define IC_BSP      3
#define IC_MESH     4
#define IC_BVBOX    5
#define IC_BVSPH    6
#define IC_TRANS    7
#define IC_PLANE    8
#define IC_TRANSF   9
//---------------------------------------------------------------------------
#include "GammaE.h"
#include "GUINodes.h"

TTreeView   *gpoTV;
int         giCurNode;
#define     _FPREC_    "0.00"
//---------------------------------------------------------------------------
// Generates a scene tree in a tree view control
//---------------------------------------------------------------------------
void GenerateSceneTree_Rec(TTreeNode *poTParent,CObject3D*poNode);
//---------------------------------------------------------------------------
void GenerateBoundingVolume(TTreeNode *poTParent,CGraphBV*poBV)
{
    // Add bounding volume
    gpoTV->Items->AddChild(poTParent,"Bounding Volume");
    TTreeNode *poBVNode = gpoTV->Items->Item[giCurNode++];
    TTreeNode *poBVNodeData;

    switch (poBV->eGetTypeID())
    {
        case eGraphBV_Sphere:
        {
            gpoTV->Items->AddChild(poBVNode,"Sphere");
            poBVNodeData = gpoTV->Items->Item[giCurNode++];
            poBVNodeData->ImageIndex = IC_BVSPH;

            gpoTV->Items->AddChild(poBVNodeData,"Radius: "+
                        FormatFloat(_FPREC_,((CGraphBV_Sphere*)poBV)->pGetSphere()->Radius));
            giCurNode++;

            gpoTV->Items->AddChild(poBVNodeData,"Center: ("+
                        FormatFloat(_FPREC_,((CGraphBV_Sphere*)poBV)->pGetSphere()->Center.X() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Sphere*)poBV)->pGetSphere()->Center.Y() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Sphere*)poBV)->pGetSphere()->Center.Z() )+")");
            giCurNode++;
        }
        break;

        case eGraphBV_Box:
        {
            gpoTV->Items->AddChild(poBVNode,"Box");
            poBVNodeData = gpoTV->Items->Item[giCurNode++];
            poBVNodeData->ImageIndex = IC_BVBOX;

            gpoTV->Items->AddChild(poBVNodeData,"Maxs: ("+
                        FormatFloat(_FPREC_,((CGraphBV_Box*)poBV)->pGetBox()->Maxs.X() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Box*)poBV)->pGetBox()->Maxs.Y() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Box*)poBV)->pGetBox()->Maxs.Z() )+")");
            giCurNode++;

            gpoTV->Items->AddChild(poBVNodeData,"Mins: ("+
                        FormatFloat(_FPREC_,((CGraphBV_Box*)poBV)->pGetBox()->Mins.X() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Box*)poBV)->pGetBox()->Mins.Y() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Box*)poBV)->pGetBox()->Mins.Z() )+")");
            giCurNode++;
        }
        break;
        case eGraphBV_Cylinder:
        {
            gpoTV->Items->AddChild(poBVNode,"Cylinder");
            poBVNodeData = gpoTV->Items->Item[giCurNode++];

            gpoTV->Items->AddChild(poBVNodeData,"Height: "+
                        FormatFloat(_FPREC_,((CGraphBV_Cylinder*)poBV)->pGetCylinder()->Height));
            giCurNode++;

            gpoTV->Items->AddChild(poBVNodeData,"Radius: "+
                        FormatFloat(_FPREC_,((CGraphBV_Cylinder*)poBV)->pGetCylinder()->Radius));
            giCurNode++;

            gpoTV->Items->AddChild(poBVNodeData,"Center: ("+
                        FormatFloat(_FPREC_,((CGraphBV_Cylinder*)poBV)->pGetCylinder()->Center.X() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Cylinder*)poBV)->pGetCylinder()->Center.Y() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Cylinder*)poBV)->pGetCylinder()->Center.Z() )+")");
            giCurNode++;
        }
        break;
        case eGraphBV_Point:
        {
            gpoTV->Items->AddChild(poBVNode,"Point");
            poBVNodeData = gpoTV->Items->Item[giCurNode++];

            gpoTV->Items->AddChild(poBVNodeData,"Position: ("+
                        FormatFloat(_FPREC_,((CGraphBV_Point*)poBV)->pGetPoint()->X() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Point*)poBV)->pGetPoint()->Y() )+","+
                        FormatFloat(_FPREC_,((CGraphBV_Point*)poBV)->pGetPoint()->Z() )+")");
            giCurNode++;
        }
        break;
    }
}
//---------------------------------------------------------------------------
void GenerateTransformMatrix(TTreeNode *poTParent,CMatrix4x4 &roMat)
{
    // Add transformation matrix
    gpoTV->Items->AddChild(poTParent,"Transform");
    TTreeNode *poTransNode = gpoTV->Items->Item[giCurNode++];
    poTransNode->ImageIndex = IC_TRANS;

    AnsiString  asRow;
    CVect4      oRow;
    int         cRow;

    for (cRow=0;cRow<4;cRow++)
    {
        oRow = roMat.GetRowVector(cRow);
        asRow = "Row "+IntToStr(cRow)+": (" +   FormatFloat(_FPREC_,oRow.X())+" "+
                                                FormatFloat(_FPREC_,oRow.Y())+" "+
                                                FormatFloat(_FPREC_,oRow.Z())+" "+
                                                FormatFloat(_FPREC_,oRow.W())+")";

        gpoTV->Items->AddChild(poTransNode,asRow);
        giCurNode++;
    }
}
//---------------------------------------------------------------------------
void GenerateLeafTree(TTreeNode *poTParent,CObject3D_Leaf *poNode)
{
    gpoTV->Items->AddChild(poTParent,"Leaf");
    TTreeNode       *poThisNode = gpoTV->Items->Item[giCurNode++];
    poThisNode->ImageIndex = IC_LEAF;

    // Add bounding volume
    GenerateBoundingVolume(poThisNode,poNode->poGetBoundVol());

    // Material
    AnsiString asMaterial = AnsiString(CE3D_ShaderWH::szGetShaderName(*poNode->poGetShader()) );
    gpoTV->Items->AddChild(poThisNode,"Shader: "+asMaterial);
    giCurNode++;

    // Add mesh properties
    gpoTV->Items->AddChild(poThisNode,"Mesh");
    TTreeNode *poMeshNode = gpoTV->Items->Item[giCurNode++];
    poMeshNode->ImageIndex = IC_MESH;

    gpoTV->Items->AddChild(poMeshNode,"Num VXs: "+IntToStr(poNode->poGetMesh()->usNumVerts));
    giCurNode++;
    gpoTV->Items->AddChild(poMeshNode,"Num Idxs: "+IntToStr(poNode->poGetMesh()->usNumIdxs));
    giCurNode++;
    gpoTV->Items->AddChild(poMeshNode,"Num Prims: "+IntToStr(poNode->poGetMesh()->usNumPrims));
    giCurNode++;

    switch (poNode->poGetMesh()->GetMeshType())
    {
        case E3D_MESH_NONE:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_NONE");
            giCurNode++;
        }
        break;
        case E3D_MESH_TRIS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_TRIS");
            giCurNode++;
        }
        break;
        case E3D_MESH_QUADS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_QUADS");
            giCurNode++;
        }
        break;
        case E3D_MESH_TRIFANS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_TRIFANS");
            giCurNode++;
        }
        break;
        case E3D_MESH_TRISTRIPS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_TRISTRIPS");
            giCurNode++;
        }
        break;
        case E3D_MESH_QUADSTRIPS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_QUADSTRIPS");
            giCurNode++;
        }
        break;
        case E3D_MESH_NITRIS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_NITRIS");
            giCurNode++;
        }
        break;
        case E3D_MESH_NIQUADS:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_NIQUADS");
            giCurNode++;
        }
        break;
        case E3D_MESH_NITRISTRIP:
        {
            gpoTV->Items->AddChild(poMeshNode,"E3D_MESH_NITRISTRIP");
            giCurNode++;
        }
        break;
    }
    if (poNode->poGetMesh()->VXs)
        gpoTV->Items->AddChild(poMeshNode,"VXs: yes");
    else
        gpoTV->Items->AddChild(poMeshNode,"VXs: no");
    giCurNode++;

    if (poNode->poGetMesh()->VNs)
        gpoTV->Items->AddChild(poMeshNode,"VNs: yes");
    else
        gpoTV->Items->AddChild(poMeshNode,"VNs: no");
    giCurNode++;

    if (poNode->poGetMesh()->VCs)
        gpoTV->Items->AddChild(poMeshNode,"VCs: yes");
    else
        gpoTV->Items->AddChild(poMeshNode,"VCs: no");
    giCurNode++;

    if (poNode->poGetMesh()->UVs2)
        gpoTV->Items->AddChild(poMeshNode,"UVs2: yes");
    else
        gpoTV->Items->AddChild(poMeshNode,"UVs2: no");
    giCurNode++;

    if (poNode->poGetMesh()->TNs)
        gpoTV->Items->AddChild(poMeshNode,"TNs: yes");
    else
        gpoTV->Items->AddChild(poMeshNode,"TNs: no");
    giCurNode++;
}
//---------------------------------------------------------------------------
void GenerateCLeafTree(TTreeNode *poTParent,CObject3D_CompiledLeaf *poNode)
{

}
//---------------------------------------------------------------------------
void GenerateTransfTree(TTreeNode *poTParent,CObject3D_Transf *poNode)
{
    gpoTV->Items->AddChild(poTParent,"Node");
    TTreeNode *poThisNode  = gpoTV->Items->Item[giCurNode++];
    poThisNode->ImageIndex = IC_TRANSF;

    // Add bounding volume
    GenerateBoundingVolume(poThisNode,poNode->poGetBoundVol());

    gpoTV->Items->AddChild(poThisNode,"Object");
    poThisNode  = gpoTV->Items->Item[giCurNode++];

    if (poNode->poGetObject())
    {
        gpoTV->Items->AddChild(poThisNode,"GEO");
        GenerateSceneTree_Rec (gpoTV->Items->Item[giCurNode++],poNode->poGetObject());
    }
}
//---------------------------------------------------------------------------
void GenerateNodeTree(TTreeNode *poTParent,CObject3D_Node *poNode)
{
    gpoTV->Items->AddChild(poTParent,"Node");
    TTreeNode *poThisNode  = gpoTV->Items->Item[giCurNode++];
    poThisNode->ImageIndex = IC_NODE;

    // Add bounding volume
    GenerateBoundingVolume(poThisNode,poNode->poGetBoundVol());

    // Add number of subobjects
    gpoTV->Items->AddChild(poThisNode,IntToStr(poNode->iNumSubObjs()) + " subobjects");
    poThisNode  = gpoTV->Items->Item[giCurNode++];

    // Add childs
    int             iObj;
    CObject3D       *poSubObj;
    TTreeNode       *poChildNode;

    for (iObj=0;iObj<poNode->iNumSubObjs();iObj++)
    {
        poSubObj = (CObject3D*)poNode->poGetObject(iObj);
        if (poSubObj)
        {
            gpoTV->Items->AddChild(poThisNode,"Child "+IntToStr(iObj));
            poChildNode =  gpoTV->Items->Item[giCurNode++];

            GenerateSceneTree_Rec (poChildNode,poSubObj);
        }
        else
        {
            gpoTV->Items->AddChild(poThisNode,"Child "+IntToStr(iObj)+" :NULL");
            giCurNode++;
        }
    }
}
//---------------------------------------------------------------------------
void GenerateBSPNodeTree(TTreeNode *poTParent,CObject3D_BSPNode *poNode)
{
    CPlane *poPlane = poNode->poGetPartitionPlane();

    gpoTV->Items->AddChild(poTParent,"BSP Node");
    TTreeNode *poThisNode  = gpoTV->Items->Item[giCurNode++];
    poThisNode->ImageIndex = IC_BSP;

    gpoTV->Items->AddChild(poThisNode,"Plane: ");
    TTreeNode *poPlaneNode  = gpoTV->Items->Item[giCurNode++];
    poPlaneNode->ImageIndex = IC_PLANE;

    gpoTV->Items->AddChild(poPlaneNode,"Normal: ("+
                    FormatFloat(_FPREC_,poPlane->Normal().X())+","+
                    FormatFloat(_FPREC_,poPlane->Normal().Y())+","+
                    FormatFloat(_FPREC_,poPlane->Normal().Z())+")");
    gpoTV->Items->AddChild(poPlaneNode,"Origin: ("+
                    FormatFloat(_FPREC_,poPlane->Origin().X())+","+
                    FormatFloat(_FPREC_,poPlane->Origin().Y())+","+
                    FormatFloat(_FPREC_,poPlane->Origin().Z())+")");
    gpoTV->Items->AddChild(poPlaneNode,"D: "+FormatFloat(_FPREC_,poPlane->D()) );

    // Traverse back node
    gpoTV->Items->AddChild(poThisNode,"BackNode");
    TTreeNode *poBackNode  = gpoTV->Items->Item[giCurNode++];
    GenerateSceneTree_Rec(poBackNode,poNode->poGetBackNode());

    // Traverse front node
    gpoTV->Items->AddChild(poThisNode,"FrontNode");
    TTreeNode *poFrontNode  = gpoTV->Items->Item[giCurNode++];
    GenerateSceneTree_Rec(poFrontNode,poNode->poGetFrontNode());
}
//---------------------------------------------------------------------------
void GenerateSceneTree_Rec(TTreeNode *poTParent,CObject3D*poNode)
{
    switch (poNode->eGetTypeID())
    {
        case e3DObj_NULL:
                                    break;
        case e3DObj_Gen:
                                    break;
        case e3DObj_Leaf:           GenerateLeafTree(poTParent,(CObject3D_Leaf*)poNode);
                                    break;
        case e3DObj_Node:           GenerateNodeTree (poTParent,(CObject3D_Node*)poNode);
                                    break;
        case e3DObj_Anim_Begin:
                                    break;
        case e3DObj_AnimGen:
                                    break;
        case e3DObj_AnimNode:
                                    break;
        case e3DObj_AnimMesh:
                                    break;
        case e3DObj_AnimTransf:
                                    break;
        case e3DObj_AnimCfg:
                                    break;
        case e3DObj_AnimCfgMgr:
                                    break;
        case e3DObj_Anim_End:
                                    break;
        case e3DObj_Camera:
                                    break;
        case e3DObj_Mux:
                                    break;
        case e3DObj_BSPNode:        GenerateBSPNodeTree(poTParent,(CObject3D_BSPNode*)poNode);
                                    break;
        case e3DObj_CompiledLeaf:   GenerateCLeafTree(poTParent,(CObject3D_CompiledLeaf*)poNode);
                                    break;
    }
}
//---------------------------------------------------------------------------
void GenerateSceneTree(TTreeView *poTV,CObject3D *poScene)
{
    gpoTV     = poTV;
    giCurNode = 0;

    gpoTV->Items->Clear();

    TTreeNode *poParent = gpoTV->Items->Add(NULL,"Root");
    giCurNode = 1;
    GenerateSceneTree_Rec(poParent,poScene);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
