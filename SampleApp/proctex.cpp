// --------------------------------------------------------------------------
#include "memory/GammaE_mem.h"

#include "tex.h"
#include "Proctex.h"
#include "E3D/GammaE_E3D.h"
#include "TerrainGeneration.h"

#define HERTZS		3000.0f
#define	TEX_SIZE	64
const float fTStep	= 8.0f / (float)TEX_SIZE;
// --------------------------------------------------------------------------
class TProcTex : public TTextureObj
{
public:
			 TProcTex();
			~TProcTex();
			virtual void Think();
			void UpdateTexture();
			
			float fTime;
			int   iCount;
			int		iLastFrame;
};
// --------------------------------------------------------------------------
TProcTex::TProcTex()
{
	MaxFilter = E3D_TEX_MAX_FILTER_LINEAR;
	MinFilter = E3D_TEX_MIN_FILTER_LINEAR;
	UWrap     = E3D_TEX_WRAP_REPEAT;
	VWrap     = E3D_TEX_WRAP_REPEAT;
	
	MipMapObj = mNew TMipMapObj();

	// Initialize Tex->MipMap;
	MipMapObj->mipMap = poCreateMipMap(TEX_SIZE, TEX_SIZE, 3);

	MipMapObj->Handler = 0;
	MipMapObj->Update  = true;

	UpdateTexture ();	
	fTime		= 0.0f;
	iCount		= 0;
	iLastFrame  = -1;
}

TProcTex::~TProcTex()
{
	DestroyMipMap(MipMapObj->mipMap);
}

void TProcTex::UpdateTexture ()
{		
	float			fs[3];	
	int				cI,cJ;
	int				iValue;	
	unsigned char*	pData  = MipMapObj->mipMap->lods[0]->data;

	fs[2] = fTime;
	fs[1] = 0.0f;
	for (cJ=0;cJ<TEX_SIZE;cJ++)
	{
		fs[0] = 0.0f;
		for (cI=0;cI<TEX_SIZE;cI++)
		{
			iValue = 255.0f * Perlin_noise(fs,3);	
			if (iValue<0) iValue = 0; else if (iValue > 255) iValue = 255;
			
			*pData++ = iValue;
			*pData++ = iValue;
			*pData++ = iValue;

			fs[0] += fTStep;
		}

		fs[1] += fTStep;
	}
}		 

void TProcTex::Think()
{
	// Set update flag
	fTime += gpoE3DRenderer->REStats.DTime;
	if (fTime > HERTZS) fTime -= HERTZS;
	iCount++;	iCount &= 0x00000007;
	
	//if (! iCount)
	{
		UpdateTexture();
		MipMapObj->Update = true;
	}
}
// --------------------------------------------------------------------------
TProcTex *pTex;

void ProcTex_Init()
{
	pTex = mNew TProcTex;
}

void ProcTex_Finish()
{
	mDel pTex;
}

void ProcTex_Think(void *Par)
{
	if (gpoE3DRenderer->REStats.iCurrentFrame != pTex->iLastFrame)
	{
		pTex->Think();
		pTex->iLastFrame = gpoE3DRenderer->REStats.iCurrentFrame;
	}
	
	gpoE3DRenderer->SetCurrentTextureContext(pTex);
}
// --------------------------------------------------------------------------