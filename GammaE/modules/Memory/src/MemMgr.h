// ----------------------------------------------------------------------
#ifndef MemMgrH
#define MemMgrH
// ----------------------------------------------------------------------



typedef enum{
	MBS_FREE,
	MBS_USED,
	MBS_INVALID,
	MBS_NUM,
}TMEMBlockState;


typedef struct{
	TMEMBlockState		eState;
	unsigned int		uiSize;
	unsigned char		*pucBuffer;
}TMEMBlock;



class MEMMgr
{
	public:			MEMMgr();
					~MEMMgr();
	
					static void Init  (unsigned int _uiTotalSize);
					static void Free  (void *_pBuffer);
					static void *Alloc(unsigned int _uiSize);
					static void Reset();
					static void Finish();					

	public:			static unsigned int		uiTotalSize;
					static unsigned int		uiNumBlocks;
					static TMEMBlock 		*poMB;
					static unsigned char 	*pucData;

					static unsigned int		uiFindPointer(unsigned char *_pucBuff);
					static void FreeMemStats();
};

// ----------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------
