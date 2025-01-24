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
#include "CHUDMsgBox.h"
// -----------------------------------------------------------------------------
void NormalizeMeshRect(CGMesh* _poMesh)
{
    CVect3 oTrans(1,1,0);
    MeshTransform_Translate(*_poMesh,oTrans);

    CVect3 oScale(0.5f,0.5f,1.0f);
    MeshTransform_Scale    (*_poMesh,oScale);
}
// -----------------------------------------------------------------------------
void TranslateMesh(CGMesh* _poMesh,int _iRow,int _iCol)
{
    CVect3 oTrans(_iCol,_iRow,0.0f);
    MeshTransform_Translate(*_poMesh,oTrans);
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::Init (int _iRows,int _iCols)
{
    oGTxt.Init(_iCols,_iRows);

    iRows = _iRows;
    iCols = _iCols;

    iHdrPos = 0;

    TranslateMesh(poPrevIcLeaf->poGetMesh(),_iRows,_iCols / 2 - 1);
    TranslateMesh(poNextIcLeaf->poGetMesh(),_iRows,_iCols / 2 + 1);

    oMsg.Init(MAX_MSG_LINES);
}

CHUDMsgBox::CHUDMsgBox()
{
    eGraphBV_TypeID eOldType = CGraphBV_Manager::eGetBVMode();
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);

    // Create the text leaf
    poTxtLeaf = mNew CGSceneLeaf;
    poTxtLeaf->SetMesh(&oGTxt);

    // Create the background leaf and transf
    poBckLeaf = mNew CGSceneLeaf;
    poBckLeaf->SetMesh(&oBckRect);

    poBckTransf = mNew CGSceneTransf;
    poBckTransf->SetObject(poBckLeaf);

    CGSceneMux::Init(4);

    // Set text and background as childs
    iAddObject(poBckTransf);
    iAddObject(poTxtLeaf);

    // Add previous/next icons
    CE3D_Shader* poNIcShader = CE3D_ShaderWH::I()->poCreateShader("MessageBox_NextIcon");
    CE3D_Shader* poPIcShader = CE3D_ShaderWH::I()->poCreateShader("MessageBox_PrevIcon");

    CGMesh* poPMesh = mNew CGMeshRect;
    NormalizeMeshRect(poPMesh);
    poPrevIcLeaf = mNew CGSceneLeaf;
    poPrevIcLeaf->SetMesh  (poPMesh);
    poPrevIcLeaf->SetShader(poPIcShader);
    poPrevIcTransf = mNew CGSceneTransf;
    poPrevIcTransf->SetObject(poPrevIcLeaf);

    CGMesh* poNMesh = mNew CGMeshRect;
    NormalizeMeshRect(poNMesh);
    poNextIcLeaf = mNew CGSceneLeaf;
    poNextIcLeaf->SetMesh  (poNMesh);
    poNextIcLeaf->SetShader(poNIcShader);
    poNextIcTransf = mNew CGSceneTransf;
    poNextIcTransf->SetObject(poNextIcLeaf);

    iAddObject(poNextIcTransf);
    iAddObject(poNextIcTransf);

    CGraphBV_Manager::SetBVMode(eOldType);
}
// -----------------------------------------------------------------------------
CHUDMsgBox::~CHUDMsgBox()
{
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::SetFont(CE3D_Shader* _poShader)
{
    poTxtLeaf->SetShader( _poShader );
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::SetBackground(CE3D_Shader* _poShader)
{
    poBckLeaf->SetShader( _poShader );
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::SetColor(CGColor _oColor)
{
    if ( (oColor.r == _oColor.r) && (oColor.g == _oColor.g) &&
        (oColor.b == _oColor.b) && (oColor.a == _oColor.a) ) return;

    oColor = _oColor;

    CGColor* poVC = poTxtLeaf->poGetMesh()->m_poVC;
    for ( int cI = 0; cI < MAX_LINE_CHARS * 4; cI++ )
    {
        poVC->Set(oColor.r,oColor.g,oColor.b,oColor.a);
        poVC++;
    }
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::SetText(char* _szText)
{
    if ( !_szText ) return;

    TMsgLine oMsgLine;

    // Mensaje nuevo
    oMsg.Clear();

    char* szString = _szText;

    while ( *szString )
    {
        // ---------------
        // Get a line
        // ---------------
        int i = 0;
        char szLine[MAX_LINE_CHARS];                    // Máximo una linea de MAX_LABEL_CHARS caracteres

        while ( (*szString != '\n') && (*szString != 0) && (i < MAX_LINE_CHARS - 1) )
        {
            szLine[i] = *szString;
            szString++;
            i++;
        }
        if ( *szString == '\n' ) szString++;

        szLine[i] = 0;

        // ---------------
        // Parse this line
        // ---------------
        char szWord[256];                    // Máximo una palabra de 256 caracteres
        int len_szWord = 0;
        int len_szLine = 0;
        char* szWordPtr = szLine;

        oMsgLine.szLine[0] = 0;
        while ( *szWordPtr )
        {
            // Coger palabra
            // Quitar espacios iniciales
            while ( (*szWordPtr == ' ') && (*szWordPtr) ) szWordPtr++;

            // Coger palabra
            len_szWord = 0;
            while ( (*szWordPtr != ' ') && (*szWordPtr) )
                szWord[len_szWord++] = *szWordPtr++;

            szWord[len_szWord] = 0;                    // Finalizar palabra

            // Quitar espacios finales
            while ( (*szWordPtr == ' ') && (*szWordPtr) ) szWordPtr++;

            // Si hay palabra
            if ( len_szWord )
            {
                // Si la palabra cabe en esa linea...
                if ( len_szLine + 1 + len_szWord < iCols )
                {
                    // Linea = Linea + ' '
                    if ( len_szLine )
                    {
                        // Añadir un espacio
                        oMsgLine.szLine[len_szLine++] = ' ';
                    }

                    // Linea = Linea +  palabra
                    strcpy(oMsgLine.szLine + len_szLine,szWord);
                    len_szLine += len_szWord;
                }
                else
                {
                    // Fill the line with spaces (left justify)
                    /*
                       while (len_szLine < iCols)
                        oLine.szLine[len_szLine++] = ' ';
                       oLine.szLine[len_szLine] = 0;
                     */

                    // Nueva linea
                    oMsg.iAdd(oMsgLine);

                    // Linea = palabra
                    strcpy(oMsgLine.szLine,szWord);

                    len_szLine = len_szWord;
                }
            }
        }

        // Si quedaban palabras por meter, ponerlas ahora
        if ( len_szLine )
        {
            oMsg.iAdd(oMsgLine);
        }
    }
}
// -----------------------------------------------------------------------------
// Set up graphically the text
// -----------------------------------------------------------------------------
void CHUDMsgBox::SetGText()
{
    if ( oMsg.uiNumElems() <= iRows )
    {
        // Display all the text
        oGTxt.Reset();
        for ( int i = 0; i < oMsg.uiNumElems(); i++ )
            oGTxt.WriteText(oMsg[i].szLine,oColor,1.0f);

        CMatrix4x4 oMat;
        oMat.LoadIdentity();
        oMat.Scale(0,0,0);

        poNextIcTransf->SetTransf(oMat);
        poPrevIcTransf->SetTransf(oMat);

        Deselect(2);
        Deselect(3);
    }
    else
    {
        CMatrix4x4 oMat;
        oMat.LoadIdentity();

        poNextIcTransf->SetTransf(oMat);
        poPrevIcTransf->SetTransf(oMat);

        oGTxt.Reset();
        for ( int i = 0; i < iRows; i++ )
            oGTxt.WriteText(oMsg[ i + iHdrPos ].szLine,oColor,1.0f);

        if ( iHdrPos == 0 )
        {
            Deselect(2);
            Select  (3);
        }
        else
        {
            if ( iHdrPos + iRows == oMsg.uiNumElems() )
            {
                Select  (2);
                Deselect(3);
            }
            else
            {
                Select(2);
                Select(3);
            }
        }
    }
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::SetBackground()
{
    // Get maximum width and height
    int iHeight,iWidth;
    iHeight = iGetHeightChars();
    iWidth = iGetWidthChars();

    CMatrix4x4 oMat;
    oMat.LoadIdentity();
    oMat.Translate(iCols * 0.5f,iHeight * 0.5f,0.0f);
    oMat.Scale(iWidth + 3,iHeight + 1,1.0f);
    oMat.Scale(0.5f,0.5f,1.0f);

    poBckTransf->SetTransf(oMat);
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::AdvanceHdr()
{
    if ( iHdrPos + iRows + 1 <= oMsg.uiNumElems() )
    {
        iHdrPos++;
        SetGText();
    }
}

void CHUDMsgBox::PutBackHdr()
{
    if ( iHdrPos > 0 )
    {
        iHdrPos--;
        SetGText();
    }
}
// -----------------------------------------------------------------------------
void CHUDMsgBox::Open(char* _szText)
{
    SelectAll();

    iHdrPos = 0;
    SetText(_szText);
    SetGText();
    SetBackground();
    ComputeBoundVol();
}

void CHUDMsgBox::Close()
{
    SelectNone();
}
// -----------------------------------------------------------------------------
int CHUDMsgBox::iGetWidthChars()
{
    int iWidth;
    if ( oMsg.uiNumElems() <= iRows )
    {
        // Display all the text
        iWidth = 0;
        for ( int i = 0; i < oMsg.uiNumElems(); i++ )
        {
            int iLen = strlen(oMsg[i].szLine);
            if ( iLen > iWidth ) iWidth = iLen;
        }
    }
    else
    {
        // Display all the text
        iWidth = 0;
        for ( int i = 0; i < iRows; i++ )
        {
            int iLen = strlen(oMsg[iHdrPos + i].szLine);
            if ( iLen > iWidth ) iWidth = iLen;
        }
    }

    return(iWidth);
}

int CHUDMsgBox::iGetHeightChars()
{
    if ( oMsg.uiNumElems() <= iRows )
        return( oMsg.uiNumElems() );
    else
        return(iRows);
}
// -----------------------------------------------------------------------------
