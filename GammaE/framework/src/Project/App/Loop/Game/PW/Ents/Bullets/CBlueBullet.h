// -----------------------------------------------------------------------------
#ifndef CBlueBulletH
#define CBlueBulletH
// -----------------------------------------------------------------------------
#include "../CBullet.h"
// -----------------------------------------------------------------------------
#define		MAX_FXELEMS		2

class CBlueBullet : public CBullet
{
public:
		CBlueBullet();
		void Init(int _iPS0,int _iPS1,int _iF0,int _iF1);
		
		virtual void Think();
		virtual void Enable();
		virtual void Disable();

public:
		
		int				m_iFl[2];
		int				m_iPS[2];
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
