//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//-----------------------------------------------------------------------------
#include "TexSet.h"

#include "Gammae_FileSys.h"
//-----------------------------------------------------------------------------
TTexSet::TTexSet()
{
    unsigned int cTex;

    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
    {
        // Initialize each element of the texture list
        TextureArray[cTex].Used = false;
	}

    strcpy(Name,TEXSET_DEFAULT_TEXSET_NAME);
}
//-----------------------------------------------------------------------------
TTexSet::~TTexSet()
{
    Invalidate();
}
//-----------------------------------------------------------------------------
void TTexSet::Invalidate()
{
    unsigned int cTex;
    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used)
		{            
			TextureArray[cTex].Used = false;
		}
}
//-----------------------------------------------------------------------------
char *TTexSet::GetTextureName(unsigned int TexID)
{
    return(TextureArray[TexID].Filename);
}
//-----------------------------------------------------------------------------
int TTexSet::LoadTexture(char *Filename,unsigned int MipMapID)
{
	if (!  Filename) return(0);
    if (! *Filename) return(0);

    TextureArray[MipMapID].m_poTex = CMipMapWH::I()->poLoad(Filename);

    if (TextureArray[MipMapID].m_poTex == NULL)
    {
		char StrBuff[MAX_CARS];    
        sprintf(StrBuff,"File not found or error while loading file %s",Filename);
        CGSystemLC::I()->Error("TEXSET0001",StrBuff);

        return(RES_OP_ERROR);
}

    // Copy the texture name
    strncpy((char *)TextureArray[MipMapID].Filename,Filename,MAX_CARS-1);
    TextureArray[MipMapID].Filename[MAX_CARS-1] = 0;

    TextureArray[MipMapID].Used = true;

    return(RES_OP_OK);
}
//-----------------------------------------------------------------------------
CGMipMap *TTexSet::GetMipMap(unsigned int MipMapID)
{
    if (MipMapID>=TEXSET_MAX_TEXTURES)
    {
        CGSystemLC::I()->Error("TEXSET0002","Bad MipMap identifier.");
        return(RES_OP_ERROR);
}
    else
    if (TextureArray[MipMapID].Used == false)
    {
        CGSystemLC::I()->Error("TEXSET0003","Empty mipmap.");
        return(RES_OP_ERROR);
}

    return(TextureArray[MipMapID].m_poTex);
}
//-----------------------------------------------------------------------------
int TTexSet::SetMipMap(unsigned int MipMapID,CGMipMap *MipMap)
{
    if (MipMapID>=TEXSET_MAX_TEXTURES)
    {
        CGSystemLC::I()->Error("TEXSET0004","Bad MipMap identifier.");
        return(RES_OP_ERROR);
}

    TextureArray[MipMapID].m_poTex = MipMap;
    TextureArray[MipMapID].Used = true;
    TextureArray[MipMapID].Filename[0] = 0;
    return(RES_OP_OK);
}
//-----------------------------------------------------------------------------
unsigned int TTexSet::GetMaxMipMaps()
{
    unsigned int cTex,LastTex;

    LastTex = 0;
    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used) LastTex = cTex;

    return(LastTex+1);
}
//-----------------------------------------------------------------------------
unsigned int TTexSet::GetNumMipMaps()
{
    unsigned int cTex,NumTexs;

    NumTexs = 0;
    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used) NumTexs++;

    return(NumTexs);
}
//-----------------------------------------------------------------------------
unsigned char TTexSet::GetMaxLODS()
{
    unsigned int uiMaxLODS = 0;
    unsigned int cTex;

    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used)
        {
            if (TextureArray[cTex].m_poTex->m_uiNumLODs > uiMaxLODS)
                uiMaxLODS = TextureArray[cTex].m_poTex->m_uiNumLODs;
}
        
    return(uiMaxLODS);
}
//-----------------------------------------------------------------------------
int TTexSet::Load(char *Filename)
{
    FILE *fd;
    unsigned long ulID;
    unsigned long ulBlockLength;
    unsigned int  uiRes;

    if (! Filename)
    {
        CGSystemLC::I()->Error("TEXSET-LD00","Null texset filename.");
        return(RES_OP_ERROR);
}

    fd = fopen(Filename,"rb");

    if (! fd)
    {
        CGSystemLC::I()->Error("TEXSET-LD00","Unable to open TexSet",Filename);
        return(RES_OP_ERROR);
}

    // Read object identifier
    if (! fread(&ulID,4,1,fd))
    {
        CGSystemLC::I()->Error("TEXSET-LD01","Cannot read TexSet from file");
        return(RES_OP_ERROR);
}

    if (ulID != TEXSET_OBJ_IDENTIFIER)
    {
        CGSystemLC::I()->Error("TEXSET-LD02","Bad TexSet identifier.");
        return(RES_OP_ERROR);
}

    // Read block length
    if (! fread(&ulBlockLength,4,1,fd))
    {
        CGSystemLC::I()->Error("TEXSET-LD03","Cannot read TexSet from file");
        return(RES_OP_ERROR);
}

    // Read texset data
    uiRes = LoadWithHandler(fd);

    fclose(fd);

    return(uiRes);
}
//-----------------------------------------------------------------------------
int TTexSet::Save(char *Filename)
{
    FILE *fd;
    int Res;

    fd = fopen(Filename,"wb");

    if (! fd)
    {
        CGSystemLC::I()->Error("TEXSET-SV01","Unable to save TexSet file",Filename);
        return(RES_OP_ERROR);
}

    Res = SaveWithHandler(fd);

    fclose(fd);
    return(Res);
}
//-----------------------------------------------------------------------------
int TTexSet::LoadWithHandler(FILE *fd)
{
	return(0);
}
//-----------------------------------------------------------------------------
int TTexSet::SaveWithHandler(FILE *fd)
{
	return(0);
}
//-----------------------------------------------------------------------------
int TTexSet::LoadTexSetList(char *Filename)
{
/*
    FILE *fd;
    unsigned int cTex;
    char StrBuff[MAX_CARS];
    unsigned int uiMaxMipMaps;
    unsigned int uiNumMipMaps;
    unsigned int uiMipMapNum;
    unsigned int uiLODS;
    MipMap   MipMap;

    if (! Filename)
    {
        CGSystemLC::I()->Error("TEXSET-LD00","No texset list filename provided.");
        return(RES_OP_ERROR);
}

    // Invalidate the texture set and prepare for mipmap loading
    InitializeMipMap(&MipMap);
    Invalidate();

    fd = fopen(Filename,"rt");
    if (! fd)
    {
        CGSystemLC::I()->Error("TEXSET-LDL00","Unable to load TexSet list file",Filename);
        return(RES_OP_ERROR);
}

    // Get TexList identifier
    fgets(StrBuff,MAX_CARS,fd);
    if (strcmp("TEXLIST",StrBuff))
    {
        fclose(fd);
        CGSystemLC::I()->Error("TEXSET-LDL00","Bad TexSet list identifier.");
        return(RES_OP_ERROR);
}

    // Get the maximum number of textures
    fscanf(fd,"%d",uiMaxMipMaps);

    // Get the maximum number of mipmap LODS
    fscanf(fd,"%d",uiLODS);

    // Get the number of mipmaps
    fscanf(fd,"%d",uiNumMipMaps);

    for (cTex=0;cTex<uiNumMipMaps;cTex++)
    {
        // Get the tile number
        fscanf(fd,"%d %s",uiMipMapNum,StrBuff);

        if (uiMipMapNum<TEXSET_MAX_TEXTURES)
        {
            if (! LoadMipMap(&MipMap,StrBuff))
            {
                fclose(fd);
                CGSystemLC::I()->Error("TEXSET-LDL12","Error loading mipmap");
                return(RES_OP_ERROR);
}
            else
            {
                // Set the current mipmap
                SetMipMap(uiMipMapNum,&MipMap);
}

            if (TextureArray[cTex].Used)
                fprintf(fd,"%d %s\r\n",cTex,TextureArray[cTex].Filename);
}
}

    DeallocateMipMap(&MipMap);
    fclose(fd);
*/
    return (RES_OP_OK);
}
//-----------------------------------------------------------------------------
int TTexSet::SaveTexSetList(char *Filename)
{
/*
    FILE *fd;
    unsigned int cTex;

    fd = fopen(Filename,"wt");

    fprintf(fd,"TEXLIST\r\n");
    fprintf(fd,"%d\r\n",TEXSET_MAX_TEXTURES);
    fprintf(fd,"%d\r\n",GetMaxLODS());
    fprintf(fd,"%d\r\n",GetNumMipMaps());

    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used)
            fprintf(fd,"%d %s\r\n",cTex,TextureArray[cTex].Filename);

    fclose(fd);
*/    
    return (RES_OP_OK);
}
//-----------------------------------------------------------------------------
