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
#include "CMenuTextGrid.h"
#include <string.h>
// -----------------------------------------------------------------------------
CMenuTextGrid::CMenuTextGrid()
{
}
// -----------------------------------------------------------------------------
void CMenuTextGrid::Init(int _iCols,int _iMaxRows)
{
    iCols = _iCols;
    iMaxRows = _iMaxRows;
    iCurRow = 0;

    CGMesh::Init(4 * iMaxRows * iCols,
                 iMaxRows * iCols,
                 E3D_PrimitiveType::E3D_PT_NIQUADS,
                 MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);
}
// -----------------------------------------------------------------------------
void CMenuTextGrid::Reset()
{
    m_uiNumPrims = 0;
    m_uiNumVXs = 0;
    iCurRow = 0;
}
// -----------------------------------------------------------------------------
void CMenuTextGrid::WriteChar(float _fX,float _fY, CGColor _oColor,char _cA)
{
    const float fUSize = 1.0f / 8.0f;
    const float fVSize = 1.0f / 16.0f;
    float fU,fV,u1,v1,u2,v2;
    int iX,iY;

    // Get proper UV coords
    int iChar = _cA - 'A';
    if ( (_cA >= 'A') && (_cA <= 'Z') )
    {
        iChar = _cA - 'A';
    }
    else
    if ( (_cA >= 'a') && (_cA <= 'z') )
    {
        iChar = (_cA - 'a') + (2 + 3 * 8);
    }
    else
    if ( (_cA >= '0') && (_cA <= '9') )
    {
        iChar = (_cA + 17) + (3 + 6 * 8);
    }
    else
    if ( _cA == '?' )
    {
        iChar = (8 * 8) - 2;
    }
    else
    if ( _cA == '!' )
    {
        iChar = (8 * 8) - 1;
    }
    else
    if ( _cA == 'ñ' )
    {
        iChar = (8 * 8) + 0;
    }
    else
    if ( _cA == 'á' )
    {
        iChar = (8 * 8) + 1;
    }
    else
    if ( _cA == 'é' )
    {
        iChar = (8 * 8) + 2;
    }
    else
    if ( _cA == 'í' )
    {
        iChar = (8 * 8) + 3;
    }
    else
    if ( _cA == 'ó' )
    {
        iChar = (8 * 8) + 4;
    }
    else
    if ( _cA == 'ú' )
    {
        iChar = (8 * 8) + 5;
    }
    else
    if ( _cA == '.' )
    {
        iChar = (8 * 8) + 6;
    }
    else
    if ( _cA == ',' )
    {
        iChar = (8 * 8) + 7;
    }
    else
    {
        // Point to the last char
        iChar = (8 * 16) - 1;
    }

    iX = iChar % 8;
    iY = iChar / 8;

    fU = (float)iX * fUSize;
    fV = (float)iY * fVSize;

    // Get data pointers
    CGVect2* poUV = m_poUV + 4 * m_uiNumPrims;
    CGVect3* poVX = m_poVX + 4 * m_uiNumPrims;
    CGColor* poVC = m_poVC + 4 * m_uiNumPrims;

    // Setup vertices
    poVX[0].Set(_fX,_fY,0.0f);
    poVX[1].Set(_fX,_fY + 1.0f,0.0f);
    poVX[2].Set(_fX + 1.0f,_fY + 1.0f,0.0f);
    poVX[3].Set(_fX + 1.0f,_fY,0.0f);

    // Setup tex coords
    poUV[0].Set(fU,fV       );
    poUV[1].Set(fU,fV + fVSize);
    poUV[2].Set(fU + fUSize,fV + fVSize);
    poUV[3].Set(fU + fUSize,fV       );

    // Setup color
    poVC[0] = _oColor;
    poVC[1] = _oColor;
    poVC[2] = _oColor;
    poVC[3] = _oColor;

    m_uiNumPrims++;
    m_uiNumVXs += 4;
}
// -----------------------------------------------------------------------------
void CMenuTextGrid::WriteXY  (float _fXOfs, float _fYOfs, CGColor _oColor,char* _szText)
{
    int iPos = 0;

    while ( *_szText )
    {
        WriteChar(_fXOfs + (float)iPos,_fYOfs,_oColor,*_szText);

        iPos++;
        _szText++;
    }
}
// -----------------------------------------------------------------------------
void CMenuTextGrid::WriteText(char* _szText,CGColor _oColor,float _fAlpha)
{
    CGColor oFinalColor;
    oFinalColor = _oColor;
    oFinalColor.a *= _fAlpha;

    int iStrLen = strlen(_szText);
    float fXOfs = ( (float)iCols - (float)iStrLen ) * 0.5f;

    WriteXY(fXOfs,(float)iCurRow,oFinalColor,_szText);
    iCurRow++;
}
// -----------------------------------------------------------------------------