#ifndef DEFFileH
#define DEFFileH

// Pasar a la estructura proyecto
typedef struct{

    float Axis[3];
    float Radius;
    float DnAngle;  // Dynamic rotation: degrees per second
    float StAngle;  // Static rotation:  degrees
    bool  Enabled;
}TSkyDomeLayer;


typedef struct{
    TSkyDomeLayer SDL[3];
    float Pos[3];
}TSkydomePars;

typedef struct
{
    // ------------------ General >
    int   cNTab;
    // --------------- HeighField >
    float fZoom;
    // ----------------- Lightmap >
    int   bOptimize;
    int   bAverageLOD;
    int   bTMapSample;

    int   cAmbientColor[3];
    int   cDifuseColor[3];

    // ------------------ 3D View >
    int   cN3DTab;
    float iCamX;
    float iCamY;
    float iCamZ;
    float fPitch;
    float fYaw;
    float fRoll;


    // --------- Fog >
    int   iFogType;
    int   cFogColor[3];
    float fFogDens;
    float fFogNear;
    float fFogFar;
    int   bFogAffEv;

    // - Performance >
    int   iNumTrianges;
    int   iTileSubdivisions;
    int   iFov;
    int   iClipingNear;
    int   iClipingFar;

    // --- Rendering >
    int   bTerrain;
    int   bEnvMap;
    int   bSkyDome;
    int   b2DFrust;
    int   cRenderStyle;
    float fZScale;

    // -- BackGround >
    int   iDiameter;
    int   iRollRotation;
    int   iZTranslation;

    int   iDunRot;
    int   iUSpeed;
    int   iVSpeeD;

} stEnvOptPars;


class TDEFFile
{
    public:TDEFFile();
           TDEFFile(unsigned int _iSecsPerRow,unsigned int _iSecsPerCol);

          ~TDEFFile();

           void Init(unsigned int _iSecsPerRow,unsigned int _iSecsPerCol);           
           // -------------------------------------------------- 
           // Modified to be supported by the GameEngine
           // -------------------------------------------------- 
           
           char *LoadFromFile(char *_szFilename );
                  
           // -------------------------------------------------- FileNames >
           void SetRoadFilename     (char * _szRoadFilename);
           void SetVisFilename      (char * _szVisFilename);
           void SetBINFilename      (char * _szBINFilename);
           void SetTexMapFilename   (char * _szTexMapFilename);
           void SetLightMapFilename (char * _szLightMapFilename);
           void SetTexSetFilename   (char *_szTexSetFilename);
           void SetAlphaSetFilename (char *_szAlphaSetFilename);
           void SetAuxTexFilename   (char *_szAuxTexFilename);

           char * szGetRoadFilename     ();
           char * szGetVisFilename      ();
           char * szGetBINFilename      ();
           char * szGetTexMapFilename   ();
           char * szGetLightMapFilename ();
           char * szGetAuxTexFilename   ();

           // ---------------------------------------- Environment Options >
           void                 SetEnvOpt       (stEnvOptPars* stNewEnvOpt);
           stEnvOptPars         *GetEnvOpt      ();


           void SetXOffset(float _fXOffset);
           void SetYOffset(float _fYOffset);
           float fGetXOffset();
           float fGetYOffset();

           void    SetGlobalMap (unsigned int _uiRow ,unsigned int _uiCol,char *_szGMap);
           void    SetMaxMin    (unsigned int _uiRow ,unsigned int _uiCol,float _fMaxZ,float _fMinZ);
           void    SetSectorRes (unsigned int _fSectorRes);
           void    SetSectorSize(float _fSectorSize);
           void    SetEnvOptions(stEnvOptPars *stNewEnvOpt);
           void    GetEnvOptions(stEnvOptPars *stNewEnvOpt);           

           int    iGetSecsPerRow();
           int    iGetSecsPerCol();
           float  fGetSectorSize();
           int    iGetSectorRes ();
           char *szGetGlobalMapFilename(int _iRow, int _iCol);

           int Load(char *_szFilename);
           int Save(char *_szFilename);

           float fGetMinZ(int _iRow, int _iCol);
           float fGetMaxZ(int _iRow, int _iCol);

           char *szGetTexSetFilename();
           char *szGetAlphaSetFilename ();

  protected:

  private:
           char * szNextString (char *_szStr);
           char * szStringFinal(char *_szStr);
           char * szWordFinal  (char *_szStr);
           char * szNextWord   (char *_szStr);
           void ParseToken     (char *_szToken, int *_piTkCol, int *_piTkRow);
           char * szSeparateToken(char *_szSrc, char * *_pszToken, int *_piTkRow, int *_piTkCol, char * *_pszArgs);
           char * szCreateString (char *szSrc);
           int    iGetToken      (char *_szToken);

  private:
      stEnvOptPars  stEnvOpt;

      char *m_szTexMapFilename;
      char *m_szTexSetFilename;

      char *m_szAlphaSetFilename;
      //char *m_szAuxTexsFilename;  Erase this line please !!!!
      char *m_szAuxTexFilename;

      char  *m_szBINFilename;
      char  *m_szLightMapFilename;
      char  *m_szVisFilename;
      char  *m_szRoadFilename;
      int    m_iSecsPerRow;
      int    m_iSecsPerCol;
      int    m_iSectorRes;
      float  m_fSectorSize;
      char* *m_pszGlobalMaps;
      float *m_pfMaxZ;
      float *m_pfMinZ;

      float m_fXOffset;
      float m_fYOffset;

      TSkydomePars SD;
};
#endif
