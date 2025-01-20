// -----------------------------------------------------------------------------
#ifndef CE3D_RenderStats_h
#define CE3D_RenderStats_h 1
// -----------------------------------------------------------------------------
class CE3D_RenderStats
{    
  public:
		int NumTestedObjs;

		int NumRenderedGObjs;

		int NumCulledObjs;

		int NumRenderedTris;

		int NumRenderedVerts;

		int cDTime;

		float DTimes[4];

		float DTime;

		float FPS;

		int iCurrentFrame;

		float fTotalTime;          
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------