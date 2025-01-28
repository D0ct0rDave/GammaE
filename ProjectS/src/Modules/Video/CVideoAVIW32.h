// ----------------------------------------------------------------------------
#ifndef CVideoAVIW32H
#define CVideoAVIW32H
// ----------------------------------------------------------------------------
#include "GammaE.h"
// ----------------------------------------------------------------------------
class CVideo
{
	public:
		static bool bInit(char* _szStr,bool _bLoop = false);
		static void Finish();
 		static void Update(float _fDeltaT);
		static void Render();
		static CGShader* poGetFrame();

		static void Play() { m_bPlaying = true; };
		static void Stop() { m_bPlaying = false; };
		static bool bPlaying()	{ return(m_bPlaying); };
		static float fTime()	{ return(m_fTime); };
		static void Time(float _fTime) { m_fTime = _fTime; };

	protected:
		static void DecodeFrame(uint _uiFrame);
	
	protected:
		static bool	m_bPlaying;
		static float m_fTime;
		static float m_fTotalTime;
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------