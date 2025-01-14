//---------------------------------------------------------------------------
#ifdef USE_PRECOMPILED_HEADERS
    #include "DED_PrecompiledHeaders.h"
    #pragma hdrstop
#endif

#include <vcl.h>
//---------------------------------------------------------------------------
#include "GUI.H"
#include "GUI_SelDumType.h"
#include "GammaE.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "DummyInfoFile.h"
#include "TerrPrj.h"

TGUIMain    *GUIMain;
TProject     Project;
//---------------------------------------------------------------------------
CDummyTypes             DLists;
//---------------------------------------------------------------------------
void SaveDummyScene(char *_szDummyFile);
//---------------------------------------------------------------------------
__fastcall TGUIMain::TGUIMain(TComponent* Owner) : TForm(Owner)
{
    DisableAll();

    // Enable some menu controls
    File1->Enabled  = true;
    LoadTerrainScene1->Enabled = true;
    Quit1->Enabled  = true;
    Help1->Enabled  = true;
    About1->Enabled = true;

    im_Background->Visible = true;

    m_poAuxBmp = NULL;
}

void __fastcall TGUIMain::EnableAll()
{
    for (int i=0;i<ControlCount;i++)
    {
        // Controls[i]->Visible = true;
        Controls[i]->Enabled = true;
    }
}

