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

#ifndef SCNUt_Triangle_h
#define SCNUt_Triangle_h 1

// GammaE_Math
#include "GammaE_Math.h"
// SCNUt_ePolyState
#include "SCNUt_ePolyState.h"

class SCNUt_Triangle
{
    public:
        SCNUt_Triangle();

        ~SCNUt_Triangle();

        // Data Members for Class Attributes

        // // XYZ coordinates
        CVect3 VXs[3];

        // // UV coordinates
        CVect2 UVs[3];

        // // VertexColor of the vertex (if any)
        CVect4 VCs[3];

        // // Vertex normals (if any)
        CVect3 VNs[3];

        int Material;

        SCNUt_ePolyState Side;

        SCNUt_ePolyState VertexSide[3];

        float DProds[3];

        unsigned int iFlags;

    protected:
    private:
    private:
};

// Class SCNUt_Triangle

#endif
