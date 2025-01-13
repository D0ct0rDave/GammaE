//## begin module%3C43544A0378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C43544A0378.cm

//## begin module%3C43544A0378.cp preserve=no
//## end module%3C43544A0378.cp

//## Module: CDetailer%3C43544A0378; Pseudo Package body
//## Source file: i:\Projects\GammaE\SceneObjects\Detailer\CDetailer.cpp

//## begin module%3C43544A0378.additionalIncludes preserve=no
//## end module%3C43544A0378.additionalIncludes

//## begin module%3C43544A0378.includes preserve=yes
#include <string.h>
#include "tex.h"
#include "Memory/GammaE_Mem.h"

#ifdef _MBCS
	#include <windows.h>
	#include <wingdi.h>
	
	#define TPixelFormatDescriptor	PIXELFORMATDESCRIPTOR
	#define TLogPalette				LOGPALETTE
	#define TPaletteEntry			PALETTEENTRY
#else
	#ifdef _BCB_
	#include <vcl\vcl.h>
	#endif
#endif

#include <gl/gl.h>

//## end module%3C43544A0378.includes

// CDetailer
#include "SceneObjects\Detailer\CDetailer.h"
//## begin module%3C43544A0378.additionalDeclarations preserve=yes
#define TEX_SIZE			128

#define TEX_NOISE_AMPLITUDE	63
#define TEX_NOISE_OFFSET	192

//## end module%3C43544A0378.additionalDeclarations


// Class CDetailer 



CDetailer::CDetailer()
  //## begin CDetailer::CDetailer%.hasinit preserve=no
  //## end CDetailer::CDetailer%.hasinit
  //## begin CDetailer::CDetailer%.initialization preserve=yes
  //## end CDetailer::CDetailer%.initialization
{
  //## begin CDetailer::CDetailer%.body preserve=yes
  //## end CDetailer::CDetailer%.body
}


CDetailer::~CDetailer()
{
  //## begin CDetailer::~CDetailer%.body preserve=yes
  //## end CDetailer::~CDetailer%.body
}



//## Other Operations (implementation)
void CDetailer::Init (int _iMaxTris)
{
  //## begin CDetailer::Init%1011045648.body preserve=yes
	poMesh = mNew CMesh();
	poMesh->Init(	_iMaxTris*3,_iMaxTris,
				E3D_MESH_NITRIS,
				MESH_FIELD_VERTEXS |
				MESH_FIELD_UVCOORDS | 
				MESH_FIELD_COLORS);
	
	poShader = poCreateMaterial();

	poMesh->usNumIdxs  = 0;
	poMesh->usNumPrims = 0;
	poMesh->usNumVerts = 0;
  //## end CDetailer::Init%1011045648.body
}

void CDetailer::SetCamPos (CVect3& _roCamPos)
{
  //## begin CDetailer::SetCamPos%1011045650.body preserve=yes

	oCamPos.Assign( _roCamPos);

  //## end CDetailer::SetCamPos%1011045650.body
}

void CDetailer::SetVertexTris (CVect3* _poVXs, int _iNumTris)
{
  //## begin CDetailer::SetVertexTris%1011045651.body preserve=yes
	poMesh->usNumIdxs  = 0;
	poMesh->usNumPrims = _iNumTris;
	poMesh->usNumVerts = _iNumTris*3;
	
	if (! _iNumTris) return;
	

	static float fThresholdDist = 50.0f;
	static float fUVMultiplier  = 0.125f;
	static float fColorAmp		= 0.3f;

	int			cI;
  	float		fDist;	
	CVect3		*poVX = poMesh->VXs;
	CVect2		*poUV = poMesh->UVs;
	CVect4		*poVC = poMesh->VCs;

	// Compute 
	poVX = poMesh->VXs;
	for (cI=0;cI<_iNumTris*3;cI++)
	{
		// Increase height
		poVX->Assign(*_poVXs);
		poVX->v[2] += 0.05f;

		// Compute UV
		poUV->SetU( poVX->X()*fUVMultiplier);
		poUV->SetV( poVX->Y()*fUVMultiplier);
		
		// Compute color 
		fDist  = oCamPos.SqDistance(*poVX);
		fDist /= fThresholdDist;
		if (fDist > 1.0f) fDist = 1.0f;
		fDist = 1.0f - fDist;

		poVC->V4(1.0f,1.0f,1.0f,fDist*fColorAmp);

		_poVXs++;
		poVX++;
		poUV++;
		poVC++;
	}
  //## end CDetailer::SetVertexTris%1011045651.body
}

void CDetailer::CreateTextureContents (MipMap *_pMipMap)
{
  //## begin CDetailer::CreateTextureContents%1011045654.body preserve=yes
	
	int				cI,cJ;	
	int				iValue;
	unsigned char*	pData = _pMipMap->lods[0]->data;
	
	for (cJ=0;cJ<TEX_SIZE;cJ++)
		for (cI=0;cI<TEX_SIZE;cI++)
		{
			iValue = TEX_NOISE_OFFSET + TEX_NOISE_AMPLITUDE * MATH_Common::fRand();

			*pData++ = iValue;
			*pData++ = iValue;
			*pData++ = iValue;
		}
  //## end CDetailer::CreateTextureContents%1011045654.body
}

TTextureObj * CDetailer::CreateTexture ()
{
  //## begin CDetailer::CreateTexture%1011045653.body preserve=yes
	TTextureObj *TObj = mNew TTextureObj;
	
  	TObj->MaxFilter = E3D_TEX_MAX_FILTER_LINEAR;
	TObj->MinFilter = E3D_TEX_MIN_FILTER_LINEAR;
	TObj->UWrap     = E3D_TEX_WRAP_REPEAT;
	TObj->VWrap     = E3D_TEX_WRAP_REPEAT;
	
	TObj->MipMapObj = mNew TMipMapObj();
	
	// Initialize Tex->MipMap;
	TObj->MipMapObj->mipMap = poCreateMipMap(TEX_SIZE, TEX_SIZE, 3);
	
	TObj->MipMapObj->Handler = 0;
	TObj->MipMapObj->Update  = true;

	CreateTextureContents(TObj->MipMapObj->mipMap);

	return ( TObj );
  //## end CDetailer::CreateTexture%1011045653.body
}

CE3D_Shader * CDetailer::poCreateMaterial ()
{
  //## begin CDetailer::poCreateMaterial%1011045652.body preserve=yes

    // Create the shader texture instruction
	CE3D_ShIns_Texture *poTI = mNew CE3D_ShIns_Texture;
	poTI->pTex = CreateTexture();

	// Setup blending op instruction
	CE3D_ShIns_BlendOp *poBO = mNew CE3D_ShIns_BlendOp;
	poBO->SeteBOpType(eSIBOp_Alpha);

	// Create the shader
	CE3D_Shader		   *poSh = mNew CE3D_Shader;
	poSh->AddInstruction(poBO);
	poSh->AddInstruction(poTI);	

	return (poSh);
  //## end CDetailer::poCreateMaterial%1011045652.body
}

void CDetailer::Render ()
{
  //## begin CDetailer::Render%1011045658.body preserve=yes
  //## end CDetailer::Render%1011045658.body
}

// Additional Declarations
  //## begin CDetailer%3C43544A0378.declarations preserve=yes
  //## end CDetailer%3C43544A0378.declarations

//## begin module%3C43544A0378.epilog preserve=yes
//## end module%3C43544A0378.epilog
