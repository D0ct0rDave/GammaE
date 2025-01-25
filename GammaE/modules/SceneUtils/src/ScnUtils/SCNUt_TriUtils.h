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

#ifndef SCNUt_TriUtils_h
#define SCNUt_TriUtils_h 1

// SCNUt_Triangle
#include "SCNUt_Triangle.h"

class SCNUt_TriUtils
{
    public:
        SCNUt_TriUtils();

        ~SCNUt_TriUtils();

        static void MinimizeMappingOffset(SCNUt_Triangle& _oTri);

        static void ChangeWinding(SCNUt_Triangle& _oTri);

        static void GetQ2UVCoords(CGVect3& _oPnt, CGVect3& _oXAxis, CGVect3& _oYAxis, float _fUOfs, float _fVOfs, float _fUScl, float _fVScl, float* _pfU, float* _pfV);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_TriUtils

#endif
