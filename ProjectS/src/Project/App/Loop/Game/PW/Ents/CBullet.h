// -----------------------------------------------------------------------------
#ifndef CBulletH
#define CBulletH
// -----------------------------------------------------------------------------
#include "Collision/CCollEntity.h"
// -----------------------------------------------------------------------------
class CBullet : public CCollEntity
{
public:
		CBullet();
		virtual void Think();
		virtual void Restart(CEntity* _poParent,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,float _fSpd);

public:
		CEntity*		m_poParent;
		MTH_CPoint3		m_oDir;

		// Graphic elements
		uint			m_uiFX;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
