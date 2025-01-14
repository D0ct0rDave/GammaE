//---------------------------------------------------------------------------
#ifdef USE_PRECOMPILED_HEADERS
    #include "OCT_PrecompiledHeaders.h"
    #pragma hdrstop
#endif
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GUIMain.h"
#include "GammaE.h"
#include "GUINodes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
SCNUt_TriScene          *gpoTriScene;
SCNUt_MaterialTable     goMatTable;
CObject3D               *gpoScene;
//---------------------------------------------------------------------------
CVect3                  goMax,goMin,goDims;
float                   gfResizeFact = 1.0f;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)   : TForm(Owner)
{
	// Initialize...	
	CE3D_ShaderWH::Init(1024);
	CE3D_ShaderDefWH::Init(1024);
	CE3D_ShaderDefWH::iAddShaderFile("../../Shaders.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    tv_Scene->Items->Clear();
}
//---------------------------------------------------------------------------
void GenerateBSP(char *InFilename,char *OutFilename)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Load1Click(TObject *Sender)
{
    if (dlg_Load->Execute())
    {
        CE3D_Shader             *poShader;
        SCNUt_TriSceneLoader    TSLoader;
        int                     iMat;

        // Load the scene
        if (gpoTriScene)
        {
            mDel gpoTriScene;
            gpoTriScene = NULL;
        }
        gpoTriScene = TSLoader.poLoad( dlg_Load->FileName.c_str() );

        // Initialize material table
        goMatTable.Init( TSLoader.iNumMaterials + 1);

        CE3D_ShaderWH::Invalidate();
        for (iMat=1;iMat<TSLoader.iNumMaterials;iMat++)
        {
            poShader = CE3D_ShaderWH::poCreateShader( TSLoader.pszMaterials[iMat] );
            goMatTable.SetShader( iMat,poShader );
        }

        SetupControls();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveCompactMesh1Click(TObject *Sender)
{
    CSaverGEM               GSaver;

    SCNUt_MeshCompacter     MComp;
    CMesh                   *Mesh;
    CObject3D_Node          *poScene;
    CObject3D_Node          *poMeshes;
    CObject3D_Leaf          *poLeafMesh;
    SCNUt_TriSceneSeparator TSSep;
    int                     iMesh;

    if (dlg_Save->Execute())
    {
        // Separate the scene meshes by material
        TSSep.SeparateScene( *gpoTriScene );

        // Create a node to store every one of the meshes
        poMeshes   = new CObject3D_Node;
        poMeshes->Init(TSSep.NumMeshes);

        for (iMesh=0;iMesh<TSSep.NumMeshes ;iMesh++)
        {
            Mesh = MComp.CompactMesh( TSSep.Meshes[iMesh] );

            poLeafMesh = new CObject3D_Leaf;
            poLeafMesh->SetMesh(Mesh);
            poLeafMesh->SetShader( goMatTable.poGetShader( TSSep.piMatIdx[iMesh] ) );

            // Add the new compacted mesh
            poMeshes->iAddObject(poLeafMesh);
        }

        GSaver.iSave(dlg_Save->FileName.c_str(),poMeshes);
        return;
    }
}
//---------------------------------------------------------------------------
// Generate a BSP
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
    SCNUt_BSPBuilder        oBSPBuilder;

    if (gpoScene)
    {
        mDel gpoScene;
        gpoScene = NULL;
    }

    // Generate the bsp: This may take a while...
    oBSPBuilder.iMinTrisPerNode = 8;
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    gpoScene = oBSPBuilder.poBuildBSP(*gpoTriScene,goMatTable);
    gpoScene->ComputeBoundVol();

    GenerateSceneTree(tv_Scene,gpoScene);
}
//---------------------------------------------------------------------------
// Generate a simple scene
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    SCNUt_SceneBuilder      oScnBuild;

    if (gpoScene)
    {
        mDel gpoScene;
        gpoScene = NULL;
    }

    // Generate the bsp: This may take a while...
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);
    gpoScene = oScnBuild.poBuildScene(*gpoTriScene,goMatTable);
    gpoScene->ComputeBoundVol();

    GenerateSceneTree(tv_Scene,gpoScene);
}
//---------------------------------------------------------------------------
// Generate an octree
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
    SCNUt_OctreeBuilder        oOctBuilder;

    if (gpoScene)
    {
        mDel gpoScene;
        gpoScene = NULL;
    }

    // Generate the bsp: This may take a while...
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    oOctBuilder.iMinTrisPerNode = 64;
    oOctBuilder.iMaxSubdivisions= 2;
    gpoScene = oOctBuilder.poBuildOctree(*gpoTriScene,goMatTable);
    gpoScene->ComputeBoundVol();

    GenerateSceneTree(tv_Scene,gpoScene);
}
//---------------------------------------------------------------------------
// Save GEM file
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveGEMScene1Click(TObject *Sender)
{
    if (dlg_Save->Execute())
    {
        CSaverGEM               GSaver;
        GSaver.iSave(dlg_Save->FileName.c_str(),gpoScene);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::SetupControls()
{
    SetupResizer();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SetupResizer()
{
    SCNUt_ComputeBoundingBox oBBoxCmp;
    CBoundingBox             *poBBox;

    poBBox = oBBoxCmp.poComputeBoundingBox(gpoTriScene);
    goMax.Assign(poBBox->Maxs);
    goMin.Assign(poBBox->Mins);
    goDims.Assign(goMax);
    goDims.Sub   (goMin);

    tb_Size->Position = 0;
    tb_SizeChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::tb_SizeChange(TObject *Sender)
{
    CVect3 oNewDims;
    char szString[1024];

    gfResizeFact      = 1.0f + (float)tb_Size->Position/100.0f;
    lb_Size->Caption  = FormatFloat("0.00",gfResizeFact);

    oNewDims.Assign(goDims);
    oNewDims.Scale (gfResizeFact);

    sprintf(szString,"(%.3f,%.3f,%.3f)",oNewDims.X(),oNewDims.Y(),oNewDims.Z());
    lb_Dims->Caption  = AnsiString(szString);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    CMatrix4x4              oMat;
    SCNUt_TransformTriScene oTrasnfScn;

    oMat.LoadIdentity();
    oMat.Scale3f(-gfResizeFact,-gfResizeFact,gfResizeFact);

    oTrasnfScn.Transform(*gpoTriScene,oMat);

    // Reset position to 0
    SetupResizer();
}
//---------------------------------------------------------------------------

