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
#ifndef MMgrH
#define MMgrH
// ----------------------------------------------------------------------------
#include <stdlib.h>

void* operator new(size_t sz);
void operator delete(void* _P);

#define mDel delete
#define mNew new
#define MEMAlloc malloc
#define MEMFree free

// ----------------------------------------------------------------------------
#endif // MMgrH
// ----------------------------------------------------------------------------
