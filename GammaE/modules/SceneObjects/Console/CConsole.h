//## begin module%3AF6F98F00DC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AF6F98F00DC.cm

//## begin module%3AF6F98F00DC.cp preserve=no
//## end module%3AF6F98F00DC.cp

//## Module: CConsole%3AF6F98F00DC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\Console\CConsole.h

#ifndef CConsole_h
#define CConsole_h 1

//## begin module%3AF6F98F00DC.additionalIncludes preserve=no
//## end module%3AF6F98F00DC.additionalIncludes

//## begin module%3AF6F98F00DC.includes preserve=yes
//## end module%3AF6F98F00DC.includes

// CMesh_Rect
#include "E3D\Mesh\CMesh_Rect.h"
// CHeadUpDisplay
#include "Scene\2D_Objects\CHeadUpDisplay.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3AF6F98F00DC.additionalDeclarations preserve=yes
//## end module%3AF6F98F00DC.additionalDeclarations


//## begin CConsole%3AF6F98F00DC.preface preserve=yes
//## end CConsole%3AF6F98F00DC.preface

//## Class: CConsole%3AF6F98F00DC
//## Category: SceneObjects::Console%3AF6F98800F0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AF70E640398;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3AF70ED601FE;CMesh_Rect { -> }

class CConsole : public CHeadUpDisplay  //## Inherits: <unnamed>%3BD33ACA0056
{
  //## begin CConsole%3AF6F98F00DC.initialDeclarations preserve=yes
  //## end CConsole%3AF6F98F00DC.initialDeclarations

  public:
    //## Constructors (generated)
      CConsole();

    //## Destructor (generated)
      virtual ~CConsole();


    //## Other Operations (specified)
      //## Operation: Init%989264851
      void Init (float _Width, float _Height, int _Cols, int _Rows, CE3D_Shader* _BGMat, CE3D_Shader* _CMMat);

      //## Operation: Write%1014992648
      void Write (char* _szTex);

      //## Operation: WriteXY%989264852
      void WriteXY (int X, int Y, char *Text);

      //## Operation: Resize%989269072
      void Resize (float _Width, float _Height);

      //## Operation: SetChar%989269073
      void SetChar (int _X, int _Y, char _a);

      //## Operation: CreateCharMatrix%989269074
      void CreateCharMatrix ();

      //## Operation: SetCharMatrixMat%989269079
      void SetCharMatrixMat (CE3D_Shader *_CMMat);

      //## Operation: SetBackgroundMat%989269080
      void SetBackgroundMat (CE3D_Shader *_BGMat);

    // Additional Public Declarations
      //## begin CConsole%3AF6F98F00DC.public preserve=yes
      //## end CConsole%3AF6F98F00DC.public

  protected:
    // Additional Protected Declarations
      //## begin CConsole%3AF6F98F00DC.protected preserve=yes
      //## end CConsole%3AF6F98F00DC.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Width%3AF6F9FB0096
      //## begin CConsole::Width%3AF6F9FB0096.attr preserve=no  private: float {UA} 0
      float Width;
      //## end CConsole::Width%3AF6F9FB0096.attr

      //## Attribute: Height%3AF6FA09028A
      //## begin CConsole::Height%3AF6FA09028A.attr preserve=no  private: float {UA} 0
      float Height;
      //## end CConsole::Height%3AF6FA09028A.attr

      //## Attribute: Cols%3AF6FA0C01C2
      //## begin CConsole::Cols%3AF6FA0C01C2.attr preserve=no  private: int {UA} 0
      int Cols;
      //## end CConsole::Cols%3AF6FA0C01C2.attr

      //## Attribute: Rows%3AF6FA130028
      //## begin CConsole::Rows%3AF6FA130028.attr preserve=no  private: int {UA} 0
      int Rows;
      //## end CConsole::Rows%3AF6FA130028.attr

      //## Attribute: BackgroundMat%3AF6FA15026C
      //## begin CConsole::BackgroundMat%3AF6FA15026C.attr preserve=no  private: CE3D_Shader * {UA} NULL
      CE3D_Shader *BackgroundMat;
      //## end CConsole::BackgroundMat%3AF6FA15026C.attr

      //## Attribute: CharMatrixMat%3AF6FB42030C
      //## begin CConsole::CharMatrixMat%3AF6FB42030C.attr preserve=no  private: CE3D_Shader * {UA} NULL
      CE3D_Shader *CharMatrixMat;
      //## end CConsole::CharMatrixMat%3AF6FB42030C.attr

      //## Attribute: Background%3AF6FC6B021C
      //## begin CConsole::Background%3AF6FC6B021C.attr preserve=no  private: CObject3D_Leaf * {UA} NULL
      CObject3D_Leaf *Background;
      //## end CConsole::Background%3AF6FC6B021C.attr

      //## Attribute: CharMatrix%3AF6FC790258
      //## begin CConsole::CharMatrix%3AF6FC790258.attr preserve=no  private: CObject3D_Leaf * {UA} NULL
      CObject3D_Leaf *CharMatrix;
      //## end CConsole::CharMatrix%3AF6FC790258.attr

      //## Attribute: Data%3AF70BFA0208
      //## begin CConsole::Data%3AF70BFA0208.attr preserve=no  private: char * {UA} NULL
      char *Data;
      //## end CConsole::Data%3AF70BFA0208.attr

      //## Attribute: MatrixMesh%3AF711B90212
      //## begin CConsole::MatrixMesh%3AF711B90212.attr preserve=no  private: CMesh * {UA} NULL
      CMesh *MatrixMesh;
      //## end CConsole::MatrixMesh%3AF711B90212.attr

      //## Attribute: Color%3C2D1AD201F4
      //## begin CConsole::Color%3C2D1AD201F4.attr preserve=no  private: CVect4 {UA} 
      CVect4 Color;
      //## end CConsole::Color%3C2D1AD201F4.attr

    // Additional Private Declarations
      //## begin CConsole%3AF6F98F00DC.private preserve=yes
      //## end CConsole%3AF6F98F00DC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CConsole%3AF6F98F00DC.implementation preserve=yes
      //## end CConsole%3AF6F98F00DC.implementation

};

//## begin CConsole%3AF6F98F00DC.postscript preserve=yes
//## end CConsole%3AF6F98F00DC.postscript

// Class CConsole 

//## begin module%3AF6F98F00DC.epilog preserve=yes
//## end module%3AF6F98F00DC.epilog


#endif
