// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "CGViewport.h"
// ----------------------------------------------------------------------------
CGViewport::CGViewport()
    : ScrCX(0), ScrCY(0), ScrTX(0), ScrTY(0)
{
}
// ----------------------------------------------------------------------------
CGViewport::~CGViewport()
{
}
// ----------------------------------------------------------------------------
void CGViewport::SetViewport (float cX, float cY, float TX, float TY)
{
    ScrCX = cX;
    ScrCY = cY;
    ScrTX = TX;
    ScrTY = TY;
}
// ----------------------------------------------------------------------------
