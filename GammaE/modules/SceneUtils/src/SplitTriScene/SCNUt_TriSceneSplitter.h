//	  %X% %Q% %Z% %W%



#ifndef SCNUt_TriSceneSplitter_h
#define SCNUt_TriSceneSplitter_h 1



// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_TriUtils
#include "ScnUtils\SCNUt_TriUtils.h"
// SCNUt_TriSceneClassifier
#include "SplitTriScene\SCNUt_TriSceneClassifier.h"





class SCNUt_TriSceneSplitter 
{
    
  public:
          SCNUt_TriSceneSplitter();

          ~SCNUt_TriSceneSplitter();


                void SplitScene (SCNUt_TriScene& _poScene, CPlane& _oPlane, int _iBackTris, int _iFrontTris);

            void ClassifyAndSplitScene (SCNUt_TriScene& _poScene, CPlane& _oPlane);

    // Data Members for Class Attributes

                  SCNUt_TriScene *poFrontScene;
      
                  SCNUt_TriScene *poBackScene;
      
    // Additional Public Declarations
            
  protected:

                void SplitIn3Triangles (SCNUt_Triangle &SrcTri, SCNUt_Triangle &A, SCNUt_Triangle &B, SCNUt_Triangle &C, CPlane &Plane);

            void SplitIn2Triangles (SCNUt_Triangle &SrcTri, SCNUt_Triangle &A, SCNUt_Triangle &B, CPlane &Plane);

            void GenerateTriangleFrom2Factors (SCNUt_Triangle &SrcTri, int iIsolVX, int ipA, int ipB, int ipC, float fFactor1, float fFactor2, SCNUt_Triangle &DstTri);

            void GenerateTriangleFromFactor (SCNUt_Triangle &SrcTri, int ipA, int ipB, int ipC, float fFactor, SCNUt_Triangle &DstTri);

            float GetSplitFactor (CVect3 &pA, CVect3 &pB, CPlane &Plane);

            void GetSplitVertexs (SCNUt_Triangle &SrcTri, int &C, int &A, int &B);

            void CheckWinding (SCNUt_Triangle& _oRefTri, SCNUt_Triangle& _oTri);

    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_TriSceneSplitter 



#endif
