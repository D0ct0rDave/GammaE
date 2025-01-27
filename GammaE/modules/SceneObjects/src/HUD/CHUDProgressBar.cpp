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
#include "CHUDProgressBar.h"
// -----------------------------------------------------------------------------
CHUDProgressBar::CHUDProgressBar()
{
    EGBoundingVolumeType eOldType = CGGraphBVFactory::eGetBVMode();
    CGGraphBVFactory::SetBVMode(EGBoundingVolumeType::BVT_AABB);

    CGSceneGroup* poNode = mNew CGSceneGroup(2);
    CGSceneLeaf* poLeaf = NULL;
    CGMesh* poMesh = NULL;

    CGVect3 oTrans(1.0f,1.0f,0.0f);
    CGVect3 oScale(0.5f,0.5f,1.0f);

    // ------------------------------
    // Create the progress bar mesh
    // ------------------------------
    poMesh = mNew CGMeshRect;
    MeshUtils::TranslateMesh(*poMesh,oTrans);
    MeshUtils::ScaleMesh(*poMesh,oScale);

    // Create the leaf
    poLeaf = mNew CGSceneLeaf;
    poLeaf->SetMesh(poMesh);

    // Create progress bar default shader
    CGColor oBarColor(1.0f,1.0f,1.0f,1.0f);
    poDefBarSh = CGShaderUtils::poGenerateShaderFromColor(oBarColor,"BarColor");
    poLeaf->SetShader(poDefBarSh);

    // Set leaf as first child
    poNode->iAddObject(poLeaf);
    m_poBarMesh = poMesh;
    m_poBarLeaf = poLeaf;

    // ------------------------------
    // Create the frame mesh
    // ------------------------------
    poMesh = mNew CGMeshRect;
    MeshUtils::TranslateMesh(*poMesh,oTrans);
    MeshUtils::ScaleMesh(*poMesh,oScale);

    // Create the leaf
    poLeaf = mNew CGSceneLeaf;
    poLeaf->SetMesh(poMesh);
    m_poFrameLeaf = poLeaf;

    // Set leaf as second child
    poNode->iAddObject(poLeaf);

    // Set the node as main object
    SetObject(poNode);

    CGSCNVBoundVolBuilder::I()->Visit(this);

    CGGraphBVFactory::SetBVMode(eOldType);

    m_fValue = 1.0f;
}
// -----------------------------------------------------------------------------
CHUDProgressBar::~CHUDProgressBar()
{
}
// -----------------------------------------------------------------------------
inline float fIrp(float _a,float _b,float _f)
{
    return(_a + (_b - _a) * _f);
}

void CHUDProgressBar::Value(float _fValue)
{
    m_fValue = _fValue;

    m_poBarMesh->m_poVX[1].x = m_fValue;
    m_poBarMesh->m_poVX[2].x = m_fValue;

    CGColor oRCol;
    oRCol.r = fIrp(oIniColor.r,oEndColor.r,m_fValue);
    oRCol.g = fIrp(oIniColor.g,oEndColor.g,m_fValue);
    oRCol.b = fIrp(oIniColor.b,oEndColor.b,m_fValue);
    oRCol.a = fIrp(oIniColor.a,oEndColor.a,m_fValue);

    m_poBarMesh->m_poVC[1].Set(oRCol.r,oRCol.g,oRCol.b,oRCol.a);
    m_poBarMesh->m_poVC[2].Set(oRCol.r,oRCol.g,oRCol.b,oRCol.a);

    m_poBarMesh->m_poUV[1].x = m_fValue;
    m_poBarMesh->m_poUV[2].x = m_fValue;

    // m_poBarMesh->ComputeBoundVol();
}
// -----------------------------------------------------------------------------
void CHUDProgressBar::SetFrameShader(CGShader* _poShader)
{
    poFShader = _poShader;

    if ( poFShader )
        m_poFrameLeaf->SetShader(poFShader);
}
// -----------------------------------------------------------------------------
void CHUDProgressBar::SetBarShader(CGShader* _poShader)
{
    poBShader = _poShader;

    if ( poBShader )
        m_poBarLeaf->SetShader(poBShader);
    else
        m_poBarLeaf->SetShader(poBShader);
}
// -----------------------------------------------------------------------------
void CHUDProgressBar::SetIniColor(CGColor _oColor)
{
    if ( (oIniColor.r == _oColor.r) && (oIniColor.g == _oColor.g) &&
        (oIniColor.b == _oColor.b) && (oIniColor.a == _oColor.a) ) return;

    oIniColor = _oColor;

    CGColor* poVC = m_poBarMesh->m_poVC;
    poVC[0] = _oColor;
    poVC[3] = _oColor;
}
// -----------------------------------------------------------------------------
void CHUDProgressBar::SetEndColor(CGColor _oColor)
{
    if ( (oEndColor.r == _oColor.r) && (oEndColor.g == _oColor.g) &&
        (oEndColor.b == _oColor.b) && (oEndColor.a == _oColor.a) ) return;

    oEndColor = _oColor;

    CGColor* poVC = m_poBarMesh->m_poVC;
    poVC[1] = _oColor;
    poVC[2] = _oColor;
}
// -----------------------------------------------------------------------------
