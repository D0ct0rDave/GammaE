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

#ifndef CGraphBV_FileIO_h
#define CGraphBV_FileIO_h 1

#include <stdio.h>

// GammaE_FileSys
#include "GammaE_FileSys.h"
// CGBVSphere
#include "BoundingVolume\GraphBoundVol\CGBVSphere.h"
// CGraphBV_Point
#include "BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
// CGraphBV_Cylinder
#include "BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
// CGBVAABB
#include "BoundingVolume\GraphBoundVol\CGBVAABB.h"

class CGraphBV_FileIO
{
    public:
        CGraphBV_FileIO();

        ~CGraphBV_FileIO();

        static CGBoundingVolume* pLoadGraphBV(CFile& _oFile);

        static int iSaveGraphBV(CFile& _oFile, CGBoundingVolume* _pGBV);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGraphBV_FileIO

#endif