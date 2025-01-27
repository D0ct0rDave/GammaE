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
#ifndef CGraphBV_FileIO_h
#define CGraphBV_FileIO_h 1
// -----------------------------------------------------------------------------
#include "GammaE_FileSys.h"
#include "GammaE_Math.h"
#include "GammaE_E3D.h"
// -----------------------------------------------------------------------------
class CGraphBV_FileIO
{
    public:
        static CGGraphBV* pLoadGraphBV(CGFile& _oFile);
        static int iSaveGraphBV(CGFile& _oFile, CGGraphBV* _pGBV);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
