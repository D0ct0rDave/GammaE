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

#ifndef SCNUt_AdjTriList_h
#define SCNUt_AdjTriList_h 1

// SCNUt_AdjTri
#include "ScnStripifier\SCNUt_AdjTri.h"

class SCNUt_AdjTriList
{
    public:
        SCNUt_AdjTriList();

        ~SCNUt_AdjTriList();

        void Init(int _iNumTris);

        // Data Members for Class Attributes

        int iNumTris;

        // Data Members for Associations

        SCNUt_AdjTri* Tri;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_AdjTriList

#endif
