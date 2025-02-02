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
// -----------------------------------------------------------------------------
#include "CHUDLabel.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------------
#define MAX_LABEL_CHARS 64
// -----------------------------------------------------------------------------
CHUDLabel::CHUDLabel()
{
    InternalInit(MAX_LABEL_CHARS);
}
// -----------------------------------------------------------------------------
CHUDLabel::CHUDLabel(uint _uiMaxChars)
{
    InternalInit(_uiMaxChars);
}
// -----------------------------------------------------------------------------
void CHUDLabel::InternalInit(uint _uiMaxChars)
{
    EGBoundingVolumeType eOldType = CGGraphBVFactory::eGetBVMode();
    CGGraphBVFactory::SetBVMode(EGBoundingVolumeType::BVT_AABB);

    // Create the leaf
    poLeaf = mNew CGSceneLeaf;

    CreateGeometry(_uiMaxChars);

    poFont = NULL;

    // Set leaf as child
    SetObject(poLeaf);

    // Recompute BVol
    CGSCNVBoundVolBuilder::I()->Visit(this);
    CGGraphBVFactory::SetBVMode(eOldType);
}
// -----------------------------------------------------------------------------
void CHUDLabel::CreateGeometry(uint _uiMaxChars)
{
    // Create new string data
    uiMaxChars = _uiMaxChars;

    // Create the text mesh
    m_poGeometryMesh = mNew CGMesh;
    m_poGeometryMesh->Init(4 * uiMaxChars,
        uiMaxChars,
        E3D_PrimitiveType::E3D_PT_NIQUADS,
        MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);

    m_poLabelMesh = mNew CGUnmanagedMesh();
    m_poLabelMesh->m_poVX = m_poGeometryMesh->m_poVX;
    m_poLabelMesh->m_poUV = m_poGeometryMesh->m_poUV;
    m_poLabelMesh->m_poVC = m_poGeometryMesh->m_poVC;
    m_poLabelMesh->SetPrimitiveType(m_poGeometryMesh->eGetPrimitiveType());

    CGVect3* poVX = m_poLabelMesh->m_poVX;
    CGColor* poVC = m_poLabelMesh->m_poVC;

    for (uint cI = 0; cI < uiMaxChars; cI++)
    {
        poVX[0].Set(cI, 0.0f, 0.0f);
        poVX[1].Set(cI, 1.0f, 0.0f);
        poVX[2].Set(cI + 1, 1.0f, 0.0f);
        poVX[3].Set(cI + 1, 0.0f, 0.0f);

        poVC[0].Set(oColor.r, oColor.g, oColor.b, oColor.a);
        poVC[1].Set(oColor.r, oColor.g, oColor.b, oColor.a);
        poVC[2].Set(oColor.r, oColor.g, oColor.b, oColor.a);
        poVC[3].Set(oColor.r, oColor.g, oColor.b, oColor.a);

        poVX += 4;
        poVC += 4;
    }

    poLeaf->SetMesh(m_poLabelMesh);
}
// -----------------------------------------------------------------------------
void CHUDLabel::SetMaxChars(uint _uiMaxChars)
{
    if ( _uiMaxChars == uiMaxChars ) return;

    // Delete old data
    mDel m_poGeometryMesh;

    CreateGeometry(_uiMaxChars);
    //
    SetText( sText );
}
// -----------------------------------------------------------------------------
void CHUDLabel::SetFont(CHUDFont* _poFont)
{
    poFont = _poFont;
    poLeaf->SetShader( poFont->poGetShader() );
}
// -----------------------------------------------------------------------------
void CHUDLabel::SetColor(CGColor _oColor)
{
    if ( (oColor.r == _oColor.r) && (oColor.g == _oColor.g) &&
        (oColor.b == _oColor.b) && (oColor.a == _oColor.a) ) return;

    oColor = _oColor;

    CGColor* poVC = m_poLabelMesh->m_poVC;
    for ( uint cI = 0; cI < uiMaxChars * 4; cI++ )
    {
        poVC->Set(oColor.r,oColor.g,oColor.b,oColor.a);
        poVC++;
    }
}
// -----------------------------------------------------------------------------
void CHUDLabel::WriteChar(char _cA,float _fOfsX,float _fW)
{
    float u1,v1,u2,v2;

    int iRow = _cA / 16;                    // Get the proper row in the font texture
    int iCol = _cA % 16;                    // Get the proper col in the font texture

    float fWFact = _fW * poFont->fDefaultCharWidth();
    float fPad = (poFont->fDefaultCharWidth() - fWFact) * 0.5f;
    u1 = fPad + (float)(iCol) / 16.0f;
    v1 = (float)(iRow) / 16.0f;
    u2 = u1 + fWFact;
    v2 = (float)(iRow + 1) / 16.0f;

    /*
       u1 = (float)(iCol  )/16.0f;
       v1 = (float)(iRow  )/16.0f;
       u2 = (float)(iCol+1)/16.0f; // u1 + fWFact;
       v2 = (float)(iRow+1)/16.0f;
     */

    // Setup UV coords
    CGVect2* poUV = m_poLabelMesh->m_poUV + 4 * m_poLabelMesh->uiGetNumPrims();
    CGVect3* poVX = m_poLabelMesh->m_poVX + 4 * m_poLabelMesh->uiGetNumPrims();

    poUV[0].Set(u1,v1);
    poUV[1].Set(u1,v2);
    poUV[2].Set(u2,v2);
    poUV[3].Set(u2,v1);

    poVX[0].Set(_fOfsX,0.0f,0.0f);
    poVX[1].Set(_fOfsX,1.0f,0.0f);
    poVX[2].Set(_fOfsX + _fW,1.0f,0.0f);
    poVX[3].Set(_fOfsX + _fW,0.0f,0.0f);
}
// -----------------------------------------------------------------------------
void CHUDLabel::SetText(const CGString& _sText)
{
    if ( _sText == sText ) return;
    uint uiLen = _sText.uiLen();

    if ( uiLen > uiMaxChars )
    {
        uiLen = uiMaxChars;
        sText = _sText;
        sText = sText.SubString(0,uiLen);
    }
    else
        sText = _sText;

    float fXOfs = 0;
    uint uiNumPrims = 0;
    for ( uint cI = 0; cI < uiLen; cI++ )
    {
        float fW = poFont->fCharWidth(sText[cI]) / poFont->fDefaultCharWidth();

        WriteChar(sText[cI],fXOfs,fW);
        uiNumPrims++;

        fXOfs += fW;
    }

    m_poLabelMesh->SetNumPrims(uiNumPrims);
    m_poLabelMesh->SetNumVXs(m_poLabelMesh->uiGetNumPrims()* 4);
}
// -----------------------------------------------------------------------------
void CHUDLabel::SetText(char* fmt,...)
{
    char szLocalBuff[8192];

    va_list argptr;
    va_start(argptr,fmt);
    vsprintf(szLocalBuff,fmt,argptr);
    va_end  (argptr);

    SetText( CGString(szLocalBuff) );
}
// -----------------------------------------------------------------------------
