/******************************************************************

STANDARD MEMORY MANAGER
by David Márquez de la Cruz

******************************************************************/

#include "MemMgr.h"

#ifndef NULL
#define NULL 0
#endif

// Define memory granularity: 
// 32 bytes aligned memory management
#define GRANDMASK	0x0000001f
#define MAXBLOCKS	48000

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#if defined(__NGC_COMPILATION__)
    #include <dolphin.h>
#else
	#define OSAlloc malloc
	#define OSFree	free
#endif

/******************************************************************
******************************************************************/

unsigned int	MEMMgr::uiTotalSize = 0;
unsigned int	MEMMgr::uiNumBlocks = 0;
TMEMBlock 		*MEMMgr::poMB       = NULL;
unsigned char 	*MEMMgr::pucData    = NULL;

/******************************************************************
******************************************************************/

// #define _DEBUG_MEM
#ifdef  _DEBUG_MEM
	#ifdef __NGC_COMPILATION__

		#define MAXCMDS (1024*1024)
		static unsigned int uiNumCmds = 2;
		static unsigned int uiCmds[MAXCMDS];

		#define CMD_FREE 	0x00000000
		#define CMD_ALLOC	0x80000000
		#define RECORDCOMMAND(Cmd,Value)\
			 uiCmds[ ((uiNumCmds++) % MAXCMDS) ] = (Cmd | (Value & 0x7fffffff));\
			 if (uiNumCmds == MAXCMDS) DumpMMGR();


		// #include "STRM_NgcUsb.h"
		#include "Tools/usb_io.h"
		#include "Tools/debug_assist.h"

		void DumpMMGR()
		{
			uiCmds[0] = MEMMgr::uiTotalSize;
			uiCmds[1] = uiNumCmds;

			ConnectToUSB();
			DA_SaveFileToPC(uiCmds,uiNumCmds*4,"MEMMGR.DAT");
		}
	#else
		#define RECORDCOMMAND(Cmd,Value)
		#define DumpMMGR()
	#endif		

#else
	#define RECORDCOMMAND(Cmd,Value)
	#define DumpMMGR()
#endif
/******************************************************************
******************************************************************/
#ifdef WIN32
	#define CHECKSORTING(a,b)
	/*
	void CHECKSORTING(TMEMBlock *poMB,unsigned int uiNumBlocks)
	{
		for (unsigned int cI=1;cI<uiNumBlocks;cI++)
		{
			if (poMB[cI-1].pucBuffer < poMB[cI].pucBuffer)
			{
				assert(0 && "STACK NOT SORTED!!!");
			}
		}
	}
	*/
#else
	#define CHECKSORTING(a,b)
#endif
/******************************************************************
******************************************************************/
MEMMgr::MEMMgr()
{
	poMB    = NULL;
	pucData = NULL;
	uiTotalSize = 0;
	uiNumBlocks = 0;
}

