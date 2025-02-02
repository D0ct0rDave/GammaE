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

#ifndef SCNUt_AdjTri_h
#define SCNUt_AdjTri_h 1

class SCNUt_AdjTri
{
    public:
        SCNUt_AdjTri();

        ~SCNUt_AdjTri();

        void AddNeigh(int _iIdx);

        // Data Members for Class Attributes

        int iNumNeighs;

        int* Neigh;

        bool Visited;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_AdjTri

#endif
