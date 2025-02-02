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

#ifndef CLODSelector_Array_h
#define CLODSelector_Array_h 1

// CLODSelector
#include "TerrainMath\CLODSelector.h"

class CLODSelector_Array : public CLODSelector
{
    public:
        CLODSelector_Array();

        virtual ~CLODSelector_Array();

        virtual float GetLOD(float fDist);

        void AddLOD(float fLODDist);

        void Init(int _MaxLODs);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        float* LODArray;

        int iMaxLODs;

        int iNumLODs;

        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CLODSelector_Array

#endif
