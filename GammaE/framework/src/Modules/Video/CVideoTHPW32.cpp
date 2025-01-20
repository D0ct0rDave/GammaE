// ----------------------------------------------------------------------------
#include "CVideo.h"
#include "thp.h"
#include "GammaE.h"
static ThpVideoFile* m_poTHP = NULL;
static CMipMapObj*	m_poTex = NULL;

static float m_fTime =  0.0f;
static float m_fOldTime	= 0.0f;
static bool m_bPlaying	= false;
static bool m_bLoop     = false;
static CMesh_Rect* m_poMesh = NULL;
static CE3D_Shader* m_poShader = NULL;
// ------------------------------------------------------------------------
inline int FRAME(float _fTime,ThpVideoFile* _poVideo,bool _bLoop)
{
	if( _poVideo != NULL)
	{
		if (_bLoop)
		{
			return ( ((int)(_fTime* _poVideo->getFps()) % _poVideo->getFrameCount()) + 1 );
		}
		else
		{
			if ((_fTime* _poVideo->getFps()) > _poVideo->getFrameCount())

				return (_poVideo->getFrameCount());

			else

				return ((int)(_fTime * _poVideo->getFps() ) + 1);
		}
	}
	else
		return(0);
}
// ----------------------------------------------------------------------------
bool CVideo::bInit(char* _szFilename)
{
	m_poTHP = mNew ThpVideoFile;
	if (! m_poTHP->openVideo(_szFilename))
	{
		mDel(m_poTHP);
		m_poTHP = NULL;
		
		CWarningLC::I()->Write("Unable to load %s video\n",_szFilename);
		return(false);
	}

	VideoFrame oFrame;
	m_poTHP->getCurrentFrame(oFrame);
	
	m_poTex = mNew CMipMapObj(oFrame.getWidth(),oFrame.getHeight(),1,IF_RGB);	
	m_poTex->Invalidate();

	DecodeFrame();

	// Sound
	m_fTime		= 0.0f;
	m_fOldTime	= 0.0f;
	m_bPlaying	= false;
	m_bLoop     = true;
	
	m_poMesh = mNew CMesh_Rect;
	m_poShader = CE3D_ShaderUtils::poGenerateShaderFromMipMap(m_poTex,"THP VideoFrame");
	CE3D_ShaderWH::I()->iAdd(m_poShader,"THP VideoFrame");
	
	return(true);
}
// ----------------------------------------------------------------------------
void CVideo::DecodeFrame()
{
	VideoFrame oFrame;
	m_poTHP->getCurrentFrame(oFrame);

	// Copy flipped image
	unsigned int uiStride	= m_poTex->m_uiTX * 3;
	char* texdata			= (char*)m_poTex->m_pLOD[0] + uiStride*(m_poTex->m_uiTY-1);
	char* framedata			= (char*)oFrame.getData();

	for (int i=0;i<m_poTex->m_uiTY;i++)
	{
		memcpy(texdata,framedata,uiStride);

		texdata		-= uiStride;
		framedata	+= uiStride;
	}

	m_poTex->Invalidate();
}
// ----------------------------------------------------------------------------
void CVideo::Update(float _fDeltaT)
{
	if (m_poTex == NULL) return;
	if (m_poTHP == NULL) return;

	// Is movie paused??
	if (! m_bPlaying) return;

	m_fOldTime = m_fTime;
	m_fTime   += _fDeltaT;

	if ((m_poTHP->getCurrentFrameNr() == (m_poTHP->getFrameCount()-1)) && (! m_bLoop))
	{
		m_bPlaying = false;
	}
	else
	{
		int iRealFrame = FRAME(m_fTime,m_poTHP,m_bLoop);

		if (m_poTHP->getCurrentFrameNr() < iRealFrame)
		{		
			m_poTHP->loadNextFrame();
			DecodeFrame();
		}
	}
}
// ----------------------------------------------------------------------------
void CVideo::Render()
{
    gpoE3DRenderer->RenderMesh(m_poMesh,m_poShader);
}
// ----------------------------------------------------------------------------
void CVideo::Finish()
{
	
}
// ----------------------------------------------------------------------------
CE3D_Shader* CVideo::poGetFrame()
{
	return (m_poShader);
}
// ----------------------------------------------------------------------------