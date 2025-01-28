// -----------------------------------------------------------------------------
#ifndef CSimpleEnemy1H
#define CSimpleEnemy1H
// -----------------------------------------------------------------------------
#include "Loop/Game/Ents/CVisEntity.h"
// -----------------------------------------------------------------------------
class CSimpleEnemy1 : public CVisEntity
{
public:
	CSimpleEnemy1();

	virtual void Init(MTH_CPoint3 _oPos,float _fCursor,float _fHeight,int _iSubType);
	virtual void Restart(MTH_CPoint3 _oPos,float _fCursor,float _fHeight,int _iSubType);

	virtual void Think();
	virtual void SetVisible(bool _bVisible);

public:
	void ComputePositions();

	unsigned int	m_uiFX;
	float			m_fCursor;
	float			m_fHeight;
	float			m_fSpd;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------