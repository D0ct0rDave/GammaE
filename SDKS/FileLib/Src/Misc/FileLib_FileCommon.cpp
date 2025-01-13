#include <stdio.h>
#include "FileLib_FileCommon.h"

unsigned int uiBlockLenPos[256];
unsigned int uiBLIdx = -1;

void FILE_BeginRIFFBlock(unsigned int uiRIFFId,FILE *fd)
{
	if ( uiBLIdx == 255) return;	
	
	uiBLIdx++;
	
	// Write RIFF identifier
	fwrite(&uiRIFFId,4,1,fd);	
	
	uiBlockLenPos[uiBLIdx] = ftell(fd);

	// Write invalid RIFF BlockLenght
	fwrite(&uiBlockLenPos[uiBLIdx],4,1,fd);
}

void FILE_EndRIFFBlock(FILE *fd)
{
	unsigned int uiBlockLenght = ftell(fd) - (uiBlockLenPos[uiBLIdx]+4);
	
	// set file position pointing to RIFF BlockLenght
	fseek(fd,uiBlockLenPos[uiBLIdx],SEEK_SET);

	// write BlockLenght
	fwrite(&uiBlockLenght,4,1,fd);
	
	// skip RIFF block data
	fseek(fd,uiBlockLenght,SEEK_CUR);

	uiBLIdx--;
}