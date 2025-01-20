// -----------------------------------------------------------------------------
#ifndef CCoronaMgr_h
#define CCoronaMgr_h 1
// -----------------------------------------------------------------------------
#include "CoronaMgr\CCorona.h"
#include "GammaE_Scene.h"
// -----------------------------------------------------------------------------
class CCoronaMgr : public CObject3D_Leaf
{   
  public:
		CCoronaMgr();

		virtual ~CCoronaMgr();

		void Init (int _iMaxCoronas);

		void AddCorona (CGColor _oColor, CE3D_Shader *_poMat, CVect3& _oPos, float _fXYSize);

		void SetMaxCoronaDist (float _fMaxCoronaDist);

		bool bVisible (CCorona& _oCorona);

		void MarkVisibles ();

		virtual void Render ();

		CCorona *poCoronas;

	private:
		int iMaxCoronas;

		int iNumCoronas;

		float fMaxCoronaDist;

		bool *bVisibles;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
