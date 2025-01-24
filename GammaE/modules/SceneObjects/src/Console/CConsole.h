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
// %X% %Q% %Z% %W%

#ifndef CConsole_h
#define CConsole_h 1

// CGMesh_Rect
#include "GammaE_E3D.h"
// CGSceneLeaf
#include "GammaE_Scene.h"
// CHUD
#include "hud/CHUD.h"

class CConsole : public CHUD
{
    public:
        CConsole();

        virtual ~CConsole();

        void Init(float _Width, float _Height, int _Cols, int _ows, CE3D_Shader* _BGMat, CE3D_Shader* _CMMat);

        void Write(char* _szTex);

        void WriteXY(int X, int Y, char* Text);

        void Resize(float _Width, float _Height);

        void SetChar(int _X, int _Y, char _a);

        void CreateCharMatrix();

        void SetCharMatrixMat(CE3D_Shader* _CMMat);

        void SetBackgroundMat(CE3D_Shader* _BGMat);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        float Width;

        float Height;

        int Cols;

        int Rows;

        CE3D_Shader* BackgroundMat;

        CE3D_Shader* CharMatrixMat;

        CGSceneLeaf* Background;

        CGSceneLeaf* CharMatrix;

        char* Data;

        CGMesh* MatrixMesh;

        CGColor Color;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CConsole

#endif
