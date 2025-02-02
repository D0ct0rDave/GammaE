// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CLoopGlobalsH
#define CLoopGlobalsH
// ----------------------------------------------------------------------------
#include <windows.h>
#include "GammaE.h"
// ----------------------------------------------------------------------------
class CLoopGlobals
{
    public:
        CLoopGlobals();
        bool m_bFinnishApplication;

        CGChrono m_oChrono;
        CGViewport m_oViewport;
        CGProjector m_oPerspPrj;
        CGCamera m_oPerspCam;
};

extern CLoopGlobals loopGlobals;
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