void __fastcall TGUIMain::DisableAll()
{
    for (int i=0;i<ControlCount;i++)
    {
        Controls[i]->Enabled = false;
        // Controls[i]->Visible = false;
    }
}
//---------------------------------------------------------------------------
void TGUIMain::DestroyAll()
{
    // Destroy project
    Project.DestroyProject();

    // Destroy Lists
    DLists.DTypes.clear();
    DLists.TerrainScene = "";
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::bt_AddDTClick(TObject *Sender)
{
    CDummyList        DList;

    DList.DummyModel = "";
    DList.iAlgType   = 0;
    DList.fProb      = 0.0f;
    DList.fScale     = 1.0f;
    DList.iIters     = 0;

    if ( Dlg_SelectDummyModel( DList) )
    {
        DLists.DTypes.push_back(DList);                        
        ShowDummyTypesList();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::ShowDummyTypesList()
{
    unsigned int uiDType;
    AnsiString   AlgType;

    // Fill the dummy types string grid
    sg_DTypes->RowCount = DLists.DTypes.size()+1;

    // StringGrid Header
    sg_DTypes->Cells[0][0] = "#";
    sg_DTypes->Cells[1][0] = "Model";
    sg_DTypes->Cells[2][0] = "Prb";
    sg_DTypes->Cells[3][0] = "Scl";
    sg_DTypes->Cells[4][0] = "It";
    sg_DTypes->Cells[5][0] = "Alg";


    for (uiDType=0;uiDType<DLists.DTypes.size();uiDType++)
    {
        // Algorithm type
        switch ( DLists.DTypes[uiDType].iAlgType )
        {
            case 0: AlgType = "Rnd";    break;
            case 1: AlgType = "Perlin";  break;
        }

        // Dummy Type Number
        sg_DTypes->Cells[0][uiDType+1] = IntToStr(uiDType);
        // Dummy model
        sg_DTypes->Cells[1][uiDType+1] = DLists.DTypes[uiDType].DummyModel;
        // Probability
        sg_DTypes->Cells[2][uiDType+1] = FormatFloat("0.00",DLists.DTypes[uiDType].fProb);
        // Scale
        sg_DTypes->Cells[3][uiDType+1] = FormatFloat("0.00",DLists.DTypes[uiDType].fScale);
        // Iterations
        sg_DTypes->Cells[4][uiDType+1] = IntToStr(DLists.DTypes[uiDType].iIters);
        // Algorithm
        sg_DTypes->Cells[5][uiDType+1] = AlgType;
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::ShowDummyInstanceList(CDummyList *_poDList)
{
    unsigned int uiDInst;
    AnsiString   AlgType;

    // Fill the dummy types string grid
    sg_DInsts->RowCount = _poDList->DInsts.size()+1;

    // StringGrid Header
    sg_DInsts->Cells[0][0] = "#";
    sg_DInsts->Cells[1][0] = "x";
    sg_DInsts->Cells[2][0] = "y";
    sg_DInsts->Cells[3][0] = "z";

    // StringGrid contents
    for (uiDInst=0;uiDInst<_poDList->DInsts.size();uiDInst++)
    {
        // Dummy Instance Number
        sg_DInsts->Cells[0][uiDInst+1] = IntToStr(uiDInst);

        // Dummy position
        sg_DInsts->Cells[1][uiDInst+1] = FormatFloat("0.0",_poDList->DInsts[uiDInst].oPos.X() );
        sg_DInsts->Cells[2][uiDInst+1] = FormatFloat("0.0",_poDList->DInsts[uiDInst].oPos.Y() );
        sg_DInsts->Cells[3][uiDInst+1] = FormatFloat("0.0",_poDList->DInsts[uiDInst].oPos.Z() );
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::bt_DeleteDTClick(TObject *Sender)
{
    if ( sg_DTypes->Cells[2][sg_DTypes->Row] == "") return;
    DLists.DTypes.erase( &DLists.DTypes[sg_DTypes->Row-1] );
    ShowDummyTypesList();
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::bt_EditDTClick(TObject *Sender)
{
    sg_DTypesDblClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::Quit1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::ComputeMeasures()
{
    TCircuit *Circuit = Project.Circuit;
    if (! Circuit) return;

    if (Circuit->GetCircuitXRes() > Circuit->GetCircuitYRes())
    {
    	m_iTX = pb_Dsp->Width;
    	m_iTY = Circuit->GetCircuitYRes() * m_iTX / Circuit->GetCircuitXRes();

    	m_iXOfs = 0;
        m_iYOfs = (pb_Dsp->Height - m_iTY)/2;

    	m_fXScale = (float)Circuit->GetCircuitXRes() / (float)m_iTX;
    	m_fYScale = (float)Circuit->GetCircuitYRes() / (float)m_iTY;
    }
	else
    {
    	m_iTY = pb_Dsp->Height;
        m_iTX = Circuit->GetCircuitXRes() * m_iTY / Circuit->GetCircuitYRes();

    	m_iXOfs = (pb_Dsp->Width - m_iTX)/2;
        m_iYOfs = 0;

    	m_fXScale = (float)Circuit->GetCircuitXRes() / (float)m_iTX;
    	m_fYScale = (float)Circuit->GetCircuitYRes() / (float)m_iTY;
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::SetupTerrainDisplay()
{
    ComputeMeasures();

    int                 cI,cJ;
    float			    fRange,fMin;
    unsigned char       ucColor;
    unsigned long       ulColor;
    unsigned long      *DstColor;
    float               cX,cY;

    if (m_poAuxBmp) delete m_poAuxBmp;
    // Setup texture size
    m_poAuxBmp              = new Graphics::TBitmap;
    m_poAuxBmp->Width       = m_iTX;
    m_poAuxBmp->Height      = m_iTY;
    m_poAuxBmp->PixelFormat = pf32bit;

    // Setup height range
    fMin   = Project.Circuit->GetMinHeight();
    fRange = Project.Circuit->GetMaxHeight() - fMin;
    if (! fRange) fRange = 1;

    // Draw circuit
    cY = 0;
    for (cJ=0;cJ<m_iTY;cJ++)
    {
    	DstColor = (unsigned long *)m_poAuxBmp->ScanLine[cJ];

        cX = 0;
        for (cI=0;cI<m_iTX;cI++)
        {
            ucColor = 255.0f * ((Project.Circuit->GetHeight(cX,cY) - fMin) / fRange);
			ulColor = (ucColor << 16) | (ucColor << 8) | (ucColor);
            *DstColor = ulColor;
            DstColor ++;

			cX += m_fXScale;
		}
        cY += m_fYScale;
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::DrawSectors()
{
    TCircuit *Circuit = Project.Circuit;
    if (! Circuit) return;

    unsigned int cXSect,cYSect;

    float XSpace = (float)m_iTX / (float)Circuit->GetSecsPerRow();
    float YSpace = (float)m_iTY / (float)Circuit->GetSecsPerCol();

    pb_Dsp->Canvas->Pen->Color = clYellow;

    for (cYSect=0;cYSect<Circuit->GetSecsPerCol()+1;cYSect++)
    {
        pb_Dsp->Canvas->MoveTo(m_iXOfs                ,m_iYOfs+cYSect*YSpace);
        pb_Dsp->Canvas->LineTo(m_iXOfs+m_iTX            ,m_iYOfs+cYSect*YSpace);
    }

    for (cXSect=0;cXSect<Circuit->GetSecsPerRow()+1;cXSect++)
    {
        pb_Dsp->Canvas->MoveTo(m_iXOfs + cXSect*XSpace,m_iYOfs      );
        pb_Dsp->Canvas->LineTo(m_iXOfs + cXSect*XSpace,m_iYOfs+m_iTY);
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::pb_DspPaint(TObject *Sender)
{
    if (! Project.Circuit) return;
    // Dump bitmap contents
    BitBlt(pb_Dsp->Canvas->Handle,m_iXOfs,m_iYOfs,m_iTX,m_iTY,m_poAuxBmp->Canvas->Handle,0,0,SRCCOPY);

    if (cb_DrawSectors->Checked) DrawSectors();
    ShowDummyInstances(&DLists.DTypes[sg_DTypes->Row-1]);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::cb_DrawSectorsClick(TObject *Sender)
{
    pb_DspPaint(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::ShowDummy(CVect3 Pos,TColor Color)
{
    float fScale = pb_Dsp->Width / (Project.EvPars.fXYScale * Project.Circuit->GetCircuitXRes());

    pb_Dsp->Canvas->Pen->Color = Color;
    pb_Dsp->Canvas->Ellipse(Pos.X()*fScale-1,Pos.Y()*fScale-1,
                            Pos.X()*fScale+1,Pos.Y()*fScale+1);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::ShowDummyInstances(CDummyList *_poDList)
{
    if ( sg_DTypes->Cells[2][sg_DTypes->Row] == "") return;
     
    unsigned int uiNumDummies;
    int          uiDum;

    for (uiDum=0;uiDum<_poDList->DInsts.size();uiDum++)
    {
        ShowDummy(_poDList->DInsts[uiDum].oPos,clRed);
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::sg_DTypesDblClick(TObject *Sender)
{
    if ( sg_DTypes->Cells[2][sg_DTypes->Row] == "") return;

    if ( Dlg_SelectDummyModel( DLists.DTypes[sg_DTypes->Row-1] ))
        ShowDummyTypesList();
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::bt_RedistDTClick(TObject *Sender)
{
    if ( sg_DTypes->Cells[2][sg_DTypes->Row] == "") return;
    CDummyRedistributor DRed;
    DRed.Redistribute(Project.Circuit,
                      Project.EvPars.fXYScale,
                      &DLists.DTypes[sg_DTypes->Row-1]);

    ShowDummyInstanceList(&DLists.DTypes[sg_DTypes->Row-1]);
    pb_DspPaint(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::sg_DTypesSelectCell(TObject *Sender, int ACol,int ARow, bool &CanSelect)
{
    ShowDummyInstanceList(&DLists.DTypes[ARow-1]);

    // Dump bitmap contents
    BitBlt(pb_Dsp->Canvas->Handle,m_iXOfs,m_iYOfs,m_iTX,m_iTY,m_poAuxBmp->Canvas->Handle,0,0,SRCCOPY);

    if (cb_DrawSectors->Checked) DrawSectors();
    ShowDummyInstances(&DLists.DTypes[ARow-1]);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::SaveDummyInfoFilr1Click(TObject *Sender)
{
    dlg_Save->Filter        = "GammaE Terrain Dummy Info files (*.dnf)|*.dnf|All the files (*.*)|*.*";
    dlg_Save->DefaultExt    = "dnf";
    dlg_Save->FilterIndex   = 1;
    dlg_Save->Title         = "Save Dummy Info File:";

    if (dlg_Save->Execute())
    {
        if (! iDummyInfoFile_Save(dlg_Save->FileName.c_str(),&DLists))
            ShowMessage(ERROR_GetError());
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::LoadDummyInfoFile1Click(TObject *Sender)
{
    dlg_Load->Filter        = "GammaE Terrain Dummy Info files (*.dnf)|*.dnf|All the files (*.*)|*.*";
    dlg_Load->DefaultExt    = "dnf";
    dlg_Load->FilterIndex   = 1;
    dlg_Load->Title         = "Select Dummy Info File:";

    if (dlg_Load->Execute())
    {
        DestroyAll();
        DisableAll();

        if (! iDummyInfoFile_Load(dlg_Load->FileName.c_str(),&DLists))
        {
            ShowMessage(ERROR_GetError());
            return;
        }

        // Load the terrain scene
        if ( Project.LoadProjectVersion(DLists.TerrainScene.c_str(),0) )
        {
            SetupTerrainDisplay();
            EnableAll();
            pb_DspPaint(Sender);

            // Show data
            ShowDummyTypesList();
            ShowDummyInstanceList(&DLists.DTypes[0]);
            pb_DspPaint(Sender);
        }
        else
        {
            DestroyAll();
            DisableAll();            
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::LoadTerrainScene1Click(TObject *Sender)
{
    dlg_Load->Filter        = "GammaE Terrain Scene files (*.ter)|*.ter|All the files (*.*)|*.*";
    dlg_Load->DefaultExt    = "ter";
    dlg_Load->FilterIndex   = 1;
    dlg_Load->Title         = "Select Terrain Scene File:";

    if (dlg_Load->Execute())
    {
        if ( Project.LoadProjectVersion(dlg_Load->FileName.c_str(),0) )
        {
            // Copy name
            DLists.TerrainScene = dlg_Load->FileName.c_str();
            
            SetupTerrainDisplay();
            EnableAll();
            pb_DspPaint(Sender);
        }
        else
        {
            DisableAll();
        }
    }
}
//---------------------------------------------------------------------------
void GenerateSectorForDummy(int _iDummyType,int _iXSect,int _iYSect)
{
/*
    SCNUt_Scn2TriScnBuilder
    SCNUt_TriangleSceneAccumulator  oTSA;
    SCNUt_TriangleScene             *poTS;
    CObject3D_Node  *poNode;
    CObject3D       *poMdl = oDMdlTable[_iDummyType];


    float fSectorXSize = Project.EvPars.fXYScale * GetCircuitXRes();
    float fSectorYSize = Project.EvPars.fXYScale * GetCircuitYRes();

    int iInst;
    int iXSect;
    int iYSect;
    for (iInst=0;iInst<DLists.DType[iMdl].DInsts.size();iInst++)
    {
        iXSect = DLists.DType[iMdl].DInsts[iInsts].oPos.X() / fSectorXSize;
        iYSect = DLists.DType[iMdl].DInsts[iInsts].oPos.Y() / fSectorYSize;

        if ((iXSect==_iXSect) && (iYSect==_iYSect))
        {
            poNode = mNew CObject3D_Node;
            poNode->Init(1);
            poNode->SetPos( DLists.DType[iMdl].DInsts[iInsts].oPos );
            poNode->AddObject(poMdl);

            poTS =
        }
    }
*/
}
//---------------------------------------------------------------------------
CVect4 GetVertexLight(CVect3&_roPos)
{
    CVect4      Color;
    tdLightType Light;
    float fX = _roPos.X() / Project.EvPars.fXYScale;
    float fY = _roPos.Y() / Project.EvPars.fXYScale;

    Light = Project.GetLightMap(0)->GetLightf(fX,fY);
    Color.V4(Light.r,Light.g,Light.b,1.0f);

    return(Color);
}

//---------------------------------------------------------------------------
void LIT_TriangleScene(SCNUt_TriScene &_roTS)
{
    int     iTri,iVert;
    CVect4  Color;
    for (iTri=0;iTri<_roTS.NumTris;iTri++)
        for (iVert=0;iVert<3;iVert++)
            _roTS.Tris[iTri].VCs[iVert].Assign( GetVertexLight(_roTS.Tris[iTri].VXs[iVert]) );
}
//---------------------------------------------------------------------------
CObject3D *poGenerateDummyScene(CDummyTypes &_roDT)
{
    TCircuit *Circuit = Project.Circuit;
    if (! Circuit) return(NULL);

	unsigned int	        uiDType;
	unsigned int	        uiDInst;
    unsigned int            cI,cJ;

    // Model utilities and structures
	CLoaderGEM		        GEMLoader;
    CObject3D*	            *poDMdl;

    // Final structures
	CObject3D_Node	        *poMainNode;
    CObject3D_Node	        *poSectNode;
    CObject3D_Leaf          *poLeaf;

    // Intermediate temporal/auxiliary structures
    CObject3D*		        *poTmpDMdl;
	CObject3D_Node	        *poTmpLeafNode;
	CObject3D_Node	        *poTmpDTNode;

    // Meshes
    CMesh                   *poMesh;
    CMesh                   *poStripMesh;

    // Triangle scene utilities
    SCNUt_Stripifier        oStrip;
    SCNUt_MeshGenerator     oMshGen;
    SCNUt_Scn2TriScnBuilder oS2TSB;

    // Triangle scene structures
    SCNUt_MaterialTable     oMT;
    SCNUt_TriScene          *poTS;
    int                     iMesh;
    int                     iNumDInsts;

    float   fSectorSize;
    CVect3  oSMaxs,oSMins;
    fSectorSize = Circuit->GetSectorRes()*Project.EvPars.fXYScale;

    // ---------------
    // Load all models
    // ---------------
    poDMdl = mNew CObject3D_Gen*[_roDT.DTypes.size()];

    for (uiDType=0;uiDType<_roDT.DTypes.size();uiDType++)
    {
        poDMdl[uiDType] = (CObject3D_Gen*)GEMLoader.pLoad(_roDT.DTypes[uiDType].DummyModel.c_str());
        poDMdl[uiDType]->Reference();
    }

    // ---------------
    // Create a material table
    // ---------------
    oMT.Init( _roDT.DTypes.size() );

    // ------------------
    // Distribute dummies
    // ------------------
	poMainNode = mNew CObject3D_Node;
	poMainNode->Init( Circuit->GetSecsPerCol()*Circuit->GetSecsPerRow() );

    for (cJ=0;cJ<Circuit->GetSecsPerCol();cJ++)
        for (cI=0;cI<Circuit->GetSecsPerRow();cI++)
        {
            // Setup bounding box of the sector
            oSMins.V3((cI  )*fSectorSize,(cJ  )*fSectorSize,-1e5);
            oSMaxs.V3((cI+1)*fSectorSize,(cJ+1)*fSectorSize, 1e5);

            // Create the sector node
            poSectNode = mNew CObject3D_Node;
            poSectNode->Init( _roDT.DTypes.size() );

            for (uiDType=0;uiDType<_roDT.DTypes.size();uiDType++)
        	{
                // ---------------------------------------------
                // BEGIN: Sector triangle scene generation
                // ---------------------------------------------

                    // Reset num dummy instances
                    iNumDInsts = 0;

                    // Count node instances
                    for (uiDInst=0;uiDInst<_roDT.DTypes[uiDType].DInsts.size();uiDInst++)
                    {
                        if (_roDT.DTypes[uiDType].DInsts[uiDInst].oPos.Inside(oSMaxs,oSMins))
                            iNumDInsts++;
                    }

                    // Create temporary dummy-set node
                    poTmpDTNode = mNew CObject3D_Node;
                    poTmpDTNode->Init(iNumDInsts);

                    // Add instances
                    for (uiDInst=0;uiDInst<_roDT.DTypes[uiDType].DInsts.size();uiDInst++)
                    {
                        if (_roDT.DTypes[uiDType].DInsts[uiDInst].oPos.Inside(oSMaxs,oSMins))
                        {
                            // Setup dummy instance
                            poTmpLeafNode = mNew CObject3D_Node;
                            poTmpLeafNode->Init(1);
                            poTmpLeafNode->iAddObject((CObject3D_Gen*)poDMdl[uiDType]);
                            poTmpLeafNode->SetPos(_roDT.DTypes[uiDType].DInsts[uiDInst].oPos);

                            // Add instance to this dummy type list
                            poTmpDTNode->iAddObject(poTmpLeafNode);
                        }
                    }

                    poStripMesh = NULL;

                    if (iNumDInsts)
                    {
                        // Generate a triangle scene
                        poTS = oS2TSB.poBuild(poTmpDTNode,oMT);

                        // illuminate dummies
                        LIT_TriangleScene(*poTS);

                        // Generate a tringle mesh using the above triangle scene
                        poMesh = oMshGen.GenerateMesh(*poTS);

                        // Stripify scene
                        poStripMesh = oStrip.poStripifyMesh(poMesh);

                        mDel poMesh;         // Remove temporary data
                        mDel poTS;           // Remove temporary data
                        mDel poTmpDTNode;    // Remove temporary data
                    }

                // ---------------------------------------------
                // END: Sector triangle scene generation
                // ---------------------------------------------

                // ---------------------------------------------
                // BEGIN: Sector node generation
                // ---------------------------------------------

                    if (poStripMesh)
                    {
                        // Generate a leaf node
                        poLeaf = mNew CObject3D_Leaf;

                        // Set leaf node mesh and material
                        poLeaf->SetMesh  (poStripMesh);
                        poLeaf->SetShader(oMT.poGetShader(uiDType ));

                        // Add to the sector node
                        poSectNode->iAddObject(poLeaf);
                    }

                // ---------------------------------------------
                // END: Sector node generation
                // ---------------------------------------------
            }

            // Add sector node to the main dummy-scene node
            if (poSectNode->iGetNumSubObjects() > 0)
                poMainNode->iAddObject(poSectNode);
        }

    // ---------------
    // Unload all models
    // ---------------
    for (uiDType=0;uiDType<_roDT.DTypes.size();uiDType++)
        poDMdl[uiDType]->UnReference();
    mDel []poDMdl;

    // Return result
	poMainNode->ComputeBoundVol();
	return(poMainNode);

    /*
	for (uiDType=0;uiDType<_roDT.DTypes.size();uiDType++)
	{
		pDMdl = GEMLoader.pLoad(_roDT.DTypes[uiDType].DummyModel.c_str(),&_roMatWH);
		if (pDMdl)
		{
			pDTNode = mNew CObject3D_Node;
			pDTNode->Init(_roDT.DTypes[uiDType].DInsts.size());

			for (uiDInst=0;uiDInst<_roDT.DTypes[uiDType].DInsts.size();uiDInst++)
			{
				// Setup instance
				pLeafNode = mNew CObject3D_Node;
				pLeafNode->Init(1);
				pLeafNode->AddObject((CObject3D_Gen*)pDMdl);
				pLeafNode->SetPos(_roDT.DTypes[uiDType].DInsts[uiDInst].oPos);

				// Add instance to this dummy type list
				pDTNode->AddObject(pLeafNode);
			}

			pMainNode->AddObject(pDTNode);
		}
	}

	pMainNode->ComputeBoundVol();
	return(pMainNode);
    */
}
//---------------------------------------------------------------------------
void SaveDummyScene(char *_szDummyFile)
{
    CSaverGEM               oGEMSaver;
    CObject3D_Gen           *poDScene;
    CObject3D_Node          *poNode;

    poDScene = poNode->poGetObject(0);

    // Generate a dummy scene
    poDScene = (CObject3D_Gen*)poGenerateDummyScene(DLists);

    oGEMSaver.iSave(_szDummyFile,poDScene);
}
//---------------------------------------------------------------------------
void __fastcall TGUIMain::Savedummyscene1Click(TObject *Sender)
{
    dlg_Save->Filter        = "GammaE model files (*.gem)|*.gem|All the files (*.*)|*.*";
    dlg_Save->DefaultExt    = "gem";
    dlg_Save->FilterIndex   = 1;
    dlg_Save->Title         = "Save model File:";

    if (dlg_Save->Execute())
    {
        SaveDummyScene(dlg_Save->FileName.c_str());
    }
}
//---------------------------------------------------------------------------

