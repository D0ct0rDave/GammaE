#include "GMMgr.h"

#include "stdlib.h"
#include <assert.h>

void* operator new(size_t sz)
{
    if ( !sz ) return(NULL);
    void* pData = malloc(sz);

    assert(pData && "Unable to allocate data");
    // __FILE__, __LINE__
    return(pData);
}

void operator delete(void* _P)
{
    free(_P);
}
