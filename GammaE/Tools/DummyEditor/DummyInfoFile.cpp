//---------------------------------------------------------------------------
#include "DummyInfoFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDummyTypes.h"
#include "File.h"
//---------------------------------------------------------------------------
#define DINFO_MAXCARS    128
//---------------------------------------------------------------------------
int iDummyInfoFile_Save(char *_szFilename,CDummyTypes *_poDTypes)
{
    FILE *fd;
    unsigned int uiDummyID = DIF_FILEIDENTIFIER;
    unsigned int uiNumDTypes,uiNumDInsts;
    unsigned int uiDType,uiDInst;
    unsigned char ucMajorVersion = DIF_MAJORVERSION;
    unsigned char ucMinorVersion = DIF_MINORVERSION;

    fd = fopen(_szFilename,"wb");
    if (! fd)
    {
        ERROR_SetError("DIF0S1","Unable to save file",_szFilename);
        return(RES_OP_ERROR);
    }

    // begin riff header
    FILE_BeginRIFFBlock(uiDummyID,fd);

        fwrite(&ucMajorVersion,1,1,fd);
        fwrite(&ucMinorVersion,1,1,fd);

        // -----------------------------
        // Write data
        // -----------------------------


        // Write terrain scene linked to dummy info
        fwrite(_poDTypes->TerrainScene.c_str(),DINFO_MAXCARS,1,fd);

        uiNumDTypes = _poDTypes->DTypes.size();

        // Write the number of dummy types
        fwrite(&uiNumDTypes,4,1,fd);

        // Write dummy properties
        for (uiDType=0;uiDType<uiNumDTypes;uiDType++)
        {
            // Write dummy filename
            fwrite(_poDTypes->DTypes[uiDType].DummyModel.c_str(),DINFO_MAXCARS,1,fd);

            // Write used algorithm
            fwrite(&_poDTypes->DTypes[uiDType].iAlgType,4,1,fd);

            // Write probability
            fwrite(&_poDTypes->DTypes[uiDType].fProb,4,1,fd);

            // Write scale
            fwrite(&_poDTypes->DTypes[uiDType].fScale,4,1,fd);

            // Write iterations
            fwrite(&_poDTypes->DTypes[uiDType].iIters,4,1,fd);

            // -----------------------------
            // Write the dummy instance list
            // -----------------------------
            uiNumDInsts = _poDTypes->DTypes[uiDType].DInsts.size();

                // Write the number of instances
                fwrite(&uiNumDInsts,4,1,fd);

                for (uiDInst=0;uiDInst<uiNumDInsts;uiDInst++)
                    fwrite( &_poDTypes->DTypes[uiDType].DInsts[uiDInst].oPos ,sizeof(CVect3),1,fd);
        }

    // End riff header
    FILE_EndRIFFBlock(fd);

    fclose(fd);
    return(RES_OP_OK);
}
//---------------------------------------------------------------------------
int iDummyInfoFile_Load(char *_szFilename,CDummyTypes *_poDTypes)
{
    FILE *fd;
    unsigned int    uiDummyID;
    unsigned int    uiBlockSize;
    unsigned int    uiNumDTypes,uiNumDInsts;
    unsigned int    uiDType,uiDInst;
    unsigned char   ucMajorVersion;
    unsigned char   ucMinorVersion;
    char            AuxStr[DINFO_MAXCARS+1];
    CDummyList      DList;
    CDummyInstance  DInst;

    fd = fopen(_szFilename,"rb");
    if (! fd)
    {
        ERROR_SetError("DIF0L1","Unable to load file",_szFilename);
        return(RES_OP_ERROR);
    }

    // begin riff header
    fread(&uiDummyID,4,1,fd);
    fread(&uiBlockSize,4,1,fd);

    if (uiDummyID != DIF_FILEIDENTIFIER)
    {
        fclose(fd);
        ERROR_SetError("DIF0L2","Bad dummy info file");
        return(RES_OP_ERROR);
    }

    fread(&ucMajorVersion,1,1,fd);
    fread(&ucMinorVersion,1,1,fd);

    if ((ucMajorVersion>DIF_MAJORVERSION) ||
        (ucMajorVersion==DIF_MAJORVERSION) && (ucMinorVersion>DIF_MINORVERSION))
    {
        fclose(fd);
        ERROR_SetError("DIF0L3","Bad file version number");
        return(RES_OP_ERROR);
    }

        // -----------------------------
        // Read data
        // -----------------------------


        // Read terrain scene linked to dummy info
        fread(AuxStr,DINFO_MAXCARS,1,fd);
        AuxStr[DINFO_MAXCARS] = 0;
        _poDTypes->TerrainScene = AuxStr;

        // Write the number of dummy types
        fread(&uiNumDTypes,4,1,fd);

        // Clear the dummy lists
        _poDTypes->DTypes.clear();

        // Write dummy properties
        for (uiDType=0;uiDType<uiNumDTypes;uiDType++)
        {
            // read dummy filename
            fread(AuxStr,DINFO_MAXCARS,1,fd);
            AuxStr[DINFO_MAXCARS] = 0;
            
            DList.DummyModel = AuxStr;

            // read used algorithm
            fread(&DList.iAlgType,4,1,fd);

            // read probability
            fread(&DList.fProb,4,1,fd);

            // read scale
            fread(&DList.fScale,4,1,fd);

            // read  iterations
            fread(&DList.iIters,4,1,fd);

            // -----------------------------
            // read the dummy instance list
            // -----------------------------

                // read the number of instances
                fread(&uiNumDInsts,4,1,fd);

                // Clear previous instance list
                DList.DInsts.clear();

                for (uiDInst=0;uiDInst<uiNumDInsts;uiDInst++)
                {
                    fread( &DInst.oPos,sizeof(CVect3),1,fd);

                    // Add instance to the list
                    DList.DInsts.push_back(DInst);
                }

                // Add list to the dummy-types list
                _poDTypes->DTypes.push_back(DList);
        }

    fclose(fd);
    return(RES_OP_OK);
}
//---------------------------------------------------------------------------
