//-----------------------------------------------------------------------------
#ifndef CHUD_h
#define CHUD_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Scene.h"
//-----------------------------------------------------------------------------
class CHUDElem 
{
  public:
		CHUDElem() : x(0),y(0),tx(0),ty(0),poObj(NULL){};
		CHUDElem(CObject3D *_poObj, float _x, float _y, float _tx, float _ty);
		~CHUDElem();

		float x;
		float y;
		float tx;
		float ty;
		CObject3D *poObj;

		void Setup(CObject3D *_poObj, float _x, float _y, float _tx, float _ty);
};
//-----------------------------------------------------------------------------
class CHUD : public CObject3D
{
  public:
			CHUD();
			CHUD(uint _uiMaxElems);
			void Init(uint _uiMaxElems);
			virtual	 ~CHUD();

			uint uiAddObject (CObject3D *_poObj, float _x, float _y, float _tx, float _ty,const CGString& _sName = "");
			CHUDElem* poGetElem(const CGString& _sName) { return(m_oHUDObjs.oGetVar(_sName)); }
			CHUDElem* poGetElem(uint _uiElem) { return (m_oHUDObjs.oGetElem(_uiElem)); }
			
			CGraphBV* poCreateBoundVol (){ return( NULL ); };

			void Invalidate ();

			virtual void Render ();
			virtual int iCulled ();
			virtual CGraphBV* poGetBoundVol ();
			virtual void ComputeBoundVol ();

	protected:
			CGLookupArray <CHUDElem*> m_oHUDObjs;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------