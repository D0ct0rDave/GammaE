#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DEFFile.h"

#if defined (__WIN32_COMPILATION__) || (__PS2_COMPILATION__)
    #include "mmry.h"
    #include "strmio.h"
#else
    
    #ifdef __TERRAIN_EDITOR__
            
    #define vDelete(a) delete(a)
    #define pNew(a)    new(a) 
    
    #endif

#endif

//-----------------------------------------------------------------------------
// Parsing states
//-----------------------------------------------------------------------------
#define STATE_Searching           0
#define STATE_Ready               1
#define STATE_Comenting1          2
#define STATE_Comenting2          3
#define STATE_Comenting3          4
#define STATE_Comenting4          5

//-----------------------------------------------------------------------------
// Token Table
//-----------------------------------------------------------------------------
// Start with the most frequently used tokens
enum TokenTypes{
      // As it is the most used token, start with it
      TKTYPE_GMAP,
      TKTYPE_MAXMINZ,
      TKTYPE_TILE,

      TKTYPE_NUMTILES,
      TKTYPE_TEXSET,
      TKTYPE_TMAPFILE,
      TKTYPE_HEADFILE,
      TKTYPE_BINFILE,
      TKTYPE_ROADFILE,
      TKTYPE_LITFILE,
      TKTYPE_VISFILE,

      TKTYPE_MATRIXDIMS,
      TKTYPE_SECTORSIZE,
      TKTYPE_SECTORRES,

      TKTYPE_TEXLIST,
      TKTYPE_ALPHASET,
      TKTYPE_ALPHALIST,
      // ------ OffSet >
      TKTYPE_CIRCOFFSET,
      TKTYPE_AUXTEXS,

      TKTYPE_SD_RADIUS,
      TKTYPE_SD_AXIS,
      TKTYPE_SD_DN_ANGLE,
      TKTYPE_SD_ST_ANGLE,
      TKTYPE_SD_POS,

    // ------------------ General >
    TKTYPE_GEN_NTAB,
    // --------------- HeighField >
    TKTYPE_HF_fZOOM,
    // ----------------- Lightmap >
    TKTYPE_LM_bOPTIMIZE,
    TKTYPE_LM_bAVERAGELOD,
    TKTYPE_LM_bTMAPSAMPLE,

    TKTYPE_LM_cAMBIENTCOLOR,
    TKTYPE_LM_cDIFUSECOLOR,
    // ------------------ 3D View >
    TKTYPE_3DV_cN3DTAB,
    TKTYPE_3DV_iCAMX,
    TKTYPE_3DV_iCAMY,
    TKTYPE_3DV_iCAMZ,
    TKTYPE_3DV_fPITCH,
    TKTYPE_3DV_fYAW,
    TKTYPE_3DV_fROLL,
    // --------- Fog >
    TKTYPE_FOG_iFOGTYPE,
    TKTYPE_FOG_cFOGCOLOR,
    TKTYPE_FOG_fFOGDENS,
    TKTYPE_FOG_fFOGNEAR,
    TKTYPE_FOG_fFOGFAR,
    TKTYPE_FOG_bFOGAFFEV,
    // - Performance >
    TKTYPE_PRF_iNUMTRIANGLES,
    TKTYPE_PRF_iTILESUBDIVISIONS,
    TKTYPE_PRF_iFOV,
    TKTYPE_PRF_iCLIPINGNEAR,
    TKTYPE_PRF_iCLIPINGFAR,
    // --- Rendering >
    TKTYPE_RND_bTERRAIN,
    TKTYPE_RND_bENVMAP,
    TKTYPE_RND_bSKYDOME,
    TKTYPE_RND_b2DFRUST,
    TKTYPE_RND_cRENDERSTYLE,
    TKTYPE_RND_fZSCALE,
    // -- BackGround >
    TKTYPE_BCK_iDIAMETER,
    TKTYPE_BCK_iROLLROTATION,
    TKTYPE_BCK_iZTRANSLATION,
    TKTYPE_BCK_iDUNROT,
    TKTYPE_BCK_iUSPEED,
    TKTYPE_BCK_iVSPEED,
    NUM_TOKEN_TYPES,
};

