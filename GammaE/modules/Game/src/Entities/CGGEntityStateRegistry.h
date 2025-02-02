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
// -----------------------------------------------------------------------------
/*! \class CGGEntityStateRegistry
 *  \brief A Registry to manage entity states and its counterpart humanreadable names
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGGEntityStateRegistryH
#define CGGEntityStateRegistryH
// -----------------------------------------------------------------------------

#include "GammaE_Misc.h"

// -----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGGEntityStateRegistry, public, CGLookupArray <uint> )
{
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
