// ----------------------------------------------------------------------------
#include "GammaE.h"
#include "CVideo.h"

#include <vfw.h>
#include <freeimage.h>



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
static CMipMapObj*	m_poTex			= NULL;
static CMesh_Rect*	m_poMesh		= NULL;
static CE3D_Shader* m_poShader		= NULL;

float		CVideo::m_fTime			= 0.0f;
bool		CVideo::m_bPlaying		= false;
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

	float fTime = (float)AVIStreamSampleToTime(pavi,m_uiNumFrames) / 1000.0f;
	m_fFPS = (float)m_uiNumFrames / fTime;	// Calculate Rough FPS

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
	m_poTex = mNew CMipMapObj(bmih.biWidth,bmih.biHeight,1,IF_RGB);	
	m_poTex->Invalidate();

	// Sound
	m_fTime		= 0.0f;
	m_bPlaying	= false;
	m_bLoop     = _bLoop;

	m_poMesh   = mNew CMesh_Rect;
	m_poShader = CE3D_ShaderUtils::poGenerateShaderFromMipMap(m_poTex,VIDEO_FRAME_SHADER);
	CE3D_ShaderWH::I()->iAdd(m_poShader,VIDEO_FRAME_SHADER);
	CMipMapWH::I()->iAdd(m_poTex,VIDEO_FRAME_SHADER);

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
	lpbi = (LPBITMAPINFOHEADER)AVIStreamGetFrame(pgf, _uiFrame);		// Grab Data From The AVI Stream
	char* framedata = (char *)lpbi+lpbi->biSize+lpbi->biClrUsed * sizeof(RGBQUAD);	// Pointer To Data Returned By AVIStreamGetFrame

	// Convert Data To Requested Bitmap Format
	DrawDibDraw (hdd, hdc, 0, 0, width, height, lpbi, framedata, 0, 0, width, height, 0);

	
	#if 0
		
		memcpy(m_poTex->m_pLOD[0],data,m_poTex->m_uiTX * m_poTex->m_uiTY * 3);	

	#else
		// Copy flipped image
		unsigned int uiStride	= m_poTex->m_uiTX * 3;
		char* texdata			= (char*)m_poTex->m_pLOD[0] + uiStride*(m_poTex->m_uiTY-1);
		framedata				= (char*)data;

		for (int i=0;i<m_poTex->m_uiTY;i++)
		{
			memcpy(texdata,framedata,uiStride);

			texdata		-= uiStride;
			framedata	+= uiStride;
		}
	#endif

	// Swap RB channels
	uint uiPixels = m_poTex->m_uiTX * m_poTex->m_uiTY;
	texdata = (char*)m_poTex->m_pLOD[0];
	while (uiPixels)
	{ 
		char aux = texdata[0];
		texdata[0] = texdata[2];
		texdata[2] = aux;

		texdata +=3;
		uiPixels--;
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

	int iRealFrame = m_fTime * m_fFPS;
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
CE3D_Shader* CVideo::poGetFrame()
{
	return (m_poShader);
}
// ----------------------------------------------------------------------------