//-----------------------------------------------------------------------------
// Nothing about typedefs prefixes: Assuming "T"
typedef struct{
    char         *szToken;
    unsigned int uiTokenID;
}TTokenEntry;
//-----------------------------------------------------------------------------
TTokenEntry stTokenTable[NUM_TOKEN_TYPES] = {
    { "GMAP"        ,TKTYPE_GMAP       },
    { "MAXMINZ"     ,TKTYPE_MAXMINZ    },
    { "TILE"        ,TKTYPE_TILE       },
    { "NUMTILES"    ,TKTYPE_NUMTILES   },
    { "TEXSET"      ,TKTYPE_TEXSET     },
    { "TMAPFILE"    ,TKTYPE_TMAPFILE   },
    { "HEADFILE"    ,TKTYPE_HEADFILE   },
    { "BINFILE"     ,TKTYPE_BINFILE    },
    { "ROADFILE"    ,TKTYPE_ROADFILE   },
    { "LITFILE"     ,TKTYPE_LITFILE    },
    { "VISFILE"     ,TKTYPE_VISFILE    },
    { "MATRIXDIMS"  ,TKTYPE_MATRIXDIMS },
    { "SECTORSIZE"  ,TKTYPE_SECTORSIZE },
    { "SECTORRES"   ,TKTYPE_SECTORRES  },
    { "TEXLIST"     ,TKTYPE_TEXLIST    },
    { "ALPHASET"    ,TKTYPE_ALPHASET   },
    { "ALPHALIST"   ,TKTYPE_ALPHALIST  },
    { "OFFSET"      ,TKTYPE_CIRCOFFSET },
    { "AUXTEXS"     ,TKTYPE_AUXTEXS    },

    { "SKY_RADIUS"  ,TKTYPE_SD_RADIUS   },
    { "SKY_AXIS"    ,TKTYPE_SD_AXIS    },
    { "SKY_DNANG"   ,TKTYPE_SD_DN_ANGLE},
    { "SKY_STANG"   ,TKTYPE_SD_ST_ANGLE},
    { "SKY_POS"     ,TKTYPE_SD_POS     },

    // ------------------ General >
    { "GEN_NTAB"        ,TKTYPE_GEN_NTAB        },
    // --------------- HeighField >
    { "HF_fZOOM"        ,TKTYPE_HF_fZOOM        },
    // ----------------- Lightmap >
    { "LM_bOPTIMIZE"    ,TKTYPE_LM_bOPTIMIZE    },
    { "LM_bAVERAGELOD"  ,TKTYPE_LM_bAVERAGELOD  },
    { "LM_bTMAPSAMPLE"  ,TKTYPE_LM_bTMAPSAMPLE  },

    { "LM_cAMBIENTCOLOR",TKTYPE_LM_cAMBIENTCOLOR},
    { "LM_cDIFUSECOLOR" ,TKTYPE_LM_cDIFUSECOLOR },
    // ------------------ 3D View >
    { "3DV_cN3DTAB"     ,TKTYPE_3DV_cN3DTAB     },
    { "3DV_iCAMX"       ,TKTYPE_3DV_iCAMX       },
    { "3DV_iCAMY"       ,TKTYPE_3DV_iCAMY       },
    { "3DV_iCAMZ"       ,TKTYPE_3DV_iCAMZ       },
    { "3DV_fPITCH"      ,TKTYPE_3DV_fPITCH      },
    { "3DV_fYAW"        ,TKTYPE_3DV_fYAW        },
    { "3DV_fROLL"       ,TKTYPE_3DV_fROLL       },
    // --------- Fog >
    { "FOG_iFOGTYPE"    ,TKTYPE_FOG_iFOGTYPE    },
    { "FOG_cFOGCOLOR"   ,TKTYPE_FOG_cFOGCOLOR   },
    { "FOG_fFOGDENS"    ,TKTYPE_FOG_fFOGDENS    },
    { "FOG_fFOGNEAR"    ,TKTYPE_FOG_fFOGNEAR    },
    { "FOG_fFOGFAR"     ,TKTYPE_FOG_fFOGFAR     },
    { "FOG_bFOGAFFEV"   ,TKTYPE_FOG_bFOGAFFEV   },
    // - Performance >
    { "PRF_iNUMTRIANGLES"       ,TKTYPE_PRF_iNUMTRIANGLES       },
    { "PRF_iTILESUBDIVISIONS"   ,TKTYPE_PRF_iTILESUBDIVISIONS   },
    { "PRF_iFOV"        ,TKTYPE_PRF_iFOV        },
    { "PRF_iCLIPINGNEAR",TKTYPE_PRF_iCLIPINGNEAR},
    { "PRF_iCLIPINGFAR" ,TKTYPE_PRF_iCLIPINGFAR },
    // --- Rendering >
    { "RND_bTERRAIN"    ,TKTYPE_RND_bTERRAIN    },
    { "RND_bENVMAP"     ,TKTYPE_RND_bENVMAP     },
    { "RND_bSKYDOME"    ,TKTYPE_RND_bSKYDOME    },
    { "RND_b2DFRUST"    ,TKTYPE_RND_b2DFRUST    },
    { "RND_cRENDERSTYLE",TKTYPE_RND_cRENDERSTYLE},
    { "RND_fZSCALE"     ,TKTYPE_RND_fZSCALE     },
    // -- BackGround >
    { "BCK_iDIAMETER"           ,TKTYPE_BCK_iDIAMETER  },
    { "BCK_iROLLROTATION"       ,TKTYPE_BCK_iROLLROTATION},
    { "BCK_iZTRANSLATION"       ,TKTYPE_BCK_iZTRANSLATION},
    { "BCK_iDUNROT"     ,TKTYPE_BCK_iDUNROT     },
    { "BCK_iUSPEED"     ,TKTYPE_BCK_iUSPEED     },
    { "BCK_iVSPEED"     ,TKTYPE_BCK_iVSPEED     },
};


//-----------------------------------------------------------------------------
TDEFFile::TDEFFile()
{
    m_szBINFilename     = NULL;
    m_szTexMapFilename  = NULL;
    m_szLightMapFilename= NULL;
    m_szVisFilename     = NULL;
    m_szTexSetFilename  = NULL;
    m_szAlphaSetFilename= NULL;
    m_szAuxTexFilename  = NULL;
    m_pszGlobalMaps     = NULL;

    m_pfMaxZ            = NULL;
    m_pfMinZ            = NULL;
}

