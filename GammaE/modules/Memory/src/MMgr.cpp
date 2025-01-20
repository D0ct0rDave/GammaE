#include <stdlib.h>
#include "MMgr.h"

void *MEMAlloc(size_t sz)
{
	return(malloc(sz));
}

void MEMFree (void *_P)
{
	free(_P);
}

