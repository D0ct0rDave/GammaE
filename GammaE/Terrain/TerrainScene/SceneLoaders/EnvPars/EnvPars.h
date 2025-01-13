// -----------------------------------------------------------------------------
#ifndef EnvParsH
#define EnvParsH
// -----------------------------------------------------------------------------

#include "tex.h"

// -----------------------------------------------------------------------------
/*
typedef struct{

    float Radius;
    float Axis[3];
    float DnAngle;  // Dynamic rotation: degrees per second
    float StAngle;  // Static rotation:  degrees
   
    bool  Enabled;

}TSkyDomeLayer;


typedef struct{
    TSkyDomeLayer SDL[3];
    float         Pos[3];
}TSkydomePars;
*/

typedef struct {
    
    int   iFogType;					//0
    float fFogColor[4];				//4
    float fFogDens;					//20
    float fFogNear;					//24
    float fFogFar;					//28
    int   iFogAffEv;				//32

    float fCamFOV;					//36
    float fCamNear;					//40
    float fCamFar;					//44
    int   iUseTileLODFunc;			//48
    float fTileLODParam;			//52
    float fTerrLODParam;			//56

    // Geometric values
    float fXYScale;					//60  (Meters per point)
    float fZScale;					//64
    float fZTranslation;			//68
    float fXOfs;					//72
    float fYOfs;					//76

    // Background
    int   fBKDiameter;				//80
    int   fBKRollRotation;			//84
    int   fBKZTranslation;			//88

    // Sky dome
    int   fSDDiameter;				//92
    int   fSDRollRotation;			//96
    int   fSDZTranslation;			//100
	
	// Light 
	float fLightAmbColor[3];		//104
	float fLightDiffColor[3];		//116
	float fLightRhoAngle;			//128
	float fLightPhiAngle;			//132
	
	// SFX
	int		iEnvType;				//136
	char  cPad[	1024-140];			//140

}TEnvironmentPars; 

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