TDEFFile::TDEFFile(unsigned int _iSecsPerRow,unsigned int _iSecsPerCol)
{
    m_szBINFilename     = NULL;
    m_szTexMapFilename  = NULL;
    m_szLightMapFilename= NULL;
    m_szVisFilename     = NULL;
    m_szTexSetFilename  = NULL;
    m_szAlphaSetFilename= NULL;
    m_pszGlobalMaps     = NULL;
    m_szAuxTexFilename  = NULL;

    m_pfMaxZ            = NULL;
    m_pfMinZ            = NULL;

    Init(_iSecsPerRow,_iSecsPerCol);
}
//-----------------------------------------------------------------------------
TDEFFile::~TDEFFile()
{
    // Delete all the objects
    int iRow,iCol;

    if (m_szBINFilename)       vDelete(m_szBINFilename);
    if (m_szTexMapFilename)    vDelete(m_szTexMapFilename);
    if (m_szLightMapFilename)  vDelete(m_szLightMapFilename);
    if (m_szVisFilename)       vDelete(m_szVisFilename);
    if (m_szTexSetFilename)    vDelete(m_szTexSetFilename);
    if (m_szAlphaSetFilename)  vDelete(m_szAlphaSetFilename);
    if (m_szAuxTexFilename)    vDelete(m_szAuxTexFilename);

    if (m_pfMaxZ)              vDelete(m_pfMaxZ);
    if (m_pfMinZ)              vDelete(m_pfMinZ);

    if (m_pszGlobalMaps)
    {
        for (iRow=0;iRow<m_iSecsPerCol;iRow++)
            for (iCol=0;iCol<m_iSecsPerRow;iCol++)
                vDelete( m_pszGlobalMaps[iRow * m_iSecsPerRow + iCol] );

        vDelete(m_pszGlobalMaps);
}
}
// --------------------------------------------------------------------------
char * TDEFFile::szNextString (char *_szStr)
{
    int iState = STATE_Searching;

    while ((iState != STATE_Ready) && *_szStr)
    {
        switch (iState)
        {
            case STATE_Searching: if (*_szStr=='/')
                                  {
                                        iState=STATE_Comenting1;
                                        _szStr++;
}
                             else if ((*_szStr==' ') || (*_szStr=='\t') || (*_szStr=='\r') || (*_szStr=='\n'))
                                        _szStr++;
                             else
                                  iState = STATE_Ready;
                                  break;

            case STATE_Comenting1:  if (*_szStr=='/')
                                        iState = STATE_Comenting4;
                             else   if (*_szStr=='*')
                                        iState = STATE_Comenting2;
                             else   STATE_Searching;

                                    _szStr++;
                                    break;

            case STATE_Comenting2:  if (*_szStr=='*') iState = STATE_Comenting3;
                                    _szStr++;
                                    break;

            case STATE_Comenting3:  if (*_szStr=='/')
                                        iState = STATE_Searching;
                                    else
                                        iState = STATE_Comenting2;
                                    _szStr++;
                                    break;

            case STATE_Comenting4:  if ((*_szStr=='\r') || (*_szStr=='\n'))
                                        iState = STATE_Searching;
                                    else
                                        _szStr++;
                                    break;
}
}

    return(_szStr);
}
// -------------------------------------------------------------------------
char * TDEFFile::szStringFinal (char *_szStr)
{
    // Saltar letras, tabuladores y espacios
    while ((*_szStr) && (*_szStr!='\r') && (*_szStr!='\n')) _szStr++;
    return(_szStr);
}
// --------------------------------------------------------------------------
char * TDEFFile::szWordFinal (char *_szStr)
{
    while ((*_szStr) && (*_szStr!='\r') && (*_szStr!='\n') && (*_szStr!=' ') && (*_szStr !='\t')) _szStr++;
    return(_szStr);
}
// --------------------------------------------------------------------------
char * TDEFFile::szNextWord (char *_szStr)
{
    while ((*_szStr==' ') || (*_szStr =='\t')) _szStr++;
    return(_szStr);
}
// --------------------------------------------------------------------------
void TDEFFile::ParseToken (char *_szToken, int *_piTkCol, int *_piTkRow)
{
    #define TK_PARSE_STATE_INI              0
    #define TK_PARSE_STATE_SETIDX           1
    #define TK_PARSE_STATE_READY            2

    char *szLetra  = _szToken;
    char *szCurrentIdx;
    int  *piCurrentIdx;
    int  iState;

    *_piTkCol = -1;
    *_piTkRow = -1;

    // FSM : Finite state machine
    iState = TK_PARSE_STATE_INI;
    while (iState != TK_PARSE_STATE_READY)
    {
        switch (iState)
        {
            case TK_PARSE_STATE_INI:    if (*szLetra == '(')
                                        {
                                            *szLetra = 0;
                                            szLetra++;
                                            piCurrentIdx = _piTkRow;
                                            szCurrentIdx = szLetra;

                                            iState = TK_PARSE_STATE_SETIDX;
}
                                   else if (*szLetra) szLetra++;
                                   else iState = TK_PARSE_STATE_READY;
                                        break;
            case TK_PARSE_STATE_SETIDX: if (*szLetra == ',')
                                        {
                                            *szLetra = 0;
                                            sscanf(szCurrentIdx,"%d",piCurrentIdx);

                                            szLetra++;
                                            piCurrentIdx = _piTkCol;
                                            szCurrentIdx = szLetra;
}
                                   else if (*szLetra == ')')
                                        {
                                            *szLetra = 0;
                                            szLetra++;
                                            sscanf(szCurrentIdx,"%d",piCurrentIdx);

                                            iState = TK_PARSE_STATE_READY;
}
                                   else {
                                            if (*szLetra)
                                                szLetra++;
                                            else
                                                iState = TK_PARSE_STATE_READY;
}
}
}
}
// --------------------------------------------------------------------------
char * TDEFFile::szSeparateToken (char *_szSrc, char * *_pszToken, int *_piTkRow, int *_piTkCol, char * *_pszArgs)
{
    *_pszToken = szNextWord (_szSrc);
    _szSrc     = szWordFinal(_szSrc);
    *_szSrc    = 0;                       // Mark the end of the token
    _szSrc++;

    // if the token is an array or matrix search the indexes    
    ParseToken(*_pszToken,_piTkRow,_piTkCol);

    // Get the next word in the string
    _szSrc = szNextWord(_szSrc);        // Begining of the next word

    if (*_szSrc=='"')                   // if the argument has a starter quote, delete it
    {
        *_pszArgs = ++_szSrc;           // Set the begining of the arguments after the quotes
        _szSrc = szWordFinal(_szSrc);   // Get the end of the string
        _szSrc--;                       // step back one char

        if (*_szSrc=='"')               // If the current char position is the end quotes
        {
            *_szSrc = 0;                // delete it
            _szSrc++;                   // Set the new string begining string after the arguments
}
}
    else
        // Set Args parameter
        *_pszArgs = _szSrc;

    _szSrc = szStringFinal(_szSrc);        // End of args
    if (*_szSrc)
    {
        *_szSrc= 0;
        return (_szSrc+1);
}
    else
        return (_szSrc);
}
// --------------------------------------------------------------------------
char * TDEFFile::szCreateString (char *szSrc)
{
    unsigned int uiLen;
    char *szNewStr;

    uiLen = strlen(szSrc);
    szNewStr = pNew( char[uiLen + 1] );
    strcpy(szNewStr, szSrc);

    return(szNewStr);
}
// --------------------------------------------------------------------------
char * TDEFFile::szGetTexMapFilename ()
{
  return ( m_szTexMapFilename );
}
// --------------------------------------------------------------------------
char * TDEFFile::szGetBINFilename ()
{
    return (m_szBINFilename);
}
// --------------------------------------------------------------------------
char * TDEFFile::szGetLightMapFilename ()
{
    return (m_szLightMapFilename);
}
// --------------------------------------------------------------------------
char * TDEFFile::szGetVisFilename ()
{
    return (m_szVisFilename);
}
// --------------------------------------------------------------------------
char * TDEFFile::szGetRoadFilename ()
{
    return (m_szRoadFilename);
}
// --------------------------------------------------------------------------
int TDEFFile::iGetSecsPerCol()
{
    return (m_iSecsPerCol);
}
// --------------------------------------------------------------------------
int TDEFFile::iGetSecsPerRow()
{
    return (m_iSecsPerRow);
}
// --------------------------------------------------------------------------
float TDEFFile::fGetSectorSize()
{
    return (m_fSectorSize);
}
// --------------------------------------------------------------------------
int TDEFFile::iGetSectorRes ()
{
  return (m_iSectorRes);
}
// --------------------------------------------------------------------------
char * TDEFFile::szGetGlobalMapFilename(int _iRow, int _iCol)
{
	if (! m_pszGlobalMaps) return(NULL);
    return( m_pszGlobalMaps[_iRow * m_iSecsPerRow + _iCol] );
}
// --------------------------------------------------------------------------
int TDEFFile::iGetToken(char *_szToken)
{
    int iTokenNum=0;
    while ((iTokenNum<NUM_TOKEN_TYPES) && (strcmp(_szToken,stTokenTable[iTokenNum].szToken)))
        iTokenNum++;

    return(iTokenNum<NUM_TOKEN_TYPES?iTokenNum:-1);
}
// --------------------------------------------------------------------------
// Specific functions: Modify these according to TerrainEditor and GameEngine
// --------------------------------------------------------------------------
char *TDEFFile::LoadFromFile(char *_szFilename )
{
    char           *szStrBuff;
    unsigned long   ulLenght;

    // ---------------------------------
    // Read file contents
    // ---------------------------------
    #if defined (__WIN32_COMPILATION__) || (__PS2_COMPILATION__)
        
        __STREAM__   poFD;

        if (! poFD.iOpen(_szFilename,"rb"))
            return(0);

        // Read object identifier        
        ulLenght = poFD.ulGetSize();
        szStrBuff = pNew(char[ulLenght+1]);
        if (! szStrBuff)
        {
            poFD.Close();            
            return(0);
}

        poFD.iReadBin(szStrBuff,ulLenght);
        poFD.Close();
   #else

        FILE            *fd;
           
        fd = fopen(_szFilename,"rb");
        if (! fd) return(0);

        fseek(fd,0,SEEK_END);
        ulLenght = ftell(fd);

        szStrBuff = pNew(char[ulLenght + 1]);
        if (! szStrBuff)
        {
            fclose(fd);
            return(0);
}

        fseek(fd,0,SEEK_SET);
        fread(szStrBuff,ulLenght,1,fd);
        fclose(fd);
    #endif

    szStrBuff[ulLenght]= 0;
    return(szStrBuff);
}
// --------------------------------------------------------------------------
int TDEFFile::Load(char *_szFilename)
{
    char            *szStrBuff;
    char            *szStr;
    char            *szToken;
    char            *szArgs;
    int             iTkRow,iTkCol;
    int             iTokenNum;

    int             iInitFlag;

    szStrBuff = LoadFromFile(_szFilename);

    // ---------------------------------
    // Buffer contents parsing
    // ---------------------------------
    iInitFlag   = 0;
    szStr = szStrBuff;

    while (*szStr)
    {
        szStr = szSeparateToken(szNextString(szStr),&szToken,&iTkCol,&iTkRow,&szArgs);

        // Parse the obtained tokens and process them
        iTokenNum = iGetToken(szToken);

        if (iTokenNum<NUM_TOKEN_TYPES)
        {
            switch (stTokenTable[iTokenNum].uiTokenID)
            {
                case TKTYPE_GMAP:       if (! iInitFlag)
                                        {
                                            Init(m_iSecsPerRow,m_iSecsPerCol);
                                            iInitFlag = 1;
}

                                        if (
                                            (iTkRow>-1) && (iTkRow<m_iSecsPerCol) &&
                                            (iTkCol>-1) && (iTkCol<m_iSecsPerRow) &&
                                            (*szArgs)
                                            )
                                            m_pszGlobalMaps[iTkRow * m_iSecsPerRow + iTkCol] = szCreateString (szArgs);
                                        break;
                case TKTYPE_TILE:       
                                        break;

                case TKTYPE_NUMTILES:
                                        break;
                case TKTYPE_TMAPFILE:   if (*szArgs)
                                            m_szTexMapFilename = szCreateString(szArgs);
                                        break;
                case TKTYPE_HEADFILE:   /*
                                        if (Args[0])
                                            m_iTMapFilename = szCreateString (Args);
                                        */
                                        break;
                case TKTYPE_BINFILE:    if (*szArgs)
                                            m_szBINFilename = szCreateString (szArgs);
                                        break;
                case TKTYPE_ROADFILE:   if (*szArgs)
                                            m_szRoadFilename = szCreateString (szArgs);
                                        break;
                case TKTYPE_LITFILE:    if (*szArgs)
                                            m_szLightMapFilename = szCreateString (szArgs);
                                        break;
                case TKTYPE_VISFILE:    if (*szArgs)
                                            m_szVisFilename = szCreateString(szArgs);
                                        break;
                case TKTYPE_MAXMINZ:    if (! iInitFlag)
                                        {
                                            Init(m_iSecsPerRow,m_iSecsPerCol);
                                            iInitFlag = 1;
}

                                        if (
                                            (iTkRow>-1) && (iTkRow<m_iSecsPerRow) &&
                                            (iTkCol>-1) && (iTkCol<m_iSecsPerCol) &&
                                            (*szArgs)
                                            )
                                        {
                                            sscanf(
                                                    szArgs,"%f %f",
                                                    &m_pfMaxZ[iTkRow * m_iSecsPerRow + iTkCol],
                                                    &m_pfMinZ[iTkRow * m_iSecsPerRow + iTkCol]
                                                   );
}
                                        break;
                case TKTYPE_MATRIXDIMS: if (*szArgs)
                                            sscanf(szArgs,"%i %i",&m_iSecsPerRow,&m_iSecsPerCol);
                                        break;

                case TKTYPE_SECTORSIZE: if (*szArgs)
                                            sscanf(szArgs,"%f",&m_fSectorSize);
                                        break;

                case TKTYPE_SECTORRES:if (*szArgs)
                                            sscanf(szArgs,"%d",&m_iSectorRes);
                                        break;
                case TKTYPE_TEXSET:     if (*szArgs)
                                            m_szTexSetFilename = szCreateString(szArgs);
                                        break;
                case TKTYPE_TEXLIST:    break;
                case TKTYPE_ALPHASET:   if (*szArgs)
                                            m_szAlphaSetFilename = szCreateString(szArgs);
                                        break;
                case TKTYPE_ALPHALIST:
                                        break;
                case TKTYPE_AUXTEXS:    if (*szArgs)
                                            m_szAuxTexFilename = szCreateString(szArgs);
                                        break;
                case TKTYPE_CIRCOFFSET: if (*szArgs)
                                            sscanf(szArgs,"%f %f",&m_fXOffset,&m_fYOffset);
                                        break;
                // Sky dome
                case TKTYPE_SD_AXIS:    if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f %f %f",
                                                    &SD.SDL[iTkRow].Axis[0],
                                                    &SD.SDL[iTkRow].Axis[1],
                                                    &SD.SDL[iTkRow].Axis[2]);
                                        break;

                case TKTYPE_SD_DN_ANGLE:if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f",&SD.SDL[iTkRow].DnAngle);
                                        break;

                case TKTYPE_SD_ST_ANGLE:if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f",&SD.SDL[iTkRow].StAngle);
                                        break;

                case TKTYPE_SD_RADIUS:  if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f",SD.SDL[iTkRow].Radius);
                                        break;

                case TKTYPE_SD_POS:     if (*szArgs)
                                            sscanf(szArgs,"%f %f %f",
                                                    &SD.Pos[0],
                                                    &SD.Pos[1],
                                                    &SD.Pos[2]);
                                        break;
                // ------------------ General >
                case TKTYPE_GEN_NTAB:   if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.cNTab); break;
                case TKTYPE_HF_fZOOM:   if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fZoom); break;
                // ----------------- Lightmap >
                case TKTYPE_LM_bOPTIMIZE:   if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bOptimize);   break;
                case TKTYPE_LM_bAVERAGELOD: if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bAverageLOD); break;
                case TKTYPE_LM_bTMAPSAMPLE: if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bTMapSample); break;
                case TKTYPE_LM_cAMBIENTCOLOR:   if (*szArgs)
                                            sscanf(szArgs,"%i %i %i",
                                                    &stEnvOpt.cAmbientColor[0],
                                                    &stEnvOpt.cAmbientColor[1],
                                                    &stEnvOpt.cAmbientColor[2]);
                                        break;
                case TKTYPE_LM_cDIFUSECOLOR:   if (*szArgs)
                                            sscanf(szArgs,"%i %i %i",
                                                    &stEnvOpt.cDifuseColor[0],
                                                    &stEnvOpt.cDifuseColor[1],
                                                    &stEnvOpt.cDifuseColor[2]);

                                        break;

                // ------------------ 3D View >
                case TKTYPE_3DV_cN3DTAB:  if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.cN3DTab); break;
                case TKTYPE_3DV_iCAMX:    if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iCamX);   break;
                case TKTYPE_3DV_iCAMY:    if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iCamY);   break;
                case TKTYPE_3DV_iCAMZ:    if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iCamZ);   break;
                case TKTYPE_3DV_fPITCH:   if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fPitch);  break;
                case TKTYPE_3DV_fYAW:     if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fYaw);    break;
                case TKTYPE_3DV_fROLL:    if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fRoll);   break;

                // --------- Fog >
                case TKTYPE_FOG_iFOGTYPE:  if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iFogType);   break;
                case TKTYPE_FOG_fFOGDENS:  if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fFogDens);   break;
                case TKTYPE_FOG_fFOGNEAR:  if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fFogNear);   break;
                case TKTYPE_FOG_fFOGFAR:   if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fFogFar);    break;
                case TKTYPE_FOG_bFOGAFFEV: if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bFogAffEv);  break;
                case TKTYPE_FOG_cFOGCOLOR: if (*szArgs) sscanf(szArgs,"%i %i %i",
                                                                &stEnvOpt.cFogColor[0],
                                                                &stEnvOpt.cFogColor[1],
                                                                &stEnvOpt.cFogColor[2]);          break;

                // - Performance >
                case TKTYPE_PRF_iNUMTRIANGLES:      if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iNumTrianges);      break;
                case TKTYPE_PRF_iTILESUBDIVISIONS:  if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iTileSubdivisions); break;
                case TKTYPE_PRF_iFOV:               if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iFov);              break;
                case TKTYPE_PRF_iCLIPINGNEAR:       if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iClipingNear);      break;
                case TKTYPE_PRF_iCLIPINGFAR:        if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iClipingFar);       break;

                // --- Rendering >
                case TKTYPE_RND_bTERRAIN:      if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bTerrain);     break;
                case TKTYPE_RND_bENVMAP:       if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bEnvMap);      break;
                case TKTYPE_RND_bSKYDOME:      if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.bSkyDome);     break;
                case TKTYPE_RND_b2DFRUST:      if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.b2DFrust);     break;
                case TKTYPE_RND_cRENDERSTYLE:  if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.cRenderStyle); break;
                case TKTYPE_RND_fZSCALE:       if (*szArgs) sscanf(szArgs,"%f",&stEnvOpt.fZScale);      break;

                // -- BackGround >
                case TKTYPE_BCK_iDIAMETER:      if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iDiameter);     break;
                case TKTYPE_BCK_iROLLROTATION:  if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iRollRotation); break;
                case TKTYPE_BCK_iZTRANSLATION:  if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iZTranslation); break;
                case TKTYPE_BCK_iDUNROT:        if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iDunRot);       break;
                case TKTYPE_BCK_iUSPEED:        if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iUSpeed);       break;
                case TKTYPE_BCK_iVSPEED:        if (*szArgs) sscanf(szArgs,"%i",&stEnvOpt.iVSpeeD);       break;

}
}
}
    
    vDelete (szStrBuff);

    return(1);
}
// --------------------------------------------------------------------------
float TDEFFile::fGetMinZ (int _iRow, int _iCol)
{
    return( m_pfMinZ[_iRow * m_iSecsPerRow + _iCol] );
}
// --------------------------------------------------------------------------
float TDEFFile::fGetMaxZ (int _iRow, int _iCol)
{
  return( m_pfMaxZ[_iRow * m_iSecsPerRow + _iCol] );
}
// --------------------------------------------------------------------------
int TDEFFile::Save(char *_szFilename)
{
#ifdef __TERRAIN_EDITOR__
    FILE *fd;
    unsigned int iRow,iCol;

    fd = fopen(_szFilename,"wt");

    fprintf(fd,"// --------------------------------------------------------------------------\n");
    fprintf(fd,"// DEF File generated with TerrainEditor \n");
    fprintf(fd,"// --------------------------------------------------------------------------\n");

    fprintf(fd,"%s\t%d %d\n" ,stTokenTable[TKTYPE_MATRIXDIMS].szToken,m_iSecsPerRow,m_iSecsPerCol);
    fprintf(fd,"%s\t%d\n"    ,stTokenTable[TKTYPE_SECTORRES].szToken ,m_iSectorRes);
    fprintf(fd,"%s\t%.03f\n" ,stTokenTable[TKTYPE_SECTORSIZE].szToken,m_fSectorSize);
    fprintf(fd,"%s\t%.03f %.03f\n",stTokenTable[TKTYPE_CIRCOFFSET].szToken,m_fXOffset,m_fYOffset);

    fprintf(fd,"\n");
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_BINFILE].szToken   ,m_szBINFilename);       // HeightField binary file
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_ROADFILE].szToken  ,m_szRoadFilename);      // Road file
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_TMAPFILE].szToken  ,m_szTexMapFilename);    // TexMap file
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_LITFILE].szToken   ,m_szLightMapFilename);  // LightMap file
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_VISFILE].szToken   ,m_szVisFilename);       // Visibility file

    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_TEXSET].szToken    ,m_szTexSetFilename);    // TexSet  file
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_ALPHASET].szToken  ,m_szAlphaSetFilename);  // AlphaSet  file
    fprintf(fd,"%s\t\"%s\"\n",stTokenTable[TKTYPE_AUXTEXS].szToken   ,m_szAuxTexFilename);   // Aux texs file

    // ------------------ General >
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_GEN_NTAB].szToken           ,stEnvOpt.cNTab);               //
    // --------------- HeighField >
    fprintf(fd,"%s\t\"%.03f\"\n",stTokenTable[TKTYPE_HF_fZOOM].szToken           ,stEnvOpt.fZoom);               //
    // ----------------- Lightmap >
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_LM_bOPTIMIZE].szToken       ,stEnvOpt.bOptimize);           //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_LM_bAVERAGELOD].szToken     ,stEnvOpt.bAverageLOD);         //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_LM_bTMAPSAMPLE].szToken     ,stEnvOpt.bTMapSample);         //
    // !
    fprintf(fd,"%s\t\"%i %i %i\"\n",stTokenTable[TKTYPE_LM_cAMBIENTCOLOR].szToken   ,stEnvOpt.cAmbientColor[0] ,stEnvOpt.cAmbientColor[1] ,stEnvOpt.cAmbientColor[2]);   //
    fprintf(fd,"%s\t\"%i %i %i\"\n",stTokenTable[TKTYPE_LM_cDIFUSECOLOR].szToken    ,stEnvOpt.cDifuseColor[0]  ,stEnvOpt.cDifuseColor[1]  ,stEnvOpt.cDifuseColor[2]);    //

    // ------------------ 3D View >
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_3DV_cN3DTAB].szToken  ,stEnvOpt.cN3DTab);  //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_3DV_iCAMX].szToken    ,stEnvOpt.iCamX);    //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_3DV_iCAMY].szToken    ,stEnvOpt.iCamY);    //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_3DV_iCAMZ].szToken    ,stEnvOpt.iCamZ);    //
    fprintf(fd,"%s\t\"%.03f\"\n",stTokenTable[TKTYPE_3DV_fPITCH].szToken,stEnvOpt.fPitch);   //
    fprintf(fd,"%s\t\"%.03f\"\n",stTokenTable[TKTYPE_3DV_fYAW].szToken  ,stEnvOpt.fYaw);     //
    fprintf(fd,"%s\t\"%.03f\"\n",stTokenTable[TKTYPE_3DV_fROLL].szToken ,stEnvOpt.fRoll);    //

    // --------- Fog >
    fprintf(fd,"%s\t\"%d\"\n",stTokenTable[TKTYPE_FOG_iFOGTYPE].szToken    ,stEnvOpt.iFogType);    //
    // !
    fprintf(fd,"%s\t\"%i %i %i\"\n",stTokenTable[TKTYPE_FOG_cFOGCOLOR].szToken   ,stEnvOpt.cFogColor[0],stEnvOpt.cFogColor[1],stEnvOpt.cFogColor[2]);  //
    fprintf(fd,"%s\t\"%.3f\"\n",stTokenTable[TKTYPE_FOG_fFOGDENS].szToken ,stEnvOpt.fFogDens);     //
    fprintf(fd,"%s\t\"%.3f\"\n",stTokenTable[TKTYPE_FOG_fFOGNEAR].szToken ,stEnvOpt.fFogNear);     //
    fprintf(fd,"%s\t\"%.3f\"\n",stTokenTable[TKTYPE_FOG_fFOGFAR].szToken  ,stEnvOpt.fFogFar);      //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_FOG_bFOGAFFEV].szToken   ,stEnvOpt.bFogAffEv);   //

    // - Performance >
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_PRF_iNUMTRIANGLES].szToken     ,stEnvOpt.iNumTrianges);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_PRF_iTILESUBDIVISIONS].szToken ,stEnvOpt.iTileSubdivisions);  //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_PRF_iFOV].szToken              ,stEnvOpt.iFov);               //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_PRF_iCLIPINGNEAR].szToken      ,stEnvOpt.iClipingNear);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_PRF_iCLIPINGFAR].szToken       ,stEnvOpt.iClipingFar);        //

    // --- Rendering >
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_RND_bTERRAIN].szToken      ,stEnvOpt.bTerrain);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_RND_bENVMAP].szToken       ,stEnvOpt.bEnvMap);        //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_RND_bSKYDOME].szToken      ,stEnvOpt.bSkyDome);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_RND_b2DFRUST].szToken      ,stEnvOpt.b2DFrust);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_RND_cRENDERSTYLE].szToken  ,stEnvOpt.cRenderStyle);   //
    fprintf(fd,"%s\t\"%f\"\n",stTokenTable[TKTYPE_RND_fZSCALE].szToken       ,stEnvOpt.fZScale);        //

    // -- BackGround >
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_BCK_iDIAMETER].szToken      ,stEnvOpt.iDiameter);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_BCK_iROLLROTATION].szToken  ,stEnvOpt.iRollRotation);        //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_BCK_iZTRANSLATION].szToken  ,stEnvOpt.iZTranslation);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_BCK_iDUNROT].szToken        ,stEnvOpt.iDunRot);       //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_BCK_iUSPEED].szToken        ,stEnvOpt.iUSpeed);   //
    fprintf(fd,"%s\t\"%i\"\n",stTokenTable[TKTYPE_BCK_iVSPEED].szToken        ,stEnvOpt.iVSpeeD);        //

    // SkyDome
    for (iRow=0;iRow<3;iRow++)
    {
        if (SD.SDL[iRow].Enabled)
        fprintf(fd,"%s\t%.03f %.03f %.03f\n",
                stTokenTable[TKTYPE_SD_AXIS].szToken,
                SD.SDL[iRow].Axis[0],
                SD.SDL[iRow].Axis[1],
                SD.SDL[iRow].Axis[2]
                );
}

    /*case TKTYPE_SD_DN_ANGLE:if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f",&SD.SDL[iTkRow].DnAngle);
                                        break;

                case TKTYPE_SD_ST_ANGLE:if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f",&SD.SDL[iTkRow].StAngle);
                                        break;

                case TKTYPE_SD_RADIUS:  if ((iTkRow>0) && (iTkRow<3) && (*szArgs))
                                            sscanf(szArgs,"%f",SD.SDL[iTkRow].Radius);
                                        break;

                case TKTYPE_SD_POS:     if (*szArgs)
                                            sscanf(szArgs,"%f %f %f",
                                                    &SD.Pos[0],
                                                    &SD.Pos[1],
                                                    &SD.Pos[2]);
                                        break;
                // Fog
                case TKTYPE_FOG_TYPE:   if (*szArgs)
                                            sscanf(szArgs,"%i",&FOG.FogType);
                                        break;
                case TKTYPE_FOG_DENS:   if (*szArgs)
                                            sscanf(szArgs,"%f",&FOG.FogDens);
                                        break;
                case TKTYPE_FOG_NEAR:   if (*szArgs)
                                            sscanf(szArgs,"%f",&FOG.FogNear);
                                        break;
                case TKTYPE_FOG_FAR:    if (*szArgs)
                                            sscanf(szArgs,"%f",&FOG.FogFar);
                                        break;
                case TKTYPE_FOG_COLOR:  if (*szArgs)
                                            sscanf(szArgs,"%i %i %i",
                                                    &FOG.FogColor[0],
                                                    &FOG.FogColor[1],
                                                    &FOG.FogColor[2]);
                                        break;
                case TKTYPE_FOG_AFF_EV: if (*szArgs)
                                            sscanf(szArgs,"%i",&FOG.FogAffEv);
                                        break;
    */
    // Write the global maps
    fprintf(fd,"// --------------------------------------------------------------------------\n");

    for (iRow=0;iRow<m_iSecsPerCol;iRow++)
        for (iCol=0;iCol<m_iSecsPerRow;iCol++)
            fprintf(fd,"%s(%d,%d)\t\"%s\"\n",
                    stTokenTable[TKTYPE_GMAP].szToken,
                    iRow,
                    iCol,
                    m_pszGlobalMaps[iRow*m_iSecsPerRow + iCol]);

    // Write the Max and Mins
    fprintf(fd,"// --------------------------------------------------------------------------\n");
    for (iRow=0;iRow<m_iSecsPerCol;iRow++)
        for (iCol=0;iCol<m_iSecsPerRow;iCol++)
            fprintf(fd,"%s(%d,%d)\t%.03f\t%.03f\n",
                    stTokenTable[TKTYPE_MAXMINZ].szToken,
                    iRow,
                    iCol,
                    m_pfMaxZ[iRow*m_iSecsPerRow + iCol],
                    m_pfMinZ[iRow*m_iSecsPerRow + iCol]);

    fclose(fd);
