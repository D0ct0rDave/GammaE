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

#ifndef CCOL_Mesh_h
#define CCOL_Mesh_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// GammaE_Math
#include "GammaE_Math.h"

class CCOL_Mesh
{
    public:
        CCOL_Mesh();

        ~CCOL_Mesh();

        void Set(CGMesh* _poMesh, int _iMat, float _fFrameFact);

        // Data Members for Class Attributes

        CGMesh* poMesh;

        float fFrameFact;

        int iMat;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_Mesh

inline void CCOL_Mesh::Set (CGMesh* _poMesh, int _iMat, float _fFrameFact)
{
    poMesh = _poMesh;
    fFrameFact = _fFrameFact;
    iMat = _iMat;
}

#endif
