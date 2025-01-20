#ifndef MMgrH
#define MMgrH

#include <stdlib.h>
#include <assert.h>
#include "MemMgr.h"

void *MEMAlloc(size_t sz);
void  MEMFree (void *_P);

inline void* operator new(size_t sz)
{
	if (! sz) return(NULL);

	void *pData = MEMAlloc(sz);

	assert(pData && "Unable to allocate data");
	// __FILE__, __LINE__
	return(pData);	
}

inline void  operator delete(void * _P)
{
	assert ( _P && "Attempting to erase a NULL pointer");
	MEMFree(_P);
}

#define mDel delete
#define mNew new
#define mAlloc MEMAlloc
#define mFree  MEMFree

#endif MMgrH
