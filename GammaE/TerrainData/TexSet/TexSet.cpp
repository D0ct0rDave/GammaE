//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------
#include "tex.h"
#include "TexSet.h"
#include "File.h"
#include <assert.h>

//---------------------------------------------------------------------------
#define     MIPMAP_OBJ_IDENTIFIER   MAKE_RIFF_ID('M','I','P','M')
//---------------------------------------------------------------------------
TTexSet::TTexSet()
{
    unsigned int cTex;

    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
    {
        // Initialize each element of the texture list
        TextureArray[cTex].Used = false;
        TextureArray[cTex].tex = NULL;
        TextureArray[cTex].Filename[0] = 0;
    }

    strcpy(Name,TEXSET_DEFAULT_TEXSET_NAME);                         
}
//---------------------------------------------------------------------------
TTexSet::~TTexSet()
{
    Invalidate();
}
//---------------------------------------------------------------------------
void TTexSet::Invalidate()
{
    unsigned int cTex;
    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used)
        {
            DestroyMipMap(TextureArray[cTex].tex);
        }
}
//---------------------------------------------------------------------------
char *TTexSet::GetTextureName(unsigned int TexID)
{
    return(TextureArray[TexID].Filename);
}
//---------------------------------------------------------------------------
int TTexSet::LoadTexture(char *Filename,unsigned int MipMapID)
{
	if (!  Filename) return(0);
    if (! *Filename) return(0);

    char StrBuff[MAX_CARS];
    MipMap* mipmap = poLoadTextureAsMipmap(Filename);

    if (mipmap == NULL)
    {
        sprintf(StrBuff,"File not found or error while loading file %s",Filename);
        ERROR_SetError("TEXSET0001",StrBuff);
        return(RES_OP_ERROR);
    }

    // Copy the texture name
    strncpy((char *)TextureArray[MipMapID].Filename,Filename,MAX_CARS-1);
    TextureArray[MipMapID].Filename[MAX_CARS-1] = 0;
    TextureArray[MipMapID].Used = true;
    TextureArray[MipMapID].tex = mipmap;

    return(RES_OP_OK);
}
//---------------------------------------------------------------------------
MipMap* TTexSet::GetMipMap(unsigned int MipMapID)
{
    if (MipMapID>=TEXSET_MAX_TEXTURES)
    {
        ERROR_SetError("TEXSET0002","Bad MipMap identifier.");
        return(RES_OP_ERROR);
    }
    else
    if (TextureArray[MipMapID].Used == false)
    {
        ERROR_SetError("TEXSET0003","Empty mipmap.");
        return(RES_OP_ERROR);
    }

    return(TextureArray[MipMapID].tex);
}
//---------------------------------------------------------------------------
int TTexSet::SetMipMap(unsigned int MipMapID,MipMap * mipMap)
{
    if (MipMapID>=TEXSET_MAX_TEXTURES)
    {
        ERROR_SetError("TEXSET0004","Bad MipMap identifier.");
        return(RES_OP_ERROR);
    }

    TextureArray[MipMapID].Used = true;
    TextureArray[MipMapID].Filename[0] = 0;
    TextureArray[MipMapID].tex = mipMap;

    return(RES_OP_OK);
}
//---------------------------------------------------------------------------
Texture* TTexSet::GetMipMapLOD(unsigned int TexID,unsigned int LOD)
{
    // Returns the most detailed LOD in the mipmap identified with TexID
    if (TexID>=TEXSET_MAX_TEXTURES)
    {
        ERROR_SetError("TEXSET0005","Bad texture identifier.");
        return(RES_OP_ERROR);
    }

    if (TextureArray[TexID].Used == false)
    {
        ERROR_SetError("TEXSET0006","Empty texture.");
        return(RES_OP_ERROR);
    }

     if (LOD >= TextureArray[TexID].tex->lods.size())
     {
        ERROR_SetError("TEXSET0007","Invalid LOD Mipmap");
        return(RES_OP_ERROR);
     }

     return( TextureArray[TexID].tex->lods[LOD] );
}
//---------------------------------------------------------------------------
Texture *TTexSet::GetTexture(unsigned int TexID)
{
    // Returns the most detailed LOD in the mipmap identified with TexID
    return( GetMipMapLOD(TexID,0) );
}
//---------------------------------------------------------------------------
int TTexSet::SetTexture(unsigned int TexID,Texture *Tex)
{
    if (TexID>=TEXSET_MAX_TEXTURES)
    {
        ERROR_SetError("TEXSET0007","Bad texture identifier.");
        return(RES_OP_ERROR);
    }

    MipMap* mipmap = poCreateMipMapFromTexture(Tex);
    if (mipmap  == NULL)
    {
        ERROR_SetError("TEXSET0008","Couldn't create texture mipmap.");
        return(RES_OP_ERROR);
    }

    TextureArray[TexID].Used = true;
    TextureArray[TexID].Filename[0] = 0;
    TextureArray[TexID].tex = mipmap;

    return(RES_OP_OK);
}
//---------------------------------------------------------------------------
unsigned int TTexSet::GetMaxMipMaps()
{
    unsigned int cTex,LastTex;

    LastTex = 0;
    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used) LastTex = cTex;

    return(LastTex+1);
}
//---------------------------------------------------------------------------
unsigned int TTexSet::GetNumMipMaps()
{
    unsigned int cTex,NumTexs;

    NumTexs = 0;
    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used) NumTexs++;

    return(NumTexs);
}
//---------------------------------------------------------------------------
unsigned char TTexSet::GetMaxLODS()
{
    unsigned int uiMaxLODS = 0;
    unsigned int cTex;

    for (cTex=0;cTex<TEXSET_MAX_TEXTURES;cTex++)
        if (TextureArray[cTex].Used)
        {
            if (TextureArray[cTex].tex->lods.size() > uiMaxLODS)
                uiMaxLODS = TextureArray[cTex].tex->lods.size();
        }
        
    return(uiMaxLODS);
}
//---------------------------------------------------------------------------
int TTexSet::Load(char *Filename)
{
    FILE *fd;
    unsigned long ulID;
    unsigned long ulBlockLength;
    unsigned int  uiRes;

    if (! Filename)
    {
        ERROR_SetError("TEXSET-LD00","Null texset filename.");
        return(RES_OP_ERROR);
    }

    fd = fopen(Filename,"rb");

    if (! fd)
    {
        ERROR_SetError("TEXSET-LD00","Unable to open TexSet",Filename);
        return(RES_OP_ERROR);
    }

    // Read object identifier
    if (! fread(&ulID,4,1,fd))
    {
        ERROR_SetError("TEXSET-LD01","Cannot read TexSet from file");
        return(RES_OP_ERROR);
    }

    if (ulID != TEXSET_OBJ_IDENTIFIER)
    {
        ERROR_SetError("TEXSET-LD02","Bad TexSet identifier.");
        return(RES_OP_ERROR);
    }

    // Read block length
    if (! fread(&ulBlockLength,4,1,fd))
    {
        ERROR_SetError("TEXSET-LD03","Cannot read TexSet from file");
        return(RES_OP_ERROR);
    }

    // Read texset data
    uiRes = LoadWithHandler(fd);

    fclose(fd);

    return(uiRes);
}
//---------------------------------------------------------------------------
int TTexSet::Save(char *Filename)
{
    FILE *fd;
    int Res;

    fd = fopen(Filename,"wb");

    if (! fd)
    {
        ERROR_SetError("TEXSET-SV01","Unable to save TexSet file",Filename);
        return(RES_OP_ERROR);
    }

    Res = SaveWithHandler(fd);

    fclose(fd);
    return(Res);
}
//---------------------------------------------------------------------------
int TTexSet::LoadWithHandler(FILE *fd)
{
    unsigned int   cI,cJ;
    unsigned int   BlockLenght;

    unsigned long  ulID;
    unsigned char  ucMajorVersion;
    unsigned char  ucMinorVersion;
    unsigned short usNumMipMaps;
    unsigned short usMaxMipMaps;
    unsigned char  ucMaxLODS;
    unsigned long  BlockLenghtFilePos;
    unsigned short cTex,usTexNum;

    unsigned long  ulRIFF_BlockLength,ulRIFF_ObjectID;

    int            iRes = RES_OP_OK;

    // Invalidate the texture set and prepare for mipmap loading
    Invalidate();

    // Read object version
    fread(&ucMajorVersion,1,1,fd);
    fread(&ucMinorVersion,1,1,fd);

    if ((ucMajorVersion > TEXSET_MAJOR_VERSION) || ((ucMajorVersion == TEXSET_MAJOR_VERSION) && (ucMinorVersion > TEXSET_MAJOR_VERSION)) )
    {
        ERROR_SetError("TEXSET-LD10","Incorrect TexSet version number.");
        return(RES_OP_ERROR);
    }

    // Read object name
    fread(&Name,MAX_CARS_TEXSET_NAME,1,fd); Name[MAX_CARS_TEXSET_NAME-1] = 0;

    fread(&usMaxMipMaps,2,1,fd);
    fread(&ucMaxLODS   ,1,1,fd);
    fread(&usNumMipMaps,2,1,fd);

    if (usNumMipMaps > TEXSET_MAX_TEXTURES)
    {
        usNumMipMaps = TEXSET_MAX_TEXTURES;
        ERROR_SetError("WARNING TEXSET-LD11","Number of mipmaps truncated.");
        iRes = RES_OP_WARNING;
    }

    // Read mipmap data
    for (cTex=0;cTex<usNumMipMaps;cTex++)
    {
        // Read mipmap number
        fread(&usTexNum,2,1,fd);

        if (usTexNum<TEXSET_MAX_TEXTURES)
        {
            // Read RIFF header
            fread(&ulRIFF_ObjectID   ,4,1,fd);
            fread(&ulRIFF_BlockLength,4,1,fd);

            if (ulRIFF_ObjectID == MIPMAP_OBJ_IDENTIFIER)
            {
                // Read mipmap
                MipMap* mipmap = poLoadMipMap(fd);

                if (mipmap == NULL)
                {
                    ERROR_SetError("TEXSET-LD12","Error loading mipmap");
                    return(RES_OP_ERROR);
                }
                else
                {
                    // Set the current mipmap
                    SetMipMap(usTexNum, mipmap);
                }
            }
            else
            {
                // Skip block
                fseek(fd,ulRIFF_BlockLength,SEEK_CUR);
            }
        }
        else
        {
            ERROR_SetError("WARNING TEXSET-LD13","Unable to load mipmap");
            iRes = RES_OP_WARNING;
        }
    }

    return (iRes);
}
//---------------------------------------------------------------------------
int TTexSet::SaveWithHandler(FILE *fd)
{
    unsigned int cI,cJ;
    unsigned int BlockLenght;

    unsigned long  ulID           = TEXSET_OBJ_IDENTIFIER;
    unsigned char  ucMajorVersion = TEXSET_MAJOR_VERSION;
    unsigned char  ucMinorVersion = TEXSET_MINOR_VERSION;
    unsigned int   usNumMipMaps   = GetNumMipMaps();
    unsigned int   usMaxMipMaps   = TEXSET_MAX_TEXTURES;
    unsigned char  ucMaxLODS      = GetMaxLODS();
    unsigned long  ulMipMapDataSize,ulBlockLenghtFilePos;
    unsigned short cTex;

    // Write identifier
    fwrite(&ulID,4,1,fd);

    // Write block length
    ulBlockLenghtFilePos = ftell(fd);     // To be object size modified
    fwrite(&BlockLenght,4,1,fd);

    // Write object version
    fwrite(&ucMajorVersion,1,1,fd);
    fwrite(&ucMinorVersion,1,1,fd);

    // Write header
    fwrite(&Name,MAX_CARS_TEXSET_NAME,1,fd);

    fwrite(&usMaxMipMaps,2,1,fd);
    fwrite(&ucMaxLODS   ,1,1,fd);
    fwrite(&usNumMipMaps,2,1,fd);

    // Write mipmap data
    for (cTex=0;cTex<usMaxMipMaps;cTex++)
    {
        if (TextureArray[cTex].Used)
        {
            // write mipmap number
            fwrite(&cTex,2,1,fd);

            // write mipmap
            assert(false, "Trying to save mipmap !!");
            
            /*
            if (! SaveMipMapWithHandler(&TextureArray[cTex].tex,fd))
            {
                ERROR_SetError("TEXSET-SV10",TEX_fn_ErrorDescription());
                return(RES_OP_ERROR);
            }
            */
        }
    }
    ulMipMapDataSize = ftell(fd) - (ulBlockLenghtFilePos + 4);
    BlockLenght = ulMipMapDataSize;

    if (fseek (fd,ulBlockLenghtFilePos,SEEK_SET))
        return(RES_OP_ERROR);

    if (! fwrite(&BlockLenght,4,1,fd))
        return(RES_OP_ERROR);

    if (fseek (fd,BlockLenght,SEEK_CUR)) // return to current pos
        return(RES_OP_ERROR);

    return (RES_OP_OK);
}
//---------------------------------------------------------------------------
int TTexSet::LoadTexSetList(char *Filename)
{
    FILE *fd;
    unsigned int cTex;
    char StrBuff[MAX_CARS];
    unsigned int uiMaxMipMaps;
    unsigned int uiNumMipMaps;
    unsigned int uiMipMapNum;
    unsigned int uiLODS;
    
    if (! Filename)
    {
        ERROR_SetError("TEXSET-LD00","No texset list filename provided.");
        return(RES_OP_ERROR);
    }

    // Invalidate the texture set and prepare for mipmap loading
    Invalidate();

    fd = fopen(Filename,"rt");
    if (! fd)
    {
        ERROR_SetError("TEXSET-LDL00","Unable to load TexSet list file",Filename);
        return(RES_OP_ERROR);
    }

    // Get TexList identifier
    fgets(StrBuff,MAX_CARS,fd);
    if (strcmp("TEXLIST",StrBuff))
    {
        fclose(fd);
        ERROR_SetError("TEXSET-LDL00","Bad TexSet list identifier.");
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
            MipMap* mipMap = poLoadTextureAsMipmap(StrBuff);
            if (mipMap == NULL)
            {
                fclose(fd);
                ERROR_SetError("TEXSET-LDL12 ","ERROR");
                return(RES_OP_ERROR);
            }
            else
            {
                // Set the current mipmap
                SetMipMap(uiMipMapNum, mipMap);
            }

            if (TextureArray[cTex].Used)
                fprintf(fd,"%d %s\r\n",cTex,TextureArray[cTex].Filename);
        }
    }

    fclose(fd);
    return (RES_OP_OK);
}
//---------------------------------------------------------------------------
int TTexSet::SaveTexSetList(char *Filename)
{
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
 
    return (RES_OP_OK);
}
//---------------------------------------------------------------------------
