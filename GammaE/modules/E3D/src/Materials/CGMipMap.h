//-----------------------------------------------------------------------------
#ifndef MipMapObjH
#define MipMapObjH
//-----------------------------------------------------------------------------
// #include <freeimage.h>
#include "GammaE_Misc.h"
//-----------------------------------------------------------------------------
typedef enum EImageFormat
{
     IF_NONE,

     IF_PALETTE,
     IF_RGB16,
     IF_RGBA16,
     IF_RGB,
     IF_RGBA,
     IF_S3TC,
     IF_JPEG,

     IF_NUMFORMATS
}EImageFormat;
//-----------------------------------------------------------------------------
class CGMipMap : public CGResource
{
public:
	CGMipMap() :	m_uiTX(0),m_uiTY(0),m_uiNumLODs(0),m_pPalette(NULL),m_eFormat(IF_NONE), m_poHandler(NULL) {};	
	CGMipMap(uint _uiTX,uint _uiTY,uint _uiNumLODs,EImageFormat _eFormat);
	~CGMipMap();

	uint			m_uiTX;
	uint			m_uiTY;
	uint			m_uiNumLODs;
	EImageFormat	m_eFormat;

	void*			m_pLOD[16];	
	void*			m_pPalette;
	handler			m_poHandler;
};
//-----------------------------------------------------------------------------
#endif