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
#ifndef CGVect3H
#define CGVect3H
// ----------------------------------------------------------------------------
#pragma warning (disable:4005)
#include "GammaE_Misc.h"
#include "Other\GMathCommon.h" // This include must be here instead of in CGVector.h
// ----------------------------------------------------------------------------

#define HAS_Z
#undef HAS_W
#define CGVECTOR CGVect3
#include "CGVector.h"
// typedef CGVECTOR CGVect3;
#undef  CGVECTOR
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
