#ifdef PROFILE
#pragma optimize ("",off)
#endif
// -----------------------------------------------------------------------------
#include "CBlueBullet.h"
#include "sfx.h"
// -----------------------------------------------------------------------------
CBlueBullet::CBlueBullet()
{
	m_iFl[0] = -1;
	m_iFl[1] = -1;
	m_iPS[0] = -1;
	m_iPS[1] = -1;
}
// -----------------------------------------------------------------------------
void CBlueBullet::Init(int _iPS0,int _iPS1,int _iF0,int _iF1)
{
	if ( _iF0 > -1) m_iFl[0] = CFlareMgr::iAddFlare( _iF0,ZEROVEC,-1.0f);
	if (_iPS0 > -1) m_iPS[0] = CPSysMgr ::iAddPSys (_iPS0,ZEROVEC,ZEROVEC);
	if ( _iF1 > -1) m_iFl[1] = CFlareMgr::iAddFlare( _iF1,ZEROVEC,-1.0f);
	if (_iPS1 > -1) m_iPS[1] = CPSysMgr ::iAddPSys (_iPS1,ZEROVEC,ZEROVEC);	
}
// -----------------------------------------------------------------------------
void CBlueBullet::Think()
{
	CBullet::Think();

	if (m_eState !=	ENTSTATE_INACTIVE)
	{
		// Update position
		for (int i=0;i<MAX_FXELEMS;i++)
		{
			if (m_iFl[i] != -1)
				CFlareMgr::UpdateFlare(m_iFl[i],m_oPos);

			if (m_iPS[i] != -1)
				CPSysMgr::UpdatePSys(m_iPS[i],m_oPos);
		}
	}
}
// -----------------------------------------------------------------------------
void CBlueBullet::Enable()
{
	CBullet::Enable();

	for (int i=0;i<MAX_FXELEMS;i++)
	{
		if (m_iFl[i] != -1)
			CFlareMgr::Enable(m_iFl[i]);

		if (m_iPS[i] != -1)
			CPSysMgr::Enable(m_iPS[i]);
	}
}
// -----------------------------------------------------------------------------
void CBlueBullet::Disable()
{
	CBullet::Disable();

	for (int i=0;i<MAX_FXELEMS;i++)
	{
		if (m_iFl[i] != -1)
			CFlareMgr::Disable(m_iFl[i]);

		if (m_iPS[i] != -1)
			CPSysMgr::Disable(m_iPS[i]);
	}	
}
// -----------------------------------------------------------------------------		
#ifdef PROFILE
#pragma optimize ("",on)
#endif