MEMMgr::~MEMMgr()
{
}
/******************************************************************
******************************************************************/
void MEMMgr::Init(unsigned int _uiTotalSize)
{
	if (poMB) return;

	uiTotalSize = _uiTotalSize;
	pucData     = (unsigned char*)OSAlloc(uiTotalSize);
	poMB        = (TMEMBlock    *)OSAlloc(MAXBLOCKS*sizeof(TMEMBlock) );

	assert(pucData && "MEMMgr: Unable to allocate space for Memory Manager");
	Reset();
}
/******************************************************************
******************************************************************/
void MEMMgr::Finish()
{	
	uiTotalSize = 0;
	poMB		= NULL;
	pucData		= NULL;

	OSFree(pucData);
	OSFree(poMB);
}
/******************************************************************
******************************************************************/
void *MEMMgr::Alloc(unsigned int _uiSize)
{
	RECORDCOMMAND(CMD_ALLOC,_uiSize);

	// First of all correct size depending on memory granularity
	_uiSize = (_uiSize + GRANDMASK) & ~GRANDMASK;

	// Look for free block
	unsigned int 		uiMinBlock = 0;
	unsigned int		uiMinSize  = uiTotalSize+1;
	unsigned int		uiFreeSize;
	unsigned int		uiBlock;
	TMEMBlock			*poFreeBlock = NULL;

	for (uiBlock=0;uiBlock<uiNumBlocks;uiBlock++)
	{
		if (poMB[uiBlock].eState == MBS_FREE)
		{
			if (poMB[uiBlock].uiSize >= _uiSize)
			{
				uiFreeSize = poMB[uiBlock].uiSize - _uiSize;
				if (! uiFreeSize)
				{
					// Substitute block and return
					poMB[uiBlock].eState = MBS_USED;
					return ( (void*)poMB[uiBlock].pucBuffer);
				}
				// Look for the best fit block
				else if (uiFreeSize < uiMinSize)
				{
					uiMinSize  = uiFreeSize;
					poFreeBlock= &poMB[uiBlock];
					uiMinBlock = uiBlock;
//					break;	// Uncomment for first fit
				}
			}
		}
	}
	
	uiBlock = uiMinBlock;

	// There were neither free block nor available memory in free blocks
	if (! poFreeBlock)
	{
		DumpMMGR();
		return(NULL);
	}
	// -----------------------------------------------
	// BEGIN: BLOCK SPLIT
	// -----------------------------------------------

		// <WARNING> Check block stack underflow
		// we can allocate space for a new stack entry
		if (uiNumBlocks+1 == MAXBLOCKS)
		{
			DumpMMGR();
			return(NULL);
		}

		// Setup block pointers
		TMEMBlock *poNewFreeBlock = poFreeBlock;		// Free blocks left to the begining of the stack
		TMEMBlock *poNewUsedBlock = poFreeBlock+1;

		unsigned int uiNewUsedBlock = uiBlock+1;
		
		if (uiNumBlocks>1)
		{
			for (uiBlock=uiNumBlocks;uiBlock>uiNewUsedBlock;uiBlock--)
				poMB[uiBlock] = poMB[uiBlock-1];
		}

		// Now we could setup free and used blocks
			
			// New occupied block:
			poNewUsedBlock->eState	 = MBS_USED;
			poNewUsedBlock->pucBuffer= poFreeBlock->pucBuffer;
			poNewUsedBlock->uiSize	 = _uiSize;

			// New free block
			poNewFreeBlock->eState    = MBS_FREE;
			poNewFreeBlock->pucBuffer = poFreeBlock->pucBuffer + _uiSize;
			poNewFreeBlock->uiSize    = poFreeBlock->uiSize - _uiSize;


		// We have now 1 block more	
		uiNumBlocks++;

		CHECKSORTING(poMB,uiNumBlocks);

	// -----------------------------------------------
	// END: BLOCK SPLIT
	// -----------------------------------------------	

	return((void*)poNewUsedBlock->pucBuffer);
}
/******************************************************************
******************************************************************/
void MEMMgr::Free(void *_pBuffer)
{	
	RECORDCOMMAND(CMD_FREE,((unsigned int)_pBuffer - (unsigned int)pucData));

	// Look for the Buffer to free up
	unsigned int uiBlock = uiFindPointer((unsigned char *)_pBuffer);
	
	assert ( (uiBlock<uiNumBlocks)  && "MEMMgr: Invalid pointer to free");
	assert ( (poMB[uiBlock].eState == MBS_USED) && "MEMMgr: Already freed pointer");

	// Mark this block as free
	poMB[uiBlock].eState    = MBS_FREE;

	// Look if we can join with the previous adjacent block
	if (uiBlock>0)
	{
		if (poMB[uiBlock-1].eState == MBS_FREE)
		{
			// Join the 2 adjacent blocks
			poMB[uiBlock-1].uiSize   += poMB[uiBlock].uiSize;
			poMB[uiBlock-1].pucBuffer = poMB[uiBlock].pucBuffer;

			unsigned int uiFirstBlock = uiBlock;
			for (uiBlock = uiFirstBlock;uiBlock<uiNumBlocks-1;uiBlock++)
				poMB[uiBlock] = poMB[uiBlock+1];			

			uiNumBlocks--;
			uiBlock = uiFirstBlock-1;
		}
	}

	// Look if we can join with the next adjacent block
	if (uiBlock < uiNumBlocks-1)
	{
		if (poMB[uiBlock+1].eState == MBS_FREE)
		{
			// Join the 2 adjacent blocks			
			poMB[uiBlock].uiSize   += poMB[uiBlock+1].uiSize;
			poMB[uiBlock].pucBuffer = poMB[uiBlock+1].pucBuffer;

			unsigned int uiFirstBlock = uiBlock+1;
			for (uiBlock = uiFirstBlock;uiBlock<uiNumBlocks-1;uiBlock++)
				poMB[uiBlock] = poMB[uiBlock+1];

			// Increase stack base pointer
			uiNumBlocks--;
		}
	}

	CHECKSORTING(poMB,uiNumBlocks);	

}
/******************************************************************
******************************************************************/
void MEMMgr::Reset()
{
	poMB[0].pucBuffer = pucData;
	poMB[0].eState    = MBS_FREE;
	poMB[0].uiSize    = uiTotalSize;

	uiNumBlocks = 1;
}
/******************************************************************
******************************************************************/
int iFindPointerRec(unsigned char *_pucBuff,TMEMBlock *poBlock,int _iStart, int _iEnd)
{
	// Dichotomycal search
	switch (_iEnd - _iStart)
	{
		case 0: if (poBlock[_iStart].pucBuffer == _pucBuff) 
					return(_iStart);
				else 
					return(-1);
		break;

		case 1: if (poBlock[_iStart].pucBuffer == _pucBuff) return(_iStart);
				if (poBlock[_iEnd  ].pucBuffer == _pucBuff) return(_iEnd );
				return(-1);
		break;

		default:
			int iMiddle = (_iEnd - _iStart) / 2 + _iStart;
			
			if (poBlock[iMiddle].pucBuffer == _pucBuff)
				return iMiddle;

			if (poBlock[iMiddle].pucBuffer > _pucBuff)			
				return (iFindPointerRec (_pucBuff, poBlock, iMiddle, _iEnd));

			else

				return (iFindPointerRec (_pucBuff, poBlock, _iStart, iMiddle));

		break;
	}
}

