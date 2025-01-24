#include "CHUDProgressBar.h"
//-----------------------------------------------------------------------------
CHUDProgressBar::CHUDProgressBar()
{
	eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

	CObject3D_Node*	poNode = mNew CObject3D_Node(2);
	CObject3D_Leaf* poLeaf = NULL;
	CMesh*			poMesh = NULL;

	CVect3 oTrans(1.0f,1.0f,0.0f);
	CVect3 oScale(0.5f,0.5f,1.0f);

	// ------------------------------
	// Create the progress bar mesh
	// ------------------------------
	poMesh = mNew CMesh_Rect;
	MeshTransform_Translate(*poMesh,oTrans);
	MeshTransform_Scale(*poMesh,oScale);

	// Create the leaf
	poLeaf = mNew CObject3D_Leaf;
	poLeaf->SetMesh(poMesh);

	// Create progress bar default shader
	CGColor oBarColor(1.0f,1.0f,1.0f,1.0f);
	poDefBarSh = CE3D_ShaderUtils::poGenerateShaderFromColor(oBarColor,"BarColor");
	poLeaf->SetShader(poDefBarSh);

	// Set leaf as first child
	poNode->iAddObject(poLeaf);
	m_poBarMesh = poMesh;
	m_poBarLeaf = poLeaf;

	// ------------------------------
	// Create the frame mesh
	// ------------------------------	
	poMesh= mNew CMesh_Rect;	
	MeshTransform_Translate(*poMesh,oTrans);
	MeshTransform_Scale(*poMesh,oScale);
	
	// Create the leaf
	poLeaf = mNew CObject3D_Leaf;
	poLeaf->SetMesh(poMesh);
	m_poFrameLeaf = poLeaf;
	
	// Set leaf as second child
	poNode->iAddObject(poLeaf);

	// Set the node as main object
	SetObject(poNode);

	ComputeBoundVol();
	CGraphBV_Manager::SetBVMode(eOldType);

	m_fValue = 1.0f;
}
//-----------------------------------------------------------------------------
CHUDProgressBar::~CHUDProgressBar()
{
}
//-----------------------------------------------------------------------------
inline float fIrp(float _a,float _b,float _f)
{
	return(_a + (_b-_a)*_f);
}


void CHUDProgressBar::Value(float _fValue)
{	
	m_fValue = _fValue;

	m_poBarMesh->VXs[1].x = m_fValue;
	m_poBarMesh->VXs[2].x = m_fValue;
	
	CGColor oRCol;
	oRCol.r = fIrp(oIniColor.r,oEndColor.r,m_fValue);
	oRCol.g = fIrp(oIniColor.g,oEndColor.g,m_fValue);
	oRCol.b = fIrp(oIniColor.b,oEndColor.b,m_fValue);
	oRCol.a = fIrp(oIniColor.a,oEndColor.a,m_fValue);

	m_poBarMesh->VCs[1].Set(oRCol.r,oRCol.g,oRCol.b,oRCol.a);
	m_poBarMesh->VCs[2].Set(oRCol.r,oRCol.g,oRCol.b,oRCol.a);

	m_poBarMesh->UVs[1].x = m_fValue;
	m_poBarMesh->UVs[2].x = m_fValue;

	m_poBarMesh->ComputeBoundVol();
}
//-----------------------------------------------------------------------------
void CHUDProgressBar::SetFrameShader(CE3D_Shader *_poShader)
{
	poFShader = _poShader;

	if (poFShader)
		m_poFrameLeaf->SetShader(poFShader);
}
//-----------------------------------------------------------------------------
void CHUDProgressBar::SetBarShader(CE3D_Shader *_poShader)
{
	poBShader = _poShader;

	if (poBShader)
		m_poBarLeaf->SetShader(poBShader);
	else
		m_poBarLeaf->SetShader(poBShader);
}
//-----------------------------------------------------------------------------
void CHUDProgressBar::SetIniColor(CGColor _oColor)
{
	if ((oIniColor.r == _oColor.r) && (oIniColor.g == _oColor.g) &&
	    (oIniColor.b == _oColor.b) && (oIniColor.a == _oColor.a)) return;

	oIniColor = _oColor;

	CGColor *poVC = m_poBarMesh->VCs;
	poVC[0] = _oColor;
	poVC[3] = _oColor;	
}
//-----------------------------------------------------------------------------
void CHUDProgressBar::SetEndColor(CGColor _oColor)
{
	if ((oEndColor.r == _oColor.r) && (oEndColor.g == _oColor.g) &&
	    (oEndColor.b == _oColor.b) && (oEndColor.a == _oColor.a)) return;

	oEndColor = _oColor;

	CGColor *poVC = m_poBarMesh->VCs;
	poVC[1] = _oColor;
	poVC[2] = _oColor;
}
//-----------------------------------------------------------------------------