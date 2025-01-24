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
#ifndef CGVect2H
#define CGVect2H
// ----------------------------------------------------------------------------
#pragma warning (disable:4005)
#include "GammaE_Misc.h"
#include "Other\GMathCommon.h" // This include must be here instead of in CGVector.h
// ----------------------------------------------------------------------------

#undef HAS_Z
#undef HAS_W
#define CGVECTOR CGVect2
#include "CGVector.h"
// typedef CGVECTOR CGVect2;
#undef  CGVECTOR
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