unsigned int MEMMgr::uiFindPointer(unsigned char *_pucBuff)
{
	/*
	int iRes = iFindPointerRec(_pucBuff,poMB,0,uiNumBlocks);
	if (iRes<0)
	{
		DumpMMGR();
		return(uiNumBlocks);
	}
	else
		return(iRes);
	*/
	
	// ------------------------------------------
	// Dichotomycal search
	// ------------------------------------------
	unsigned int	uiStart,uiEnd,uiMiddle;

	uiStart = 0;
	uiEnd   = uiNumBlocks;
	
	while (1)
	{			
		switch (uiEnd - uiStart)
		{
			case 0: if (poMB[uiStart].pucBuffer == _pucBuff) 
						return(uiStart);
					else 
						return(uiNumBlocks);
			break;

			case 1: if (poMB[uiStart].pucBuffer == _pucBuff) return(uiStart);
					if (poMB[uiEnd  ].pucBuffer == _pucBuff) return(uiEnd );
					return(uiNumBlocks);
			break;

			default:
				uiMiddle = (uiEnd - uiStart) / 2 + uiStart;
				
				if (poMB[uiMiddle].pucBuffer == _pucBuff)
					return uiMiddle;

				if (poMB[uiMiddle].pucBuffer > _pucBuff)
					uiStart = uiMiddle;
				else
					uiEnd   = uiMiddle;
			break;
		}
	}

	// We have not found the pointer
	return (uiNumBlocks);
}
/******************************************************************
******************************************************************/
void MEMMgr::FreeMemStats()
{	
	// Look for free block
	unsigned int 		uiTotalFreeMem = 0;
	unsigned int		uiMaxBlockSize = 0;
	unsigned int		uiNumFreeBlocks= 0;
	unsigned int		uiBlock;

	for (uiBlock=0;uiBlock<uiNumBlocks;uiBlock++)
	{
		if (poMB[uiBlock].eState == MBS_FREE)
		{
			uiNumFreeBlocks++;			
			if (poMB[uiBlock].uiSize >= uiMaxBlockSize) uiMaxBlockSize = poMB[uiBlock].uiSize;
			uiTotalFreeMem += poMB[uiBlock].uiSize;
		}
	}
}
/******************************************************************
******************************************************************/