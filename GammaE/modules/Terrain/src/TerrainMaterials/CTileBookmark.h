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

#ifndef CTileBookmark_h
#define CTileBookmark_h 1

// GammaE_E3D
#include "GammaE_E3D.h"

class CTileBookmark
{
    public:
        CTileBookmark();

        ~CTileBookmark();

        void Init(int _MaxTiles, int _MaxLODs);

        void SetTileMaterial(int _iTile, int _iLOD, CE3D_Shader* _Mat);

        CE3D_Shader* poGetTileMaterial(int _iTile, int _iLOD);

        int GetTileLODs(int _iTile);

        void Invalidate();

        int GetMaxTiles();

        int GetMaxLODs();

        // Data Members for Class Attributes

        CE3D_Shader* * Tiles;

        int MaxTiles;

        int MaxLODs;

        int* TileLODs;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class CTileBookmark

inline int CTileBookmark::GetMaxTiles ()
{
    return(MaxTiles);
}

inline int CTileBookmark::GetMaxLODs ()
{
    return(MaxLODs);
}

#endif
