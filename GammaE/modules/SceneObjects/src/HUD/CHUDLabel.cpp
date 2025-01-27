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
    uiMaxChars = _uiMaxChars;

    eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    // Create the text mesh
    CGMesh* poMesh;

    poMesh = mNew CGMesh;
    poMesh->Init(4 * uiMaxChars,
                 uiMaxChars,
                 E3D_MESH_NIQUADS,
                 MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);

    CGVect3* poVX = poMesh->m_poVX;

    for ( uint cI = 0; cI < uiMaxChars; cI++ )
    {
        poVX[0].Set(cI,0.0f,0.0f);
        poVX[1].Set(cI,1.0f,0.0f);
        poVX[2].Set(cI + 1,1.0f,0.0f);
        poVX[3].Set(cI + 1,0.0f,0.0f);

        poVX += 4;
    }

    // Create the leaf
    poLeaf = mNew CGSceneLeaf;
    poLeaf->SetMesh(poMesh);

    poFont = NULL;

    // Set leaf as child
    SetObject(poLeaf);
    ComputeBoundVol();
    CGraphBV_Manager::SetBVMode(eOldType);
}
// -----------------------------------------------------------------------------
CGBoundingVolume* CHUDLabel::poCreateBoundVol()
{
    eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    CGBoundingVolume* poBVol = CGraphBV_Manager::poCreate();

    CGraphBV_Manager::SetBVMode(eOldType);

    return(poBVol);
}
// -----------------------------------------------------------------------------
CHUDLabel::~CHUDLabel()
{
}
// -----------------------------------------------------------------------------
void CHUDLabel::SetMaxChars(uint _uiMaxChars)
{
    if ( _uiMaxChars == uiMaxChars ) return;

    // Delete old data
    CGMesh* poOldMesh = poLeaf->poGetMesh();
    mDel poOldMesh;

    // Create new string data
    uiMaxChars = _uiMaxChars;

    // Create the text mesh
    CGMesh* poMesh;
    poMesh = mNew CGMesh;
    poMesh->Init(4 * uiMaxChars,
                 uiMaxChars,
                 E3D_MESH_NIQUADS,
                 MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);

    CGVect3* poVX = poMesh->m_poVX;
    CGColor* poVC = poMesh->m_poVC;

    for ( uint cI = 0; cI < uiMaxChars; cI++ )
    {
        poVX[0].Set(cI,0.0f,0.0f);
        poVX[1].Set(cI,1.0f,0.0f);
        poVX[2].Set(cI + 1,1.0f,0.0f);
        poVX[3].Set(cI + 1,0.0f,0.0f);

        poVC[0].Set(oColor.r,oColor.g,oColor.b,oColor.a);
        poVC[1].Set(oColor.r,oColor.g,oColor.b,oColor.a);
        poVC[2].Set(oColor.r,oColor.g,oColor.b,oColor.a);
        poVC[3].Set(oColor.r,oColor.g,oColor.b,oColor.a);

        poVX += 4;
        poVC += 4;
    }

    poLeaf->SetMesh(poMesh);

    // Recompute BVol
    ComputeBoundVol();

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

    CGColor* poVC = poLeaf->poGetMesh()->m_poVC;
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
    CGVect2* poUV = poLeaf->poGetMesh()->m_poUV + 4 * poLeaf->poGetMesh()->m_uiNumPrims;
    CGVect3* poVX = poLeaf->poGetMesh()->m_poVX + 4 * poLeaf->poGetMesh()->m_uiNumPrims;

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
    poLeaf->poGetMesh()->m_uiNumPrims = 0;
    for ( uint cI = 0; cI < uiLen; cI++ )
    {
        float fW = poFont->fCharWidth(sText[cI]) / poFont->fDefaultCharWidth();

        WriteChar(sText[cI],fXOfs,fW);
        poLeaf->poGetMesh()->m_uiNumPrims++;

        fXOfs += fW;
    }

    poLeaf->poGetMesh()->m_usNumVXs = poLeaf->poGetMesh()->m_uiNumPrims * 4;
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
