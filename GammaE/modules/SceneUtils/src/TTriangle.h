//	  %X% %Q% %Z% %W%



#ifndef TTriangle_h
#define TTriangle_h 1



// GammaE_Math
#include "GammaE_Math.h"
enum ePolyState
{
	POLYSTATE_NONE		= 0,
	POLYSTATE_FRONT		= 1,			// Polygon frontside the plane
	POLYSTATE_BACK		= 2,			// Polygon backside the plane
	POLYSTATE_OVER		= 3,			// Polygon over the plane
	POLYSTATE_ONEOVER	= 4,			// 1 vertex over the plane  (tris)
	POLYSTATE_TWOOVER	= 5,			// 2 vertexs over the plane (tris)
	POLYSTATE_CROSS1	= 6,			// The polygon crosses the plane
	POLYSTATE_CROSS2	= 7,			// The polygon crosses the plane
};




class TTriangle 
{
  public:
          TTriangle();

          ~TTriangle();

    // Data Members for Class Attributes

            //	// XYZ coordinates
            CVect3 VXs[3];
      
            //	// UV coordinates
            CVect2 UVs[3];
      
            //	// VertexColor of the vertex (if any)
            CVect4 VCs[3];
      
            //	// Vertex normals (if any)
            CVect3 VNs[3];
      
                  int Material;
      
            //	// Side of the triangle respect the plane
            ePolyState Side;
      
            //	// Side of this vertex respect the plane
            ePolyState VertexSide[3];
      
            //	// Dot product of the vertex and the plane
            float DProds[3];
      
  protected:
  private:
  private: };

// Class TTriangle 



#endif
