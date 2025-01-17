// -----------------------------------------------------------------------------
#ifndef CPSysMgrH
#define CPSysMgrH 1
// -----------------------------------------------------------------------------
#include "GammaE.h"

// -----------------------------------------------------------------------------

#define		MAX_PSYS_TYPES		16
#define		PSYS_PER_COL		32
#define		MAX_PARTICLES		8192
#define		MAX_PSSHADERS		16
#define     MAX_FREQ            50
#define     MAX_LTIME           10
#define     MAX_TYPEPART        4096

// -----------------------------------------------------------------------------

// Particle system instance
typedef struct{
	void			*pParent;
	int				iChildNum;
	int				iStamp;

	int				iType;			// Type of PSys: Index of Flare Type Table

	CVect3			oPos;
	CVect3			oDir;
	
	float			fTime;

}TPSysInstance;


// Particle element
typedef struct{

	CVect3		oPos;
	CVect3		oOldPos;
	CVect3		oSpeed;

	TFColor		oColor;
	
	float		fDAngle;
	float		fAngle;
	
	float		fSize;
	
	float		fDColor;
	float		fColor;

	float		fLTime;

	TPSysInstance	*pParent;

}TParticle;


// Particle process function prototype
typedef void (* TParticleProcess)(TParticle *poPart);


// Particle type definition element
typedef struct{
	
	int			iTex;
	int			iMaxPSys;
	
	CVect3		oExtPos;
	CVect3		oExtSpeed;
		
	float		fGravity;
	
	float		fDAngle;
	float		fIAngle;

	float		fISize;
	float		fDSize;
	float		fRSize;

	float		fSpeed;				// Speed module
	float		fRSpeed;			// Random speed module
	
	float		fILTime;
	float		fRLTime;

	float		fFreq;				// Particles created per second
	float		fPeriod;

	TFColor		oIColor;
	TFColor		oFColor;
	
	TParticleProcess Process;
}TPSysType;

// -----------------------------------------------------------------------------
class CPSysMgr
{
  public:

       CPSysMgr();
      ~CPSysMgr();
	  
		static void Init();
		static void Reset();
		static void AddPSys(int _iType,void *_pParent,int _iChildNum,CVect3 &_roWorldPos,CVect3 &_roWorldDir);
				
		static void AddParticle(TParticle &_roPart);
		static void RenderPSys(TPSysInstance *_poElem);
		static void Render();

		static void UpdateParticle(TParticle &_roPart);
		static void Update();
			
		static void CreateParticle (TParticle &_roPart,TPSysInstance *_poParent);
		static void CreateParticles(TPSysInstance *_poParent,int _iNumParts);


    public:
    	static	CE3D_Shader		*oShTab[MAX_PSSHADERS];
		static	TPSysType		 oPSTT[MAX_PSYS_TYPES];				// PSys Type Table
		static	TPSysInstance	*oPSys[MAX_PSYS_TYPES];				// The PSys
		static	TParticle		oPars [MAX_PARTICLES];				// The particles
		
		static	CMesh			oMesh;
		
		static	CMatrix4x4		oCamMat;
		static	CMatrix4x4		oPrjMat;
		static	CMatrix4x4		oCPMat;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------