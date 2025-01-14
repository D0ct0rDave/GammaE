//---------------------------------------------------------------------------
#ifndef DummyInfoFileH
#define DummyInfoFileH
//---------------------------------------------------------------------------
#define DIF_FILEIDENTIFIER  MAKE_RIFF_ID('D','I','N','F')

#define DIF_MAJORVERSION    1
#define DIF_MINORVERSION    0
//---------------------------------------------------------------------------
#include "CDummyTypes.h"
//---------------------------------------------------------------------------
int iDummyInfoFile_Save(char *_szFilename,CDummyTypes *_poDTypes);
int iDummyInfoFile_Load(char *_szFilename,CDummyTypes *_poDTypes);
//---------------------------------------------------------------------------
#endif
