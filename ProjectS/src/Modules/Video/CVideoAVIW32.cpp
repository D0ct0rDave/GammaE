// ----------------------------------------------------------------------------
#include "GammaE.h"
#include "CVideo.h"

#include <vfw.h>
#include "FreeImage.h"


HDRAWDIB hdd;													// Handle For Our Dib
HBITMAP hBitmap;												// Handle To A Device Dependant Bitmap
HDC hdc = CreateCompatibleDC(0);								// Creates A Compatible Device Context
unsigned char* data = 0;										// Pointer To Our Resized Image

AVISTREAMINFO		psi;										// Pointer To A Structure Containing Stream Info
PAVISTREAM			pavi;										// Handle To An Open Stream
PGETFRAME			pgf;										// Pointer To A GetFrame Object
BITMAPINFOHEADER	bmih;										// Header Information For DrawDibDraw Decoding
int					width;										// Video Width
int					height;										// Video Height
int					mpf;										// Will Hold Rough Milliseconds Per Frame

static bool			m_bInitialized	= false;
static float		m_fFPS			= 0.0f;
static uint			m_uiNumFrames	= 0;
static uint			m_uiCurFrame	= 0;

static bool			m_bLoop			= false;
static CGMipMap*	m_poTex			= NULL;
static CGMeshRect*	m_poMesh		= NULL;
static CGShader* m_poShader		= NULL;

float		CVideo::m_fTime			= 0.0f;
float		CVideo::m_fTotalTime	= 0.0f;
bool		CVideo::m_bPlaying		= false;