#endif

    return(1);
}
// --------------------------------------------------------------------------
void TDEFFile::Init(unsigned int _iSecsPerRow,unsigned int _iSecsPerCol)
{
    m_iSecsPerRow = _iSecsPerRow;
    m_iSecsPerCol = _iSecsPerCol;

    if (m_pszGlobalMaps) vDelete(m_pszGlobalMaps);
    m_pszGlobalMaps = pNew ( char *[m_iSecsPerRow * m_iSecsPerCol] );

    if (m_pfMaxZ)   vDelete(m_pfMaxZ);
    m_pfMaxZ        = pNew ( float [m_iSecsPerRow * m_iSecsPerCol] );

    if (m_pfMinZ)   vDelete(m_pfMinZ);
    m_pfMinZ        = pNew ( float [m_iSecsPerRow * m_iSecsPerCol] );
}
// --------------------------------------------------------------------------
void TDEFFile::SetRoadFilename(char * _szRoadFilename)
{
    m_szRoadFilename = szCreateString(_szRoadFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetVisFilename(char * _szVisFilename)
{
    m_szVisFilename = szCreateString(_szVisFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetBINFilename(char * _szBINFilename)
{
    m_szBINFilename = szCreateString(_szBINFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetTexMapFilename(char * _szTexMapFilename)
{
    m_szTexMapFilename = szCreateString(_szTexMapFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetLightMapFilename(char * _szLightMapFilename)
{
    m_szLightMapFilename = szCreateString(_szLightMapFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetGlobalMap(unsigned int _uiRow,unsigned int _uiCol,char *_szGMap)
{
    m_pszGlobalMaps[_uiRow * m_iSecsPerRow + _uiCol] = szCreateString(_szGMap);
}
// --------------------------------------------------------------------------
void TDEFFile::SetMaxMin(unsigned int _uiRow,unsigned int _uiCol,float _fMaxZ,float _fMinZ)
{
    m_pfMaxZ[_uiRow * m_iSecsPerRow + _uiCol] = _fMaxZ;
    m_pfMinZ[_uiRow * m_iSecsPerRow + _uiCol] = _fMinZ;
}
// --------------------------------------------------------------------------
void TDEFFile::SetSectorSize(float _fSectorSize)
{
    m_fSectorSize = _fSectorSize;
}
// --------------------------------------------------------------------------
void TDEFFile::SetSectorRes(unsigned int _iSectorRes)
{
    m_iSectorRes = _iSectorRes;
}
// --------------------------------------------------------------------------
void TDEFFile::SetTexSetFilename(char *_szTexSetFilename)
{
    m_szTexSetFilename    = szCreateString(_szTexSetFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetAlphaSetFilename(char *_szAlphaSetFilename)
{
    m_szAlphaSetFilename  = szCreateString(_szAlphaSetFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetAuxTexFilename(char *_szAuxTexFilename)
{
    m_szAuxTexFilename  = szCreateString(_szAuxTexFilename);
}
// --------------------------------------------------------------------------
char *TDEFFile::szGetTexSetFilename()
{
    return(m_szTexSetFilename);
}
// --------------------------------------------------------------------------
char *TDEFFile::szGetAlphaSetFilename()
{
    return(m_szAlphaSetFilename);
}
// --------------------------------------------------------------------------
char *TDEFFile::szGetAuxTexFilename()
{
    return(m_szAuxTexFilename);
}
// --------------------------------------------------------------------------
void TDEFFile::SetXOffset(float _fXOffset)
{
    m_fYOffset = _fXOffset;
}

void TDEFFile::SetYOffset(float _fYOffset)
{
    m_fYOffset = _fYOffset;
}

float TDEFFile::fGetXOffset()
{
    return(m_fXOffset);
}

float TDEFFile::fGetYOffset()
{
    return(m_fYOffset);
}


// --------------------------------------------------------------------------
void  TDEFFile::SetEnvOptions(stEnvOptPars *stNewEnvOpt)
{
    // ------------------ General >
    stEnvOpt.cNTab       = stNewEnvOpt->cNTab;
    // --------------- HeighField >
    stEnvOpt.fZoom       = stNewEnvOpt->fZoom;
    // ----------------- Lightmap >
    stEnvOpt.bOptimize   = stNewEnvOpt->bOptimize;
    stEnvOpt.bAverageLOD = stNewEnvOpt->bAverageLOD;
    stEnvOpt.bTMapSample = stNewEnvOpt->bTMapSample;

    stEnvOpt.cAmbientColor[0] = stNewEnvOpt->cAmbientColor[0];
    stEnvOpt.cAmbientColor[1] = stNewEnvOpt->cAmbientColor[1];
    stEnvOpt.cAmbientColor[2] = stNewEnvOpt->cAmbientColor[2];

    stEnvOpt.cDifuseColor[0]  = stNewEnvOpt->cDifuseColor[0];
    stEnvOpt.cDifuseColor[1]  = stNewEnvOpt->cDifuseColor[1];
    stEnvOpt.cDifuseColor[2]  = stNewEnvOpt->cDifuseColor[2];

    // ------------------ 3D View >
    stEnvOpt.cN3DTab = stNewEnvOpt->cN3DTab;
    stEnvOpt.iCamX   = stNewEnvOpt->iCamX;
    stEnvOpt.iCamY   = stNewEnvOpt->iCamY;
    stEnvOpt.iCamZ   = stNewEnvOpt->iCamZ;
    stEnvOpt.fPitch  = stNewEnvOpt->fPitch;
    stEnvOpt.fYaw    = stNewEnvOpt->fYaw;
    stEnvOpt.fRoll   = stNewEnvOpt->fRoll;


    // --------- Fog >
    stEnvOpt.iFogType     = stNewEnvOpt->iFogType;
    stEnvOpt.cFogColor[0] = stNewEnvOpt->cFogColor[0];
    stEnvOpt.cFogColor[1] = stNewEnvOpt->cFogColor[1];
    stEnvOpt.cFogColor[2] = stNewEnvOpt->cFogColor[2];
    stEnvOpt.fFogDens     = stNewEnvOpt->fFogDens;
    stEnvOpt.fFogNear     = stNewEnvOpt->fFogNear;
    stEnvOpt.fFogFar      = stNewEnvOpt->fFogFar;
    stEnvOpt.bFogAffEv    = stNewEnvOpt->bFogAffEv;

    // - Performance >
    stEnvOpt.iNumTrianges      = stNewEnvOpt->iNumTrianges;
    stEnvOpt.iTileSubdivisions = stNewEnvOpt->iTileSubdivisions;
    stEnvOpt.iFov              = stNewEnvOpt->iFov;
    stEnvOpt.iClipingNear      = stNewEnvOpt->iClipingNear;
    stEnvOpt.iClipingFar       = stNewEnvOpt->iClipingFar;

    // --- Rendering >
    stEnvOpt.bTerrain      = stNewEnvOpt->bTerrain;
    stEnvOpt.bEnvMap       = stNewEnvOpt->bEnvMap;
    stEnvOpt.bSkyDome      = stNewEnvOpt->bSkyDome;
    stEnvOpt.b2DFrust      = stNewEnvOpt->b2DFrust;
    stEnvOpt.cRenderStyle  = stNewEnvOpt->cRenderStyle;
    stEnvOpt.fZScale       = stNewEnvOpt->fZScale;

    // -- BackGround >
    stEnvOpt.iDiameter     = stNewEnvOpt->iDiameter;
    stEnvOpt.iRollRotation = stNewEnvOpt->iRollRotation;
    stEnvOpt.iZTranslation = stNewEnvOpt->iZTranslation;

    stEnvOpt.iDunRot       = stNewEnvOpt->iDunRot;
    stEnvOpt.iUSpeed       = stNewEnvOpt->iUSpeed;
    stEnvOpt.iVSpeeD       = stNewEnvOpt->iVSpeeD;

}
// --------------------------------------------------------------------------
void  TDEFFile::GetEnvOptions(stEnvOptPars *stNewEnvOpt)
{
    // ------------------ General >
    stNewEnvOpt->cNTab         = stEnvOpt.cNTab;
    // --------------- HeighField >
    stNewEnvOpt->fZoom         = stEnvOpt.fZoom;
    // ----------------- Lightmap >
    stNewEnvOpt->bOptimize     = stEnvOpt.bOptimize;
    stNewEnvOpt->bAverageLOD   = stEnvOpt.bAverageLOD;
    stNewEnvOpt->bTMapSample   = stEnvOpt.bTMapSample;

    stNewEnvOpt->cAmbientColor[0] = stEnvOpt.cAmbientColor[0];
    stNewEnvOpt->cAmbientColor[1] = stEnvOpt.cAmbientColor[1];
    stNewEnvOpt->cAmbientColor[2] = stEnvOpt.cAmbientColor[2];

    stNewEnvOpt->cDifuseColor[0]  = stEnvOpt.cDifuseColor[0];
    stNewEnvOpt->cDifuseColor[1]  = stEnvOpt.cDifuseColor[1];
    stNewEnvOpt->cDifuseColor[2]  = stEnvOpt.cDifuseColor[2];

    // ------------------ 3D View >
    stNewEnvOpt->cN3DTab       = stEnvOpt.cN3DTab;
    stNewEnvOpt->iCamX         = stEnvOpt.iCamX;
    stNewEnvOpt->iCamY         = stEnvOpt.iCamY;
    stNewEnvOpt->iCamZ         = stEnvOpt.iCamZ;
    stNewEnvOpt->fPitch        = stEnvOpt.fPitch;
    stNewEnvOpt->fYaw          = stEnvOpt.fYaw;
    stNewEnvOpt->fRoll         = stEnvOpt.fRoll;


    // --------- Fog >
    stNewEnvOpt->iFogType      = stEnvOpt.iFogType;
    stNewEnvOpt->cFogColor[0]  = stEnvOpt.cFogColor[0];
    stNewEnvOpt->cFogColor[1]  = stEnvOpt.cFogColor[1];
    stNewEnvOpt->cFogColor[2]  = stEnvOpt.cFogColor[2];
    stNewEnvOpt->fFogDens      = stEnvOpt.fFogDens;
    stNewEnvOpt->fFogNear      = stEnvOpt.fFogNear;
    stNewEnvOpt->fFogFar       = stEnvOpt.fFogFar;
    stNewEnvOpt->bFogAffEv     = stEnvOpt.bFogAffEv;

    // - Performance >
    stNewEnvOpt->iNumTrianges  = stEnvOpt.iNumTrianges;
    stNewEnvOpt->iTileSubdivisions = stEnvOpt.iTileSubdivisions;
    stNewEnvOpt->iFov          = stEnvOpt.iFov;
    stNewEnvOpt->iClipingNear  = stEnvOpt.iClipingNear;
    stNewEnvOpt->iClipingFar   = stEnvOpt.iClipingFar;

    // --- Rendering >
    stNewEnvOpt->bTerrain      = stEnvOpt.bTerrain;
    stNewEnvOpt->bEnvMap       = stEnvOpt.bEnvMap;
    stNewEnvOpt->bSkyDome      = stEnvOpt.bSkyDome;
    stNewEnvOpt->b2DFrust      = stEnvOpt.b2DFrust;
    stNewEnvOpt->cRenderStyle  = stEnvOpt.cRenderStyle;
    stNewEnvOpt->fZScale       = stEnvOpt.fZScale;

    // -- BackGround >
    stNewEnvOpt->iDiameter     = stEnvOpt.iDiameter;
    stNewEnvOpt->iRollRotation = stEnvOpt.iRollRotation;
    stNewEnvOpt->iZTranslation = stEnvOpt.iZTranslation;

    stNewEnvOpt->iDunRot       = stEnvOpt.iDunRot;
    stNewEnvOpt->iUSpeed       = stEnvOpt.iUSpeed;
    stNewEnvOpt->iVSpeeD       = stEnvOpt.iVSpeeD;

}
// --------------------------------------------------------------------------