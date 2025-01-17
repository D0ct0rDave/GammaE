// -----------------------------------------------------------------------------
#ifndef CFlareMgrH
#define CFlareMgrH 1
// -----------------------------------------------------------------------------
#include "GammaE.h"

// -----------------------------------------------------------------------------
typedef enum TBlinkFunc  {TBF_none,TBF_step,TBF_pulse,TBF_invpulse,TBF_flicker};
typedef enum TFlareState {TFS_Off,TFS_Showing,TFS_On,TFS_Hidding};


#define		MAX_FLARE_TYPES		16
#define		FLARES_PER_COL		32
#define		MAX_FLARE_COLS		32

typedef struct{
	
	CE3D_Shader *poShader;
	TFColor		oColor;
	TBlinkFunc	eBlinkFunc;
	float		fFreq;
	bool		bDirectional;
	
}TFlareType;


typedef struct{
	void			*pParent;
	int				iChildNum;
	int				iStamp;

	int				iType;			// Type of flare: Index of Flare Type Table

	TFlareState		eState;			// Flare State
	float			fFactor;		// State transition factor
	float			fTime;
	
	CVect3			oPos;
	CVect3			oDir;
	CVect2			oPrjPos;
	float			fSize;

}TFlareElem;

// -----------------------------------------------------------------------------
class CFlareMgr 
{
  public:

       CFlareMgr();
      ~CFlareMgr();
	  
		static void Init();
		static void Reset();
		static void AddFlare(int _iType,void *_pParent,int _iChildNum,CVect3 &_roWorldPos,CVect3 &_roWorldDir,float _fSize);
		static void Render();
		static void Update();
		static void UpdateFlare(TFlareElem &_roElem);
		static bool	bFlareVisible(TFlareElem &_roElem);

		static void RenderFlare(TFlareElem &_roElem);

  protected:
  private:
  private:
		static TFlareType		oFTT[MAX_FLARE_TYPES];					// Flare Type Table
		static TFlareElem		oFlare[MAX_FLARE_COLS][FLARES_PER_COL];	// The flares
		
		static	CMesh			oMesh;
		
		static	CMatrix4x4		oCamMat;
		static	CMatrix4x4		oPrjMat;
		static	CMatrix4x4		oCPMat;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------