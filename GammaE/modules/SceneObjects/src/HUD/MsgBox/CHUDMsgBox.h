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
#ifndef CHUDMsgBoxH
#define CHUDMsgBoxH

#include "GammaE_E3D.h"
#include "GammaE_Scene.h"

#include "CMenuTextGrid.h"

#define MAX_LINE_CHARS  64
#define MAX_MSG_LINES   128

typedef struct
{
    char szLine[MAX_LINE_CHARS];
}TMsgLine;

class CHUDMsgBox : public CGSceneMux
{
    public:     CHUDMsgBox();
        virtual ~CHUDMsgBox();

        void Init(int _iRows,int _iCols);

        void Open(char* _szText);
        void Close();

        void SetBackground(CGShader* _poShader);
        void SetFont(CGShader* _poShader);                    //
        void SetColor(CGColor _oColor);                         //

        void AdvanceHdr();
        void PutBackHdr();

        int iGetWidthChars();
        int iGetHeightChars();

    protected:  CGStArray <TMsgLine> oMsg;

        void SetText(char* _szText);                             //
        void SetGText();                                        //
        void SetBackground();                                   //

        int iHdrPos;

        CMenuTextGrid oGTxt;
        CGMeshRect oBckRect;

        CGSceneLeaf* poTxtLeaf;

        CGSceneLeaf* poBckLeaf;
        CGSceneTransf* poBckTransf;

        CGSceneLeaf* poPrevIcLeaf;
        CGSceneTransf* poPrevIcTransf;

        CGSceneLeaf* poNextIcLeaf;
        CGSceneTransf* poNextIcTransf;
        
        CGMesh* poPrevIcMesh;
        CGMesh* poNextIcMesh;

        CGColor oColor;
        int iRows;
        int iCols;
};

#endif
