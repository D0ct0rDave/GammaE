// -----------------------------------------------------------------------------
#ifndef CVisEntityH
#define CVisEntityH

// -----------------------------------------------------------------------------
#include "antares.h"
#include "Collision/CCollEntity.h"
#include "Game/GameGraphics/CGraphicInstance.h"

class CVisEntity : public CCollEntity
{
public:	
		 CVisEntity();
		~CVisEntity();

		// AI/Think
		virtual void Pos(MTH_CPoint3& _oPos);
		virtual void Visible(bool _bVisible);

		virtual void Kill();
		virtual void Restart();

		virtual void Enable();
		virtual void Disable();
		virtual void HideDisable();
		virtual void ShowEnable();
		
		virtual void BuildBV();

public:
		// Status
		CGraphicInstance*	m_poGI;			// If the entity has a graphic representation;
		int					m_iRI;			// Render Entity Index
		bool				m_bVisible;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
