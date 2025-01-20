#include <stdlib.h>
#include "MMgr.h"

#ifdef _DEBUG
#ifdef _MBCS

#ifndef __BORLANDC__
//#define MEMWATCH
//#include "memwatch.h"
#endif

#endif
#endif

void *MEMAlloc(size_t sz)
{
	#ifdef _DEBUG
		// if (! MEMMgr::poMB) MEMMgr::Init(64*1024*1024);

		void *pData;			
		static void *pDataCmp = NULL;

		if (! MEMMgr::poMB)
			pData = malloc(sz);
		else
			pData = MEMMgr::Alloc(sz);

		if (pData == pDataCmp)
		{
			int a=0;
		}

		return(pData);
	#else
		if (! MEMMgr::poMB)
			return(malloc(sz));
		else
			return(MEMMgr::Alloc(sz));
	#endif
}

void MEMFree (void *_P)
{
	#ifdef _DEBUG
		static void *pDataCmp = NULL;
		if (! MEMMgr::poMB)
		{			
			if (_P == pDataCmp)
			{
				int a=0;
			}

			free(_P);
		}
		else
			MEMMgr::Free(_P);
	#else		
		if (! MEMMgr::poMB)
			free(_P);
		else
			MEMMgr::Free(_P);
	#endif

}

