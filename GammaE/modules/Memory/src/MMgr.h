#ifndef MMgrH
#define MMgrH

#include <stdlib.h>

void* operator new(size_t sz);
void operator delete(void * _P);

#define mDel delete
#define mNew new
#define mAlloc malloc
#define mFree  free

#endif MMgrH