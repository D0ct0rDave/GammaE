//	  %X% %Q% %Z% %W%



#ifndef CConsole_h
#define CConsole_h 1



// CMesh_Rect
#include "GammaE_E3D.h"
// CObject3D_Leaf
#include "GammaE_Scene.h"
// CHUD
#include "hud/CHUD.h"

class CConsole : public CHUD
{
    
  public:
          CConsole();

          virtual ~CConsole();


            void Init (float _Width, float _Height, int _Cols, int _ows, CE3D_Shader* _BGMat, CE3D_Shader* _CMMat);

            void Write (char* _szTex);

            void WriteXY (int X, int Y, char *Text);

            void Resize (float _Width, float _Height);

            void SetChar (int _X, int _Y, char _a);

            void CreateCharMatrix ();

            void SetCharMatrixMat (CE3D_Shader *_CMMat);

            void SetBackgroundMat (CE3D_Shader *_BGMat);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  float Width;
      
                  float Height;
      
                  int Cols;
      
                  int Rows;
      
                  CE3D_Shader *BackgroundMat;
      
                  CE3D_Shader *CharMatrixMat;
      
                  CObject3D_Leaf *Background;
      
                  CObject3D_Leaf *CharMatrix;
      
                  char *Data;
      
                  CMesh *MatrixMesh;
      
                  CGColor Color;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CConsole 



#endif