const EImageFormat TEXTUREFORMAT    = IF_RGB;
// ----------------------------------------------------------------------------
bool CVideo::bInit(char* _szFilename,bool _bLoop)
{
	// Initialize library
	if (! m_bInitialized)
	{
		AVIFileInit();											// Opens The AVIFile Library
		m_bInitialized = true;
	}

	// Opens The AVI Stream
	if (AVIStreamOpenFromFile(&pavi, _szFilename, streamtypeVIDEO, 0, OF_READ, NULL) !=0)
	{
		// An Error Occurred Opening The Stream
		CGErrorLC::I()->Write("Failed To Open The AVI Stream %s",_szFilename);
		return(false);
	}
		

	AVIStreamInfo(pavi, &psi, sizeof(psi));						// Reads Information About The Stream Into psi
	width =psi.rcFrame.right-psi.rcFrame.left;					// Width Is Right Side Of Frame Minus Left
	height=psi.rcFrame.bottom-psi.rcFrame.top;					// Height Is Bottom Of Frame Minus Top

	m_uiNumFrames = AVIStreamLength(pavi);						// The Last Frame Of The Stream
	m_uiCurFrame  = 0;

	m_fTotalTime = (float)AVIStreamSampleToTime(pavi,m_uiNumFrames) / 1000.0f;
	m_fFPS = (float)m_uiNumFrames / m_fTotalTime;	// Calculate Rough FPS

	bmih.biSize			= sizeof (BITMAPINFOHEADER);			// Size Of The BitmapInfoHeader
	bmih.biPlanes		= 1;									// Bitplanes	
	bmih.biBitCount		= 24;									// Bits Format We Want (24 Bit, 3 Bytes)
	bmih.biWidth		= width;								// Width We Want (256 Pixels)
	bmih.biHeight		= height;								// Height We Want (256 Pixels)
	bmih.biCompression	= BI_RGB;								// Requested Mode = RGB

	hdd		= DrawDibOpen();									// Grab A Device Context For Our Dib
	hBitmap = CreateDIBSection (hdc, (BITMAPINFO*)(&bmih), DIB_RGB_COLORS, (void**)(&data), NULL, NULL);
	SelectObject (hdc, hBitmap);								// Select hBitmap Into Our Device Context (hdc)

	pgf=AVIStreamGetFrameOpen(pavi, &bmih);						// Create The PGETFRAME	Using Our Request Mode
	if (pgf==NULL)
	{
		// An Error Occurred Opening The Frame
		CGErrorLC::I()->Write("Failed To Open The AVI Frame");
		return(false);		
	}

	// Information For The Title Bar (Width / Height / Last Frame)
	// wsprintf (title, "NeHe's AVI Player: Width: %d, Height: %d, Frames: %d", width, height, lastframe);
	// SetWindowText(g_window->hWnd, title);
	if (m_poTex == NULL)
	{
		if (TEXTUREFORMAT == IF_RGBA)
			m_poTex = mNew CGMipMap(bmih.biWidth,bmih.biHeight,1,IF_RGBA);	
		else
			m_poTex = mNew CGMipMap(bmih.biWidth,bmih.biHeight,1,IF_RGB);	
		
		m_poTex->Invalidate();

		m_poMesh   = mNew CGMeshRect;
		m_poShader = CGShaderUtils::poGenerateShaderFromMipMap(m_poTex,VIDEO_FRAME_SHADER);
		CGShaderWH::I()->uiAdd(m_poShader,VIDEO_FRAME_SHADER);
		CGMipMapWH::I()->uiAdd(m_poTex,VIDEO_FRAME_SHADER);
	}

	// Sound
	m_fTime		= 0.0f;
	m_bPlaying	= false;
	m_bLoop     = _bLoop;

	DecodeFrame(0);

	return(true);
}
// ----------------------------------------------------------------------------
void CVideo::Finish()
{
	
}
// ----------------------------------------------------------------------------
void CVideo::DecodeFrame(uint _uiFrame)
{
	if (_uiFrame >= m_uiNumFrames) return;

	LPBITMAPINFOHEADER lpbi;											// Holds The Bitmap Header Information
	lpbi = (LPBITMAPINFOHEADER)AVIStreamGetFrame(pgf, m_uiCurFrame);		// Grab Data From The AVI Stream
	if (lpbi == NULL) return;

	char* framedata = (char *)lpbi+lpbi->biSize+lpbi->biClrUsed * sizeof(RGBQUAD);	// Pointer To Data Returned By AVIStreamGetFrame	

	// Convert Data To Requested Bitmap Format
	DrawDibDraw (hdd, hdc, 0, 0, width, height, lpbi, framedata, 0, 0, width, height, 0);

	/*	
	#if 0
		
		memcpy(m_poTex->m_pLOD[0],data,m_poTex->m_uiWidth * m_poTex->m_uiHeight * 3);	

	#else
		// Copy flipped image
		unsigned int uiStride	= m_poTex->m_uiWidth * 3;
		char* texdata			= (char*)m_poTex->m_pLOD[0] + uiStride*(m_poTex->m_uiHeight-1);
		framedata				= (char*)data;

		for (uint i=0;i<m_poTex->m_uiHeight;i++)
		{
			memcpy(texdata,framedata,uiStride);

			texdata		-= uiStride;
			framedata	+= uiStride;
		}
	#endif

	// Swap RB channels
	uint uiPixels = m_poTex->m_uiWidth * m_poTex->m_uiHeight;
	char* srcdata			= (char*)m_poTex->m_pLOD[0]
	char* dstdata			= (char*)framedata + (uiPixels-1)*3; // set the pointer to the last pixel

	char* uiStride = m_poTex->m_uiWidth*3;

	while (uiPixels)
	{ 
		char aux = texdata[0];
		texdata[0] = texdata[2];
		texdata[2] = aux;

		texdata +=3;
		uiPixels--;
	}

	m_poTex->Invalidate();

*/
	if (TEXTUREFORMAT == IF_RGBA)
	{
		// Convert from 24 to 32 bit, Flip Vertically and Swap R&B channels
		uint uiStride = m_poTex->m_uiTX * 3;
		char* srcdata = (char*)m_poTex->m_pLOD[0];
		char* dstdata = (char*)framedata + (m_poTex->m_uiTY-1) * uiStride; // set the pointer to the first pixel of the last line

		for (uint j=0;j<m_poTex->m_uiTX;j++)
		{
			for (uint i=0;i<m_poTex->m_uiTY;i++)
			{
				srcdata[0] = dstdata[2];
				srcdata[1] = dstdata[1];
				srcdata[2] = dstdata[0];
				srcdata[3] = 255;

				srcdata	+= 4;
				dstdata	+= 3;
			}

			dstdata -= 2*uiStride;
		}
	}
	else
	{
		// Flip Vertically and Swap R&B channels
		uint uiStride = m_poTex->m_uiTX * 3;
		char* srcdata = (char*)m_poTex->m_pLOD[0];
		char* dstdata = (char*)framedata + (m_poTex->m_uiTY -1) * uiStride; // set the pointer to the first pixel of the last line

		for (uint j=0;j<m_poTex->m_uiTY;j++)
		{
			for (uint i=0;i<m_poTex->m_uiTX;i++)
			{
				srcdata[0] = dstdata[2];
				srcdata[1] = dstdata[1];
				srcdata[2] = dstdata[0];

				srcdata	+= 3;
				dstdata	+= 3;
			}

			dstdata -= 2*uiStride;
		}	
	}
	
	m_poTex->Invalidate();

	/*
	static int iDo = 0;
	if (iDo)
	{
		FreeImage_Save(FIF_PNG,(FIBITMAP*)m_poTex->m_poHandler,"caca.bmp",0);
		iDo = 0;
	}
	*/

	m_uiCurFrame = _uiFrame;
}
// ----------------------------------------------------------------------------
void CVideo::Update(float _fDeltaT)
{
	if (m_poTex == NULL) return;
	if (! m_bPlaying) return;

	m_fTime   += _fDeltaT;

	if (m_fTime >= m_fTotalTime)
	{
		m_fTime = m_fTotalTime;
		
		if (m_bLoop)
			m_fTime = 0.0f;
		else
			m_bPlaying = false;
	}
	
	int iRealFrame = (int)(m_fTime * m_fFPS);
	if (iRealFrame != m_uiCurFrame)
	{		
		DecodeFrame(iRealFrame);
	}
	
}
// ----------------------------------------------------------------------------
void CVideo::Render()
{
    CGRenderer::I()->RenderMesh(m_poMesh,m_poShader);
}
// ----------------------------------------------------------------------------
CGShader* CVideo::poGetFrame()
{
	return (m_poShader);
}
// ----------------------------------------------------------------------------
